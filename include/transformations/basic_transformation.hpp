#ifndef __BASIC_TRANSFORMATION_HPP__
#define __BASIC_TRANSFORMATION_HPP__

#include <syntax.hpp>

namespace jawe {
class BasicTransformation {
public:
	void transform() const;
};

template<class... Ts>
struct compose: Ts... {
	using Ts::operator()...;
};
template<class... Ts> compose(Ts...) -> compose<Ts...>;
}

#endif // __BASIC_TRANSFORMATION_HPP__

