#ifndef __LAMBDA_COMPOSER_HPP__
#define __LAMBDA_COMPOSER_HPP__

namespace jawe {
	/** \brief Main tool for composing lambdas in pattern matching fashion in std::visit algorithm */
	template<class... Ts>
	struct lambda_composer: Ts... {
		using Ts::operator()...;
	};
	template<class... Ts> lambda_composer(Ts...) -> lambda_composer<Ts...>;
}

#endif // __LAMBDA_COMPOSER_HPP__

