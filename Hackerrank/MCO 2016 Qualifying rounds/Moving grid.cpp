#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Problem statement:
//Justin finds an ancient moving grid in an ancient temple. The grid has n rows and n columns.
//There is a letter written on each square of the grid, which can be either N (North), E (East), S (South), or W (West).
//When someone steps on a square, the grid will move him to the next square in the direction written on the current square.
//ustin wonders, given a square A on the grid, how many other squares B on the grid are there such that when someone stands on square , the grid will move him to square.

int main() {
	int n;
	cin >> n;

	char a[n + 1][n + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	//(x,y) is the coordinate of A

	//new grid filled with 0,1,2
	//0: status unknown, waiting to be explored
	//1: impossible to go grid A (by default every square outside the edges is 1)
	//2: possible to go grid A (by default A is 2)
	//algorithm:
	//we only consider those grids labelled 0
	//then we move according to the instructions
	//throughout the process we mark the grids we landed as 1
	//if the next grid is 1, then we know that throughout the trail it is impossible to reach A
	//nothing needs to be done (either the next grid is previously marked impossible or we returned to a grid/vicious cycle)
	//if the next grid is 2, then we know that throughout the trail it is possible to reach A
	//mark from (i,j) to the new point as 2
	//if the next grid is 0, keep going
	//running time: O(N^2) since for each grid we only touched at most thrice:
	//once for travelling to determine 0 or 1
	//second for changing to 2, if appicable
	//thirdfor checking to determine total

	int c[n + 2][n + 2] = { 0 };
	c[x][y] = 2;
	for (int i = 0; i <= n + 1; i++)
	{
		c[0][i] = 1;
		c[n + 1][i] = 1;
		c[i][0] = 1;
		c[i][n + 1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (c[i][j] == 0)
			{
				int tempv = i;
				int temph = j;//our cursors
							  //v=vertical and h=horizontal
				while (c[tempv][temph] == 0)//stop when it encounters 1 or 2
				{
					c[tempv][temph] = 1;//mark the current grid first
					if (a[tempv][temph] == 'N')//upwards: tempv minus 1
					{
						tempv--;
					}

					else if (a[tempv][temph] == 'S')//downwards: tempv plus 1
					{
						tempv++;
					}

					else if (a[tempv][temph] == 'W')//leftwards: temph minus 1
					{
						temph--;
					}
					else if (a[tempv][temph] == 'E')//rightwards: temph plus 1
					{
						temph++;
					}
				}

				//for the case where c[tempv][temph]=2 we need to lable each grid travelled as 2
				if (c[tempv][temph] == 2)
				{//initialize
					int winv = i;
					int winh = j;
					while (c[winv][winh] != 2)
					{
						c[winv][winh] = 2;//mark the current grid first
						if (a[winv][winh] == 'N')//upwards: winv minus 1
						{
							winv--;
						}
						//caution: use else to avoid winv/winh from chnaging more than one
						//reason: suppose we had 'N' and the next grid is 'S', hen we indavertently moved twice
						else if (a[winv][winh] == 'S')//downwards: winv plus 1
						{
							winv++;
						}

						else if (a[winv][winh] == 'W')//leftwards: winh minus 1
						{
							winh--;
						}
						else if (a[winv][winh] == 'E')//rightwards: winh plus 1
						{
							winh++;
						}

					}

				}

			}
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (c[i][j] == 2)
			{
				total++;
			}
		}
	}

	cout << (total - 1);//take off (x,y) since we shouldn't include it
	return 0;
}
