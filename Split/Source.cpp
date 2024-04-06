#include <iostream>
using namespace std;
#define tab "\t"

void fillrand(int arr[], const int n);
void print(const int arr[], const int n);
void main() {
	setlocale(LC_ALL, "ru");
	const int n = 10;
	int arr[n];
	fillrand(arr, n);
	print(arr, n);
	//вычисл€ем размеры массивов
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}
	cout << " ол-во четных элементов: " << even_count << endl;
	cout << " ол-во нечетных элементов: " << odd_count << endl;
	//выдел€ем пам€ть под массивы
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];
	//распредел€ем значени€ по разным массивам: 
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
		/*if (arr[i] % 2 == 0)
		{
			even_arr[j] = arr[i];
			j++;
		}
		else {
			odd_arr[k] = arr[i];
			k++;
		}*/
	}
	//выводим полученные массивы в консоль
	cout << "Even arr: ";  print(even_arr, even_count);
	cout << "Odd arr: "; print(odd_arr, odd_count);

	delete[] odd_arr;
	delete[] even_arr;

}
void fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}