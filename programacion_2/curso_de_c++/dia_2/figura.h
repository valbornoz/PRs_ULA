// figura.h

# ifndef FIGURA_H
# define FIGURA_H

# include <iostream>

using namespace std;

class figura {

protected:
	string nombre;
public:
	figura(){};
	
	void establecer_nombre(string);
	string obtener_nombre() const;
	
	virtual void imprimir() = 0;
	
	//~figura(){};
};		

#endif
