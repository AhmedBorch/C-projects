#ifndef EXCEP_H
#define EXCEP_H
#include<iostream>
#include<exception>
using namespace std;

class OutOfRangeEx :public exception {     //an exception class for out of range elements
	virtual const char* what() const throw() {
		return "      ------ERRRO------Out_of_range_number-------ERROR------";
	}
}OutOfRangeEx;

class OutOfTypeEx :public exception {     //an exception class for wrong type 
	virtual const char* what() const throw() {
		return "      ------ERRRO------Not_a_number------ERRRO------";
	}
}OutOfTypeEx;






#endif 

