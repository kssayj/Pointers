#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//#define POINTERS_BASICS
//#define POINTERS_AND_ARRAY
void main() {
	setlocale(LC_ALL, "ru");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << &a << endl;
	cout << pa << endl;
	cout << *pa << endl;
	cout << pa[0] << endl;

	int pb;
	int b = 3;
	//pb = &b;
	//std::cout<<
#endif
#ifdef POINTERS_AND_ARRAY
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#endif
}