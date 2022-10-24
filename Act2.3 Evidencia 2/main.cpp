// AUTORES
// Iván Santiago Hernández Mendoza - A01662556
// Diego Esteban Zepeda Ceballos - A01026512
// Moisés Arturo Badillo Álvarez - A00834306

// INICIALIZAR EL CÓDIGO CON LOS SIGUIENTES COMANDOS EN SHELL, APLICANDO EL ARGUMENTO DE LÍNEA DE COMANDO PARA DETECTAR EL ARCHIVO DE BITACORA:
//  g++ main.cpp -o main
// ./main bitacora.csv

#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
#include "city.h"
#include "lista.h"
#include "hashtablevd.h"
#include "persona.h"

// FUNCIONES

int partition(LinkedList<Persona> &lista, int l, int h) {
  Persona x = lista.get(h);
  int i = (l - 1);

  for (int j = l; j <= h - 1; j++) {
    if (lista.get(j) <= x) {
      i++;
      // swap (&arr[i], &arr[j]);
      Persona temporal = lista.get(i);
      lista.set(i, lista.get(j));
      lista.set(j, temporal);
    }
  }
  // swap (&arr[i + 1], &arr[h]);
  Persona temporal = lista.get(i + 1);
  lista.set(i + 1, lista.get(h));
  lista.set(h, temporal);
  return (i + 1);
}

template <typename T> void quickSort(LinkedList<T> &lista, int l, int h) {
  if (l < h) {
    int p = partition(lista, l, h); /* Partitioning index */
    quickSort(lista, l, p - 1);
    quickSort(lista, p + 1, h);
  }
}

int busquedaFirstName(LinkedList<Persona> &lista, string first_name) {
  int count = 0;
  for (int i = 0; i < lista.size(); i++) {
    Persona user = lista.get(i); // O(n)
    if (user.getFirstName() == first_name) {
      count++;
    }
  }
  return count;
}

// void cityHabitants(LinkedList<Persona> &lista) {}

template <typename T, typename S>
void busquedaBinaria(LinkedList<T> &lista, S busco) {
  int mitad;
  int inf = 0;
  int sup = lista.size();
  bool band = false;

  while (inf <= sup) {
    mitad = (inf + sup) / 2;

    if (lista.get(mitad) == busco) {
      band = true;
      break;
    }
    if (lista.get(mitad) > busco) {
      sup = mitad;
      mitad = (inf + sup) / 2;
    }
    if (lista.get(mitad) < busco) {
      inf = mitad;
      mitad = (inf + sup) / 2;
    }
  }
  if (band == true) {
    cout << "El usuario se ha encontrado con éxito" << endl;
    cout << lista.get(mitad) << endl;
  } else {
    cout << "Usuario no encontrado" << endl;
  }
}

// PROGRAMA PRINCIPAL
int main(int argc, char **argv) {

  for (int i = 0; i < argc; ++i) {
    cout << argv[i] << endl;
  }
  cout << "Leyendo el archivo..." << endl;

  vector<vector<string>> content;
  vector<string> row;
  string line, word;

  fstream file(argv[1], ios::in);
  if (file.is_open()) {
    while (getline(file, line)) {
      row.clear();

      stringstream str(line);

      while (getline(str, word, ','))
        row.push_back(word);
      content.push_back(row);
    }
  } else {
    cout << "Could not open the file\n";
  }

  LinkedList<City> cities;
  LinkedList<Persona> users;
  string firstname, lastname, cityName;
  for (int i = 0; i < content.size(); i++) {
    int id = stoi(content[i][0]);
    string fn = content[i][1];
    string ln = content[i][2];
    int zip = stoi(content[i][3]);
    string cityName = content[i][4];
    users.addLast(Persona(id, fn, ln, zip, cityName));

    /* Si sirve, pero la complejidad es extremadamente alta y tarda demasiado tiempo en compilar. Si se hace con menos datos se puede demostrar que si sirve.
    if (cities.size() == 0) {
      cities.addLast(City(cityName, 1));
    } else {
      int pos = -1;
      for (int j = 0; j < cities.size(); j++) {
        City checkingCity = cities.get(j);
        if (checkingCity.getName() == cityName) {
          pos = j;
          break;
        }
      }
      if (pos == -1) {
        cities.addLast(City(cityName, 1));
      } else {
        City checkingCity = cities.get(pos);
        checkingCity.increasePopulation(1);
        cities.remove(pos);
        cities.addLast(checkingCity);
      }
    }*/
  }

  // DESPLIEGUE DE LISTA LIGADA CON USUARIOS
  cout << users << endl;
  cout << "--" << endl;
  // DESPLIEGUE DE LISTA LIGADA CON CIUDADES
  cout << cities << endl;

  cout << "" << endl;
  cout << "Usuarios cargados con éxito..." << endl;
  cout << "" << endl;

  // Variables
  int answer;

  cout << "---------------------" << endl;
  cout << "-----EVIDENCIA 2-----" << endl;
  cout << "---------------------" << endl;
  cout << "ESTRUCTURA DE DATOS LINEALES" << endl;
  cout << "" << endl;

  cout << "Created by..." << endl;
  cout << "Iván Santiago Hernández Mendoza - A01662556" << endl;
  cout << "Diego Esteban Zepeda Ceballos - A01026512" << endl;
  cout << "Moisés Arturo Badillo Álvarez - A00834306" << endl;
  cout << "" << endl;

  do {
    cout << "" << endl;
    cout << "----SELECCIONE UNA OPCION----" << endl;
    cout << "" << endl;
    cout << "1. ¿Cuáles son las cinco ciudades con mayor número de personas "
            "registradas?"
         << endl;
    cout << "2. ¿Con qué frecuencia se repite un nombre en la lista ligada?"
         << endl;
    cout << "3. ¿Cuántos habitantes existen por ciudad?" << endl;
    cout << "4. Lista ligada ordenada usando el last name de cada usuario"
         << endl;
    cout << "5. Ingrese el last name de la persona a buscar" << endl;
    cout << "6. SALIR" << endl;
    cout << "" << endl;
    cin >> answer;

    if (answer == 1) {
      cout << "TOP 5 CIUDADES" << endl;
      cout << "" << endl;
      cout << "Complejidad: O()" << endl;
    } else if (answer == 2) {
      cout << "Ingrese nombre a buscar" << endl;
      cin >> firstname;
      int rep = busquedaFirstName(users, firstname);
      cout << firstname << " se repite: " << rep << " veces " << endl;
      cout << "" << endl;
      cout << "Complejidad: O(n^2)" << endl;
    } else if (answer == 3) {
      cout << cities << endl;;
      cout << "" << endl;
      cout << "Complejidad: O()" << endl;
    } else if (answer == 4) {
      quickSort(users, 0, users.size() - 1);
      cout << users << endl;
      cout << "" << endl;
      cout << "Complejidad: O()" << endl;
    } else if (answer == 5) {
      cout << "Inserte apellido a buscar" << endl;
      cin >> lastname;
      busquedaBinaria(users, lastname);
      cout << "" << endl;
      cout << "Complejidad: O(n^4)" << endl;
    } else if (answer == 6) {
      cout << "Adios!" << endl;
      break;
    } else {
      cout << "Opción no válida, seleccione una nueva" << endl;
      cin >> answer;
    }
  } while (true);

  return 0;
}
