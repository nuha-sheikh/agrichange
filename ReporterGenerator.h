#ifndef REPORTERGENERATOR_H
#define REPORTERGENERATOR_H
#include <vector>
#include "Record.h"
#include "Map.h"
/*
Purpose: Assists in implementing an inheritance hierarchy of report generator classes
Descriptions:
*/

class ReporterGenerator
{
  public:
    static void loadRecords();
    virtual void compute() = 0;
    virtual ~ReporterGenerator() = 0;
    void cleanup();

  protected:
    static vector<Record*> records;
    static Map<string> regionMap;
    static Map<int> yearMap;
    static Map<string> animalMap;

};

#endif
