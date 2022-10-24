// AUTOR
// Iván Santiago Hernández Mendoza
// A01662556

// Diego Esteban Zepeda Ceballos
// A01026512

// Moises Arturo Badillo Álvarez
// A00834306

// REFERENCIAS
// https://java2blog.com/read-csv-file-in-cpp/#C_Code_To_Read_A_CSV_File
// https://es.acervolima.com/ordenar-strings-usando-bubble-sort/
// https://stackoverflow.com/questions/22892323/how-to-bubble-sort-a-string

//COMPLEJIDAD DE NUESTRO CÓDIGO
// O(N^2)

// LIBRERÍAS
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

// DEFINICIÓN DE FUNCIONES
void bubblesort(int n, string arr[]) {
  for (int i = 1; i < n; i++) // for n-1 passes
  {
    // In pass i,compare the first n-i elements
    // with their next elements
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        string temp;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void display(int n, string arr[]) {
  cout << endl;
  cout << "----------------------\n";
  cout << "Sorted array elements \n";
  cout << "----------------------\n";
  for (int j = 0; j < n; j++)
    cout << arr[j] << endl;
}
/*
void busqSec(string dato, string arr[]){
  string band = "F";
  int i = 0;
  while((band == "F")&&(i<16377)){
    if(arr[i]==dato){
    band = "V";
    }
    i++;
  }

  if(band=="V"){
    cout<<arr[i-1]<<endl;
  }
}
*/

void busqSec(char ans, int n, string arr[]) {
  vector<string> result;

  for (int k = 0; k < n; k++) {
    string title = arr[k];
    char letter = title[0];
    if (ans == letter) {
      result.push_back(title);
      cout << title << endl;
      
    
    
  }
}
  }


void datos(int n, string arr[]){
  ofstream myFile;
  myFile.open("orderedNames.csv");
  for (int i = 0; i<n; i++){
  myFile<<arr[i]<<endl;
  }
}
 

// PROGRAMA PRINCIPAL
int main() {
  char ans;
  cout << "-------ACTIVIDAD INTEGRADORA-------" << endl;
  cout << "" << endl;
  cout << "Created by..." << endl;
  cout << "Iván Santiago Hernández Mendoza - A01662556" << endl;
  cout << "Diego Esteban Zepeda Ceballos - A01026512" << endl;
  cout << "Moises Arturo Badillo Álvarez - A00834306" << endl;
  cout << "" << endl;

  string fname;
  cout << "Enter the file name: ";
  cin >> fname;
  cout << "" << endl;
  cout << "------------SUPERHEROES------------" << endl;
  string names[16377] = {};
  string line, word;
  int cont = 0;

  fstream file(fname, ios::in);
  if (file.is_open()) {
    while (getline(file, line)) {
      stringstream str(line);

      while (getline(str, word))
        names[cont] = word;
      cont++;
    }
  } else
    cout << "Could not open the file\n";

  bubblesort(16377, names);
  display(16377, names);

  cout << "" << endl;
  cout << "------------------------------" << endl;
  cout << "Búsqueda por letra inicial: ";
  cin >> ans;
  ans = toupper(ans);
  cout << "" << endl;
  cout << "---------RESULTADOS DE LA BUSQUEDA---------" << endl;
  datos(16377, names);
  busqSec(ans, 16377, names);
  return 0;
}
