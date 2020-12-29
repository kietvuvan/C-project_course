#include <iostream>
using namespace std;

// Hoan doi gia tri hai bien
void Swap(int *num1, int *num2)
{
	//your code here
}

// In mang
void PrintArray(int *arr, int n)
{
	//your code here
}

// Thuat toan sap xep noi bot
void BubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			//your code here
		}
	}
}

// Thuat toan sap xep chon
void SelectionSort(int *arr, int n)
{
	int *i, *j;
	int *end = NULL;

	if (n < 2 || arr == NULL)
		return;

	end = arr + n - 1;

	for (i = arr; i < end; i++)
	{
		//your code here
	}
}

int main()
{
	int arr[10]; // Mang dau vao
	int i;
	int n; // Kich thuoc mang
	int menu_option;

	cout << "Kich thuoc mang: ";
	//your code here

	cout << endl << "Nhap mang dau vao: " << endl;
	//your code here

	cout << endl << "Mang truoc khi sap xep: " << endl;
	//your code here
	cout << endl;


	do {
		//your code here
	} while (menu_option != 1 && menu_option != 2);


	switch (menu_option) {
		case 1:
			//your code here
			break;
		case 2:
			//your code here
			break;

	}

	cout << endl << "Mang sau khi sap xep: " << endl;
	//your code here

	return 0;
}
