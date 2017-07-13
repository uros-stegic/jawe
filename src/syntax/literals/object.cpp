#include <literals/object.hpp>
#include <algorithm>
#include <utility>

using namespace jawe;

Object::Object()
	: AbstractObject(TObject)
{}
Object::Object(const std::map<std::string, Expr*>& pairs)
	: AbstractObject(TObject)
	, m_pairs(pairs)
{}

Object::~Object()
{
	for(auto &i : m_pairs) {
		delete i.second;
	}
}

void Object::set(std::string name, Expr* expr)
{
	auto e = m_pairs.find(name);
	if( e != std::end(m_pairs) ) {
		delete e->second;
	}
	m_pairs[name] = expr;
	expr->set_parent(this);
}

void Object::print(std::ostream& out) const
{
	out << "{";
	if( m_pairs.size() == 0 ) {
		out << "}";
		return;
	}
	out << std::endl;
	print_pair(out, *m_pairs.begin());

	std::for_each(
		++m_pairs.begin(),
		m_pairs.end(),
		[&](std::pair<std::string, Expr*> p) {
			out << "," << std::endl;
			print_pair(out, p);
		}
	);
	out << std::endl << "}";
}

void Object::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "Object"
		<< "(" << m_pairs.size() << ") [" << this << ": from <" << get_parent() << ">]"
		<< std::endl;
	for(auto &p: m_pairs) {
		dump_pair_ast(out, p, tabs+1);
	}
}

void Object::print_pair(std::ostream& out, const std::pair<std::string, Expr*>& p) const
{
	out << p.first << ": ";
	p.second->print(out);
}
void Object::dump_pair_ast(std::ostream& out, const std::pair<std::string, Expr*>& p, int tabs) const
{
	out << std::string(4*tabs, ' ') << "KeyValue" << std::endl;
	out << std::string(4*(tabs+1), ' ') << p.first << std::endl;
	p.second->dump_ast(out, tabs+1);
}

Object* Object::copy()
{
	auto result = new Object();
	for(auto& p: m_pairs) {
		result->set(p.first, p.second->copy());
	}
	return result;
}

