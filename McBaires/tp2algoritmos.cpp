#include <iostream>
#include <string>

using namespace std;

struct puntuacion{
	
	int puntos;
	char compra;
	char atencion;
	char volver;
	int factura;
		
};


void iniciarVector(puntuacion encuestas[10]);
puntuacion ingresoEncuesta();




int main(){
	

	puntuacion encuestas[10];
	
	iniciarVector(encuestas)

	cargarEncuestaAVector(encuesta);
	ingresoEncuesta(encuestas[10]);
	
	
	return 0;
}



void iniciarVector(puntuacion encuestas[10]){
	
	for (i=0 i<11 i++){

		int encuestas[i].puntos =0;
		char encuestas[i].compra = '';
		char encuestas[i].atencion = '';
		char encuestas[i].volver = '';
		int encuestas[i].factura = 1;	
	}
	
}


puntuacion ingresoEncuesta(puntuacion encuestas[10]){
	
	int i=0;
	
	while(encuestas[i].factura !=0000){
	cout << "Bienvenido a MC Baires, por favor responda la siguiente encuesta." << endl;
	cout << "Del 1 al 10 que puntacion le das a McBaires?" << endl;
	cin >> encuestas[i].puntos;
	cout << "Que tipo de compra realizaste ?" << endl << " C: para comer en el restaurante o L para llevar" << endl;
	cin >> encuestas[i].compra;
	cout << "Como fue la antencion de los empleados ?" << endl << "E Exelente, B Buena o M Mala." << endl; 
	cin >> encuestas[i].atencion;
	cout << "Volveria a comprar em Mc.Baires ?" << endl << "S para si o N para no" << endl;
	cin >> encuestas[i].volver;
	cout << "Por favor ingrese los 4 ultimos numeros de su factura" << endl;
	cin >> encuestas[i].factura;
	cout << " Gracias por responder"<<endl;
	i++;
	}
	return encuestas[10];
		
}







