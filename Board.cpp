#include "stdafx.h"
#include "Board.h"
#include <iostream>

bool Board::AddWord(Point start, Direction dir, const string &word)
{
	static unsigned int count = 0;
	bool retval = false;

	if (!m_validator->isValid(word) || word.length() == 0 || word.length() > m_size)
	{
		return retval;
	}
	if (dir != Direction::Left_toRight && dir != Direction::Top_ToBottom)
	{
		return retval;
	}

	if (start.x > (m_size - 1) || start.y > (m_size -1) || start.x < 0 || start.y < 0)
	{
		return retval;
	}


	if (dir == Direction::Left_toRight)
	{
		if ((start.y + word.length()) > m_size)
		{
			return retval;
		}


		bool overlapFound = false;
		bool foundNull = false;

		if (count != 0) {			
			for (size_t i = 0; i < word.length(); ++i)
			{
				if (m_structure[start.x ][start.y + i] != '\0') {

					if (m_structure[start.x][start.y + i] != word[i]) {
						overlapFound = false;
						break;
					}
					else {
						overlapFound = true;
					}

				}
				else {
					foundNull = true;
				}
			}
		}
		if (count == 0 || (overlapFound && foundNull)) {
			for (size_t i = 0; i < word.length(); ++i)
			{
				m_structure[start.x][start.y + i] = word[i];
			}
			retval = true;
		}
		
	}
	
	if (dir == Direction::Top_ToBottom)
	{
		if ((start.x + word.length()) > m_size)
		{
			return retval;
		}

		bool overlapFound = false;
		bool foundNull = false;

		if (count != 0) {
			for (size_t i = 0; i < word.length(); ++i)
			{
				if (m_structure[start.x + i][start.y] != '\0' ) {

					if (m_structure[start.x + i][start.y] != word[i]) {
						overlapFound = false;
						break;
					}
					else {
						overlapFound = true;
					}

				}
				else {
					foundNull = true;
				}
			}
		}
		if (count == 0 || (overlapFound && foundNull)) {
			for (size_t i = 0; i < word.length(); ++i)
			{
				m_structure[start.x + i][start.y] = word[i];
			}
			retval = true;
		}

	}

	if (retval == true)
	{
		count++;
	}
	return retval;
}

void Board::DisplayBoard() const
{
	cout << "\n";

	for (size_t i = 0; i < m_size; ++i)
	{
		for (size_t j = 0; j < m_size; ++j)
		{
			if (m_structure[i][j] != '\0') {

				cout << m_structure[i][j];
			}
			else
			{
				cout << "-";
			}

		}
		cout << "\n";
	}

}

bool Board::IsBoardFull() 
{
	bool retVal = true;

	if (!m_IsBoardFull) {
	
		for (size_t i = 0; i < m_size; ++i)
		{
			for (size_t j = 0; j < m_size; ++j)
			{
				if (m_structure[i][j] == '\0') {

					retVal = false;
					break;
				}

			}
		}

		m_GameOver = true;
		m_IsBoardFull = true;
	}
	return retVal;
}