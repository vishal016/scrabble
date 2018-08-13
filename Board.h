#pragma once
#include <vector>
#include "WordValidator.h"

using namespace std;

enum class Direction
{
	Left_toRight,
	Top_ToBottom
};

struct Point
{
	unsigned int x;
	unsigned int y;

	Point(unsigned int dim1, unsigned int dim2) : x(dim1), y(dim2) {}
};


class Board {

public:
	Board(unsigned int dim, WordValidator * validator) : m_size (dim), m_structure(m_size, (vector<char> (m_size, 0))), m_validator (validator),
		m_GameOver(false), m_IsBoardFull(false)
	{
		
	}
	~Board() = default;
	bool AddWord(Point start, Direction dir, const string &word );
	void DisplayBoard() const;
	inline bool IsGameOver() { return m_GameOver;  }
	bool IsBoardFull() ;
	inline void SetGameOver(bool gameOver) { m_GameOver = gameOver;  }

private:



private:
	unsigned int m_size;
	vector<vector<char>> m_structure;
	WordValidator * m_validator;
	bool m_GameOver;
	bool m_IsBoardFull;
};