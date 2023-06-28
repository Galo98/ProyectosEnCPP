



#include <iostream>
#include <string>

using namespace std;

//estructura de datos
struct info{

    string dia;
    int minuto;
    int pulso;
};


//Declaracion de funcion
void iniciarVector(info datos[7]);//Como se usa el vector
info entradaDatos();
void cargarDatos(info datos[7],info data); // Como se usa el vector
void mostrarDatos(info datos[7]); // Como se usa el vector
bool Continuar();

int main(){

    // Declaracion de variables
    info datos[7];
    info data;
    bool continuar = true;

    //Utilizacion de funcion en el main
    iniciarVector(datos);

    while (continuar == true){

        data = entradaDatos();
        cargarDatos(datos, data);
        continuar = Continuar();
    }

    mostrarDatos(datos);

    return 0;
}

//Creacion de funciones

void iniciarVector(info datos[7]){
 //inicia el vector
    info vacio;

    vacio.dia = "";
    vacio.minuto = 0;
    vacio.pulso = 0;

    for (int i = 0; i < 7; i++)
    {
        datos[i] = vacio;
    }
}

info entradaDatos(){

    
    info ingresos;

    ingresos.dia = "";
    ingresos.minuto = 0;
    ingresos.pulso = 0;

    cout << "\nIngrese el dia: " << endl;
    cin >> ingresos.dia;
    cout << "Ingrese los minutos: " << endl;
    cin >> ingresos.minuto;
    cout << "Ingrese las pulsaciones: " << endl;
    cin >> ingresos.pulso;

    return ingresos;
}

//Carga de datos al vector
void cargarDatos(info datos[7], info data){

    for (int i = 0; i < 7; i++){
        if (datos[i].dia != data.dia){
            datos[i] = data;
            cout << "\n el dia se pudo ingresar correctamente" << endl;
            i = 10;
        } else {
            if(datos[i].dia == data.dia){
                cout << "\nEse dia ya se encuentra ingresado." << endl;
            }
        }
    }
}
//Funcion para mostrar el mejor tiempo
void mostrarDatos(info datos[7]){
    
    
    info datas;
    int con = 0;

    datas.dia = " ";
    datas.minuto = 100;
    datas.pulso = 0;

    for (int i = 0; i < 7; i++){

            if(datos[i].minuto << datas.minuto){
            datas = datos[i];
            }

    }


    cout << "\nEl mejor tiempo fue el dia " << datas.dia << " el tiempo fue de " << datas.minuto << " minutos " << " y el pulso fue de " << datas.pulso << " pulsaciones por minuto. " << endl;
    


}

bool Continuar(){

    char op = 's';
    bool res = true;
    int i = 1;

    while(i == 1){
        cout << "\nSi desea continuar ingrese s (para si) o n (para no)" << endl;
        cin >> op;
        if(op == 's' ){
            res = true;
            i = 0;
        } else {
            if(op == 'n'){
                res = false;
                i = 0;
            } else {
                if (op != 's' && op != 'n'){
                    cout << "\n Opcion no valida" << endl;
                }
            }
        }
    }


    return res;
}
