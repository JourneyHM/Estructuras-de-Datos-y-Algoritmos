#include <iostream>
using namespace std;

class Persona{
  private:
    int id, zip;
    string first_name,last_name, city;
  public:
      Persona(int id = 0,  string fname = "", string lname = "", int zip = 0, string city = ""){
        this->id = id;
        this->zip = zip;
        this->first_name = fname;
        this->last_name = lname;
        this->city = city;
      }
    ~Persona(){ } //Destructor 
    string getCity(){return city;}
    
    string getFirstName(){return first_name;}
      
      bool operator>(const Persona & user){
        return (this->last_name > user.last_name);
      }
      
      bool operator>( const string & last_name){
        return (this->last_name > last_name);
      } 

      bool operator==(const string & last_name){
        return (this->last_name == last_name);
      } 

       bool operator<(const Persona & user){
        return (this->last_name > user.last_name);
      }
      
      bool operator<( const string & last_name){
        return (this->last_name < last_name);
      } 

      bool operator<=( const string & last_name){
        return (this->last_name <= last_name);
      } 

      bool operator<=( const Persona & user){
        return (this->last_name <= user.last_name);
      } 

    
      friend ostream & operator<<( ostream &, const Persona &);


};

ostream & operator<<( ostream & salida, const Persona & user){
    salida << user.id << " :: " << user.first_name << " :: " << user.last_name << " :: " << user.zip << " :: " << user.city << "\n";
    return salida;
  }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/
    
