// Guess game using recursive functions

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void clear_input()
{
    cin.clear();
    cin.ignore(50000, '\n');
}

bool is_duplicate(vector<int> &guesses, int user_input)
{
    bool is_found = false;

    for (int i = 0; i < guesses.size(); i++)
    {
        if (user_input == guesses[i])
        {
            is_found = true;
            break;
        }
    }

    return is_found;
}

void show_menu(vector<int> &guesses);

int generate_random_number()
{
    srand(time(NULL));

    int random = rand() % 21;

    return random;
}

void play_game(int random_number, vector<int> &guesses)
{
    int user_guess;

    cout << "\nRandomly generate number is: " << random_number << endl;

    cout << "Enter your guess: ";
    cin >> user_guess;

    if (!cin)
    {
        cout << "Please enter a integer" << endl;
        clear_input();

        play_game(random_number, guesses);

        return;
    }

    if (is_duplicate(guesses, user_guess))
    {
        cout << "\nAh! nice try but you already tried this number, try a different number" << endl;
        play_game(random_number, guesses);

        return;
    }

    guesses.push_back(user_guess);

    if (user_guess == random_number)
    {
        vector<int> newGuesses;
        cout << "You guessed it right, congo you won" << endl;
        cout << "Your guesses are:" << endl;

        for (int i = 0; i < guesses.size(); i++)
        {
            cout << guesses[i] << endl;
        }

        show_menu(newGuesses);
    }
    else if (user_guess < random_number)
    {
        cout << "Your guess is less than the target number, try again" << endl;
        play_game(random_number, guesses);
    }
    else if (user_guess > random_number)
    {
        cout << "Your guess is greater than the target number, try again" << endl;
        play_game(random_number, guesses);
    }
}

void show_menu(vector<int> &guesses)
{
    int user_selection;

    cout << "\nWelcome to the best game ever" << endl;
    cout << "This game will generate any random number from 0 to 20 and you have to guess it" << endl;

    cout << "Choice an action:" << endl;
    cout << "0) Play game" << endl;
    cout << "1) Quit" << endl;

    cout << "Enter: ";
    cin >> user_selection;

    if (!cin)
    {
        clear_input();
        cout << "\nWrong Selection, please select again" << endl;
        show_menu(guesses);
    }
    else if (user_selection != 0 && user_selection != 1)
    {
        cout << "\nWrong Selection, please select again" << endl;
        show_menu(guesses);
    }
    else if (user_selection == 0)
    {
        play_game(generate_random_number(), guesses);
    }
    else
    {
        cout << "\nThank you for your time";
    }
}

int main()
{
    vector<int> guesses;

    show_menu(guesses);

    return 0;
}