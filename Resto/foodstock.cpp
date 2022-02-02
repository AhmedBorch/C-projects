#include<string>
#include<iostream>
#include<fstream>
#include"food.h"
using namespace std;

foodstock::foodstock() {
	string az;
	double bz;
	ifstream initialfood("foodstock.txt");

	initialfood >> az>> bz;
	flour = bz;
	initialfood >> az >> bz;
	sauce = bz;
	initialfood >> az >> bz;
	chicken = bz;
	initialfood >> az >> bz;
	seafood = bz;
	initialfood >> az >> bz;
	cheese = bz;
	initialfood >> az >> bz;
	beef = bz;                    
	initialfood >> az >> bz;
	spaghetti = bz;
	initialfood >> az >> bz;
	Rivioli = bz;
	initialfood >> az >> bz;
	lasagne = bz;

	initialfood.close();
}




foodstock::~foodstock() {
	ofstream refresh("foodstock.txt");

	refresh << "flour " << flour<<endl;
	refresh << "sauce " << sauce<<endl;
	refresh << "chicken " << chicken<<endl;
	refresh << "seafood " << seafood<<endl;
	refresh << "cheese " << cheese << endl;
	refresh << "beef " << beef << endl;
	refresh << "spaghetti " << spaghetti << endl;
	refresh << "Riviolli " << Rivioli << endl;
	refresh << "lasagne " << lasagne << endl;

	refresh.close();
}


//foo* foodstock::foodcheck() {}