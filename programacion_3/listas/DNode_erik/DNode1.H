/**
	@file DNode.H
	@brief Clase Nodo Doble. 
	Lista Doblemente enlazada circular.
	Cualquier duda o mejora informar al correo: erikvelasquez.25@gmail.com
	@author Erik Velasquez
	@date 4/2011, 4/2013

*/

#ifndef _DNODE
#define _DNODE
#include<iostream>
#include<utility>

using namespace std;

/**
	@class DNode
	@brief Nodo doblemente enlazado circular
 */
template<class T> class DNode
{

	//atributos publicos de la clase
	public:
		T data;					//Dato a almacenar en el nodo
		DNode<T> *next;				//Puntero al siguiente Nodo
		DNode<T> *prev;				//puentero al nodo anterior


	/**
		@brief Constructor por omision de la clase DNode
	*/
	DNode()
	{
		next=this;
		prev=this;
	};
	/**
		@brief Constructor por copia de la clase DNode
	*/
	DNode(DNode<T> & node)
	{
		this->data=node.data;
		this->next=node.next;
		this->prev=node.prev;
	};
	/**
		@brief Constructor por copia pasando puntero de la clase DNode
	*/
	DNode(DNode<T> * node)
	{
		this->data=node->data;
		this->next=node->next;
		this->prev=node->prev;
	};
	/**
		@brief destructor por omision de la clase DNode
	*/
	~DNode(){};
	/**
		@brief Constructor por copia de la clase DNode
	*/
	DNode(const T & dat)
	{
		data=dat;
	};

	/**
		@brief retorna la data almacenada en el nodo
		@return informacion almacenada en el nodo
	*/
	T& getData()
	{
		return data;	
	};
	
	/**
		@brief resetea el nodo 
		@return nada
	*/
	void reset()
	{
		next = this;
		prev = this;
	};
	/**
		@brief verifica si el nodo esta vacio
		@return True si esta vacio, False en caso contrario
	*/
	bool isEmpty()
	{
		return ((next == this)and(prev == this));
	};
	/**
		@brief Verificamos si el nodo es unico
		@return True si es unico, False en caso contrario
	*/
	bool isUnitarian()
	{ 
		return ((this != next) and (next == prev)); 
	};
	/**
		@brief Verificamos si el nodo es unico o tiene un solo elemento enlazado
		@return True si es unico o tiene un solo elemento, False en caso contrario
	*/
	bool isUnitarianOrEmpty() 
	{ 
		return next == prev; 
	};
	/**
		@brief Obtenemos el siguiente nodo enlazado a el
		@return puntero del siguiente nodo DNode<T>* 
	*/
	DNode<T>* getNext()
	{	
		return next;	
	};
	/**
		@brief Obtenemos el nodo anterior enlazado a el
		@return puntero del nodo anterior DNode<T>* 
	*/
	DNode<T>* getPrev()
	{	
		return prev;	
	};
	/**
		@brief inserto un nodo despues de mi
		@param nodo es el nodo a insertar
		@return nada
	*/
	void insertNext(DNode<T> * node)
	{
		node->prev = this;			//el nodo anterior de node sera nodo actual (this)
		node->next = next;			//el siguiente de node sera el siguiente de mi nodo actual (this)
		next->prev = node;			//el anterior de mi nodo siguiente sera el node
		next = node;				//mi siguiente nodo sera node
	};
	/**
		@brief inserto un nodo antes de mi
		@param nodo es el nodo a insertar
		@return nada
	*/
	void insertPrev(DNode<T> * node)
	{
		node->next = this;			//el nodo siguiente de node sera nodo actual (this)
		node->prev = prev;			//el nodo anterior de node sera el anterior de mi nodo actual (this)
		prev->next = node;			//el siguiente de mi nodo anterior sera el node
		prev = node;				//mi anterior nodo sera node
	};
	/**
		@brief remuevo el nodo actual de la lista
		@return nada
	*/
	void deleteNode()
	{
		prev->next = next;			//el siguiente de mi anterior sera mi siguiente
		next->prev = prev;			//el anterior de mi siguiente sera mi anterior
		reset();				//mando mis punteros a apuntarme a mi
	};

	/**
		@brief remuevo el nodo anterior de la lista
		@return nada
	*/
	DNode<T> * removePrev()
	{

		DNode<T> * retValue;			//defino el nodo auxiliar que contendra al nodo anterior
		retValue = prev;			//inicializo ese nodo auxiliar con el valor de mi nodo anterior
		retValue->deleteNode();			//remuevo al nodo anterior de la lista
		return retValue;
	};
	/**
		@brief remuevo el nodo siguiente de la lista
		@return nada
	*/
	DNode<T> * removeNext()
	{
		DNode<T> * retValue;			//defino el nodo auxiliar que contendra al nodo siguiente
		retValue = next;			//inicializo ese nodo auxiliar con el valor de mi nodo siguiente
		retValue->deleteNode();			//remuevo al nodo siguiente de la lista
		return retValue;
	};



/*FUNCIONES INTERESANTES*/

	/**
		@brief insertar ordenado siguiendo el criterio de menor a mayor
		@param node nodo a intercambiar
		@return nada
	*/
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

	/**
		@brief permite intercambiar los elementos de dos nodos
		@param node nodo a intercambiar
		@return nada
	*/
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

		std::swap(prev->next, node->prev->next);		//el siguiente del anterior de mi nodo actual con el siguiente del anterior de node
		std::swap(next->prev, node->next->prev);		//el anterior del siguiente de mi nodo actual con el anterior del siguiente de node
		std::swap(prev, node->prev);				//el anterior de mi nodo actual con el anterior de node
		std::swap(next, node->next);				//el siguiente de mi nodo actual con el siguiente de node

	};



	/**
		@brief insertamos una lista completa como siguiente nodo
		@param head cabecera de la lista a concatenar
		@return nada
	*/
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
	/**
		@brief insertamos una lista completa como nodo anterior
		@param head cabecera de la lista a concatenar
		@return nada
	*/
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

	/**
		@brief concatena dos listas
		@param head cabecera de la lista a concatenar
		@return nada
	*/
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

	/**
		@brief permite invertir los elementos de una lista
		@return nada
	*/
	void reverseList()
	{
		if (isEmpty())					//verifico que la lista no este vacia
			return;
		DNode<T> aux;					 // Lista temporal donde se guarda lista invertida

		while(not isEmpty())				//mientras la lista no este vacia
			aux.insertNext(removeNext());		//remuevo un elemento de la lista y lo inserto en la auxiliar

		swap(&aux);				 	//intercambio las cabeceras de las listas
	};

	/**
		@brief divide una lista actual en dos nuevas listas
		@param l lista de los elementos izquierdos de la division
		@param r lista de los elementos derechos de la division
		@return nada
	*/
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

	/**
		@brief divide una lista a partir de un nodo especificado
		@param node es el nodo a partir del cual se dividira la lista
		@param list lista con los elementos substraidos de la lista
		@return nada
	*/
	void cutList(DNode<T> * node, DNode<T> * list)
	{
		if(!list->isEmpty())				//list debe estar vacia
			return;

		list->prev = prev;			 	// enlazar list a node (punto de corte)
		list->next = node;
		prev = node->prev;			 	// quitar de this tod0o lo que esta a partir de node
		node->prev->next = this;
		node->prev = list;			 	// colocar el corte en list
		list->prev->next = list;
	};


/*DEFINICION DEL ITERADOR PARA CLASE DNODE*/


/**
	@class Iterator
	@brief Iterador sobre Nodos doblemente enlazados circulares
 */
	class Iterator
	{
		private:
			DNode<T> * head;				//puntero a la cabecera de la lista
			DNode<T> * curr;				//puntero al nodo actual
		public:

	/**
		@brief Constructor por omision de la clase
	*/
			Iterator()
			{
				head = curr = NULL;
			};
	/**
		@brief Constructor por copia de nodo cabecera 
	*/
			Iterator(DNode<T> * head_ptr)
			{
				head = head_ptr;
				curr = head->getNext();
			};
	/**
		@brief Constructor por copia de cabecera 
			Iterator(DNode<T> & _head)
			{
				head = &_head;
				curr = head->getNext();
			};

	/**
		@brief Constructor por copia 
	*/
			Iterator(DNode<T> * head_ptr, DNode<T> * curr_ptr)
			{
				head = head_ptr;
				curr = curr_ptr;
			};
	/**
		@brief Constructor por copia de otro iterador 
	*/
			Iterator(const Iterator &  itor)
			{
				head = itor.head;
				curr = itor.curr;
			};

	/**
		@brief Sobre escritura del operador igual (=)
		@param itor iterador a copiar
		@return la copia del iterador
	*/
			Iterator & operator = (const Iterator & itor)
			{

				if (this == &itor)
					return *this;
				head = itor.head;
				curr = itor.curr;
				return *this;
			};
	/**
		@brief Sobre escritura del operador igual (=)
		@param head_ptr
		@return la copia del iterador
	*/
			Iterator & operator = (DNode<T> * head_ptr)
			{
				head = head_ptr;
				curr = head->getNext();
				return *this;
			};
	/**
		@brief reiniciamos el iterador en el primer elemento de la lista
		@return nada
	*/
			void resetFirst()
			{
				curr = head->getNext();
			};
	/**
		@brief reiniciamos el iterador en el ultimo elemento de la lista
		@return nada
	*/
			void resetLast()
			{
				curr = head->getPrev();
			};
	/**
		@brief defino cual es el elemento actual
		@param new_curr nodo que sera actual
		@return nada
	*/
			void setCurrent(DNode<T> * new_curr)
			{
				curr = new_curr;
			};

	/**
		@brief reseteo el iterador
		@return nada
	*/
			void reset(DNode<T> * new_head, DNode<T> * new_curr)
			{
				head = new_head;
				curr = new_curr;
			};
	/**
		@brief reseteo el iterador
		@return nada
	*/
			void reset(DNode<T> * new_head)
			{
				head = new_head;
				curr = head->getNext();;
			};

	/**
		@brief verifico si mi actual es diferente a la cabecera de la lista
		@return True si es distinto a la cabecera, False en caso contrario
	*/
			bool hasCurrent() const
			{
				return (curr != head);
			};
			
	/**
		@brief obtengo el nodo actual 
		@return el nodo actual 
	*/
			DNode<T> * getCurrent()
			{
				if (hasCurrent())
					return curr;

				return NULL;
			};
	/**
		@brief verifico si estoy en el primer nodo de la lista
		@return True si estoy en el primer nodo, False en caso contrario
	*/
			bool isInFirst() const 
			{ 
				return (curr == head->next); 
			};
	/**
		@brief verifico si estoy en el ultimo nodo de la lista
		@return True si estoy en el ultimo nodo, False en caso contrario
	*/
			bool isInLast() const 
			{ 
				return (curr == head->prev); 
			};

	/**
		@brief muevo el iterador al nodo anterior de la lista
		@return nada
	*/
			void prev()
			{
				curr = curr->getPrev();
			};
	/**
		@brief muevo el iterador al nodo siguiente de la lista
		@return nada
	*/
			void next()
			{
				curr = curr->getNext();
			};

	/**
		@brief definimos el operador de comparacion (==)
		@return True si son iguales, False en caso contrario
	*/
			bool operator == (const Iterator & it) const 
			{ 
				return curr == it.curr; 
			};
	/**
		@brief definimos el operador distinto (!=)
		@return True si son distintos, False en caso contrario
	*/
			bool operator != (const Iterator & it) const 
			{ 
				return curr != it.curr; 
			};

	/**
		@brief remuevo el elemento actual de la lista
		@return puntero del elemento eliminado
	*/
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
