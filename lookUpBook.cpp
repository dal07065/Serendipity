// -------------------------------------------------------
// File name: lookUpBook.cpp
// Project name: Serendipity
// -------------------------------------------------------
// Creator's name and email: Lina Kang and DAL07065@gmail.com
// Course-Selection: CS 1B Ticket #14295
// Creation Date: 08/20/19
// Date of Last Modification: 10/02/19
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

void lookUpBook(orderedLinkedList<bookType> &bookData, linkedListIterator<bookType> &it)
{
	system("cls");

	string userInput;
	int index;
	int i = 0;
	char choice;

	bool exitStatus1;
	bool exitStatus2;

	bool noBooksFound;

	noBooksFound = true;

	do
	{
		system("cls");

		cout << ">>> BOOK LOOK UP <<<\n"
				"Search: >";

		getline(cin, userInput);

		for(it = bookData.begin(); it != bookData.end(); ++it) //#
		{
			index = toUpper((*it).getBookTitle()).find(toUpper(userInput)); //#

			if(index != -1)
			{
				noBooksFound = false;

				cout << "\nRESULT>: "
					 << (*it).getBookTitle(); //#

				do
				{
					cout << "\nView this book record? (Y/N)>: ";

					cin.get(choice);
					cin.ignore(1000, '\n');

					if(toupper(choice) == 'Y')
					{
						cout << "\n";

						bookInfo((*it).getBookTitle(), //#
								 (*it).getisbn(),
								 (*it).getAuthor(),
								 (*it).getPublisher(),
								 (*it).getDateAdded(),
								 (*it).getQty(),
								 (*it).getWholesale(),
								 (*it).getRetail());

						cout << "\n";

						system("pause");

						index = i;

						exitStatus2 = false;

					}
					else if(toupper(choice) == 'N')
					{
						exitStatus2 = false;
					}
					if(toupper(choice) != 'Y' && toupper(choice) != 'N')
					{
						cout << "\nPlease input 'Y' or 'N'.\n\n";

						exitStatus2 = true;
					}

				} while(exitStatus2);
				break;
			}
			i++;
		}

		if(noBooksFound)
		{
			cout << "\n\nNo books were found.\n";

			do
			{
				cout << "\n\nLook up another book? (Y/N): ";
				cin.get(choice);
				cin.ignore(1000, '\n');

				if(toupper(choice) == 'Y')
				{
					exitStatus2 = false;
					exitStatus1 = true;
				}
				else if(toupper(choice) == 'N')
				{
					exitStatus2 = false;
					exitStatus1 = false;

					index = -1;
				}
				if(toupper(choice) != 'Y' && toupper(choice) != 'N')
				{
					cout << "\nPlease input 'Y' or 'N'.\n\n";
					exitStatus2 = true;
				}

			} while(exitStatus2);
		}
		else
		{
			do
			{
				cout << "\n\nIs this the book desired? (Y/N): ";
				cin.get(choice);
				cin.ignore(1000, '\n');

				if(toupper(choice) == 'Y')
				{
					exitStatus2 = false;
					exitStatus1 = false;
				}
				else if(toupper(choice) == 'N')
				{
					do
					{
						cout << "\n\nLook up another book? (Y/N): ";
						cin.get(choice);
						cin.ignore(1000, '\n');

						if(toupper(choice) == 'Y')
						{
							exitStatus2 = false;
							exitStatus1 = true;
						}
						else if(toupper(choice) == 'N')
						{
							exitStatus2 = false;
							exitStatus1 = false;

							index = -1;
						}
						if(toupper(choice) != 'Y' && toupper(choice) != 'N')
						{
							cout << "\nPlease input 'Y' or 'N'.\n\n";
							exitStatus2 = true;
						}

					} while(exitStatus2);
				}
				if(toupper(choice) != 'Y' && toupper(choice) != 'N')
				{
					cout << "\nPlease input 'Y' or 'N'.\n\n";
					exitStatus2 = true;
				}

			} while(exitStatus2);
		}

	} while(exitStatus1);
}

