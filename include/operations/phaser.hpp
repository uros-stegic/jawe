#ifndef __PHASER_HPP__
#define __PHASER_HPP__

#include <tuple>

namespace jawe {
template<typename... Phases>
class Phaser {
public:
	void run() const {
		run(m_phases);
	}

private:
	std::tuple<Phases...> m_phases;

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I == sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>&) const {}

	template<std::size_t I = 0, typename... Ts>
	inline typename std::enable_if<I < sizeof...(Ts), void>::type
	run(const std::tuple<Ts...>& phases) const {
		auto phase = std::get<I>(phases);
		phase.run();
		run<I+1, Ts...>(phases);
	}
};
}

#endif // __PHASER_HPP__

