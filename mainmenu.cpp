// -------------------------------------------------------
// File name: bookType.h
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

int bookType::bookCount = 0;
int bookType::compareCode = 0;

bookType::bookType()
{
	bookTitle = "0";
	isbn = "0";
	author = "0";
	publisher = "0";
	dateAdded = "0";
	qtyOnHand = 0;
	wholesale = 0;
	retail = 0;
//	compareCode = 0;
}

bookType::bookType(string b, string i, string a, string p, string d,
					   int q, double w, double r)
{
	bookTitle = b;
	isbn = i;
	author = a;
	publisher = p;
	dateAdded = d;
	qtyOnHand = q;
	wholesale = w;
	retail = r;
//	compareCode = 0;
}
bookType::bookType(const bookType& copyBook)
{
	bookTitle = copyBook.getBookTitle();
	isbn = copyBook.getisbn();
	author = copyBook.getAuthor();
	publisher = copyBook.getPublisher();
	dateAdded = copyBook.getDateAdded();
	qtyOnHand = copyBook.getQty();
	wholesale = copyBook.getWholesale();
	retail = copyBook.getRetail();
//	compareCode = 0;
}
bool bookType::operator==(const bookType& other) const
{
	bool boolean = false;
	if(getBookTitle() == other.getBookTitle() &&
	   getisbn() == other.getisbn() &&
	   getAuthor() == other.getAuthor() &&
	   getPublisher() == other.getPublisher() &&
	   getDateAdded() == other.getDateAdded() &&
	   getQty() == other.getQty() &&
	   getWholesale() == other.getWholesale() &&
	   getRetail() == other.getRetail())
	{
		boolean = true;
	}
	return boolean;
}
bool bookType::operator<(const bookType& other) const
{
	bool boolean = false;

	switch(compareCode)
	{
	case 0:
		boolean = getQty() < other.getQty();
		break;
	case 1:
		boolean = getWholesale() < other.getWholesale();
		break;
	case 2:
	{
		string date = getDateAdded();

		string dateOther = other.getDateAdded();

		//04/23/2008 < 01/01/2001

		int month = stoi(date.substr(0,2));
		int monthOther = stoi(dateOther.substr(0,2));

		int day = stoi(date.substr(3,2));
		int dayOther = stoi(dateOther.substr(3,2));

		int year = stoi(date.substr(6,4));
		int yearOther = stoi(dateOther.substr(6,4));

		if(year < yearOther)
		{
			boolean = false;
		}
		else if(year > yearOther)
		{
			boolean = true;
		}
		else if(year == yearOther)
		{
			if(month < monthOther)
			{
				boolean = false;
			}
			else if(month > monthOther)
			{
				boolean = true;
			}
			else if(month == monthOther)
			{
				if(day < dayOther)
				{
					boolean = false;
				}
				else if(day > dayOther)
				{
					boolean = true;
				}
				else if(day == dayOther)
				{
					boolean = true;
				}
			}
		}
		break;
	}
	}
	return boolean;
}

//this one
bool bookType::operator>(const bookType& other) const
{
	bool boolean;

	switch(compareCode)
	{
	case 0:
		boolean = getQty() > other.getQty();
		break;
	case 1:
		boolean = getWholesale() > other.getWholesale();
		break;
	case 2:
		string date = getDateAdded();

		string dateOther = other.getDateAdded();

		//04/23/2008 > 01/01/2001

		int month = stoi(date.substr(0,2));
		int monthOther = stoi(dateOther.substr(0,2));

		int day = stoi(date.substr(3,2));
		int dayOther = stoi(dateOther.substr(3,2));

		int year = stoi(date.substr(6,4));
		int yearOther = stoi(dateOther.substr(6,4));


		if(year > yearOther)
		{
			boolean = false;
		}
		else if(year < yearOther)
		{
			boolean = true;
		}
		else if(year == yearOther)
		{
			if(month > monthOther)
			{
				boolean = false;
			}
			else if(month < monthOther)
			{
				boolean = true;
			}
			else if(month == monthOther)
			{
				if(day > dayOther)
				{
					boolean = false;
				}
				else if(day < dayOther)
				{
					boolean = true;
				}
				else if(day == dayOther)
				{
					boolean = true;
				}
			}
		}

		break;
	}
	return boolean;
}
bool bookType::operator<=(const bookType& other) const
{
	bool boolean = false;

	switch(compareCode)
	{
	case 0:
		boolean = getQty() <= other.getQty();
		break;
	case 1:
		boolean = getWholesale() <= other.getWholesale();
		break;
	case 2:
		string date = getDateAdded();

		string dateOther = other.getDateAdded();

		//04/23/2008 <= 01/01/2001

		int month = stoi(date.substr(0,2));
		int monthOther = stoi(dateOther.substr(0,2));

		int day = stoi(date.substr(3,2));
		int dayOther = stoi(dateOther.substr(3,2));

		int year = stoi(date.substr(6,4));
		int yearOther = stoi(dateOther.substr(6,4));

		if(year < yearOther)
		{
			boolean = false;
		}
		else if(year > yearOther)
		{
			boolean = true;
		}
		else if(year == yearOther)
		{
			if(month < monthOther)
			{
				boolean = false;
			}
			else if(month > monthOther)
			{
				boolean = true;
			}
			else if(month == monthOther)
			{
				if(day < dayOther)
				{
					boolean = false;
				}
				else if(day > dayOther)
				{
					boolean = true;
				}
				else if(day == dayOther)
				{
					boolean = true;
				}
			}
		}
		break;
	}
	return boolean;
}
bool bookType::operator>=(const bookType& other) const
{
	bool boolean = false;

	switch(compareCode)
	{
	case 0:
		boolean = getQty() >= other.getQty();
		break;
	case 1:
		boolean = getWholesale() >= other.getWholesale();
		break;
	case 2:
		string date = getDateAdded();

		string dateOther = other.getDateAdded();

		//04/23/2008 >= 01/01/2001

		int month = stoi(date.substr(0,2));
		int monthOther = stoi(dateOther.substr(0,2));

		int day = stoi(date.substr(3,2));
		int dayOther = stoi(dateOther.substr(3,2));

		int year = stoi(date.substr(6,4));
		int yearOther = stoi(dateOther.substr(6,4));

		if(year > yearOther)
		{
			boolean = false;
		}
		else if(year < yearOther)
		{
			boolean = true;
		}
		else if(year == yearOther)
		{
			if(month > monthOther)
			{
				boolean = false;
			}
			else if(month < monthOther)
			{
				boolean = true;
			}
			else if(month == monthOther)
			{
				if(day > dayOther)
				{
					boolean = false;
				}
				else if(day < dayOther)
				{
					boolean = true;
				}
				else if(day == dayOther)
				{
					boolean = true;
				}
			}
		}
		break;
	}
	return boolean;
}
bool bookType::operator!=(const bookType& other) const
{
	bool boolean = false;
	if(getBookTitle() != other.getBookTitle() &&
	   getisbn() != other.getisbn() &&
	   getAuthor() != other.getAuthor() &&
	   getPublisher() != other.getPublisher() &&
	   getDateAdded() != other.getDateAdded() &&
	   getQty() != other.getQty() &&
	   getWholesale() != other.getWholesale() &&
	   getRetail() != other.getRetail())
	{
		boolean = true;
	}
	return boolean;
}
void bookType::operator=(const bookType& other)
{
	setBookTitle(other.getBookTitle());
	setisbn(other.getisbn());
	setAuthor(other.getAuthor());
	setPublisher(other.getPublisher());
	setDateAdded(other.getDateAdded());
	setQty(other.getQty());
	setWholesale(other.getWholesale());
	setRetail(other.getRetail());

}
