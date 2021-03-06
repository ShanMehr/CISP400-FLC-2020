// inventoryinquisitor.cpp
// Ishan Meher, CISP 400
// 10/11/2020

#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include <ctime>

using namespace std;


// Specification C2 - Dynamic Array
template <class A>
class ArrayList
{
	// The template class ArrayList creates an array that is able to store any data type 
	public:

		int length=0;
		A* array;

	public:
		
		ArrayList(int size)
		{	
			// Defines an ArrayList Object that accepts a length
			// Allocates space on the heap to store array
			if(length>=0)
			{
				// Makes sure the length is at least 0
				this->length=size;
				
			}			
			array= new A[length];
		}

		ArrayList()
		{
			// Creates an ArrayList object
			// Allocates space on the heap to store array
			this->length=0;
			array=new A[length];

		}


		

	private:

		void resizeArrayList()
		{
			// Resiszes the array by one

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
			// Returns the size of the array
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


		// Specification C3 - Resize Array - subtract from end
		void removeLast()
		{
			// Removes the element at the last index of the array
			remove(length-1);
		}

		
		void ArrayListUnitTest()
		{
			// Tests various functions of the ArrayList Class

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
		
		~ArrayList()
		{
			delete[] array;
			array=nullptr;
			this->length=0;
		}	

};

// Specification B1 - Date class
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

		//Specification B2 - ComponentTest method in Date
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
			cout<<"\n";
			cout<<"\n";

		}


	friend ostream& operator << (ostream &output,Date& date)
	{
		// Prints the data of the Date Class
    	output<<date.getDate(); 
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
		
};





struct InventoryItem
{
	int idNumber; 
	int itemQuantity;
	double wholesaleCost;
	double retailCost;
	Date dateAdded;

	InventoryItem(int idNumber, int itemQuantity, int wholesaleCost, Date date)
	{
		// Initializes the member variables of InventoryItem
		this->idNumber=idNumber;
		this->itemQuantity=itemQuantity;
		this->wholesaleCost=wholesaleCost;
		this->retailCost=2*wholesaleCost;
		this->dateAdded=date;
	}

	InventoryItem()
	{
		
	}

	// Specification A2 - Overload operator«
	friend ostream& operator << (ostream &output, InventoryItem& inventory)
	{
		// Prints the data of the InvetoryItem
    	output<<"ID: "<<inventory.idNumber<<'\n';
    	output<<"Number of Items: "<<inventory.itemQuantity<<'\n';
    	output<<"Wholesale Cost: $"<<inventory.formatDecimalToTwoPlaces(inventory.wholesaleCost);
    	output<<'\n';
    	output<<"Retail Cost: $"<<inventory.formatDecimalToTwoPlaces(inventory.retailCost);
    	output<<'\n';
    	output<<"Date Added: "<<inventory.dateAdded.getNumericDate()<<'\n'<<'\n';


 
    	return output;
	}

	
	// Specification B4 - Inventory Entry Input Validation
	void editItem()
	{
		// Edits and changes the instance variables of the InventoryItem class
		int id=validateIdNumberInput();
		this->idNumber=id;
		int itemQuantity=validateItemQuantityInput();
		this->itemQuantity=itemQuantity;
		this->wholesaleCost=validateWholeSaleCostInput();
		this->retailCost=wholesaleCost*2;
		this->dateAdded.setDate(9,9,99);	

	}


	// Specification A3 - Overload operator»
	friend istream &operator >>(istream &input, InventoryItem& inventory )
	{		
			// Changes member variables of the InventoryItem
			cout<<"Enter Id Number:\n";
			input>>inventory.idNumber;
			cout<<"Enter Number of Items:\n";
			input>>inventory.itemQuantity;
			cout<<"Enter Wholesale Cost :\n";
			input>>inventory.wholesaleCost;
			inventory.retailCost=inventory.wholesaleCost*2;
			Date date(9,9,99);
			inventory.dateAdded=date;
			return input;
	}	
	

	int validateIdNumberInput()
	{
		// Prompts the User for an idNumber and checks if the item chosen is correct
		// If the data entered is invalid repropmts the user for an entry
		bool done=false;
		int id;

		do
		{
			int chosenID;
			cout<<"Enter the id(A number with 5 digits)\n";
			cin>>chosenID;

			if(!cin.fail())
			{	
				if(chosenID>9999&&chosenID<=99999)
				{
					// Makes sure the id entered had five digits
					done=true;
					id=chosenID;
					cout<<"ID Recorded\n";
				}
				else
				{
					cout<<"ID Input Failed\n";
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

	int validateItemQuantityInput()
	{

		// Prompts the User for an itemQuantity and checks if the item chosen is correct
		// If the data entered is invalid repropmts the user for an entry

		bool done=false;

		int itemQuantity=0;

		do
		{
			int quantitySelected;
			cout<<"Enter the number of items\n";
			cin>>quantitySelected;
			cout<<"You Entered: "<<	quantitySelected<<'\n';

			if(!cin.fail())
			{	
				// Makes sure the data entered is not a bad type

				if(quantitySelected>=0)
				{	
					// Makes sure the quantitySelected is not negative a
					done=true;	
					itemQuantity=quantitySelected;
				}	
				else
				{					
					cout<<"Enter at least 1 item\n";
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

		return itemQuantity;
	}
 
	double validateWholeSaleCostInput()
	{
		// Prompts the User for an wholesaleCost and checks if the item chosen is correct
		// If the data entered is invalid repropmts the user for an entry

		bool done=false;
			double wholesaleCost=0;

		do
		{
			double wholesaleCostChosen;
			cout<<"Enter the wholesale cost:\n";
			cin>>wholesaleCostChosen;
			if(!cin.fail())
			{	
				if(wholesaleCostChosen>=0)
				{		
					// Confirms that the data entered is not negative before storing item
					wholesaleCost=wholesaleCostChosen;
					wholesaleCost=formatDecimalToTwoPlaces(wholesaleCost);
					retailCost=2*wholesaleCost;
					cout<<"Wholesale Cost Recorded: "<<wholesaleCost<<'\n';
					cout<<"Retail Cost Recorded: "<<retailCost<<'\n';
					done=true;		
				}		

				else
				{
					cout<<"Entered Wholesale Cost is not valid";
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

		return wholesaleCost;

	}


	Date validateDateInput()
	{

		// Prompts the User for an Date and checks if the item chosen is correct
		// If the data entered is invalid repropmts the user for an entry

		bool done;
		Date date;

		int month;
		int day;
		int year;


		do
		{

			

			// Prompts User for Input until a correct date is entered	
			cout<<"Enter Month(1-12)\n";
			cin>>month;

			if(!cin.fail())
			{
				cout<<"Month Entered: "<<month<<'\n';
				if(!cin.fail())
				{
					// If the correct datatype of int is entered then prompts user for day
					cout<<"Enter day (1-31 is a likely input)\n";
					cin>>day;


					if(!cin.fail())
					{
						cout<<"Day Chosen: "<<day<<'\n';
						// If the correct datatype of int is entered the prompts the user for the year
						cout<<"Enter Year (Between 1900-2100)\n";
						cin>>year;
						if(date.isValidDate(month,day,year))
						{
							
							date.setDate(month,day,year);
							done=true;


						}
					}	

					else
					{
						// Clears the buffer if the input fails when a bad type is entered
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

					}	

				}	

				else
				{
					// Clears the buffer if the input fails when a bad type is entered
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
		cout<<"Date Updated to:\n"<<date;

		return date;

	}

	void InventoryItemUnitTest()
	{
		// Unit Tests for InventoryItem
		InventoryItem item;

		cout<<"Testing the changing the values of the item\n";
		item.editItem();
		cout<<"Testing the Overloaded output operator\n";
		cout<<item;
		cout<<'\n';
		cout<<"Testing the Overloaded input Operator\n";
		InventoryItem item2;
		cin>>item2;
		cout<<item2;
		cout<<'\n';
	}	

	private:

		double formatDecimalToTwoPlaces(double number)
		{
			// Formats the Decimal to two places
			// First divides by 100 to shift the values 2 places to the left of the decimal
			// Then the number is converted to an int which removes the remaining unneeded decimals
			// Next the number is converted to a type double so that it can have decimals
			// Finally the number is shifted two decimal places to the right making allowing it to have two decimal places
    		return (((double)((int)(number*100)))/100);

		}




};


class InventoryManager
{
	public:

		ArrayList<InventoryItem> inventory; // An ArrayList which stores an array of InventoryItems

	public:

		void addItem()
		{
			// Adds an item to the ArrayList of InventoryItems 
			InventoryItem item;
			item.editItem();
			addItem(item);		

			
		}

		void addItem(InventoryItem &item)
		{
			// Accepts the reference of an item and adds the item to the inventory
			inventory.add(item);			
		}

		void remove()
		{
			// Removes the last item from the inventory

			if(getSize()>0)
			{
				this->inventory.removeLast();
			}
			else
			{
				cout<<"The Inventory is Empty!\n";
			}
		}

		void outputInventoryData()
		{

			// Prints the contents of he inventory
				if(inventory.size()>0)
				{
					for(int i=0;i<inventory.size();i++)
					{
						printItem(i);
					}
				}
				else
				{
					cout<<"The Inventory is Empty!\n";
				}			
		}


		

		void printItem(int index)
		{
			// Prints a single content of the inventory.
			inventory.printItem(index);
		}

		// Specification A1 - Edit Inventory	
		void editInventoryManagerItem()
		{

			// Edits the data members of a specific InventoryItem of the inventory Arraylist chosen by the user

			cout<<"Inventory Editor\n";
			cout<<"================\n";
			if(getSize()>0)
			{	
				bool done=false;
				int choice;
				int index;
				do
				{
					cout<<"Select an item edit\n";
					cout<<"Choose an index between 0 and "<<(inventory.size()-1)<<" (inclusive)\n";	
					cout<<"================\n";			
					cin>>index;
					
					if(!cin.fail())
					{	
						system("clear");
						cout<<"Choose a value:\n";
						cout<<"================\n";
						cout<<"(1)Change ID\n";
						cout<<"(2)Change Number of Items:\n";
						cout<<"(3)Change Wholesale Cost:\n";
						cout<<"(4)Change Date:\n";
						cout<<"(5) Quit\n";		
						cout<<"================\n";	

						cin>>choice;
	
						if(!cin.fail())
						{
							// Makes sure a value of a different type is not chosen by the user
							if(index>=0&&index<inventory.size())
							{
								// Only prompts the user to edit the item if the item is located at a valid index
								bool endProgram=handleUserSelection(index,choice);
								done=endProgram;


							}
							else
							{
								system("clear");
								cout<<"Index Entered is not valid\n";
							}
						}

						else
						{
							// Clears the buffer if the input fails when a bad type is entered
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			}
			else
			{
				cout<<"The Inventory is Empty\n";
				cout<<"Redirecting to Item Insertion\n";
				addItem();
			}
		}

			

		int getSize()
		{
			// Returns the size of inventory
			return inventory.size();
		}

		
		int isValidIndex(int index)
		{
			// Checks if the index chosen is valid 
			return inventory.isValidIndex(index);
		}

		void InventoryManagerUnitTest()
		{
			// Tests core functions of the InventoryManager
			InventoryManager testInventory;

			testInventory.addItem();			

			int id=12345;
			int itemQuantity=23;
			double wholesaleCost=12.23;
			Date date(2,25,2001);
			InventoryItem item(id,itemQuantity,wholesaleCost,date);
			testInventory.addItem(item);


			testInventory.outputInventoryData();

			cout<<"Removing an Item\n";
			testInventory.remove();
			testInventory.outputInventoryData();

		}




	private:

		bool handleUserSelection(int index,int choice)
		{
			// Processes the input chosen in editInventoryManagerItem() and updates a specific data type based on the int choice parameter

			bool done=false;

			InventoryItem *itemToInputData=nullptr;

			

				if(choice==1)
				{
					// Changes the idNumber of an InventoryItem located at the chosen index
					cout<<"Editing ID Number:\n";

					int ID= itemToInputData->validateIdNumberInput();

					InventoryItem item(ID,inventory.get(index).itemQuantity,inventory.get(index).wholesaleCost,inventory.get(index).dateAdded);

					itemToInputData=&item;

					cout<<"Updated ID: "<<item.idNumber<<'\n';

					inventory.set(index,item);
				}	

				else if(choice==2)
				{
					// Changes the itemQuantity of an InventoryItem located at the chosen index
					cout<<"Editing Number Of Items:\n";

					int itemQuantity= itemToInputData->validateItemQuantityInput();

					InventoryItem item(inventory.get(index).idNumber,itemQuantity,inventory.get(index).wholesaleCost,inventory.get(index).dateAdded);

					itemToInputData=&item;

					cout<<"Updated Number of Items: "<<item.itemQuantity<<'\n';

					inventory.set(index,item);

				}

				else if(choice==3)
				{	
					// Changes the wholesaleCost of an InventoryItem located at the chosen index
					cout<<"Editing Wholesale Cost:\n";

					double wholesaleCost= itemToInputData->validateWholeSaleCostInput();

					InventoryItem item(inventory.get(index).idNumber,inventory.get(index).itemQuantity,wholesaleCost,inventory.get(index).dateAdded);

					cout<<"Updated Number of Items: "<<item.wholesaleCost<<'\n';

					inventory.set(index,item);
					
				}

				else if(choice==4)
				{
					// Changes the Date of an InventoryItem located at the chosen index
					cout<<"Editing Date:\n";
					Date dateAdded=itemToInputData->validateDateInput();
					
					InventoryItem item(inventory.get(index).idNumber,inventory.get(index).itemQuantity,inventory.get(index).wholesaleCost,dateAdded);

					itemToInputData=&item;

					cout<<"Updated Number of Items: "<<item.dateAdded<<'\n';

					inventory.set(index,item);
				}

				else if(choice==5)
				{
					cout<<"Quitting Item Editor\n";
					done=true;
				}
				else
				{
					cout<<"Input is not Valid\n";
					done=true;
				}
				cout<<"Redirecting Back to Item Editor\n";
				cout<<'\n';			
				
				return done;
		}



};


// Function Prototypes
void ProgramGreeting();
void UnitTest();
void pressEnterKey();
void runInventoryInquisitor();
void alphaMenu();
bool validateUserInput(char input,InventoryManager &inventory);


int main()
{
	ProgramGreeting();
 	UnitTest(); 

 	runInventoryInquisitor();
}

void ProgramGreeting()
{
	Date date;
	cout<<"Today's Date: "<<date<<'\n';
	cout<<"========================================================================\n";
	cout<<"Welcome to the Inventory Inquisitory\n";
	cout<<"The Inventory Inquisitor keeps track of items added to an inventory\n";
	cout<<"Program Author: Ishan Meher\n";
	cout<<"Program Due Date: Ocotober 20, 2020\n";
	cout<<"Proceeding to UnitTests\n";
	cout<<"========================================================================\n";
	pressEnterKey();

}

// Specification A4 - UnitTest() method in main()
void UnitTest()
{
	cout<<"Starting Unit Tests\n";
	cout<<"Starting ArrayList Class Unit Test\n";
	ArrayList<int> array;
	array.ArrayListUnitTest();	
	Date date;
	date.dateUnitTest();
	pressEnterKey();
	


	
	cout<<"Starting InventoryItem Unit Testing\n";
	InventoryItem item;
	item.InventoryItemUnitTest();
	cout<<"Starting InventoryManager Unit Testing\n";
	pressEnterKey();
	InventoryManager inventory;
	inventory.InventoryManagerUnitTest();
	cout<<"Starting Program...\n";
	pressEnterKey();

}


void runInventoryInquisitor()
{
	bool done=false;

	InventoryManager inventory;
	do
	{
		char input=0;

		alphaMenu();
		cin>>input;


		if(cin.fail())
		{	
			// Clears the buffer if the input fails when a bad type is entered
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else
		{
			// Processes the user input and checks what task the user wants to perform
			// Also records whether the user want to quit the program
			system("clear");
			input=tolower(input);
			done=validateUserInput(input,inventory);
		}


	}
	while(done==false);
}

// Specification C1 - Alpha Menu
void alphaMenu()
{	

	cout<<"Select an Input\n";
	cout<<"================\n";
	cout<<"1. Add Inventory(A)\n";
	cout<<"2. Delete Inventory(D)\n";
	cout<<"3. Edit Inventory(E)\n";
	cout<<"4. Output Inventory(O)\n";
	cout<<"5. Quit Program(Q)\n";
	cout<<"================\n";
}


// Specification B3 - Menu Input Validation
bool validateUserInput(char input, InventoryManager &program)
{
	bool done=false;

	if(input=='o')
	{
		// Outputs the Inventory
		program.outputInventoryData();
		cout<<"Inventory Information\n";
		cout<<"========================\n";
		
	}

	else if(input=='a')
	{
		// Add item to the Inventory
		program.addItem();	
		
	}

	else if(input=='d')
	{
		// Removes the Item last added to the inventory
		program.remove();	
	}

	else if(input=='e')
	{
		// Edits the data values of the Inventory
		program.editInventoryManagerItem();

	}	

	else if(input=='q')
	{

			// Quits the Program
			cout<<"Quitting Program\n";
			done=true;
	}

	else
	{
		cout<<"The input entered is not valid!"<<'\n';
	}
	 
	return done;
}

void pressEnterKey()
{
	// Clears the console and asks the user to press the enter key to contine
	 int enter=0;
        
        cout << "Press Enter key to Continue\n";
        while (enter==cin.get() )      {
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

