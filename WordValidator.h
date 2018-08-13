#pragma once
#include <string>

using namespace std;

class WordValidator
{
public:
	virtual ~WordValidator() = default;
	virtual bool isValid(const string &word) const = 0;

};
