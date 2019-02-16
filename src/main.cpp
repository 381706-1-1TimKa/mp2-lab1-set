#include "tset.h"
#include "tset.h"
#include <iostream>
using namespace std;

int main(){
	cout << "Let's create your bit field" << endl;
	cout << "First of all, enter lenght of your bit field" << endl;
	int len;
	cin >> len;
		TBitField BF(len);
	cout << "Now your should enter a string consisting of '0' and '1'" << endl;
	cout << "If the lenght of the string will be less than " << len << endl;
	cout << "only the first elemtnts will be filled" << endl;
	cout << "Simbols different from '1' are equal to '0'" << endl;
	cin >> BF;
	cout << "Ok. Now you will see your bit field" << endl << endl;
	cout << BF;
	cout << "Is it your bit field?" << endl;

	cout << "1)Yes" << endl << "2)No" << endl << "3)I dont't see bit field" << endl;
	int n;
	cin >> n;
	int a = 1;
	while (a=1)
	{
		switch (n) {
		case 1:
			cout << "test passed" << endl;
			cout << "Now let's check the sets";
			a = 0;
			break;
		case 2:
			cout << "test failed" << endl;
			return 0;
		case 3:
			cout << "test failed" << endl;
			return 0;
		default:
			cout << "What? I can't understand. Answer again, please" << endl;
		}
	}

	return 0;
}