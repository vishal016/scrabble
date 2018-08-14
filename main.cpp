// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "MyWordValidator.h"
#include <iostream>

using namespace std;

void UnitTest1(void);


int main()
{
	UnitTest1();


    return 0;
}

// Function to test adding words to a 4 by 4 board
void UnitTest1(void)
{
	MyWordValidator validator;
	Board b(4, &validator);

	Point p(0, 0);
	bool added = b.AddWord(p, Direction::Left_toRight, "ARE");
	if (added)
	{
		cout << "added" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	added = b.AddWord(p, Direction::Top_ToBottom, "ATE");
	if (added)
	{
		cout << "added" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}
	added = b.AddWord(p, Direction::Top_ToBottom, "ATE");
	if (added)
	{
		cout << "added" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	added = b.AddWord(p, Direction::Left_toRight, "ATE");
	if (added)
	{
		cout << "added" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TEN");
	if (added)
	{
		cout << "added TEN" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	added = b.AddWord(p, Direction::Left_toRight, "TENT");
	if (added)
	{
		cout << "added TENT" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "RENT");
	if (added)
	{
		cout << "added RENT" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 0;
	added = b.AddWord(p, Direction::Top_ToBottom, "RENT");
	if (added)
	{
		cout << "added RENT" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 2; p.y = 0;
	added = b.AddWord(p, Direction::Left_toRight, "EVER");
	if (added)
	{
		cout << "added EVER" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}
	b.DisplayBoard();
	added = b.AddWord(p, Direction::Left_toRight, "END");
	if (added)
	{
		cout << "added END" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}


	added = b.AddWord(p, Direction::Left_toRight, "ENDS");
	if (added)
	{
		cout << "added ENDS" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 2; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "SO");
	if (added)
	{
		cout << "added SO" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}


	p.x = 0; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "IT");
	if (added)
	{
		cout << "added IT" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 0; p.y = 3;
	added = b.AddWord(p, Direction::Top_ToBottom, "IT");
	if (added)
	{
		cout << "added IT" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 3; p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TWO");
	if (added)
	{
		cout << "added TWO" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 3; p.y = 1;
	added = b.AddWord(p, Direction::Left_toRight, "TWO");
	if (added)
	{
		cout << "added TWO" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}
	p.x = 2; p.y = 1;
	added = b.AddWord(p, Direction::Top_ToBottom, "TWO");
	if (added)
	{
		cout << "added TWO" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	p.x = 2; p.y = 2;
	added = b.AddWord(p, Direction::Top_ToBottom, "TOO");
	if (added)
	{
		cout << "added TWO" << "\n";
	}
	else {
		cout << "not added " << "\n";
	}

	b.DisplayBoard();
	cout << b.IsBoardFull() ? "Board is full" : "Words can still be added";
}