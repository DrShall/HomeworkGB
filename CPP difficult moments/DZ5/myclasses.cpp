#include "myclasses.h"

void countSentence( std::string& str)
{
	struct cmp
	{
			bool operator()(const std::pair<std::string,int>& p1, const std::pair<std::string,int>& p2) const
			{
				if(p1.second == p2.second)
					return p1.first < p2.first;
			else
					return p1.second < p2.second;
			}
	};

	const std::string punctuationMarks { ".?!"};
	std::set< std::pair<std::string,int>, cmp> sentences;
	std::string tempStr;
	int count_c = 1;

	for( const char& c : str)
	{
		if (punctuationMarks.find(c) != std::string::npos)
		{
			tempStr += c;
			sentences.insert({tempStr, count_c});
			tempStr = "";
			count_c = 1;
		}
		else
		{
			if( c == ' ' && !tempStr.empty())
			{
				count_c++;
			}
			else if(c == ' ' && tempStr.empty())
				continue;
			tempStr +=c;
		}

	}

	for( auto [str, c] : sentences)
	{
		std::cout << str << "  - " << c << std::endl;
	}
}

