#include <iostream>
using namespace std;

#include "FarmPercentageReporter.h"

FarmPercentageReporter::FarmPercentageReporter(CompareBehaviour<float>* c)
{
  reportResults = new ReportData<float>(c);
}

FarmPercentageReporter::~FarmPercentageReporter()
{
  delete reportResults;
}

void FarmPercentageReporter::compute()
{
  vector< vector<float> >  numFarmsRegion;
  vector< vector<Record*> > totalAnimalsRec;
  float totalAnimalsType[animalMap.getKeySize()] = {0}, totalFarm = 0;

  for(int i = 0; i < regionMap.getKeySize(); i++)
  {
    vector<float> rowA;
    vector<Record*> rowB, tempRef;
    float totalA = 0;
    int index = 0;
    tempRef = regionMap[regionMap.getKeys().at(i)];

    for(int j = 0; j < tempRef.size(); j++)
    {
      if(tempRef.at(j)->getYear() == 2016 && tempRef.at(j)->getRegion() != "CAN" && tempRef.at(j)->getSubRegion() == "All")
      {
        totalA += tempRef.at(j)->getNumFarms();
        totalFarm += tempRef.at(j)->getNumFarms();
        rowB.push_back(tempRef.at(j));
        totalAnimalsType[index] += tempRef.at(j)->getNumFarms();
        index++;
      }
    }
    rowA.push_back(totalA);
    numFarmsRegion.push_back(rowA);
    totalAnimalsRec.push_back(rowB);
  }
  formatData(totalAnimalsRec, totalAnimalsType, numFarmsRegion, totalFarm);
  printReport();
  reportResults->clear();
}

void FarmPercentageReporter::formatData(vector< vector<Record*> >& totalAnimalsRec, float* totalAnimalsType, vector< vector<float> >& numFarmsRegion, float totalFarm)
{
  for( int i = 0; i < totalAnimalsRec.size(); i++)
  {
    string str;
    stringstream ss;
    int index = 0;

    if(regionMap.getKeys()[i] != "CAN"){
      ss << setw(5) << regionMap.getKeys()[i] << setw(4) << " ";
      for( int j = 0; j < totalAnimalsRec.at(i).size(); j++)
      {
        if( totalAnimalsRec.at(i).at(j)->getAnimal() != animalMap.getKeys()[j] )
        {
          ss << setw(8) << 0.0 << " ";
        }
        ss << setw(8) << setprecision(1) << fixed << (totalAnimalsRec.at(i).at(j)->getNumFarms()/totalAnimalsType[index])*100 << " ";
        index++;
      }
      ss << setw(8) << (numFarmsRegion.at(i).at(0)/totalFarm)*100 << endl;
      str = ss.str();
      reportResults->add((numFarmsRegion.at(i).at(0)/totalFarm)*100 , str);
    }
  }
}

void FarmPercentageReporter::printReport()
{
  cout << "\t\t\t\t" << "PERCENTAGE OF FARMS BY REGION IN 2016" << endl;
  cout << "\t\t\t\t" << "-------------------------------------" << endl;
  cout << "\t" << "    Horses/  Goats    Llamas   Rabbits  Bison/   Elk/    Domestic   Wild     Mink    Totals " << endl;
  cout << "\t" << "    Ponies            Alpacas           Buffalo  Wapiti    Deer     Boars  " << endl;
  cout << *reportResults << endl;

  ofstream outfile("FarmPercentageReporter.txt", ios::out);
  if(!outfile)
  {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  outfile << endl;
  outfile << "\t\t\t\t" << "PERCENTAGE OF FARMS BY REGION IN 2016" << endl;
  outfile << "\t\t\t\t" << "-------------------------------------" << endl;
  outfile << "\t" << "    Horses/  Goats    Llamas   Rabbits  Bison/   Elk/    Domestic   Wild     Mink    Totals " << endl;
  outfile << "\t" << "    Ponies            Alpacas           Buffalo  Wapiti    Deer     Boars  " << endl;
  outfile << *reportResults << endl;
}
