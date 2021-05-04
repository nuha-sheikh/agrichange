#ifndef ANIMALCHANGEREPORTER_H
#define ANIMALCHANGEREPORTER_H
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "ReporterGenerator.h"
#include "ReportData.h"
/*
Purpose: Computes and formates a report listing the animal type percentage breakdown for Canada,
          and for each animal type, the percentage change from 2011 to 2016
Descriptions: Compute() function helps generate the corresponding report
*/

class AnimalChangeReporter : public ReporterGenerator
{
  public:
    AnimalChangeReporter(CompareBehaviour<float>*);
    virtual ~AnimalChangeReporter();
    virtual void compute();

  private:
    ReportData<float>* reportResults;
    void formatData(vector< vector<Record*> >&, float*);
    void printReport();

};

#endif
