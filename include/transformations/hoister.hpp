#ifndef __HOISTER_HPP__
#define __HOISTER_HPP__

#include <transformations/basic_transformation.hpp>
#include <command.hpp>

namespace jawe {
class Hoister : public BasicTransformation {
public:
	void transform() const;

private:
	void decouple(Command*) const;
};
}

#endif // __HOISTER_HPP__

