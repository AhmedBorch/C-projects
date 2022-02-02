#include"customer.h"
#include<string>
#include<iostream>
using namespace std;





food** customer::choose(food** food_arr){
		int a,b;
		int type,quant;
		char size;
		//just to check


		cout << "******Welcome dear customer, you can choose from the list bellow******" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|      category       |     Sub_categories    |    size    |  price  |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|      pizza          |    pizza Margherita   |    Small   |  5.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  7.99$  |" << endl;
		cout << "|                     |                       |    Large   |  9.99$  |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |     pizza chicken     |    Small   |  6.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  8.99$  |" << endl;
		cout << "|                     |                       |    Large   |  10.99$ |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |     pizza 4 cheese    |    Small   |  7.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  9.99$  |" << endl;
		cout << "|                     |                       |    Large   |  11.99$ |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|      burger         |        cheese burger  |    Small   |  4.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  5.99$  |" << endl;
		cout << "|                     |                       |    Large   |  6.99$  |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |        chicken burger |    Small   |  5.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  7.99$  |" << endl;
		cout << "|                     |                       |    Large   |  9.99$  |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |        fish burger    |    Small   |  5.99$  |" << endl;
		cout << "|                     |                       |    Medium  |  7.99$  |" << endl;
		cout << "|                     |                       |    Large   |  9.99$  |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|      pasta          |        Lasagne        |    Small   |  10.99$ |" << endl;
		cout << "|                     |                       |    Medium  |  12.99$ |" << endl;
		cout << "|                     |                       |    Large   |  14.99$ |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |        Spaghetti      |    Small   |  12.99$ |" << endl;
		cout << "|                     |                       |    Medium  |  14.99$ |" << endl;
		cout << "|                     |                       |    Large   |  16.99$ |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                     |        Rivioli        |    Small   |  13.99$ |" << endl;
		cout << "|                     |                       |    Medium  |  15.99$ |" << endl;
		cout << "|                     |                       |    Large   |  17.99$ |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		do {
			cout << "1)pizza" << "|||||" << "2)burger" << "|||||" << "3)pasta" << endl;
			cin >> a;
			if (a == 1) {
				cout << "please choose the number of type of pizza you want" << endl;
				cout << "1)pizza Margherita" << endl << "2)pizza chiken" << endl << "3)pizza 4 cheese" << endl;
				cin >> type;
				cout << "choose the size: S/M/L" << endl;
				cin >> size;
				cout << "choose the number of pizzas you want" << endl;
				cin >> quant;
				//pizza p1(type, size);
				//elemNum++;
				//bill += p1.price();
				//add a new element to the customer list
				food** new_food_arr = new food * [elemNum+1];
				for (int i = 0; i < elemNum ; i++) {
					new_food_arr[i] = food_arr[i];
				}
				new_food_arr[elemNum] = new pizza(type, size,quant);
				bill += new_food_arr[elemNum]->price();
				elemNum++;
				delete[] food_arr;
				food_arr = new_food_arr;

				



			}
			else if (a == 2)
			{

				cout << "please choose the type of burger you want" << endl;
				cout << "****1:cheese burger" << endl << "****2:chicken burguer" << endl << "****3:fish burger" << endl;
				cin >> type;
				cout << "choose the size: S/M/L" << endl;
				cin >> size;
				cout << "choose the number of burgers you want" << endl;
				cin >> quant;
				
				food** new_food_arr1 = new food * [elemNum+1];
				for (int i = 0; i < elemNum; i++) {
					new_food_arr1[i] =  food_arr[i];
				}
				new_food_arr1[elemNum] = new burger(type, size, quant);
				bill += new_food_arr1[elemNum]->price();
				elemNum++;
				delete[] food_arr;
				food_arr = new_food_arr1;
			
				
			}
			else if (a == 3) {
				cout << "please choose the type of pasta you want" << endl;
				cout << "****1:Lasagne " << endl << "****2:Spaghetti" << endl << "****3:Rivioli" << endl;
				cin >> type;
				cout << "choose the size: S/M/L" << endl;
				cin >> size;
				cout << "choose the quantity you want" << endl;
				cin >> quant;

				food** new_food_arr1 = new food * [elemNum + 1];
				for (int i = 0; i < elemNum; i++) {
					new_food_arr1[i] = food_arr[i];
				}
				new_food_arr1[elemNum] = new burger(type, size, quant);
				bill += new_food_arr1[elemNum]->price();
				elemNum++;
				delete[] food_arr;
				food_arr = new_food_arr1;

			}

			cout << "press 1 to choose again ||||| press 0 to leave" << endl;
			cin >> b;
		} while (b == 1);

		int pop;
		cout << "to get delivery enter the district, press 0 to eat in the restaurent" << endl;
		cin >> pop;
		setDistrict(pop);
		return food_arr;


}


void customer::print(food** food_arr) {
	cout << "-----------your order------------" << endl;
	cout << "the bill is: " << this->bill << "$" << endl;
	for (int i = 0; i < this->elemNum; i++) {
		cout << " item " << i+1 << " price" << endl;
		cout << food_arr[i]->price() << endl;
		cout << "------------------" << endl;
	}
	cout << "---------time of ordering: " << this->getTime()->tm_hour << ":" << this->getTime()->tm_min << endl;

}



