#include "order.h"
#include "product.h"

using namespace std;

void Order::Input() {
	Product::Input();
	//your code here
	//nhap so luong khong nho hon 0 va gia ban nhap vao la so khong phai ki tu
	do
	{
		cout << "So luong:";
		cin >> quantity_;
		cout << endl;
	} while (quantity_ < 0);//dieu kien khong nho hon 0.

	cout << "Gia ban:";
	cin >> sell_price_;//nhap gia ban
	cout << endl;
	while (!cin)
	{
		cout << "Gia tri nhap vao khong dung.Xin vui long nhap lai gia tri" << endl;
		cin.clear();//reset loi neu nhap vao la character;
		cin.ignore();
		cin >> sell_price_;//nhap lai gia tri
		cout << endl;
	}
}


// In ra thong tin hoa don tren 1 dong theo dinh dang sau
// Do rong 25 ky tu cho ten san pham, can le phai
// Do rong 15 ky tu cho gia nhap, can le phai
// Do rong 10 ky tu so luong san pham, can le phai
// Do rong 15 ky tu cho gia ban, can le phai
// Do rong 15 ky tu cho tong tien hoa don, can le phai
// Do rong 10 ky tu thue VAT, can le phai
// Do rong 15 ky tu cho loi nhuan thu duoc tu hoa don, can le phai
void Order::Output() {
	//cout << setw(25) << GetName() << setw(15) << GetOriginalPrice();
	Product::Output();
	cout << setw(10) << quantity_ << setw(15) << sell_price_ << setw(15) << GetSubTotal();
	cout<< setw(10) << GetVAT() << setw(15) << GetProfit() << endl;
}

// Tra ve tong tien trong hoa don hien tai
// Tong tien = so luong san pham * gia ban 1 san pham
long Order::GetSubTotal() {
	//your code here
	int tongtien;
	tongtien=quantity_ * sell_price_;//cong thuc tinh gia tien cho 1 loai san pham
	return tongtien;
}

// Tra ve thue VAT cho hoa don hien tai
// Thue VAT = (tong tien trong hoa don hien tai)/10, lam tron ve so nguyen
long Order::GetVAT() {
	//your code here
	int thueVAT;
	thueVAT=(GetSubTotal() * 10) / 100;//cong thuc tinh thue VAT
	return thueVAT;
}

// Tra ve loi nhuan (tien lai) tu hoa don hien tai
// Loi nhuan cho 1 san pham la hieu cua gia ban va gia nhap
long Order::GetProfit() {
	//your code here
	int loinhuan;
     loinhuan = (sell_price_ - GetOriginalPrice())*quantity_;//cong thuc tinh loi nhuan
	return loinhuan;
}

// Nhap vao n hoa don, luu trong mang orders
void Order::GenerateOrders(Order orders[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin hoa don: " << i + 1 << endl;
		//your code here
		orders[i].Input();//Nhap thong tin hoa don
	}
}

// In ra thong tin tat ca cac hoa don trong mang dau vao - orders
void Order::PrintOrders(Order orders[], int n) {

	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" <<setw(25)<<"Nam san Xuat" <<setw(20) << "Gia nhap";
	cout << setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "VAT" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << i + 1;
		//your code here
		orders[i].Output();//In ra tat ca hoa don

	}

}

// Tra ve gia tri VAT lon nhat cua hoa don trong mang orders cac hoa don dau vao
long GetMaxVAT(Order orders[], int n)
{
	long max = orders[0].GetVAT();
	for (int i = 1; i < n; i++)
	{
		//your code here
		if (max < orders[i].GetVAT())
		{
			max = orders[i].GetVAT();
		}
	}
	return max;
}
// Tra ve gia tri VAT nho nhat cua hoa don trong mang orders cac hoa don dau vao
long GetMinVAT(Order orders[], int n)
{
	long min = orders[0].GetVAT();
	for (int i = 1; i < n; i++)
	{
		//your code here
		if (min > orders[i].GetVAT())
		{
			min = orders[i].GetVAT();
		}
	}
	return min;
}

// Sap xep mang hoa don orders theo loi nhuan (tien lai) giam dan
void SortOrderByProfit(Order orders[], int n)
{
	Order hoandoi;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (orders[j].GetProfit() > orders[j - 1].GetProfit())
			{
				//your code here
				//so sanh noi bot 
				hoandoi = orders[j];
				orders[j] = orders[j - 1];
				orders[j - 1] = hoandoi;

			}
		}
	}
	
			
}

// In ra cac hoa don co thue VAT lon nhat trong mang orders cac hoa don dau vao
void PrintOrdersWithMaxTAX(Order orders[], int n)
{
	cout << endl;
	//cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(15) << "Gia nhap";
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(25) << "Nam san Xuat" << setw(20) << "Gia nhap";
	cout << setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		if (orders[i].GetVAT() == GetMaxVAT(orders, n))
		{
			//your code here
		    cout << setw(5) << i + 1;
			orders[i].Output();//hien thi hoa don co thue VAT lon nhat
		}
	}
}
// In ra cac hoa don co thue VAT nho nhat trong mang orders cac hoa don dau vao
void PrintOrdersWithMinTAX(Order orders[], int n)
{
	cout << endl;
	//cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(15) << "Gia nhap";
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(25) << "Nam san Xuat" << setw(20) << "Gia nhap";
	cout << setw(10) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		if (orders[i].GetVAT() == GetMinVAT(orders, n))
		{
			//your code here
			cout << setw(5) << i + 1;
			orders[i].Output();//hien thi hoa don co thue VAT lon nhat
		}
	}
}

// Tra ve tong tien tat ca cac hoa don trong mang orders
long GetSumSubTotal(Order orders[], int n)
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		//your code here
		sum = sum+orders[i].GetSubTotal();//cong thuc tinh tong hoa don toan bo san pham
	}
	return sum;
	
}
