#include <iostream>
#include <string>

using namespace std;

//Estructuras de datos

struct alumno {
    string nombre;
    string materia;
    double nota;
};

struct promedio{
    string nombre; 
    double promedio;
};

// Definicion de funciones

void inicializarAlumnos(alumno datos[10]);
void inicializarOrdenados(alumno datos[10]);
void inicializarPromedios(promedio datos[4]);
void cargarOrdenado(alumno dato, alumno salida[10]);
void promediarAlumnos(alumno datos[10], promedio salida[4]);
void mostrarAlumnos(alumno datos[10]);
void mostrarPromedios(promedio datos[4]);

int main(){

    string nombre = "";
    string materia = "";
    double nota = 0;
    int i = 0;

    alumno alumnosCargados[10];
    alumno alumnosOrdenados[10];
    promedio notasPromedios[4];

    inicializarAlumnos(alumnosCargados);
    inicializarOrdenados(alumnosOrdenados);
    inicializarPromedios(notasPromedios);

    cout << "\n \n ALUMNOS CARGADOS \n \n";
    mostrarAlumnos(alumnosCargados);

    while( i < 10){
        if(alumnosCargados[i].nombre != "" && alumnosCargados[i].nombre != nombre){
            nombre = alumnosCargados[i].nombre;
            cout << "\n deberia cargar a " + nombre;
            cargarOrdenado(alumnosCargados[i], alumnosOrdenados);
            alumnosCargados[i].nombre = "";
            for(int b = 0; b < 10; b++){
                 if(alumnosCargados[b].nombre != "" && alumnosCargados[b].nombre == nombre){
                    cargarOrdenado(alumnosCargados[b], alumnosOrdenados);
                    alumnosCargados[b].nombre = "";
                }
            }
        } else{
            i++;
        }
    }

    cout << "\n \n ALUMNOS ORDENADOS \n \n";
    mostrarAlumnos(alumnosOrdenados);

    promediarAlumnos(alumnosOrdenados,notasPromedios);
    cout << "\n \n PROMEDIOS DE LOS ALUMNOS \n \n";
    mostrarPromedios(notasPromedios);


    return 0;
}

void inicializarAlumnos(alumno alumnos[10]){

    // pepe
    alumnos[0].nombre = "pepe";
    alumnos[0].materia = "algoritmos";
    alumnos[0].nota = 8;

    alumnos[4].nombre = "pepe";
    alumnos[4].materia = "matematica";
    alumnos[4].nota = 8;

    alumnos[9].nombre = "pepe";
    alumnos[9].materia = "ingles";
    alumnos[9].nota = 8;

    // maria
    alumnos[1].nombre = "maria";
    alumnos[1].materia = "ingles";
    alumnos[1].nota = 7;

    alumnos[6].nombre = "maria";
    alumnos[6].materia = "ingles";
    alumnos[6].nota = 7;

    alumnos[7].nombre = "maria";
    alumnos[7].materia = "ingles";
    alumnos[7].nota = 7;

    // Alba

    alumnos[2].nombre = "alba";
    alumnos[2].materia = "ingles";
    alumnos[2].nota = 9;

    alumnos[3].nombre ="alba";
    alumnos[3].materia = "ingles";
    alumnos[3].nota = 9;
    
    alumnos[5].nombre = "alba";
    alumnos[5].materia = "ingles";
    alumnos[5].nota = 9;

    // Jorge

    alumnos[8].nombre = "jorge";
    alumnos[8].materia = "ingles";
    alumnos[8].nota = 10;

};

void inicializarOrdenados(alumno datos[10]){
    for (int i = 0; i < 10; i++){
        datos[i].nombre = "";
        datos[i].materia = "";
        datos[i].nota = 0;
    }
};

void inicializarPromedios(promedio datos[4]){
    for (int i = 0; i < 4; i++){
        datos[i].nombre = "";
        datos[i].promedio = 0;
    }
};

void mostrarAlumnos(alumno datos[10]){
       for(int i = 0; i < 10; i++){
        cout << "\n";
        cout << datos[i].nombre;
        cout << "\n";
        cout << datos[i].materia;
        cout << "\n";
        cout << datos[i].nota;
        cout << "\n";
    } 
};

void cargarOrdenado(alumno dato, alumno salida[10]){

    for(int i = 0; i< 10; i++){
        if(salida[i].nombre == ""){
            cout << "\n deberia cargar a " + dato.nombre + " en la funcion cargar ordenado";
            salida[i] = dato;
            i = 100;
        }
    }
}

void promediarAlumnos(alumno datos[10], promedio salida[4]){
    string nombre = "";
    promedio promedioAlumno;
    double nota = 0;
    int i = 1;
    int cuentaNota = 0;

    promedioAlumno.nombre = "";
    promedioAlumno.promedio = 0;

    promedioAlumno.nombre = datos[0].nombre;
    nota = datos[0].nota;
    cuentaNota = 1;

    while (i < 10)
    {
        if(datos[i].nombre == promedioAlumno.nombre){
            nota = nota + datos[i].nota;
            cuentaNota++;
        }else{
            for (int b = 0; b < 4; b++){
                if(salida[b].nombre == ""){
                    nota = nota / cuentaNota;
                    promedioAlumno.promedio = nota;
                    salida[b] = promedioAlumno;
                    break;
                }
            }

            promedioAlumno.nombre = datos[i].nombre;
            nota = datos[i].nota;
            cuentaNota = 1;
        }

        i++;
    }

    for (int b = 0; b < 4; b++){
        if(salida[b].nombre == ""){
            nota = nota / cuentaNota;
            promedioAlumno.promedio = nota;
            salida[b] = promedioAlumno;
            break;
        }
    }
    
};

void mostrarPromedios(promedio datos[4]){
        for(int i = 0; i < 10; i++){
        cout << "\n";
        cout << datos[i].nombre;
        cout << "\n";
        cout << datos[i].promedio;
        cout << "\n";
        
    }
};