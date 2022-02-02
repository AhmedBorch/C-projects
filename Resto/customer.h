#pragma warning(disable : 4996) //using localtime maybe unsafe but it's necessary for me to get the exact current time
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"pizza.h"
#include"burger.h"
#include"food.h"
#include"person.h"
#include<iostream>
#include<string>


#include<time.h>
using namespace std;



class customer:public person{
	double bill;
	int elemNum;
	
	struct tm* order_time;
	int district;
public:
	customer():person(){
		bill = 0;
		elemNum = 0;
		district = 0;
	}
	customer(string s):person(s) {
		bill = 0;
		elemNum = 0;
		district = 0;
		time_t t;
		time(&t);
		order_time=localtime(&t);

		/*auto start = chrono::system_clock::now();
		time_t start_time = chrono::system_clock::to_time_t(start);
		//cout << "finished computation at " << ctime(&start_time);
		order_time = gmtime(&start_time);
		//cout << "||||" << tmp->tm_hour;*/
	}
	food** choose(food** food_arr);

	void print(food** food_arr);


	//Number of elements getter
	int getElementNum() const {
		return elemNum;
	}
	//not sure hethyy
	int getElementNum() {
		return elemNum;
	}
	
	//district getter
	int getDistrict() {
		return district;
	}

	//district setter
	void setDistrict(int a) {
		district = a;
	}

	//bill getter
	bool getBill() {
		return bill;
	}

	struct tm* getTime() const{
		return order_time;
	}

	void SetelemNum(int e){
		elemNum = e;
	}
	
	customer& operator=(int dis) {
		this->district = dis;
		return *this;
	}

	customer& operator=(double bil) {
		this->bill = bil;
		return *this;
	}



};




#endif