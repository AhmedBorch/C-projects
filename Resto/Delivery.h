#ifndef DELIVERY_H
#define DELIVERY_H

#include"person.h"
#include"customer.h"

class delivery_worker :public person {
	customer* listCust;
	int numCust;
	int max_packs;
	int packs;
public:
	delivery_worker(){
		listCust = NULL;
		numCust = 0;
		max_packs = 10;
		packs = 0;
	}
	delivery_worker(string ,int p);
	void add_cust(const customer& cust);
	bool check(const customer& cust,int n);
	void order();
	void setcusn(int a) {
		listCust += a;
	}

	//const delivery_worker& operator =(const delivery_worker& theOther);

	~delivery_worker() {
		delete[] listCust;
		listCust = NULL;

	}
};



#endif // !DELIVERY_H

