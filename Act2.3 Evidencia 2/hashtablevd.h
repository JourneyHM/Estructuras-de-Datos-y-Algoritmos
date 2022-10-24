#include <iostream>
using namespace std;

template<typename K, typename T> /* K key, T value*/
class HashPair{
  public:
    K key;
    T value;
    HashPair(K key, T value ){
      this->key = key;
      this->value  = value;
    }
     HashPair(){
    }
};
template<typename K, typename T> 
class Hashtable{
    private:
        int size;
       LinkedList<HashPair<K,T>*>*tabla;
        int fh(K key) const{
          hash<K> hasher;
          return hasher(key) % size;
        }
    public:
      Hashtable(int _size){
        this->size = _size;
        tabla = new LinkedList<HashPair<K,T>*>[_size];
        for(int i = 0; i<_size; i++){
          tabla[i] = LinkedList<HashPair<K,T>*>();
        }
      }

      bool put(K key, T value) {
        int posicion = fh(key);
        LinkedList<HashPair<K,T>*> lista = tabla[posicion];
        int indice = -1;
        for(int i = 0; i<lista.size(); i++) {
          if(lista.get(i)->key == key) {
            indice = i;
          }
        }
        if(indice >= 0) {
          lista.get(indice)->value= value;
        }else{
          tabla[posicion].addLast(new HashPair<K,T>(key, value));
        }
        return (indice >= 0) ? 0: 1;
      }


      T get(K key)const{
          int posicion = fh(key);
          cout << posicion << endl;
          LinkedList<HashPair<K,T>*> lista = tabla[posicion];
          cout << lista << endl;
          cout << lista.size() << endl;
          cout << size << endl;
          int indice = -1;
          for(int i = 0; i<lista.size(); i++){
            cout << "lista.get(i)->key" << (lista.get(i)->key) << endl; // no imprime nada aqui, creo que el put esta mal. Nunca se agrega a la hashtable nada
            if(lista.get(i)->key == key){
              indice = i;
            }
          }
          if(indice<0) throw -1;
          return lista.get(indice)->value;
        }

        


      /*T get(K key)const{
          int posicion = fh(key);
          LinkedList<HashPair<K,T>*> lista = tabla[posicion];
          cout << "Lista: " << endl;
          cout << lista << endl;
          int indice = -1;
          for(int i = 0; i<lista.size(); i++){
            cout << "Key: " << endl;
            cout << key << endl;
            cout << posicion << endl; // aqui no esta dando nada
            if(lista.get(i)->key == key) { // aqui no se esta cumpliendo, entonces se queda en -1 el indice, y cuando llega al if de abajo se hace un throw
              indice = i;
            }
          }
          cout << "Size de la lista: " << lista.size() << endl;
          cout << "Indice: " << indice << endl;
          cout << "Value: " << lista.get(indice)->value << endl;
          // if(indice<0) throw -1;
          return lista.get(indice)->value;
        }*/

      bool contains(K key) const{
          int posicion = fh(key);
          LinkedList<HashPair<K,T>*> lista = tabla[posicion];
          int indice = -1;
          for(int i = 0; i<lista.size(); i++){
            if(lista.get(i)->key == key){
              indice = i;
            }
          }
          return (indice<0)? 0: 1 ;
      }

      void print(){
            for(int i =0; i<size; i++){
              for(int j =0; j<tabla[i].size(); j++){
                cout <<"i:" <<i << " k: " << tabla[i].get(j)->key  << "  " << tabla[i].get(j)->value<<endl;
              }
            }
        }
      
};