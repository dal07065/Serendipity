// -------------------------------------------------------
// File name: mainmenu.h
// Project name: Serendipity
// -------------------------------------------------------
// Creator's name and email: Lina Kang and DAL07065@gmail.com
// Course-Selection: CS 1B Ticket #14295
// Creation Date: 08/20/19
// Date of Last Modification: 10/28/19
// -------------------------------------------------------
// Purpose: a point-of-sale software package that will make the computer
//			function as a cash register and keep an inventory file
// -------------------------------------------------------
// Algorithm:
//  Step 1: Look up a book desired
//  Step 2: Interact with the user regarding the transaction
//  Step 3: Guide the user to the end of transaction
// -------------------------------------------------------
//                     DATA DICTIONARY
//
// VARIABLES
//
// NAME           DATA TYPE           INITIAL VALUE
// -------------  ------------------  --------------------
// quantity       integer             -
// subtotal       float               -
// total          float               -
// tax            float               -
// bookTitle[]    array(string)       user input
// isbn[]         array(string)       user input
// author[]       array(string)       user input
// publisher[]    array(string)       user input
// dateAdded[]    array(string)       user input
// qtyOnHand[]    array(integer)      user input
// wholesale[]    array(double)       user input
// retail[]       array(double)       user input
////////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include "orderedLinkedList.h"

using namespace std;

const int DBSIZE = 125;

class bookType
{
private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int    qtyOnHand;
	double wholesale;
	double retail;

	static int bookCount;

	static int compareCode;		// 0 - compare by qty
								// 1 - compare by wholesale cost
								// 2 - compare by date added
public:
	bookType();
	bookType(string b, string i, string a, string p, string d,
					   int q, double w, double r);
	bookType(const bookType &copyBook);

	void setBookTitle(string i) {bookTitle = i;}
	void setisbn(string i)      {isbn = i;}
	void setAuthor(string i)    {author = i;}
	void setPublisher(string i) {publisher = i;}
	void setDateAdded(string i) {dateAdded = i;}
	void setQty(int i)          {qtyOnHand = i;}
	void setWholesale(double i) {wholesale = i;}
	void setRetail(double i)    {retail = i;}

	static void setCompareCode(int i) {compareCode = i;}

	static void incBookCount() {bookCount++;}
	static void decBookCount() {bookCount--;}


	string getBookTitle() const {return bookTitle;}
	string getisbn()      const {return isbn;}
	string getAuthor()    const {return author;}
	string getPublisher() const {return publisher;}
	string getDateAdded() const {return dateAdded;}
	int    getQty()       const {return qtyOnHand;}
	double getWholesale() const {return wholesale;}
	double getRetail()    const {return retail;}

	static int getBookCount() {return bookCount;}

	bool operator<(const bookType& other) const;
	bool operator>(const bookType& other) const;
	bool operator<=(const bookType& other) const;
	bool operator>=(const bookType& other) const;
	bool operator==(const bookType& other) const;
	bool operator!=(const bookType& other) const;
	void operator=(const bookType& other);


};

void cashier(orderedLinkedList<bookType> &bookData);

void invmenu(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> &it);

void reports(orderedLinkedList<bookType> &bookData);

void bookInfo(string title, string isbn, string author, string publisher, string date, int qty, double wholesale, double retail);

void lookUpBook(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> &it);

void addBook(orderedLinkedList<bookType> &bookData);

void editBook(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> &it);

void deleteBook(orderedLinkedList<bookType> &bookData);

int lookForSameBook(bookType bookData[], bookType book, int i);

//int isEmpty(orderedLinkedList<bookType> &bookData, int index);

//bookType* nextEmpty(orderedLinkedList<bookType> &bookData);

void removeBook(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> newBook);

void repListing(orderedLinkedList<bookType> &bookData);
void repWholesale(orderedLinkedList<bookType> &bookData);
void repRetail(orderedLinkedList<bookType> &bookData);
void repQty(orderedLinkedList<bookType> &bookData);
void repCost(orderedLinkedList<bookType> &bookData);
void repAge(orderedLinkedList<bookType> &bookData);

//self-made functions for easier processing and readability
void reportsNavigation(int& i, bool& loopRunning, int& startingPoint);
string toUpper(string str);
void printDate();

//template <class U>
//void selectionSort(orderedLinkedList<U> &list, const int length)
//{
//	int index;
//	int smallestIndex;
//	int location;
//	U temp;
//
//	for(index = 0; index < length - 1; index++)
//	{
//		smallestIndex = index;
//		for(location = index + 1; location < length; location++)
//		{
//			if(list[location] > list[smallestIndex])
//			{
//				smallestIndex = location;
//			}
//		}
//		temp = list[smallestIndex];
//		list[smallestIndex] = list[index];
//		list[index] = temp;
//	}
//}



//template <class U>
//void insertionSort(orderedLinkedList<U> &list, const int length)
//{
//	//look at first item
//	//mark it sorted
//	//look at next item
//	//compare to the sorted list
//	//place in the correct spot
//	linkedListIterator<U> it;
//	for(it = list.begin(); it != list.end(); ++it)
//	{
//		if()
//	}
//}
