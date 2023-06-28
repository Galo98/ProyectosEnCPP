#include <iostream>
#include <string>

using namespace std; 

int main()
{
string apellido=" ";
string nombre=" ";
int nota=0;
cout<<"\nIngrese el apellido del estudiante: ";
cin>>apellido;
cout<<"\nIngrese el nombre del estudiante: ";
cin>>nombre;
cout<<"\nIngrese la nota del estudiante: ";
cin>>nota;
if(nota >= 4 )
{
	cout <<"El estudiante esta aprobado";
}
else
{
	cout << "El estudiante esta desaprobado";
}		
return 0;
}

