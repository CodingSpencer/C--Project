//
// Created by spencer on 7/11/24.
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Variables to hold the length and height amounts
int length;
int height;

void GetPreferences()
{
    // Gets preferences for the game from user
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
    // Will display each square of the board
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
    // Set board variable to the board for the game
    board = vector<vector<char>>(height, vector<char>(length, ' '));
}

bool PlacePiece(vector<vector<char>>& board, int column, char piece)
{
    // Check for lowest unassigned piece
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

// ChatGPT assisted in corrections
bool CheckWin(vector<vector<char>>& board, char piece)
{
    // Horizontal Win
    for (int y =0; y < height; y++)
    {
        for (int x = 0; x <= length - 4; x++)
        {
            if (board[y][x] == piece && board[y][x+1] == piece && board[y][x+2] == piece && board[y][x+3] == piece)
            {
                cout << "Horizontal win at: (" << y << ", " << x << ")" << endl;
                return true;
            }
        }
    }

    // Vertical Win
    for (int y = 0; y <= height - 4; y++)
    {
        for (int x = 0; x <= length; x++)
        {
            if (board[y][x] == piece && board[y+1][x] == piece && board[y+2][x] == piece && board[y+3][x] == piece)
            {
                cout << "Vertical win at: (" << y << ", " << x << ")" << endl;
                return true;
            }
        }
    }

    // Diagonal Win (Bottom to Top)
    for (int y = 0; y <= height - 4; y++)
    {
        for (int x = 0; x <= length - 4; x++)
        {
           if (board[y][x] == piece && board[y+1][x+1] == piece && board[y+2][x+2] == piece && board[y+3][x+3] == piece)
            {
                cout << "Diagonal (B to T) win at: (" << y << ", " << x << ")" << endl;
                return true;
            }
        }
    }

    // Diagonal Win (Bottom to Top)
    for (int y = 3; y < height; y++)
    {
        for (int x = 0; x <= length; x++)
        {
            if (board[y][x] == piece && board[y-1][x+1] == piece && board[y-2][x+2] == piece && board[y-3][x+3] == piece)
            {
                cout << "Diagonal (T to B) win at: (" << y << ", " << x << ")" << endl;
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

        cout << "Select a column between 1-"<<length-1<<endl;
        string input;
        cin >> input;

        try
        {
            column = stoi(input);
        } catch (exception& e)
        {
            cout << "Invalid integer input. Try again." << endl;
            continue;
        }

        if (column == -1)
        {
            break;
        }
        // ChatGPT test
        else if (column <= 0 || column >= length) {
            cout << "Invalid input. Please try again!" << endl;
            continue;
        }
        else
        {
            PlacePiece(board, column, piece);
            if (CheckWin(board, piece))
            {
                Display(board);
                cout << "Congrats player " << piece << " you won!" << endl;
                break;
            }
        }

        piece = (piece == 'X') ? 'O' : 'X';
    }

    return 0;
}
