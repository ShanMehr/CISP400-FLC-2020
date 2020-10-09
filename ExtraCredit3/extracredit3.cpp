#include<iostream>
#include<string>
#include<limits>
#include<cctype>
#include <ctime>

using namespace std;


class Date
{
	private:

		int month; // Stores the current month
		int day;  // Stores the current day
		int year; // Stores the current year
   
    

  	const string MONTHLIST[12] ={"January","February","March","April","May","June","July","August","September","October","November","December"};

  
   

	public:

   

    Date(int month,int day)
    {
      this->day=day;
      this->month=month;
    }

    int getMonth()
    {
      return month;
    }
    int getDay()
    {
      return day;
    }

    string getDayString()
    {
      return (MONTHLIST[month-1]);
    }
				

    Date(int dayOfYear)
    {
      setDateFromIntDay(dayOfYear);
    }

    Date(string month, int day)
    {
      month[0]=toupper(month[0]);
      
      for(int index=0;index<12;index++)
      {
          if(month.compare(MONTHLIST[index]))
          {
            this->month=index;
           
            break;
          }                   
      }

      if(day>0&&day<31)
      {
        this->day=day;
      }
      else
      {
                cout<<"Not a valid day;";
      }

    }



	

	public:
		
	


    void print()
    {
      cout<<MONTHLIST[month-1]<<", "<<this->day<<'\n';
    }

	

	
  Date operator++()
  {
    // Prefix increment operator.
    int day=this->day;
    int month=this->month;
    (++day);
    
    if(day>31)
    {
      day=1;
      if(this->month==12)
      { 
        month=1;
      }
      else
      {
        ++month;
        
      }
    }
    return Date(month,day);
  }

  Date operator++(int)
  {
       // Postfix increment operator.
    int day=this->day;
    int month=this->month;
    day++;
    
    if(day>31)
    {
      day=1;
      if(this->month==12)
      { 
        month=1;
      }
      else
      {
        month++;
        
      }
    }
     return Date(month,day);
  }
  

  
   Date operator--()
   {
    // Prefix decrement operator.
    int day=this->day;
    int month=this->month;
    --day;
    if(day<1)
    {
      day=31;
      if(this->month==1)
      { 
        month=12;
      }
      else
      {
        --month;
        
      }
    }
     return Date(month,day);
  }
         
  Date operator--(int)     
  {
    // Postfix decrement operator.
    int day=this->day;
    int month=this->month;
    day--;
    if(day<1)
    {
      day=31;
      if(this->month==1)
      { 
        month=12;
      }
      else
      {
         month--;
        
      }
    }
    return Date(month,day);
  }


 void setDateFromIntDay(int dayOfYear)
  { 

    
    if(!(dayOfYear>365&&dayOfYear<1))
    {
        if(dayOfYear>334)
        {
          this->month=12;
          this->day=(dayOfYear-334);
          
        }
        else if(dayOfYear>304)
        {          
          this->month=11;
          this->day=(dayOfYear-304);
        }
        else if(dayOfYear>273)
        {
          this->month=10;
          this->day=(dayOfYear-273);
        }
        else if(dayOfYear>243)
        {
          this->month=9;
          this->day=(dayOfYear-243);
        }
        else if(dayOfYear>212)
        {
          this->month=8;
          this->day=(dayOfYear-212);
        }
        else if(dayOfYear>181)
        {
          this->month=7;
          this->day=(dayOfYear-181);
        }
        else if(dayOfYear>151)
        {
          this->month=6;
          this->day=(dayOfYear-151);
        }
        else if(dayOfYear>120)
        {
          this->month=5;
          this->day=(dayOfYear-120);
        }
        else if(dayOfYear>90)
        {
          this->month=4;
          this->day=(dayOfYear-90);
        }
        else if(dayOfYear>59)
        {
          this->month=3;
          this->day=(dayOfYear-59);
        }
        else if(dayOfYear>31)
        {
          this->month=2;
          this->day=(dayOfYear-31);
        }
        else
        {
          this->month=1;
          this->day=(dayOfYear-0);
        }
    }
    else
    {
      cout<<"Not a Valid Date\n";
    }

  }  



		
};

//Function Prototypes
void Driver();

int main()
{
  Driver();
}


void Driver()
{
  cout<<"Printing a date initialized to January, 5\n";
  Date date("January",5);
  date.print();
   cout<<"\n";
  
  cout<<"Printing a date initialized to the 365th day December, 31\n";
  date.setDateFromIntDay(365);
  date.print();
   cout<<"\n";

  
   cout<<"Increasing the December, 12 date by 1 using post-increment\n";
  cout<<"Should Print January, 1\n";
   cout<<"Date skips to January, 1 since there cannot be 366 days in a common year or a day more than 31\n";
  Date date2 =date++;
  date2.print();
   cout<<"\n";
   
  cout<<"Increasing the January, 1 date by 1 using pre-increment\n";
  cout<<"Should Print January, 2\n";
  Date date3 = ++date2;
  date3.print();
   cout<<"\n";

  cout<<"Decreasing the January, 2 date by 1 using post-decrement\n";
  cout<<"Should Print January, 1\n";
  Date date4=date3--;
  date4.print();
  cout<<"\n";

  cout<<"Decreasing the January, 1 date by 1 using pre-decrement\n";
  cout<<"Should Print December, 31\n";
  cout<<"December, 31 is printed since date can't be less than 1\n";
  date4.setDateFromIntDay(1);
  Date date5=--date4;
  
  date5.print();
  
}