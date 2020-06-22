#include <iostream>
#include <fstream>
 
using namespace std;
 
int main () {

    fstream ficheroMp3;
    char marca[3];
char marca2[3]={'T','A','G'};

    ficheroMp3.open ("ejemplo.dat", ios::app | ios::binary);

if (ficheroMp3.is_open()) {
ficheroMp3.write(marca2, 3);
cout<<"escribio"<<endl;
ficheroMp3.close();
}else cout<<"no escribio"<<endl;
 
    ficheroMp3.open ("ejemplo.dat", ios::in | ios::binary);
    // Compruebo si he podido abrir

    if (ficheroMp3.is_open()) {
        // Me coloco donde empieza el ID3 TAG
//        ficheroMp3.seekg(-128, ios::end);
        // Leo 3 bytes

        ficheroMp3.read(reinterpret_cast<char*>(&marca), 3);
	cout<<"marca[0]: "<<marca[0]<<" "<<"marca[1]: "<<marca[1]<<" "<<"marca[2]: "<<marca[2]<<endl;
        // Digo si day datos o no
        if ((marca[0] != 'T') || (marca[1] != 'A') || (marca[2] != 'G'))

            cout << "Sin datos de artista" << endl;
        else
            cout << "Parece un MP3 con ID3 TAG" << endl;
        // Finalmente, cierro

        ficheroMp3.close();
    }
    // Si no he podido abrir, aviso
    else cout << "Fichero inexistente" << endl;
    return 0;

}
