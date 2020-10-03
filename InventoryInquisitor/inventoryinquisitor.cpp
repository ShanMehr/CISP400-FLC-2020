// inventoryinquisitor.cpp
// Ishan Meher, CISP 400
// 10/11/2020

#include<iostream>
#include<string>
#include<limits>
#include <cstdlib>
#include <ctime>

using namespace std;


// Specification C2 - Dynamic Array
template <class A>
class ArrayList
{
	// The template class ArrayList creates an array that is able to store any data type 
	private:

		int length;
		A* array[];

	public:
		
		ArrayList(int length)
		{	
			if(length>0)
			{
				this->length=length;
				
			}
			else
			{
				this->length=0;
			}
			
			array=new A[length];
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


		void remove(int index)
		{
			A* tempArrayList = new A[length-1];
			if(isValidIndex())
			{
				for(int position=0;position<length;position++)
				if(!(position==index))
				{
					tempArrayList[position]=array[position];
				}
			}
			

		}

	public:

		void set(int index, A value)
		{
			// Changes the data stored at the requested index
			if(isValidIndex())
			{	
				array[index]=value;
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

		bool isValidIndex(int index)
		{
			return (index>0&&index<length);
		}

		~ArrayList()
		{
			delete[] array;
			array=nullptr;
			this->length=0;
		}

		A get(int index)
		{
			// Gets the data stored at the requested index
			// Returns the last index of the array if the requested index is invalid
			if(index>0&&index<length)
			{	
				return array[index];
			}
			else
			{
				// If the entered index is not valid returns value of last index
				return array[length-1];
			}
		}

};




int main()
{
	
}