#ifndef VIEW_H
#define VIEW_H
/*
Purpose: Assists in establishing the user display menu
Descriptions: 
*/

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
