#pragma once
#include <string>

using namespace std;

// Interface to check whether word is a valid word in English dictionary
class WordValidator
{
public:
	virtual ~WordValidator() = default;
	virtual bool isValid(const string &word) const = 0;

};
