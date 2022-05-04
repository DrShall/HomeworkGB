#include "myclasses.h"

int way1( const std::string& str, const std::string& v)
{
	size_t num = std::count_if(str.begin(), str.end(),[&](const auto& c){ return v.find(c) != std::string::npos; });
	std::cout << "Way1 num = " << num << std::endl;
	return num;
}

int way2( const std::string& str, const std::string& v)
{
	size_t num = std::count_if(str.begin(), str.end(),[&](const auto& c)
	{
		for(int i = 0; i < v.size(); ++i)
		{
			if(v[i] == c)
				return true;
		}
		return false;
	});
	std::cout << "Way2 num = " << num << std::endl;
	return num;
}

int way3( const std::string& str, const std::string& v)
{
	size_t num = 0;
	for(size_t i = 0; i < str.size(); ++i)
	{
		if( v.find(str[i]) != std::string::npos )
			++num;
	}
	std::cout << "Way3 num = " << num << std::endl;
	return num;
}

int way4( const std::string& str, const std::string& v)
{
	size_t num = 0;
	for(size_t i = 0; i < str.size(); ++i)
	{
		for(size_t j = 0; j < v.size(); ++j)
		{
			if(str[i] == v[j])
			{
				++num;
				break;
			}
		}
	}
	std::cout << "Way4 num = " << num << std::endl;
	return num;
}
