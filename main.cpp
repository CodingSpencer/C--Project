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

int main()
{
    int column;
    char piece = 'X';
    // int turns = 0;

    // if (turns % 2 == 0)
    // {
    //     piece = 'X';
    // } else
    // {
    //     piece = 'O';
    // }

    GetPreferences();

    vector<vector<char>> board;
    CreateBoard(board);

    while (true)
    {
        Display(board);

        cout << "Welcome to my Connect 4 game! Enter q at anytime to quit:";
        cout << endl;
        cout << "Select a column between 0-"<<length-1<<endl;
        cin >> column;

        if (column == 'q')
        {
            break;
        } else if (column < 0 && column >= length) {
            cout << "Invalid input. Please try again!" << endl;
            continue;
        }

        PlacePiece(board, column, piece);

        piece = (piece == 'X') ? 'O' : 'X';

    }

    // turns++;

    return 0;
}
