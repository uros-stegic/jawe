#include <transformations/hoister.hpp>
#include <syntax.hpp>
#include <algorithm>

using namespace jawe;

extern Command* program;

void Hoister::transform() const
{
	decouple(program);
}

void Hoister::decouple(CommandBlock* node) const
{
	auto commands = node->get_commands();
	std::for_each(
		std::begin(commands),
		std::end(commands),
		[this](Command* p) {
			decouple(p);
		}
	);
}
void Hoister::decouple(IfElse* node) const
{
	auto left = node->get_if();
	auto right = node->get_else();
	decouple(left);
	if( right != nullptr ) {
		decouple(right);
	}
}
void Hoister::decouple(While* node) const
{
	auto body = node->get_body();
	decouple(body);
}
void Hoister::decouple(DoWhile* node) const
{
	auto body = node->get_body();
	decouple(body);
}
void Hoister::decouple(For* node) const
{
	auto body = node->get_body();
	auto init = node->get_init();
	auto post = node->get_post();
	decouple(body);
	decouple(init);
	decouple(body);
}
void Hoister::decouple(Switch* node) const
{
	auto commands = node->get_cases();
	std::for_each(
		std::begin(commands),
		std::end(commands),
		[this](Command* p) {
			decouple(p);
		}
	);
}
void Hoister::decouple(Case* node) const
{
	auto body = node->get_body();
	decouple(body);
}
void Hoister::decouple(Default* node) const
{
	auto body = node->get_body();
	decouple(body);
}
void Hoister::decouple(FunctionDeclaration* node) const
{
	auto body = node->get_body();
	decouple(body);
}
void Hoister::decouple(Declaration* node) const
{
	if( node->expr()->priority() != TAssign ) {
		return;
	}

	// Isolate assignment
	auto assignment = static_cast<Assign*>(node->expr()->copy());

	// Isolate variable in question
	auto var = static_cast<Variable*>(assignment->left()->copy());

	// Isolate parenting container
	auto parent = static_cast<CommandBlock*>(node->get_parent());
	
	// Generate new variable declaration
	Command* decl;
	if( node->get_type() == TVarDeclaration ) {
		decl = new VarDeclaration(var);
	}
	else if( node->get_type() == TLetDeclaration ) {
		decl = new LetDeclaration(var);
	}
	else {
		decl = new ConstDeclaration(var);
	}

	var->set_parent(decl);
	decl->set_parent(parent);
	assignment->set_parent(parent);

	parent->replace(node, assignment);

	CommandBlock* decl_container;
	if( decl->get_type() == TVarDeclaration ) {
		decl_container = find_top_block(parent);
	}
	else {
		decl_container = parent;
	}
	decl_container->prepend(decl);

	auto* rval = assignment->right();
	if( rval->priority() == TFunction ) {
		Function* f = static_cast<Function*>(rval);
		decouple(f->get_body());
	}
	// TLiteral -> {TObject, TFunction, TNumber, ...}
}

void Hoister::decouple(Command* root) const
{
	switch( root->get_type() ) {
		case TCommandBlock: {
			decouple(static_cast<CommandBlock*>(root));
			break;
		}
		case TIfElse: {
			decouple(static_cast<IfElse*>(root));
			break;
		}
		case TWhile: {
			decouple(static_cast<While*>(root));
			break;
		}
		case TDoWhile: {
			decouple(static_cast<DoWhile*>(root));
			break;
		}
		case TFor: {
			decouple(static_cast<For*>(root));
			break;
		}
		case TSwitch: {
			decouple(static_cast<Switch*>(root));
			break;
		}
		case TCase: {
			decouple(static_cast<Case*>(root));
			break;
		}
		case TDefault: {
			decouple(static_cast<Default*>(root));
			break;
		}
		case TFunctionDeclaration: {
			decouple(static_cast<FunctionDeclaration*>(root));
			break;
		}
		case TLetDeclaration:
		case TVarDeclaration: {
			decouple(static_cast<Declaration*>(root));
			break;
		}
		default: {}
	}
}

CommandBlock* Hoister::find_top_block(Command* block) const {
	auto parent = block->get_parent();
	if( parent == nullptr ) {
		return static_cast<CommandBlock*>(block);
	}
	else if( parent->get_type() == TFunctionDeclaration ) {
		return static_cast<CommandBlock*>(block);
	}
	else if(
		parent->get_type() == TExpr &&
		static_cast<Expr*>(parent)->priority() == TFunction
	) {
		return static_cast<CommandBlock*>(block);
	}
	return find_top_block(block->get_parent());
}

