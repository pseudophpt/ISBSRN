test:
	g++ -c isbsrn.cpp -o isbsrn.o
	g++ -c isbsrn-test.cpp -o isbsrn-test.o
	g++ -o isbsrn isbsrn-test.o isbsrn.o 
