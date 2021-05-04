#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H
/*
Purpose: An abstract class that helps implement ascending and
        descending concrete classes for report behaviour
Descriptions: Compare() function that is implemented in derived concrete classes to compares two parameters
*/

template <class T>
class CompareBehaviour
{
  public:
    virtual bool compare(T,T) = 0;
};

#endif
