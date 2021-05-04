#include <iostream>
using namespace std;

#include "SubRegionReporter.h"

SubRegionReporter::SubRegionReporter(CompareBehaviour<int>* c)
{
  reportResults = new ReportData<int>(c);
}

SubRegionReporter::~SubRegionReporter()
{
  delete reportResults;
}

void SubRegionReporter::compute()
{
  vector<Record*> regionArr, tempRef;
  Record* tempRecord = NULL;
  string tempRegion = "";
  int numHorses = 0;

  for(int i = 0; i < animalMap.getKeySize(); i++)
  {
    if( animalMap.getKeys()[i] == "Horses-Ponies" ){ tempRef = animalMap[animalMap.getKeys().at(i)]; }
  }
  for(int i = 0; i < tempRef.size(); i++)
  {
      if( tempRegion != tempRef.at(i)->getRegion() )
      {
        tempRegion = tempRef.at(i)->getRegion();
        numHorses = 0;
        if(tempRecord != NULL) { regionArr.push_back(tempRecord); }
        tempRecord = NULL;
      }
      if( tempRef.at(i)->getYear() == 2016 && tempRef.at(i)->getRegion() != "CAN" && tempRef.at(i)->getSubRegion() != "All" && tempRef.at(i)->getNumAnimal() > numHorses )
      {
        tempRecord = tempRef.at(i);
        numHorses = tempRef.at(i)->getNumAnimal();
      }
  }

  formatData(regionArr);
  printReport();
  reportResults->clear();
}

void SubRegionReporter::formatData(vector<Record*>& regions)
{
  for(int i = 0; i < regionMap.getKeySize(); i++)
  {
    string s = "", subRegion = "";
    stringstream ss;
    int numAnimal = 0;
    if(regionMap.getKeys()[i] != "CAN")
    {
      for(int j = 0; j < regions.size(); j++)
      {
        if(regions.at(j)->getRegion() == regionMap.getKeys()[i])
        {
          subRegion = regions.at(j)->getSubRegion();
          numAnimal = regions.at(j)->getNumAnimal();
          break;
        }
      }
      ss << setw(12) << regionMap.getKeys()[i] << setw(4) << " " << setw(30) << subRegion << setw(4)  << " " << setw(6) << numAnimal << endl;
      s = ss.str();
      reportResults->add(numAnimal, s);
    }
  }
}

void SubRegionReporter::printReport()
{
  cout << endl;
  cout << "\t" << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl;
  cout << "\t" << "----------------------------------------------------" << endl;
  cout << *reportResults << endl;

  ofstream outfile("SubRegionReporter.txt", ios::out);
  if(!outfile)
  {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  outfile << endl;
  outfile << "\t" << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl;
  outfile << "\t" << "----------------------------------------------------" << endl;
  outfile << *reportResults << endl;
}
