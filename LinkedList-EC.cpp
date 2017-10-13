/*
* Author: Katrina Rosemond   
* Due Date: 10/13/2017
* Assignment: Program #3.5 - Extra Credit List - Double Linked List Implementation
* File: LinkedList-EC.cpp
* Description: This file contains linked list methods that will be used for the list class.
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include"LinkedList-EC.h"
using namespace std;
/* initialize random seed: */
  //srand((unsigned)time(0));
 
//Function creates an empty list
LinkedList::LinkedList(){ 
   first = NULL; 
}
   
// Function will check Array to see if it is empty.
bool LinkedList :: Empty() {

   if ( first == NULL )	{
      cout << "List is empty" << endl;
      return true;
   }
   else	{	
      return false;      
   }
}

// Function will insert user given word into the beginning of the linked list.
void LinkedList :: InsertAtEnd(ElementType x)  {
      
      node * endPtr = new node;
      endPtr -> data = x;
      endPtr -> next = NULL;  
      endPtr -> prev = NULL;
      
      if ( first == NULL ) {
         first = endPtr;
         Display();
         return;
      }
      else  {
         node * traversePtr = new node;
         traversePtr = first;
         while (traversePtr -> next != NULL )  {
               traversePtr = traversePtr -> next;               
      }
      endPtr -> prev = traversePtr;
      traversePtr -> next = endPtr ;
      last = endPtr;
      Display();
    }                 
}

// Function will remove instances of a user given word from the list array.
void LinkedList :: Delete(ElementType x) {
	node * traverse, * temp;
	traverse = first;

 if (Empty())  {
   cout << "There are no elements to delete." << endl;
   return;
 }
 // deletes the first node if it is the only node in the list
 if( first -> data == x && first -> next == NULL){
         temp = first;
		 first = NULL;
         last = NULL;
         delete temp;
		 return;
 }
 while ( traverse != NULL)	{
   if( traverse -> data == x) {
      temp = traverse;
        if (traverse == first)  {
            first = first -> next;
            first -> prev = NULL;
            traverse = first;
         }
         else if (traverse == last /* //or// traverse -> next == NULL */)   {
         traverse -> prev -> next = NULL;
         last = traverse -> prev;
         traverse = NULL;
         }
         else {
         traverse -> prev -> next = temp -> next;
         traverse -> next -> prev = traverse -> prev;
         traverse = temp -> next;
         }
      temp -> next = NULL;
      temp -> prev = NULL;
      delete temp;   
  }
  else {
      traverse = traverse -> next;   
  }
}
 cout<<endl;
 Display();
}
// Function will print linked list.
void LinkedList :: Display() {
   node * traverse = first;
   if (Empty())  {
   cout << "There are no elements to print." << endl;
   return;
   }
   while ( traverse != NULL )    {
      cout<< traverse -> data <<endl;
      traverse = traverse -> next;
   }
   cout<<endl;
} 
// Function will sort the list based on length of each string.
void LinkedList :: Sort()   {
   node * traverse = first -> next;
   node * previous = first;
   node * temp = first;
   if (Empty())  {
   cout << "There are no elements to sort." << endl;
   return;
   }
   if ( first -> next == NULL)	{
   cout << "There is only one element." << endl;
   Display();
   return;
   }
//	while ( previous != last )	{
		while ( traverse != NULL )	{
			if (previous -> data.length() > traverse -> data.length() )	{
			   ElementType temp1 = traverse -> data;
			   ElementType temp2 = previous -> data;
			   previous -> data = temp1;
			   traverse -> data = temp2;
			   previous = first;
			   traverse = first -> next;
		   }
		   else {
		   previous = previous -> next;
		   traverse = traverse -> next;
		   }
		}
//	}
   Display();
}
// Function will calculate the average string length.
double LinkedList :: Average()   {
   int sum = 0;
   int n = 0;
   node * traverse = first;
   if (Empty())  {
   cout << "There are no elements to average." << endl;
   return 0;
   }
   while ( traverse != NULL )    {
      sum += traverse -> data.length();
      n++;
      traverse = traverse -> next;
   }
   double avg = (double) sum / n;
   return  ceil(avg); 
}

// Function will calculate the median string length.
double LinkedList :: Median()    {
	int n = 1; 
	int count = 1;
	int sum = 0;
   node * traverse = first;
   if (Empty())  {
      cout << "There are no elements to to get the median length." << endl;
      return 0;
   }
   if (traverse -> next == NULL) {
      return traverse->data.length();
   }
   Sort();
   while ( traverse -> next != NULL )    {
         n++;
         traverse = traverse -> next;
   }
   int indexVal = n/2;
   int i = 0;
   traverse = first;
   while ( i < indexVal )  {
         traverse = traverse -> next;
         i++;
   }
      if (n % 2 == 0) {
         int temp1 = traverse -> data.length(); 
   	   int temp2 = traverse -> prev -> data.length();
   	   double temp3 = (double)(temp2 + temp1)/2;
   	   return ceil((double)(temp3));   
      }
      else{
         return traverse -> data.length();
      }
}
// Function will shuffle the string within the list.
void LinkedList :: Shuffle()  {
	int n = 0; 
   node * traverse = first;
   node * temp1, * temp2;
   if (Empty())  {
      cout << "There are no elements to shufle." << endl;
      return;
   }
   if (first -> next == NULL)	{
	   Display();
	   return;
   }
   while ( traverse != NULL )    {
         traverse = traverse -> next;
		 n++;
   }
   traverse = first;
   for(int r=0; r <= n; r++)	{
      int indexVal1 = (rand() % n);
      int indexVal2 = (rand() % n);
      temp1 = first;
      temp2 = first;
      for (int i = 0; i <= indexVal1; i++)  {
			if (i == 0)	{
				temp1 = first;
			}
			else if (temp1 -> next == NULL)	{
				temp1 = temp1;
			}
			else {
				temp1 = temp1 -> next;
			}	
      }
      for (int j = 0; j <= indexVal2; j++)   {
			if (j == 0)	{
				temp2 = first;
			}
			else if (temp2 -> next == NULL)	{
				temp2 = temp2;
			}
			else {
			temp2 = temp2 -> next;
			}
      }
      ElementType t1 = temp1 -> data;
      ElementType t2 = temp2 -> data;
	  temp1 -> data = t2;
   	  temp2 -> data = t1;
   }
  
   Display();
}