#include "stdafx.h"
#include "WordValidator.h"

class MyWordValidator : public  WordValidator
{
public:
	virtual ~MyWordValidator() = default;

	bool isValid(const string &word)
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

};