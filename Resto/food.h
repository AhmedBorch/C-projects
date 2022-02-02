#ifndef FOOD_H
#define FOOD_H

#include<iostream>
#include<fstream>
using namespace std;

class foodstock {
public:
	double flour;
	double sauce;
	double chicken;
	double seafood;
	double cheese;
	double beef;
	double spaghetti;
	double Rivioli;
	double lasagne;

	foodstock();
	~foodstock();
};

class food {
public:
	int quantity;
	int id;
	char size;
	food(int x, char c,int q):id(x),size(c),quantity(q) {}
	food():id(0),size(0){}

	virtual double price() = 0;
	~food() {}
};


#endif