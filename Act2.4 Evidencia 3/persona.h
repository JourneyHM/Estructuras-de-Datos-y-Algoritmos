#include <iostream>
using namespace std;

class Persona;
ostream &operator<<(ostream &, const Persona &);

class Persona {
private:
  string first_name, last_name, gender, birth_date, tel, email, city, state;
  int id, zip;
  
public:
  Persona(int id = 0, string fname = "", string lname = "", string gender = "", string bdate = "", string tel = "", string email = "", int zip = 0, string city = "", string state = "") {
    this->id = id;
    this->first_name = fname;
    this->last_name = lname;
    this->gender = gender;
    this->birth_date = bdate;
    this->tel = tel;
    this->email = email;
    this->zip = zip;
    this->city = city;
    this->state = state;
  }

  bool operator>( const string & last_name){
    return (this->last_name > last_name);
  }

  bool operator<( const string & last_name){
    return (this->last_name < last_name);
  } 

  friend ostream &operator<<(ostream &, const Persona &);

  int getId() const { return id; }
  string getFname() const { return first_name; }
  string getLname() const { return last_name; }
  string getGender() const { return gender; }
  string getBdate() const { return birth_date; }
  string getTel() const { return tel; }
  string getEmail() const { return email; }
  int getZip() const { return zip; }
  string getCity() const { return city; }
  string getState() const { return state; }
};

ostream &operator<<(ostream &salida, const Persona &persona) {
  salida << to_string(persona.getId()) << " || " << persona.getFname() << " || " << persona.getLname() << " || " << persona.getGender() << " || " << persona.getBdate() << " || " << persona.getTel() << " || " << persona.getEmail() << " || " << to_string(persona.getZip()) << " || " << persona.getCity() << " || " << persona.getState();
  return salida;
}