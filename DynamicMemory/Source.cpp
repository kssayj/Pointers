#include<iostream>
using std::cin;
using::std::cout;
using::std::endl;
#define tab "\t"

void fillrand(int arr[], const int n);
void print(const int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int *push_back(int arr[], int &n, int value);
int* push_front(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
void pop_front(int arr[], int& n);
void insert(int arr[], int& n, int index, int value);
void erase(int arr[], int& n, int index);

int** Allocate(int rows, int cols);
void Clear(int** arr, int rows);
void push_row_back(int**& arr, int& rows, int cols, int* row);
void push_row_front(int**& arr, int& rows, int cols, int* row);
void insert_row(int**& arr, int& rows, int cols, int index, int* row);
void pop_row_back(int**& arr, int& rows);
void pop_row_front(int**& arr, int& rows);
void erase_row(int**& arr, int& rows, int index);
void push_col_back(int** arr, int rows, int& cols, int* col);
void push_col_front(int** arr, int rows, int& cols, int* col);
void insert_col(int** arr, int rows, int& cols, int index, int* col);
void pop_col_back(int** arr, int rows, int& cols);
void pop_col_front(int** arr, int rows, int& cols);
void erase_col(int** arr, int rows, int& cols, int index);

//#define DYNAMIC_MAMORY_1
#define DYNAMIC_MAMORY_2

int main() {
	setlocale(LC_ALL, "ru");
#ifdef DYNAMIC_MAMORY_1


	int n = 5;
	cout << "n = "; cin >> n;
	int* arr = new int[n];

	fillrand(arr, n);
	print(arr, n);

	int value;
	cout << "value = "; cin >> value;
	arr=push_back(arr, n, value);
	print(arr, n);

	cout << "value = "; cin >> value;
	arr = push_front(arr, n, value);
	print(arr, n);

	arr = pop_back(arr, n);
	print(arr, n);
	delete[] arr;
#endif 
#ifdef DYNAMIC_MAMORY_2
	int rows;
	int cols;
	cout << "Введите кол-во строк:  "; cin >> rows;
	cout << "Введите кол-во столбцов:  "; cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols] {};
	}
	Print(arr, rows, cols);

	push_row_back(arr, rows, cols); // Добавляем строку в конец
	push_row_front(arr, rows, cols); // Добавляем строку в начало
	insert_row(arr, rows, cols, 1); // Вставляем строку по индексу
	pop_row_back(arr, rows); // Удаляем последнюю строку
	pop_row_front(arr, rows); // Удаляем первую строку
	erase_row(arr, rows, 0); // Удаляем строку по индексу
	cout << endl;
	push_col_back(arr, rows, cols); // Добавляем столбец в конец
	push_col_front(arr, rows, cols); // Добавляем столбец в начало
	insert_col(arr, rows, cols, 1); // Вставляем столбец по индексу
	pop_col_back(arr, rows, cols); // Удаляем последний столбец
	pop_col_front(arr, rows, cols); // Удаляем первый столбец
	erase_col(arr, rows, cols, 0); // Удаляем столбец по индексу

	Clear(arr, rows);



	/*for (int i = 0; i < rows; i++) { //удаляем строки, а затем массив указателей
		delete[] arr[i];
	}
	delete[] arr;*/
#endif 
}
void fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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
void Print(int** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; i < cols; j++) {
			cout << arr[i][j] << tab;

		}
		cout << endl;
	}
}
int* push_back(int arr[], const int &n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	//n++;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n) {
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;*/
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
void pop_front(int arr[], int& n) {
	if (n > 0) {
		int* buffer = new int[--n];
		for (int i = 0; i < n; i++) {
			buffer[i] = arr[i + 1];
		}
		delete[] arr;
		arr = buffer;
	}
}
void insert(int arr[], int& n, int index, int value) {
	if (index < 0 || index > n) {
		cout << "Invalid index\n";
		return;
	}
	int* buffer = new int[++n];
	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index; i < n - 1; i++) {
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void erase(int arr[], int& n, int index) {
	if (index < 0 || index >= n) {
		cout << "Invalid index\n";
		return;
	}
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n + 1; i++) {
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

int** Allocate(int rows, int cols) {
	int** arr = new int* [rows];
	for (int i = 0; i < rows; ++i)
		arr[i] = new int[cols] {};
	return arr;
}
void Clear(int** arr, int rows) {
	for (int i = 0; i < rows; ++i)
		delete[] arr[i];
	delete[] arr;
}
void push_row_back(int**& arr, int& rows, int cols) {
	int** newArr = new int* [rows + 1];
	for (int i = 0; i < rows; ++i)
		newArr[i] = arr[i];
	newArr[rows] = new int[cols] {};
	delete[] arr;
	arr = newArr;
	++rows;
}
void push_row_front(int**& arr, int& rows, int cols) {
	int** newArr = new int* [rows + 1];
	for (int i = 1; i < rows + 1; ++i)
		newArr[i] = arr[i - 1];
	newArr[0] = new int[cols] {};
	delete[] arr;
	arr = newArr;
	++rows;
}
void insert_row(int**& arr, int& rows, int cols, int index) {
	if (index < 0 || index > rows) {
		cout << "Invalid index\n";
		return;
	}
	int** newArr = new int* [rows + 1];
	for (int i = 0; i < index; ++i)
		newArr[i] = arr[i];
	newArr[index] = new int[cols] {};
	for (int i = index; i < rows; ++i)
		newArr[i + 1] = arr[i];
	delete[] arr;
	arr = newArr;
	++rows;
}
void pop_row_back(int**& arr, int& rows) {
	if (rows > 0) {
		int** newArr = new int* [rows - 1];
		for (int i = 0; i < rows - 1; ++i)
			newArr[i] = arr[i];
		delete[] arr[rows - 1];
		delete[] arr;
		arr = newArr;
		--rows;
	}
}
void pop_row_front(int**& arr, int& rows) {
	if (rows > 0) {
		int** newArr = new int* [rows - 1];
		for (int i = 0; i < rows - 1; ++i)
			newArr[i] = arr[i + 1];
		delete[] arr[0];
		delete[] arr;
		arr = newArr;
		--rows;
	}
}
void erase_row(int**& arr, int& rows, int index) {
	if (index < 0 || index >= rows) {
		cout << "Invalid index\n";
		return;
	}
	int** newArr = new int* [rows - 1];
	for (int i = 0; i < index; ++i)
		newArr[i] = arr[i];
	for (int i = index; i < rows - 1; ++i)
		newArr[i] = arr[i + 1];
	delete[] arr[index];
	delete[] arr;
	arr = newArr;
	--rows;
}
void push_col_back(int** arr, int rows, int& cols) {
	for (int i = 0; i < rows; ++i) {
		int* newArr = new int[cols + 1];
		for (int j = 0; j < cols; ++j)
			newArr[j] = arr[i][j];
		newArr[cols] = 0;
		delete[] arr[i];
		arr[i] = newArr;
	}
	++cols;
}
void push_col_front(int** arr, int rows, int& cols) {
	for (int i = 0; i < rows; ++i) {
		int* newArr = new int[cols + 1];
		newArr[0] = 0;
		for (int j = 1; j <= cols; ++j)
			newArr[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = newArr;
	}
	++cols;
}
void insert_col(int** arr, int rows, int& cols, int index) {
	if (index < 0 || index > cols) {
		cout << "Invalid index\n";
		return;
	}
	for (int i = 0; i < rows; ++i) {
		int* newArr = new int[cols + 1];
		for (int j = 0; j < index; ++j)
			newArr[j] = arr[i][j];
		newArr[index] = 0;
		for (int j = index; j < cols; ++j)
			newArr[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = newArr;
	}
	++cols;
}
void pop_col_back(int** arr, int rows, int& cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; ++i) {
			int* newArr = new int[cols - 1];
			for (int j = 0; j < cols - 1; ++j)
				newArr[j] = arr[i][j];
			delete[] arr[i];
			arr[i] = newArr;
		}
		--cols;
	}
}
void pop_col_front(int** arr, int rows, int& cols) {
	if (cols > 0) {
		for (int i = 0; i < rows; ++i) {
			int* newArr = new int[cols - 1];
			for (int j = 0; j < cols - 1; ++j)
				newArr[j] = arr[i][j + 1];
			delete[] arr[i];
			arr[i] = newArr;
		}
		--cols;
	}
}
void erase_col(int** arr, int rows, int& cols, int index) {
	if (index < 0 || index >= cols) {
		cout << "Invalid index\n";
		return;
	}
	for (int i = 0; i < rows; ++i) {
		int* newArr = new int[cols - 1];
		for (int j = 0; j < index; ++j)
			newArr[j] = arr[i][j];
		for (int j = index; j < cols - 1; ++j)
			newArr[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = newArr;
	}
	--cols;
}