#include <iostream>
#include <string>
using namespace std;

string account_number;
int menu_option;
int withdraw_option;
float deposit_amount;
char welcome_option;
float balance_amount = 5000000;

// Function declarations
void Welcome();
void ShowMenu();
void CheckBalance();
void Withdraw();
void Deposit();
void Eject();


int main()
{
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "--Vui long dua the ATM vao--" << endl;
	//system("pause");
	//your code here
	//system("pause");
	return 0;
}

// Hien thi thong diep welcome va
// yeu cau nguoi dung nhap vao tai khoan giao dich

void Welcome() {
	system("cls");
	cout << "--ATM C++ kinh chao quy khach--" << endl;
	cout << "Da nhan duoc the, vui long nhap tai khoan giao dich:" << endl;

	cin >> account_number;
	//your code here

	cin >> welcome_option;
	system("cls");


	while (1) {
		if (welcome_option != 'n' && welcome_option != 'y'){
			//your code here
			continue;
		}
		if (welcome_option == 'y') {
			//your code here
		} else {
			//your code here
		}
	}

	ShowMenu();
}

// Hien thi menu voi 4 chuc nang
void ShowMenu() {
	do {
		system("cls");
		//your code here
		cin >> menu_option;
	} while (menu_option < 1 || menu_option>4);

	switch (menu_option) {
	case 1:
		CheckBalance();
		break;
	case 2:
		Withdraw();
		break;
	case 3:
		Deposit();
		break;
	case 4:
		Eject();
	}
}

// Tra cuu so du
void CheckBalance()
{
	system("cls");
	//your code here
	system("pause");
	ShowMenu();
}

// Rut tien trong tai khoan
void Withdraw()
{
	system("cls");
	do {
		cout << "--RUT TIEN--" << endl;
		//your code here
		cin >> withdraw_option;
		cout << endl;
	} while (withdraw_option < 1 || withdraw_option>7);


	int withdraw_amount = 0; // So tien muon rut
	switch (withdraw_option) {
		case 1:
			//your code here
		case 2:
			//your code here
		case 3:
			//your code here
		case 4:
			//your code here
		case 5:
			//your code here
		case 6:
			//your code here
		case 7:
			cout << "\nVe man hinh chinh..." << endl;
			system("pause");
			ShowMenu();
			return;
	}
	if (balance_amount < withdraw_amount) {
		//your code here
	} else {
		//your code here

		cout << "Vui long nhan lai the ATM va kiem tra tien truoc khi di" << endl;
	}


	system("pause");
	ShowMenu();
}


// Nap tien vao tai khoan
void Deposit()
{
	system("cls");
	cout << "Nap tien" << endl;
	//your code here
	cout << "\nSo du hien tai: " << balance_amount << endl;
	cout << endl;
	system("pause");
	ShowMenu();
}

// Ngung giao dich
void Eject()
{
	system("cls");
	cout << "--ATM C++--" << endl;
	cout << "\nKet thuc..." << endl;
	cout << "\nVui long nhan the va tien o khe cam" << endl;
	cout << "\nCam on quy khach da su dung dich vu tai ATM C++" << endl;
}