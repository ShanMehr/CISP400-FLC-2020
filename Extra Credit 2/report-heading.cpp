// report-heading.cpp
// Ishan Meher, CISP 400
// 9/27/2020

#include<iostream>
#include<string>
#include <iomanip> 

using namespace std;

class Heading
{
	private:
		string companyName;
		string reportHeading;
	
	public:

		Heading(string companyName, string reportHeading)
		{
			this->companyName=companyName;
			this->reportHeading=reportHeading;
		}

		Heading()
		{
			
			this->companyName="ABC Industries";
			this->reportHeading="Report";
		}
	
	private:

		void centerText(string text, int asteriskNumber)
		{
			int center= (asteriskNumber-text.length())/2;
			 
			if ( center > 0 )
			{ 	cout << string( center, ' ' );
  			 	cout << text << '\n';
  			}

		}

	public:
		string getCompanyName()
		{
			return companyName;
		}

		string getReportHeading()
		{
			return reportHeading;
		}

		string printHeading()
		{
			return (companyName+" "+reportHeading);
		}

		void printBoxedHeading()
		{
			int asteriskCount=50; 

			cout<<setfill('*')<< setw(asteriskCount)<<'\n';
			centerText(companyName,asteriskCount);
			centerText(reportHeading,asteriskCount);
			cout<<setfill('*')<< setw(50)<<'\n';


		}
};

int main()
{
	cout<<"Displaying the default Constuctor Output/n";
	Heading company;
	cout<<"Printing the single line output for the default Constuctor\n";
	company.printHeading();
	cout<<"Printing the boxed output\n";
	cout<<"\n";
	company.printBoxedHeading();
	cout<<"\n";
	
	cout<<"Displaying the paramterized Constuctor content\n";
	Heading company2("Colonel's Fried Chicken","Balance Sheet");
	cout<<"Printing the single line output for the paramterized Constuctor\n";

	company2.printHeading();
	cout<<"Printing the boxed output\n";
	cout<<"\n";
	company2.printBoxedHeading();



}
