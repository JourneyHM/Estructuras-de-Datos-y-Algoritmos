#include <iostream>
using namespace std;

template <typename K, typename T> class HashPair { 
public:
  K key; //O(1)
  T value;  //O(1)
  HashPair(K key, T value) {  //O(1)
    this->key = key;
    this->value = value;
  }
  HashPair() {}
};

template <typename K, typename T> class Hashtable { 
private:
  int size;
  LinkedList<HashPair<K, T> *> *tabla; //O(1)
  int fh(K key) const { //O(1)
    hash<K> hasher; //O(1)
    return hasher(key) % size; //O(1)
  }

public:
  Hashtable(int size = 20) { //O(n)
    this->size = size;
    tabla = new LinkedList<HashPair<K, T> *>[size];
    for (int i = 0; i < size; i++) {
      tabla[i] = LinkedList<HashPair<K, T> *>();
    }
  }

  bool put(K key, T value) { //O(n)
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++) {
      if (lista.get(i)->key == key) {
        indice = i;
      }
    }
    if (indice >= 0) {
      lista.get(indice)->value = value;
    } else {
      tabla[posicion].addLast(new HashPair<K, T>(key, value));
    }
    return (indice >= 0) ? 0 : 1;
  }

  T get(K key) const { //O(n)
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++) {
      if (lista.get(i)->key == key) {
        indice = i;
      }
    }
    if (indice < 0)
      throw -1;
    return lista.get(indice)->value;
  }

  bool contains(K key) const { //O(n)
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++) {
      if (lista.get(i)->key == key) {
        indice = i;
      }
    }
    return (indice < 0) ? 0 : 1;
  }

  void print() { //O(n2)
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < tabla[i].size(); j++) {
        cout << "i: " << i << " k: " << tabla[i].get(j)->key << " v: " << tabla[i].get(j)->value << endl;
      }
    }
  }
};