#include <literals/array.hpp>
#include <algorithm>

using namespace jawe;

Array::Array()
	: AbstractObject(TArray)
{}

Array::Array(const std::vector<Expr*>& elements)
	: AbstractObject(TArray)
	, m_elements(elements)
{}

Array::~Array()
{
	for(auto &elem : m_elements) {
		delete elem;
	}
}

void Array::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
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
		<< ") " << memory_address()
		<< std::endl;
	for(auto &elem: m_elements) {
		elem->dump_ast(out, tabs+1);
	}
}

void Array::insert(Expr* expr)
{
	m_elements.push_back(expr);
	expr->set_parent(this);
}

Array* Array::copy()
{
	auto result = new Array();
	std::for_each(
		std::begin(m_elements),
		std::end(m_elements),
		[&result](Expr* expr) {
			result->insert(expr->copy());
		}
	);
	return result;
}

