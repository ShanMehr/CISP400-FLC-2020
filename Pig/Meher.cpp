// C++ Meher.cpp
// Ishan Meher, CISP 400
// 9/6/2020

#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

class Pig
{
	private:

		int highScore=0;
		int playerScore=0;
		int computerScore=0;
		string playerFirstName;
		string playerLastName;
		string playerFullName;

	public:

		Pig(string first,string last)
		{
			// Constructor that creates(instantiates) pig objects
			playerFirstName=first;
			playerLastName=last;
			playerFullName=first+" "+last;
		}

	private:

		void setPlayerScore(int score)
		{
			// Assigns a value to playerScore
			playerScore=score;	
		}
		void setComputerScore(int score)
		{
			// Assigns a value to playerScore
			computerScore=score;
		}
		int setHighScore()
		{
			// Compares the playerScore and computerScore,sets larger score to high score
			// Returns the new highSocore;

			highScore= max(playerScore,computerScore);
			return highScore;
		}
	public:

		void recordPlayerScore(int pointsPlayerScored)
		{
			// Checks if score entry is a valid range between 0 and 100
			// updates the playerScore
			if(pointsPlayerScored>0 && pointsPlayerScored<=100)
			{
				int playerPoints= playerScore+pointsPlayerScored;
				setPlayerScore(playerPoints);
				
			}
		}
		
		void recordComputerScore(int pointsComputerScored)
		{
			// Checks if score entry is a valid range between 0 and 100
			// updates computerScore
			
			if(pointsComputerScored>0 && pointsComputerScored<=100)
			{
				int computerPoints=pointsComputerScored+computerScore;
				setComputerScore(computerPoints);
				
			}
			
		}

		int getPlayerScore()
		{
			// Returns playerScore
			return playerScore;
		}

		int getComputerScore()
		{
			// Returns computerScore
			return computerScore;
		}

		int getHighScore()
		{
			// Returns highScore
			return (setHighScore());
		} 

		string getPlayerFirstName()
		{
			// Returns playerFirstName
			return playerFirstName;
		}
		string getPlayerLastName()
		{
			// Returns playerLastName
			return playerLastName;
		}
		string getPlayerFullName()
		{
			// Returns playerFullName
			return playerFullName;
		}

};

// Function Prototypes
void ProgramGreeeting();
void UnitTest();
void displayInstructions();
void startPig();
Pig* requestPlayerName();
void gameMenuDisplay();
int gameInput(Pig *pig);
int randomNumberGenerator(int seed);
int randomNumberGenerator();
int fixedRoll();
int randomRoll(int lo,int hi);
int protectedRandomNumberOutput(int lo,int hi);
int protectedRandomNumberInput(int lo, int hi);
int randomRoll();
void computerRoll(Pig *pig);
void displayTurnStats(Pig *pig);
void displayHighScore(Pig *pig);
void displayCurrentHighScorer(Pig *pig);
void displayWinner(Pig *pig);

int main()
{
	
	ProgramGreeeting();
	UnitTest();
 	displayInstructions();
 	startPig();
}

//Specification B2 - Display Due Date
void ProgramGreeeting()
{
	//Program Greeting
	cout<<"This program implements the game Pig"<<'\n';
	cout<<"Program Due Date: 9/6/2020"<<'\n'<<" "<<'\n';
	
	
	
}

void UnitTest()
{
	//UnitTest
	//Tests core program functions

	cout<<"Starting UnitTest, Enter a Value, Example(5 or c) to begin"<<'\n';
	string unitTest;
	cin>>unitTest;


	

	cout<<"Validating int protectedRandomNumberInput(int lo,int hi) function which returns a -1 error code when lo is greater than hi,"<<'\n'<<" "<<'\n';
	cout<<"Also returns error code when lo is less than 1, "<<"And when hi parameter is greater than 100"<<" "<<'\n'<<" "<<'\n';
	cout<<"Validating int protectedRandomNumberInput(int lo, int hi), by entering an int lo paramater greater than in hi parameter to verify a -1 error code is returned "<<'\n'<<"Running Function:"<<protectedRandomNumberInput(100,1)<<'\n'<<" "<<'\n';
	cout<<"Validating int protectedRandomNumberInput(int lo, int hi), by entering an int lo parameter as 0 to verify -1 error code is returned"<<'\n'<<"Running Function:"<<protectedRandomNumberInput(0,1)<<'\n'<<" "<<'\n';
	cout<<"Validating int protectedRandomNumberInput(int lo, int hi), by entering an int hi parameter to verify a -1 is returned when 100 value is passed as hi"<<'\n'<<"Running Function:"<<protectedRandomNumberInput(1,100)<<'\n'<<" "<<'\n';
	cout<<"Displaying int protectedRandomNumberInput(int lo, int hi), value when a correct input is entered, 1 is passed as lo and 6 is passed as hi"<<'\n'<<"Running Function:"<<protectedRandomNumberInput(1,6)<<'\n'<<" "<<'\n';




}

void displayInstructions()
{
	// Displays how to play Pig
	cout<<"Game Instructions:"<<'\n'<<""<<'\n';
	cout<<"Roll a dice against the computer."<<'\n';
	cout<<"If you roll a number between 2-6(inclusive) then you can choose to roll again."<<'\n';
	cout<<"But if you roll a 1 then you lose the points you have gained during your turn."<<'\n';
	cout<<"You can choose to hold your score to keep the points you have gained in exchange for ending your turn"<<'\n';
	cout<<"The first to get 100 points wins Pig"<<'\n'<<" "<<'\n';
  cout<<"Good Luck!"<<'\n';
}


// Specification B3 - Hi Score on Heap
void startPig()
{
	// Runs the game Pig


	cout<<"Enter a value to begin the game, Example(5 or c or helloWorld)"<<'\n';
	string game;
	cin>>game;


	int playerInput=0;
	Pig *pig = requestPlayerName();	// Calls requestPlayerName which returns adress of object stored on the heap

	while(playerInput!=-1&&(pig->getHighScore()<100))
	{
		// Loops until highScore on gameInformation Object is greater than 100 or player has ended the game

		int turn=0;
		// turn Variable keeps track of what tasks turn it is to be performed

		if(turn==0)
		{
			turn=1;
			playerInput=gameInput(pig); //Player's turn
			

			if(playerInput==-1)
			{
				// Closes the game
				cout<<"Quitting Game"<<'\n';
					
				break;
			}
		}

		if(turn==1)
		{
			computerRoll(pig);
			turn=2;
		}

		if(turn==2)
		{
			displayTurnStats(pig); // Displays the current score of the player and the computer
			displayHighScore(pig);	// Displays the current high score
			displayCurrentHighScorer(pig); // Dispalys who has the high score	
		}
		
	}
	
	
	displayHighScore(pig); // Displays the high score
	displayWinner(pig);	// Disaplys the winner
	delete pig;
	pig=nullptr;	// Frees memory on the heap that points to the gameInformation object
  	
}

// Specification C2 - Student Name
Pig* requestPlayerName()
{
	// Requests and stores the player's last name in the pig object
	// Then stores the pig object on the heap and returns the adress of the object
	string firstName;
	string lastName;

	cout<<"Print your first name"<<'\n';
	cin>>firstName;
	cout<<"Print your last name"<<'\n';
	cin>>lastName;

	Pig *pig = new Pig(firstName,lastName);
	cout<<"Hello "<<pig->getPlayerFullName()<<'\n'<<" "<<'\n';
	return pig;
}



// Specification C3 - Numeric Menu
void gameMenuDisplay()
{
  // Numeric Menu that displays input options
 	cout<<"Enter a value:"<<'\n';
 	cout<<"1)	1.Roll"<<'\n';
 	cout<<"2)	2.Hold"<<'\n';
 	cout<<"3)	3.Quit"<<'\n';
}

// Specification C4 - Bulletproof Menu
int gameInput(Pig *pig)
{
  
	// Accepts and processes user input
	int currentScore=0; // Stores the score that the player has earned
	bool canHold=false; //Stores the number of times the player has rolled the dice
	int chosenValue=0;// Stores the value inputted by the player
	bool done;// Stores wether the player has ended their turn by quitting or rolling a 1

	do
	{
		gameMenuDisplay();
		//Displays the Numeric Menu 

		cin>>chosenValue;	
		// Accepts an input
		
		if(cin.fail())
		{	
			// Checks if the inupt has failed clears the fault input entered in cin
			cin.clear();
			cin.ignore(256,'\n');
		}

		if(chosenValue==1)
    	{
			cout<<"Rolling Dice"<<'\n';

			int valueRolled= protectedRandomNumberOutput(1,6); 
			// Stores the value that is rolled;
      
			cout<<"You Rolled a "<<valueRolled<<'\n';

			if(valueRolled==1)
			{
				// End turn if 1 has beeen rolled 
				cout<<"Better luck next turn"<<'\n'<<" "<<'\n';
				currentScore=0;
				done=true;
			}

			else
			{
				// If a 1 has not been rolled then add the value rolled to the total points earned during the turn
				currentScore+=valueRolled;
				canHold=true;
        
			}
		}
		
		else if(chosenValue==2)
		{

			if(canHold==false)
			{
				// Prevents player from entering a hold when no points are earned
				cout<<"Don't give up you have a chance to earn points this round!"<<'\n';
				cout<<"Try Rolling the dice to earn some points"<<'\n'<<""<<'\n';
			}

			else
			{
				// If player has points let them hold their points
				cout<<"Holding Points"<<'\n';
				cout<<"Points earned during this round: "<<currentScore<<'\n'<<" "<<'\n';
				done=true;
			}

		}

		else if(chosenValue==3)
		{
			// If player chooses to quit return a -1 to inform that the player intends to quit
			int errorValue=-1;
			currentScore=errorValue;
			done=true;
		}

		else
		{
			cout<<"Invalid Input!"<<'\n';
			//Number Rolled is invalid
		}

 	}
	while(!done);

	if(currentScore>0)
	{
		pig->recordPlayerScore(currentScore);
		// Store Computer's Score in pig object;
	}		   

	return currentScore;

}




// Specification C1 - Fixed Seed
int randomNumberGenerator(int seed)
{
	//Accepts a Seed and returns a number
	srand(seed);
	return rand();
}

// Specification A1 - D6() function
int randomNumberGenerator()
{
	// Generates a random number
	return rand();
}

int fixedRoll()
{
	// Rolls a fixed number	betweeb 1 and six
	int roll= (randomNumberGenerator(12)%6+1);
	return roll;
}

int randomRoll()
{	
	// Rolls a random number between 1 and 6
	int roll= randomNumberGenerator()%6+1;
	return roll;
}

void computerRoll(Pig *pig)
{
	// Computer Rolls Die and store the score in pig object if 1 is not rolled
	// Returns an int 
	int pointsEarned=0;
	bool done;

	cout<<"It's the Computer's turn"<<'\n';

	do
	{
		
		// int computerRoll=fixedRoll();  
		int computerRoll=protectedRandomNumberOutput(1,6);

		if(computerRoll>=2&&computerRoll<=6)
		{
			// If roll is not 6 store points
			pointsEarned+=computerRoll;
			if(computerRoll<4)
			{
				// If roll was less then hold points
				done=true;
				cout<<"The Computer earned: "<<pointsEarned<<'\n';
				done=true;
			}			

		}

		else
		{
			// Computer earns no points and turn is ended 
			pointsEarned=0;
			cout<<"The Computer earned no points"<<'\n';
			done=true;

		}

		if(pointsEarned>=100)
		{
			// If Computer earns more than 100 points end the turn
			done=true;
		}			
	}

	while(!done&& pointsEarned<=100);

	cout<<"The Computer has finished its turn"<<'\n';
	pig->recordComputerScore(pointsEarned); // Store Computer's Score in pig object;
	cout<<" "<<'\n';
	
}



// Specification A2 - RandomNumber() function
int randomRoll(int lo,int hi)
{
	// Generates a ranodm number between lo and hi
	int random = (rand()% (hi-lo+1))+lo;
  
	 return random;
}

// Specification A3 - Protect RandomNumber() input
int protectedRandomNumberInput(int lo, int hi)
{
	// Validates lo and hi
	// Checks if lo is not greater than high 
	// Checks if lo is not less than zero
	// Checks if high is not greater than 100
	// Generates a random number between lo and hi if conditions met
	// Otherwise if not met a -1 error code is displayed
	
	if(lo>hi)
	{
		return -1;
	}

	else if(lo<1)
	{
		return -1;
	}

	else if(hi>=100)
	{
		return -1;
	}

	else
	{
		return randomRoll(lo, hi);
	}

}

// Specification A4 - Protect RandomNumber() output
int protectedRandomNumberOutput(int lo,int hi)
{
	// Validates the protected input to see if outpus is not greater than 100
	int randomNumber = protectedRandomNumberInput(lo,hi);

	if(randomNumber==-1)
	{
    	// Checks if failed protectedRandomNumberInput test
		return -1;
	}

	else if(randomNumber>100)
	{
		return -2;
	}

	else
	{
		return randomNumber;
	}

}



// Specification B1 - Display Turn Stats
void displayTurnStats(Pig *pig)
{
	// Displays the scores of each player
	cout<<pig->getPlayerFullName()<<" Scored: "<<pig->getPlayerScore()<<'\n';
	cout<<"Computer Score: "<<pig->getComputerScore()<<'\n';
	cout<<" "<<'\n';
}

// Specification B4 – Display High Score
void displayHighScore(Pig *pig)
{	
	// Displays the high score
	cout<<"High Score: "<<pig->getHighScore()<<'\n';
	
}

void displayCurrentHighScorer(Pig *pig)
{
  	// Displays who has the high score
	if(pig->getComputerScore()<pig->getPlayerScore())
	{
		cout<<pig->getPlayerFullName()<<" has the current high score!"<<'\n';

	}

	if(pig->getComputerScore()>pig->getPlayerScore())
	{
		cout<<"The Computer has the current high score!"<<'\n';	
	}

	if(pig->getComputerScore()==pig->getPlayerScore())
	{
		cout<<"You both are tied for the high score!"<<'\n';
		
	}

	cout<<" "<<'\n';

}

void displayWinner(Pig *pig)
{
  	//Displays the winner  
	if(pig->getComputerScore()<pig->getPlayerScore())
	{
		cout<<pig->getPlayerFullName()<<" Won!"<<'\n'<<"Congratulations, hope see to you again!"<<'\n';

	}

	if(pig->getComputerScore()>pig->getPlayerScore())
	{
		cout<<"The Computer Won!"<<'\n';
		
	}

	if(pig->getComputerScore()==pig->getPlayerScore())
	{
		cout<<"It's a tie!"<<'\n';
		
	}

	cout<<" "<<'\n';

}

