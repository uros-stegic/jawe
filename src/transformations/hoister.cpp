#include <transformations/hoister.hpp>
#include <syntax.hpp>
#include <algorithm>

using namespace jawe;

extern Command* program;

void Hoister::transform() const
{
	decouple(program);
}

void Hoister::decouple(Command* root) const
{
	switch( root->get_type() ) {
		case TCommandBlock: {
			CommandBlock* node = static_cast<CommandBlock*>(root);
			auto commands = node->get_commands();
			std::for_each(
				std::begin(commands),
				std::end(commands),
				[this](Command* p) {
					decouple(p);
				}
			);
			break;
		}
		case TIfElse: {
			IfElse* node = static_cast<IfElse*>(root);
			auto left = node->get_if();
			auto right = node->get_else();
			decouple(left);
			if( right != nullptr ) {
				decouple(right);
			}
			break;
		}
		case TWhile: {
			While* node = static_cast<While*>(root);
			auto body = node->get_body();
			decouple(body);
			break;
		}
		case TDoWhile: {
			DoWhile* node = static_cast<DoWhile*>(root);
			auto body = node->get_body();
			decouple(body);
			break;
		}
		case TFor: {
			For* node = static_cast<For*>(root);
			auto body = node->get_body();
			auto init = node->get_init();
			auto post = node->get_post();
			decouple(body);
			decouple(init);
			decouple(body);
			break;
		}
		case TSwitch: {
			Switch* node = static_cast<Switch*>(root);
			auto commands = node->get_cases();
			std::for_each(
				std::begin(commands),
				std::end(commands),
				[this](Command* p) {
					decouple(p);
				}
			);
			break;
		}
		case TCase: {
			Case* node = static_cast<Case*>(root);
			auto body = node->get_body();
			decouple(body);
			break;
		}
		case TDefault: {
			Default* node = static_cast<Default*>(root);
			auto body = node->get_body();
			decouple(body);
			break;
		}
		case TConstDeclaration:
		case TLetDeclaration:
		case TVarDeclaration: {
			Declaration* node = static_cast<Declaration*>(root);
			if( node->expr()->priority() != TAssign ) {
				break;
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

			decl->set_parent(parent);
			assignment->set_parent(parent);

			parent->replace(node, assignment);
			parent->insert_before(assignment, decl);
			break;
		}
		default: {}
	}
}

