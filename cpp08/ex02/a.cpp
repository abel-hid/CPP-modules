#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int isValid(vector<vector<char> >& board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++) 
    {
        if (board[i][col] != '.' && board[i][col] == c) return false; //check row
        if (board[row][i] != '.' && board[row][i] == c) return false; //check column
        if (board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
    }
    return true;
}

    void solveSudoku(vector<vector<char> >& board) 
    {
        for(size_t i = 0 ; i < board.size() ; i++)
        {
            for(size_t j = 0 ; j < board[i].size() ; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1' ; c <= '9' ; c++)
                    {

                    }
                }
            }
        }
    }
    void print(vector<vector<char> >& board)
    {
        for(size_t i = 0 ; i < board.size() ; i++)
        {
            for(size_t j = 0 ; j < board[i].size() ; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board ;
    vector<char> v;
    v.push_back('5');
    v.push_back('3');
    v.push_back('.');
    v.push_back('.');
    v.push_back('7');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    board.push_back(v);
    v.clear();
    v.push_back('6');
    v.push_back('.');
    v.push_back('.');
    v.push_back('1');
    v.push_back('9');
    v.push_back('5');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    board.push_back(v);
    v.clear();
    v.push_back('.');
    v.push_back('9');
    v.push_back('8');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('6');
    v.push_back('.');
    board.push_back(v);
    v.clear();
    v.push_back('8');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('6');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('3');
    board.push_back(v);
    v.clear();
    v.push_back('4');
    v.push_back('.');
    v.push_back('.');
    v.push_back('8');
    v.push_back('.');
    v.push_back('3');
    v.push_back('.');
    v.push_back('.');
    v.push_back('1');
    board.push_back(v);
    v.clear();
    v.push_back('7');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('2');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('6');
    board.push_back(v);
    v.clear();
    v.push_back('.');
    v.push_back('6');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('2');
    v.push_back('8');
    v.push_back('.');
    board.push_back(v);
    v.clear();
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('4');
    v.push_back('1');
    v.push_back('9');
    v.push_back('.');
    v.push_back('.');
    v.push_back('5');
    board.push_back(v);
    v.clear();
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('.');
    v.push_back('8');
    v.push_back('.');
    v.push_back('.');
    v.push_back('7');
    v.push_back('9');
    board.push_back(v);
    v.clear();
    // s.solveSudoku(board);
    s.print(board);
    return 0;
}