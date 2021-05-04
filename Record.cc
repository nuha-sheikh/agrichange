#include <iostream>
using namespace std;
#include <string>

#include "Record.h"

Record::Record(int y, string r, string sr, string at, int f, int a)
  : year(y), region(r), subRegion(sr), animalType(at), numFarms(f), numAnimals(a)
{
}

int Record::getYear() { return year; }
string Record::getRegion() { return region; }
string Record::getAnimal() { return animalType; }
int Record::getNumAnimal() { return numAnimals; }
string Record::getSubRegion() { return subRegion; }
int Record::getNumFarms() { return numFarms; }

ostream& operator<<(ostream& output, Record& r)
{
  output << r.year<<" "<< r.region<<" "<<r.subRegion<<" "<<r.animalType<<" "<<r.numFarms<<" "<<r.numAnimals;
  return output;
}
