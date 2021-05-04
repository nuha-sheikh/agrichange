#include <iostream>
using namespace std;
#include <string>
#include <sstream>

#include "Control.h"

Control::Control()
{
  CompareBehaviour<int>* d1 = new DescBehaviour<int>();
  CompareBehaviour<float>* d2 = new DescBehaviour<float>();
  CompareBehaviour<float>* d3 = new AscBehaviour<float>();

  subRegion = new SubRegionReporter(d1);
  farmPercentage = new FarmPercentageReporter(d2);
  animalChange = new AnimalChangeReporter(d3);

  reportGenerator.push_back(farmPercentage);
  reportGenerator.push_back(animalChange);
  reportGenerator.push_back(subRegion);
}

Control::~Control()
{
  reportGenerator.at(0)->cleanup();
  delete subRegion;
  delete farmPercentage;
  delete animalChange;
}

void Control::launch()
{
  reportGenerator.at(0)->loadRecords();
  View v1;
  int num;

  v1.showMenu(num);
  while(num != 0)
  {
    if( num == 1 )
    {
      reportGenerator.at(num-1)->compute();
    }
    else if( num == 2 )
    {
      reportGenerator.at(num-1)->compute();
    }
    else if( num == 3 )
    {
      reportGenerator.at(num-1)->compute();
    }
    v1.showMenu(num);
  }
}
