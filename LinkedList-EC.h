/*
* Author: Katrina Rosemond   
* Due Date: 10/13/2017
* Assignment: Program #3.5 - Extra Credit List - Double Linked List Implementation
* File: LinkedList-EC.h
* Description: This file contains header linked list class.
*/
// **Header provided by: Brandon Long
// ** Edits made by: Katrina Rosemond

#define	LINKEDLIST_H

// #ifdef	__cplusplus
// extern "C" {
// #endif

#include<string>
using namespace std;


typedef string ElementType;

struct node
{
    ElementType data;
    node * next;
    node * prev;
};

class LinkedList {
public:
    LinkedList(); // Create an empty list
    bool Empty(); // Return true if the list is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
    void Delete(ElementType x); // If value x is in the list, remove x (all instances)
    void Display(); // Display the data values in the list
    void Sort(); // Sort the list of strings based on length (shortest to longest)
    double Average(); // Compute amd return the average string length for the strings in the list
    double Median(); // Compute and return the median string length for the strings in the list
    void Shuffle(); // Shuffle the strings in the list around

private:
    node * first; // Pointer
    node * last; //Pointer to the last node in the list
};