// AUTORES
// Iván Santiago Hernández Mendoza - A01662556
// Diego Esteban Zepeda Ceballos - A01026512
// Moisés Arturo Badillo Álvarez - A00834306

// INICIALIZAR EL CÓDIGO CON LOS SIGUIENTES COMANDOS EN SHELL, APLICANDO EL
// ARGUMENTO DE LÍNEA DE COMANDO PARA DETECTAR EL ARCHIVO DE BITACORA:
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

#include "lista.h"
#include "persona.h"
#include "hashtablevd.h"

int main(int argc, char **argv) {
  argv[0] = "./main";
  argv[1] = "bitacora3.csv";
  
  /*for (int i = 0; i < argc; ++i) {
    cout << argv[i] << endl;
  }*/
  cout << "Leyendo el archivo... " << argv[1] << endl;

  vector<vector<string>> content;
  vector<string> row;
  string line, word;

  fstream file(argv[1], ios::in);
  if (file.is_open()) {
    while (getline(file, line)) {
      row.clear();
      stringstream str(line);
      while (getline(str, word, ',')) {
        row.push_back(word);
      }
      content.push_back(row);
    }
    cout << "Archivo leido con exito.\nOrdenando datos... tardara un rato si son bastantes datos." << endl;
  } else {
    cout << "Could not open the file\nPlease write ./main followed by the csv file you want to open.\n";
    exit(0);
  }

  // 0. y 1.
  Hashtable<int, Persona> users(content.size());
  Hashtable<string, int> cities(content.size());
  string fname, lname, gender, bdate, tel, email, cityName, stateName;
  int id, zip, poblacion;
  int numCities = 0;
  // 2.
  Stack<Persona> pila1;
  Stack<Persona> pila2;
  Persona auxPersona;
  // 3.
  Queue<Persona> fila1;
  Queue<Persona> fila2;
  Persona minZip;
  for (int i = 1; i < content.size(); i++) {
    id = stoi(content[i][0]);
    fname = content[i][1];
    lname = content[i][2];
    gender = content[i][3];
    bdate = content[i][4];
    tel = content[i][5];
    email = content[i][6];
    zip = stoi(content[i][7]);
    cityName = content[i][8];
    stateName = content[i][9];
    Persona persona(id, fname, lname, gender, bdate, tel, email, zip, cityName, stateName);
    users.put(i, persona);
    // 1. CENSO POBLACIONAL
    if(cities.contains(cityName)) {
      poblacion = cities.get(cityName);
      poblacion += 1;
    } else {
      poblacion = 1;
      numCities += 1;
    }
    cities.put(cityName, poblacion);
    // 2. HABITANTES SEGUN APELLIDO
    do {
      if (pila1.is_empty()) {
        pila1.push(persona);
        break;
      } else {
        auxPersona = pila1.pop();
        if (lname >= auxPersona.getLname()) {
          pila1.push(auxPersona);
          pila1.push(persona);
          break;
        } else {
          pila2.push(auxPersona);
        }
      }
    } while(true);
    while (!(pila2.is_empty())) {
      auxPersona = pila2.pop();
      pila1.push(auxPersona);
    }
    // 3. SEGUN ZIP  
    fila1.enqueue(persona);
  }
  // Variables
  int answer;
  do {
    cout << "\n---------------------" << endl;
    cout << "-----EVIDENCIA 3-----" << endl;
    cout << "---------------------" << endl;
    cout << "ESTRUCTURA DE DATOS LINEALES" << endl;
    cout << "Created by..." << endl;
    cout << "Iván Santiago Hernández Mendoza - A01662556" << endl;
    cout << "Diego Esteban Zepeda Ceballos - A01026512" << endl;
    cout << "Moisés Arturo Badillo Álvarez - A00834306" << endl;
    cout << "\n----OPCIONES----\n0. Imprimir todos los habitantes\n1. Censo poblacional\n2. Ordenar habitantes segun su apellido\n3. Imprimir habitantes segun su ZIP y prioridad menor.\n(Tarda mucho con demasiados datos y puede que se acabe la memoria. Es por ello que usamos 3 archivos de bitácora, cada uno con menos datos, para corroborar el funcionamiento de nuestros procedimientos.) \n4. Salir" << endl;
    cin >> answer;
    if (answer == 0) {
      cout << "\n----HABITANTES----" << endl;
      users.print();
    } else if (answer == 1) {
      cout << "\n----CENSO POBLACIONAL----" << endl;
      cities.print();
      cout << numCities << " different cities." << endl;
    } else if (answer == 2) {
      cout << "\n----HABITANTES SEGUN APELLIDO----" << endl;
      pila1.print();
    } else if (answer == 3) {
      cout << "\n----HABITANTES SEGUN ZIP----" << endl;
      if (fila1.is_empty()) {
        while (!(fila2.is_empty())) {
          minZip = fila2.dequeueMinZip();
          cout << minZip.getZip() << ": " << minZip << endl;
          fila1.enqueue(minZip);
        }
      } else {
        while (!(fila1.is_empty())) {
          minZip = fila1.dequeueMinZip();
          cout << minZip.getZip() << ": " << minZip << endl;
          fila2.enqueue(minZip);
        }
      }
    } else if (answer == 4) {
      cout << "Adios!" << endl;
      break;
    } else {
      cout << "\nOpcion no valida" << endl;
    }
  } while (true);

  // cout << argv[0] << endl;
  // cout << argv[1] << endl;
  // cout << "finito" << endl;
}
