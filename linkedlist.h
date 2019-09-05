#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T info;
	node<T> *link;
};

template<typename T>
class linkedListIterator
{
private:
	node<T> *current;
public:
	linkedListIterator(){current = NULL;}
	linkedListIterator(node<T> *ptr){ current = ptr;}
	T operator *();
	linkedListIterator<T> operator++();
	bool operator ==(const linkedListIterator<T>& right) const;
	bool operator !=(const linkedListIterator<T>& right) const;
};

template<typename T>
T linkedListIterator<T>::operator *()
{
	return current->dato;
}

template<typename T>
linkedListIterator<T> linkedListIterator<T>::operator++()
{
	current = current->link;
	return *this;
}
template<typename T>
bool linkedListIterator<T>::operator == (const linkedListIterator<T>& right) const// se comprueba con un mismo tipo de ietetrador debe ser constante
{
	return (current == right.current);// comprueba si los puntreros son iguales
}

template<typename T>
bool linkedListIterator<T>::operator !=(const linkedListIterator<T>& right)const
{
	return (current != right.current);
}




template <typename T>
class linkedListType
{
	protected:
		int count;
		node<T> *first;
		node<T> *last;
	public:
		
		bool isEmptyList() const
		{
			return (first == NULL);
		}
		
		linkedListType()//constructor
		{
			first=NULL;
			last=NULL;
			count=0;
		}
		
		void destroylist()
		{
			node<T> *temp;
			while (first != NULL) 
			{
				temp = first; 
				first = first->link; 
			}
			last = NULL; 
			count = 0;
		}
		
		void initializeList()
		{
			//destroyList();
		}
		
		void print() const
		{
			node<T> *current; 
			current = first; 
			while (current != NULL)
			{
				cout << current->info << " ";
				current = current->link;
			}
		}
		
		int length() const
		{
			return count;
		}
		
		T front () const
		{
			assert(first != NULL);
			return first->info;
		}
		
		T back() const
		{
			assert(last != NULL);
		}
		
		linkedListType(const linkedListType<T>& otherList)
		{
			first = NULL;
			copyList(otherList);
		}
		
		const linkedListType<T> &operator=(const linkedListType<T> &otherList)
		{
			if (this != &otherList)
			{
				copyList(otherList);
			}
			return *this;
		}
		
		virtual bool search(const T& searchItem) const = 0; 
		virtual void insertFirst(const T& newItem) = 0;
		virtual void insertLast(const T& newItem) = 0;
		virtual void deleteNode(const T& deleteItem) = 0;
		
		~linkedListType()
		{
			//destroyList();
		}

		linkedListIterator<T>  begin()
		{
			linkedListIterator<T> temp(first);//un iterador contien un nodo con sobrecargas, por eso se usa el iterador llama al iterador
			return temp;//retornamos ese valor gerarquia de contencion
		}

		linkedListIterator<T>  end()
		{
			linkedListIterator<T> temp(NULL);
			return temp;
		}
	private:
		void copyList(const linkedListType<T>& otherList)
		{
			node<T> *newNode; 
			node<T> *current; 
			if (first != NULL) 
				//destroyList();
			if (otherList.first == NULL) 
			{
				first = NULL;
				last = NULL;
				count = 0;
			}
			else
			{
				current = otherList.first; 
				count = otherList.count;
				first = new node<T>; 
				first->info = current->info; 
				first->link = NULL; 
				last = first; 
				current = current->link; 
				while (current != NULL)
				{
					newNode = new node<T>; 
					newNode->info = current->info; 
					newNode->link = NULL; 
					last->link = newNode; 
					last = newNode;
					current = current->link;
				}
			}
		}
};

