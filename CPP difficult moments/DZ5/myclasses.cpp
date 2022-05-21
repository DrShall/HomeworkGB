#include "myclasses.h"

void countSentence( std::string& str)
{
	const std::string punctuationMarks { ".?!"};
	std::set< std::pair<std::string, int> > sentences;
	std::string tempStr;
//	std::pair<std::string, int> p;
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
			tempStr +=c;
		}

	}

	sort( sentences.begin(), sentences.end(), [](std::pair<std::string,int>& p1, std::pair<std::string,int>& p2){
		return p1.second < p2.second;
	});
	for( auto [str, c] : sentences)
	{
		std::cout << str << " " << c << std::endl;
	}
}

