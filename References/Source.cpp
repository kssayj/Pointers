#include <iostream>

int main() {
	int a = 2;
	int& ra = a;
	ra += 3;
	std::cout << a << std::endl;
}