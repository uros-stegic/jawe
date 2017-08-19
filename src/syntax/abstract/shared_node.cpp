#include <algorithm>
#include <sstream>
#include <shared_node.hpp>
#include <syntax.hpp>
#include <utils/control.hpp>

using namespace jawe;


basic_node::basic_node(std::string symbol)
	:m_symbol(symbol)
{}

std::string basic_node::get_symbol() const {
	return m_symbol;
}

std::string basic_node::memory_address() const
{
	std::stringstream ss;
	if( control::get().show_memory() ) {
		ss << "[" << this << "]";
	}
	return ss.str();
}

void deleter::operator() (node_variant* node)
{
	std::visit(lambda_composer {
		// abstract
		[](basic_node* node) {
			delete node;
		},
		// control flow
		[](break_node* node) {
			delete node;
		},
		[](case_node* node) {
			// case condition
			node->get_case().reset();
			// case body
			node->get_body().reset();

			delete node;
		},
		[](command_block_node* node) {
			auto nodes = node->get_commands();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[](auto n) { n.reset(); }
			);

			delete node;
		},
		[](continue_node* node) {
			delete node;
		},
		[](default_node* node) {
			// default body
			node->get_body().reset();

			delete node;
		},
		[](do_while_node* node) {
			// do while body
			node->get_body().reset();
			// do while expr
			node->get_expr().reset();

			delete node;
		},
		[](empty_node* node) {
			delete node;
		},
		[](for_node* node) {
			// for init
			node->get_init().reset();
			// for expr
			node->get_expr().reset();
			// for post
			node->get_post().reset();
			// for body
			node->get_body().reset();

			delete node;
		},
		[](if_else_node* node) {
			// if expr
			node->get_expr().reset();
			// if
			node->get_if().reset();
			// if else
			auto else_node = node->get_else();
			if(else_node != nullptr) {
				else_node.reset();
			}
			delete node;
		},
		[](return_node* node) {
			// return expr
			node->get_expr().reset();

			delete node;
		},
		[](switch_node* node) {
			// switch expr
			node->get_expr().reset();
			// switch cases
			auto nodes = node->get_cases();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[](auto n) { n.reset(); }
			);

			delete node;
		},
		[](while_node* node) {
			// while expr
			node->get_expr().reset();
			// while body
			node->get_body().reset();

			delete node;
		},
		// literals
		[](array_node* node) {
			auto nodes = node->get_elements();

			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[](auto n) { n.reset(); }
			);
			delete node;
		},
		[](function_object_node* node) {
			// function body
			node->get_body().reset();

			delete node;
		},
		[](literal_node* node) {
			delete node;
		},
		[](object_node* node) {
			auto pairs = node->get_pairs();
			// object key value pairs
			for(auto &p: pairs) {
 				p.second.reset();
			}

			delete node;
		},
		// operators
		[](binary_operator_node* node) {
			// left operator
			node->get_left().reset();
			// right operator
			node->get_right().reset();

			delete node;
		},
		[](function_call_node* node) {
			// function expr
			node->get_expr().reset();
			auto args = node->get_args();

			if(args.size() != 0) {
				std::for_each(
					std::begin(args),
					std::end(args),
					[](auto expr) {
						expr.reset();
					}
				);

				delete node;
			}
		},
		[](ternary_operator_node* node) {
			node->get_first_operand().reset();
			node->get_second_operand().reset();
			node->get_third_operand().reset();

			delete node;
		},
		[](unary_operator_node* node) {
			node->get_operand().reset();

			delete node;
		},
		// variables
		[](declaration_node* node) {
			node->get_expr().reset();

			delete node;
		},
		[](function_declaration_node* node) {
			node->get_function_object().reset();

			delete node;
		},
		[](variable_node* node) {
			delete node;
		},
	}, *node);

	delete node;
}
