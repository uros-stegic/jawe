#ifndef __MEM_LEAK_HPP__
#define __MEM_LEAK_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

namespace jawe {
template <typename T>
class LeakChecker {
public:
	 LeakChecker() {
		 LeakChecker::s_counter++;
		 LeakChecker::s_allocated_ptrs.push_back(this);
	 }
	~LeakChecker() {
		LeakChecker::s_counter--;
		auto start = std::begin(LeakChecker::s_allocated_ptrs);
		auto end = std::end(LeakChecker::s_allocated_ptrs);
		LeakChecker::s_allocated_ptrs.erase(
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
	static std::vector<LeakChecker*> s_allocated_ptrs;
};

class Command;
class LeakPreviewer {
public:
	static void show_leaked(Command*, std::ostream& = std::cerr);
};

template <typename T>
unsigned int LeakChecker<T>::s_counter = 0;

template <typename T>
std::vector<LeakChecker<T>*> LeakChecker<T>::s_allocated_ptrs;
}

#endif // __MEM_LEAK_HPP__

