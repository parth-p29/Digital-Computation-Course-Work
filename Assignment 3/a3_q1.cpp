//***************************************************************

// Name: Parth Patel 

// SYDE 121 Assignment 3 Question 1
// Filename: a3_q1.cpp

// Project: Soccer Simmulator
// Purpose: Simulates a game of soccer with 2 teams and outputs their stats at the end
// Due Date: Nov 1 2020

//***************************************************************

//Testing 

/* Sample Output 1

Team B made a dirty move near the net. Team A will be given a penalty!
Team A performed a fabulous penalty shot and got the ball in the net!!!!
The refs have decided that Team B will not receive any card!

It's Half Time!
Team A's Stats                    Team B's Stats
1                    Score                   0
1               On Goal Shots                0
0              Off Goal Shots                0
0               Blocked Shots                0
0                    Fouls                   1
0                Yellow Cards                0
0                   Red Cards                0

Team B made a dirty move near the net. Team A will be given a penalty!
Team A made a great on goal shot but it got blocked by the goal keeper!
The refs have decided that Team B will receive a yellow card!

Team B made a dirty move near the net. Team A will be given a penalty!
Team A made a terrible penalty shot and missed the net completley.
The refs have decided that Team B will receive a red card!

Final Game Stats
Team A's Stats                    Team B's Stats
1                    Score                   0
2               On Goal Shots                0
1              Off Goal Shots                0
1               Blocked Shots                0
0                    Fouls                   3
0                Yellow Cards                1
0                   Red Cards                1

Team A Won!

 As you can see from this output, my program executes the simulation correctly as all the values in the stats table makes sense (I manually made sure they check up, and they sure do). 
 Also it outputs which team wins at the end and it is clear that team a wins. In this simulation, all the event types also occur which show that my program works and a partiular game scenario isnt repeated.

 A different scenario can easily occur where Team B wins and different values are outputted for the stats of each team - this is the magic of random it allows countless outcomes!

*/


/* Sample Output 2

Team A has just shot the ball!
Team A has shot the ball on goal, but it was saved by the goalie! Fantastic Save by the goalkeeper!

Team A has just shot the ball!
Team A has shot the ball on goal, but it was saved by the goalie! Fantastic Save by the goalkeeper!

It's Half Time!
Team A's Stats                    Team B's Stats
0                    Score                   0
2               On Goal Shots                0
0              Off Goal Shots                0
2               Blocked Shots                0
0                    Fouls                   0
0                Yellow Cards                0
0                   Red Cards                0

Team B has commited a rude foul on Team A. A free kick will be awarded to Team A
Team A has scored a fantastic goal!! OLE OLE OLE OLE
The refs have decided that Team B will receive a yellow card!

Team B has just made a shot!
Team B has shot the ball on goal, but it was saved by the goalie! Fantastic Save by the goalkeeper!

Team A made a dirty move near the net. Team B will be given a penalty!
Team B performed a fabulous penalty shot and got the ball in the net!!!!
The refs have decided that Team A will receive a yellow card!

Final Game Stats
Team A's Stats                    Team B's Stats
1                    Score                   1
3               On Goal Shots                2
0              Off Goal Shots                0
2               Blocked Shots                1
1                    Fouls                   1
1                Yellow Cards                1
0                   Red Cards                0

Game is a Tie!

In this scenario the game ended in a tie. This shows how my program works for different scenarios and isn't static in the output that is recieved (it changes from game to game).
I manually checked all the values and see that they work out to just what my program outputted.

*/

//Limitations
/*
- The limitations to my program is that it doesn't account for overtime. It only plays the 2 halves but if there is a tie, it doesn't play overtime
- My program doesnt account for the skill level of different players. If a certain player like Ronaldo or Messi shot the ball, there would be a higher % it goes rather than just pure random
*/


#include <iostream>
#include <iomanip>

using namespace std;

void team_shot_event(int team_stats[], string team_name);
    
    //purpose: chooses a random number which will lead to determining the outcome after a player has shot the ball. It will output whatever outcome that comes and updates the value in the stats array
    //Inputs: team_stats[] is the array of variables that store the stats for the team which is inputted into the function, whenever this specific team has shot the ball or recieved a free kick
    //        team_name is the name of the team which is inputted into the array that will be used for some output
    //Returns: Nothing - void function
    
void penalty_event(int team_stats[], string team_name);

    //Purpose: chooses a random number which will lead to the outcome of a team's penalty kick. It then updats the outcome (e.g shot gone in) in the team's stats array.
    //Inputs: team_stats[] is the array of variables that store the stats for the team which is inputted into the function, whenever this specific team has recieved a penalty
    //        team_name is the name of the team which is inputted into the array that will be used for some output
    //Returns: Nothing - void function

void give_card(int team_stats[], string team_name);

    //Purpose: chooses a random number which will lead to the certain card a team might recieve. If a team does receive a card it will update it in the team's stats array
    //Inputs: team_stats[] is the array of variables that store the stats for the team which is inputted into the function, whenever this specific team has gotten a foul 
    //        team_name is the name of the team which is inputted into the array that will be used for some output
    //Returns: Nothing - void function

void output_stats(int team_a[], int team_b[]);

    //Purpose: Outputs the stats of each team
    //Inputs: team_a[] and team_b[] are the 2 arrays which represent the two team's stats. The stats of both of these teams will be needed to output them
    //Returns: Nothing - void function

void run_game();    
    
    //Purpose: runs the simulation of the game, starts by choosing the random number of events and the proceeds to execute the corresponding functions based on the random numbers to play the game
    //Inputs: None
    //Outputs: None


void team_shot_event(int team_stats[], string team_name) {

    int did_score = rand() % 4;     // Sets a variable to check if the player's shot scored, got blocked by goalie or player, and missed completley (represented by a random number between 0 and 3 inclusive)

    if (did_score == 0) {
        cout << team_name << " has scored a fantastic goal!! OLE OLE OLE OLE \n";  //if the player scored it will output the following
        team_stats[0] += 1; //score increased by 1
        team_stats[1] += 1; //on goal increased by 1

    }

    if (did_score == 1) {
        cout << team_name << " has shot the ball on goal, but it was saved by the goalie! Fantastic Save by the goalkeeper! \n"; //if the player shot on goal but got blocked by goalie, it will output the following
        team_stats[1] += 1; //increase on goal by 1
        team_stats[3] += 1; //increase blocked shots by 1           

    }

    if (did_score == 2) {
        cout << team_name << " has shot the ball off goal, next time make a better shot! \n";     //if the player missed completley and ball was off goal it will output 
        team_stats[2] += 1; //increase off goal by 1

    }

    if (did_score == 3) {

        cout << team_name << " has shot the ball but it got BLOCKED by a fabulous defender in midfield!"; //if the player shot the ball and got defended by a goal keeper it will output the following
        team_stats[3] += 1; //blocked increased by 1
    }

}

void penalty_event(int team_stats[], string team_name) { 

    int did_score = rand() % 3;      //determines how a team performs on a penalty kick

    if (did_score == 0) {

        cout << team_name << " performed a fabulous penalty shot and got the ball in the net!!!!\n";     //if the ball goes in, it will output the following
        team_stats[0] += 1; //score increased by 1
        team_stats[1] += 1; //on goal increased by 1
    }

    if (did_score == 1) {

        cout << team_name << " made a great on goal shot but it got blocked by the goal keeper!\n";    //if goalie blocks, it will output the following
        team_stats[3] += 1; //blocked increased by 1
        team_stats[1] += 1; //on goal increased by 1

    }

    if (did_score == 2) {

        cout << team_name << " made a terrible penalty shot and missed the net completley.\n";    //if the ball missed completley and was off course it will output the following 
        team_stats[2] += 1; //off goal increased by 1

    }

}

void give_card(int team_stats[], string team_name) {

    int rand_card = rand() % 3;     //determines what type of card a team will get after a foul (or no card)
    team_stats[4] += 1;   //increases the number of fouls the team has

    if (rand_card == 0) {

        cout << "The refs have decided that " << team_name << " will not receive any card! \n";      //no card will be recieved
    }

    if (rand_card == 1) {

        cout << "The refs have decided that " << team_name << " will receive a yellow card! \n";  //yellow card will be recieved
        team_stats[5] += 1; //yellow cards increased by 1
    }

    if (rand_card == 2) {

        cout << "The refs have decided that " << team_name << " will receive a red card! \n";    //red card will be recieved

        team_stats[6] += 1; //red cards increased by 1 

    }

}

void output_stats(int team_a[], int team_b[]) {

    cout << "Team A's Stats" << setw(35) << "Team B's Stats\n";
    cout << team_a[0] << setw(25) << "Score" << setw(20) << team_b[0] << "\n";
    cout << team_a[1] << setw(28) << "On Goal Shots" << setw(17) << team_b[1] << "\n";
    cout << team_a[2] << setw(28) << "Off Goal Shots" << setw(17) << team_b[2] << "\n";          //outputs the stats of each team in a nicely organized table
    cout << team_a[3] << setw(28) << "Blocked Shots" << setw(17) << team_b[3] << "\n";
    cout << team_a[4] << setw(25) << "Fouls" << setw(20) << team_b[4] << "\n";
    cout << team_a[5] << setw(28) << "Yellow Cards" << setw(17) << team_b[5] << "\n";
    cout << team_a[6] << setw(28) << "Red Cards" << setw(17) << team_b[6] << "\n";

}

void run_game() {

    srand(time(0)); //makes sure new random numbers are generated each time the code is run 
    
    //variable and array declarations
    int rand_event = rand() % 20 + 1;        //number of events in the game
    int half_time = rand_event / 2;          //how many events until half time
    int team_a_stats[7] = { 0,0,0,0,0,0,0 };    //the 2 arrays will hold the stats for each time, see below for what each element represents...
    int team_b_stats[7] = { 0,0,0,0,0,0,0 };

    //[0] is the score
    //[1] is the number of shots on goal
    //[2] is the shots off goal
    //[3] is the blocked shots
    //[4] is the fouls
    //[5] is the yellow cards
    //[6] is the red cards

    for (int event_num = 0; event_num < rand_event; event_num++) {    //main for loop will iterate through all the events

        cout << "\n";   //makes output more organized
         
        if (event_num == half_time && rand_event > 1) {      //if half time has been reached, it will output the stats for both teams by calling the ouput function

            cout << "It's Half Time!" << "\n";
            output_stats(team_a_stats, team_b_stats);
            cout << "\n";
        }

        int rand_play = rand() % 6 + 1;    //random number will determine what happens in each event


        if (rand_play == 1) {

            cout << "Team A has just shot the ball! \n";     
            team_shot_event(team_a_stats, "Team A");

        }                                                                               //A team has shot the ball so the "team_shot_event" function will be called

        if (rand_play == 2) {

            cout << "Team B has just made a shot! \n";   
            team_shot_event(team_b_stats, "Team B");

        }

        if (rand_play == 3) {

            cout << "Team B has commited a rude foul on Team A. A free kick will be awarded to Team A \n";
            team_shot_event(team_a_stats, "Team A");
            give_card(team_b_stats, "Team B");

        }                                                                                                 //A team has fouled the other, so the "team_shot_event" function is called again to determine what happens in the free kick
                                                                                                          //"give_card" function is also called to determine which card the team recieves, if any
        if (rand_play == 4) {

            cout << "Team A has commited a rude foul on Team B. A free kick will be awarded to Team B \n";
            team_shot_event(team_b_stats, "Team B");
            give_card(team_a_stats, "Team A");

        }

        if (rand_play == 5) {

            cout << "Team B made a dirty move near the net. Team A will be given a penalty!\n";
            penalty_event(team_a_stats, "Team A");
            give_card(team_b_stats, "Team B");

        }                                                                                                  //A team has gotten a penalty so the "penalty_event" function is called to see how the penalty will play out

        if (rand_play == 6) {                                                                             //"give_card" function is also called to see if the team gets any cards

            cout << "Team A made a dirty move near the net. Team B will be given a penalty!\n";
            penalty_event(team_b_stats, "Team B");
            give_card(team_a_stats, "Team A");

        }

    }

    cout << "\n";
    cout << "Final Game Stats \n";
    output_stats(team_a_stats, team_b_stats);    //outputs the final stats of both teams
    cout << "\n";

    if (team_a_stats[0] > team_b_stats[0]) {
        cout << "Team A Won!";
    }

    else if (team_a_stats[0] == team_b_stats[0]) {      //determines which team has one, or if their is a tie
        cout << "Game is a Tie!";
    }

    else {
        cout << " Team B won!";
    }
}

int main() {

    run_game();   //calls the run_game function which will initiate the simulation

}

