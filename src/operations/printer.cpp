#include <operations/printer.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <variant>
#include <shared_node.hpp>
#include <syntax.hpp>
#include <utils/lambda_composer.hpp>

using namespace jawe;

extern shared_node* program;

void printer::run() const
{
  if( control::get().dump_ast() ) {
    dump_ast(*program, 0);
  }
  if( control::get().dump_program() ) {
    	std::cout	<< "~~~~~ Printing program"
  					<< std::endl << std::endl;
    dump_program(*program, 0);
    	std::cout	<< std::endl
  					<< "~~~~~ Finished printing"
  					<< std::endl << std::endl;
  }

  control::get().get_module()->dump();
}

void printer::dump_ast(const shared_node& program, int num_tabs) const {
    std::visit(lambda_composer {
      // abstract
      [this, num_tabs](basic_node* node) {
  			std::cout	<< std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;
  		},
      // control flow
      [this, num_tabs](break_node* node) {
  			std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;
  		},
      [this, num_tabs](case_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // case condition
        dump_ast(node->get_case(), num_tabs+1);
        // case body
        dump_ast(node->get_body(), num_tabs+1);
  		},
      [this, num_tabs](command_block_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        auto nodes = node->get_commands();
  			std::for_each(
  				std::begin(nodes),
  				std::end(nodes),
  				[this, num_tabs](auto n) { dump_ast(n, num_tabs+1); }
    	  );
      },
      [this, num_tabs](continue_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;
      },
      [this, num_tabs](default_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // default body
        dump_ast(node->get_body(), num_tabs+1);
      },
      [this, num_tabs](do_while_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // do while body
        dump_ast(node->get_body(), num_tabs+1);
        // do while expr
        dump_ast(node->get_expr(), num_tabs+1);
      },
      [this, num_tabs](empty_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;
      },
      [this, num_tabs](for_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // for init
        dump_ast(node->get_init(), num_tabs+1);
        // for expr
        dump_ast(node->get_expr(), num_tabs+1);
        // for post
        dump_ast(node->get_post(), num_tabs+1);
        // for body
        dump_ast(node->get_body(), num_tabs+1);
      },
      [this, num_tabs](if_else_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // if expr
        dump_ast(node->get_expr(), num_tabs+1);
        // if
        dump_ast(node->get_if(), num_tabs+1);
        // if else
        auto else_node = node->get_else();
        if(else_node != nullptr)
          dump_ast(else_node, num_tabs+1);
      },
      [this, num_tabs](return_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // return expr
        dump_ast(node->get_expr(), num_tabs+1);
      },
      [this, num_tabs](switch_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // switch expr
        dump_ast(node->get_expr(), num_tabs+1);
        // switch cases
        auto nodes = node->get_cases();
  			std::for_each(
  				std::begin(nodes),
  				std::end(nodes),
  				[this, num_tabs](auto n) { dump_ast(n, num_tabs+1); }
    	  );
      },
      [this, num_tabs](while_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
      						<< node->get_symbol()
                  << " "
                  << node->memory_address()
      						<< std::endl;

        // while expr
        dump_ast(node->get_expr(), num_tabs+1);
        // while body
        dump_ast(node->get_body(), num_tabs+1);
      },
      // literals
      [this, num_tabs](array_node* node) {
        auto nodes = node->get_elements();
        std::cout << std::string(4*num_tabs, ' ')
                  << "Array("
                  << nodes.size()
                  << ") "
                  << node->memory_address()
      						<< std::endl;

        std::for_each(
          std::begin(nodes),
          std::end(nodes),
          [this, num_tabs](auto n) { dump_ast(n, num_tabs+1); }
        );
      },
      [this, num_tabs](function_object_node* node) {
        auto args = node->get_args();
        std::cout << std::string(4*num_tabs, ' ')
                  << "Function [";

        // function args
        if(args.size() != 0) {
          std::cout << *std::begin(args);
          std::for_each(
            ++std::begin(args),
            std::end(args),
        		[&](std::string arg) {
        			std::cout << ", " << arg;
        		}
          );
        }

        std::cout << "] "
                  << node->memory_address()
      						<< std::endl;
        // function body
        dump_ast(node->get_body(), num_tabs+1);
      },
      [this, num_tabs](logical_literal_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
                  << "Boolean ["
                  << node->get_symbol()
                  << "] "
                  << node->memory_address()
      						<< std::endl;
      },
      [this, num_tabs](numeric_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
                  << "Numeric ["
                  << node->get_symbol()
                  << "] "
                  << node->memory_address()
                  << std::endl;
      },
      [this, num_tabs](object_node* node) {
        auto pairs = node->get_pairs();
        std::cout << std::string(4*num_tabs, ' ')
                  << "Object("
                  << pairs.size()
                  << ") "
                  << node->memory_address()
      						<< std::endl;

        // object key value pairs
        for(auto &p: pairs) {
          std::cout << std::string(4*(num_tabs+1), ' ')
                    << "KeyValue"
                    << std::endl
                    << std::string(4*(num_tabs+2), ' ')
                    << p.first
                    << std::endl;
          dump_ast(p.second, num_tabs+2);
      	}
      },
      [this, num_tabs](string_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
                  << "String [\""
                  << node->get_symbol()
                  << "\"] "
                  << node->memory_address()
                  << std::endl;
      },
      // operators
      [this, num_tabs](binary_operator_node* node) {
        std::cout << std::string(4*num_tabs, ' ')
                  << "operator ["
                  << node->get_symbol()
                  << "] "
                  << node->memory_address()
                  << std::endl;

        // left operator
        dump_ast(node->get_left(), num_tabs+1);
        // right operator
        dump_ast(node->get_right(), num_tabs+1);
      },
      [this, num_tabs](function_call_node* node) {
        std::cout	<< std::string(4*num_tabs, ' ')
                  << "FunctionCall "
                  << node->memory_address()
                  << std::endl;
        // function expr
        dump_ast(node->get_expr(), num_tabs+1);
        std::cout << std::string(4*(num_tabs+1), ' ')
                  << "Args"
                  << std::endl;

        auto args = node->get_args();

        if(args.size() != 0) {
          dump_ast(*args.begin(), num_tabs+1);

        	std::for_each(
        		++std::begin(args),
        		std::end(args),
        		[&](auto expr) {
        			dump_ast(expr, num_tabs+1);
        		}
        	);
        }
      },
      [this, num_tabs](ternary_operator_node* node) {
        	std::cout << std::string(4*num_tabs, ' ')
                		<< "operator ["
                		<< node->get_symbol()
                    << " "
                    << node->get_symbol2()
                		<< "] "
                    << node->memory_address()
                		<< std::endl;
        	dump_ast(node->get_first_operand(), num_tabs+1);
        	dump_ast(node->get_second_operand(), num_tabs+1);
        	dump_ast(node->get_third_operand(), num_tabs+1);
      },
      [this, num_tabs](unary_operator_node* node) {
        	std::cout << std::string(4*num_tabs, ' ')
                		<< "operator ["
                		<< node->get_symbol()
                		<< "] "
                    << node->memory_address()
                		<< std::endl;
        	dump_ast(node->get_operand(), num_tabs+1);
      },
      // variables
      [this, num_tabs](declaration_node* node) {
        	std::cout << std::string(4*num_tabs, ' ')
                		<< "Declaration ["
                    << node->get_symbol()
                    << "] "
                    << node->memory_address()
                		<< std::endl;
        	dump_ast(node->get_expr(), num_tabs+1);
      },
      [this, num_tabs](function_declaration_node* node) {
        	std::cout << std::string(4*num_tabs, ' ')
                		<< "FunctionDeclaration ["
                    << node->get_name()
                    << "] "
                    << node->memory_address()
                		<< std::endl;
        	dump_ast(node->get_function_object(), num_tabs+1);
      },
      [this, num_tabs](variable_node* node) {
        	std::cout << std::string(4*num_tabs, ' ')
                		<< "Variable ["
                    << node->get_name()
                    << "] "
                    << node->memory_address()
                		<< std::endl;
      },
    }, *program);
}

void printer::dump_program(const shared_node& program, int num_tabs) const {
  std::cout << "This should be a program printer." << std::endl;
}
