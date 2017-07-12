#include <operators/function_call.hpp>
#include <algorithm>

using namespace jawe;

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

void FunctionCall::print(std::ostream& out) const
{
	m_expr->print(out);
	out << "(";
	print_args(out);
	out << ")";
}

void FunctionCall::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "FunctionCall" << std::endl;
	m_expr->dump_ast(out, tabs+1);
	out << std::string(4*(tabs+1), ' ') << "Args" << std::endl;
	dump_args(out, tabs+1);
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

FunctionCall* FunctionCall::copy()
{
	std::vector<Expr*> cp;
	cp.reserve(m_args.size());
	std::for_each(
		std::begin(m_args),
		std::end(m_args),
		[&cp](Expr* expr) {
			cp.push_back(expr->copy());
		}
	);
	return new FunctionCall(m_expr->copy(), cp);
}

