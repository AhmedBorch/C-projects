#include"Admin.h"
#include"food.h"
#include<iostream>
using namespace std;


bool Admin::fill(foodstock& f1) {
	int a;
	double b;

	cout << "**********choose the food element number you want to fill**********" << endl;
	cout << "****0:exit******1:flour****2:sauce********3:chicken****4:seafood****" << endl;
	cout << "****5:cheese****6:beef*****7:spaghetti****8:Riviolli***9:lasagne****" << endl;
	cin >> a;
	while (a != 0) {
		switch (a)
		{
		case 1:
			cout << "enter the amount of flour you are going to add" << endl;
			cin >> b;
			f1.flour += b;
			break;
		case 2:
			cout << "enter the amount of sauce you are going to add" << endl;
			cin >> b;
			f1.sauce += b;
			break;
		case 3:
			cout << "enter the amount of chicken you are going to add" << endl;
			cin >> b;
			f1.chicken += b;
			break;
		case 4:
			cout << "enter the amount of seafood you are going to add" << endl;
			cin >> b;
			f1.seafood += b;
		case 5:
			cout << "enter the amount of cheese you are going to add" << endl;
			cin >> b;
			f1.cheese += b;
			break;
		case 6:
			cout << "enter the amount of beef you are going to add" << endl;
			cin >> b;
			f1.beef += b;
			break;
		case 7:
			cout << "enter the amount of spaghetti you are going to add" << endl;
			cin >> b;
			f1.spaghetti += b;
			break;
		case 8:
			cout << "enter the amount of Rivioli you are going to add" << endl;
			cin >> b;
			f1.Rivioli += b;
			break;
		case 9:
			cout << "enter the amount of lasagne you are going to add" << endl;
			cin >> b;
			f1.lasagne += b;
			break;
		}
		cout << "**********choose the food element number you want to fill**********" << endl;
		cout << "****0:exit******1:flour****2:sauce********3:chicken****4:seafood****" << endl;
		cout << "****5:cheese****6:beef*****7:spaghetti****8:Riviolli***9:lasagne****" << endl;
		cin >> a;
	}
	return true;   //just for the sake of errors
}

void Admin::check(const foodstock& f1) {
	cout << "the amount of flour is: " << f1.flour << endl;
	cout << "the amount of sauce is: " << f1.sauce << endl;
	cout << "the amount of chicken is: " << f1.chicken << endl;
	cout << "the amount of seafood is: " << f1.seafood << endl;
	cout << "the amount of cheese is: " << f1.cheese << endl;
	cout << "the amount of beef is: " << f1.beef << endl;
	cout << "the amount of spaghetti is: " << f1.spaghetti << endl;
	cout << "the amount of Riviolli is: " << f1.Rivioli << endl;
	cout << "the amount of lasagne is: " << f1.lasagne << endl;
	cout << "///////////////////////////////////////////////" << endl;
	
}


void Admin::add_deliv() {
	string deliv_n, deliv_pass;
	cout << "****please enter the name of the delivery worker****" << endl;
	cin >> deliv_n;
	cout << "*****************enter the password*****************" << endl;
	cin >> deliv_pass;

	ofstream signdeliv("delivery.txt", ios_base::app);
	signdeliv << deliv_n << " " << deliv_pass << endl;
	signdeliv.close();
	cout << "delivery worker added successefully" << endl;

}