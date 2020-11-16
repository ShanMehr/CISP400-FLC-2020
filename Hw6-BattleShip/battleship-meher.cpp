// battleship.cpp
// Ishan Meher, CISP 400
// 11/22/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include<ctime>
#include<fstream> 

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
			
		

	}

};







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


        Vector(Vector& vector)
		{	
            // Assign one Vector to another
			delete this->array;
            this->array=nullptr;
            this->array=vector.array;
		}


		Vector()
		{
			// Creates an Vector object
			// Allocates space on the heap to store array
			this->length=0;
			array=new A[length];

		}

  void removeLast()
  {
    remove(size()-1);
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

    Vector& operator =(const Vector& vector)
		{
			delete this->array;
      this->array=vector.array;
			return *this;
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

struct Position
{
    int xCoord;
    int yCoord;
		bool isHit;
    public:

    Position(int xCoord,int yCoord)
    {
        this->xCoord=xCoord;
        this->yCoord=yCoord;
    }
    Position()
    {
        // Default Constuctor
        this->xCoord=0;
        this->yCoord=0;
    }

		// Specification C4 - Overload «
    friend ostream& operator << (ostream& output, Position& position)
    {
        output<<"X-Coordinate: "<<position.xCoord<<'\n';
        output<<"Y-Coordinate: "<<position.yCoord<<'\n';
        return output;

    }

    void setCoordinates(const int xCoord, const int yCoord) 
    {
        this->xCoord=xCoord;
        this->yCoord=yCoord;
    }

    void PositionsUnitTest()
    {
			auto printPassed = [](bool value) 
    	{ 
      	if(value)
				{
					return "Passed";
				}
				else
				{
					return "Failed";
				}
			
   		}; 
				cout<<"+++++++++++++++++++++++\n";
        cout<<"Positions Unit Test\n";				
				cout<<"The Positions Class Stores The coordinates an Object is located at\n";
				cout<<"Testing the Positions Constructor\n";
				Position coordinate(4,5);
				cout<<printPassed(coordinate.xCoord==4&&coordinate.yCoord==5)<<'\n';
	
				cout<<"Testing the Setter Method\n";
				coordinate.setCoordinates(12,13);
				cout<<printPassed(coordinate.xCoord==12&&coordinate.yCoord==13)<<'\n';
				cout<<"+++++++++++++++++++++++\n";
				
    }
};

// Specification C1 - OOP
class Ship
{
  public:
  string shipType;
  int shipSize;
  Position* positions;
	

  Ship(string shipType,const int shipSize,string shipcode)
  {
    this->shipType=shipType;
    this->shipSize=shipSize;
    positions=new Position[shipSize];
  }

  Ship()
  {
      // Default Constrcutor;
  }

  ~Ship()
  {
      delete[] positions;
  }
  
    friend ostream& operator << (ostream& output, Ship& ship)
    {
        output<<"Ship Type: "<<ship.shipType<<'\n';
        output<<"Ship Size: "<<ship.shipSize<<'\n';
				output<<"Printing Coordinate\n"<<'\n';
        for(int index=0;index<ship.shipSize;index++)
        {   
            // Prints all the positons the ship is located at
            output<<"Position at "<<index<<":"<<'\n';
            output<<(ship.positions[index])<<'\n';
        }
      return output;
    }

		void setCoordinateAtPosition(int index=0,int xCoord=0,int yCoord=0)
		{	
			if(index<shipSize&&index>=0)
			{
				Position position(xCoord,yCoord);
				this->positions[index]=position;

			}
			else
			{
				cout<<"Error:Position Cannot Be Added\n";
			}
			
		}

		void shipUnitTest()
		{

			auto printPassed = [](bool value) 
    	{ 
      	if(value)
				{
					return "Passed";
				}
				else
				{
					return "Failed";
				}
			
   		};
			cout<<"+++++++++++++++++++++++\n";
			cout<<"Ship UnitTest\n";
			cout<<"Testing the Constructor\n";
			Ship ship("Star Destroyer",15,"SD");
			cout<< ship<<'\n';

			ship.setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship.positions[1].xCoord==1&&ship.positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship.setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship.positions[24].xCoord==1&&ship.positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

		}

};
// Specification A3 - Child Classes
class Carrier : public Ship
{
    public:
    Carrier()
    {
        Ship:Ship("Carrier",5,"5");
    }
		~Carrier()
		{
			
		}

		void carrierShipUnitTest()
		{

			auto printPassed = [](bool value) 
    	{ 
      	if(value)
				{
					return "Passed";
				}
				else
				{
					return "Failed";
				}
			
   		};
			cout<<"+++++++++++++++++++++++\n";
			cout<<"Ship UnitTest\n";
			cout<<"Testing the Constructor\n";
			Carrier ship;
			cout<<ship<<'\n';

			ship.setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship.positions[1].xCoord==1&&ship.positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship.setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship.positions[24].xCoord==1&&ship.positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

		}


};

class BattleShip : public Ship
{
    
    public:
    BattleShip()
    {
        Ship:Ship("BattleShip",4,"B4");
    }
		~BattleShip()
		{
			
		}

};

class Cruiser : public Ship
{
    
    public:
    Cruiser()
    {
        Ship:Ship("Cruise",3,"C3");
    }
		~Cruiser()
		{
			
		}

};

class Submarine : public Ship
{	
    public:	
    Submarine()
    {
        Ship:Ship("Submarine",3,"S3");
    }
		~Submarine()
		{
			
		}
};


class Destroyer : public Ship
{
  public:
  	Destroyer()
  	{
      Ship:Ship("Destroyer",3,"D2");
  	}
		~Destroyer()
		{

		}
};


class Grid
{	
	public:
	int gridSize;
	string** grid;
	
	Grid(const int gridSize)
	{
		this->gridSize=gridSize;
		this->grid=make2DArray(gridSize);
	}

	Grid()
	{
		this->gridSize=10;
		this->grid=make2DArray(10);
	} 

	~Grid()
	{
		for(int index=0;index<gridSize;index++)
		{
			delete grid[index];
		} 
		delete grid;
	}

	private:

	string** make2DArray(int gridSize)
	{
		string** array;
		*array= new string[gridSize];
		for(int index=0;index<gridSize;index++)
		{
			array[index]= new string[gridSize];
		}
    return array;
	}

	string getValue(int x,int y)
	{
		return grid[x][y];
	}



};

class BattleShipGameManager
{
  private:
    Vector<Ship*> playerShipList;
    Vector<Ship*> computerShipList;
    Grid playerDisplayGrid;
		Grid playerGameGrid;
		Grid computerDiplaryGrid;
		Grid ComputerGameGrid;
    
	public:
    BattleShipGameManager()
    {
      addShips();
      populateGrids();
      void startGame();

    }

    ~BattleShipGameManager()
    {
      for(int index=0;index<5;index++)
      {
        delete playerShipList.array[index]; 
        delete computerShipList.array[index];
      }
		
    }
    private:

    void addShips()
    {
      cout<<"Adding the player's ships\n";
      // Make all the player's Ships
      Ship* playerCarrier= new Carrier;
      Ship* playerBattleship = new BattleShip;
      Ship* playerCruiser = new Cruiser;
      Ship* playerSubmarine = new Submarine;
      Ship* playerDestroyer = new Destroyer;

      // Add all the Player's Ships to the playerlist
      playerShipList.add(playerCarrier);
      playerShipList.add(playerBattleship);
      playerShipList.add(playerCruiser);


      // Make all the computerShips
      Ship* computerCarrier= new Carrier;
      Ship* computerBattleship = new BattleShip;
      Ship* computerCruiser = new Cruiser;
      Ship* computerSubmarine = new Submarine;
      Ship* computerDestroyer = new Destroyer;

      // Add all the computer's ships to the computerList
      computerShipList.add(computerCarrier); 
      computerShipList.add(computerBattleship);
      computerShipList.add(computerDestroyer);
      computerShipList.add(computerSubmarine);
      computerShipList.add(computerDestroyer);

    }

    void populateGrids()
    {

    }

  

};


// Function Protypes
 void UnitTest();
 void ProgramGreeting();


int main() {

  
  cout << "Hello World!\n";
	UnitTest();
	ProgramGreeting();
	//BattleShipGameManager battleship;
} 

void UnitTest()
{
	Position positionUnitTest;
	//positionUnitTest.PositionsUnitTest();

	Ship shipUnitTest;
	//shipUnitTest.shipUnitTest();

	Carrier carrierShipUnitTest;
	
	carrierShipUnitTest.carrierShipUnitTest();
	

}

void ProgramGreeting()
{	
	 Date currentDate;
	cout<<"Today's Date: "<<currentDate;
    cout<<"============================\n";
    cout<<"Welcome to the Game Battle Ship\n";
    cout<<"Program Author: Ishan Meher\n";
		cout<<"Project for my CISP 400 Class\n";
    cout<<"Program Due Date: November 22, 2020\n";
	  cout<<"============================\n";
}