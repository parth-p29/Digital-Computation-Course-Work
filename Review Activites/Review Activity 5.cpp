// Review Activity 5.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;


//Test

//I tests various cases to see if this works, and for all cases the code always works! Check the sample output doc to see how the test cases I used.
//to make sure the code doesn't fail I tested all the possibles the user can choose and in all cases the code worked ( i started with 3, 2 and 1 and went all the way to a winner)

void game() {   // created a game function to hold all the logic of this simple 23 game

    int sticks = 23;  //initilizes the starting number of sticks to 23
    
    while (sticks > 0) {   //has a while loop to keep iterating as the sticks are greater than 0 or while there are still sticks left to choose

        if (sticks == 1) {
            cout << "Humans loose, Computer Wins ! \n";    //if sticks are 1, then that means the human as to choose the last stick so the human looses
            break;
        }

        int human_move;  //initilizes the variable to hold the human's moves

        cout << "Enter your move Human: ";     //simple UI for the user to input their sticks
        cin >> human_move;

        cout << "The human took " << human_move << " sticks. \n";   // Simple output for the user to show how many sticks they took
        
        sticks -= human_move;  //after the user enters their sticks, it updates the sticks variable to decrease that many sticks. 

        if (sticks > 4){   //if the reamining sticks is greater than 4, the computer will take that many sticks as proposed by the question

            cout << "The Computer took " << 4 - human_move << " sticks \n";  //output for the computers move
            sticks -= 4 - human_move;  //decreases overall sticks by the amount the computer took

        }

        else if (sticks == 2 || sticks == 3 || sticks == 4) {   //if sticks remaining are between 2 and 4 inclusive...

            cout << "The Computer took " << sticks - 1 << " sticks \n";  //the computer will take as many sticks so the remaining will always equal 0.
            sticks -= (sticks - 1); //decreases that many sticks 

        }

        else {

            cout << "Computer looses, Human Wins!";  //if the remaining sticks are 1, the computer looses
        }

        cout << "These many sticks remain: " << sticks << " \n"; //outputs the amount of sticks left

 
    }
}

int main()
{
    game(); //calls game function
}

