#include <iostream>
using namespace std;

class City {
private:
  string name;
  int population;

public:
  City(string name = "", int population = 0) {
    this->name = name;
    this->population = population;
  }
  ~City() {}
  string getName() { return name; }
  int getPopulation() { return population; }

  void increasePopulation(int n) {
    population = population + n;
  }
  void decreasePopulation(int n) {
    population = population - n;
  }
  bool operator==(const City& ciudad){
        return (this->name == ciudad.name);
      } 
  friend ostream &operator<<(ostream &, const City &);
};

ostream &operator<<(ostream &salida, const City &city) {
  salida << city.name << " :: " << city.population << "\n";
  return salida;
}

/*
Agrega las sobre cargas de operadores necesarias en la clase City.
*/
