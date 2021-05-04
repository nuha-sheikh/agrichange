#include <iostream>
using namespace std;

#include "AnimalChangeReporter.h"

AnimalChangeReporter::AnimalChangeReporter(CompareBehaviour<float>* c)
{
  reportResults = new ReportData<float>(c);
}

AnimalChangeReporter::~AnimalChangeReporter()
{
  delete reportResults;
}

void AnimalChangeReporter::compute()
{
  float totalArr[yearMap.getKeySize()] = {0};
  vector< vector<Record*> > animalArr;

  for(int i = 0; i < yearMap.getKeySize(); i++)
  {
    vector<Record*> row, tempRef;
    tempRef = yearMap[yearMap.getKeys().at(i)];

    for(int j = 0; j < tempRef.size(); j++){
      if( ((tempRef.at(j)->getYear() == 2011) || (tempRef.at(j)->getYear() == 2016)) && (tempRef.at(j)->getRegion() == "CAN") )
      {
        row.push_back(tempRef.at(j));
        totalArr[i] += tempRef.at(j)->getNumAnimal();
      }
    }
    animalArr.push_back(row);
  }
  formatData(animalArr, totalArr);
  printReport();
  reportResults->clear();
}

void AnimalChangeReporter::formatData(vector< vector<Record*> >& animalArr, float* totalArr)
{
  for(int i = 0; i < animalMap.getKeySize(); i++)
  {
    string str, space = " ";
    stringstream ss;
    float var1 = 0, var2 = 0, change = 0;

    ss << setw(20) << animalMap.getKeys()[i] << setw(4) << " ";
    for(int j = 0; j <animalArr.size(); j++)
    {
      for(int k = 0; k <animalArr.at(j).size(); k++)
      {
        if( (animalArr.at(j).at(k)->getAnimal() ==  animalMap.getKeys()[i]) && (animalArr.at(j).at(k)->getYear() == 2011) )
        {
          var1 = (animalArr.at(j).at(k)->getNumAnimal()/totalArr[j])*100;
        }
        else if( (animalArr.at(j).at(k)->getAnimal() ==  animalMap.getKeys()[i]) && (animalArr.at(j).at(k)->getYear() == 2016) )
        {
          var2 = (animalArr.at(j).at(k)->getNumAnimal()/totalArr[j])*100;
        }
      }
    }
    change = var2-var1;
    ss << setw(4) << setprecision(1) << fixed << var1 << setw(2) << " " << setw(6) << setprecision(1) << var2 << setw(9)  << std::showpos << change << endl;
    str = ss.str();
    reportResults->add(change, str);
  }
}

void AnimalChangeReporter::printReport()
{
  cout << endl;
  cout << " \t" << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
  cout << " \t" << "----------------------------------------" << endl;
  cout << " \t\t";
  for(int i = 0; i < yearMap.getKeySize(); i++)
  {
    cout << "\t" << yearMap.getKeys()[i];
  }
  cout << "\t" << "Change" << endl;
  cout << endl;
  cout << *reportResults << endl;

  ofstream outfile("AnimalChangeReporter.txt", ios::out);
  if(!outfile)
  {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  outfile << endl;
  outfile << " \t" << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
  outfile << " \t" << "----------------------------------------" << endl;
  outfile << " \t\t";
  for(int i = 0; i < yearMap.getKeySize(); i++)
  {
    outfile << "\t" << yearMap.getKeys()[i];
  }
  outfile << "\t" << "Change" << endl;
  outfile << endl;
  outfile << *reportResults << endl;
}
