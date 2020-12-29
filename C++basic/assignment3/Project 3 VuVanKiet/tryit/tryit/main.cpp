
#include "order.h"
using namespace std;
int menu_option;
Order orders[10];
int n;
void Showmenu()//menu chon chuc nang loc du lieu: sap xep,tong tien, loi nhuan.
{
	do
	{
		//system("cls");
		cout << "MENU" << endl;
		cout << "Chuc nang loc du lieu" << endl;
		cout << "1.Sap xep tien lai giam dan" << endl;
		cout << "2.Tong tien tat ca hoa don" << endl;
		cout << "3.Hoa don co tien thue lon nhat" << endl;
		cout << "4.Hoa don co tien thue nho nhat" << endl;
		cout << "5.Thoat chuong trinh" << endl;
		cout << "Vui long chon chuc nang" << endl;
		cin >> menu_option;
	} while (menu_option < 1 || menu_option>5);//nhap lai neu chon sai 
	switch (menu_option)
	{
	case 1://sap xep
		system("cls");
		SortOrderByProfit(orders,n);
		orders[10].PrintOrders(orders,n);
		Showmenu();
		break;
	case 2://tinh tong tien
		system("cls");
		cout << "\nTong tien cac hoa don: " << setw(47) << "" << setw(15) << GetSumSubTotal(orders, n) << endl;
		Showmenu();
		break;
	case 3://hien thi loi nhuan lon nhat
		system("cls");
		PrintOrdersWithMaxTAX(orders, n);
		Showmenu();
		break;
	case 4://hien thi loi nhuan nho nhat
		system("cls");
		PrintOrdersWithMinTAX(orders, n);
		Showmenu();
		break;
	case 5://thoat chuong trinh
		cout << "chuong trinh se thoat" << endl;
		system("pause");
		exit(0);
		break;
	}

}
int main()
{
	cout << "Vao Chuong trinh............." << endl;
	system("pause");
	system("cls");
	do
	{
		//your code here
		cout << "Chon So hoa don can nhap:";
		cin >> n;
		cout << endl;
	} while (n < 1 || n > 10);//chon lai neu khong dung dieu kien

	cout << "\nNhap thong tin cac hoa don:" << endl;
	//your code here
	orders[10].GenerateOrders(orders, n);
	//in ra man hinh danh sach hoa don
	orders[10].PrintOrders(orders, n);//in ra man hinh hoa don nhap vao
	system("pause");
	system("cls");
	Showmenu();
	system("pause");
	return 0;
}

