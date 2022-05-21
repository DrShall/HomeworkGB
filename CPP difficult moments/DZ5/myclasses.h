#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <string>
#include <iostream>
#include <set>
#include <iterator>
#include <unordered_set>
#include <algorithm>

template<typename Iter>
void printWords(const Iter& it_b, const Iter& it_e)
{
	std::unordered_set<std::string> words(it_b, it_e);
	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, ", "));
}

void countSentence( std::string& str);

#endif
