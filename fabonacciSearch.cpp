// fabonacciSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


template <class genVal>
struct fabFunctions {
	static void fillFobVec(vector<genVal>&v, int num) {
		v.resize(num + 2);
		v.at(0) = 0;
		v.at(1) = 1;

		for (int i = 2; i < num + 1; i++) {
			v.at(i) = v.at(i - 1) + v.at(i - 2);
		}
	}

	static void printVec(vector<genVal>tmpVec) {
		for (int j = 0; j < tmpVec.size() - 1; j++) {
			cout << tmpVec.at(j) << endl;
		}
	}
};

int main() {
	vector<unsigned long long>fobVal;
	int fobAmt = 0;
	bool flag = true;

	while (flag) {
		cout << "Enter the number of indexes for vec (less than 91): ";
		cin >> fobAmt;
		if (fobAmt <= 90) { flag = false; }
	}
	cout << endl;

	fabFunctions<unsigned long long>::fillFobVec(fobVal, fobAmt);
	fabFunctions<unsigned long long>::printVec(fobVal);

	return 0;
}

