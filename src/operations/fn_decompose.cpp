#include <operations/fn_decompose.hpp>
#include <syntax.hpp>
#include <lang.syn.hpp>

using namespace jawe;

extern shared_node* program;

void FunctionDecomposer::decompose(shared_node* root) const
{
	// switch( root->get_type() ) {
	// 	case TCommandBlock: {
	// 		decompose(static_cast<CommandBlock*>(root));
	// 		break;
	// 	}
	// 	case TIfElse: {
	// 		decompose(static_cast<IfElse*>(root));
	// 		break;
	// 	}
	// 	case TWhile: {
	// 		decompose(static_cast<While*>(root));
	// 		break;
	// 	}
	// 	case TDoWhile: {
	// 		decompose(static_cast<DoWhile*>(root));
	// 		break;
	// 	}
	// 	case TFor: {
	// 		decompose(static_cast<For*>(root));
	// 		break;
	// 	}
	// 	case TSwitch: {
	// 		decompose(static_cast<Switch*>(root));
	// 		break;
	// 	}
	// 	case TCase: {
	// 		decompose(static_cast<Case*>(root));
	// 		break;
	// 	}
	// 	case TDefault: {
	// 		decompose(static_cast<Default*>(root));
	// 		break;
	// 	}
	// 	case TFunctionDeclaration: {
	// 		decompose(static_cast<FunctionDeclaration*>(root));
	// 		break;
	// 	}
	// 	case TLetDeclaration:
	// 	case TVarDeclaration: {
	// 		decompose(static_cast<Declaration*>(root));
	// 		break;
	// 	}
	// 	default: {}
	// }
}

void FunctionDecomposer::run() const
{
	decompose(program);
}
//
// void FunctionDecomposer::decompose(CommandBlock* node) const
// {
// 	auto commands = node->get_commands();
// 	std::for_each(
// 		std::begin(commands),
// 		std::end(commands),
// 		[this](Command* p) {
// 			decompose(p);
// 		}
// 	);
// }
// void FunctionDecomposer::decompose(IfElse* node) const
// {
// 	auto left = node->get_if();
// 	auto right = node->get_else();
// 	decompose(left);
// 	if( right != nullptr ) {
// 		decompose(right);
// 	}
// }
// void FunctionDecomposer::decompose(While* node) const
// {
// 	auto body = node->get_body();
// 	decompose(body);
// }
// void FunctionDecomposer::decompose(DoWhile* node) const
// {
// 	auto body = node->get_body();
// 	decompose(body);
// }
// void FunctionDecomposer::decompose(For* node) const
// {
// 	auto body = node->get_body();
// 	decompose(body);
// }
// void FunctionDecomposer::decompose(Switch* node) const
// {
// 	auto commands = node->get_cases();
// 	std::for_each(
// 		std::begin(commands),
// 		std::end(commands),
// 		[this](Command* p) {
// 			decompose(p);
// 		}
// 	);
// }
// void FunctionDecomposer::decompose(Case* node) const
// {
// 	auto body = node->get_body();
// 	decompose(body);
// }
// void FunctionDecomposer::decompose(Default* node) const
// {
// 	auto body = node->get_body();
// 	decompose(body);
// }
// void FunctionDecomposer::decompose(FunctionDeclaration* node) const
// {
// 	// Where are we gonna operate?
// 	auto parent = static_cast<CommandBlock*>(node->get_parent());
//
// 	auto fn = static_cast<Function*>(node->get_function()->copy());
//
// 	auto body = fn->get_body();
// 	decompose(body);
//
// 	auto var = new Variable(node->name());
// 	auto ass = new Assign(var, fn);
// 	var->set_parent(ass);
// 	fn->set_parent(ass);
//
// 	auto decl = new VarDeclaration(ass);
// 	ass->set_parent(decl);
// 	parent->replace(node, decl);
// 	decl->set_parent(parent);
// }
// void FunctionDecomposer::decompose(Declaration* node) const
// {
// 	if( node->expr()->priority() != TAssign ) {
// 		return;
// 	}
//
// 	auto* rval = static_cast<Assign*>(node->expr())->right();
// 	if( rval->priority() == TFunction ) {
// 		Function* f = static_cast<Function*>(rval);
// 		decompose(f->get_body());
// 	}
// }
//
