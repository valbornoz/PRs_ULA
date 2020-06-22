// punto.h

# ifndef PUNTO_H
# define PUNTO_H

using namespace std;

class punto {

private:
	int x;
	int y;
public:
	punto();
	
	void establecer_x(int);
	void establecer_y(int);
	int obtener_x() const;
	int obtener_y() const;
	
	~punto(){};
};		

#endif
