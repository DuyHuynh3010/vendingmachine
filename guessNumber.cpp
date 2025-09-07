// Randomly generate numbers between 1 and 1000 for user to guess.

#include <iostream>
#include <cstdlib> //for srand() and rand()
#include <ctime>   //for time()

using namespace std;

bool isCorrect( int, int ); // function prototype

int main()
{
    int answer {0};        // randomly generated number
    int guess {0};         // user's guess
    char response {'y'};   // 'y' or 'n' response to continue game

    // loop until user types 'n' to quit game
    do {
        // generate random number between 1 and 90
        // 1 is shift, 90 is scaling factor
        srand(time(0));
        answer = 1 + rand() % 90;

        // prompt for guess
        cout  <<"Duy Huynh's Number Game\n"
              << "I have a number between 1 and 90.\n" 
              << "Can you guess my number?\n" 
              <<"Enter 0 to exit !!"<<endl
              << "Please type your first guess." << endl << "? ";
        cin >> guess;

        // loop until correct number
        while (true)  {
            if (guess==0){
                cout << "Exit the game"<<endl;
                break;
            }

            if (isCorrect(guess, answer)) {
                cout << "\nExcellent! You guessed the number!\n";
                break;
            }
            cin >> guess;
        }

        // prompt for another game
        cout << "Would you like to play again (y or n)? ";
        cin >> response;

        cout << endl;
    } while ( response == 'y' );

} // end main

// isCorrect returns true if g equals a
// if g does not equal a, displays hint
bool isCorrect( int g, int a )
{
    // guess is correct
    if ( g == a )
        return true;

    // guess is incorrect; display hint
    if ( g < a )
        cout << "Too low, you are " << a-g <<" off. Try again\n";
    else
        cout << "Too high, you are " << g-a <<" off. Try again\n";

    return false;
} // end function isCorrect
