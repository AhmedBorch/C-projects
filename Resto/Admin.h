#include<iostream>
#include<string>
#include"food.h"
#include"person.h"
using namespace std;

class Admin:public person{
		
public:
	Admin(string s):person(s){}
	bool fill(foodstock& f1); //this is a function to fill in the new items in the foodstock class
	void check(const foodstock& f1); //this function takes a foodstock object and print the existence values of the stock to the admin
	void add_deliv();  //this function allows the admin to add a delivery worker

}; 
