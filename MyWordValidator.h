#pragma once
#include "stdafx.h"
#include "WordValidator.h"

// A basic implementation of the word validator that checks only that the characters in the word are alphanumeric
class MyWordValidator : public  WordValidator
{
public:
	virtual ~MyWordValidator() {}

	virtual bool isValid(const string &word) const; 

}; 


 bool MyWordValidator::isValid(const string &word) const
{
	bool valid = true;

	for (size_t i = 0; i < word.length(); ++i)
	{
		if (word[i] >= 'A' && word[i] <= 'Z') {
			continue;
		}
		else {
			valid = false;
			break;
		}
	}

	return true;
}