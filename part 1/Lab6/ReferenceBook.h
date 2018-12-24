#pragma once
#include <map>
#include <string>
#include <vector>

class ReferenceBook
{
public:
	ReferenceBook();
	~ReferenceBook();
	std::vector<std::string> GetAllKey();
	std::vector<std::string> GetDataFor(std::string);
	void AddData(std::string, std::string);
	void RemoveAllDataWithKey(std::string);
	void RemoveData(std::string, std::string);	
private:
	std::multimap<std::string, std::string> data;
};

