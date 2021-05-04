#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include "Record.h"
/*
Purpose: Stores a collection of keys and a collection of values
Descriptions:
*/

template <class T>
class Map
{
  public:
    Map();
    void add(T key, Record* rec);
    int getKeySize();
    vector<T>& getKeys();
    vector<Record*>& operator[](T);

  private:
    vector<T> keys;
    vector< vector<Record*> > values;
    int numElements;
};

template <class T>
Map<T>::Map()
{
  numElements = 0;
}

template <class T>
int Map<T>::getKeySize() { return numElements; }

template <class T>
vector<T>& Map<T>::getKeys() { return keys; }

template <class T>
void Map<T>::add(T k, Record* r)
{
  for(int i =0; i < keys.size(); i++)
  {
    if( keys.at(i) == k )
    {
      values.at(i).push_back(r);
      return;
    }
  }

  keys.push_back(k);
  vector<Record*> newKeys;
  newKeys.push_back(r);
  values.push_back(newKeys);
  numElements++;
}

template <class T>
vector<Record*>& Map<T>::operator[](T k)
{
  for(int i =0; i < keys.size(); i++)
  {
    if( keys.at(i) == k )
    {
      return values.at(i);
    }
  }
  cerr<<"ERROR: Not a valid index"<<endl;
  exit(1);
}
