#ifndef __SYNTAX_HPP__
#define __SYNTAX_HPP__

/* Commands */
#include <ast.hpp>
#include <command_block.hpp>
#include <expr.hpp>

/* Control flow */
#include <control_flow/break.hpp>
#include <control_flow/continue.hpp>
#include <control_flow/return.hpp>
#include <control_flow/if_else.hpp>
#include <control_flow/while.hpp>
#include <control_flow/for.hpp>
#include <control_flow/do_while.hpp>
#include <control_flow/case.hpp>
#include <control_flow/default.hpp>
#include <control_flow/switch.hpp>

/* Binary arithmetic operators */
#include <operators/plus.hpp>
#include <operators/minus.hpp>
#include <operators/times.hpp>
#include <operators/divide.hpp>
#include <operators/mod.hpp>
#include <operators/power.hpp>

/* Unary arithmetic operators */
#include <operators/uminus.hpp>
#include <operators/uplus.hpp>
#include <operators/increment.hpp>
#include <operators/decrement.hpp>
#include <operators/post_increment.hpp>
#include <operators/post_decrement.hpp>

/* Comparison operators */
#include <operators/equals.hpp>
#include <operators/typed_equals.hpp>
#include <operators/not_equals.hpp>
#include <operators/typed_not_equals.hpp>
#include <operators/less_then.hpp>
#include <operators/less_or_equals.hpp>
#include <operators/greater_then.hpp>
#include <operators/greater_or_equals.hpp>

/* Logical operators */
#include <operators/logic_not.hpp>
#include <operators/logic_and.hpp>
#include <operators/logic_or.hpp>

/* Bitwise operators */
#include <operators/bit_not.hpp>
#include <operators/bit_shift_left.hpp>
#include <operators/bit_shift_right.hpp>
#include <operators/bit_shift_unsigned.hpp>
#include <operators/bit_and.hpp>
#include <operators/bit_xor.hpp>
#include <operators/bit_or.hpp>

/* Ternary conditional */
#include <operators/ternary_conditional.hpp>

/* Creational and removal operators */
#include <operators/new.hpp>
#include <operators/delete.hpp>

/* Assignments */
#include <operators/assign.hpp>
#include <operators/assign_plus.hpp>
#include <operators/assign_minus.hpp>
#include <operators/assign_pow.hpp>
#include <operators/assign_mul.hpp>
#include <operators/assign_div.hpp>
#include <operators/assign_mod.hpp>
#include <operators/assign_shift_l.hpp>
#include <operators/assign_shift_r.hpp>
#include <operators/assign_shift_u.hpp>
#include <operators/assign_bit_con.hpp>
#include <operators/assign_bit_xor.hpp>
#include <operators/assign_bit_dis.hpp>

/* Type checking */
#include <operators/typeof.hpp>
#include <operators/void.hpp>

/* Access operators */
#include <operators/array_access.hpp>
#include <operators/dot_access.hpp>

/* Function call */
#include <operators/function_call.hpp>

/* Litrerals */
#include <literals/undefined.hpp>
#include <literals/null.hpp>
#include <literals/nan.hpp>
#include <literals/true.hpp>
#include <literals/false.hpp>
#include <literals/numeric.hpp>
#include <literals/string.hpp>
#include <literals/array.hpp>
#include <literals/object.hpp>
#include <literals/function.hpp>

/* Variables */
#include <variables/variable.hpp>
#include <variables/const_declaration.hpp>
#include <variables/var_declaration.hpp>
#include <variables/let_declaration.hpp>
#include <variables/function_declaration.hpp>


#endif // __SYNTAX_HPP__

