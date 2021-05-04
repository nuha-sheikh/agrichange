#ifndef REPORTDATA_H
#define REPORTDATA_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <string>
#include "CompareBehaviour.h"
/*
Purpose: Contains the results for one report, organised as an order collection
          of keys and formatted strings that represent a row in the report
Descriptions:
*/

template <class T>
class ReportData
{
  class ReportRow
  {
    public:
      ReportRow(T k , string r)
      {
        key = k;
        row = r;
      }
      T key;
      string row;
  };

  template <class U>
  friend ostream& operator<<(ostream&, ReportData<U>&);

  public:
    ReportData(CompareBehaviour<T>*);
    ~ReportData();
    void add(T, string);
    void clear();

  private:
    vector<ReportRow> allRows;
    CompareBehaviour<T>* comp;
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c)
{
  comp = c;
}

template <class T>
ReportData<T>::~ReportData()
{
  delete comp;
}

template <class T>
void ReportData<T>::clear()
{
  allRows.clear();
}

template <class T>
void ReportData<T>::add(T key, string row)
{
  typename vector<ReportRow>::iterator itr;
  ReportRow obj(key, row);
  if(allRows.size() == 0)
  {
    allRows.push_back(obj);
    return;
  }

  for( itr = allRows.begin(); itr != allRows.end(); ++itr)
  {
    if(comp->compare(key, itr->key))
    {
      allRows.insert(itr, obj);
      return;
    }
  }
  allRows.push_back(obj);
}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& r)
{
  for(int i = 0; i<r.allRows.size(); ++i)
  {
    output<< r.allRows[i].row;
  }
  return output;
}

#endif
