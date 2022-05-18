#ifndef MYCLASSES_H
#define MYCLASSES_H
//#include <string>
//#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void insert_sorted(std::vector<T> &v, const T &val)
{
	auto in = std::find_if(v.begin(), v.end(), [&val](const T &el){ return el >= val; });
	if( in != v.end())
		v.insert( in, val);
	else
		v.push_back(val);
}

#endif
