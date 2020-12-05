// battleship.cpp
// Ishan Meher, CISP 400
// 11/22/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include<ctime>
#include<fstream> 
#include<algorithm>


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
    string orientation;
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
        output<<"Orientation: "<<position.orientation<<'\n';
        return output;

    }


    //Specification B4 - Overload »
    friend istream& operator >> (istream& input, Position& position)
    {
      bool done;
        cout<<"Enter X-Coordinate:(A-J)\n";
        do
        {
          input>>position.xCoord;
          if(!cin.fail())
          {
             cout<<"Enter Y-Coordinate:(0-9)\n";
             input>>position.yCoord;
              if(cin.fail())
              {
                cin.clear();
					      cin.ignore(numeric_limits<streamsize>::max(), '\n');
              }
              else
              {
                done=true;
              }
              

          }
          else
          {
            cin.clear();
					  cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }

        }
        while(!done);

        return input;

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
  string shipCode;
  bool isDown;
  int health;
	

  Ship(string shipType,const int shipSize,string code)
  {
    this->shipType=shipType;
    this->shipSize=shipSize;
    this->health=shipSize;
    positions=new Position[shipSize];
    this->shipCode=code;
  }

  Ship()
  {
      // Default Constrcutor;
  }

  ~Ship()
  {
      positions=nullptr;
      delete[] positions;
  }
  
    friend ostream& operator << (ostream& output, Ship& ship)
    {
        output<<"Ship Type: "<<ship.shipType<<'\n';
        output<<"Ship Size: "<<ship.shipSize<<'\n';
        output<<"Ship Code: "<<ship.shipCode<<'\n';
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
        this->shipType="Carrier";
        this->shipSize=5;
        this->shipCode="C5";
        this->positions=new Position[5];      
        this->health=shipSize;
    }
		~Carrier()
		{
      positions=nullptr;
      delete[] positions;;
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
			cout<<"Carrier Unit Test\n";
			cout<<"Testing the Constructor\n";
      cout<<"Using a Class stored on the heap\n";
			Ship* ship=new Carrier();
			cout<<*ship<<'\n';

			ship->setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship->positions[1].xCoord==1&&ship->positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship->setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship->positions[24].xCoord==1&&ship->positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

      delete ship;

		}


};

class BattleShip : public Ship
{
    
    public:
    BattleShip()
    {
        this->shipType="BattleShip";
        this->shipSize=4;
        this->shipCode="B4";
        this->positions=new Position[4];
        this->health=shipSize;
    }

    void battleShipUnitTest()
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
			cout<<"BattleShip Unit Test\n";
			cout<<"Testing the Constructor\n";
      cout<<"Using a Ship stored on the heap with a pointer to a BattleShip Object\n";
			Ship* ship=new BattleShip();
			cout<<*ship<<'\n';

			ship->setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship->positions[1].xCoord==1&&ship->positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship->setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship->positions[24].xCoord==1&&ship->positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

      delete ship;

		}

		~BattleShip()
		{
			positions=nullptr;
      delete[] positions;
		}

};

class Cruiser : public Ship
{
    
    public:
    Cruiser()
    {
       
        this->shipType="Cruiser";
        this->shipSize=3;
        this->shipCode="C3";
        this->positions=new Position[3];
        this->health=shipSize;
    }

    void cruiserShipUnitTest()
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
			cout<<"Cruiser Unit Test\n";
			cout<<"Testing the Constructor\n";
      cout<<"Using a Ship stored on the heap with a pointer to a Cruiser Object\n";
			Ship* ship=new Cruiser();
			cout<<*ship<<'\n';

			ship->setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship->positions[1].xCoord==1&&ship->positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship->setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship->positions[24].xCoord==1&&ship->positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

      delete ship;

		}

		~Cruiser()
		{
      positions=nullptr;
      delete[] positions;
		}

};

class Submarine : public Ship
{	
    public:	
    Submarine()
    {
        this->shipType="Submarine";
        this->shipSize=3;
        this->shipCode="S3";
        this->positions=new Position[3];
        this->health=shipSize;
    }

    void submarineUnitTest()
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
			cout<<"Submarine Unit Test\n";
			cout<<"Testing the Constructor\n";
      cout<<"Using a Ship stored on the heap with a pointer to a Submarine Object\n";
			Ship* ship=new Submarine();
			cout<<*ship<<'\n';

			ship->setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship->positions[1].xCoord==1&&ship->positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship->setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship->positions[24].xCoord==1&&ship->positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

      delete ship;

		}


		~Submarine()
		{
			positions=nullptr;
      delete[] positions;
		}
};


class Destroyer : public Ship
{
  public:
  	Destroyer()
  	{
      ;
      this->shipType="Destroyer";
        this->shipSize=2;
        this->shipCode="C2";
        this->positions=new Position[5];
        this->health=shipSize;
  	}

    void destroyerUnitTest()
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
			cout<<"Destroyer Unit Test\n";
			cout<<"Testing the Constructor\n";
      cout<<"Using a Ship stored on the heap with a pointer to a Destroyer Object\n";
			Ship* ship=new Destroyer();
			cout<<*ship<<'\n';

			ship->setCoordinateAtPosition(1,1,2);
			cout<<"Testing the Position array's changing of coordinates\n";
			cout<<"Position 1 is changed (Must Pass): "<<printPassed(ship->positions[1].xCoord==1&&ship->positions[1].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";


			ship->setCoordinateAtPosition(24,1,2);
			cout<<"Testing to see if it fails when a bad positions is entered\n";
			cout<<"Position 24 is changed (Must Fail): "<<printPassed(ship->positions[24].xCoord==1&&ship->positions[24].yCoord==2)<<'\n';
			cout<<"+++++++++++++++++++++++\n";

      delete ship;

		}
		~Destroyer()
		{
      positions=nullptr;
      delete[] positions;

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
    loadGrid();
	}

	Grid()
	{
		this->gridSize=10;
		this->grid=make2DArray(10);
    loadGrid();
    
	} 

	~Grid()
	{
    /*
		for(int index=0;index<gridSize;index++)
		{
      // Delete all the columns of the array
      grid[index]=nullptr;
      delete grid[index]; 		
      
		}
    */
    // Delete array
    grid=nullptr;
    delete[] grid;

  
		
	}

  friend ostream& operator <<(ostream& output, Grid& grid)
  {
   

    output<<"  A ";
    output<<"  B  ";
    output<<" B  ";
    output<<" D  ";
    output<<" E  ";
    output<<" F  ";
    output<<" G  ";
    output<<" H  ";
    output<<" I  ";
    output<<" J ";
    cout<<'\n';
    for(int i=0;i<grid.gridSize;i++)
    {
      output<<i;
      for(int j=0;j<grid.gridSize;j++)
      {
        output<<grid.grid[i][j];
      }
      output<<'\n';
    }
    
    return output;
  }

  void gridUnitTest()
  { 
    cout<<"Grid Unit Test\n";
    Grid grid(2);
    cout<<"Testing the loading of the parameterized Constructor\n";
    cout<<"Printing the Empty grid (The result of the constructor)\n"<<'\n';
    cout<<"Printing a 2x2 grid\n";
    cout<<grid;
   

    cout<<"Testing the Default constructor"<<'\n';
    Grid defaultGrid;
    cout<<"Also testing the addition of an string to the grid\n";
    for(int i=0;i<defaultGrid.gridSize;i++)
    {
      for(int j=0;j<defaultGrid.gridSize;j++)
      {
        string row= to_string(i);
        string col= to_string(j+1);
        
        defaultGrid.addToPosition(i,j,row+col);
      }
    }
    cout<<defaultGrid<<'\n';

  }

   
  void printGrid()
  {
    
    for(int i=0;i<gridSize;i++)
    {
      for(int j=0;j<gridSize;j++)
      {
        cout<<grid[i][j];
      }
      cout<<'\n';
    }
  }

  void addToPosition(int row,int column,string text)
  {
    if(row<gridSize&&column<gridSize)
    {
      string textValue= "["+text+"]";
      grid[row][column]=textValue;
    }
  }

	public:

	string** make2DArray(const int gridSize)
	{
		string** array;
    
		array= new string*[gridSize];
  
		for(int index=0;index<this->gridSize;index++)
		{
			array[index]= new string[gridSize];
      
		}
    return array;
	}

	string getValue(int x,int y)
	{
		return grid[x][y];
	}

  void loadGrid()
  {
    for(int i=0;i< this->gridSize;i++)
    {
      for(int j=0;j<this->gridSize;j++)
      {    
        grid[i][j]="[  ]";
     
      }
      
    }
  }

};

class Player
{
  public: 

    Vector<Ship*>* playerShipList = new Vector<Ship*>();
    Grid* playerDisplayGrid= new Grid;
  	Grid* playerGameGrid= new Grid;
    Vector<Position*>* pastShots = new Vector<Position*>();
    int numberOfShips;

  Player()
  {
    addShips();
    //addPositionsToPlayer();
    populateGrid();
    
  }

  ~Player()
  {
    delete playerShipList;
    delete playerGameGrid;
    delete playerDisplayGrid;
    delete pastShots;
  }

   void playerUnitTest()
    {
        Player player;

        cout<<"Player Unit Test\n";
        cout<<"Printing all the player's ships\n";
        cout<<"Testing to see if the playerShipList vector contains all the ships that have been added to\n";
        
        cout<<*player.playerGameGrid<<'\n';
    }

    private:

     void addShips()
    {
      
      // Make all the player's Ships
      Ship* playerCarrier= new Carrier;
      Ship* playerBattleship = new BattleShip;
      Ship* playerCruiser = new Cruiser;
      Ship* playerSubmarine = new Submarine;
      Ship* playerDestroyer = new Destroyer;

      // Add all the Player's Ships to the playerlist
      playerShipList->add(playerCarrier);
      playerShipList->add(playerBattleship);
      playerShipList->add(playerCruiser);
      playerShipList->add(playerSubmarine);
      playerShipList->add(playerDestroyer);


      delete playerCarrier;
      delete playerBattleship;
      delete playerCruiser;
      delete playerSubmarine;
      delete playerDestroyer;

    }

    int randomNumberGenerator(int lo,int hi)
    {
      
      // Generates a ranodm number between lo and hi
      srand(time(0));
      int random = (rand()% (hi-lo+1))+lo;
        
      return random;
     
    }


    // Specification B3 - Random Start
    Position* addShipToGrid(int size)
    {
      
      /*      
        Find a random position in the grid
        Select a random orientation horizonal or veritcal
        directions from the cardinal direction array of Position struct
        Check if the next position in that direction is within the bounds
        Check if the next position has a boat
        If out of bounds or boat start all over again
      */
      int xCoord= randomNumberGenerator(0,9);
      int yCoord= randomNumberGenerator(0,9);

      Position* array = new Position[size];
      
      // Stores the number of orientations that have been tried and failed
  
      int i=0;

      /**
        Stores a Random orientation
        1 is North
        2 is Hoo
        
      */
      int shipOrientation=randomNumberGenerator(1,2);

      while(i<size)
      {
        if(positionIsInBounds(xCoord,yCoord)&&positionIsEmpty(xCoord,yCoord))
        {
			
          if(shipOrientation==1)
          {
            // If Orientation is North
            // If there is a match at the position store the position in the array
            // The next position is 1 up so increase yCoord
            array[i].xCoord=xCoord;
            array[i].yCoord=yCoord;
            yCoord++;
			      i++;
          }
          else if(shipOrientation==2)
          {
            // If Orientation is South
            // If there is a match at the position store the position in the array
            // The next position is 1 down so decrease yCoord
            array[i].xCoord=xCoord;
            array[i].yCoord=yCoord;
            xCoord++;
              i++;
              
          }

        }
        else
        {
          // If a position is not found find another coordinate
          xCoord= randomNumberGenerator(0,size);
          yCoord= randomNumberGenerator(0,size);
          shipOrientation=randomNumberGenerator(1,2);
          i=0;
        }

      }
      
      return array;

    }

    void populateGrid()
    {
      

      for(int i=0;i<playerShipList->size();i++)
      {
       
        int index=0;
        int size=playerShipList->get(i)->shipSize;
        
        playerShipList->get(i)->positions=addShipToGrid(size);

        string shipCode=playerShipList->get(i)->shipCode;
        
        int shipSize=playerShipList->get(i)->shipSize;
        
        while(index<shipSize)
        {
         
          int row=playerShipList->get(i)->positions[index].xCoord;
          int column=playerShipList->get(i)->positions[index].yCoord;
          string text="["+shipCode+"]";
          playerGameGrid->grid[row][column]=text;         
          index++;
          
        }
      }
    }

    void addPositionsToPlayer()
    {
      for(int i=0;i<playerShipList->size();i++)
      {
        int size= playerShipList->get(i)->shipSize;
        playerShipList->get(i)->positions=addShipToGrid(size);
      }
    }

    

    bool positionIsInBounds(int xCoord,int yCoord)
    {
      /*
        Returns true if within the bounds of the grid
        Position Can't be more than the size of the grid
        Position can't be less than the size of the grid
      */       
      return (xCoord<10&&yCoord<10&&xCoord>=0&&yCoord>=0);
    
    }

    bool positionIsEmpty(int xCoord,int yCoord)
    {
      // return true the grid is empty
      return (playerGameGrid->grid[xCoord][yCoord]=="[  ]");
    }


};

class BattleShipGameManager
{
    protected:
    Player* human = new Player;
    Player* computer = new Player;
    Player* humanReplay;
    Player* computerReplay;
    
    int gameType;
   

	public:
    BattleShipGameManager()
    {
      this->humanReplay=human;
      this->computerReplay=computer;
      this->gameType=0;
      cout<<"Loading Game\n";
      startGame();
      


    }

    BattleShipGameManager(int gameType)
    {
      this->humanReplay=human;
      this->computerReplay=computer;
      this->gameType=1;
      startGame();


    }
    void startGame()
    {
      bool gameEnded;
      do
      {
        
      system("clear");

        // Player playerTurn
        
        cout<<"Your Ship Grid\n";
        cout<<*this->human->playerGameGrid;
        cout<<"Your Game Grid\n";
        cout<<*this->human->playerDisplayGrid;

  
        string command;
        
        
        cout<<"Press Enter to Proceed\n";
        getline(cin,command);
        system("clear");
        
        // Specification B1 - Secret Option
        if(command=="nuclearlaunchcodes")
        {
          cout<<"It's ok to cheat if you don't get caught\n";
          cout<<*this->computer->playerGameGrid;
        }
        else if(command=="abandonship")
        {
          // Specification A1 - Resign Game
          gameEnded=true;
          cout<<"Quitting Game\n";
          break;
        }
         cout<<"Your Ship Grid\n";
        cout<<*this->human->playerGameGrid;
        cout<<"Your Game Grid\n";
        cout<<*this->human->playerDisplayGrid;
        playerTurn(*human);
        computerTurn(*computer);
        gameEnded= gameIsOver();


      }
      while(!gameEnded);
    }

    void playerTurn(Player& player)
    {
      bool turnRecorded=false;

      int numberOfTurns;
      if(this->gameType==1)
      {
        numberOfTurns= player.numberOfShips;
      }
      else
      {
        numberOfTurns=1;
      }

      for(int i=0;i<numberOfTurns;i++)
      {
      do
      {

        char column;
        int row=0;

        // Player playerTurn
        cout<<"Enter a column(A-J)\n";
        
        cin>>column;
        if(!cin.fail())
        {

          cout<<"Enter a row(1-10)\n";
          cin>>row;
          

          if(!cin.fail())
          {
         
            int xCoord=((int)tolower(column))-97;            
            // Specification C3 - Validate Input3
            if(xCoord<10&&xCoord>=0&&row>=0&&row<10)
            {
              turnRecorded =recordMove(*this->human,*this->computer,row,xCoord);
              
            }
      
          }
          else
          {
            cout<<"Invalid Input\n";
            cin.clear();
					  cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
  
          
        }
        else
        {
           cout<<"Invalid Input\n";
          cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
      while(!turnRecorded);
      }
      
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
    }

    void computerTurn(Player& player)
    {
      system("clear");
      
      bool turnRecorded;
      
      int numberOfTurns;
      if(this->gameType==1)
      {
        numberOfTurns= player.numberOfShips;
      }
      else
      {
        numberOfTurns=1;
      }
      for(int i=0;i<numberOfTurns;i++)
      {
      do
      {

        // Player playerTurn  
        int col= randomNumberGenerator(0, 9);
        int row=randomNumberGenerator(0, 9);

        if(!cin.fail())
        {
          if(!cin.fail())
          {
            
            turnRecorded =recordMove(*this->computer,*this->human,col,row);
      
          }
          
          
        }

      }
      while(!turnRecorded);
      }
      
    }

    int randomNumberGenerator(int lo,int hi)
    {
      
      // Generates a ranodm number between lo and hi
      srand(time(0));
      int random = (rand()% (hi-lo+1))+lo;
        
      return random;
     
    }

    bool gameIsOver()
    {
      if(playerLost(*this->human))
      {
        cout<<"The Player Lost\n";
        return true;
      }
      else if(playerLost(*this->computer))
      {
        cout<<"The Computer Lost\n";
        return true;
      }
      return false;
  
    }

    

    bool recordMove(Player& currentPlayer,Player& opposingPlayer,int xCoord,int yCoord)
    {
    
        // Returns true if the move is recorded
      
      if(!checkIfShotPrevioslyFired(xCoord,yCoord))
      {
       
        Position* shot = new Position(xCoord,yCoord);
        this->human->pastShots->add(shot);
         // Mark the player's game grid as an already chosen shot
        currentPlayer.playerDisplayGrid->addToPosition(shot->xCoord,shot->yCoord,"/*");

        // Mark the oppposing player's display grid as a position shot at 
        opposingPlayer.playerGameGrid->addToPosition(shot->xCoord,shot->yCoord,"/&");
        positionIsHit(currentPlayer,opposingPlayer,shot);
        return true;
      }
      else
      {
       
        return false;
      }
      
      
    }

    // Specification B2 - Adv Input Validation
    // Specification C2 - Prohibit AI wasted shots
    bool checkIfShotPrevioslyFired(int row, int col)
    {
      for(int i=0;i<this->human->pastShots->size();i++)
      {
        if(row==this->human->pastShots->get(i)->xCoord&&col==this->human->pastShots->get(i)->yCoord)
        {
         return true; 
        }
      }
      return false;
    }

    void positionIsHit(Player& currentPlayer, Player& opposingPlayer,Position* shot)
    {
    
      for(int i=0;i<opposingPlayer.playerShipList->size();i++)
      {
        // Check thorugh all the player's ships and see if that ship has the position
        for(int j=0;j<opposingPlayer.playerShipList->get(i)->shipSize;j++)
        {

          if(shot->xCoord==opposingPlayer.playerShipList->get(i)->positions->xCoord&&shot->xCoord==opposingPlayer.playerShipList->get(i)->positions->yCoord)
          {
          
            // Lower the health of the opposiong player's ship
            opposingPlayer.playerShipList->get(i)->health--;
            opposingPlayer.playerGameGrid->addToPosition(shot->xCoord,shot->yCoord,"**");
            currentPlayer.playerDisplayGrid->addToPosition(shot->xCoord,shot->yCoord,"**");
           
             
            break;
          }
        }
      }
      
    }

    void BattleShipGameManagerUnitTest()
    {
      BattleShipGameManager game;

    }
    


    ~BattleShipGameManager()
    {
      delete human;
      delete computer;
    }

    bool playerLost(Player& player)
    {
      int numberOfShips=5;
      int shipsLost;
      for(int i=0;i<numberOfShips;i++)
      {
        if(player.playerShipList->get(i)->health==0)
        {
          // Check if all ships are hit
          
          // Decrease the number of turns the player has if they lost a ship
          shipsLost++;

        }
        else
        {
          // If a ship is not down then the game is not over
          return false;
        }
        // Record the number of ships that the player has
        if(gameType==1)
        {
          player.numberOfShips=(numberOfShips-shipsLost);
        }
      }
      return true;
    }

    // Specification A4 - Replay Finished Game
    void displayReplay()
    {
      
     int gameTurns= max(this->human->pastShots->size(),this->computer->pastShots->size());
      for(int i=0;i<gameTurns;i++)
      {
        if(gameTurns<this->human->pastShots->size())
        {
          this->humanReplay->playerDisplayGrid->addToPosition(this->human->pastShots->get(i)->xCoord,this->human->pastShots->get(i)->yCoord,"*/");
          this->computerReplay->playerGameGrid->addToPosition(this->human->pastShots->get(i)->xCoord,this->human->pastShots->get(i)->yCoord,"*/");
          cout<<*this->computerReplay->playerGameGrid;
        }
         if(gameTurns<this->computer->pastShots->size())
        {
          this->computerReplay->playerDisplayGrid->addToPosition(this->human->pastShots->get(i)->xCoord,this->human->pastShots->get(i)->yCoord,"*/");
          this->humanReplay->playerGameGrid->addToPosition(this->human->pastShots->get(i)->xCoord,this->human->pastShots->get(i)->yCoord,"*/");
          cout<<*this->humanReplay->playerGameGrid;
        }
      }


    }
};




// Function Protypes
 void UnitTest();
 void ProgramGreeting();


int main() {

	//UnitTest();
	ProgramGreeting();
  //g++ -std=c++14 -g -Wall main.cpp REMOVE BEOFRE SUBMITTING
	cout<<"Select a Game Type\n";
  int gameType;
  cout<<"Select 0 for normal Battle Ship\n";
  cout<<"Select 1 for Rapid Fire Battle Ship\n";
  cin>>gameType;
  BattleShipGameManager* battleship;
  if(!cin.fail())
  {
    if(gameType==0)
    {
      battleship= new BattleShipGameManager();
    }
    else
    {
      battleship= new BattleShipGameManager(1);
    }
  }
  else
  {
    cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cout<<"Replay Game\n";
  cout<<"Select 1 to replay\n";
  cout<<"Select 2 to quit\n";
  cin>>gameType;
  if(!cin.fail())
  {
    if(gameType==1)
    {
      battleship->displayReplay();
    }
  }
  else
  {
    cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }


} 

void UnitTest()
{
  cout<<"Starting Unit Tests\n";


  
  Date dateUnitTest;
  dateUnitTest.dateUnitTest();

  Vector<int> vectorUnitTest;
  vectorUnitTest.VectorUnitTest();

	Position positionUnitTest;
	positionUnitTest.PositionsUnitTest();

	Ship shipUnitTest;
	shipUnitTest.shipUnitTest();

	Carrier carrierShipUnitTest;

  carrierShipUnitTest.carrierShipUnitTest();
	
  BattleShip battleShipUnitTest;
  battleShipUnitTest.battleShipUnitTest();

  Cruiser cruiserUnitTest;
  cruiserUnitTest.cruiserShipUnitTest();

  Submarine submarineUnitTest;
  submarineUnitTest.submarineUnitTest();

  Destroyer destroyerUnitTest;
  destroyerUnitTest.destroyerUnitTest();

  Grid gridUnitTest;
  gridUnitTest.gridUnitTest();

  
  Player playerUnitTest;
  playerUnitTest.playerUnitTest();

  BattleShipGameManager gameUnitTest;
  gameUnitTest.BattleShipGameManagerUnitTest();
}

void ProgramGreeting()
{	
	 Date currentDate;
	
    cout<<"==========================================\n";
    cout<<"Welcome to the Game Battle Ship\n";
    cout<<"Today's Date: "<<currentDate;
    cout<<"Program Author: Ishan Meher\n";
		cout<<"Project for my CISP 400 Class\n";
    cout<<"Program Due Date: November 22, 2020\n";
	  cout<<"==========================================\n";
}