// -------------------------------------------------------
// File name: functions.cpp
// Project name: Serendipity
// -------------------------------------------------------
// Creator's name and email: Lina Kang and DAL07065@gmail.com
// Course-Selection: CS 1B Ticket #14295
// Creation Date: 08/20/19
// Date of Last Modification: 11/27/19
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
#include "mainmenu.h"
#include <ctime>
//#include <conio.h>

//These are for my own personal computer
//#define PAGE_DOWN 81
//#define PAGE_UP 73
//#define EXIT 27
//#define FIVE 63

//These are for lab computer
#define PAGE_DOWN 51
#define PAGE_UP 57
#define EXIT 27
#define FIVE 63

int lookForSameBook(bookType bookData[], bookType book, int length) //#
{
	int index;
	int i = 0;

	bool noSameBooksFound = true;

	for(int i = 0; i < length; i++) //#
	{
		if(book.getBookTitle() == bookData[i].getBookTitle()) //#
		{
			index = i;
			i = length;
			noSameBooksFound = false;
		}
		i++;
	}
	if(noSameBooksFound)
	{
		index = length;
	}

	return index;
}

void invmenu(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> &it)
{
	int  choice;		 // user's input for a chosen option from menu
	bool exitStatus;     // status that becomes true when the user chooses
						 // 	the exit option which will end the do while loop
						 // 	thus terminating the program.
	int index;

	exitStatus = true;

	//run the inventory database menu module until user chooses to exit
	do
	{
		cout << "-----------------------------------------------------\n"
				"-                                                   -\n"
				"-             Serendipity Booksellers               -\n"
				"-               Inventory Database                  -\n"
				"-                                                   -\n"
				"-             1. Look Up a Book                     -\n"
				"-             2. Add a Book                         -\n"
				"-             3. Edit a Book's Record               -\n"
				"-             4. Delete a Book                      -\n"
				"-             5. Return to the Main Menu            -\n"
				"-                                                   -\n"
				"-----------------------------------------------------\n"
				"Enter Your Choice: ";

		cin >> choice;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nPlease input a number.\n\n";
			system("pause");
		}
		else if(choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1- 5.\n\n";
			system("pause");
		}
		else
		{
			cin.ignore(10000, '\n');

			switch(choice)
			{
				case 1:
					lookUpBook(bookData, it);
					break;
				case 2:
					addBook(bookData);
					break;
				case 3:
					editBook(bookData, it);
					break;
				case 4:
					deleteBook(bookData);
					break;
				case 5:
					exitStatus = false;
					break;
			}
		}
		system("cls");

	} while(exitStatus);

}

void reports(orderedLinkedList<bookType> &bookData)
{
	int  choice;		 // user's input for a chosen option from menu
	bool exitStatus;     // status that becomes true when the user chooses
						 // 	the exit option which will end the do while loop
						 // 	thus terminating the program.

	exitStatus = true;

	//run the reports menu module until user chooses to exit
	do
	{
		cout << "-----------------------------------------------------\n"
				"-                                                   -\n"
				"-             Serendipity Booksellers               -\n"
				"-                    Reports                        -\n"
				"-                                                   -\n"
				"-             1. Inventory Listing                  -\n"
				"-             2. Inventory Wholesale Value          -\n"
				"-             3. Inventory Retail Value             -\n"
				"-             4. Listing by Quantity                -\n"
				"-             5. Listing by Cost                    -\n"
				"-             6. Listing by Age                     -\n"
				"-             7. Return to Main Menu                -\n"
				"-                                                   -\n"
				"-----------------------------------------------------\n"
				"Enter Your Choice: ";

		cin >> choice;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nPlease input a number.\n\n";
			system("pause");
		}
		else if(choice < 1 || choice > 7)
		{
			cout << "\nPlease enter a number in the range 1- 7.\n\n";
			system("pause");
		}
		else
		{
			//do something based on the option chosen by the user
			switch(choice)
			{
				case 1:
					repListing(bookData);
					break;
				case 2:
					repWholesale(bookData);
					break;
				case 3:
					repRetail(bookData);
					break;
				case 4:
					repQty(bookData);
					break;
				case 5:
					repCost(bookData);
					break;
				case 6:
					repAge(bookData);
					break;
				case 7:
					exitStatus = false;
					break;
				default:
					cout << "\nPlease enter a number in the range 1- 7.\n\n";
					system("pause");
					break;
			}
		}
		system("cls");

	} while(exitStatus);
}
//int isEmpty(orderedLinkedList<bookType> &bookData, int index) //#
//{
//	int i = 0;
//	string title;
//	linkedListIterator<bookType> it;
//
//	for(it = bookData.begin(); it != bookData.end(); ++it) //#
//	{
//		if(i == index)
//		{
//			title = (*it).getBookTitle();
//			it = bookData.end();
//		}
//		i++;
//	}
//
//	if(title == "0")
//	{
//		i = 1;
//	}
//	else
//	{
//		i = 0;
//	}
//	return i;
//}
//bookType* nextEmpty(orderedLinkedList<bookType> &bookData)
//{
//	int i = 0;
//	string title;
//	linkedListIterator<bookType> it;
//	bookType *book;
//	for(it = bookData.begin(); it != bookData.end(); ++it) //#
//	{
//		if((*it).getBookTitle() == "0")
//		{
//			return (*it);
//			it = bookData.end();
//		}
//		i++;
//	}
//	return book;
//}
void removeBook(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> newBook)
{
	bookData.deleteNode(*newBook);
	/*
	int i = 0;
	linkedListIterator<bookType> it;

	bookType *newBook = nullptr;

	for(it = bookData.begin(); it != bookData.end(); ++it) //#
	{
		if(index == i)
		{
			(*it).setBookTitle("0");
			it = bookData.end();
		}
		i++;
	}
	*/
}

//toupper function but works with strings instead of individual char
string toUpper(string str)
{
	char strNew[str.length() + 1];

	strcpy(strNew, str.c_str());

	int length = strlen(strNew);

	for(int i = 0; i < length; i++)
	{
		strNew[i] = toupper(strNew[i]);
	}

	string strReturn(strNew);

	return strReturn;
}
/*
void reportsNavigation(int& i, bool& loopRunning, int& startingPoint)
{
	bool inputLoop = true;

	while(inputLoop)
	{
		cout << "Press: \n"
				" - PgDn for Next Page\n"
				" - PgUp for Previous Page\n"
				" - ESC to return to menu\n"
				" - F5 to jump to a certain page\n";

		int c = 0;

		switch((c=getch()))
		{
			case PAGE_DOWN:
			{
				if(i == bookType::getBookCount())
				{
					i = 0;
				}
				inputLoop = false;
				break;
			}
			case PAGE_UP:
			{
				if(i == 10 || i < 10)
				{
					bool correctPageNumber = true;

					i = bookType::getBookCount();

					while(correctPageNumber)
					{
						if(i % 10 == 0)
						{
							correctPageNumber = false;
							i = i - 10;
						}
						else
						{
							i--;
						}
					}
				}
				else
				{
					if(i%10 == 0)
					{
						i = i - 20;
					}
					else
					{
						i = startingPoint - 10;
					}
				}
				inputLoop = false;

				break;
			}
			case EXIT:
			{
				inputLoop = false;
				loopRunning = false;
				break;
			}
			case FIVE:
			{
				int pageNum = 0;
				bool exitStatus = true;
				//write code to jump to a page
				while(exitStatus)
				{
					cout << "\nWhich page would you like to go? : ";
					cin  >> pageNum;
					//56 books
					if(pageNum > bookType::getBookCount()/10 || pageNum <= 0)
					{
						cout << "Please input a number within the range of "
								"1 - " << bookType::getBookCount()/10 << endl;
					}
					else
					{
						i = (pageNum-1) * 10;
						startingPoint = (pageNum-1) * 10;
						exitStatus = false;
						inputLoop = false;
					}
				}
				break;
			}
			default:
			{
				inputLoop = false;
				i = startingPoint;
			}
		}
	}
}*/
void printDate()
{
    //Author: anon and milleniumbug
	//https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

	time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '/'
         << (now->tm_mon + 1) << '/'
         <<  now->tm_mday;
}
