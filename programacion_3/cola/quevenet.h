#ifndef COLA
#define COLA // Define la cola

template <class T>
class Cola{

	private:

	struct Nodo{

	T elemento;
	struct Nodo* siguiente;  // coloca el nodo en la segunda posición

        }* primero;

        struct Nodo* ultimo;

        unsigned int elementos;

      public:

        Cola(){
            elementos = 0;
        }

        ~Cola(){
            while (elementos != 0) pop();
        }

        void push(const T& elem){
            Nodo* aux = new Nodo;
            aux->elemento = elem;
            if (elementos == 0) primero = aux;
            else ultimo->siguiente = aux;
            ultimo = aux;
            ++elementos;
        }
        void pop(){
            Nodo* aux = primero;
            primero = primero->siguiente;
            delete aux;
            --elementos;
        }
        T consultar() const{
            return primero->elemento;
        }
        bool vacia() const{
            return elementos == 0;
        }
        unsigned int size() const{
            return elementos;
        }
    };
    #endif
