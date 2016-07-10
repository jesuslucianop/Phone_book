
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>


using namespace std;

struct Contacto
{
	int id;
	char nombre[50];
	char telefono[13];
};

   	void menu()
	{
		system("cls");
		cout <<" Agenda Telefonica"<<endl;
		cout<< endl << endl <<" Elija una opcion"<<endl;
		cout << endl <<" 1 - Agregar Contactos"<<endl;
		cout << endl <<" 2 - Ver Contactos" << endl;
		cout << endl <<" 3 - Eliminar Contactos" << endl;
		cout << endl <<" 4 - Salir" << endl;

	}





	void verContacto()
	{
		ifstream leer_archivo("Agenda.txt");
		Contacto contacto;

		leer_archivo.read((char *)&contacto, sizeof(contacto));
		if(leer_archivo.fail())
		{
			cout <<" Ocurrio un ploblema, intentando abrir la agenda :(" <<endl;
			exit(1);
		}
		cout <<"id   Nombre     Telefono"<<endl;
		while(!leer_archivo.eof())
		{

			cout <<endl <<contacto.id <<" -> "<<  contacto.nombre << "   " <<contacto.telefono << endl;
			leer_archivo.read((char *)&contacto, sizeof(contacto));

		}
		cout << endl;
		leer_archivo.close();


	}

	void eliminarContacto(int id)
	{

		fstream leer_archivo("Agenda.txt");
		ofstream archivo("borrar.txt");
		Contacto contacto;
		leer_archivo.read((char *)&contacto, sizeof(contacto));

		if(leer_archivo.fail())
		{
			cout <<" Ocurrio un ploblema, intentando abrir la agenda :(" <<endl;
			exit(1);
		}

		while(!leer_archivo.eof())
		{

			if(contacto.id != id)
			{

				archivo.write((char *)&contacto, sizeof(contacto));
			}
			leer_archivo.read((char *)&contacto, sizeof(contacto));
		}
		cout << endl;
		leer_archivo.close();
		archivo.close();

	    remove("Agenda.txt");
		rename("borrar.txt", "Agenda.txt");



	}

int main()
{
	int opcion = 0, salir = 0, p = 0, l = 0, id = 1;

	string nombre, numero;



	do
	{
		menu();
		cin >> opcion;

		switch (opcion)
		{

		case 1:
			do{
				system("cls");

				//guardar(id);

				cout <<endl << "Quieres? " <<endl;
				cout << "1 - Seguir agregando" <<endl;
				cout << "2 - Salir" <<endl;
				cout << "Seleccione una opcion => ";
				cin >>p;
				id++;

			}while (p != 2);

			break;

		case 2:
		system("cls");
		cout << "Contactos" <<endl<<endl;
		verContacto();
	    cout <<endl<< "1 - Salir" <<endl;
		cout <<endl<< "Seleccione la opcion para salir: ";
		cin >>salir;
		if(salir == 1)
		{
			menu();
		}
			break;

		case 3:
			do{
				system("cls");
				cout << "Eliminar contactos" <<endl<<endl;
				verContacto();
				cout <<endl << "Seleccione el contacto : ";
				cin >>l;
				eliminarContacto(l);

			    cout <<endl<< "1 - Salir" <<endl;
				cout <<endl<< "2 - Seguir eliminando" <<endl;
				cout <<endl<< "Seleccione la opcion para salir: ";
				cin >>salir;
				if(salir == 1)
				{
					menu();
				}

			}while(salir != 1);
			break;

		}

	} while (opcion != 4);

	system("pause");
	return 0;
}

