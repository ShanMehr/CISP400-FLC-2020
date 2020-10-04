// inventoryinquisitor.cpp
// Ishan Meher, CISP 400
// 10/11/2020

#include<iostream>
#include<string>
#include<limits>

#include <ctime>

using namespace std;


// Specification C2 - Dynamic Array
template <class A>
class ArrayList
{
	// The template class ArrayList creates an array that is able to store any data type 
	private:

		int length=0;
		A* array;

	public:
		
		ArrayList(int size)
		{	
			if(length>=0)
			{
				this->length=size;
				
			}			
			array= new A[length];
		}

		ArrayList()
		{
			this->length=0;
			array=new A[length];
		}


		

	private:

		void resizeArrayList()
		{
			
			A* tempArrayList= new A[length+1]; // The tempArrayList stores all the data of array and has one more element

			for(int position=0; position < length; position++)
			{
				// Loops through each position of the array and stores copies the element at each position into the tempArrayList
				tempArrayList[position]= array[position];
			}

			// Frees the memory used by the smaller array
			// The gradeList is set to point to the tempArrayList memory location
			delete[] array; 
			array=tempArrayList;	
			tempArrayList=nullptr;	
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
			return length;
		}

		// Specification C2 - Resize Array - add to end
		void add(A element)
		{
			// Adds a new element to the end of the array

			// Increases the size of the array by one
			resizeArrayList();
						
			array[length]=element;
			length++;		
			
		}



		bool isValidIndex(const int index)
		{
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

		void remove(const int index)
		{
			// Removes an alement at any index of the array
			if(isValidIndex(index))
			{
				// If the index is a valid index then remove the element located at the position

				A* tempArrayList = new A[length-1];
				int copyPosition=0;
				for(int position=0;position<length;position++)
				{
					if(!(position==index))
					{
						tempArrayList[copyPosition]=array[position];
						copyPosition++;
						

					}
					
				}
				delete[] array;
				length--;
				array=tempArrayList;
				tempArrayList=nullptr;
			}
			
		}

		void removeLast()
		{
			// Removes the element at the last index of the array
			remove(length-1);
		}

		

		
		
		~ArrayList()
		{
			delete[] array;
			array=nullptr;
			this->length=0;
		}

		void ArrayListUnitTest()
		{

			ArrayList<string> array;
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


};


class Date
{
	private:

		int month; // Stores the current month
		int day;  // Stores the current day
		int year; // Stores the current year
		string monthList[12] ={"January","February","March","April","May","June","July","August","September","October","November","December"}; // Used to convert numeric month to the name of the month
		

	public:

		// Specification A2 - External date initialization
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

	private:

		void setDate(int month, int day, int year )
		{
			// Utility dunctio used to set a date by changing instance variables 
			
			this->month=month; 
			this->day=day;
			this->year=year;


		}
		void testingSetDate(int month, int day, int year)
		{
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
			if(year>=1900&&year<=2100)
			{
				// Checks if a reasonable year is entered				
				return true;				
			}

			else
			{
					cout<<"Year input failed!\n";
					cout<<"The year entered is not a reasonable year entry try a year between 1900-2100(inclusive)\n";
					return false;
			}
		}

		void printDate()
		{
			// Prints the date
			if(isValidDate(month,day,year))
			{
				// The date will only be printed if the date is a valid date

				string monthString= monthList[month-1];
				cout<<"Date: ";
				cout<<monthString<<" "<<day<<", "<<year<<'\n';

			}
			else
			{
				cout<<"Date is not valid"<<'\n';
			}	
		}

		void printNumericDate()
		{
			// Prints the date
			if(isValidDate(month,day,year))
			{
				// The date will only be printed if the date is a valid date

				
				cout<<"Date: ";
				cout<<month<<"/"<<day<<"/"<<year<<'\n';

			}
			else
			{
				cout<<"Date is not valid"<<'\n';

			}	

		}

		// Specification A3 - Component Test Method in Date
		void dateUnitTest()
		{
			//Tests the cases in which dates will work and cases where dates will fail

			
			// Printing Today's Date
			Date testDate;
			cout<<"Displaying Today's date in Letter form\n";
			testDate.printDate();
			cout<<"Entering Today's date in numeric form\n";
			testDate.printNumericDate();
			cout<<"\n";
			
			// Testing Constructor with multiple parameters and checking date entered
			cout<<"Testing wether the multiple parameter constructor works\n";
			Date* date  = testDateContructor(12,15,2020);
			cout<<"Displaying Today's date in Letter form\n";
			cout<<"Printing Numeric Date:\n";	
			cout<<"Expected: 12/15/2015\n";
			testDate.printNumericDate();
			cout<<"Printing Letter Date\n";
			cout<<"Expected "<<"December 15, 2015\n";	
			testDate.printDate();				
			cout<<"\n";
			cout<<"\n";;


			// Fails all the tests for a valid date
			cout<<"Testing a Day that fails for any date test \n";
			testDate.testingSetDate(12000,15000,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();
			testDate.printNumericDate();
			cout<<"\n";
		

			// A date can't have a month that is more than 12
			testDate.testingSetDate(13,29,2000);
			cout<<"Testing a month that is not valid!\n";
			cout<<"Testing a month that is greater than 12\n";			
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();
			testDate.printNumericDate();
			cout<<"\n";


			// A month can't be less than 1
			cout<<"Testing a month that will fail! \n";
			cout<<"Testing a month smaller than 1\n";	
			testDate.testingSetDate(0,12,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();
			testDate.printNumericDate();
			cout<<"\n";


			// Testing a date to have a month that works
			cout<<"Testing a month that works\n";
			testDate.testingSetDate(12,15,2015);
			cout<<"Printing Numeric Date:\n";	
			cout<<"Expected: 12/15/2015\n";
			testDate.printNumericDate();
			cout<<"Printing Letter Date\n";
			cout<<"Expected "<<"December 15, 2015\n";	
			testDate.printDate();				
			cout<<"\n";
			cout<<"\n";


			cout<<"Testing a year smaller than expected that fails\n";
			testDate.testingSetDate(12,15,1800);
			cout<<"Printing Numeric Date:\n";
			testDate.printNumericDate();
			cout<<"Printing Letter Date\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a year that works\n";
			testDate.testingSetDate(12,15,2020);
			cout<<"Printing Numeric Date:\n";
			cout<<"Expected: 12/15/2002\n";
			testDate.printNumericDate();
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: December 15, 2020\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// A month can't have more than 31 days
			cout<<"Testing a day that is greater than 31\n";
			testDate.testingSetDate(2,32,2000);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// A month can't less than 1 day
			cout<<"Testing a day that is less than 1\n";
			testDate.testingSetDate(1,0,2000);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// The month of April has 30 days 
			cout<<"Testing a Day that fails for a 30 day month\n";
			testDate.testingSetDate(4,31,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";


			// The month of april has 30 days
			cout<<"Testing a Day that passes for a 30 day month \n";
			testDate.testingSetDate(4,30,2020);	
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: 4/30/2020\n";	
			testDate.printNumericDate();	
			cout<<"Printing Letter Date:\n";
			cout<<"Expected: April 30, 2020\n";
			testDate.printDate();

			cout<<"\n";
			cout<<"\n";

			// The Month of February has 29 days on leap year
			cout<<"Testing a day in february that fails when it is leap year \n";
			testDate.testingSetDate(2,30,2022);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";


			cout<<"Testing a day in february that passes when it is leap year \n";
			testDate.testingSetDate(2,29,2000);
			cout<<"Printing Numeric Date\n";
			cout<<"Expected: 2/29/2000\n";
			cout<<"Printing Letter Date\n";
			cout<<"Expected: February 29, 2000\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// The month of February has 28 days in a Common year
			cout<<"Testing a day in february that fails when it is not a leap year \n";
			testDate.testingSetDate(2,29,2001);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a day in february that passes when it is not leap year \n";
			testDate.testingSetDate(2,28,2001);
			cout<<"Printing Numeric Date\n";
			cout<<"Expected: 2/28/2001\n";
			testDate.printNumericDate();
			cout<<"Printing Letter Date\n";
			cout<<"Expected: February 28, 2001\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

		}
		
};





struct InventoryItem
{
	int idNumber;
	int itemQuantity;
	int wholesaleCost;
	int retailCost=2*wholesaleCost;
	Date dateAdded;

	InventoryItem(int idNumber, int itemQuantity, int wholesaleCost, Date dateAdded)
	{
		this->idNumber=idNumber;
		this->itemQuantity=itemQuantity;
		this->wholesaleCost=wholesaleCost;
		this->retailCost=2*wholesaleCost;

	}

};


class InventoryManager
{
	private:
		ArrayList<InventoryItem*> inventory;
	public:
		InventoryManager()
		{
			cout<<"Constructor";
		}



};


// Function Prototypes
void ProgramGreeting();
void UnitTest();
void pressEnterKey();


int main()
{
 	UnitTest(); 
}

void UnitTest()
{
	cout<<"Starting ArrayList Class Unit Test\n";
	pressEnterKey();
	ArrayList<int> array;
	array.ArrayListUnitTest();	
	pressEnterKey();
	Date date;
	date.dateUnitTest();

}


void pressEnterKey()
{
	// Clears the console and asks the user to press the enter key to contine
	 int enter=0;
        
        cout << "Press Enter to Continue\n";
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
