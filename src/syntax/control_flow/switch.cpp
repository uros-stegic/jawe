#include <control_flow/switch.hpp>

using namespace jawe;

Switch::Switch(Expr* expr, const std::vector<Command*>& cases)
	: m_expr(expr)
	, m_cases(cases)
{}

Switch::~Switch()
{
	delete m_expr;
	for(auto &c: m_cases) {
		delete c;
	}
}

void Switch::print(std::ostream& out) const {
	out << "switch( ";
	m_expr->print(out);
	out << ") {" << std::endl;
	for(auto &c : m_cases) {
		c->print(out);
		out << std::endl;
	}
	out << "}" << std::endl;
}

void Switch::dump_ast(std::ostream& out, int tabs) const {
	out << std::string(4*tabs, ' ') << "switch" << std::endl;
	m_expr->dump_ast(out, tabs+1);
	for(auto &c : m_cases) {
		c->dump_ast(out, tabs+1);
	}
}
