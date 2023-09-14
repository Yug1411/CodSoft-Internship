#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main() {
    
    int guess;
    int attempts = 0;
    char c;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a random number between 1 and 1000." << endl;

    
    srand(time(NULL));

    do
    {
        int randomNumber = rand() % 1000 + 1;
        do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts." << endl;
        }
        } while (guess != randomNumber);
        
        cout << "If you want to play again, press Y: ";
        cin >> c;
    } while (c == 'Y');
    
    return 0;
}
