// gpaanalyzer.cpp
// Ishan Meher, CISP 400
// 9/27/2020

#include<iostream>
#include<string>
#include<limits>
#include <cstdlib>
#include <ctime>

using namespace std;


class GradeInfo
{
	private:

		int gradeListSize=0; // The size of the gradesList

		
		int *gradeList;
		

	public:

		// Specification B1 - Dynamic Array
		GradeInfo()
		{
			// Constructor sets starting value of grades class

			gradeList= new int[0]; // allocates space for one grade
				
		}

		~GradeInfo()
		{
			delete[] gradeList; // Frees memory used on the heap by gradelist
			gradeList=nullptr; // Removes the pointer to memory location to avoid a dangling pointer
			gradeListSize=0;	// Sets the size of the array to 0
		}

		

	private:

		void resizeGradeList()
		{
			// Makes a copy of the gradesList and 
			int* tempGradesList= new int[gradeListSize+1]; // The temporary grade liat is 1 position larger than gradeList

			for(int position=0; position < gradeListSize; position++)
			{
				// Loops through each position of the grade list array and stores copies the element at each position into the tempGradeList
				tempGradesList[position]= gradeList[position];
			}

			delete[] gradeList; // Deletes the memory stored
			gradeList=tempGradesList;	// Set the gradeList pointer to the copy's memory location
			tempGradesList=nullptr;	//Removes the pointer to the memory location ot avoid a dangling pointer
			gradeListSize++;	// Updates the size of the gradeList array	

		}

	public:

		// Specification C2 - Print Scores
		// Specification C3 - Letter Grades
		void displayAllNumericGrades()
		{
			// Displays the entered grades if the list is not empty

			system("clear"); // Clears the console

			if(gradeListSize>=0
)			{
				// If the array is not empty display all the grades
				cout<<"Displaying Numeric Grades"<<'\n';
				

				for(int position=0; position<gradeListSize; position++)
				{
					// Prints all the grades in the gradeList
					cout<<"Grade "<<position+1<<": "<<gradeList[position]<<'\n';

					// Also prints the letter grade after converting the letter grade into a string
					cout<<"Letter Grade "<<position+1<<": "<<convertToLetterGrade(this->gradeList[position])<<'\n';
					cout<<"\n";
				}
			}
			
			else
			{
				cout<<"There are no grades entered"<<'\n';
			}

		}


		string convertToLetterGrade(const int grade)
		{
			// Converts and returns a letter grade based
			// Only returns grade if on 0-100 numeric grade scale

			if(grade>=90&&grade<=120)
			{
				// if the numeric grade is greater than or equal to 90 the grade is an A
				return "A";
			}

			else if(grade>=80&&grade<90)
			{
				// if the numeric grade is greater than or equal to 80 the grade is an B
				// Already checked if greater than 90
				return "B";
			}

			else if(grade >=70&&grade<80)
			{
				// if the numeric grade is greater than or equal to 70 the grade is an C
				// Already checked if greater than 80

				return "C";				
			}

			else if (grade>=60&&grade<70)
			{
				// if the numeric grade is greater than or equal to 60 the grade is an D
				// Already checked if greater than 70
				return "D";
			}

			else if(grade>=0 && grade<60)
			{
				// if the numeric grade is greater than or equal to 0 and less than 60 the grade is an F
				
				return "F";
			}

			else
			{
				// If the numeric grade is negative then return an E error code
				cout<<"The numeric grade is not a valid grade"<<'\n';

				return "Error";
			}

		}

		// Specification C4 - Compute GPA
		int computeGpa()
		{
			// Calcualtes the Gpa
			// Finds the Gpa by calcuating the grade average of the scores entered;

			int gradeSum=0; // Stores the total of all the grades

			for(int position=0; position< gradeListSize; position++)
			{
				// Adds the total of all the grades

				gradeSum+=gradeList[position];

			}

			// Calculates the average by dividing the sum of the grades by the number of grades
			return (gradeSum/gradeListSize);
		}
		
		//Specification B2 - Add Elements
		void addGrade()
		{
			// Adds a grade to the gradeList array

			resizeGradeList();
			// Increases gradeList size by 1

 			bool valid=false;
 			int enteredGrade;

			do
			{
				// Requests for an entered grade and checks if the input is valid
				// If input is not valid then 
				

				cout<<"Enter a numeric grade, Input values are between 0-100(inclusive)"<<'\n';

				cin>>(enteredGrade); // Asks for the grade and stores the grade in enteredGrade casts the 
				if(cin.fail())
				{	
					// Clears the buffer if the input fails whnen a bad type is entered
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				else
				{
					if(enteredGrade>=0&&enteredGrade<=100)
					{
						// Runs If the input is a valid type and the grade entered is a possible numeric grade
						// Records the grade in gradeList

						gradeList[gradeListSize-1]= enteredGrade;

						cout<<"Grade entered successfully"<<'\n';
						cout<<"Grade: "<<gradeList[gradeListSize-1]<<" Recorded"<<'\n';

						valid=true; // Grade has been entered breaks out of the grade request loop
					}
				}

			}while(!valid);

		}

		void gradeInfoUnitTest(); // Tests the converToLetterGrade()
		

};


// Specification A1 - Date class
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
				return false;
			}

			else
			{

				if((month==9||month==11)||(month%2==0&&(month!=10||month!=12||month!=8||month!=2)))
				{
					// Tests to see if months that have 30 days do not have more than 30 days4
					// Most even months have 30 days have 30 days except December August and February
					// The odd months September and November have 30 days
					if(day>=31||day<1)
					{
						// Checks if the day entered of the checked months don't have more than 30 days or less than 1
						cout<<"Day input failed!\n";
						return false;
					}
				}
				if(month==2)
				{
					if(isLeap&&day>=30)
					{
						// There are 29 days in the month of february during leap year
						cout<<"Day input failed!\n";
						return false;

					}

					else if(!isLeap&&day>=29)
					{
						// ELse if its a Common year then it will have 28 days
						cout<<"Day input failed!\n";
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
				cout<<monthString<<" "<<day<<", "<<year;

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
			cout<<"Displaying Today's date\n";
			printDate();
			cout<<"\n";
			cout<<"\n";

			// Fails all the tests for a valid date
			cout<<"Testing a Day that fails for any date test \n";
			testDate.setDate(12000,15000,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
		

			// A date can't have a month that is more than 12
			testDate.setDate(13,29,2000);
			cout<<"Testing a month that is not valid!\n";
			cout<<"Testing a month that is greater than 12\n";			
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();
			cout<<"\n";


			// A month can't be less than 1
			cout<<"Testing a month that will fail! \n";
			cout<<"Testing a month smaller than 1\n";	
			testDate.setDate(0,12,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();
			cout<<"\n";


			// Testing a date to have a month that works
			cout<<"Testing a month that works\n";
			testDate.setDate(12,15,2015);			
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";	


			cout<<"Testing a year smaller than expected that fails\n";
			testDate.setDate(12,15,1800);

			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a year that works\n";
			testDate.setDate(12,15,2020);
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// A month can't have more than 31 days
			cout<<"Testing a day that is greater than 31\n";
			testDate.setDate(2,32,2000);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// A month can't less than 1 day
			cout<<"Testing a day that is less than 1\n";
			testDate.setDate(1,0,2000);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// The month of April has 30 days 
			cout<<"Testing a Day that fails for a 30 day month\n";
			testDate.setDate(4,31,2020);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";


			// The month of april has 30 days
			cout<<"Testing a Day that passes for a 30 day month \n";
			testDate.setDate(4,30,2020);			
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// The Month of February has 29 days on leap year
			cout<<"Testing a day in february that fails when it is leap year \n";
			testDate.setDate(2,30,2022);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";


			cout<<"Testing a day in february that passes when it is leap year \n";
			testDate.setDate(2,29,2000);
			
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			// The month of February has 28 days in a Common year
			cout<<"Testing a day in february that fails when it is not a leap year \n";
			testDate.setDate(2,29,2001);
			cout<<"Expected: Date is not valid\n";
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

			cout<<"Testing a day in february that passes when it is not leap year \n";
			testDate.setDate(2,28,2001);
			testDate.printDate();	
			cout<<"\n";
			cout<<"\n";

		}


		
};



// Function Prototypes
void ProgramGreeting();
void unitTest(); // tests functions that have the possibilty to fail
void startGpaAnalyzer();
void numericMenu();
bool validateUserInput(const int INPUT,GradeInfo *gpaanalyzer);
void printBlankLine();
void pressEnterKey();

int main()
{
	cout<<"Displaying Unit Tests"<<'\n';
	pressEnterKey();
	unitTest();
	cout<<"Starting Gpa Analyzer"<<'\n';
	pressEnterKey();
	ProgramGreeting();
	startGpaAnalyzer();	
	 
}

void GradeInfo::gradeInfoUnitTest()
{
	//Unit Test for GradeInfo Class
	GradeInfo gpaanalyzer;
	int gradeValue;

	// Tests cases where convertToLetterGrade function might fail
	// Inputs can only be between 0-100

	cout<<"Testing an a grade that cannot be converted to a letter grade(Too large)\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=500)<<'\n';
	cout<<"\n";

	cout<<"Testing an a grade that cannot be converted to a letter grade(Too small)\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=-1)<<'\n';
	cout<<"\n";

	cout<<"Testing a A grade\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=100)<<'\n';
	cout<<"\n";	

	cout<<"Testing a B grade\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=89)<<'\n';
	cout<<"\n";	

	cout<<"Testing a C grade\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=79)<<'\n';
	cout<<"\n";	

	cout<<"Testing a D grade\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=69)<<'\n';
	cout<<"\n";	

	cout<<"Testing an F grade\n";
	cout<<"Result: "<<convertToLetterGrade(gradeValue=59)<<'\n';
	cout<<"\n";	



}


// Specification C1 - Program Greeting Function
void ProgramGreeting()
{
	// Greets the user and describes program purpose

	Date currentDate;

	cout<<"Welcome to the Gpa Analyzer"<<'\n';
	cout<<"The Gpa Analyzer calculates the user's gpa"<<'\n';
	cout<<"The gpa is calculated by finding the average of the user's grades"<<'\n';	
	cout<<"Program Author: Ishan Meher\n"; 
	currentDate.printDate();

	printBlankLine();
	printBlankLine();
}

// Specification A4 - Component Test Grade Conversion
void unitTest()
{
	// Runs all the Unit Tests

	// Unit Tests for Date Class
	Date date;
	date.dateUnitTest();

	// Unit Tests for Numeric Grade to Letter Grade Converion
	GradeInfo gpaanalyzer;
	gpaanalyzer.gradeInfoUnitTest();
}

// Specification B3 - Menu Input Validation
void startGpaAnalyzer()
{
	// Handles the calculations for gpa analyzer
	bool done; // Variable that stores wether the user is done using the Gpa Analyzer 
	GradeInfo gpaanalyzer;
	do
	{
		int input=0;

		numericMenu();
		cin>>input;
		system("clear");

		if(cin.fail())
		{	
			// Clears the buffer if the input fails whnen a bad type is entered
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else
		{
			// Processes the user input and checks what task the user wants to perform
			// Also records whether the user want to quit the program
			done=validateUserInput(input,&gpaanalyzer);
		}


	}
	while(!done);
}

// Specification B4 - Print Letter Grade
bool validateUserInput(const int INPUT,GradeInfo *gpaanalyzer)
{
	
	bool done =false; // done is true if the user enters a 4

	switch(INPUT)
	{
		case 1:	
			
			gpaanalyzer->addGrade(); // If a 1 is entered the user can add a grade
			break;

		case 2:

			gpaanalyzer->displayAllNumericGrades(); // If the user enters a 2 the user can view all the numeric grades that have been entered
			cout<<""<<'\n';
			break;

		case 3:
			// If the user enters a 3 then the letter grades are displayed

			cout<<"Gpa:"<<gpaanalyzer->computeGpa()<<" Letter Grade: "<<gpaanalyzer->convertToLetterGrade(gpaanalyzer->computeGpa())<<'\n'; 
			
			break;

		case 4:
			
			cout<<"Quitting Gpa Analyzer"<<'\n'; 
			done=true; // The user wants to end the program when a 4 is entered
			break;

		default:

			cout<<"The input entered is not valid!"<<'\n';
			break;
	} 
	return done;

}

void numericMenu()
{
	// Displays Gpa Analyzer Menu

	cout<<"Main Menu:"<<'\n';
	cout<<"1. Add Grade\n";
	cout<<"2. Display All Grades"<<'\n';
	cout<<"3. Process All Grades"<<'\n';
	cout<<"4. Quit Menu"<<'\n';
	printBlankLine();
}

void printBlankLine()
{
	// Prints a blank line
	cout<<" "<<'\n';
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
