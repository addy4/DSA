#include </Users/PremBhatia1/stdc.h>

using namespace std;

bool wordExist(vector<vector<char>> &board, int index, int row, int col, string word, vector<vector<bool>> visited);
bool isValid(vector<vector<char>> &board, int row, int col, vector<vector<bool>> visited);

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int index = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " | " << visited[i][j] << " | " << word[index] << endl;
                if (board[i][j] == word[index])
                {
                    if (wordExist(board, index, i, j, word, visited) == true)
                    {
                        cout << "yep!" << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

bool wordExist(vector<vector<char>> &board, int index, int row, int col, string word, vector<vector<bool>> visited)
{
    cout << "row = " << row << ", "
         << "col = " << col << endl;
    visited[row][col] = true;
    if (index == word.size() - 1)
    {
        return true;
    }
    if (isValid(board, row + 1, col, visited) && board[row + 1][col] == word[index + 1])
    {
        if (wordExist(board, index + 1, row + 1, col, word, visited) == true)
        {
            return true;
        }
    }
    if (isValid(board, row - 1, col, visited) && board[row - 1][col] == word[index + 1])
    {
        if (wordExist(board, index + 1, row - 1, col, word, visited) == true)
        {
            return true;
        }
    }
    if (isValid(board, row, col + 1, visited) && board[row][col + 1] == word[index + 1])
    {
        if (wordExist(board, index + 1, row, col + 1, word, visited) == true)
        {
            return true;
        }
    }
    if (isValid(board, row, col - 1, visited) && board[row][col - 1] == word[index + 1])
    {
        if (wordExist(board, index + 1, row, col - 1, word, visited) == true)
        {
            return true;
        }
    }
    cout << "BACK row = " << row << ", "
         << "col = " << col << endl;
    visited[row][col] = false;
    return false;
}

bool isValid(vector<vector<char>> &board, int row, int col, vector<vector<bool>> visited)
{
    if (row > -1 && row < board.size() && col > -1 && col < board[0].size() && visited[row][col] == false)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'C', 'B', 'C', 'E'}, {'S', 'F', 'S', 'C'}, {'A', 'D', 'E', 'E'}};
    string word = "CSCEC";
    Solution *sln = new Solution();
    sln->exist(board, word);
    return 0;
}

// In the JAVA based wordsearch solution, visited logic was not incorporated.
// Also, in the solution, it straightaway returns the boolean (true/false) for the very first recursive match function invocation
// In this solution, it does move to the next recursive call (i.e. it checks another cell) if current cell doesn't satisify the match requirements
