#ifndef __OPTIMIZER__HPP__
#define __OPTIMIZER__HPP__

#include <operations/basic_operation.hpp>
#include <tuple>
#include <syntax.hpp>
#include <transformations/hoister.hpp>

namespace jawe {

extern shared_node* program;

template<typename... Optimizations>
/** \brief Compilation phase that works on optimizing the AST.
 *
 * Currently, only optimization available in jawe is hoisting the variables
 * which is not an optimization per-se, but it's there to be a place holder
 * for optimizations that will be developed in the future.
 *
 * \see jawe::control
 */
class optimizer : public basic_operation {
public:
	void run() const {
		run(m_optimizations);
	}

private:
	std::tuple<Optimizations...> m_optimizations;

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I == sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>&) const {}

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I < sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>& optimizations) const {
		auto optimization =  std::get<I>(optimizations);
		optimization.run();
		run<I+1, Ts...>(optimizations);
	}
};
}

#endif // __OPTIMIZER__HPP__
