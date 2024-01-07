#include<iostream>
using namespace std;

int main(){
    // UI/Game start
    cout<<endl;
    cout<<"You have numbers from 1 to 100 and 10 chances."<<endl;
    cout<<"Guess the number, Best of Luck."<<endl;
    cout<<endl;

    //Logic
        int randNumber = (rand() % 100) + 1;
        int userInput;
        bool won = false;

        for(int i = 10; i>0; i--){
            cout<<"Enter your "<< 11 - i <<" guess: ";
            cin>>userInput;

            if(userInput<1 || userInput>100){
                cout<<"Please enter a number between 1 to 100 only."<<endl;
                continue;
            }
            if(userInput == randNumber){
                won = true;
                cout<<"You WON ✨, guessed it right Champ."<<endl;
                cout<<endl;
                break;
            }
            else if(userInput < randNumber){
                if(userInput < randNumber - 20) 
                    cout<<"The secret number is TOO high than your guess."<<endl;
                else
                    cout<<"The secret number is higher than your guess."<<endl;
            }
            else{
                if(userInput > randNumber + 20)
                    cout<<"The secret number is TOO low than your guess."<<endl;
                else
                    cout<<"The secret number is lower than your guess."<<endl;
            }
                cout<<endl;
        }
        if(!won){
            cout<<"The secret number was "<<randNumber<<" Better luck next time."<<endl;
        }
    return 0;
}
