// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "MyWordValidator.h"
#include <iostream>

using namespace std;



int main()
{
	MyWordValidator validator;
	Board b(4, &validator);

	Point p(0, 0);
	bool added = b.AddWord(p, Direction::Left_toRight, "ARE");
	if (added)
	{
		cout << "added";
	}

	
	added = b.AddWord(p, Direction::Top_ToBottom, "ATE");
	if (added)
	{
		cout << "added";
	}
	else {
		cout << "not added ";
	}
	added = b.AddWord(p, Direction::Top_ToBottom, "ATE");
	if (added)
	{
		cout << "added";
	}
	else {
		cout << "not added ";
	}

	added = b.AddWord(p, Direction::Left_toRight, "ATE");
	if (added)
	{
		cout << "added";
	}
	else {
		cout << "not added ";
	}

	p.x = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TEN");
	if (added)
	{
		cout << "added TEN";
	}
	else {
		cout << "not added ";
	}

	added = b.AddWord(p, Direction::Left_toRight, "TENT");
	if (added)
	{
		cout << "added TENT";
	}
	else {
		cout << "not added ";
	}

	p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "RENT");
	if (added)
	{
		cout << "added RENT";
	}
	else {
		cout << "not added ";
	}

	p.x = 0;
	added = b.AddWord(p, Direction::Top_ToBottom, "RENT");
	if (added)
	{
		cout << "added RENT";
	}
	else {
		cout << "not added ";
	}

	p.x = 2; p.y = 0;
	added = b.AddWord(p, Direction::Left_toRight, "EVER");
	if (added)
	{
		cout << "added EVER";
	}
	else {
		cout << "not added ";
	}
	b.DisplayBoard();
	added = b.AddWord(p, Direction::Left_toRight, "END");
	if (added)
	{
		cout << "added END";
	}
	else {
		cout << "not added ";
	}


	added = b.AddWord(p, Direction::Left_toRight, "ENDS");
	if (added)
	{
		cout << "added ENDS";
	}
	else {
		cout << "not added ";
	}

	p.x = 2; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "SO");
	if (added)
	{
		cout << "added SO";
	}
	else {
		cout << "not added ";
	}


	p.x = 0; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "IT");
	if (added)
	{
		cout << "added IT";
	}
	else {
		cout << "not added ";
	}

	p.x = 0; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "IT");
	if (added)
	{
		cout << "added IT";
	}
	else {
		cout << "not added ";
	}

	p.x = 3; p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TWO");
	if (added)
	{
		cout << "added TWO";
	}
	else {
		cout << "not added ";
	}

	p.x = 3; p.y = 1;
	added = b.AddWord(p, Direction::Left_toRight, "TWO");
	if (added)
	{
		cout << "added TWO";
	}
	else {
		cout << "not added ";
	}
	p.x = 2; p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TWO");
	if (added)
	{
		cout << "added TWO";
	}
	else {
		cout << "not added ";
	}

	p.x = 2; p.y = 2;
	added = b.AddWord(p, Direction::Top_ToBottom, "TOO");
	if (added)
	{
		cout << "added TWO";
	}
	else {
		cout << "not added ";
	}

	b.DisplayBoard();
	cout << b.IsBoardFull();

#if 0
	Board b2(10, &validator);

	while (!b2.IsBoardFull() && b2.IsGameOver())
	{
		cout << "Enter the start point where you want the word, indexes separated by space \n";
		cin >> 


	}

#endif

    return 0;
}

