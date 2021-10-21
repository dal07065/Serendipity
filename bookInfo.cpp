// -------------------------------------------------------
// File name: bookInfo.cpp
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

void bookInfo(string title, string isbn, string author,
			  string publisher, string date, int qty,
			  double wholesale, double retail)
{
	cout << "---------------------------------\n"
			"     Serendipity Booksellers\n"
			"     Book Information\n"
			"---------------------------------\n\n";
	cout << "Title:            " << title     << "\n" <<
			"ISBN:             " << isbn      << "\n" <<
			"Author:           " << author    << "\n" <<
			"Publisher:        " << publisher << "\n" <<
			"Date Added:       " << date      << "\n" <<
			"Quantity-On-Hand: " << qty       << "\n" <<
			"Wholesale Cost:   " << wholesale << "\n" <<
			"Retail Price:     " << retail    << "\n" <<
			"---------------------------------\n";
}
