//// -------------------------------------------------------
//// File name: editBook.cpp
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
//#include "mainmenu.h"
//
//void editBook(orderedLinkedList<bookType> &bookData)
//{
//	system("cls");
//
//	string userInput;
//
//	int index;
//
//	char choiceView;
//	int choiceInt;
//
//	string title;
//	string isbnStr;
//	string authorStr;
//	string publishStr;
//	string date;
//	int qty;
//	double wholesaleDouble;
//	double retailDouble;
//
//	linkedListIterator<bookType> newBook;
//
//	choiceView = '\0';
//	choiceInt  = 0;
//
//	do
//	{
//
//		newBook = lookUpBook(bookData);
//
////		linkedListIterator<bookType> it;
////
////		int i = 0;
////		//change the lookupBook function to return a book, not the index
////		for(it = bookData.begin(); it != bookData.end(); ++it) //#
////		{
////			if(index == i)
////			{
////				newBook = *it;
////				it = bookData.end();
////			}
////			i++;
////		}
//
//		title           = (*newBook).getBookTitle();
//		isbnStr         = (*newBook).getisbn();
//		authorStr       = (*newBook).getAuthor();
//		publishStr      = (*newBook).getPublisher();
//		date            = (*newBook).getDateAdded();
//		qty             = (*newBook).getQty();
//		wholesaleDouble = (*newBook).getWholesale();
//		retailDouble    = (*newBook).getRetail();
//
//		do
//		{
//			system("cls");
//
//			if(choiceInt == 9)
//			{
//				cout << "*Book edits have been saved to the database.*\n\n";
//			}
//
//			cout << "-------------------------------------------------------------------\n"
//					"-                     Serendipity Booksellers                     -\n"
//					"-                           Edit Book                             -\n"
//					"-                                                                 -\n"
//					"-                     Database Size: " << DBSIZE << " Current Book Count: " << bookType::getBookCount() << "     -\n"
//					"-                                                                 -\n";
//			cout << left;
//			cout << setw(40) << "- <1> Enter Book Title"              << "> --" << setw(22) << title      	   << "-\n"
//				 << setw(40) << "- <2> Enter ISBN"                    << "> --" << setw(22) << isbnStr    	   << "-\n"
//				 << setw(40) << "- <3> Enter Author"                  << "> --" << setw(22) << authorStr  	   << "-\n"
//				 << setw(40) << "- <4> Enter Publisher"               << "> --" << setw(22) << publishStr 	   << "-\n"
//				 << setw(40) << "- <5> Enter Date Added (mm/dd/yyyy)" << "> --" << setw(22) << date            << "-\n"
//				 << setw(40) << "- <6> Enter Quantity on Hand"        << "> --" << setw(22) << qty             << "-\n"
//				 << setw(40) << "- <7> Enter Wholesale Cost"          << "> --" << setw(22) << fixed << setprecision(2) << wholesaleDouble << "-\n"
//				 << setw(40) << "- <8> Enter Retail Price"            << "> --" << setw(22) << fixed << setprecision(2) << retailDouble    << "-\n";
//
//			cout << "- <9> Save Book to Database                                       -\n"
//				 << "- <0> Return to Inventory Menu                                    -\n"
//				 << "-                                                                 -\n"
//				 << "-------------------------------------------------------------------\n"
//				 << "       Choice <0-9>: ";
//
//			cin >> choiceInt;
//			cin.ignore(1000, '\n');
//
//			cout << "\n\n\n";
//
//			if(cin.fail())
//			{
//				cin.clear();
//				cin.ignore(10000, '\n');
//				cout << "\nPlease input a number.\n\n";
//				system("pause");
//			}
//			else
//			{
//				switch(choiceInt)
//				{
//					case 1:
//						cout << "       Book Title > ";
//						getline(cin, title);
//						break;
//					case 2:
//						cout << "       ISBN > ";
//						getline(cin, isbnStr);
//						break;
//					case 3:
//						cout << "       Author > ";
//						getline(cin, authorStr);
//						break;
//					case 4:
//						cout << "       Publisher > ";
//						getline(cin, publishStr);
//						break;
//					case 5:
//						cout << "       Date Added > ";
//						getline(cin, date);
//						break;
//					case 6:
//						cout << "       Quantity on Hand > ";
//						cin >> qty;
//						cin.ignore(1000, '\n');
//						break;
//					case 7:
//						cout << "       Wholesale Cost > ";
//						cin >> wholesaleDouble;
//						cin.ignore(1000, '\n');
//						break;
//					case 8:
//						cout << "       Retail Price > ";
//						cin >> retailDouble;
//						cin.ignore(1000, '\n');
//						break;
//					case 9:
//						(*newBook).setBookTitle(title);
//						(*newBook).setisbn(isbnStr);
//						(*newBook).setAuthor(authorStr);
//						(*newBook).setPublisher(publishStr);
//						(*newBook).setDateAdded(date);
//						(*newBook).setQty(qty);
//						(*newBook).setWholesale(wholesaleDouble);
//						(*newBook).setRetail(retailDouble);
//
//						break;
//				}
//			}
//		}while(choiceInt != 0);
//
//		cout << "\nEdit another book? <Y/N>: ";
//
//		cin.get(choiceView);
//
//		cin.ignore(1000, '\n');
//
//		system("cls");
//
//	} while(toupper(choiceView) == 'Y');
//}
//
//
//
//
