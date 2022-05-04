#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

template <typename T> void swapPtr(T** first, T** second)
{
	T *tmp = *first;
	*first = *second;
	*second = tmp;
}

template <typename T> void sortPointers(std::vector<T*> &v)
{
	std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return *a < *b; });
}

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::string m_name;
	std::chrono::time_point<clock_t> m_beg;
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() -m_beg).count();
	}

public:
	Timer() : m_beg(clock_t::now()) { }
	Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

	void start(std::string name) {
		m_name = name;
		m_beg = clock_t::now();
	}
	void print() const {
		std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
	}
};

int way1( const std::string& str, const std::string& v);
int way2( const std::string& str, const std::string& v);
int way3( const std::string& str, const std::string& v);
int way4( const std::string& str, const std::string& v);

#endif
