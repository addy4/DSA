//Problem - https://www.geeksforgeeks.org/shortest-path-by-removing-k-walls/
//Debub solution at - /Users/PremBhatia1/Desktop/CS_Lab/Competetive/algoPract/shortestPathWallRemove.cpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define LIMIT 1000

using namespace std;

const int M = 3;
const int N = 9;

bool comp(int a, int b)
{
    return (a < b);
}

int getMinSteps(int x, int y, int grid[M][N], int k, bool visited[M][N])
{
    int rs = LIMIT, ds = LIMIT, us = LIMIT, ls = LIMIT;

    visited[x][y] = true;

    if (x == M - 1 && y == N - 1)
    {
        return 0;
    }

    if (y + 1 < N)
    {
        if (grid[x][y + 1] == 1 && visited[x][y + 1] == false)
        {
            rs = 1 + getMinSteps(x, y + 1, grid, k, visited);
        }
        if (grid[x][y + 1] == 0 && visited[x][y + 1] == false)
        {
            if (k > 0)
            {
                k--;
                rs = 1 + getMinSteps(x, y + 1, grid, k, visited);
            }
        }
    }

    if (x + 1 < M)
    {
        if (grid[x + 1][y] == 1 && visited[x + 1][y] == false)
        {
            ds = 1 + getMinSteps(x + 1, y, grid, k, visited);
        }
        if (grid[x + 1][y] == 0 && visited[x + 1][y] == false)
        {
            if (k > 0)
            {
                k--;
                ds = 1 + getMinSteps(x + 1, y, grid, k, visited);
            }
        }
    }

    if (y - 1 > -1)
    {
        if (grid[x][y - 1] == 1 && visited[x][y - 1] == false)
        {
            ls = 1 + getMinSteps(x, y - 1, grid, k, visited);
        }
        if (grid[x][y - 1] == 0 && visited[x][y - 1] == false)
        {
            if (k > 0)
            {
                k--;
                ls = 1 + getMinSteps(x, y - 1, grid, k, visited);
            }
        }
    }

    if (x - 1 > -1)
    {
        if (grid[x - 1][y] == 1 && visited[x - 1][y] == false)
        {
            us = 1 + getMinSteps(x - 1, y, grid, k, visited);
        }
        if (grid[x - 1][y] == 0 && visited[x - 1][y] == false)
        {
            if (k > 0)
            {
                k--;
                us = 1 + getMinSteps(x - 1, y, grid, k, visited);
            }
        }
    }

    visited[x][y] = false;

    return min({rs, ds, us, ls}, comp);
}

int main(int argc, char const *argv[])
{
    int grid[M][N] =
        {{1, 0, 1, 1, 1, 0, 1, 1, 1},
         {1, 0, 1, 0, 1, 0, 1, 0, 1},
         {1, 1, 1, 0, 1, 1, 1, 0, 1}};

    bool visited[M][N] =
        {{false, false, false, false, false, false, false, false, false},
         {false, false, false, false, false, false, false, false, false},
         {false, false, false, false, false, false, false, false, false}};

    int k = 0;

    int a = getMinSteps(0, 0, grid, k, visited);

    cout << "# JUMPS=" << a << endl;

    return 0;
}