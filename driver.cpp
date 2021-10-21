// -------------------------------------------------------
// File name: mainmenu.cpp
// Project name: Serendipity
// -------------------------------------------------------
// Creator's name and email: Lina Kang and DAL07065@gmail.com
// Course-Selection: CS 1B Ticket #14295
// Creation Date: 08/20/19
// Date of Last Modification: 10/20/19
// -------------------------------------------------------
// Purpose: a point-of-sale software package that will make the computer
//			function as a cash register and keep an inventory file
// -------------------------------------------------------
// Algorithm:
//  Step 1: Display the main menu and the options
//  Step 2: Allow the user the choose a desired option
//  Step 3: Guide the user to the desired option menu
// -------------------------------------------------------
//                     DATA DICTIONARY
// CONSTANTS
//
// NAME           DATA TYPE           INITIAL VALUE
// -------------  ------------------  --------------------
// DBSIZE         integer             20
//
//
// VARIABLES
//
// NAME           DATA TYPE           INITIAL VALUE
// -------------  ------------------  --------------------
// bookCount      integer             0
// choice         integer             null
// index          integer             null
// exitStatus     boolean             false
// bookTitle[]    array(string)       user input
// isbn[]         array(string)       user input
// author[]       array(string)       user input
// publisher[]    array(string)       user input
// dateAdded[]    array(string)       user input
// qtyOnHand[]    array(integer)      user input
// wholesale[]    array(double)       user input
// retail[]       array(double)       user input
#include "mainmenu.h"
#include "orderedLinkedList.h"
#include <fstream>

using namespace std;



int main()
{
	system("cls");


	int  choice;		 // user's input for a chosen option from menu
	bool exitStatus;     // status that becomes true when the user chooses
						 // 	the exit option which will end the do while loop
						 // 	thus terminating the program.

	linkedListIterator<bookType> it;
	orderedLinkedList<bookType> bookData;

	ifstream fin;
	ofstream fout;

	fin.open("databaseInput.txt");


	string title      = "EMPTY";
	string isbnStr    = "EMPTY";
	string authorStr  = "EMPTY";
	string publishStr = "EMPTY";
	string date       = "EMPTY";
	int qty = 0;
	double wholesaleDouble = 0.0;
	double retailDouble   = 0.0;

	while(!fin.eof())
	{
		getline(fin,title);
		getline(fin,isbnStr);
		getline(fin,authorStr);
		getline(fin,publishStr);
		getline(fin,date);
		fin >> qty;
		fin >> wholesaleDouble;
		fin >> retailDouble;
		fin.ignore(100, '\n');
		bookType *newBook = new bookType(title, isbnStr, authorStr, publishStr, date, qty, wholesaleDouble, retailDouble);
		bookData.insert(*newBook);
		bookType::incBookCount();
		delete newBook;

	}

	fin.close();
	//bookType *newBook = new bookType("title", "author", "d", "f", "c", 2, 2, 2);

	//bookData.insert(*newBook);
	//bookData.print();

//	bookType *newBook;
//	for(it = bookData.begin(); it != bookData.end(); ++it)
//	{
//		newBook = new bookType;
//		//newBook->setBookTitle("0");
//		bookData.insert(*newBook);
//		delete newBook;
//	}

	exitStatus = false;

	//run the menu until the user chooses to exit
	do
	{
		cout << "-----------------------------------------------------\n"
				"-                                                   -\n"
				"-        Serendipity Booksellers Main Menu          -\n"
				"-                                                   -\n"
				"-             1. Cashier Module                     -\n"
				"-             2. Inventory Database Module          -\n"
				"-             3. Report Module                      -\n"
				"-             4. Exit                               -\n"
				"-                                                   -\n"
				"-----------------------------------------------------\n"
				"Enter Your Choice: ";

		cin >> choice;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nPlease enter a number.\n\n";
			system("pause");
		}
		else if(choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1- 5.\n\n";
			system("pause");
		}
		else
		{
			system("cls");
			cin.ignore(10000, '\n');
			//do something based on the option chosen by the user
			switch(choice)
			{
				case 1:
					cashier(bookData);
					break;
				case 2:
					invmenu(bookData, it);
					break;
				case 3:
					reports(bookData);
					break;
				case 4:
					exitStatus = true;
					break;
			}

		}


	} while(!exitStatus);

	fout.open("database.txt");
	while(fout)
	{
		for(it = bookData.begin(); it != bookData.end(); ++it)
		{
			fout << (*it).getBookTitle() << endl <<
					(*it).getisbn()  << endl <<
					(*it).getAuthor()  << endl <<
					(*it).getPublisher() << endl <<
					(*it).getDateAdded() << endl <<
					(*it).getQty() << endl <<
					(*it).getWholesale() << endl <<
					(*it).getRetail() << endl;
		}
	}
	fout.close();

}
