#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H
/*
Purpose: Helps format a report in Ascending/increasing order
Descriptions: Compare() function compares two parameters in ascending order
*/

template <class T>
class AscBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T,T);
};

template <class T>
bool AscBehaviour<T>::compare(T x, T y)
{
  if( x > y )
  {
    return false;
  }
  return true;
}

#endif
