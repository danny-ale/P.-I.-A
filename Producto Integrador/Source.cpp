#include <iostream>
#include <string>
#include<fstream>
#include<windows.h>

using namespace std;
struct Cita {
	string nombre;
	string hora;
	int num = 0;
	int cant = 0;
	int n = 0;
	Cita* anterior = nullptr;
	Cita* siguiente = nullptr;
};

int option = 0;
int No = 1;
int counter = 1;
int conteo = 1;
int num_Cita = 0;
int eleccion = 0;
int vez = 1;
int numero = 1;
string nuevo = "";

Cita* Primer = nullptr;
Cita* Ultimo = nullptr;
Cita* Auxiliar = nullptr;

void menu();
void Imprimir_Cita();
void registro_Cita();
void cambiar_Cita();
void eliminar_Cita();
void Guardar_Cita();
void leer_Archivo();
void registro_Corto(string nombre, string hora, int num, int cant);

int main() {
	while (1 == 1) {
		menu();
	}

}

void menu() {
	cout << "Bienvenido a Clinica Dental del Norte\n";
	cout << "Por Favor eliga una de estas opciones\n";
	cout << "1.Agendar Cita\n";
	cout << "2.Modificar Cita\n";
	cout << "3.Eliminar Cita\n";
	cout << "4.Lista de Citas Vigentes\n";
	cout << "5.Salir\n";
	cin >> option;
	cin.ignore();
	system("cls");
	if (vez == 1) {
		leer_Archivo();
	}

	switch (option) {
	case 1: {
		registro_Cita();
		Guardar_Cita();
		vez = 1;
		break; }

	case 2: {
		cambiar_Cita();
		break; }

	case 3: {
		eliminar_Cita();
		Guardar_Cita();
		break; }

	case 4: {
		Imprimir_Cita();
		break; }

	case 5: {
		exit(EXIT_SUCCESS);
		break; }
	}
}

void Imprimir_Cita() {
	if (Primer) {
		Auxiliar = Primer;
		while (Auxiliar) {
			cout << "\nPaciente No." << Auxiliar->n;
			cout << "\nNombre del paciente:" << Auxiliar->nombre;
			cout << "\nHora del tratamiento (Formato 24 Horas):" << Auxiliar->hora;
			switch (Auxiliar->num) {
			case 1: {
				cout << "\nNombre del tratamiento:Limpieza Dental\n";
				cout << "Descripcion:Consiste en una intervencion odontologica que eliminala placa bacteriana y el sarro acumulado";
				cout << "\nCosto:$589";
				cout << "\nTotal:" << Auxiliar->cant * 589 << endl;
				break; }
			case 2: {
				cout << "\nNombre de tratamiento:Extraccion de Muelas del juicio y otras piezas bucales\n";
				cout << "Descripcion:Procedimiento quirurgico para la extraccion de alguna pieza bucal";
				cout << "\nCosto:$900";
				cout << "\nTotal:" << Auxiliar->cant * 900 << endl;
				break; }
			case 3: {
				cout << "\nNombre del tratamiento:Aplicacion de Carillas Bucales\n";
				cout << "Descripcion; Implantacion de unas fundas esteticas compuestas por porcelana y resinas dentales que se colocan sobre nuestros dientes simulando su apariencia.";
				cout << "\nCosto:$1500";
				cout << "\nTotal:" << Auxiliar->cant * 1500 << endl;
				break; }
			case 4: {
				cout << "\nNombre del tratamiento:Ortodoncia\n";
				cout << "Descripcion:Tratamiento bucal que se utiliza para corregir los problemas de la mordida, tiene como principal objetivo alinear los dientes y la mandibula.";
				cout << "\nCosto:$7000";
				cout << "\nTotal:" << Auxiliar->cant * 7000 << endl;
				break; }
			}
			Auxiliar = Auxiliar->siguiente;
		}
	}
	else {
		cout << "Aun no existen registros\n";
	}
	system("pause");
	system("cls");
}

void registro_Corto(string nombre, string hora, int num, int cant) {
	Cita* Paciente = new Cita;
	Paciente->n = numero;
	Paciente->nombre = nombre;
	Paciente->hora = hora;
	Paciente->num = num;
	Paciente->cant = cant;

	if (numero == 1) {
		Primer = Paciente;
		Ultimo = Paciente;
	}
	numero++;
	counter++;
}

void registro_Cita() {
	Cita* Paciente = new Cita;
	Paciente->n = counter;
	if (Primer == NULL) {
		counter = 1;
	}
	do {
		cout << "     *******************     " << endl;
		cout << "-----* APARTADO NOMBRE *-----" << endl;
		cout << "     *******************     " << endl;
		cout << "Ingrese su nombre completo\n";
		std::getline(cin, Paciente->nombre);
		system("cls");
	} while (Paciente->nombre == "");

	do {
		cout << "     *****************     " << endl;
		cout << "-----* APARTADO HORA *-----" << endl;
		cout << "     *****************     " << endl;
		cout << "Ingrese la hora del tratamiento (en formato de 24 horas)\n";
		std::getline(cin, Paciente->hora);
		system("cls");
	} while (Paciente->hora == "");


	do {
		cout << "     ************************     " << endl;
		cout << "-----* APARTADO TRATAMIENTO *-----" << endl;
		cout << "     ************************     " << endl;
		cout << "Ingrese el numero del tratamiento a elegir\n";
		cout << "TRATAMIENTO 1\nNombre:Limpieza Dental\n";
		cout << "Descripcion:Consiste en una intervencion odontologica que eliminala placa bacteriana y el sarro acumulado";
		cout << "\nCosto:$589";
		cout << endl;
		cout << "TRATAMIENTO 2\nNombre:Extraccion de Muelas del juicio y otras piezas bucales\n";
		cout << "Descripcion:Procedimiento quirurgico para la extraccion de alguna pieza bucal";
		cout << "\nCosto:$900";
		cout << endl;
		cout << "TRATAMIENTO 3\nNombre:Aplicacion de Carillas Bucales\n";
		cout << "Descripcion; Implantacion de unas fundas esteticas compuestas por porcelana y resinas dentales que se colocan sobre nuestros dientes simulando su apariencia.";
		cout << "\nCosto:$1500";
		cout << endl;
		cout << "TRATAMIENTO 4\nNombre:Ortodoncia\n";
		cout << "Descripcion:Tratamiento bucal que se utiliza para corregir los problemas de la mordida, tiene como principal objetivo alinear los dientes y la mandibula.";
		cout << "\nCosto:$7000";
		cout << endl;
		cout << "Ingrese la opcion de tratamiento: ";
		cin >> Paciente->num;
		cin.ignore();
	} while (Paciente->num == 0);
	cout << "Gracias numero valido" << endl;
	system("pause");
	system("cls");

	do {
		cout << "     *********************     " << endl;
		cout << "-----* APARTADO CANTIDAD *-----" << endl;
		cout << "     *********************     " << endl;
		cout << "Ingrese la cantidad de tratamiento que se recibira\n";
		cin >> Paciente->cant;
		cin.ignore();
	} while (Paciente->cant == 0);
	cout << "Gracias numero valido" << endl;
	system("pause");
	system("cls");

	if (counter == 1) {
		Primer = Paciente;
		Ultimo = Paciente;
	}
	else if (counter != 1) {
		Paciente->anterior = Ultimo;
		Ultimo->siguiente = Paciente;
		Ultimo = Paciente;
	}
	counter++;
}

void cambiar_Cita() {
	Auxiliar = Primer;
	if (!Auxiliar) {
		cout << "Aun no existen citas para cambiar\n";
		system("pause");
		system("cls");
		menu();
	}
	else {
		cout << "----Estas son las citas disponibles---";
		while (Auxiliar) {
			cout << "\nPaciente No." << Auxiliar->n;
			cout << "\nNombre del paciente:" << Auxiliar->nombre;
			cout << "\nHora del tratamiento (Formato 24 Horas):" << Auxiliar->hora;
			cout << endl;
			Auxiliar = Auxiliar->siguiente;
		}

		cout << "\nIngrese el Numero de Cita a cambiar o presione 0 para volver al inicio.\n";
		cin >> num_Cita;
		system("pause");
		system("cls");
		if (num_Cita == 0) {
			menu();
		}

		if (num_Cita != 0) {
			Auxiliar = Ultimo;
			while (num_Cita != Auxiliar->n) {
				Auxiliar = Auxiliar->anterior;
			}

			cout << "¿Que desea modificar?";
			cout << "\n1.Nombre";
			cout << "\n2.Hora de la cita";
			cout << "\n3.Tipo de tratamiento";
			cout << "\n4.Cantidad de tratamiento\n";
			cin >> eleccion;
			system("pause");
			system("cls");
			switch (eleccion) {
			case 1: {
				cout << "Ingrese el nuevo nombre completo\n";
				cin.ignore();
				std::getline(cin, nuevo);
				Auxiliar->nombre = nuevo;
				break; }
			case 2: {
				cout << "Ingrese la nueva hora\n";
				cin >> nuevo;
				Auxiliar->hora = nuevo;
				cin.ignore();
				break; }
			case 3: {
				cout << "TRATAMIENTO 1\nNombre:Limpieza Dental\n";
				cout << "Descripcion:Consiste en una intervencion odontologica que eliminala placa bacteriana y el sarro acumulado";
				cout << "\nCosto:$589";
				cout << endl;
				cout << "TRATAMIENTO 2\nNombre:Extraccion de Muelas del juicio y otras piezas bucales\n";
				cout << "Descripcion:Procedimiento quirurgico para la extraccion de alguna pieza bucal";
				cout << "\nCosto:$900";
				cout << endl;
				cout << "TRATAMIENTO 3\nNombre:Aplicacion de Carillas Bucales\n";
				cout << "Descripcion; Implantacion de unas fundas esteticas compuestas por porcelana y resinas dentales que se colocan sobre nuestros dientes simulando su apariencia.";
				cout << "\nCosto:$1500";
				cout << endl;
				cout << "TRATAMIENTO 4\nNombre:Ortodoncia\n";
				cout << "Descripcion:Tratamiento bucal que se utiliza para corregir los problemas de la mordida, tiene como principal objetivo alinear los dientes y la mandibula.";
				cout << "\nCosto:$7000";
				cout << endl;
				cout << "\nIngrese el nuevo numero de tratamiento\n";
				cin >> nuevo;
				Auxiliar->num = stoi(nuevo);
				cin.ignore();
				break; }
			case 4: {
				cout << "Ingrese la nueva cantidad\n";
				cin >> nuevo;
				Auxiliar->cant = stoi(nuevo);
				cin.ignore();
				break; }
				  cout << "La cita se ha modificado con exito";
			}
		}
		system("pause");
		system("cls");
	}
}

void eliminar_Cita() {
	if (Primer) {
		Auxiliar = Primer;
		cout << "----Estas son las citas disponibles---";
		while (Auxiliar) {
			cout << "\nPaciente No." << Auxiliar->n;
			cout << "\nNombre del paciente:" << Auxiliar->nombre;
			cout << "\nHora del tratamiento (Formato 24 Horas):" << Auxiliar->hora;
			cout << endl;
			Auxiliar = Auxiliar->siguiente;
		}
		cout << "\nIngrese el Numero de Cita a eliminar o presione 0 para volver al inicio.";
		cin >> num_Cita;
		system("pause");
		system("cls");
		if (num_Cita == 0) {
			void menu();
		}
		else if (num_Cita != 0) {
			Auxiliar = Primer;
			while (num_Cita != Auxiliar->n) {
				Auxiliar = Auxiliar->siguiente;
			}

			if (Auxiliar == Primer) {
				if (Auxiliar->siguiente != nullptr) {
					Primer = Auxiliar->siguiente;
				}
				else {
					Primer = nullptr;
				}
				delete Auxiliar;
			}
			else {
				Auxiliar = Auxiliar->anterior;
				Auxiliar->siguiente = Auxiliar->siguiente->siguiente;
			}
		}
	}
	else {
		cout << "Aun no existen citas para eliminar\n";
		system("pause");
		system("cls");
		menu();
	}
}

void Guardar_Cita() {
	ofstream archivo;
	archivo.open("registros.txt");
	if (Primer) {
		Auxiliar = Primer;
		while (Auxiliar) {
			archivo << Auxiliar->nombre << endl;
			archivo << Auxiliar->hora << endl;
			archivo << Auxiliar->num << endl;
			archivo << Auxiliar->cant << endl;
			Auxiliar = Auxiliar->siguiente;
		}
	}
	archivo.close();

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
	}

	ofstream archivo_txt;
	archivo_txt.open("Citas.txt");
	if (Primer) {
		Auxiliar = Primer;
		while (Auxiliar) {
			archivo_txt << "\nPaciente No." << Auxiliar->n;
			archivo_txt << "\nNombre del paciente:" << Auxiliar->nombre;
			archivo_txt << "\nHora del tratamiento (Formato 24 Horas):" << Auxiliar->hora;
			switch (Auxiliar->num) {
			case 1: {
				archivo_txt << "\nNombre del tratamiento:Limpieza Dental\n";
				archivo_txt << "Descripcion:Consiste en una intervencion odontologica que eliminala placa bacteriana y el sarro acumulado";
				archivo_txt << "\nCosto:$589";
				archivo_txt << "\nTotal:" << Auxiliar->cant * 589 << endl;
				break; }
			case 2: {
				archivo_txt << "\nNombre de tratamiento:Extraccion de Muelas del juicio y otras piezas bucales\n";
				archivo_txt << "Descripcion:Procedimiento quirurgico para la extraccion de alguna pieza bucal";
				archivo_txt << "\nCosto:$900";
				archivo_txt << "\nTotal:" << Auxiliar->cant * 900 << endl;
				break; }
			case 3: {
				archivo_txt << "\nNombre del tratamiento:Aplicacion de Carillas Bucales\n";
				archivo_txt << "Descripcion; Implantacion de unas fundas esteticas compuestas por porcelana y resinas dentales que se colocan sobre nuestros dientes simulando su apariencia.";
				archivo_txt << "\nCosto:$1500";
				archivo_txt << "\nTotal:" << Auxiliar->cant * 1500 << endl;
				break; }
			case 4: {
				archivo_txt << "\nNombre del tratamiento:Ortodoncia\n";
				archivo_txt << "Descripcion:Tratamiento bucal que se utiliza para corregir los problemas de la mordida, tiene como principal objetivo alinear los dientes y la mandibula.";
				archivo_txt << "\nCosto:$7000";
				archivo_txt << "\nTotal:" << Auxiliar->cant * 7000 << endl;
				break; }
			}
			Auxiliar = Auxiliar->siguiente;
		}
	}
	archivo_txt.close();

	if (archivo_txt.fail()) {
		cout << "No se pudo abrir el archivo";
	}
}

void leer_Archivo() {
	ifstream txt;
	txt.open("registros.txt");
	string texto = "";
	Cita* Prueba = new Cita;
	while (getline(txt, texto)) {
		if (conteo == 1) {
			Prueba->nombre = texto;
			conteo++;
		}
		else if (conteo == 2) {
			Prueba->hora = texto;
			conteo++;
		}
		else if (conteo == 3) {
			Prueba->num = stoi(texto);
			conteo++;
		}
		else {
			Prueba->cant = stoi(texto);
			conteo = 1;
		}
		if (Prueba->cant != 0) {
			registro_Corto(Prueba->nombre, Prueba->hora, Prueba->num, Prueba->cant);
		}
	}
	txt.close();
}
