#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Exchange(int &a, int &b);

int main() {
	setlocale(LC_ALL, "ru");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl; //(копирование строки ctrl+d)
	Exchange(a, b);
	cout << a << "\t" << b << endl;
}

void Exchange(int &a, int &b) {
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << "\t" << b << endl;
}