#ifndef __MEM_LEAK_HPP__
#define __MEM_LEAK_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

namespace jawe {

/** \brief Simple reference counting mechanism for checking for memory leaks in AST.
 *
 * Since all AST nodes are created from a single class hierarchy, base class of that
 * hierarchy can inherit from this class which counts the number of allocations and
 * deallocations. If the difference between these two numbers is zero at the end of
 * compilation then no memory leaks happend.
 *
 * This class also keeps the memory addresses of allocated objects so when previewing AST,
 * one can more easily figure out which AST nodes didn't get deallocated.
 *
 * NOTICE: One should remove inheritance from this class in production build for perfomance reasons.
 */
template <typename T>
class leak_checker {
public:
	/**
	 * Increments static counter when creating object of this type. Also, adds it to the list of allocated objects.
	 */
	 leak_checker() {
		 leak_checker::s_counter++;
		 leak_checker::s_allocated_ptrs.push_back(this);
	 }

	/**
	 * Decrements static counter when destructing object of this type. Also, removes it from the list of allocated
	 * objects.
	 */
	~leak_checker() {
		leak_checker::s_counter--;
		auto start = std::begin(leak_checker::s_allocated_ptrs);
		auto end = std::end(leak_checker::s_allocated_ptrs);
		leak_checker::s_allocated_ptrs.erase(
			std::remove(start, end, this),
			end
		);
	}

	/** Gets the number of allocated objects. */
	static inline unsigned int get() {
		return s_counter;
	}

	/** Checks if there's any allocated objects left. */
	static inline bool check() {
		return s_counter == 0;
	}

	/** Gets InputIterator of the beginning of the list of allocated objects. */
	static auto begin() {
		return std::begin(s_allocated_ptrs);
	}

	/** Gets InputIterator of the one-past-end of the list of allocated objects. */
	static auto end() {
		return std::end(s_allocated_ptrs);
	}

private:
	static unsigned int s_counter;
	static std::vector<leak_checker*> s_allocated_ptrs;
};

class basic_node;

/** \brief Shows a list of unallocated object. */
class leak_previewer {
public:
	/** Shows a list of unallocated object. */
	static void show_leaked(basic_node*, std::ostream& = std::cerr);
};

template <typename T>
unsigned int leak_checker<T>::s_counter = 0;

template <typename T>
std::vector<leak_checker<T>*> leak_checker<T>::s_allocated_ptrs;
}

#endif // __MEM_LEAK_HPP__

