 /*   Trabajo practico Algoritmos y estructuras de datos I.

  Integrantes:  More Dana
                Diaz Celeste Noelia
                Herdeli Luciano
                Suarez Daniela
                Olguin Galo
*/

#include <iostream>
#include <string.h>
#include <windows.h>

//ESPACIO DE NOMBRE

using namespace std;

//DECLARACIÓN DE TIPOS NO PRIMITIVOS


// para declarar una estructura es
/*
struct NOMBRE-DEL-NUEVO-TIPO{

    int variable;
    string variable;
    boole variable;
    float variable;

}

*/

struct zona
{
    string partido;
    string localidad;
    string barrio;
};

struct cuadra
{
    string calle;
    string entrecalle1;
    string entrecalle2;
    int luzRota;
    int luz;
};

//DECLARACIÓN DE FUNCIONES

//funcion para ingresar numero int ingresar();
//funcion para ingresar la opracion char ingresooperacion();
//funcion para mostrar los datos int resultado();

void inicializarVector(cuadra cuadraRevisada[10]);
zona cargarZona();
cuadra ingresarCuadra();
void agregarCalleACuadra(cuadra cuadraRevisada[10], cuadra calleRevisada);
bool Continuar();
void mostrarZonaRevisada(zona zonaRevisada);
void contadorCuadras(cuadra cuadraRevisada[10]);
void mostrarCuadrasRevisadas(cuadra cuadraRevisada[10]);
void contadorLuces(cuadra cuadraRevisada[10]);
void mostrarCuadraMasAfectada(cuadra cuadraRevisada[10]);

//BLOQUE PRINCIPAL

int main()
{
    //DECLARACIÓN DE VARIABLES
    zona zonaRevisada;
    cuadra cuadraRevisada[10];
    cuadra calleRevisada;
    bool continuar = true;

    inicializarVector(cuadraRevisada);
    zonaRevisada = cargarZona();

    while (continuar == true)
    {
        calleRevisada = ingresarCuadra();
        agregarCalleACuadra(cuadraRevisada, calleRevisada);
        continuar = Continuar();
    }
    mostrarZonaRevisada(zonaRevisada);
    contadorCuadras(cuadraRevisada);
    mostrarCuadrasRevisadas(cuadraRevisada);
    contadorLuces(cuadraRevisada);
    mostrarCuadraMasAfectada(cuadraRevisada);
    system("pause");
    return 0;
}

//IMPLEMENTACI�N DE FUNCIONES

void inicializarVector(cuadra cuadraRevisada[10]){
    cuadra cuadraVacia;
    cuadraVacia.calle = "";
    cuadraVacia.entrecalle1 = "";
    cuadraVacia.entrecalle2 = "";
    cuadraVacia.luzRota = 0;
    cuadraVacia.luz = 0;
    for (int i = 0; i <= 9; i++){
        cuadraRevisada[i] = cuadraVacia;
        }
}

zona cargarZona()
{
    zona nuevaZona;
    cout << "Ingrese los datos a continuacion pedidos SIN espacios (utilice - o _ para separar)" << endl;
    cout << "intrese el partido" << endl;
    /*PARA EVITAR EL INCONVENIENTE DEBEN USAR LA FUNCI�N getline DEL SIGUIENTE MODO. Y DE FORMA SIMILAR
    PARA EL RESTO DE LOS STRING QUE SE INGRESAN DESDE TECLADO*/
    //cin >> nuevaZona.partido;
    getline(cin,nuevaZona.partido);
    cout << "Ingrese la localidad" << endl;
    //cin >> nuevaZona.localidad;
    getline(cin,nuevaZona.localidad);
    cout << "Ingrese el barrio" << endl;
    //cin >> nuevaZona.barrio;
    getline(cin,nuevaZona.barrio);

    return nuevaZona;
}
cuadra ingresarCuadra()
{
    cuadra nuevaCuadra;
    bool condicion = false;

    while (condicion == false)
    {
        cout << "ingrese el nombre de la calle" << endl;
        cin >> nuevaCuadra.calle;
        cout << "Ingrese el nombre de la primer entrecalle" << endl;
        cin >> nuevaCuadra.entrecalle1;
        cout << "Ingrese en nombre de la segunda entrecalle" << endl;
        cin >> nuevaCuadra.entrecalle2;
        cout << "Ingrese la cantidad de luces con fallas" << endl;
        cin >> nuevaCuadra.luzRota;
        cout << "ingrese la cantidad de luces en correcto funcionamiento" << endl;
        cin >> nuevaCuadra.luz;
    
        /* El IF acontinuacion verifica que se hayan ingresado los datos, ya que mas adelante si algun dato esta mal ingresado
        no permitiria el correcto funcionamiento.*/

        if (nuevaCuadra.calle != "" && nuevaCuadra.entrecalle1 != "" && nuevaCuadra.entrecalle2 != "") 
        {
            condicion = true;
        }
    }
    return nuevaCuadra;
}

void agregarCalleACuadra(cuadra cuadraRevisada[10], cuadra calleRevisada)
{
    int i = 0;
    bool agregado = false;
    while (i <= 9){
        if (cuadraRevisada[i].calle == "" && cuadraRevisada[i].entrecalle1 == "" && cuadraRevisada[i].entrecalle2 == "")
            {
            cuadraRevisada[i] = calleRevisada;
            agregado = true;
            i = 13;
            }
             else{
                    i++;
            }
    }
/* este if avisa al usuario cuando el vector esta completo y no se pueden ingresar nuevos campos.*/
    if (agregado == true){
        cout << "Se pudo agregar la calle correctamente" <<endl;
        }
        else{
            cout << "No se pueden ingresar mas calles" << endl;
        }
}

bool Continuar()
{
    char respuesta = 's';
    bool condicion = false;
    cout << "Desea continuar? ingrese s (para SI) o  n  (para no)" << endl;
    cin >> respuesta;
    while (respuesta != 's' && respuesta != 'n')
    {
        cout << "Debe ingresar s (en minusculas) para continuar o  n  (en minusculas) para no continuar" << endl;
        cin >> respuesta;
    }
    if (respuesta == 's')
    {
        condicion = true;
    }
    else
    {
        condicion = false;
    }
    return condicion;
}

void mostrarZonaRevisada(zona zonaRevisada)
{
    cout << "Los datos de la zona ingresada son:" << endl;
    cout << "Partido: " << zonaRevisada.partido << " localidad: " << zonaRevisada.localidad << " barrio: " << zonaRevisada.barrio << endl;
}

void contadorCuadras(cuadra cuadraRevisada[10])
{
    int i = 0;
    int contador = 0;
    while (i <= 9)
    {
    	if (cuadraRevisada[i].calle != "")
        {
            contador++;
            i++;
        }
        else
        {
            i++;
        }       	
    }
    /*EN ESTE CASO i SE INCREMENTA TANTO EN EL CAMINO IF COMO EN EL ELSE. ES DECIR, i SE INCREMENTA SIEMPRE.
     TENIENDO EN CUENTA ESTO, PODR�AN SACAR i++ FUERA DEL IF-ELSE (A CONTINUACI�N) Y TENERLO UNA SOLA VEZ. 
	 DE ESE MODO, EL ELSE QUEDA VAC�O Y DEBER�A QUITARSE. QUEDANDO DEL SIGUIENTE MODO:
	 while (i <= 9)
    {
    	if (cuadraRevisada[i].calle != "")
        {
            contador++;  
        }
        i++;      	
    }
    DICHO DE OTRO MODO: RECORREN EL VECTOR CON i++, Y CUANDO ENCUENTRAN UNA CUADRA QUE NO ES VACIA ENTONCES
	INCREMENTAN EL contador++	
	*/
    cout << "El total de las calles revisadas es: " << contador << endl;
}

void mostrarCuadrasRevisadas(cuadra cuadraRevisada[10])
{
    int i = 0;
    cout << "Datos de las cuadras ingresadas" << endl;
    while (i <= 9)
    {
        if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].entrecalle1 != "")
        {
            cout << "La calle es: " << cuadraRevisada[i].calle << " la primer entrecalle es: " << cuadraRevisada[i].entrecalle1 << " la segunda entrecalle es: " << cuadraRevisada[i].entrecalle2 << " la cantidad de luces a reparar es: " << cuadraRevisada[i].luzRota << " la cantidad de luces en funcionamiento es: " << cuadraRevisada[i].luz << endl;
            i++;
        }
        else
        {
            cout << "No hay mas cuadras ingresadas" << endl;
            i = 20;
        }
    }
}

void contadorLuces(cuadra cuadraRevisada[10])
{
    int i = 0;
    int contadorLuz = 0;
    int contadorLuzRota = 0;
    while (i <= 9)
    {
        if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].luzRota == 0 && cuadraRevisada[i].luz > 0)
        {
            contadorLuz++;
            i++;
        } 
        else
        {
            if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].luzRota > 0)
            {
                contadorLuzRota++;
                i++;
            }
           else
                i++;
        }
    }
    /*
	OTRA FORMA DE PLANTEAR LA MISMA EVALUACI�N SER�A:
	while (i <= 9)
    {
        if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].luzRota == 0 && cuadraRevisada[i].luz > 0)
             contadorLuz++;
        
        if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].luzRota > 0)
             contadorLuzRota++;
        i++;
    }
    ES DECIR, PUEDEN TENER IF CONSECUTIVOS SIN TENER NECESARIAMENTE ELSE: 
	-SE EVALUA EL PRIMER IF 
	-LUEGO EL SEGUNDO IF
	-Y POR �LTIMO SE INCREMENTE i++ EN CADA CICLO PARA RECORRER EL VECTOR.
	DICHO DE OTRA MODO: RECORREN EL VECTOR DE CUADRAS CON i++. SI LA CUADRA NO TIENE INCONVENIENTES SE 
	INCREMENTA contadorLuz++. SI LA CUADRA TIENE INCONVENIENTES SE INCREMENTA contadorLuzRota++;
	*/
    cout << "La cantidad de calles en correcto funcionamiento es: " << contadorLuz << endl;
    cout << "La cantidad de calles que presentan fallas es: " << contadorLuzRota << endl;
}

void mostrarCuadraMasAfectada(cuadra cuadraRevisada[10])
{
    int i = 0;
    cuadra cuadraMayor;

    cuadraMayor.calle = "";
    cuadraMayor.entrecalle1 = "";
    cuadraMayor.entrecalle2 = "";
    cuadraMayor.luzRota = 0;
    cuadraMayor.luz = 0;

    while (i <= 9)
    {
        if (cuadraRevisada[i].calle != "" && cuadraRevisada[i].luzRota > cuadraMayor.luzRota){
            cuadraMayor = cuadraRevisada[i];
            i++;
        } else{
            i++;
        }
    }
    cout << " Los datos de la cuadra mas afectada son: "<< endl;
    cout << "Calle: " << cuadraMayor.calle << " primer entrecalle: " << cuadraMayor.entrecalle1 << " segunda entrecalle " << cuadraMayor.entrecalle2 << " cantidad de Luz afectadas " << cuadraMayor.luzRota << " cantidad de luces en funcionamiento " << cuadraMayor.luz << endl;
}
