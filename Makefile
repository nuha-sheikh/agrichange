project:	ReporterGenerator.o Record.o main.o SubRegionReporter.o FarmPercentageReporter.o AnimalChangeReporter.o View.o Control.o 
	g++ -o project ReporterGenerator.o Record.o main.o SubRegionReporter.o FarmPercentageReporter.o AnimalChangeReporter.o View.o Control.o

ReporterGenerator.o:	ReporterGenerator.cc ReporterGenerator.h
	g++ -c ReporterGenerator.cc 

SubRegionReporter.o:	SubRegionReporter.cc SubRegionReporter.h
	g++ -c SubRegionReporter.cc 

FarmPercentageReporter.o:	FarmPercentageReporter.cc FarmPercentageReporter.h
	g++ -c FarmPercentageReporter.cc 

AnimalChangeReporter.o:	AnimalChangeReporter.cc AnimalChangeReporter.h
	g++ -c AnimalChangeReporter.cc 

Record.o: Record.cc Record.h
	g++ -c Record.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc 

View.o:	View.cc View.h
	g++ -c View.cc 

main.o:	main.cc
	g++ -c main.cc 

clean:
	rm -f *.o project SubRegionReporter.txt AnimalChangeReporter.txt FarmPercentageReporter.txt
