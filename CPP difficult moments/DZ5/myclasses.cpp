#include "myclasses.h"

bool cmp (std::pair<std::string,int>& p1, std::pair<std::string,int>& p2)
{
	if(p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

void countSentence( std::string& str)
{
	const std::string punctuationMarks { ".?!"};
	std::set< std::pair<std::string, int>, decltype(cmp)* > sentences(&cmp);
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

//	std::sort( sentences.begin(), sentences.end(), [](std::pair<std::string,int>& p1, std::pair<std::string,int>& p2){ return p1.second < p2.second; });
	for( auto [str, c] : sentences)
	{
		std::cout << str << "  - " << c << std::endl;
	}
}

