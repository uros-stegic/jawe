#ifndef __OPTIMIZER__HPP__
#define __OPTIMIZER__HPP__

#include <operations/basic_operation.hpp>
#include <tuple>
#include <syntax.hpp>
#include <transformations/hoister.hpp>

namespace jawe {

extern Command* program;

template<typename... Optimizations>
class Optimizer : public basic_operation {
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
		optimization.transform();
		run<I+1, Ts...>(optimizations);
	}
};
}

#endif // __OPTIMIZER__HPP__

