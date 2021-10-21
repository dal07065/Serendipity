//// -------------------------------------------------------
//// File name: cashier.cpp
//// Project name: Serendipity
//// -------------------------------------------------------
//// Creator's name and email: Lina Kang and DAL07065@gmail.com
//// Course-Selection: CS 1B Ticket #14295
//// Creation Date: 08/20/19
//// Date of Last Modification: 10/02/19
//// -------------------------------------------------------
//// Purpose: a point-of-sale software package that will make the computer
////			function as a cash register and keep an inventory file
//// -------------------------------------------------------
//// Algorithm:
////  Step 1: Look up a book desired
////  Step 2: Interact with the user regarding the transaction
////  Step 3: Guide the user to the end of transaction
//// -------------------------------------------------------
////                     DATA DICTIONARY
////
//// VARIABLES
////
//// NAME           DATA TYPE           INITIAL VALUE
//// -------------  ------------------  --------------------
//// quantity       integer             -
//// subtotal       float               -
//// total          float               -
//// tax            float               -
//// bookTitle[]    array(string)       user input
//// isbn[]         array(string)       user input
//// author[]       array(string)       user input
//// publisher[]    array(string)       user input
//// dateAdded[]    array(string)       user input
//// qtyOnHand[]    array(integer)      user input
//// wholesale[]    array(double)       user input
//// retail[]       array(double)       user input
//////////////////////////////////////////////////////////////////
//
#include "mainmenu.h"
//
void cashier(orderedLinkedList<bookType> &bookData)
{
	bool exitStatus1;     	// status that becomes true when the user chooses
						 	// 		the exit option which will end the do while loop
						 	// 		thus terminating the program.
	bool exitStatus2;     	// second exitStatus boolean variable for the sub-
							//		do-while loop within the pre-existing do-while loop
							//		in this function

	bool exitStatus3;     	// status that becomes true when the user chooses
 							// 		the exit option which will end the do while loop

	do
	{
		int quantity;			// quantity of books the user wish to purchase by user input
		float subtotal;			// total purchase amount before tax
		float total;			// total purchase amount after tax
		float tax;				// tax amount

		string date;			// date of the user's purchase by user input
		string isbn;			// isbn of the book by user input
		string title;			// title of the book by user input

		char choice;		 	// decision of the user to repeat the cashier module

		int purchaseIndex;

		bookType bookPurchase[DBSIZE];

		int   bookQty[DBSIZE]   = {0};
		int bookQtyChanged[DBSIZE] = {0};
		float subTotal[DBSIZE]  = {0};

		linkedListIterator<bookType> newBook;

		exitStatus1 = false;
		purchaseIndex = 0;
		subtotal = 0;
		total = 0;

		system("cls");

		lookUpBook(bookData, newBook);

		if(newBook != bookData.end())
		{
			do
			{
				cout << "\nIs this the book you want to PURCHASE? <Y/N>: ";
				char choiceEdit;
				cin.get(choiceEdit);
				cin.ignore(1000, '\n');

				if(toupper(choiceEdit) == 'Y')
				{
					do
					{
						cout << "\nHow many would you like to purchase?\n";
						cin >> quantity;
						cin.ignore(1000, '\n');

						if(cin.fail() || quantity < 0)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "\nPlease enter a valid number.\n\n";
							exitStatus3 = true;
							system("pause");
						}
						else if(quantity == 0)
						{
							exitStatus3 = false;
						}
						else if((*newBook).getQty() >= quantity)
						{
							cout << endl << (*newBook).getBookTitle() << " are available for purchase\n";
							cout << (*newBook).getBookTitle() << " has been added to cart!\n";

							int indexTemp = lookForSameBook(bookPurchase, *newBook, purchaseIndex);

//							bookIndex[indexTemp]    = index;

							subTotal[indexTemp]     += quantity * ((*newBook).getRetail());

							bookQty[indexTemp]      += quantity;

							int changedqty = (*newBook).getQty() - quantity;

							bookQtyChanged[indexTemp] = changedqty;

							bookPurchase[indexTemp] = *newBook;

							if(indexTemp == purchaseIndex)
								purchaseIndex++;

							exitStatus3 = false;
						}
						else if((*newBook).getQty() <  quantity)
						{
							cout << endl << (*newBook).getBookTitle() << " is NOT available enough for purchase.\n";
							exitStatus3 = false;
						}

					} while(exitStatus3);
				}
				else if(toupper(choiceEdit) != 'Y' && toupper(choiceEdit) != 'N')
				{
					cout << "\nPlease input 'Y' or 'N'.\n\n";
					exitStatus2 = true;
				}
				do
				{
					cout << "\nWould you like to make another purchase?(Y/N) :";
					cin.get(choice);
					cin.ignore(10000, '\n');

					if(toupper(choice) == 'Y')
					{
						exitStatus3 = false;
						exitStatus2 = true;

						lookUpBook(bookData, newBook);
					}
					if(toupper(choice) == 'N')
					{
						exitStatus3 = false;
						exitStatus2 = false;
					}
					else if(toupper(choice) != 'Y'&& toupper(choice) != 'N')
					{
						cout << "\nPlease input 'Y' or 'N'.\n\n";
						exitStatus3 = true;
					}

				} while(exitStatus3);

			}while (exitStatus2);

			system("cls");

			cout << "-----------------------------------"
					"-----------------------------------"
					"-----------------------------------\n";
			cout << left << endl
				 << "Serendipity Book Sellers\n\n"
				 //<< "Date: " << printDate() << endl << endl
				 << setw(5)  << "Qty "
				 << setw(14) << "ISBN"
				 << setw(59) << "Title"
				 << setw(11) << "Price"
				 << setw(10) << "Total"
				 << endl;

			cout << "-----------------------------------"
					"-----------------------------------"
					"-----------------------------------\n";

			//print as many books as user chose
			for(int i = 0; i < purchaseIndex; i++)
			{

				cout << left;
				cout << setw(5)  << bookQty[i]
					 << setw(14) << bookPurchase[i].getisbn()
					 << setw(59) << (bookPurchase[i].getBookTitle()).substr(0,57);

				cout << right;
				cout << "$" << setw(7) << fixed << setprecision(2) << bookPurchase[i].getRetail() << "  "
					 << "$" << setw(7) << fixed << setprecision(2) << subTotal[i] << "\n";

				subtotal += subTotal[i];

			}

			//Transaction Calculation

			tax  = subtotal * 0.06;
			total = subtotal + tax;

			cout << "\n\n\n";
			cout << right << setw(89) << "Subtotal: $" << right << setw(7) << subtotal << endl
				 << right << setw(89) << "Tax: $"      << right << setw(7) << fixed << setprecision(2) << tax   << endl
				 << right << setw(89) << "Total: $"    << right << setw(7) << fixed << setprecision(2) << total << endl;

			cout << "-----------------------------------"
					"-----------------------------------"
					"-----------------------------------\n";

			do
			{
				cout << "Confirm Purchase? <Y/N>\n\n";
				cin.get(choice);
				cin.ignore(10000, '\n');

				if(toupper(choice) == 'Y')
				{
					for(int i = 0; i < purchaseIndex; i++)
					{
//						index = bookIndex[i];

						//bookPurchase[i].setQty(bookQtyOriginal[i]);

						bookData.deleteNode(bookPurchase[i]);

						bookPurchase[i].setQty(bookQtyChanged[i]);


						bookData.insert(bookPurchase[i]);
					}
				}
				else if(toupper(choice) =='N')
				{
					exitStatus2 = false;
				}
				else if(toupper(choice) != 'Y'&& toupper(choice) != 'N')
				{
					cout << "\nPlease input 'Y' or 'N'.\n\n";

					exitStatus2 = true;
				}
				system("pause");

			} while(exitStatus2);
			do
									{
										cout << "\nWould you like to make another purchase? <Y/N>\n";
										cin.get(choice);
										cin.ignore(10000, '\n');

										if(toupper(choice) == 'N')
										{
											exitStatus3 = false;
											exitStatus1 = false;
										}
										else if(toupper(choice) =='Y')
										{
											exitStatus3 = false;
											exitStatus1 = true;
										}
										else if(toupper(choice) != 'Y'&& toupper(choice) != 'N')
										{
											cout << "\nPlease input 'Y' or 'N'.\n\n";

											exitStatus3 = true;
										}

									} while(exitStatus3);

		}
		system("cls");

	} while(exitStatus1);

}
