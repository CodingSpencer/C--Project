//
// Created by spencer on 7/11/24.
//
#include <iostream>
#include <vector>

using namespace std;

int length;
int height;

void GetPreferences()
{
    cout << "What size of board do you want?" << endl;
    cout << "Board Length: " << endl;
    cin >> length;
    length += 1;
    cout << "Board Height: " << endl;
    cin >> height;

    cout << "Height = " << height << " | Length = " << length << endl;
}

void Display(vector<vector<char>>& board)
{
    for (int y =0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            cout << board[y][x] << '|';
        }
        cout << endl;
    }
}

void CreateBoard(vector<vector<char>>& board)
{
    board = vector<vector<char>>(height, vector<char>(length, ' '));
}

bool PlacePiece(vector<vector<char>>& board, int column, char piece)
{
    for (int x = height - 1; x >= 0; x--)
    {
        if (board[x][column] == ' ')
        {
            board[x][column] = piece;
            return true;
        }
    }
    return false;
}

bool CheckWin(vector<vector<char>>& board, char piece)
{
    for (int y =0; y < height; y++)
    {
        for (int x = 0; x < length-4; x++)
        {
            if (board[y][x] == piece && board[y][x+1] == piece && board[y][x+2] == piece && board[y][x+3])
            {
                return true;
            }
        }
    }

    for (int y =0; y < height; y++)
    {
        for (int x = 0; x < length-4; x++)
        {
            if (board[y][x] == piece && board[y+1][x] == piece && board[y+2][x] == piece && board[y+3][x])
            {
                return true;
            }
        }
    }

    for (int y =0; y < height; y++)
    {
        for (int x = 0; x < length-4; x++)
        {
            if (board[y][x] == piece && board[y+1][x+1] == piece && board[y+2][x+2] == piece && board[y+3][x+3])
            {
                return true;
            }
        }
    }

    for (int y =0; y < height; y++)
    {
        for (int x = 0; x < length-4; x++)
        {
            if (board[y][x] == piece && board[y-1][x+1] == piece && board[y-2][x+2] == piece && board[y+-3][x+3])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int column;
    char piece = 'X';

    GetPreferences();

    vector<vector<char>> board;
    CreateBoard(board);

    cout << "Welcome to my Connect 4 game! Enter -1 at anytime to quit:";
    cout << endl;

    while (true)
    {
        Display(board);

        cout << "Select a column between 0-"<<length-1<<endl;
        cin >> column;

        if (column == -1)
        {
            break;
        }
        // else if (column < 0 || column >= length) {
        //     cout << "Invalid input. Please try again!" << endl;
        //     continue;
        // }
        else
        {
            PlacePiece(board, column, piece);
            // if (!PlacePiece(board,column,piece))
            // {
            //     cout << "Column is full. Try again!" << endl;
            //     continue;
            // }
            // if (CheckWin(board, piece))
            // {
            //     Display(board);
            //     cout << "Congrats player" << piece << "you won!" << endl;
            //     break;
            // }
        }

        piece = (piece == 'X') ? 'O' : 'X';
    }

    return 0;
}
