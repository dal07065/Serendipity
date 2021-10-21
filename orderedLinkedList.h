#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
  using linkedListType<Type>::first;
  using linkedListType<Type>::last;
  using linkedListType<Type>::count;

public:
	bool search(const Type& searchItem) const;
	void insert(const Type& newItem);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
	void selectionSort();

};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type> *current;

	current = first;

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;
	if (found)
		found = (current->info == searchItem);

	return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent = nullptr;
	nodeType<Type> *newNode;

	bool found;

	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = nullptr;

	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		current = first;
		found = false;

		while (current != nullptr && !found)
			if (current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		if (current == first)
		{
			newNode->link = first;
			first = newNode;
			count++;
		}
		else
		{
			trailCurrent->link = newNode;
			newNode->link = current;

			if (current == nullptr)
				last = newNode;
			count++;
		}
	}
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent = nullptr;
	bool found;

	if (first == nullptr)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = first;
		found = false;

		while (current != nullptr && !found)
		{
			if (current->info.getBookTitle() == deleteItem.getBookTitle())
			{
				found = true;
				cout << deleteItem.getBookTitle() << " has been found.\n";
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if(found)
		{
			if (first == current)
			{
				first = first->link;
				if (first == nullptr)
					last = nullptr;
				cout << current->info.getBookTitle() << " has been deleted.\n";

				delete current;
			}
			else
			{
				trailCurrent->link = current->link;
				if (current == last)
					last = trailCurrent;
				cout << current->info.getBookTitle() << " has been deleted.\n";

				delete current;
			}

			count--;
		}
		else
			cout << "The item to be deleted is not in the list. last else" << endl;
	}
}
template <class Type>
void orderedLinkedList<Type>::selectionSort()
{
	nodeType<Type> *temp = first;

    // Traverse the List
    while (temp)
    {
    	nodeType<Type> *min = temp;
    	nodeType<Type> *r   = temp->next;

        // Traverse the unsorted sublist
        while (r)
        {
            if (min->data > r->data)
                min = r;

            r = r->next;
        }

        // Swap Data
        Type x     = new Type(temp->data);
        temp->data = min->data;
        min->data  = x;
        temp = temp->next;
    }
}
#endif /* ORDEREDLINKEDLIST_H_ */
