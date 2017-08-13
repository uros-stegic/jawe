#include <transformations/hoister.hpp>
#include <syntax.hpp>
#include <algorithm>

using namespace jawe;

extern shared_node* program;

void Hoister::run() const
{
  	decouple(*program, *program, *program);
}

void Hoister::decouple(const shared_node& root, const shared_node& parent_var, const shared_node& parent_let) const
{
  std::visit(lambda_composer {
    [](basic_node* node) {},
    [this, root, parent_var, parent_let](case_node* node) {
			decouple(node->get_body(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](default_node* node) {
      decouple(node->get_body(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](do_while_node* node) {
      decouple(node->get_body(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](for_node* node) {
      decouple(node->get_body(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](if_else_node* node) {
      decouple(node->get_if(), parent_var, parent_let);
			auto else_node = node->get_else();
			if(else_node != nullptr) {
        decouple(else_node, parent_var, parent_let);
			}
		},
		[this, root, parent_var, parent_let](return_node* node) {
			decouple(node->get_expr(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](switch_node* node) {
			auto nodes = node->get_cases();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
        [this, root, parent_var, parent_let](auto n) { decouple(n, parent_var, parent_let); }
			);
		},
		[this, root, parent_var, parent_let](while_node* node) {
      decouple(node->get_body(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](array_node* node) {
			auto nodes = node->get_elements();

			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this, root, parent_var, parent_let](auto n) { decouple(n, parent_var, parent_let); }
			);
		},
		[this, root, parent_var, parent_let](object_node* node) {
			auto pairs = node->get_pairs();
			for(auto &p: pairs) {
        decouple(p.second, parent_var, parent_let);
			}
		},
		[this, root, parent_var, parent_let](binary_operator_node* node) {
      decouple(node->get_left(), parent_var, parent_let);
      decouple(node->get_right(), parent_var, parent_let);
    },
		[this, root, parent_var, parent_let](function_call_node* node) {
			auto args = node->get_args();

			if(args.size() != 0) {
				std::for_each(
					std::begin(args),
					std::end(args),
					[this, root, parent_var, parent_let](auto expr) {
            decouple(expr, parent_var, parent_let);
    			}
				);
	    }
		},
		[this, root, parent_var, parent_let](ternary_operator_node* node) {
      decouple(node->get_first_operand(), parent_var, parent_let);
      decouple(node->get_second_operand(), parent_var, parent_let);
      decouple(node->get_third_operand(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](unary_operator_node* node) {
      decouple(node->get_operand(), parent_var, parent_let);
		},
    [this, root, parent_var, parent_let](function_declaration_node* node) {
      decouple(node->get_function_object(), parent_var, parent_let);
    },
    // changing parent for var
    [this, root, parent_var, parent_let](function_object_node* node) {
      decouple(node->get_body(), node->get_body(), parent_let);
    },
		[this, root, parent_var, parent_let](const_declaration_node* node) {
      decouple(node->get_expr(), parent_var, parent_let);
		},
		[this, root, parent_var, parent_let](declaration_node* node) {
      // x = 5
      auto assign_expr_op = get_decl_ass_op(node->get_expr());
      auto parent_var_raw = std::get<command_block_node*>(*parent_var);
      auto parent_let_raw = std::get<command_block_node*>(*parent_let);
      auto new_decl = root;

      if(assign_expr_op) {
        // x = 5
        auto assign_expr_op_raw = std::get<assign_node*>(**assign_expr_op);
        // x
        auto left_ass_exp = assign_expr_op_raw->get_left();

        if(node->get_qualifier() == QVar)
          // var x;
          new_decl = make_node<var_declaration_node>(left_ass_exp);
        else if(node->get_qualifier() == QLet)
          // let x;
          new_decl = make_node<let_declaration_node>(left_ass_exp);

        // replace var/let x = 5; with x = 5;
        parent_let_raw->replace(root, std::move(*assign_expr_op));
      }

      if(node->get_qualifier() == QVar)
        // insert var x; in command block
        parent_var_raw->push_back_var_decl(new_decl);
      else if(node->get_qualifier() == QLet)
        // insert let x; in command block
        parent_let_raw->push_back_var_decl(new_decl);

      decouple(node->get_expr(), parent_var, parent_let);
		},
    // changing parent for let
		[this, root, parent_var, parent_let](command_block_node* node) {
			auto nodes = node->get_commands();

      std::for_each(
        std::begin(nodes),
        std::end(nodes),
        [this, root, parent_var, parent_let](auto expr) {
          decouple(expr, parent_var, root);
        }
      );
		},
  }, *root);
}

std::optional<shared_node> Hoister::get_decl_ass_op(const shared_node& root) const {
  return std::visit(lambda_composer {
    [root](assign_node* node) -> std::optional<shared_node> {
			return root;
		},
    [](basic_node* node) -> std::optional<shared_node> {
			return {};
		},
  }, *root);
}
