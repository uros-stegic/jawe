#include <operations/empty_remover.hpp>
#include <syntax.hpp>

using namespace jawe;

extern shared_node* program;

void EmptyRemover::remove(shared_node* root) const
{
	// switch( root->get_type() ) {
	// 	case TCommandBlock: {
	// 		remove(static_cast<CommandBlock*>(root));
	// 		break;
	// 	}
	// 	case TIfElse: {
	// 		remove(static_cast<IfElse*>(root));
	// 		break;
	// 	}
	// 	case TWhile: {
	// 		remove(static_cast<While*>(root));
	// 		break;
	// 	}
	// 	case TDoWhile: {
	// 		remove(static_cast<DoWhile*>(root));
	// 		break;
	// 	}
	// 	case TFor: {
	// 		remove(static_cast<For*>(root));
	// 		break;
	// 	}
	// 	case TSwitch: {
	// 		remove(static_cast<Switch*>(root));
	// 		break;
	// 	}
	// 	case TCase: {
	// 		remove(static_cast<Case*>(root));
	// 		break;
	// 	}
	// 	case TDefault: {
	// 		remove(static_cast<Default*>(root));
	// 		break;
	// 	}
	// 	case TFunctionDeclaration: {
	// 		remove(static_cast<FunctionDeclaration*>(root));
	// 		break;
	// 	}
	// 	case TEmpty: {
	// 		remove(static_cast<Empty*>(root));
	// 		break;
	// 	}
	// 	case TLetDeclaration:
	// 	case TVarDeclaration: {
	// 		remove(static_cast<Declaration*>(root));
	// 		break;
	// 	}
	// 	default: {}
	// }
}

void EmptyRemover::run() const
{
	remove(program);
}

// void EmptyRemover::remove(CommandBlock* node) const
// {
	// auto commands = node->get_commands();
	// std::for_each(
	// 	std::begin(commands),
	// 	std::end(commands),
	// 	[this](Command* p) {
	// 		remove(p);
	// 	}
	// );
// }
// void EmptyRemover::remove(IfElse* node) const
// {
// 	auto left = node->get_if();
// 	auto right = node->get_else();
// 	remove(left);
// 	if( right != nullptr ) {
// 		remove(right);
// 	}
// }
// void EmptyRemover::remove(While* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(DoWhile* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(For* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(Switch* node) const
// {
// 	auto commands = node->get_cases();
// 	std::for_each(
// 		std::begin(commands),
// 		std::end(commands),
// 		[this](Command* p) {
// 			remove(p);
// 		}
// 	);
// }
// void EmptyRemover::remove(Case* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(Default* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(FunctionDeclaration* node) const
// {
// 	auto body = node->get_body();
// 	remove(body);
// }
// void EmptyRemover::remove(Declaration* node) const
// {
// 	if( node->expr()->priority() != TAssign ) {
// 		return;
// 	}
//
// 	auto* rval = static_cast<Assign*>(node->expr())->right();
// 	if( rval->priority() == TFunction ) {
// 		Function* f = static_cast<Function*>(rval);
// 		remove(f->get_body());
// 	}
// }
// void EmptyRemover::remove(Empty* node) const
// {
// 	auto parent = static_cast<CommandBlock*>(node->get_parent());
// 	parent->remove(node);
// }
