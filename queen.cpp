#include "queen.h"
#include <iostream>
using namespace std;
void print(int board[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
bool safe(int board[n][n], int r, int c)
{
	int i, j;
	for (i = 0; i < c; i++)
	{
		if (board[r][i])
			return false;
	}
	for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;
	}
	for (i = r, j = c; j >= 0 && i < n; i++, j--)
	{
		if (board[i][j])
			return false;
	}
	return true;
}
bool solvequ(int board[n][n], int c)
{
	if (c >= n)
		return true;
	for (int i = 0; i < n; i++)
	{
		if (safe(board, i, c))
		{
			board[i][c] = 1;
			if(solvequ(board,c+1)==true)
			return true;
			board[i][c] = 0;
		}
	}
	return false;
}
bool solve()
{
	int board[n][n] = { 0 };
	if (solvequ(board, 0) == false)
	{
		cout << "solution does not exist" << endl;
		return false;
	}
	print(board);
	return true;
}
