// hokeeman.cpp
// Ishan Meher, CISP 400
// 11/22/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include <ctime>
#include<memory>

using namespace std;

template <class A>
class Vector
{
	// The template class Vector creates an array that is able to store any data type 
	public:

		int length=0;
		A* array;

	public:
		
		Vector(int size)
		{	
			// Defines an Vector Object that accepts a length
			// Allocates space on the heap to store array
			if(length>=0)
			{
				// Makes sure the length is at least 0
				this->length=size;
				
			}			
			array= new A[length];
		}

		Vector()
		{
			// Creates an Vector object
			// Allocates space on the heap to store array
			this->length=0;
			array=new A[length];

		}

	private:

		void resizeVector()
		{
			// Resiszes the array by one

			A* tempVector= new A[length+1]; // The tempVector stores all the data of array and has one more element

			for(int position=0; position < length; position++)
			{
				// Loops through each position of the array and stores copies the element at each position into the tempVector
				tempVector[position]= array[position];
			}

			// Frees the memory used by the smaller array
			// The gradeList is set to point to the tempVector memory location
			delete[] array; 
			array=tempVector;	
			tempVector=nullptr;
		}

	public:

		void set(int index, A element)
		{
			// Changes the data stored at the requested index
			
				if(isValidIndex(index))
				{
					array[index]=element;
				}		
			
		}

		void clear()
		{
			// clears the contents of the arrray
			delete[] array;
			array=nullptr;
			length=0;
			array= new A[length]; 
		}

		int size()
		{
			// Returns the size of the array
			return length;
      
		}

	
		void add(A element)
		{
			// Adds a new element to the end of the array

			// Increases the size of the array by one
			resizeVector();
						
			array[length]=element;
			length++;		
			
		}

		bool isValidIndex(const int index)
		{
			// Checks if the index entered is within the bounds of the array
			return (index>=0&&index<length);
		}

		

		A get(const int index)
		{
			// Gets the data stored at the requested index
			// Returns the last index of the array if the requested index is invalid
			if(isValidIndex(index))
			{	
				return array[index];
			}
			else
			{
				// If the entered index is not valid returns value of last index
				return (array[length-1]);
			}
		}

		void printItem(int index)
		{	
				// Prints the item at the requested index
				cout<<array[index];
			
			
		}

		void printContents()
		{
			// Prints the the entire array
			for(int index=0;index>size();++index)
			{
				printItem(index);
			}
		}

		void remove(const int index)
		{
			// Removes an alement at any index of the array
			if(isValidIndex(index))
			{
				// If the index is a valid index then remove the element located at the position


				// Defines a temporary array allocated on the heap
				// The int copyPosition variable increases with the loop unless the position that is to be removed is reached
				// By not increasing int copyPosition it will make sure that one less item will be copied;
				A* tempVector = new A[length-1];
				int copyPosition=0;
				for(int position=0;position<length;position++)
				{

					if(!(position==index))
					{
						tempVector[copyPosition]=array[position];
						copyPosition++;
						

					}
					
				}
				delete[] array;
				length--;
				array=tempVector;
				tempVector=nullptr;
			}
			
		}


		
		void removeLast()
		{
			// Removes the element at the last index of the array
			remove(length-1);
		}

		
		void VectorUnitTest()
		{
			// Tests various functions of the Vector Class

			Vector<string> array;
			cout<<"Printing Initial Size:\n"<<array.size()<<'\n';
			cout<<"Adding an element:\n";
			array.add("Ishan Meher");
			cout<<"Printing Added element\n"<<array.get(0)<<'\n';
			

			cout<<"Adding a few Elements and printing these elements"<<'\n';
			array.add("Professor Fowler");
			cout<<"Printing the newly added element\n";
			cout<<array.get(1)<<'\n';
			array.add("Knuth");
			array.add("Warshall");
			array.add("Kruskal");

			cout<<"Printing All the elements in the array"<<'\n';
			for(int i=0;i<array.size();i++)
			{
				cout<<array.get(i)<<'\n';

			}
			cout<<'\n';

			cout<<"Removing last element(Kruskal is gone)\n";
			array.removeLast();

			for(int i=0;i<array.size();i++)
			{
				cout<<array.get(i)<<'\n';
			}

			array.remove(3);

			cout<<'\n';
			cout<<"Removing Warshall at index 2\n";			
			for(int i=0;i<array.size();i++)
			{
				cout<<array.get(i)<<'\n';
			}

			cout<<"Removing all elements"<<'\n';
			array.clear();
			
			cout<<"Adding element to cleared array\n";
			array.add("Ishan");
			cout<<array.get(0)<<'\n';
			cout<<array.size()<<'\n';
			cout<<"Changing the value of an index\n";
			array.set(0,"Professor Fowler");
			cout<<array.get(0)<<'\n';
			cout<<'\n';
		}
		
		~Vector()
		{
			delete[] array;
			array=nullptr;
			this->length=0;
		}	

};


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

		// Specification A3 - System Date.
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


	
	friend istream& operator >>(istream &input, Date& date)
	{
		// Sets the member variables for the Date Class
		cout<<"Enter the month\n";
		input>>date.month;
		cout<<"Enter the day of the month the date falls under.\n";
		input>>date.day;
		cout<<"Enter the year.\n";
		input>>date.year;
		return input;
	}	
		
		void dateUnitTest()
		{
			//Tests the cases in which dates will work and cases where dates will fail

			
			// Printing Today's Date
			Date testDate;
			cout<<"Displaying Today's date in Letter form\n";
			cout<<testDate.getDate();
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
			
			cout<<"Testing the overloaded Date input operator\n";
			Date dateOperatorTesting;
			cin>>dateOperatorTesting;
			cout<<"\n";

			cout<<"Testing the overloaded Date output operator\n";
			cout<<dateOperatorTesting;
			
      cout<<"Checking the functionality of the overloaded = operator\n";
      cout<<"Assinging one object's data to another\nThen printing object's content\n";
      cout<<"Should print the previous object's data\n"<<'\n';
      dateOperatorTesting=testDate;
      cout<<dateOperatorTesting;
    

    
    cout<<"Testing Constructor Overloading\n";
    cout<<"Editing the previous item's member variables\n"<<"Then assigning the data into a new object\n"<<"This is done by passing the reference of the edited object into the new object's overloaded constructor\n";
    cin>>testDate;
    Date item3(testDate);
    cout<<item3<<'\n';
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
    virtual bool isParalyzed()
    {
        // Checks if the Creature is Paralyzed
        return boredomLevel>20;
    }

    virtual bool isDead()
    {
        return hungerLevel<0;
    }

  

    friend ostream& operator << (ostream& out,Creature& creature)
    {
        out<<"Name: "<<creature.name<<'\n';
        out<<"Boredom Level: "<<creature.boredomLevel<<'\n';
        out<<"Hunger Level: "<<creature.hungerLevel<<'\n';
        out<<"Is Dead: "<<creature.isDead()<<"\n";
        out<<"Is Paralyzed: "<<creature.isParalyzed()<<"\n";
        return out;
    }

};


// Specification C1 - PassTime()
void Creature ::passTime()
{
    
    this->hungerLevel--;
    this->boredomLevel++;    
}

int Creature :: randomNumberGenerator(int lo,int hi)
{
   // Generates a ranodm number between lo and hi
  int random = (rand()% (hi-lo+1))+lo;
    
  return random;
}

  void Creature :: feedCreature()
  {
    // Feed the Hokeeman and increase hungerLevel by a random number

    int amountToFeed=randomNumberGenerator(3,6);
    this->hungerLevel+=amountToFeed;
    passTime();
  }

  void Creature:: playWithCreature()
  {

    // Play with the Hokeeman and decrease boredomLevel by a random number

    int boredomLevelUpdated= randomNumberGenerator(4,8);
    this->boredomLevel+=boredomLevelUpdated;
    passTime();
  }
  

// Specification B1 - Child Class
class Hokeeman :public Creature
{ 
    public: 

    bool isParalyzed()
    {
        return boredomLevel>20;
    }

    bool isDead()
    {
        return hungerLevel<0;
    }

    
    Hokeeman(Hokeeman& parent1, Hokeeman &parent2)
    {
        this->name= (parent1.name+" "+parent2.name);

        // Use the overloaded + operator to increase hungerLevels
        *this=(parent1+parent2);
    }


    //Specification B3 - Overload Assignment Operator
    Hokeeman& operator =(const Hokeeman& hokeeman)
    {
			this->name=hokeeman.name;
			this->hungerLevel=hokeeman.hungerLevel;
			this->boredomLevel=hokeeman.boredomLevel;
			return *this;
	} 

    // Specification A2 - Copy Constructor
    Hokeeman(Hokeeman& hokeeman)
	{
        
        // Copy Constructor for Hokeeman
        // Absorbs and Spits out the other Hokeeman
        // Takes the other Hokeeman's hunger and boredom levels and uses it to strengthen itself
		this->name=hokeeman.name+" Parasite"; 
		this->hungerLevel+=hokeeman.hungerLevel;
		this->boredomLevel-=hokeeman.boredomLevel;        
	} 

  
  Hokeeman(string name)
  {
    this->name=name;
    this->boredomLevel=randomNumberGenerator(0, 5);
    this->hungerLevel=randomNumberGenerator(0, 5);
  }

  //Specification B4 - Overload + Operator
  Hokeeman operator +(Hokeeman& hokeeman)
  {
    this->hungerLevel+=hokeeman.hungerLevel;
    this->boredomLevel-=hokeeman.boredomLevel;
    return *this;
  }



};


// Specification A3 - Second Child Class
class BattleHokeeman : public Creature
{
  public:
  int health;
  string elementalType;
  int attackDamage;

  BattleHokeeman(string name,string elementalType, int health)
  { 
    this->name=name;
    this->elementalType=elementalType;
    this->health=randomNumberGenerator(5,200);
    this->attackDamage=randomNumberGenerator(1,10);
  }

	void dealDamage(BattleHokeeman& hokeeman)
  	{
    	hokeeman.health-=randomNumberGenerator(0, this->attackDamage);
  	}

};


class HokeemanGame
{
  private:  
  Creature* hokeeman;
  public:

    HokeemanGame()
    {
        playGame();
    }


  // Specification C3 - Validate Input
  bool validateInput(string input)
  {
    if(hokeeman->isDead())
    {
        cout<<hokeeman->name+" is died from starvation\n";
      cout<<"The Game is Over\n";
      return true;
    }
    else if(hokeeman->isParalyzed())
    {
      cout<<hokeeman->name+" is Paralyzed from Boredom\n";
      cout<<"The Game is Over\n";
      return true;
    }
	if(input.length()>0)
	{
    
		string command = input.substr(0,1);
    
		if(input=="L"||input=="l")
		{
			cout<<*hokeeman<<"\n";
		}
		else if(input=="P"||input=="p")
		{
			hokeeman->playWithCreature();
		}
		else if(input=="Q"||input=="q")
		{
			return true;
		}
		else if(input=="F"||input=="f")
		{
			hokeeman->feedCreature();
		}
		else
		{
		cout<<"Not a valid input\n";
		}	
	}
      return false;
  }

  void playGame()
  {
    bool done;
    cout<<"Print the Hokeeman's Name\n";

    // Specification A1 - Critter Name
    string name;
    getline(cin,name);
    
    Creature* hokeemanToCopy= new Hokeeman(name);
	  this->hokeeman=hokeemanToCopy;

    string command;
    
    do
    {
        displayHokeemanTask();
        
        getline(cin,command);
        
        done= validateInput(command);
   
    
    }
    while(!done);
  }

  private:

	void displayHokeemanTask()
	{
		cout<<"Hokeeman Menu\n";
		cout<<"========================\n";
		cout<<"(L)isten to Hokeeman\n";
		cout<<"(F)eed Hokeeman\n";
		cout<<"(P)lay with Hokeeman\n";
		cout<<"========================\n";
	}


public:

 

 
~HokeemanGame()
{
	delete hokeeman;
}
  
 

};

// Function Protypes
void ProgramGreeting();
void UnitTest();

int main() {
    ProgramGreeting();
	HokeemanGame game;
}


// Program Greeting
void ProgramGreeting()
{
   Date currentDate;
	cout<<"Today's Date: "<<currentDate;
    cout<<"============================\n";
    cout<<"Welcome to the Hokeeman\n";
    cout<<"Program Author: Ishan Meher\n";
    cout<<"Program Due Date: November 22, 2020\n";
	  cout<<"============================\n";
}

void UnitTest()
{
  cout<<"Starting Unit Testing\n";
}