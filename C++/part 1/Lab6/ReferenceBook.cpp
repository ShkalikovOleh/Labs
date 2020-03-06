#include "ReferenceBook.h"
#include <vector>


ReferenceBook::ReferenceBook()
{
}


ReferenceBook::~ReferenceBook()
{
}

std::vector<std::string> ReferenceBook::GetAllKey()
{
	std::vector<std::string> result;
	for (auto it = data.cbegin(); it != data.cend(); ++it) {
		result.push_back(it->first);
	}
	return result;
}

std::vector<std::string> ReferenceBook::GetDataFor(std::string key)
{
	auto fit = data.equal_range(key);
	std::vector<std::string> result;
	for (auto it = fit.first; it != fit.second; ++it) {
		result.push_back(it->second);
	}
	return result;
}

void ReferenceBook::AddData(std::string key, std::string value)
{
	data.insert(std::make_pair(key, value));
}

void ReferenceBook::RemoveAllDataWithKey(std::string key)
{	
	data.erase(key);
}

void ReferenceBook::RemoveData(std::string key, std::string value)
{
	auto arr = data.equal_range(key);
	std::vector<std::multimap<std::string, std::string>::iterator> iterators;
	for (auto it = arr.first; it != arr.second; ++it) {
		if (it->second == value)
			iterators.push_back(it);
	}
	for (auto it = iterators.cbegin(); it != iterators.cend(); ++it) {
		data.erase(*it);
	}
}
