#include"pch.h"
#include <iostream>
using namespace std;
int so_lan_lap_bubble = 1;//khoi tao so lan sap xep
int so_lan_lap_selection = 1;//khoi tao so lan lap selection
///// nhap gia tri mang



// Hoan doi gia tri hai bien
void Swap(int *num1, int *num2)
{
	//your code here
	int hoandoi;
	 hoandoi=*num1;
	 *num1 = *num2;
	 *num2 = hoandoi;
	 
}

// In mang
void PrintArray(int *arr, int n)
{
	//your code here
	int i;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}



// Thuat toan sap xep noi bot
void BubbleSort(int *arr, int n)
{
	
	int i, j;
	//int so_lan_lap_bubble = 1;//khoi tao so lan sap xep
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			
			cout << "sap xep phan tu : " << "arr[" << arr[j] << " " << arr[j + 1] << "]" << endl;// sap xep phan tu trong mang
			//your code here
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);//hoan doi 
				
			}
			cout << "lan lap thu :" << so_lan_lap_bubble << endl;
			cout << "mang sau 1 lan sap xep noi bot:" << endl;
			PrintArray(arr, n);//in ra day so sau 1 lan lap
			cout << endl;
			so_lan_lap_bubble++;
		}
		
	}
	
	
}

// Thuat toan sap xep chon
void SelectionSort(int *arr, int n)
{
	
	int *i;
	int	*j;
	int *end = NULL;
	int *imin;// gan gia tri nho nhat mang
	
	if (n < 2 || arr == NULL)
		return;

	end = arr + n - 1;

	for (i = arr; i < end; i++)
	{
		for (j = i + 1; j < end + 1; j++)
		{
			if (*j < *i)
			{
				cout << "sap xep phan tu   " << "arr[" << *i << " " << *j << "]";
				cout << endl;
				Swap(i, j);	//sap xep phan tu 
				cout << endl;
				cout << "Lan lap thu : " << so_lan_lap_selection << " Selection" << endl;
				cout << "mang sau 1 lan sap xep selection:" << endl;
				PrintArray(arr, n);//in ra day so sau 1 lan lap
				cout << endl;
				so_lan_lap_selection++;

			}
			
		}
		
	}
	
}

void sosanh(int *arr, int n)
{
	SelectionSort(arr, n);
	cout << endl;
	BubbleSort(arr, n);
	cout << endl;
	
	cout << "so buoc sap xep bot (Bubble)" << so_lan_lap_bubble << endl;
	cout << "so buoc sap xep chon (selection)" << so_lan_lap_selection << endl;
	cout << "Ket luan:" << endl;
	if (so_lan_lap_selection > so_lan_lap_bubble)
	{
		
		cout << "So buoc sap xep noi bot(Bubble) it buoc hon chon (selection) " << endl;
	}
	else if(so_lan_lap_selection <so_lan_lap_bubble)
	{
		cout << "so buoc sap xep chon (Selection) it buoc hon sap xep noi bot (Bubble)" << endl;
	}
	else
	{
		cout << "so buoc sap xep chon (Selection) bang buoc hon sap xep noi bot (Bubble)" << endl;
	}
	system("pause");
	system("cls");
	exit(0);
	}



int main()
{
	cout << "Vao chuong trinh" << endl;
	system("pause");
	int arr[10]; // Mang dau vao
	int i;
	int n;//kich thuoc mang;
	int menu_option;
	cout << "Kich thuoc mang: ";
	//your code here
	cin >> n;
	cout << endl << "Nhap mang dau vao: " << endl;
	//your code here
	for (i = 0; i < n; i++)
	{
		cout<< "arr[" << i << "]=" ;
		cin >> arr[i];
		cout << endl;
	}
	cout << endl << "Mang truoc khi sap xep : " << endl;
	//your code here
	PrintArray(arr,n);//ket qua
	cout << endl;

	do {
		//your code here

		cout << "Vui long chon thuat toan sap xep" << endl;
		cout << "1. Thuat toan noi bot(bubble)" << endl;
		cout << "2. Thuat toan chon (selection)" << endl;
		cout << "3. So sanh so 2 thuat toan (Extention)" << endl;
		cin >> menu_option;
	} while (menu_option < 1 || menu_option > 3);


	switch (menu_option) {
	case 1:
		//your code here
		BubbleSort(arr,n);
		break;
	case 2:
		//your code here
		SelectionSort(arr, n);
		break;
	case 3:
		sosanh(arr, n);
		break;
	}
	
	
	cout << endl << "Mang sau khi sap xep: " << endl;
	//your code here
	PrintArray(arr, n);
	system("pause");
	return 0;
}