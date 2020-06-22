/*Luis Santiago 21.181.829
  Universidad de los Andes
*/
#include "temp.h"

int main(){
	temp x;		//declaramos un objeto temp
	int c;		
	std::cout<<x.verCodigo();	//verificamos el codigo que habia
	std::cin>>c;			
	x.cambiarCodigo(c);		//asignamos el codigo nuevo
	return 0;
}
