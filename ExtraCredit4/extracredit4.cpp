// Ishan Meher
// CISP 400
// Extra Credit 4
#include <iostream>
#include<string>
#include <cstring>


using namespace std;


class Pstring
{ 
  public:
 
  bool operator()(string task)
  {
    return isPalindrome(task);
  }

  private:
  bool isPalindrome(string task)
  {
    bool isPalindrome=true;
    int startIndex=1;
    for(int index=task.length()-1;index>=0;index--)
    {
      //cout<<task[index]; 
      if((tolower(task[startIndex-1]))==(tolower(task[index])))
      {

      }
      else
      {return false;}
      startIndex++;
      
    }
    return isPalindrome;
  }

};

string printBool(bool boolean)
{
  if(boolean)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}


int main() {
  cout<<"Checking if a string is a palindrome\n";
  Pstring palindrome;
  cout<<"Checking to see if a word that is a palindrome returns true\n";
  cout<<"Checking the word radar\n";
  cout<<printBool(palindrome("radar"))<<endl;  
  cout<<endl;

  cout<<"Now check to see if a word that is not a palindrome prints false\n";
  cout<<"Checking the word sytnax\n";
  cout<<printBool("syntax")<<endl;
  cout<<endl;

  
  string result;
  cout<<"Now it's your turn enter a word and see the result\n";
  cin>>result;
  cout<<printBool(palindrome(result))<<endl;



  
  
}


