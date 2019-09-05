#include "linkedlist.h"
using namespace std;

template <class T>
class listaOrdenada : public linkedListType<T>
{
	public:
		bool search(const T& searchItem) const
		{
			bool found = false;
			node<T> *current;
			current = this->first;
			while (current != NULL && !found)
				if (current->info >= searchItem)
					found = true;
				else
					current = current->link;
			if (found)
				found = (current->info == searchItem); 
			return found;
		}
		
		void insert(const T& newItem)
		{
			node<T> *current; 
			node<T> *trailCurrent;
			node<T> *newNode; 
			bool found;
			newNode = new node<T>; 
			newNode->info = newItem; 
			newNode->link = NULL; 
			if (this->first == NULL) 
			{
				this->first = newNode;
				this->last = newNode;
				this->count++;
			}
			else
			{
				current = this->first;
				found = false;
				while (current != NULL && !found) 
					if (current->info >= newItem)
						found = true;
					else
					{
						trailCurrent = current;
						current = current->link;
					}
				if (current == this->first)
				{
					newNode->link = this->first;
					this->first = newNode;
					this->count++;
				}
				else
				{
					trailCurrent->link = newNode;
					newNode->link = current;
					if (current == NULL)
						this->last = newNode;
					this->count++;
				}
			}
		}
		
		void insertFirst(const T& newItem)
		{
			insert(newItem);
		}
		
		void insertLast(const T& newItem)
		{
			insert(newItem);
		}
		
		void deleteNode(const T& deleteItem)
		{
			node<T> *current;
			node<T> *trailCurrent;
			bool found;
			if (this->first == NULL)
				cout << "Cannot delete from an empty list." << endl;
			else
			{
				current = this->first;
				found = false;
				while (current != NULL && !found)
					if (current->info >= deleteItem)
						found = true;
					else
					{
						trailCurrent = current;
						current = current->link;
					}
				if (current == NULL)
					cout << "The item to be deleted is not in the list."
						 << endl;
				else
					if (current->info == deleteItem)
					{
						if (this->first == current) 
						{
							this->first = this->first->link;
							if (this->first == NULL)
								this->last = NULL;
							delete current;
						}
						else
						{
							trailCurrent->link = current->link;
							if (current == this->last)
								this->last = trailCurrent;
							delete current;
						}
						this->count--;
					}
					else 
						cout << "The item to be deleted is not in the "
						<< "list." << endl;
			}
		}
};
