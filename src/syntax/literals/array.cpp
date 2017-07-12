#include <literals/array.hpp>
#include <algorithm>

using namespace jawe;

Array::Array()
{}

Array::Array(const std::vector<Expr*>& elements)
	: m_elements(elements)
{}

Array::~Array()
{
	for(auto &elem : m_elements) {
		delete elem;
	}
}

void Array::print(std::ostream& out) const
{
	out << "[";
	if( m_elements.size() == 0 ) {
		out << "]";
		return;
	}
	(*m_elements.begin())->print(out);

	std::for_each(
		++m_elements.begin(),
		m_elements.end(),
		[&](Expr *e) { out << ", "; e->print(out); }
	);
	out << "]";
}

void Array::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "Array("
		<< m_elements.size()
		<< ")"
		<< std::endl;
	for(auto &elem: m_elements) {
		elem->dump_ast(out, tabs+1);
	}
}

Array* Array::copy()
{
	std::vector<Expr*> cp;
	cp.reserve(m_elements.size());
	std::for_each(
		std::begin(m_elements),
		std::end(m_elements),
		[&cp](Expr* expr) {
			cp.push_back(expr->copy());
		}
	);
	return new Array(cp);
}

