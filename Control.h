#ifndef CONTROL_H
#define CONTROL_H
#include "ReporterGenerator.h"
#include "ReportData.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"
#include "SubRegionReporter.h"
#include "FarmPercentageReporter.h"
#include "AnimalChangeReporter.h"
#include "CompareBehaviour.h"
#include "View.h"
#include <vector>
/*
Purpose: Manages the program control flow
Descriptions:
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();


  private:
    vector<ReporterGenerator*> reportGenerator;
    SubRegionReporter* subRegion;
    FarmPercentageReporter* farmPercentage;
    AnimalChangeReporter* animalChange;

};

#endif
