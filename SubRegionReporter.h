#ifndef SUBREGIONREPORTER_H
#define SUBREGIONREPORTER_H
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "ReporterGenerator.h"
#include "ReportData.h"
/*
Purpose: A report lising the sub-region, within each region,
        that hosted the highest number of horses and ponies in 2016
Descriptions: Compute() function helps generate the corresponding report
*/

class SubRegionReporter : public ReporterGenerator
{
  public:
    SubRegionReporter(CompareBehaviour<int>*);
    virtual ~SubRegionReporter();
    virtual void compute();

  private:
    ReportData<int>* reportResults;
    void formatData(vector<Record*>&);
    void printReport();

};

#endif
