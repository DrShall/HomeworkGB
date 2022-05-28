#include "myclasses.h"

void test_thread(int num)
{
	pcout() << "Start thread " << num << std::endl;
	pcout() << "Stop thread " << num << std::endl;
}

bool isPrime(int n)
{
	if( n < 4)   //2 и 3 простые числа
		return true;

	if( n % 2 == 0)   //четные числа не являются простыми
	{
		return false;
	}


	for( int i = 3; i*i < n; i+=2)   //перебираем нечетные делители до корень из n
	{
		if( n % i == 0)
		{
			return false;
		}
	}

	return true;
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

			if (p + 1 >= num) { // если выйдем за границы, расширяем массив
				size_t *tmp = new size_t[num * 2];

				for (int k = 0; k < num; k++)
					tmp[k] = numbers[k];

				delete[] numbers;

				num *= 2;
				numbers = tmp;

				for (int j = num / 2; j < num; j++)
					numbers[j] = j;    // заполняем новую часть массива числами

				ind = 0; // возвращаемся к начальной стадии просеивания
			} else
			{
				primes[ind] = p + 1; // запоминаем новое простое число
			}

		}
	size_t res = primes[n-1];
	delete[] numbers;
	delete[] primes;
	return res;
}
