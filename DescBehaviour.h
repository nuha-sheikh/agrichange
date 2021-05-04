#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H
/*
Purpose: Helps format a report in Descending/decreasing order
Descriptions: Compare() function compares two parameters in descending order
*/

template <class T>
class DescBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T,T);
};

template <class T>
bool DescBehaviour<T>::compare(T x, T y)
{
  if( x < y )
  {
    return false;
  }
  return true;
}

#endif
