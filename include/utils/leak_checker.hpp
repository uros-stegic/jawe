#ifndef __MEM_LEAK_HPP__
#define __MEM_LEAK_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

namespace jawe {
template <typename T>
class leak_checker {
public:
	 leak_checker() {
		 leak_checker::s_counter++;
		 leak_checker::s_allocated_ptrs.push_back(this);
	 }
	~leak_checker() {
		leak_checker::s_counter--;
		auto start = std::begin(leak_checker::s_allocated_ptrs);
		auto end = std::end(leak_checker::s_allocated_ptrs);
		leak_checker::s_allocated_ptrs.erase(
			std::remove(start, end, this),
			end
		);
	}

	static inline unsigned int get() {
		return s_counter;
	}
	static inline bool check() {
		return s_counter == 0;
	}
	static auto begin() {
		return std::begin(s_allocated_ptrs);
	}
	static auto end() {
		return std::end(s_allocated_ptrs);
	}

private:
	static unsigned int s_counter;
	static std::vector<leak_checker*> s_allocated_ptrs;
};

class basic_node;
class leak_previewer {
public:
	static void show_leaked(basic_node*, std::ostream& = std::cerr);
};

template <typename T>
unsigned int leak_checker<T>::s_counter = 0;

template <typename T>
std::vector<leak_checker<T>*> leak_checker<T>::s_allocated_ptrs;
}

#endif // __MEM_LEAK_HPP__

