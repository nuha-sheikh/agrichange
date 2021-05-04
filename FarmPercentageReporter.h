#ifndef FARMPERCENTAGEREPORTER_H
#define FARMPERCENTAGEREPORTER_H
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "ReporterGenerator.h"
#include "ReportData.h"
/*
Purpose: A report listing the regional percentage breakdown of
          farms that hosted animals of each type in 2016
Descriptions: Compute() function helps generate the corresponding report
*/

class FarmPercentageReporter : public ReporterGenerator
{
  public:
    FarmPercentageReporter(CompareBehaviour<float>*);
    virtual ~FarmPercentageReporter();
    virtual void compute();

  private:
    ReportData<float>* reportResults;
    void formatData(vector< vector<Record*> >&, float*, vector< vector<float> >&, float);
    void printReport();

};

#endif
