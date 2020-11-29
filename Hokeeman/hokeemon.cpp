// hokeemon.cpp
// Ishan Meher, CISP 400
// 11/29/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include <ctime>
#include<memory>

using namespace std;



class Date
{
	private:

		int month; // Stores the current month
		int day;  // Stores the current day
		int year; // Stores the current year
		string monthList[12] ={"January","February","March","April","May","June","July","August","September","October","November","December"}; // Used to convert numeric month to the name of the month
		

	public:

		
		Date(int month, int day,int year)
		{
			// Constructor for Date object

			this->month=month; // sets pointer to this Date object's month to month parameter
			this->day=day; // sets pointer to this Date object's day to day parameter
			this->year=year; // sets pointer to this Date object's year to year parameter

		}


		Date()
		{
			// Initializes member variables to store current day
			time_t today = time(0);
 
 			tm *tdy = localtime(&today);

   			this->month=1 + tdy->tm_mon; //sets pointer to this Date objects month and initializes it to hold the current month
  			this->day=tdy->tm_mday;  //sets pointer to this Date objects day and initializes it to hold the current month	
   			this->year=1900+ tdy->tm_year;  //sets pointer to this Date objects year and initializes it to hold the current year
		}


		Date(const Date& date)
		{
			this->month=date.month;
			this->day=date.day;
			this->year=date.year;
		}	


	private:

		
		void testingSetDate(int month, int day, int year)
		{
			// Tests wether the setDate method sets the Date object's member variables are correctly set
			setDate(month,day,year);
			if(month==this->month&&day==this->day&&year==this->year)
			{
				cout<<"Date member variables have been initialized\n";
			}
			else
			{
				cout<<"Date member variables have not been initialized\n";
			}
		}

		Date* testDateContructor(int month,int day, int year)
		{
				// Tests wether the Constructor sets the Date object's member variables are correctly set
				Date date(month, day, year);
				Date* testDate=&date;

				if(month==testDate->month&&day==testDate->day&&year==testDate->year)
				{
					cout<<"Date member variables have been initialized\n";
					cout<<"Contructor successfully works\n";
				}
				
				else
				{
					cout<<"Date member variables have not been initialized\n";
					cout<<"Contructor failed\n";
				}

				return testDate;

		}


	public:

    int getMonth()
    {
      return month;
    }

    int getDay()
    {
      return day;
    }

    int getYear()
    {
      return year;
    }
		
		bool isValidDate(int month,int day,int year)
		{
			// Checks wether the month, day and year are valid
			if(validMonth(month)&&validYear(year)&&validDay(month,day,isLeap(year)))
			{
				return true;
			}
			else
			{
				return false;
			}

		}

		Date& operator =(const Date& date)
		{
			this->month=date.month;
			this->day=date.day;
			this->year=date.year;
			return *this;
		} 

		bool validMonth(int month)
		{
			// Checks if the month entered is a valid month
			// return true if the month is between 1 and 12 inclusive
			if(month>=1&&month<=12)
			{
				return true;
			}

			else
			{
				cout<<"Month input failed!\n";
				return false;
			}	
		}

		bool validDay(int month,int day,bool isLeap)
		{
			// Checks wether the day entered is a valid day based on the day
			bool valid=true;

			// Fails if the month is not a valid month, month is needed for day validity		


			if(day>31||day<1)
			{
				// Its not possible to have negative days or more than 31 days in a month
				cout<<"Day input failed!\n";
				cout<<"Months usually have days ranging from 1 and 31 days (inclusive)\n";
				return false;
			}

			else
			{

				if((month==9||month==11)||(month%2==0&&(month!=10||month!=12||month!=8||month!=2)))
				{
					// Tests to see if months that have 30 days do not have more than 30 days
					// Most even months have 30 days have 30 days except December August and February
					// The odd months September and November have 30 days
					if(day>=31||day<1)
					{
						// Checks if the day entered of the checked months don't have more than 30 days or less than 1
						cout<<"Day input failed!\n";
						cout<<"Most of the even months have 30 days, Not including the months of February and August\n";
						cout<<"The odd months of September and November have 30 days\n";
						return false;
					}
				}
				if(month==2)
				{
					if(isLeap&&day>=30)
					{
						// There are 29 days in the month of february during leap year
						cout<<"Day input failed!\n";
						cout<<"The month of February has only dates between 1-29 (inclusive) during leap year\n";
						return false;

					}

					else if(!isLeap&&day>=29)
					{
						// ELse if its a Common year then it will have 28 days
						cout<<"Day input failed!\n";
						cout<<"The month of February has only dates between 1-28 (inclusive) during a common year\n";
						return false;
					}
				}

				else
				{				
					
					// Runs if the month is odd and not September or November then but can be even only if December, October or August
					// These months have 31 days
					
				}

			}			

			return valid;

			
		}

		bool isLeap(int year)
		{
			// Checks wether a year is a leap year or not		

			if(year%4!=0)
			{
				// Common year if not divisible by 3
				return false;
			}

			else if(year%100!=0)
			{
				// Common year if divisible by 100
				
				return true;
			}

			else if(year%400!=0)
			{
				// Commmon year if not divisible by 400
				
				return false;
			}

			else
			{
				// If it is not a common year then the year is a leap year
				
				return true;

			}
			
			

		}


		bool validYear(int year)
		{
			if(year>=0&&year<=3000)
			{
				// Checks if a reasonable year is entered				
				return true;				
			}

			else
			{
					cout<<"Year input failed!\n";
					cout<<"The year entered is not a reasonable year entry try a year larger than 0 and less than 3000\n";
					return false;
			}
		}

		string getDate()
		{
			// Prints the date
			if(isValidDate(month,day,year))
			{
				// The date will only be printed if the date is a valid date

				string monthString= monthList[month-1];
				
				
				return (monthList[month-1]+" "+to_string(day)+", "+to_string(year));

			}
			else
			{
				return "Date is not valid!";
			}	
		}

		string getNumericDate()
		{
			// Prints the date
			if(isValidDate(month,day,year))
			{
				// The date will only be printed if the date is a valid date

				
				return (to_string(month)+"/"+to_string(day)+"/"+to_string(year));

			}
			else
			{
				return "Date is not valid!";

			}	

		}

		void setDate(int month, int day, int year )
		{
			// Utility dunctio used to set a date by changing instance variables 
			
			this->month=month; 
			this->day=day;
			this->year=year;


		}

        friend ostream& operator << (ostream &output,Date& date)
	{
		// Prints the data of the Date Class
    	output<<date.getDate()<<'\n'; 
    	return output;
	}

		
		void dateUnitTest()
		{
			//Tests the cases in which dates will work and cases where dates will fail

			cout<<"Date Unit Tests\n";
			// Printing Today's Date
			Date testDate;
			cout<<"Displaying Today's date in Letter form\n";
			cout<<testDate.getDate()<<'\n';
			cout<<"Entering Today's date in numeric form\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"\n";
			
			// Testing Constructor with multiple parameters and checking date entered
			cout<<"Testing wether the multiple parameter constructor works\n";
			
			cout<<"Displaying Today's date in Letter form\n";
			cout<<"Printing Numeric Date:\n";	
			cout<<"Expected: 12/15/2015\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"Printing Letter Date\n";
			cout<<"Expected "<<"December 15, 2015\n";	
			cout<<"Date: "+testDate.getNumericDate()<<'\n';
			cout<<"\n";
			cout<<"\n";;


			// Fails all the tests for a valid date
			cout<<"Testing a Day that fails for any date test \n";
			testDate.testingSetDate(12000,15000,2020);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"\n";
		

			// A date can't have a month that is more than 12
			testDate.testingSetDate(13,29,2000);
			cout<<"Testing a month that is not valid!\n";
			cout<<"Testing a month that is greater than 12\n";			
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"\n";


			// A month can't be less than 1
			cout<<"Testing a month that will fail! \n";
			cout<<"Testing a month smaller than 1\n";	
			testDate.testingSetDate(0,12,2020);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"\n";


			// Testing a date to have a month that works
			cout<<"Testing a month that works\n";
			testDate.testingSetDate(12,15,2015);
			cout<<"Printing Numeric Date:\n";	
			cout<<"Expected: 12/15/2015\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"Printing Letter Date\n";
			cout<<"Expected "<<"December 15, 2015\n";	
			cout<<"Date: "+testDate.getNumericDate()<<'\n';
			cout<<"\n";
			cout<<"\n";


			cout<<"Testing a year smaller than expected that fails\n";
			testDate.testingSetDate(12,15,1800);
			cout<<"Printing Numeric Date:\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"Printing Letter Date\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a year that works\n";
			testDate.testingSetDate(12,15,2020);
			cout<<"Printing Numeric Date:\n";
			cout<<"Expected: 12/15/2002\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: December 15, 2020\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			// A month can't have more than 31 days
			cout<<"Testing a day that is greater than 31\n";
			testDate.testingSetDate(2,32,2000);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			// A month can't less than 1 day
			cout<<"Testing a day that is less than 1\n";
			testDate.testingSetDate(1,0,2000);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			// The month of April has 30 days 
			cout<<"Testing a Day that fails for a 30 day month\n";
			testDate.testingSetDate(4,31,2020);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";


			// The month of april has 30 days
			cout<<"Testing a Day that passes for a 30 day month \n";
			testDate.testingSetDate(4,30,2020);	
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: 4/30/2020\n";	
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;	
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: April 30, 2020\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';

			cout<<"\n";
			cout<<"\n";

			// The Month of February has 29 days on leap year
			cout<<"Testing a day in february that fails when it is leap year \n";
			testDate.testingSetDate(2,30,2022);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";


			cout<<"Testing a day in february that passes when it is leap year \n";
			testDate.testingSetDate(2,29,2000);
			cout<<"Printing Numeric Date\n";
			cout<<"Expected: 2/29/2000\n";
			cout<<"Printing Letter Date\n";
			cout<<"Expected: February 29, 2000\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			// The month of February has 28 days in a Common year
			cout<<"Testing a day in february that fails when it is not a leap year \n";
			testDate.testingSetDate(2,29,2001);
			cout<<"Expected: Date is not valid\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a day in february that passes when it is not leap year \n";
			testDate.testingSetDate(2,28,2001);
			cout<<"Printing Numeric Date\n";
			cout<<"Expected: 2/28/2001\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';;
			cout<<"Printing Letter Date\n";
			cout<<"Expected: February 28, 2001\n";
			cout<<"Date: "+testDate.getNumericDate()<<'\n';	
			cout<<"\n";
			
		

	}

};


// Specification C2 - Creature class
class Creature
{
    public:
    string name;
    int boredomLevel;
    int hungerLevel;

  public:


    Creature()
    {
        this->hungerLevel=randomNumberGenerator(0,5);
        this->boredomLevel=randomNumberGenerator(0,5);
    }
    Creature(string name)
    {
        this->name=name;
        this->hungerLevel=randomNumberGenerator(0,5);
        this->boredomLevel=randomNumberGenerator(0,5);
    }
    
    // Specification C1 - PassTime()
    void passTime();

    // Feeds the Creature a random amount of food (3-6)
    // Increases the hungerLevel
    void feedCreature();


    // Play with the Creature
    // Increases the boredomLevel by a random amount (4-8)
    void playWithCreature();

    // Generates a random number between two numbers
    int randomNumberGenerator(int lo,int hi);

    // Specification B2 - Virtual Class Creature
    virtual bool isParalyzed()=0;
    


  

    // Specification C4 - Overload «
    friend ostream& operator << (ostream& out,Creature& creature)
    {
		// Specification A4 - Write a Lambda
		auto printTrue = [](bool value) 
    	{ 
        	if(value==true)
			{
				return "true";
			}
			else
			{
				return "false";
			}
			
   		}; 

        out<<"Name: "<<creature.name<<'\n';
        out<<"Boredom Level: "<<creature.boredomLevel<<'\n';
        out<<"Hunger Level: "<<creature.hungerLevel<<'\n';
        out<<"Is Paralyzed: "<<printTrue(creature.isParalyzed())<<"\n";
        return out;
    }




};



void Creature ::passTime()
{
    
    this->hungerLevel--;
    this->boredomLevel++;    
}

int Creature :: randomNumberGenerator(int lo,int hi)
{
   // Generates a random number between lo and hi
  int random = (rand()% (hi-lo+1))+lo;
    
  return random;
}



  void Creature :: feedCreature()
  {
    // Feed the Hokeemon and increase hungerLevel by a random number

    int amountToFeed=randomNumberGenerator(3,6);
    this->hungerLevel+=amountToFeed;
    passTime();
  }

  void Creature:: playWithCreature()
  {

    // Play with the Hokeemon and decrease boredomLevel by a random number
    int boredomLevelUpdated= randomNumberGenerator(4,8);
    this->boredomLevel-=boredomLevelUpdated;
    passTime();
  }
  

// Specification B1 - Child Class
class Hokeemon:public Creature
{ 
    public: 

    Hokeemon()
    {
    this->boredomLevel=randomNumberGenerator(0, 5);
    this->hungerLevel=randomNumberGenerator(0, 5);
    }
    virtual bool isParalyzed()
    {
        return boredomLevel>20;
    }

    bool isDead()
    {
        return hungerLevel<0;
    }

    
    Hokeemon(Hokeemon& parent1, Hokeemon &parent2)
    {
        // Use the overloaded + operator to increase hungerLevels
        this->name=parent1.name+" "+parent2.name;
        this->hungerLevel+=parent1.hungerLevel+parent2.hungerLevel;
		    this->boredomLevel-=parent1.boredomLevel-parent2.boredomLevel;        

    }

    
    friend ostream& operator << (ostream& out,Hokeemon& creature)
    {
		
		auto printTrue = [](bool value) 
    	{ 
        	if(value==true)
			{
				return "true";
			}
			else
			{
				return "false";
			}
			
   		}; 

        out<<"Name: "<<creature.name<<'\n';
        out<<"Boredom Level: "<<creature.boredomLevel<<'\n';
        out<<"Hunger Level: "<<creature.hungerLevel<<'\n';
        out<<"Is Dead: "<<printTrue(creature.isDead())<<"\n";
        out<<"Is Paralyzed: "<<printTrue(creature.isParalyzed())<<"\n";
        return out;
    }



    //Specification B3 - Overload Assignment Operator
    Hokeemon& operator =(const Hokeemon& hokeemon)
    {
			this->name=hokeemon.name;
			this->hungerLevel=hokeemon.hungerLevel;
			this->boredomLevel=hokeemon.boredomLevel;
			return *this;
	} 

  // Specification A2 - Copy Constructor
  Hokeemon(const Hokeemon& hokeemon)
	{
        // Copy Constructor for Hokeemon
        // Absorbs and Spits out the other Hokeemon
        // Takes the other Hokeemon's hunger and boredom levels and uses it to strengthen itself
		this->name=hokeemon.name;
		this->hungerLevel+=hokeemon.hungerLevel;
		this->boredomLevel-=hokeemon.boredomLevel;        
	} 

 
  
  Hokeemon(string name)
  {
    this->name=name;
    this->boredomLevel=randomNumberGenerator(0, 5);
    this->hungerLevel=randomNumberGenerator(0, 5);
  }

  

  //Specification B4 - Overload + Operator
  Hokeemon operator +(Hokeemon& hokeemon)
  {
	// Overloaded Add Operator
	// Takes
    this->name+=" "+hokeemon.name;
    this->hungerLevel=hokeemon.hungerLevel;
    this->boredomLevel=hokeemon.boredomLevel;
    return *this;
  }

	void UnitTest()
	{
    cout<<"Hokeeman Unit Tests\n";
    cout<<"Making Object for Testing\n";
		Hokeemon hokeemon("Blue Eyes");
    cout<<hokeemon<<'\n';
    cout<<"\n";

    cout<<"Making Object for Testing\n";
		Hokeemon hokeemon2("White Dragon");
    cout<<hokeemon2<<'\n';
    cout<<"\n";
	Hokeemon hokeemon3 = hokeemon+hokeemon2;
    cout<<"Testing the overloaded add operator\n";
    cout<<hokeemon3<<'\n';

    cout<<"Testing the Overloaded Assignment Operator\n";
    hokeemon3=hokeemon2;
    cout<<hokeemon3<<'\n';

	}


};


// Specification A3 - Second Child Class
class BattleHokeemon : protected Creature
{
  public:
  int health;
  string elementalType;
  int attackDamage;


  public:

  void UnitTest()
  {
    cout<<"Battle Hokeeman Unit Tests\n";
    BattleHokeemon pikachu("Pikachu","fire",200);
    cout<<pikachu<<'\n';
    BattleHokeemon magikarp("Magikarp","water",200);
    cout<<magikarp<<'\n';

    
    cout<<"Testing forming a new child hokeemon from two hokeemon\n";
	BattleHokeemon evolvedHokeemon(pikachu,magikarp);
    cout<<evolvedHokeemon<<'\n';

  
    cout<<"Testing the dealDamage() Function by running a fight\n";
    cout<<"\n";  
    while(!magikarp.isParalyzed())
    {
      pikachu.dealDamage(magikarp);
      cout<<magikarp.name<<" "<<magikarp.returnLifeState()<<'\n';
      
    }
    
  }

  string returnLifeState()
    {
      if(!isParalyzed())
      {
        return "Alive";
      }
      else
      {
        return "Dead";
      }
    }


  BattleHokeemon()
  { 
  }


  BattleHokeemon(string name,string elementalType, int health)
  { 
    this->name=name;
    this->elementalType=elementalType;
    this->health=randomNumberGenerator(5,health);
    this->attackDamage=randomNumberGenerator(2,100);
  }


  BattleHokeemon(BattleHokeemon &h1, BattleHokeemon& h2)
  { 
    this->name="Shiny "+h1.name+" "+h2.name;
    this->elementalType=h1.elementalType;
    this->health=h1.health+h2.health;
    this->attackDamage=h2.attackDamage+h1.attackDamage;
  }


	void dealDamage(BattleHokeemon& hokeemon)
  {
      cout<<this->name<<" is attacking\n";
      int damageDealt=randomNumberGenerator(1,this->attackDamage);
    	hokeemon.health-=damageDealt;
      if(attackDamage==0)
      {
        cout<<hokeemon.name<<" dodged the attack\n";
      }
      else
      {
        cout<<hokeemon.name<<" took \n"<< attackDamage<<'\n';
      }
  }

  bool isParalyzed()
  {
    return health<=0;
  }

friend ostream& operator << (ostream& out,BattleHokeemon& creature)
    {
		
		auto printTrue = [](bool value) 
    	{ 
        	if(value==true)
			{
				return "true";
			}
			else
			{
				return "false";
			}
			
   		}; 

        out<<"Name: "<<creature.name<<'\n';
        out<<"Is Paralyzed: "<<printTrue(creature.isParalyzed())<<"\n";
        out<<"Attack Damage: "<<creature.attackDamage<<'\n';
        out<<"Health: "<<creature.health<<'\n';
        return out;
    }
};


// Function Protypes
void ProgramGreeting();
void UnitTest();
void pressEnterKey();
void playGame(Hokeemon& hokeemon);
void displayHokeemonTask();
bool validateInput(string input,Hokeemon& hokeemon);

int main()
{
	ProgramGreeting();
  pressEnterKey();
  system("clear");
	UnitTest();
  pressEnterKey();
  system("clear");
  ProgramGreeting();
	Hokeemon hokeemon;
	playGame(hokeemon);
	
}

 void playGame(Hokeemon& hokeemon)
  {
    bool done;
   

    // Specification A1 - Critter Name
    string name;
    do
    {
       cout<<"Print the Hokeemon's Name:\n";
      getline(cin,name);
      system("clear"); 
    }
    while(name=="");
    
    hokeemon.name=name;
    string command;
    
    do
    {
       
        displayHokeemonTask();
        
        getline(cin,command);
        system("clear");
        
        done= validateInput(command,hokeemon);
   
    
    }
    while(!done);
  }

 // Specification C3 - Validate Input
  bool validateInput(string input,Hokeemon& hokeemon)
  {
    if(hokeemon.isDead())
    {
        cout<<hokeemon.name+" is dead from starvation.\n";
      cout<<"The Game is Over\n";
      return true;
    }
    else if(hokeemon.isParalyzed())
    {
      cout<<hokeemon.name+" is paralyzed from of boredom.\n";
      cout<<"The Game is Over\n";
      return true;
    }
	if(input.length()>0)
	{
    
		string command = input.substr(0,1);
    
		if(input=="L"||input=="l")
		{
			cout<<hokeemon<<"\n";
      hokeemon.passTime();
		}
		else if(input=="P"||input=="p")
		{
			hokeemon.playWithCreature();
		}
		else if(input=="F"||input=="f")
		{
			hokeemon.feedCreature();
		}
		else
		{
		cout<<"Not a valid input\n";
		}	
	}
      return false;
  }

void displayHokeemonTask()
	{
		cout<<"Hokeemon Menu\n";
		cout<<"========================\n";
		cout<<"(L)isten to Hokeemon\n";
		cout<<"(F)eed Hokeemon\n";
		cout<<"(P)lay with Hokeemon\n";
		cout<<"========================\n";
	}



// Program Greeting
void ProgramGreeting()
{
   Date currentDate;
	cout<<"Today's Date: "<<currentDate;
    cout<<"============================\n";
    cout<<"Welcome to the Hokeemon Game\n";
    cout<<"A Game where you take care of your Hokeemon\n"; 
	  cout<<"Play with and feed your Hokeemon to keep it alive\n";
    cout<<"Program Author: Ishan Meher\n";
    cout<<"Program Due Date: November 29, 2020\n";
	cout<<"============================\n";
} 


// Unit Tests
void UnitTest()
{
  cout<<"Starting Unit Testing\n";
  Date date;
  date.dateUnitTest();
  pressEnterKey();
  system("clear");
 
  Hokeemon hokeemon;
  hokeemon.UnitTest();
  pressEnterKey();
  system("clear");
  BattleHokeemon pikachu;
  pikachu.UnitTest();

}

void pressEnterKey()
{
	// Clears the console and asks the user to press the enter key to contine
	 int enter=0;
        
        cout << "Press Enter key to Continue\n";
        while (enter==cin.get() )      
		{
                if ( enter == (int)'\n' ) 
                {
                    
                    break;
                }
                else 
                {
                    cout << "Failure, Program Quitting\n";
                    exit(EXIT_FAILURE);
                }
        }

}

