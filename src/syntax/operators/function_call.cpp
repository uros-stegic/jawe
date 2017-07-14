#include <operators/function_call.hpp>
#include <algorithm>

using namespace jawe;

FunctionCall::FunctionCall(Expr* expr)
	: Expr(TFunctionCall)
	, m_expr(expr)
{}

FunctionCall::FunctionCall(Expr* expr, const std::vector<Expr*>& args)
	: Expr(TFunctionCall)
	, m_expr(expr)
	, m_args(args)
{}

FunctionCall::~FunctionCall()
{
	delete m_expr;
	for(auto &arg: m_args) {
		delete arg;
	}
}

void FunctionCall::print_args(std::ostream& out) const
{
	if( m_args.size() == 0 ) {
		return;
	}
	(*m_args.begin())->print(out);
	std::for_each(
		++std::begin(m_args),
		std::end(m_args),
		[&](Expr* expr) {
			out << ",";
			expr->print(out);
		}
	);
}
void FunctionCall::print(std::ostream& out, int tabs) const
{
	if( get_parent()->get_type() == TCommandBlock ) {
		out << std::string(4*tabs, ' ');
	}
	m_expr->print(out);
	out << "(";
	print_args(out);
	out << ")";
}

void FunctionCall::dump_args(std::ostream& out, int tabs) const
{
	if( m_args.size() == 0 ) {
		return;
	}
	(*m_args.begin())->dump_ast(out, tabs+1);
	std::for_each(
		++std::begin(m_args),
		std::end(m_args),
		[&](Expr* expr) {
			expr->dump_ast(out, tabs+1);
		}
	);
}
void FunctionCall::dump_ast(std::ostream& out, int tabs) const
{
	out	<< std::string(4*tabs, ' ')
		<< "FunctionCall" << memory_address()
		<< std::endl;
	m_expr->dump_ast(out, tabs+1);
	out << std::string(4*(tabs+1), ' ') << "Args" << std::endl;
	dump_args(out, tabs+1);
}

void FunctionCall::insert(Expr* expr)
{
	expr->set_parent(this);
	m_args.push_back(expr);
}

FunctionCall* FunctionCall::copy()
{
	auto expr = m_expr->copy();
	auto result = new FunctionCall(expr);
	expr->set_parent(result);

	std::for_each(
		std::begin(m_args),
		std::end(m_args),
		[&result](Expr* expr) {
			result->insert(expr->copy());
		}
	);

	return result;
}

