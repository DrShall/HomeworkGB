#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>
#include <queue>
#include <random>
#include <algorithm>

void test_thread(int num);

static std::mutex mt_cout;

static std::mutex sm;
static std::condition_variable prime_plus;
static std::queue<size_t> data_i;

static std::mutex things;

class pcout
{
		std::lock_guard<std::mutex> lg;
	public:
		pcout() : lg(std::lock_guard<std::mutex>(mt_cout)) 	{ }

		template <typename T>
		pcout& operator<<(const T& d)
		{
			std::cout << d;
			return *this;
		}

		pcout& operator<<(std::ostream& (*s)(std::ostream&))
		{
			std::cout << s;
			return *this;
		}
};

size_t sieve( size_t n );

void put_thing(std::vector<int> &vec);

void take_thing(std::vector<int> &vec);

void fill_vector(std::vector<int> &vec);
#endif
