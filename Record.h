#ifndef RECORD_H
#define RECORD_H
/*
Purpose: Contains the information for a data record
Descriptions:
*/

class Record
{
  friend ostream& operator<<(ostream&, Record&);
  public:
    Record(int, string, string, string, int, int);
    int getYear();
    string getRegion();
    string getAnimal();
    int getNumAnimal();
    string getSubRegion();
    int getNumFarms();


  private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};

#endif
