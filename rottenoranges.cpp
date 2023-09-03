#include </Users/PremBhatia1/stdc.h>

using namespace std;

int isValid(int r, int c, int rs, int cs);
void printQ(list<pair<int, int>> q);

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        pair<int, int> increments[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int time = 0;
        list<pair<int, int>> q; // rotten
        int r = 0;              // fresh
        bool started = false;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    r++;
                }
                if (grid[i][j] == 2)
                {
                    q.push_front({i, j});
                }
            }
        }

        while (q.size())
        {
            started = true;
            int size = q.size();
            time++;
            cout << "~~~~~~~~~~ TIME INCREASED TO: " << time << endl;
            while (size > 0)
            {
                auto orange = q.back();
                cout << "AT " << orange.first << " | " << orange.second << endl;
                q.pop_back();
                for (auto inc : increments)
                {
                    if (isValid(orange.first + inc.first, orange.second + inc.second, grid.size(), grid[0].size()) && grid[orange.first + inc.first][orange.second + inc.second] == 1)
                    {
                        cout << " -- pushed : " << orange.first + inc.first << " -- " << orange.second + inc.second << endl;
                        q.push_front({orange.first + inc.first, orange.second + inc.second});
                        r--;
                        grid[orange.first + inc.first][orange.second + inc.second] = 2;
                    }
                }
                size--;
            }
        }

        if (r == 0 && started)
        {
            return time - 1;
        }

        return -1;
    }
};

int isValid(int r, int c, int rs, int cs)
{
    if (r > -1 && r < rs && c > -1 && c < cs)
    {
        cout << "visited: " << r << ", " << c << endl;
        return true;
    }
    return false;
}

void printQ(list<pair<int, int>> q)
{
    for (auto elems : q)
    {
        cout << "...." << elems.first << " ----- " << elems.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    Solution *sln = new Solution();
    vector<vector<int>> grid{{2, 1, 1},
                             {1, 1, 0},
                             {0, 1, 1}};

    int t = sln->orangesRotting(grid);
    cout << t << endl;
    return 0;
}
