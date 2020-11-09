// todolist.cpp
// Ishan Meher, CISP 400
// 11/8/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include<ctime>
#include<fstream> 
#include<regex>

using namespace std;

// Specification C4 - TODO array
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


struct TODO
{
    string task; 
  	int int_TODOId;
	Date dateAdded;
    
    

    TODO(string task,int int_TODOId,Date dateAdded)
    {
        // Creates a TODO object
        this->task=task;
        this->int_TODOId=int_TODOId;
        this->dateAdded=dateAdded;
        
	}	


	// Specification A1 - Overload Copy Constructor
    TODO(const TODO& todo)
    {
      // Copy Constructor
      this->task=todo.task;
      this->int_TODOId=todo.int_TODOId;
      this->dateAdded=todo.dateAdded;
    }
  	// Specification A2 - Overload Assignment Operator
	TODO& operator= (const TODO& todo)
	{
    	// Overloads the = operator
		this->task=todo.task;
		this->int_TODOId=todo.int_TODOId;
		this->dateAdded=todo.dateAdded;
		return *this;
	}

  	// Specification A4 - Overload Constructor
	TODO()
	{
    // Default Constructor that holds default data
		this->task="Task";
		Date dateAdded;
		this->dateAdded=dateAdded;
		this->int_TODOId=0000000;
	}

    // Specification C1 - Overload «
    friend ostream& operator << (ostream &output,TODO& item)
	{
        // Overloads the print operator and prints the instance variables of TODO 
		output<<"Task: "<<item.task<<'\n';
        output<<"Date Added: "<<item.dateAdded.getDate()<<'\n';
		output<<"ID: "<<item.int_TODOId<<'\n';
        return output;

	}

	// Specification C2 - Overload »
	friend istream& operator >> (istream &input, TODO& item)
	{
    	// Overloads the >> operator 
    	// Inputs the instance members of TODO struct

    	// Runs the default constructor which get the current date
		Date dateAdded;
		item.dateAdded=dateAdded; 

		// Prompts the user for input
		// Stores the input in the instance variables
		cout<<"Enter an ID for the task: ";
		input>>item.int_TODOId;			
    
    cout<<"Enter the task:"<<'\n'; 	
		getline(input,item.task);	
			 
		return input;
	}

	void UnitTest()
	{			
    	// Unit Test for my TODO object
		cout<<"TODO class Unit Test\n";

		// Testing the TODO constructor
		cout<<"Testing the TODO Constructor and print << operator\n";
		Date date;
		TODO todo("Do my CISP 400 homework",1234567,date);
		cout<<"\nExpected: "<<'\n';
		cout<<"Task: Do my CISP homework\n";
		cout<<"Date Added: (The Current Date)\n";
		cout<<"ID: 1234567\n";
		cout<<"Result:\n";
    	cout<<todo<<'\n';
    	cout<<"------------------------\n";
    

		// Testing << and >> operators
		cout<<"Testing the inputstream operator >>\n";
		TODO item;
		cin>>item;
		cout<<"\nResult:\n";
		cout<<item;    
   	 	cout<<"------------------------\n";
   		cout<<'\n';
    

		// Testing the overloaded = operator
		cout<<"Checking the functionality of the overloaded = operator\n";
		cout<<"Assinging one object's data to another\nThen printing object's content\n";
		cout<<"Should print the previous object's data\n"<<'\n';
		todo=item;
		cout<<todo;
    

		// Testing the overloaded copy constructor
		cout<<"Testing Constructor Overloading\n";
		cout<<"Editing the previous item's member variables\n"<<"Then assigning the data into a new object\n"<<"This is done by passing the reference of the edited object into the new object's overloaded constructor\n";
		cin>>item;
		TODO item3(item);
		cout<<item3<<'\n';
		cout<<"------------------------\n";    	

	}
  

};


class ListManager
{
	private:

	  	// Specification C4 - TODO array
    	Vector<TODO> list; // Array of TODO's stored on the heap
      	bool hasBlankEntries;

	public:

    	bool handleUserInput(const string input="  ");

      // Specification B4 - Persistence
      ListManager()
      {
          // Checks if there is a file with ListManger data 
          // If there is a file then that data is saved to the array
          loadListContents();
      }
    	
		// Specification C3 - Test TODO’s
		void UnitTest()
		{	
      		// Unit Test for my list Manager Class
			ListManager todoList;

			cout<<"List Manager Unit Test\n";

			// Adding an item to the TODO list 
			// A TODO is created this way to test the removal of an item from the TODO list
			cout<<"Testing the addition of a Todo\n";	
			Date dateAdded;
			TODO todo("Remind Myself to go Running",1234567,dateAdded);
			todoList.add(todo);
			todoList.handleUserInput("?Print the list");
			cout<<'\n';

			// Checking if an item can be added to the list;
			cout<<"Testing the addTodo() method\n";
			cout<<"Note: can't enter ID: 1234567, already chosen\n";
			todoList.addTODO("Do my Homework");
			cout<<"Printing the newly added task\n";
			todoList.printTODOList();
			cout<<'\n';


			// Checking if the + add command and the ? print items command works
			cout<<"Adding an item using the handleUserInput() method\n";
			cout<<"Also printing the list and the newly entered item\n";
			todoList.handleUserInput("+Mow the Lawn"); 
			cout<<"Printing the whole list\n";
			cout<<"Testing the ? command that prints the list\n";
			todoList.handleUserInput("?Print the list");
			cout<<'\n';	
			

			// Entering several items into the list
			cout<<"adding a few more TODOs to the list\n";
			todoList.handleUserInput("+Attend Online Class\n");
			todoList.handleUserInput("+Walk the Dog");
			todoList.handleUserInput("+Check the Electricity Bill");
			cout<<'\n';

			// Testing the removal of an item 
			cout<<"Testing the removal of a TODO\n";
			cout<<"Removing the first TODO entered\n";
			todoList.handleUserInput("-1234567");
			cout<<"Should print the list with the first entry removed\n";
			cout<<"Note: task Remind myself to go Running should be gone\n";			
			todoList.handleUserInput("?Print the list");
		}

		

    ~ListManager()
    {
      // Writes all the data of the array to the file
      saveListContents();
    }

	private:

    void add(TODO& todo)
		{
			// adds a TODO reference to the list
			list.add(todo);
			
		}

		void addTODO(const string input)
		{
				// Takes in a string input
				// Performs a command based on the first character of the string parameter

				// Prompts for an ID
				int id= getID();
        
        		// The default contructor sets the date object to have the current date
				Date dateAdded;

        		// Makes a new TODO item object and adds it to the array
				TODO todo(input,id,dateAdded);
        if(hasBlankEntries)
        {
          // Checks to see if there are blank entries
          // Replaces the blank entries with a new TODO
          replaceDefaultObject(todo);
        }
        else
        {
          list.add(todo);
        }				
						
		}

			

		void printTODOList()
		{
      		// Prints the contents of the array
			for(int index=0;index<list.size();index++)
			{
				cout<<"-----------------------------\n";
				cout<<"Task #"<<index+1<<'\n';
				list.printItem(index);	
			}
			cout<<"-----------------------------\n";
		}

		int idIsInList(const int id)
		{
      		// Checks if the ID is in th elist
			int result=-1;
			
				// Loops through the list and checks if the ID entered matches a previously chosen id
				for(int index=0;index<list.size();index++)
				{
					int idAtIndex=list.get(index).int_TODOId;
							
					if(id==(idAtIndex))
					{
						result=index;					
						
					}

				}			
			
			return result;
		}

    void saveListContents()
    {
        // Saves the contents of the array to a text file
        ofstream outputFile;
        
        // opens the file
        outputFile.open("todolist-ishanmeher.txt");
        cout<<"Writing the data of the list to the file\n";     
        
        // Saves the length of the list to the file
        // Used to determine how many objects are read when the program runs again
        outputFile<<list.size()<<'\n';

        // Loops through the array and adds the contents of each object
        for(int index=0; index<list.size();index++)
        {
         
          TODO task=list.get(index);
          outputFile<<task.task<<'\n';
          outputFile<<task.dateAdded.getMonth()<<'\n';
          outputFile<<task.dateAdded.getDay()<<'\n';
          outputFile<<task.dateAdded.getYear()<<'\n';
          outputFile<<task.int_TODOId<<'\n';
          
          
        }
        
        outputFile.close();
        
    }


     int stringToInt(string task)
    {
      // Used when reading from the text file
      // Checks if the values inside the string is a number
      //  Only casts to int if the string can be casted to int
      int valueToReturn;

      regex reg("^[0-9]+$");
      // A regular exression(regex) string pattern that the string parameter has to match
      // The string must have numbers zero to 9 in it and must have at least 1 number inside it;

        // If the string matches the regular expression pattern only then is the string made into an int
       if(regex_match(task, reg)) 
       {
         valueToReturn=stoi(task);         
       }
       return valueToReturn;
    }   


    void loadListContents()
    {
        // Reads the contents of the text file
        // Saves the contents of the text file into the array
		
        fstream readFile;


        readFile.open("todolist-ishanmeher.txt");

        // Reads if the file was found
        if(readFile)
        {
          int listSize=0;

          // Reads the first line which stores the length of the array
          // The input is read in chunks, of every five lines having the instance variables to make a TODO object
          // After the fifth line starts a new TODO object

          readFile>>listSize;   
          
        Vector<string>list;

        // Stores a line of the file 
        string value;     

        // The increment is meant to keep track of what member variable of TODO is going to be saved
        
        int increment=0;

            string task; // Read First in file
            int month; // Read second in file
            int day; // Read third in file
            int year; // Read fourth in file
            int id; // Read fifth in file

            

        int index;
        while(!readFile.eof())
        {
          getline(readFile,value);
          if(value!="")
          {
            list.add(value);
           
            if(increment==4)
            {
              // If the last line of the TODO struct then save the id
              // If it is at the 5th line then the instance varibales can be saved to the todo and added to the list

              id= stringToInt(list.get(index));

              // Resetting to start saving to a new object
              increment=0;
              Date date(month,day,year);
              TODO todo(task,id,date);
              add(todo);
              
            }          
            else if(increment==3)
            {
              // The 4th line of the has the day
              // stores the day to be added when the fourth line is reached
              year= stringToInt(list.get(index));
              increment++;
            }
            else if(increment==2)
            {
              // The 3rd line of the has the day
              // stores the day to be added when the fourth line is reached
              day= stringToInt(list.get(index));
              increment++;
            }
            else if(increment==1)
            {
              // The 2nd line of the has the day
              // stores the month to be added when the fourth line is reached
              month= stringToInt(list.get(index));
              increment++;
            }
            else if(increment==0)
            {
              // The first line of the has the day
              // stores the day to be added when the fourth line is reached
              task=list.get(index);
              increment++;
            }
            index++;
                   
          }

        }

          readFile.close();
		  cout<<"Past data loaded to TODO list\n";
        }
        else 
        {
          cout<<"No tasks have been saved\n";
        }

    }


    void replaceDefaultObject(TODO todo)
    {
      // Changes a blank entry
      // Checks if there are still blank TODO objects
      bool blankNotFound=false;
      int blankCount;
      for(int index=0;index<list.size();index++)
      {
        // Loops through the array ot find blank TODO entries
        if(list.get(index).int_TODOId==0)
        {
          // If a TODO entry has been found then increment the variable that stores the count of blank entries
          blankCount++;
          if(blankNotFound==true)
          {
            // If a blank Entry has been previously found then don't update then don't change the other blank entries
            // We don't want to repeat tasks
            hasBlankEntries=true;
            
          }
          else
          {
            // Changes the first found blank entry            
            TODO todoToAdd(todo);
            list.set(index,todoToAdd);
            blankNotFound=true;
            blankCount--;
            hasBlankEntries=false;
          }
          
        }
      }
    }
   

		int getID()
		{
			// Prompts the User for an idNumber and checks if the item chosen is correct
			// If the data entered is invalid repropmts the user for an entry
			bool done=false;
			int id;

			do
			{
				cout<<"List Manager Editor\n";
				int chosenID;
				cout<<"Enter the id(A number with 7 digits)\n";
				cin>>chosenID;

				// Checks if the id entered is the correct datatype
				if(!cin.fail())
				{
					// Check if the id entered had seven digits	
					if(chosenID==0||(chosenID>999999&&chosenID<=9999999))
					{				
						// Checks if the id is unique	
						int idValidationResult=idIsInList(chosenID);
						if(-1==idValidationResult)
						{
							id=chosenID;
							cout<<"ID Recorded\n";
							done=true;	
						}
						else
						{
							cout<<"The id entered belongs to another task\n";
							cout<<"Please choose another id\n";
						}						
						
					}		
					else
					{
						cout<<"The value entered does not have seven digits\n";
					}
								
				}	
				else
				{
					// Clears the buffer if the input fails when a bad type is entered
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				}	
			}	
			while(done==false);

			return id;
		}	
		
		
};

	bool ListManager:: handleUserInput(const string input)
  	{
		// Takes the first char of the input and checks if it matches a task
		// If a task is matched then a task is performed based on the input
		bool done=false;	

			if(input.length()>0)
			{
       			// Gets the first char		
				char chosen = input[0];
        		// Cuts the char from the input
    			string task= input.substr(1,input.length());
				
				// Specification B1 - + Symbol
				if(chosen=='+')
				{
            		addTODO(task);
					
				}
				// Specification B3 - - symbol
				else if(chosen=='-')
				{
          			// If a - is matched then runs the remove command
					int idToRemove = (int)(stoi(task));				
					int itemIndex= idIsInList(idToRemove);
					if(itemIndex!=-1)
					{
						list.remove(itemIndex);
					}
				} 
				// Specification B2 - ? Symbol   
				else if(chosen=='?')
				{
          			// If a ? is matched then contents are displayed
					printTODOList();
				}
				else if(chosen=='E'||chosen=='e')
				{
          			// If E is matched then quit
					cout<<"Quitting Program\n";
					done=true;    
				}
				else
				{
					cout<<"Command is not valid\n";
				}
				
			}
			
			else
			{
				TODO todo;
				add(todo);
				this->hasBlankEntries=true;
			}
    		
			return done;

    }	


//Funtion Prototypes
void ProgramGreeting();
void UnitTest();
void runTODOLIST();
void menu();
void pressEnterKey();
void findTODOList();

int main()
{
    ProgramGreeting();
  	UnitTest();
	runTODOLIST();
    return 0;
}

void runTODOLIST()
{
    bool done;
    ListManager list;

    do
    {

        cout<<"Press Enter to Continue";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');		
        string input;
        
        menu();
			
        getline(cin,input);
		system("clear");
		
        if(!cin.fail())
        {
            done=list.handleUserInput(input);
		t p
        }

        else
        {
            // Clears the buffer if the input fails when a bad type is entered
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    while(!done);
    
}

void menu()
{   
    cout<<"TODO List Menu\n";
	cout<<"|============================|\n";
    cout<<"Enter a task into the console:\n";
    cout<<"<+> +Task to be added\n";
	cout<<"	Example Input: +Do my Math Homework\n";
    cout<<"<->Remove";
	cout<<"	Example Input: -TODO ID Number\n";
	cout<<"<?> ?Display all Tasks\n";
	cout<<"	Example Input: ?Display All Tasks\n";
	cout<<"<E> Exit the Program\n";
	cout<<"|============================|\n";
	cout<<"TODO List console~$";
	
} 


void ProgramGreeting()
{
    Date currentDate;
	cout<<"Today's Date: "<<currentDate;
    cout<<"============================\n";
    cout<<"Welcome to the TODO LIST\n";
    cout<<"The TODO List keeps all of the tasks that you need to do!\n";
    cout<<"Program Author: Ishan Meher\n";
    cout<<"Program Due Date: November 3, 2020\n";
	cout<<"============================\n";
}

void UnitTest()
{
	// Unit Tests
	pressEnterKey();
    Vector<int> array;
    array.VectorUnitTest();
    Date date;
	
  	date.dateUnitTest();
	
	TODO todo;
	todo.UnitTest();
	
	ListManager TODOLIST;
	TODOLIST.UnitTest();
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

