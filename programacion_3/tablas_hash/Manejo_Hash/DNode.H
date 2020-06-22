/*Clase Nodo Doble circular
Realizada por:
Erik Velasquez*/

#ifndef _DNODE
#define _DNODE
#include<iostream>

using namespace std;


template<class T> class DNode
{

	//atributos publicos de la clase
	public:
		T data;					//Dato a almacenar en el nodo
		DNode<T> *next;				//Puntero al siguiente Nodo
		DNode<T> *prev;				//puentero al nodo anterior


	//Constructor por omision
	DNode()
	{
		next=this;
		prev=this;
	};
	//constructor por copia
	DNode(DNode<T> & node)
	{
		this->data=node.data;
		this->next=node.next;
		this->prev=node.prev;
	};
	//constructor por copia pasando puntero
	DNode(DNode<T> * node)
	{
		this->data=node.data;
		this->next=node.next;
		this->prev=node.prev;
	};
	//destructor por omision
	~DNode(){};
	//Constructor por copia
	DNode(const T & dat)
	{
		data=dat;
	};

	//Obtener el valor de dato
	T& getData()
	{
		return data;	
	};
	//reseteamos el valor del nodo, ponemos a apuntar mis punteros al mismo nodo
	void reset()
	{
		next = this;
		prev = this;
	};
	//verificamos si esta vacia la lista
	bool isEmpty()
	{
		return ((next == this)and(prev == this));
	};
	//verificamos si posee un solo valor el this
	bool isUnitarian()
	{ 
		return ((this != next) and (next == prev)); 
	};
	//verificamos si la lista esta vacia o tiene un solo elemento
	bool isUnitarianOrEmpty() 
	{ 
		return next == prev; 
	};
	//obtener el siguiente nodo
	DNode<T>* getNext()
	{	
		return next;	
	};
	//obtener el nodo anterior
	DNode<T>* getPrev()
	{	
		return prev;	
	};
	//inserto siguiente a mi
	void insertNext(DNode<T> * node)
	{
		node->prev = this;			//el nodo anterior de node sera nodo actual (this)
		node->next = next;			//el siguiente de node sera el siguiente de mi nodo actual (this)
		next->prev = node;			//el anterior de mi nodo siguiente sera el node
		next = node;				//mi siguiente nodo sera node
	};
	//inserto un nodo antes de mi
	void insertPrev(DNode<T> * node)
	{
		node->next = this;			//el nodo siguiente de node sera nodo actual (this)
		node->prev = prev;			//el nodo anterior de node sera el anterior de mi nodo actual (this)
		prev->next = node;			//el siguiente de mi nodo anterior sera el node
		prev = node;				//mi anterior nodo sera node
	};
	//remuevo al nodo actual de la lista
	void deleteNode()
	{
		prev->next = next;			//el siguiente de mi anterior sera mi siguiente
		next->prev = prev;			//el anterior de mi siguiente sera mi anterior
		reset();				//mando mis punteros a apuntarme a mi
	};

	//remover el nodo anterior
	DNode<T> * removePrev()
	{

		DNode<T> * retValue;			//defino el nodo auxiliar que contendra al nodo anterior
		retValue = prev;			//inicializo ese nodo auxiliar con el valor de mi nodo anterior
		retValue->deleteNode();			//remuevo al nodo anterior de la lista
		return retValue;
	};
	//remover el nodo anterior
	DNode<T> * removeNext()
	{
		DNode<T> * retValue;			//defino el nodo auxiliar que contendra al nodo siguiente
		retValue = next;			//inicializo ese nodo auxiliar con el valor de mi nodo siguiente
		retValue->deleteNode();			//remuevo al nodo siguiente de la lista
		return retValue;
	};



/*FUNCIONES INTERESANTES*/

	//insertar odenado siguiendo el criterio de menor a mayor
	void OrderedInsertion(DNode<T> *node)
	{
		DNode<T> *aux;
		DNode<T> *aux2;
		aux = this->getNext();				//obtengo el siguiente nodo a mi nodo actual
		aux2 = this;					//mantengo una referencia a mi nodo actual

		while(aux != this)				//mientras mi nodo siguiente no sea mi nodo actual
		{
			if(node->data < aux->data)		//verifico que el dato de mi nodo a insertar sea menor al nodo siguiente
			{
				aux2->insertNext(node);		//inserto y termino el metodo
				return;
			}
			aux2 = aux;				//me muevo al siguiente nodo de la lista
			aux = aux->getNext();
		
		}
		aux->insertNext(node);				//inserto el nodo en la ultima posicion de la lista		

	};

	//permite intercambiar los elementos de dos nodos
	void swap(DNode<T> * node)
	{
		if (isEmpty() and node->isEmpty())		//verifico si los dos nodos son vacios
			return;
		if (isEmpty())					//verifico si el nodo actual(this) es el que esta vacio
		{
			node->next->prev = this;		//el anterior del siguiente nodo de node apuntara a mi actual
			node->prev->next = this;		//el siguiente del anterior del nodo de node apuntara a mi actual
			next = node->next;			//el siguiente de mi actual apuntara al siguiente de node
			prev = node->prev;			//el anterior de mi actual apuntara al anterior de node
			node->reset();				//reseteamos al valor de node
			return;
		}
		if (node->isEmpty())				//verifico si el node es vacio
		{
			next->prev = node;			//el anterior del siguiente nodo de mi nodo actual(this) apuntara a node
			prev->next = node;			//el siguiente del anterior nodo de mi nodo actual apuntara a node
			node->next = next;			//el siguiente de node apuntara a el siguiente de mi actual
			node->prev = prev;			//el anterior de node apuntara a el anterior de mi actual
			reset();				//reseteamos al valor de mi actual
			return;
		}
		//hago las llamadas RECURSIVAS en el caso de que los dos nodos forman parte de una lista

		swap(prev->next, node->prev->next);		//el siguiente del anterior de mi nodo actual con el siguiente del anterior de node
		swap(next->prev, node->next->prev);		//el anterior del siguiente de mi nodo actual con el anterior del siguiente de node
		swap(prev, node->prev);				//el anterior de mi nodo actual con el anterior de node
		swap(next, node->next);				//el siguiente de mi nodo actual con el siguiente de node
	};


	//insertamos una lista completa como siguiente nodo
	void insertListNext(DNode<T> * head)
	{
		if (head->isEmpty())				//verificamos que la cabecera de la lista a insertar no este vacia
			return;
		head->prev->next = next;			//el siguiente del anterior de la cabecera apuntara a el siguiente de mi nodo actual
		head->next->prev = this;			//el anterior del siguiente de la cabecera apuntara a el anterior de mi nodo actual
		next->prev = head->prev;			//el anterior del siguiente de mi nodo actual apuntara a el anterior de la cabecera
		next = head->next;				//el siguiente de mi nodo actual apuntara al siguiente de la cabecera
		head->reset();					//reseteamos la cabecera
	};
	//insertamos una lista completa como nodo anterior
	void insertListPrev(DNode<T> * head)
	{
		if (head->isEmpty())				//verificamos que la cabecera de la lista a insertar no este vacia
			return;
		head->next->prev = prev;			//el anterior del siguiente de la cabecera apuntara a el anterior de mi nodo actual
		head->prev->next = this;			//el siguiente del anterior de la cabecera apuntara a mi nodo actual
		prev->next = head->next;			//el siguiente del anterior de mi nodo actual apuntara al siguiente de la cabecera
		prev = head->prev;				//el anterior de mi nodo actual apuntara al anterior de la cabecera
		head->reset();					//reseteamos la cabecera
	};

	//concatena dos listas
	void concatList(DNode<T> * head)
	{
		if (head->isEmpty())				//verificamos que la cabecera de la lista a concatenar no este vacia
			return;
		if (this->isEmpty())				//verificamos que la lista actual no este vacia
		{
			swap(head);				//intercambio la lista actual con la cabecera de la lista a concatenar
			return;
		}
		prev->next = head->next;			//el siguiente del anterior de mi nodo actual apuntara al siguiente de la cabecera
		head->next->prev = prev;			//el anterior del siguiente de la cabecera apuntara al anterior de mi nodo actual
		prev = head->prev;				//el anterior de mi nodo actual apuntara al anterior de la cabecera
		head->prev->next = this;			//el siguiente del anterior de la cabecera apuntara al mi nodo actual
		head->reset();					//reseteamos la cabereca
	};

	//permite invertir los elementos de una lista
	void reverseList()
	{
		if (isEmpty())					//verifico que la lista no este vacia
			return;
		DNode<T> aux;					 // Lista temporal donde se guarda lista invertida

		while(not isEmpty())				//mientras la lista no este vacia
			aux.insertNext(removeNext());		//remuevo un elemento de la lista y lo inserto en la auxiliar

		swap(&aux);				 	//intercambio las cabeceras de las listas
	};

	//divide la lista actual en dos nuevas listas
	void splitList(DNode<T> & l, DNode<T> & r)
	{
		while (not isEmpty())				//mientras la lista no este vacia
		{
			l.insertPrev(removeNext());		//inserto en la lista izquierda
			if (isEmpty())				//verifico que la lista no este vacia
				break;
			r.insertNext(removePrev());		//inserto en la lista derecha
		}
	};

	//divido la lista a partir de un nodo especificado
	void cutList(DNode<T> * node, DNode<T> * list)
	{
		if(!list->isEmpty())				//list debe estar vacia
			return;

		list->prev = prev;			 	// enlazar list a node (punto de corte)
		list->next = node;
		prev = node->prev;			 	// quitar de this todo lo que esta a partir de node
		node->prev->next = this;
		node->prev = list;			 	// colocar el corte en list
		list->prev->next = list;
	};


/*DEFINICION DEL ITERADOR PARA CLASE DNODE*/



	class Iterator
	{
		private:
			DNode<T> * head;				//puntero a la cabecera de la lista
			DNode<T> * curr;				//puntero al nodo actual
		public:

			//constructor por omision
			Iterator()
			{
				head = curr = NULL;
			};
			//constructor
			Iterator(DNode<T> * head_ptr)
			{
				head = head_ptr;
				curr = head->getNext();
			};
			//constructor
			Iterator(DNode<T> & _head)
			{
				head = &_head;
				curr = head->getNext();
			};

			//constructor
			Iterator(DNode<T> * head_ptr, DNode<T> * curr_ptr)
			{
				head = head_ptr;
				curr = curr_ptr;
			};
			//constructor
			Iterator(const Iterator &  itor)
			{
				head = itor.head;
				curr = itor.curr;
			};

			//sobreescritura del operador =
			Iterator & operator = (const Iterator & itor)
			{

				if (this == &itor)
					return *this;
				head = itor.head;
				curr = itor.curr;
				return *this;
			};
			//sobreescritura del operador =
			Iterator & operator = (DNode<T> * head_ptr)
			{
				head = head_ptr;
				curr = head->getNext();
				return *this;
			};
			//reiniciamos el iterador en el primer nodo de la lista
			void resetFirst()
			{
				curr = head->getNext();
			};
			//reiniciamos el iterador en el ultimo nodo de la lista
			void resetLast()
			{
				curr = head->getPrev();
			};
			//defino cual es el nodo actual
			void setCurrent(DNode<T> * new_curr)
			{
				curr = new_curr;
			};

			//reseteo el iterador
			void reset(DNode<T> * new_head, DNode<T> * new_curr)
			{
				head = new_head;
				curr = new_curr;
			};
			//reseteo el iterador
			void reset(DNode<T> * new_head)
			{
				head = new_head;
				curr = head->getNext();;
			};

			//verifico si mi actual es diferente de la cabecera de la lista
			bool hasCurrent() const
			{
				return (curr != head);
			};
			
			//obtengo al nodo actual
			DNode<T> * getCurrent()
			{
				if (hasCurrent())
					return curr;

				return NULL;
			};
			//verifico si estoy en el primer nodo de la lista
			bool isInFirst() const 
			{ 
				return (curr == head->next); 
			};
			//verifico si estoy en el ultimo nodo de la lista
			bool isInLast() const 
			{ 
				return (curr == head->prev); 
			};

			//muevo el iterador al nodo anterior de la lista
			void prev()
			{
				curr = curr->getPrev();
			};
			//muevo el iterador al nodo anterior de la lista
			void next()
			{
				curr = curr->getNext();
			};

			//definimos el operador ==
			bool operator == (const Iterator & it) const 
			{ 
				return curr == it.curr; 
			};
			//definimos el operador !=
			bool operator != (const Iterator & it) const 
			{ 
				return curr != it.curr; 
			};

			//remuevo el elemento actual de la lista
			DNode<T> * del()
			{							
				DNode<T> * current = getCurrent();
				next();							
				current->del();			
				return current;
			};


	};//fin clase Iterator



};//fin clase DNode



#endif 
