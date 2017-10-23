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

/** \brief Empty class used for specialization of non-container class template.
 */
class empty {};
template<typename T = empty> class scope;

/** \brief Scope implementation when user needs to map certain type to variable's definition.
 *
 * Intent of this class is to be used only by class jawe::utils::scope when user needs to map
 * variable to some other object (e.g. llvm::AllocaInst).
 *
 * @see jawe::utils::scope
 */
template<typename T = empty>
class scope_pimpl {
	friend class scope<T>;
	std::vector<std::map<std::string, T>> m_scope;

	/**
	 * @see jawe::utils::scope<T>::fetch()
	 */
	std::optional<T> fetch(const std::string& var_name) const	{
		for(auto scope = m_scope.rbegin(); scope != m_scope.rend(); scope++) {
			for(auto&& var : *scope) {
				if( var.first == var_name ) return var.second;
			}
		}
		return {};
	}

	/**
	 * @see jawe::utils::scope<T>::fetch_last()
	 */
	std::optional<T> fetch_last(const std::string& var_name) const	{
		if( m_scope.size() > 0 ) {
			auto scope = m_scope.rbegin();
			for(auto&& var : *scope) {
				if( var.first == var_name ) return var.second;
			}
			return {};
		 }
	}

	/**
	 * @see jawe::utils::scope<T>::insert()
	 */
	void insert(const std::string& var_name, const T& t = T{})	{ (*m_scope.rbegin())[var_name] = t; }

	/**
	 * @see jawe::utils::scope<T>::dump()
	 */
	void dump() {
		for(auto&& sc : m_scope) {
			std::cout << "*********" << std::endl;
			for(auto&& var : sc) {
				std::cout << var.first << " " << var.second << std::endl;
			}
		}
	}
};

/** \brief Scope implementation when no additional information about variables are needed.
 *
 * When user just wants to store variable names in scoped manner, std::map is overkill
 * since it would have pure overhead with unused second map parameter. Instead implementation
 * of scope in this case is done with std::set container (more precisely, a vector of sets).
 * This class is not to be used by it self, it's a implementational detail.
 *
 * @see jawe::utils::scope
 */
template<>
class scope_pimpl<empty> {
	friend class scope<empty>;
	std::vector<std::set<std::string>> m_scope;

	/**
	 * @see jawe::utils::scope<T>::insert()
	 */
	void insert(const std::string& var_name) {
		m_scope.rbegin()->insert(var_name);
	}

	/**
	 * @see jawe::utils::scope<T>::dump()
	 */
	void dump() {
		for(auto&& sc : m_scope) {
			std::cout << "*********" << std::endl;
			for(auto&& var : sc) {
				std::cout << var << std::endl;
			}
		}
	}

	/**
	 * @see jawe::utils::scope<T>::fetch()
	 */
	std::optional<empty> fetch(const std::string& var_name) const	{
		auto f = std::find_if(
			m_scope.rbegin(),
			m_scope.rend(),
			[var_name](auto scope) { return std::find(scope.begin(), scope.end(), var_name) != scope.end(); }
		);
		if( f == m_scope.rend() ) {
			return {};
		}
		return empty{};
	}

	/**
	 * @see jawe::utils::scope<T>::fetch_last()
	 */
	std::optional<empty> fetch_last(const std::string& var_name) const	{
			auto f = std::find(m_scope.rbegin()->begin(),
												 m_scope.rbegin()->end(),
												 var_name);

		if( f == m_scope.rbegin()->end() ) {
			return {};
		}
		return empty{};
	}
};

/** \brief Encapsulates scope behavior.
 *
 * When user needs to store variables in scoped manner, this class template can be used.
 * Two internal versions are provided. If user needs to map a variable to certain type, then
 * scope<T> should be used, otherwise scope (without template parameter) is enough.
 *
 * @param T type of mapped type
 */
template<typename T>
class scope {
public:
	/**
	 * Searches for variable starting with the most inner scope.
	 *
	 * @param var_name name of the variable which is to be found.
	 * @return empty optional if variable with said name was found, returns mapped object wrapped in std::optional
	 * otherwise.
	 */
	std::optional<T> fetch(const std::string& var_name) const {
		return m_pimpl.fetch(var_name);
	}

	/**
	 * Searches for variable ONLY in most inner (currently open) scope.
	 *
	 * @param var_name name of the variable which is to be found.
	 * @return empty optional if variable with said name was found, returns mapped object wrapped in std::optional
	 * otherwise.
	 */
	std::optional<T> fetch_last(const std::string& var_name) const {
		return m_pimpl.fetch_last(var_name);
	}

	/**
	 * Opens new scope.
	 */
	void open_scope()  { m_pimpl.m_scope.emplace_back(); }

	/**
	 * Closes most recently opened scope.
	 */
	void close_scope() { m_pimpl.m_scope.pop_back();  }

	/**
	 * Prints all scopes with their variables.
	 *
	 * This function is used for debugging purposes.
	 */
	void dump() { m_pimpl.dump(); }

	/**
	 * Inserts new variable in most recently opened scope.
	 *
	 * This function should be used only if no template arguments were provided while
	 * creating this object.
	 *
	 * @param var_name name of the variable that is to be inserted.
	 */
	void insert(const std::string& var_name) {
		m_pimpl.insert(var_name);
	}

	/**
	 * Inserts new variable (/w mapped object) in most recently opened scope.
	 *
	 * This function should be used only if template argument for mapped object was provided.
	 *
	 * @param var_name name of the variable that is to be inserted.
	 * @param t object asociated with this variable's name.
	 */
	void insert(const std::string& var_name, const T& t) {
		m_pimpl.insert(var_name, t);
	}
private:
	scope_pimpl<T> m_pimpl;
};

}
}
#endif // __SCOPE_HPP__
