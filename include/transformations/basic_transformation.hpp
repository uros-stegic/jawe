#ifndef __BASIC_TRANSFORMATION_HPP__
#define __BASIC_TRANSFORMATION_HPP__

namespace jawe {
/** \brief Base class of all AST transformation
 *
 * @see jawe::hoister
 */
class basic_transformation {
public:
	void run() const;
};
}

#endif // __BASIC_TRANSFORMATION_HPP__
