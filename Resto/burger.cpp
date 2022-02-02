#include"burger.h"


burger::burger(int a, char s,int qu) :food(a, s, qu), foodstock() {
	for (int i = 1; i <= qu; i++) {
		switch (toupper(size)) {       //different sizes
		case 'L':
			flour -= 0.3;
			sauce -= 0.1;
			break;
		case 'M':
			flour -= 0.2;
			sauce -= 0.1;
			break;
		case 'S':
			flour -= 0.1;
			sauce -= 0.1;
		}

		switch (a) {             //different types
		case 1:
			chicken -= 0.4;
			break;
		case 2:
			seafood -= 0.3;
			break;
		case 3:
			cheese -= 0.3;
			beef -= 0.3;
		}
	}
	

}

double burger::price() {   //specific prices for each type and size
	
	if (id == 1) {
		switch (toupper(size))
		{
		case 'S':
			return quantity*4.99;
			break;
		case 'M':
			return quantity * 5.99;
			break;
		case 'L':
			return quantity * 6.99;
		}
	}

	if (id == 2) {
		switch (toupper(size))
		{
		case 'S':
			return quantity * 5.99;
			break;
		case 'M':
			return quantity * 7.99;
			break;
		case 'L':
			return quantity * 9.99;
		}
	}

	if (id == 3) {
		switch (toupper(size))
		{
		case 'S':
			return quantity * 5.99;
			break;
		case 'M':
			return quantity * 7.99;
			break;
		case 'L':
			return quantity * 9.99;
		}
	}

	
}