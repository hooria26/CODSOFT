#include <iostream>
#include <vector>
using namespace std ;

void display( const vector <string> & brd )
{
    cout << endl ;
    cout << "  " << brd[1] << "  |  " << brd[2] << "  |  " << brd[3] << "  " << endl ;
    cout << "_____|_____|_____" << endl ;
    cout << "     |     |     " << endl ;
    cout << "  " << brd[4] << "  |  " << brd[5] << "  |  " << brd[6] << "  " << endl ;
    cout << "_____|_____|_____" << endl ;
    cout << "     |     |     " << endl ;
    cout << "  " << brd[7] << "  |  " << brd[8] << "  |  " << brd[9] << "  " << endl << endl ;
}

bool isValid ( int move, const vector<string>& brd)
{
    return (move > 0 && move < 10 && brd[move] != "X" && brd[move] != "O");
}

void makeMove(int move, const string& player, vector<string>& brd)
{
        brd[move] = player;
}

string checkWin(const string& player, const vector<string>& brd)
{
    if ((brd[1] == player && brd[2] == player && brd[3] == player) ||
        (brd[4] == player && brd[5] == player && brd[6] == player) ||
        (brd[7] == player && brd[8] == player && brd[9] == player) ||
        (brd[1] == player && brd[4] == player && brd[7] == player) ||
        (brd[2] == player && brd[5] == player && brd[8] == player) ||
        (brd[3] == player && brd[6] == player && brd[9] == player) ||
        (brd[1] == player && brd[5] == player && brd[9] == player) ||
        (brd[3] == player && brd[5] == player && brd[7] == player))
        {
            return player ;
        }
    return "0" ;
}

int main()
{
    vector<string> brd(10) ;
    for ( int i = 1 ; i < 10 ; i++ )
    {
        brd[i] = to_string( i ) ;
    }
    char playAgain ;
    cout << " Press any key to start the game or 'q' to quit: " ;
    cin >> playAgain ;
    while ( playAgain != 'q' )
    {
        display(brd) ;
        int turnCount = 0 ;
        bool player1Wins = false, player2Wins = false ;
        while ( turnCount < 9 )
        {
            int move ;
            cout << " Player 1's turn (X). Enter your move (1-9): " ;
            cin >> move ;
            while ( !isValid( move, brd ))
            {
                cout << " Invalid move! Player 1, please try again: " ;
                cin >> move ;
            }
            makeMove( move, "X", brd) ;
            if ( checkWin( "X", brd ) == "X" )
            {
                player1Wins = true ;
                break ;
            }
            turnCount++ ;
            if ( turnCount == 9 )
            {
                break;
            }
            display(brd) ;
            cout << " Player 2's turn (O). Enter your move (1-9): " ;
            cin >> move ;
            while ( !isValid( move, brd ))
            {
                cout << " Invalid move! Player 2, please try again: " ;
                cin >> move ;
            }
            makeMove( move, "O", brd ) ;
            if ( checkWin( "O", brd ) == "O" )
            {
                player2Wins = true ;
                break ;
            }
            turnCount++ ;
            display( brd ) ;
        } 
        display( brd ) ;
        if ( player1Wins )
        {
            cout << " Congratulations! Player 1 wins! " << endl ;
        }
        else if ( player2Wins )
        {
            cout << " Congratulations! Player 2 wins! " << endl ;
        }
        else
        {
            cout << " It's a draw! " << endl ;
        }
        for ( int i = 1 ; i < 10 ; i++ )
        {
            brd[i] = to_string(i) ;
        }
        cout << " Press any key to play again or 'q' to quit: " ;
        cin >> playAgain ;
    }
    return 0 ;
}
