#include "myclasses.h"

void test_thread(int num)
{
	pcout() << "Start thread " << num << std::endl;
	pcout() << "Stop thread " << num << std::endl;
}

size_t sieve( size_t n )   //массив простых чисел и номер простого числа, которое нужно найти
{
	size_t num = n * 2;   // число элементов для массива чисел
	size_t *numbers = new size_t[num];   // массив для чисел
	size_t *primes = new size_t[n];   //массив простых чисел

	for(size_t i = 0; i < num; ++i)
		numbers[i] = i;

	primes[0] = 2;   // первое простое число
	size_t ind = 0;   // индекс текущего простого числа

	while ( ind < n) {
			size_t p = primes[ind++];   // запоминаем текущее простое число
			std::lock_guard<std::mutex> lk(sm);
			data_i.push(ind);

			for (int j = p * 2; j < num; j += p)
				numbers[j] = 0;   // обнуляем все кратные ему числа в массиве

			while (numbers[p + 1] == 0)
				p++; // ищем следующее ненулевое число

			prime_plus.notify_all();

			if (p + 1 >= num)   // если выйдем за границы, расширяем массив
			{
				size_t *tmp = new size_t[num * 2];

				for (int k = 0; k < num; k++)
					tmp[k] = numbers[k];

				delete[] numbers;

				num *= 2;
				numbers = tmp;

				for (int j = num / 2; j < num; j++)   // заполняем новую часть массива числами
					numbers[j] = j;

				ind = 0;   // возвращаемся к начальной стадии просеивания
			} else
			{
				primes[ind] = p + 1;   // запоминаем новое простое число
			}

		}
	size_t res = primes[n-1];
	delete[] numbers;
	delete[] primes;
	return res;
}

void fill_vector(std::vector<int> &vec)
{
	std::random_device rd;
	std::mt19937 gen{rd()};
	std::normal_distribution<> d{100, 50};
	std::generate(vec.begin(), vec.end(), [&]{ return d(gen); });
}

void put_thing(std::vector<int> &vec)
{
	while(!vec.empty())
	{
	std::chrono::milliseconds sec(1000);
	std::this_thread::sleep_for(sec);

	std::random_device rd;
	std::mt19937 gen{rd()};
	std::normal_distribution<> d{100, 50};

	std::lock_guard lkt(things);
	vec.push_back(0);
	std::generate(vec.begin(), vec.end(), [&]{ return d(gen); });
	std::cout << std::endl << "Owner put " << *(vec.end()-1) << std::endl;
	for_each(vec.begin(), vec.end(), [&](int it){ std::cout << it << " "; });
	std::cout << std::endl;
	}
	exit(0);
}

void take_thing(std::vector<int> &vec)
{
	while(!vec.empty())
	{
	std::chrono::milliseconds hsec(500);
	std::this_thread::sleep_for(hsec);
	std::lock_guard lkt(things);
	auto it = std::max_element(vec.begin(), vec.end());
	std::cout << std::endl << "Thief took " << *it << std::endl;
	vec.erase(it);
	for_each(vec.begin(), vec.end(), [&](int it){ std::cout << it << " "; });
	std::cout << std::endl;
	}
	exit(0);
}
