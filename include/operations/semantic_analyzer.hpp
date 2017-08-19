#ifndef __SEMANTIC_ANALYZER__HPP__
#define __SEMANTIC_ANALYZER__HPP__

#include <operations/basic_operation.hpp>
#include <tuple>
#include <syntax.hpp>
#include <operations/reference_checker.hpp>

namespace jawe {

extern shared_node* program;

template<typename... Analyzations>
class semantic_analyzer : public basic_operation {
public:
	void run() const {
		run(m_analyzations);
	}

private:
	std::tuple<Analyzations...> m_analyzations;

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I == sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>&) const {}

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I < sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>& analyzations) const {
		auto analyzation =  std::get<I>(analyzations);
		analyzation.run();
		run<I+1, Ts...>(analyzations);
	}
};
}

#endif // __SEMANTIC_ANALYZER__HPP__
