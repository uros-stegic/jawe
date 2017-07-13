#include <control_flow/switch.hpp>
#include <algorithm>

using namespace jawe;

Switch::Switch(Expr* expr, const std::vector<Command*>& cases)
	: Command(TSwitch)
	, m_expr(expr)
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
	out << std::string(4*tabs, ' ') << "switch " << memory_address() << std::endl;
	m_expr->dump_ast(out, tabs+1);
	for(auto &c : m_cases) {
		c->dump_ast(out, tabs+1);
	}
}

std::vector<Command*>& Switch::get_cases()
{
	return m_cases;
}

Switch* Switch::copy()
{
	std::vector<Command*> cp;
	cp.reserve(m_cases.size());
	std::for_each(
		std::begin(m_cases),
		std::end(m_cases),
		[&cp](Command* command) {
			cp.push_back(command->copy());
		}
	);
	auto expr = m_expr->copy();
	auto result = new Switch(expr, cp);
	expr->set_parent(result);
	
	std::for_each(
		std::begin(result->m_cases),
		std::end(result->m_cases),
		[&result](Command* command) {
			command->set_parent(result);
		}
	);
	return result;
}

