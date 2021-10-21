// -------------------------------------------------------
// File name: repListing.cpp
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
//  Step 1: Display the main menu and the options
//  Step 2: Allow the user the choose a desired option
//  Step 3: Guide the user to the desired option menu
// -------------------------------------------------------
//                     DATA DICTIONARY
// VARIABLES
//
// NAME           DATA TYPE           INITIAL VALUE
// -------------  ------------------  --------------------
// loopRunning    integer             0
// i              integer             null
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

void repListing(orderedLinkedList<bookType> &bookData)
{
	system("cls");

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	linkedListIterator<bookType> it;

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}

	while(loopRunning)
	{

	currpg = i/10 + 1;

	cout << "---------------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                                   -\n"
			"-                                                    Report Listing                                                             -\n"
			"- Date: "; printDate(); cout << " Page: " << left << currpg << " of " << setw(2) << endpg << setw(43) << " " <<
			" Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << "-\n"
			"-                                                                                                                               -\n"
			"- Title                          ISBN         Author         Publisher    Date Added   Qty O/H   Wholesale Cost   Retail Price  -\n"
			"- ----------------------------------------------------------------------------------------------------------------------------- -\n";

	for(int j = 0; j < 10; j++)
	{

		if(j == 0)
		{
			startingPoint = i;
		}

		cout << "- "
			 << setw(29) << (bookTemp[i].getBookTitle()).substr(0,29) << "  "
			 << setw(11) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(13) << (bookTemp[i].getAuthor()).substr(0,13)    << "  "
			 << setw(11) << (bookTemp[i].getPublisher()).substr(0,11) << "  "
			 << setw(11) << (bookTemp[i].getDateAdded()).substr(0,11) << "  "
			 << setw(9)  << (bookTemp[i].getQty())       << " ";

		cout << right;
		cout << "$" << setfill('.') << setw(13);
		cout << bookTemp[i].getWholesale() << "   ";
		cout << "$" << setfill('.') << setw(12);
		cout << (bookTemp[i].getRetail()) << setfill(' ') << setw(1) << " -\n";
		cout << left;

		cout << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}

	}

	cout << "--------------------------------------------------------------"
			"-------------------------------------------------------------------\n";

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");
	}

}

void repWholesale(orderedLinkedList<bookType> &bookData)
{

	system("cls");

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	linkedListIterator<bookType> it;

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}

	while(loopRunning)
	{
		currpg = i/10 + 1;

	cout << "-------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                           -\n"
			"-                                               Report Wholesale Listing                                                -\n"
			"- Date: "; printDate(); cout << " Page: " << left << currpg << " of " << setw(2) << endpg << setw(43) << " " <<
			" Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << "-\n"
			"-                                                                                                                       -\n"
			"- Title                                     ISBN                      Qty O/H              Wholesale Cost               -\n"
			"- --------------------------------------------------------------------------------------------------------------------- -\n";


	for(int j = 0; j < 10; j++)
	{

		if(j == 0)
		{
			startingPoint = i;
		}

		cout << "- "
			 << setw(40) << (bookTemp[i].getBookTitle()).substr(0,40) << "  "
			 << setw(24) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(19) << (bookTemp[i].getQty())                    << "  ";

		cout << right;
		cout << "$" << setfill('.') << setw(13);
		cout << bookTemp[i].getWholesale() << setfill(' ') << setw(17) << "-\n";
		cout << left;

		cout << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}

	}

	cout << "--------------------------------------------------------------"
			"--------------------------------------------------------- -\n";

	if(currpg == endpg)
	{
		double total = 0;

		for(int m = 0; m < bookType::getBookCount(); m++)
		{
			total += (bookTemp[m].getWholesale() * bookTemp[m].getQty());
		}

		cout << "- Total Wholesale Value: " << total << endl << endl;
	}

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");
	}

}
void repRetail(orderedLinkedList<bookType> &bookData)
{
	system("cls");

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	linkedListIterator<bookType> it;

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}

	while(loopRunning)
	{
		currpg = i/10 + 1;

	cout << "-------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                           -\n"
			"-                                                 Report Retail Listing                                                 -\n"
			"- Date: "; printDate(); cout << " Page: " << left << currpg << " of " << setw(2) << endpg << setw(43) << " " <<
			"- Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << 					"-\n"
			"- Title                                     ISBN                      Qty O/H              Retail Cost                  -\n"
			"- --------------------------------------------------------------------------------------------------------------------- -\n";


	for(int j = 0; j < 10; j++)
	{
		if(j == 0)
		{
			startingPoint = i;
		}
		cout << "- "
			 << setw(40) << (bookTemp[i].getBookTitle()).substr(0,40) << "  "
			 << setw(24) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(19) << (bookTemp[i].getQty())                    << "  ";

		cout << right;
		cout << "$" << setfill('.') << setw(14);
		cout << bookTemp[i].getRetail() << setfill(' ') << setw(16) << " -\n";
		cout << left;

		cout << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}
	}

	cout << "--------------------------------------------------------------"
			"--------------------------------------------------------- -\n";

	if(currpg == endpg)
	{
		double total = 0;

		for(int m = 0; m < bookType::getBookCount(); m++)
		{
			total += (bookTemp[m].getRetail() * bookTemp[m].getQty());
		}

		cout << "- Total Retail Value: " << total << endl << endl;
	}

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");

	}
}


void repQty(orderedLinkedList<bookType> &bookData)
{
	system("cls");

	linkedListIterator<bookType> it;
	orderedLinkedList<bookType> copy;
	bookType *newBook = nullptr;

	bookType::setCompareCode(0);
	//making a new sorted ordered linked bookData and leaving the original bookData unchanged
	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		newBook = new bookType(*it);
		copy.insert(*newBook);
		delete newBook;
	}

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	//newBook->setCompareCode(0);
	//bookData.selectionSort();

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}

	while(loopRunning)
	{
		currpg = i/10 + 1;

	cout << "-------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                           -\n"
			"-                                               Report Quantity Listing                                                 -\n"
			"- Date: "; printDate(); cout << "     Page: " << left << currpg << " of " << setw(2) << endpg << setw(33) << " " <<
			" Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << "-\n"
			"- Title                                     ISBN                      Qty O/H                                           -\n"
			"- --------------------------------------------------------------------------------------------------------------------- -\n";


	for(int j = 0; j < 10; j++)
	{
		if(j == 0)
		{
			startingPoint = i;
		}
		cout << "- "
			 << setw(40) << (bookTemp[i].getBookTitle()).substr(0,40) << "  "
			 << setw(24) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(48) << (bookTemp[i].getQty())                    << "  ";

		cout << "-" << endl << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}
	}

	cout << "--------------------------------------------------------------"
			"--------------------------------------------------------- -\n";

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");

	}

	//destroy the bookData to prevent memoryleak

	copy.destroyList();
}
void repCost(orderedLinkedList<bookType> &bookData)
{

	system("cls");

	linkedListIterator<bookType> it;
	orderedLinkedList<bookType> copy;
	bookType *newBook = nullptr;

	bookType::setCompareCode(1);
	//making a new sorted ordered linked bookData and leaving the original bookData unchanged
	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		newBook = new bookType(*it);
		copy.insert(*newBook);
		delete newBook;
	}

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	//newBook->setCompareCode(1);
	//bookData.selectionSort();

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}

	while(loopRunning)
	{
		currpg = i/10 + 1;

	cout << "-------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                           -\n"
			"-                                                  Report Cost Listing                                                  -\n"
			"- Date: "; printDate(); cout << " Page: " << left << currpg << " of " << setw(2) << endpg << setw(43) << " " <<
			" Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << "-\n"
			"-                                                                                                                       -\n"
			"- Title                                     ISBN                      Qty O/H              Wholesale Cost               -\n"
			"- --------------------------------------------------------------------------------------------------------------------- -\n";


	for(int j = 0; j < 10; j++)
	{

		if(j == 0)
		{
			startingPoint = i;
		}

		cout << "- "
			 << setw(40) << (bookTemp[i].getBookTitle()).substr(0,40) << "  "
			 << setw(24) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(19) << (bookTemp[i].getQty())                    << "  ";

		cout << right;
		cout << "$" << setfill('.') << setw(13);
		cout << bookTemp[i].getWholesale() << setfill(' ') << setw(17) << "-\n";
		cout << left;

		cout << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}

	}

	cout << "--------------------------------------------------------------"
			"--------------------------------------------------------- -\n";

	if(currpg == endpg)
	{
		double total = 0;

		for(int m = 0; m < bookType::getBookCount(); m++)
		{
			total += (bookTemp[m].getWholesale() * bookTemp[m].getQty());
		}

		cout << "- Total Wholesale Value: " << total << endl << endl;
	}

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");
	}

}
void repAge(orderedLinkedList<bookType> &bookData)
{
	system("cls");

	linkedListIterator<bookType> it;
	orderedLinkedList<bookType> copy;
	bookType *newBook = nullptr;

	bookType::setCompareCode(2);
	//making a new sorted ordered linked bookData and leaving the original bookData unchanged
	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		newBook = new bookType(*it);
		copy.insert(*newBook);
		delete newBook;
	}

	bool loopRunning = true;

	int i = 0;

	int currpg = 0;
	int endpg = (bookType::getBookCount()/10);

	int startingPoint = 0;

	//newBook->setCompareCode(2);
	//bookData.selectionSort();

	bookType bookTemp[DBSIZE];

	for(it = bookData.begin(); it != bookData.end(); ++it)
	{
		bookTemp[i] = bookType(*it);
	}


	while(loopRunning)
	{
		currpg = i/10 + 1;

	cout << "-------------------------------------------------------------------------------------------------------------------------\n"
			"-                                           Serendipity Booksellers Main Menu                                           -\n"
			"-                                               Report Date Added Listing                                               -\n"
			"- Date: "; printDate(); cout << "     Page: " << left << currpg << " of " << setw(2) << endpg << setw(33) << " " <<
			" Database Size: " << DBSIZE << "  Current Book Count: " << setw(5) << bookType::getBookCount() << "-\n"
			"-                                                                                                                       -\n"
			"- Title                                     ISBN                      Qty O/H              Date Added                   -\n"
			"- --------------------------------------------------------------------------------------------------------------------- -\n";


	for(int j = 0; j < 10; j++)
	{

		if(j == 0)
		{
			startingPoint = i;
		}

		cout << "- "
			 << setw(40) << (bookTemp[i].getBookTitle()).substr(0,40) << "  "
			 << setw(24) << (bookTemp[i].getisbn()).substr(0,11)      << "  "
			 << setw(19) << (bookTemp[i].getQty())                    << "  "
			 << setw(29) << (bookTemp[i].getDateAdded())              << "-\n";

		cout << endl;

		i++;

		if(i == bookType::getBookCount())
		{
			j = 10;
			//end this for loop if there are less than 10 books in the database
		}

	}

	cout << "--------------------------------------------------------------"
			"--------------------------------------------------------- -\n";

	reportsNavigation(i, loopRunning, startingPoint);

	system("cls");
	}

}
