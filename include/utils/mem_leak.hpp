#ifndef __MEM_LEAK_HPP__
#define __MEM_LEAK_HPP__

template <typename T>
class LeakChecker {
public:
	 LeakChecker() { LeakChecker::s_counter++; }
	~LeakChecker() { LeakChecker::s_counter--; }

	static inline unsigned int get() {
		return s_counter;
	}
	static inline bool check() {
		return s_counter == 0;
	}

private:
	static unsigned int s_counter;
};

template <typename T>
unsigned int LeakChecker<T>::s_counter = 0;
#endif // __MEM_LEAK_HPP__

