#include<iostream>
using std::cin;
using::std::cout;
using::std::endl;
#define tab "\t"

template<typename T>T fillrand(T arr[], const int n);
//void Fillrand(int**arr, const int rows, )
template<typename T>void print(const T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);
template<typename T>T *push_back(T arr[], int &n, const T value);
template<typename T>T* push_front(T arr[], int& n, const T value);
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T pop_front(T arr[], int& n);
void insert(int arr[], int& n, int index, int value);
void erase(int arr[], int& n, int index);

template<typename T>T** Allocate(int rows, int cols);
template<typename T>T Clear(T** arr, int rows);
template<typename T>T push_row_back(T**& arr, int& rows, int cols, int* row);
template<typename T>T push_row_front(T**& arr, int& rows, int cols, int* row);
void insert_row(int**& arr, int& rows, int cols, int index, int* row);
template<typename T>T pop_row_back(T**& arr, int& rows);
template<typename T>T pop_row_front(T**& arr, int& rows);
void erase_row(int**& arr, int& rows, int index);
template<typename T>T push_col_back(T** arr, int rows, int& cols, int* col);
template<typename T>T push_col_front(T** arr, int rows, int& cols, int* col);
void insert_col(int** arr, int rows, int& cols, int index, int* col);
template<typename T>T pop_col_back(T** arr, int rows, int& cols);
template<typename T>T pop_col_front(T** arr, int rows, int& cols);
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
template<typename T>T fillrand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
template <typename T>void print(const T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template <typename T>void Print(T** arr, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; i < cols; j++) {
			cout << arr[i][j] << tab;

		}
		cout << endl;
	}
}
template<typename T>T* push_back(T arr[], const int &n, const T value)
{
	T* buffer = new T[n + 1];
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
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T>T* pop_back(T arr[], int& n) {
	T* buffer = new T[--n];
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
template<typename T>T push_row_back(T**& arr, int& rows, int cols) {
	return push_back(arr, rows, new T [cols]{}); 
}
template<typename T>T push_row_front(T**& arr, int& rows, int cols) {
	T** newArr = new T* [rows + 1];
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
template<typename T>T push_col_back(T** arr, int rows, int& cols) {
	for (int i = 0; i < rows; ++i) {
		T* newArr = new T[cols + 1];
		for (int j = 0; j < cols; ++j)
			newArr[j] = arr[i][j];
		newArr[cols] = 0;
		delete[] arr[i];
		arr[i] = newArr;
	}
	++cols;
}
template<typename T>T push_col_front(T** arr, int rows, int& cols) {
	for (int i = 0; i < rows; ++i) {
		T* newArr = new T[cols + 1];
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
