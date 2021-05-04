#include <iostream>
using namespace std;
#include <fstream>

#include "ReporterGenerator.h"

vector<Record*> ReporterGenerator::records;
Map<string> ReporterGenerator::regionMap;
Map<int> ReporterGenerator::yearMap;
Map<string> ReporterGenerator::animalMap;

ReporterGenerator::~ReporterGenerator() { }

void ReporterGenerator::loadRecords()
{
  int year, numFarms, numAnimals;
  string region, subRegion, animalType;

  ifstream infile("farms.dat", ios::in);
  if(!infile)
  {
    cout << "Error: could not open file" << endl;
    exit(1);
  }

  while( infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals)
  {
    Record* rec = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
    records.push_back(rec);
    regionMap.add(region, rec);
    yearMap.add(year, rec);
    animalMap.add(animalType, rec);
  }
}

void ReporterGenerator::cleanup()
{
  for(int i = 0; i < records.size(); i++)
  {
    delete records.at(i);
  }
}
