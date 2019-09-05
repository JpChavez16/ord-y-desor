#include "linkedlist.h"
using namespace std;

template <class T>
class listaDesordenada : public linkedListType<T>
{
	public:
		bool search(const T& searchItem) const 
		{
				node<T> *current; 
				bool found = false;
				current = this->first;
				while (current != NULL && !found)
				if (current->info == searchItem)
				found = true;
				else
					current = current->link;
				return found;
		}
		
		void insertFirst(const T& newItem)
		{
			node<T> *newNode;
			newNode = new node<T>; 
			newNode->info = newItem;
			newNode->link = this->first; 
			this->first = newNode; 
			this->count++; 
			if (this->last == NULL)
				this->last==newNode; 
		}
		
		void insertLast(const T& newItem)
		{
			node<T> *newNode;
			newNode = new node<T>; 
			newNode->info = newItem; 
			newNode->link = NULL; 
			if (this->first == NULL) //
			{
				this->first = newNode;
				this->last = newNode;
				this->count++; 
			}
			else 
			{
				this->last->link = newNode;
				this->last = newNode; 
				this->count++; 
			}
		}
		
		void deleteNode(const T& deleteItem)
		{
			node<T> *current; 
			node<T> *trailCurrent;
			bool found;
			if (this->first == NULL) 
				cout << "Cannot delete from an empty list."
				<< endl;
			else
			{
				if (this->first->info == deleteItem)
				{
					current = this->first;
					this->first = this->first->link;
					this->count--;
					if (this->first == NULL) 
						this->last = NULL;
					delete current;
				}
				else 
				{
					found = false;
					trailCurrent = this->first; 
					current = this->first->link;
					while (current != NULL && !found)
					{
						if (current->info != deleteItem)
						{
							trailCurrent = current;
							current = current-> link;
						}
						else
							found = true;
					}
					if (found) 
					{
						trailCurrent->link = current->link;
						this->count--;
						if (this->last == current) 
							this->last = trailCurrent; 
						delete current;
					}
					else
						cout << "The item to be deleted is not in "
							 << "the list." << endl;
				}
			}
		}
}; 
