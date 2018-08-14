#include "stdafx.h"
#include "Board.h"
#include <iostream>

// Function to add word to the board after doing checks on the word 
// Arguments Point start --> Starting coordiates of the word
// e.g. in a  board like below start coordiates of T are (1,0), start point for W is (2,1)
// ARE
// TOO
// EWF

//  Direction dir-->>> can be leftToRight or TopToBottom
// const string &word->>> Word to be added
bool Board::AddWord(Point start, Direction dir, const string &word)
{
	static unsigned int count = 0;
	bool retval = false;

	// If Board is full or game over flag set, no more words can be added
	if (this->IsGameOver() || m_IsBoardFull)
	{
		return retval;
	}
	// If invalid word, it cannot be added
	if (!m_validator->isValid(word) || word.length() == 0 || word.length() > m_size)
	{
		return retval;
	}
	// If invalid direction of word, it cannot be added
	if (dir != Direction::Left_toRight && dir != Direction::Top_ToBottom)
	{
		return retval;
	}

	// If the starting point of the word is invalid, it cannot be added
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

		// If not the intial word, then atleast one characters of this word have to be adjacent to one character already there on board
		// Atleast one character of the word has to be added to a space existing on the board
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

// Function to display the board contents. For emply spaces, a '-' is displayed.
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

// Function to check if the board has any spaces left
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