#include "product.h"

using namespace std;

// Nhap thong tin san pham, bao gom
// ten san pham, nam san xuat va gia nhap
void Product::Input() {
	getline(cin, name_);
	cout << "Ten san pham:";
	getline(cin, name_);
	cout << endl;
	do {
	cout << "Nam san xuat:";
	cin >> production_year_;
	} while (production_year_ < 2000 || production_year_>2019);//nam san xuat tu 2000 den 2018
	cout << endl;
	cout << "Gia nhap:";
	cin >> original_price_;
	while (!cin)
	{
		cout << "Gia tri nhap vao khong dung.Xin vui long nhap lai gia tri" << endl;
		cin.clear();//reset loi neu nhap vao la character;
		cin.ignore();
		cin >> original_price_;
		cout << endl;
	}
}

// In ra thong tin san pham tren 1 dong theo dinh dang sau
// Do rong 25 ky tu cho ten san pham, can le phai
// Do rong 10 ky tu cho nam san xuat, can le phai
// Do rong 20 ky tu cho gia nhap, can le phai
void Product::Output() {
	//your code here
	cout << setw(25) << GetName();
	cout << setw(25) << GetProductionYear();
	cout << setw(20) << GetOriginalPrice();
}

// Tra ve ten san pham
string Product::GetName() {
	//your code here
	return name_;
};

// Tra ve nam san xuat
int Product::GetProductionYear() {
	//your code here
	return production_year_;
}

// Tra ve gia goc
long Product::GetOriginalPrice() {
	//your code here
	return original_price_;
}
