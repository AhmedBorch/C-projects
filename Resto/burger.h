#include"food.h"



class burger :public foodstock, public food {
public:
	burger(int a, char s,int qu);
	//burger(int a, char s);

	double price();
};
