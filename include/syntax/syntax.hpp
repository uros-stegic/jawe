#ifndef __SYNTAX_HPP__
#define __SYNTAX_HPP__

/* Commands */
#include <ast.hpp>
#include <command_block.hpp>
#include <break.hpp>
#include <continue.hpp>
#include <return.hpp>
#include <if_else.hpp>
#include <while.hpp>
#include <for.hpp>
#include <do_while.hpp>

/* Binary arithmetic operators */
#include <plus.hpp>
#include <minus.hpp>
#include <times.hpp>
#include <divide.hpp>
#include <mod.hpp>
#include <power.hpp>

/* Unary arithmetic operators */
#include <uminus.hpp>
#include <uplus.hpp>
#include <increment.hpp>
#include <decrement.hpp>
#include <post_increment.hpp>
#include <post_decrement.hpp>

/* Comparison operators */
#include <equals.hpp>
#include <typed_equals.hpp>
#include <not_equals.hpp>
#include <typed_not_equals.hpp>
#include <less_then.hpp>
#include <less_or_equals.hpp>
#include <greater_then.hpp>
#include <greater_or_equals.hpp>

/* Logical operators */
#include <logic_not.hpp>
#include <logic_and.hpp>
#include <logic_or.hpp>

/* Bitwise operators */
#include <bit_not.hpp>
#include <bit_shift_left.hpp>
#include <bit_shift_right.hpp>
#include <bit_shift_unsigned.hpp>
#include <bit_and.hpp>
#include <bit_xor.hpp>
#include <bit_or.hpp>

/* Ternary conditional */
#include <ternary_conditional.hpp>

/* Creational and removal operators */
#include <new.hpp>
#include <delete.hpp>

/* Type checking */
#include <typeof.hpp>
#include <void.hpp>

/* Access operators */
#include <array_access.hpp>
#include <dot_access.hpp>

/* Constants */
#include <numeric.hpp>

#endif // __SYNTAX_HPP__

