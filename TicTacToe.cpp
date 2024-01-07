#include<iostream>
using namespace std;

int row;
int column;
char symbol;
string player1, player2;
bool tieGame = false;
char table[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void display(){
    
    cout<<"     |     |    \n";
    cout<<"  "<<table[0][0]<<"  |  "<<table[0][1]<<"  |  "<<table[0][2]<< "\n";
    cout<<"----- ----- -----\n";
    cout<<"     |     |    \n";
    cout<<"  "<<table[1][0]<<"  |  "<<table[1][1]<<"  |  "<<table[1][2]<< "\n";
    cout<<"----- ----- -----\n";
    cout<<"     |     |    \n";
    cout<<"  "<<table[2][0]<<"  |  "<<table[2][1]<<"  |  "<<table[2][2]<< "\n";
    
    cout<<endl;       
}
void randomSymbol(){
    int randNumber = (rand() % 2) + 1;
    symbol = randNumber == 1 ? 'X' : 'O';
    cout << (symbol == 'X' ? player1 : player2) << " will play with " << symbol << endl;  
}
bool checkWinner() {
    // Check in all rows and columns
    for (int i = 0; i < 3; i++) {
        // Updated condition to check for the current symbol (symbol) instead of 'X'
        if ((table[i][0] == table[i][1] && table[i][0] == table[i][2] && table[i][0] == symbol) ||
            (table[0][i] == table[1][i] && table[0][i] == table[2][i] && table[0][i] == symbol))
            return true;
    }

    // Check in diagonals
    if ((table[0][0] == table[1][1] && table[0][0] == table[2][2] && table[0][0] == symbol) ||
        (table[1][1] == table[2][0] && table[1][1] == table[0][2] && table[1][1] == symbol))
        return true;

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If any block is still empty, the game is not a tie
            if (table[i][j] != 'X' && table[i][j] != 'O')
                return false;
        }
    }
    
    tieGame = true;
    return true;
}


void getLocation(){

    int digit;

    while (true) {
        if(symbol == 'X'){
            cout << player1 << ", Please enter position: ";
            cin >> digit;
        }
        if(symbol == 'O'){
            cout << player2 << ", Please enter position: ";
            cin >> digit;
        }

        switch (digit)
        {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
        
        default:
            cout << "Error: Invalid Position" << endl;
            continue; // Continue the loop to get a valid input
        }

        // Update the symbol after checking for a winner
        if (symbol == 'X' && table[row][column] != 'X' && table[row][column] != 'O') {
            table[row][column] = 'X';
        } else if (symbol == 'O' && table[row][column] != 'X' && table[row][column] != 'O') {
            table[row][column] = 'O';
        } else {
            cout << "Error: Given block is already filled" << endl;
            continue; // Continue the loop to get a valid input
        }
        
        display();

        // Check for a winner after each move
        if (checkWinner()) {
            display(); // Displaying the final board state
            break; // Break out of the loop if there's a winner
        } else {
            // Updating the symbol only if the game is not over
            symbol = (symbol == 'X') ? 'O' : 'X';
            break; // Break out of the loop after updating the symbol
        }
    }
}






int main() {
    cout << "\n\n\nWelcome to the TIC TAC TOE showdown!👊" << endl;
    cout << "The Game will automatically decide which player will begin." << endl;
    cout << "Heres your board, choose numbers to fill position\n" << endl;
    display();
    cout << "Enter name of first player: ";
    getline(cin, player1); //because cin only takes upto first space/tab..etc.
    cout << "Enter name of second player: ";
    getline(cin, player2);

    randomSymbol();
    bool firstIteration = true;
    while (!checkWinner()) {
        if (firstIteration) {
            display();
            firstIteration = false;
        }
        getLocation();
        
    }
    if (symbol == 'X' && tieGame == false)
        cout << player1 << ", Wins. Congratulations✨✨" << endl;
    else if (symbol == 'O' && tieGame == false)
        cout << player2 << " Wins. Congratulations✨✨." << endl;
    else
        cout << "It's a draw" << endl;

    return 0;
}

