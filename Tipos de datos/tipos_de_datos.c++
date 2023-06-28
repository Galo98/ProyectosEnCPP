// comentario de lineas
/* 
comentarios de varias lineas
 */

#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;


//Declaracion de funciones
/*
Las funciones con VOID en su inicio no devuelven ningun tipo de dato 

Las funciones que declaran un tipo de variables (primitivo o no) en su inicio retornan algun dato de ese tipo

*/

void tiposDeDatos();
void lecturaYEscrituradeDatos();
void problema1();

int main (){

    int opcion = 0;
    char continuar = 's';

    cout << "Bienvenido a los programas de iniciacion en c++" <<endl;
    while (continuar == 's'){
    cout << "A continuacion se detallaran los diferentes programas cargados, por favor ingrese el numero correspondiente para elegirlo" <<endl;
    cout << " 1. Tipos de datos \n 2.Lectura y escritura de datos \n 3.Mini Calculadora" <<endl;
    cin >> opcion;
    if (opcion == 1){
        tiposDeDatos();
    } else{

            if(opcion == 2){
            lecturaYEscrituradeDatos();
            } 
                else {
                 problema1();
                }
    }
    cout << "Desea volver al menu s (para SI) n (para NO)?" << endl;
    cin >> continuar;
    }
    return 0;
}

void tiposDeDatos(){
    // tipos de datos

    float flotante = 10.25;
    int numero = 10;
    double doble = 10.3430;
    char caracter = 's';
    bool booleano = true;

    cout << "Hola mundo \n"
         << endl;
    cout << "Esto es un float \n"
         << flotante << endl;
    cout << "Esto es un entero \n"
         << numero << endl;
    cout << "Esto es un double \n"
         << doble << endl;
    cout << "Esto es un char \n"
         << caracter << endl;
    cout << "Esto es un booleano \n"
         << booleano << endl;
}

void lecturaYEscrituradeDatos(){
    // Lectura y escritura de datos

    int numero = 0;
    char letra = 'a';
    string palabra = " ";

    cout << "\n Por favor ingrese un nuevo numero" << endl;
    cin >> numero;
    cout << "Ingrese una letra" << endl;
    cin >> letra;
    cout << "Ingrese una palabra" << endl;
    cin >> palabra;

    cout << "El numero ingresado es: \n"
         << numero << endl;
    cout << "La letra ingresada es: \n"
         << letra << endl;
    cout << "La palabra ingresada es: \n"
         << palabra << endl;
}

void problema1(){

    /* 1. Escribe un programa que lea de la entrada estandar dos numeros y muestre en la salida estandar su suma, resta multiplicacion y division. */

    int n1 = 0;
    int n2 = 0;

    cout << "\n Ingrese el primer numero:" << endl;
    cin >> n1;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> n2;
    cout << "La suma de los dos numeros es: " << n1 + n2 << endl;
    cout << "La resta entre los dos numeros es: " << n1 - n2 << endl;
    cout << "La multiplicacion entre los dos numeros es: " << n1 * n2 << endl;
    cout << "La division entre los dos numeros es: " << n1 / n2 << endl;
}