#include "dualList.h"
using namespace std;

bool dualList::list_in_list(dualList* list_what)
{
	Node* what_current = head;
	for (Node* where_current = head; where_current != tail; where_current = where_current->next)
	{
		if (where_current->content == list_what->head->content)
		{
			Node* start = where_current;
			while (where_current->content == what_current->content)
			{
				if (what_current == list_what->tail)
					return true;
				if (where_current == tail)
					return false;
				where_current = where_current->next;
				what_current = what_current->next;
			}
			where_current = start->next;
			what_current = list_what->head;
		}
	}
	return false;
}

void dualList::push_back(int add)
{
	if (size == 0) //if list is empty
	{
		head = new Node(add); //create head
		tail = head;
	}
	else
	{
		Node* curr = new Node(add);
		curr->before = tail;
		tail->next = curr;
		tail = curr;  //set new tail
	}
	size++;
}

void dualList::push_front(int add)
{
	if (size == 0)
	{
		head = new Node(add);
		tail = head;
	}
	else
	{
		Node* curr = new Node(add);
		curr->next = head;
		head->before = curr;
		head = curr;  //set new head
	}
	size++;
}

size_t dualList::get_size()
{
	return size;
}

void dualList::pop_back()
{
	if (size == 1)
	{
		size = 0;  //setup zero position
		head = NULL;
		tail = NULL;
	}
	else if (size > 1) //if list is not empty
	{
		tail = tail->before; //set new tail
		delete tail->next;
		tail->next = NULL;
		size--;
	}
	else  //else return error
		throw out_of_range("Segmentation fault");
}

void dualList::pop_front()
{
	if (size == 1)
	{
		size = 0;  //setup zero position
		head = NULL;
		tail = NULL;
	}
	else if (size > 1) //if list is not empty
	{
		head = head->next; //set new head
		delete head->before;
		head->before = NULL;
		size--;
	}
	else //else return error
		throw out_of_range("Segmentation fault");
}

void dualList::remove(size_t i)
{
	if (i >= size) //if index is larger than size return error
		throw out_of_range("Index is greater than list size");
	else if (i == 0) // if index points to first
		pop_front();
	else if (i == size - 1)	 // if index points to first
		pop_back();
	else
	{
		Node* cur = head;
		while (i) //go to "i" item
		{
			cur = cur->next;
			i--;
		}
		cur->before->next = cur->next; //cut item from list
		size--;
		delete cur;
	}
}

int dualList::at(size_t i)
{
	if (i >= size) //if index is larger than size return error
		throw out_of_range("Index is greater than list size");
	else
	{
		Node* cur = head;
		while (i) //go to "i" item
		{
			cur = cur->next;
			i--;
		}
		return cur->content;
	}
}

void dualList::insert(int add, size_t i)
{
	if (i >= size)  //if index is larger than size return error
		throw out_of_range("Index is greater than list size");
	else if (i == 0) //if insert before first item
		push_front(add);
	else
	{
		Node* cur = head;
		while (i)
		{
			cur = cur->next;
			i--;
		}
		Node* nadd = new Node(add, cur->before, cur);  //create new Node with new connection
		cur->before->next = nadd; //add poin to new Node
		cur->before = nadd;
		size++;
	}
}

void dualList::print_to_console()
{
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->content << "| ";
		cur = cur->next;
	}
}

void dualList::clear()
{
	if (head != NULL)
	{
		while (head->next != NULL)  //delete all item
		{
			head = head->next;
			delete head->before;
		}
		size = 0;  //setup zero position
		head = NULL;
		tail = NULL;
	}
}

void dualList::set(size_t i, int ins)
{
	if (i >= size) //if index is larger than size return error
		throw out_of_range("Index is greater than list size");
	else {
		Node* cur = head;
		while (i) //go to "i" item
		{
			cur = cur->next;
			i--;
		}
		cur->content = ins; //change content
	}
}

bool dualList::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}