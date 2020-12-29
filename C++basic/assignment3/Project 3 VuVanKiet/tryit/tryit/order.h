#pragma once
#include "product.h"

class Order : private Product {
private:
	int quantity_; // So luong san pham
	int sell_price_; // Gia ban moi san pham

public:
	void Input();//ham nhap
	void Output();//ham xuat
	long GetSubTotal();//ham tinh gia tien cho 1 san pham
	long GetVAT();// ham tinh thue VAT
	long GetProfit();//Ham tinh loi nhuan

	void static GenerateOrders(Order orders[], int n); // In ra man hinh thong so tat ca san pham
	void static PrintOrders(Order orders[], int n);//ham in label thong so cua san pham

	friend long GetMaxVAT(Order orders[], int n);//tinh VAT lon nhan
	friend void SortOrderByProfit(Order orders[], int n);//sap xep hoa don theo loi nhuan thu duoc giam dan
	friend void PrintOrdersWithMaxTAX(Order orders[], int n);//In ra man hinh hoa don co VAT lon nhat
	friend long GetSumSubTotal(Order orders[], int n);//In hoa don ra man hinh
	friend long GetMinVAT(Order orders[], int n);//tinh VAT nho nhan
	friend void PrintOrdersWithMinTAX(Order orders[], int n);//In ra man hinhvhoa don co VAT nho nhat
};
