#include "tset.h"
#include "tset.h"
#include <iostream>
#define _IO_EXAMPLE_
using namespace std;

int main() {
	cout << "Let's create your bit field" << endl;
	cout << "First of all, enter lenght of your bit field" << endl;
	int len;
#ifdef _IO_EXAMPLE_
	cin >> len;
#endif
#ifndef _IO_EXAMPLE_
	len = 10;
	cout << "10" << endl;
#endif
	TBitField BF(len);
	cout << "Now your should enter a string consisting of '0' and '1'" <<endl;
	cout << "If the lenght of the string will be less than " << len << endl;
	cout << "Only the first elemtnts will be filled" << endl;
#ifdef _IO_EXAMPLE_
	cin >> BF;
#endif
#ifndef _IO_EXAMPLE_
	BF.SetBit (1);
	BF.SetBit(3);
	BF.SetBit(7);
	cout << "0101000100" << endl;
#endif
	cout << "Ok. Now you will see your bit field" << endl;
	cout << BF << endl;
	cout << "Is it your bit field?" << endl;



	cout << "1)Yes" << endl << "2)No" << endl << "3)I dont't see bit field" << endl;
	int n;
#ifdef _IO_EXAMPLE_
	cin >> n;
#endif
#ifndef _IO_EXAMPLE_
	n = 1;
	cout << "1" << endl;
#endif
	int a = 1;
	while (a == 1)
	{
		switch (n) {
		case 1:
			cout << "test passed" << endl;
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

	cout << endl << endl << "Now let's check the sets" << endl;
	cout << "Let's create your set" << endl;
	cout << "First of all, enter lenght of your set" << endl;
	int setLen;
#ifdef _IO_EXAMPLE_
	cin >> setLen;
#endif
#ifndef _IO_EXAMPLE_
	setLen = 50;
	cout << "50" << endl;
#endif
	TSet S(setLen);
	cout << endl << "Now your should enter elements which are include at your set" << endl;
	cout << "Enter incorrect value to exit from enter mode" << endl;
#ifdef _IO_EXAMPLE_
	cin >> S;
#endif
#ifndef _IO_EXAMPLE_
	S.InsElem(1);
	S.InsElem(3);
	S.InsElem(5);
	S.InsElem(10);
	S.InsElem(23);
	S.InsElem(45);
	cout << "1 3 5 10 23 45 91" << endl;
#endif
	cout << S;
	cout << "Is it your set?" << endl;

	cout << "1)Yes" << endl << "2)No" << endl << "3)I dont't see set" << endl;
	int p;
#ifdef _IO_EXAMPLE_
	cin >> p;
#endif
#ifndef _IO_EXAMPLE_
	p = 1;
	cout << "1" << endl;
#endif
	int v = 1;
	while (v == 1)
	{
		switch (n) {
		case 1:
			cout << "all tests passed" << endl;
			v = 0;
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