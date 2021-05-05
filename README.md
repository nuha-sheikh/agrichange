# AgriChange
A report generating program that reflects the endangered species in Canada by evaluating agriculture data sets from Statistics Canada

Program Author: Nuha Sheikh 

View UML Diagram of program: https://drive.google.com/file/d/1xJAo3J5baJsPliVwrKuj9op8UkxfA7Gr/view?usp=sharing

Launch: (Linux Environment)
1. In command prompt, navigate to the directory containing all the files (using cd command) 
2. In command prompt, type "make"
3. In command prompt, type "./project" and follow the menu instructions
4. In command prompt, when exited program, type "make clean" to handle dynamic memory deallocation 

Files: 

Header files:
- AnimalChangeReporter.h 
- AscBehaviour.h
- CompareBehaviour.h
- Control.h
- DescBehaviour.h
- FarmPercentageReporter.h
- Map.h
- Record.h
- ReportData.h
- ReporterGenerator.h
- SubRegionReporter.h
- View.h

Source Files:
- AnimalChangeReporter.cc
- Control.cc
- FarmPercentageReporter.cc
- Record.cc
- ReporterGenerator.cc
- SubRegionReporter.cc
- View.cc
- main.cc

Other Files:
- Makefile
- farms.dat (statistics file) 
