
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <class genT>
struct faboFunctions {
	static void fillFobVec(vector<genT>&v, int num) {
		v.resize(num + 2);
		v.at(0) = 0;
		v.at(1) = 1;

		for (int i = 2; i < num + 1; i++) {
			v.at(i) = v.at(i - 1) + v.at(i - 2);
		}
	}
	static void printVec(vector<genT>tmpVec) {
		for (int j = 0; j < tmpVec.size() - 1; j++) {
			cout << tmpVec.at(j) << endl;
		}
	}

	//put function for finding minimum under temp class
	//so that it can be used with other variable types
	static genT minOf(genT x, genT y) { return (x <= y) ? x : y; }
};

int fabonacciSearch(vector<int>contVec, int searchForVal, int sizeOfVec){
	int fabM2 = 0;  
	int fabM1 = 1; 
	int fabM = fabM2 + fabM1;

	while (fabM < sizeOfVec){
		fabM2 = fabM1;
		fabM1 = fabM;
		fabM = fabM2 + fabM1;
	}

	int offset = -1;

	while (fabM > 1){
		int i = faboFunctions<int>::minOf(offset + fabM2, sizeOfVec - 1);

		if (contVec.at(i) < searchForVal){
			fabM = fabM1;
			fabM1 = fabM2;
			fabM2 = fabM - fabM1;
			offset = i;
		}

		else if (contVec.at(i) > searchForVal){
			fabM = fabM2;
			fabM1 = fabM1 - fabM2;
			fabM2 = fabM - fabM1;
		}

		else return i;
	}

	if (fabM1 && contVec.at(offset +1) == searchForVal)return offset + 1;
	return -1;
}

int main() {
	/*
	vector<unsigned long long>fobVal;
	int fobAmt = 0;
	bool flag = true;

	while (flag) {
		cout << "Enter the number of indexes for vec (less than 91): ";
		cin >> fobAmt;
		if (fobAmt <= 90) { flag = false; }
	}

	cout << endl;

	faboFunctions<unsigned long long>::fillFobVec(fobVal, fobAmt);
	faboFunctions<unsigned long long>::printVec(fobVal);
	*/

	vector<int> testVec;
    int searchForTest = 0;
	int n = 0;
	int result = 0;

	testVec.push_back(27);
	testVec.push_back(10);
	testVec.push_back(7);
	testVec.push_back(1);
	testVec.push_back(99);
	testVec.push_back(137);
	testVec.push_back(42);
	testVec.push_back(85);
	testVec.push_back(76);
	testVec.push_back(5);
	testVec.push_back(201);
	testVec.push_back(197);

	sort(testVec.begin(), testVec.end());

	cout << "Enter integer to search for: ";
	cin >> searchForTest;
	n = testVec.size();

	result = fabonacciSearch(testVec, searchForTest, n);
	if (result == -1) {
		cout << "RESULT NOT FOUND." << endl;
	}
	else
		cout << "Integer found at index: " << result << endl;


	return 0;
}

/* Returns index of x if present,  else returns -1 
int fibMonaccianSearch(int arr[], int x, int n)
{
	/* Initialize fibonacci numbers 
	int fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
	int fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
	int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 

								   /* fibM is going to store the smallest Fibonacci
								   Number greater than or equal to n 
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front 
	int offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 
	while (fibM > 1)
	{
		// Check if fibMm2 is a valid location 
		int i = minOf(offset + fibMMm2, n - 1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i 
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is greater than the value at index fibMm2,
		cut the subarray after i+1  
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index 
		else return i;
	}

	/* comparing the last element with x 
	if (fibMMm1 && arr[offset + 1] == x)return offset + 1;

	/*element not found. return -1 
	return -1;
}*/