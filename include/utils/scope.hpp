#ifndef __SCOPE_HPP__
#define __SCOPE_HPP__

#include <vector>
#include <map>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

namespace jawe {
namespace utils {

using empty = bool;
template<typename T = empty> class scope;

template<typename T = empty>
class scope_pimpl {
	friend class scope<T>;
	std::vector<std::map<std::string, T>> m_scope;

	std::optional<T> fetch(const std::string& var_name) const	{
		for(auto&& scope : m_scope) {
			for(auto&& var : scope) {
				if( var.first == var_name ) return var.second;
			}
		}
		return {};
	}

	std::optional<T> fetch_last(const std::string& var_name) const	{
		if( m_scope.size() > 0 ) {
			auto scope = m_scope.rbegin();
			for(auto&& var : *scope) {
				if( var.first == var_name ) return var.second;
			}
			return {};
		 }
	}

	void insert(const std::string& var_name, const T& t = T{})	{ (*m_scope.rbegin())[var_name] = t; }
	void dump() {
		for(auto&& sc : m_scope) {
			std::cout << "*********" << std::endl;
			for(auto&& var : sc) {
				std::cout << var.first << std::endl;
			}
		}
	}
};

template<>
class scope_pimpl<empty> {
	friend class scope<empty>;
	std::vector<std::set<std::string>> m_scope;

	void insert(const std::string& var_name) {
		m_scope.rbegin()->insert(var_name);
	}
	void dump() {
		for(auto&& sc : m_scope) {
			std::cout << "*********" << std::endl;
			for(auto&& var : sc) {
				std::cout << var << std::endl;
			}
		}
	}

	std::optional<empty> fetch(const std::string& var_name) const	{
		auto f = std::find_if(
			m_scope.rbegin(),
			m_scope.rend(),
			[var_name](auto scope) { return std::find(scope.begin(), scope.end(), var_name) != scope.end(); }
		);
		if( f == m_scope.rend() ) {
			return {};
		}
		return true;
	}

	std::optional<empty> fetch_last(const std::string& var_name) const	{
			auto f = std::find(m_scope.rbegin()->begin(),
												 m_scope.rbegin()->end(),
												 var_name);

		if( f == m_scope.rbegin()->end() ) {
			return {};
		}
		return true;
	}
};

template<typename T>
class scope {
public:
	std::optional<T> fetch(const std::string& var_name) const {
		return m_pimpl.fetch(var_name);
	}

	std::optional<T> fetch_last(const std::string& var_name) const {
		return m_pimpl.fetch_last(var_name);
	}

	void open_scope()  { m_pimpl.m_scope.emplace_back(); }
	void close_scope() { m_pimpl.m_scope.pop_back();  }
	void dump() { m_pimpl.dump(); }

	void insert(const std::string& var_name) {
		m_pimpl.insert(var_name);
	}
	void insert(const std::string& var_name, const T& t) {
		m_pimpl.insert(var_name, t);
	}
private:
	scope_pimpl<T> m_pimpl;
};

}
}
#endif // __SCOPE_HPP__
