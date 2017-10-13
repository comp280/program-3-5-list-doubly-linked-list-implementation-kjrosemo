/*
* Author: Katrina Rosemond   
* Due Date: 10/13/2017
* Assignment: Program #3.5 - Extra Credit List - Double Linked List Implementation
* File: LinkedList-EC.cpp
* Description: This file will allow a user to create a list of strings which can be sorted, displayed, shuffled, averaged and determine the median.
*/

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
#include"LinkedList-EC.h"
using namespace std;

int main ( int argc, char** argv)   {
 srand((unsigned)time(0)); 
   char userSelection; //integer for user menu
   string userWord;	  //user input string
   bool toExit = false; //
   
   //creates a list 
   LinkedList list;
   
   //will propmt user if exit is false
   do   {
   
	  // menu prompt
      cout << "Let's create your word list! Please select an option."<<endl;
      cout << "1. Insert  - Inserts a word to your list." <<endl;
      cout << "2. Delete  - Deletes every instance of a given word from your list." <<endl;
      cout << "3. Display - Prints your list." <<endl;
      cout << "4. Sort    - Sorts your words based on length." <<endl;
      cout << "5. Average - Calculates the average length of your words, rounds up." <<endl;
      cout << "6. Median  - Caluculates the median length of your words, rounds up.." <<endl;
      cout << "7. Shuffle - Shuffles the words within your list." <<endl;
      cout << "8. Exit " <<endl;
      cin >> userSelection;
	  cout<<endl;
      
		  switch (userSelection)  {
			 
			 //Insert
			 case '1':
				{
				cout << "Please enter the word you wish to insert in your list." <<endl;
				cin >> userWord;
				cout<<endl;
				list.InsertAtEnd(userWord);
				break;
				}
			 //Delete
			 case '2':
				{
				cout << "Please enter the word you wish to delete in your list." <<endl;
				cin >> userWord;
				list.Delete(userWord);
				cout <<"All elements containing " << userWord << " has been deleted." << endl;
				cout<<endl;
				break;
				}
			//Display
			 case '3':
				{
				list.Display();
				cout<<endl;
				break;
				}
			 //Sort
			 case '4':
				{
				list.Sort();
				cout<<endl;
				break;
				}
			//Average
			 case '5':
				{
				cout<<"The average length is: " << list.Average() << endl;
				break;
				}
			//Median
			 case '6':
				{
				list.Sort();
				cout<<"The median length is: " << list.Median() << endl;
				cout<<endl;
				break;
				}
			//Shuffle
			 case '7':
				{
				list.Shuffle();
				cout<<endl;
				break;
				}
			 // Exit
			 case '8':
				{
				toExit = true;
				cout << "GOODBYE!" << endl;
				break;
				}   
			  // Default - if user selection is not on the menu.
			 default:
			   {
				 cout << "You did not select a menu option. Select an option on the menu. " << endl;
				 cout << endl;
 				 break;
				}
		  }
	 } while (!toExit);

   return 0;
   }