#include <operations/empty_remover.hpp>
#include <utils/lambda_composer.hpp>
#include <syntax.hpp>

using namespace jawe;

extern shared_node* program;

void empty_remover::remove(const shared_node& root, const shared_node& parent) const
{
	std::visit(lambda_composer {
		// abstract
		[root](basic_node* node) {},
		[this, root](command_block_node* node) {
			auto commands = node->get_commands();

			std::for_each(
				std::begin(commands),
				std::end(commands),
				[this, root](auto p) {
					remove(p, root);
				});
		},
		[this, root](if_else_node* node) {
			auto left = node->get_if();
			auto right = node->get_else();

			remove(left, root);
			if( right != nullptr ) {
				remove(right, root);
			}
		},
		[this, root](while_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](do_while_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](for_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](switch_node* node) {
			auto commands = node->get_cases();
			std::for_each(
				std::begin(commands),
				std::end(commands),
				[this, root](auto p) {
					remove(p, root);
				});
		},
		[this, root](case_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](default_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](function_declaration_node* node) {
			auto body = node->get_body();
			remove(body, root);
		},
		[this, root](declaration_node* node) {
			auto expr = node->get_expr();
			remove(expr, root);
		},
		[this, parent, root](empty_node* node) {
			if(root != parent){
				remove_impl(root, parent);
			}
		},
	}, *root);
}

void empty_remover::remove_impl(const shared_node& child, const shared_node& parent) const {
	std::visit(lambda_composer {
		[](basic_node* node) {},
		[this, child, parent](command_block_node* node) {
			node->remove(child);
		},
	}, *parent);

}

void empty_remover::run() const
{
	remove(*program, *program);
}
