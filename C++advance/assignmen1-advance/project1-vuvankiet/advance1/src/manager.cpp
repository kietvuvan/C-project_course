#include "manager.h"

using namespace std;

Manager::Manager() :
	Employee() {
	// khoi tao du lieu mac dinh cua manager
	chuc_vu_ = "";
	he_so_chuc_vu_ = 0.0;
	thuong_ = 0.0;
}

Manager::~Manager() {

}
//nhap thong tin
void Manager::NhapThongTin() {
	Employee::NhapThongTin();
	cin.ignore(100, '\n');
	cout << "chuc vu:";
	getline(cin, chuc_vu_);
	cout << endl;
	do
	{
		cout << "he so chuc vu:";
		cin >> he_so_chuc_vu_;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (he_so_chuc_vu_ <= 0.0)
		{
			cout << "gia tri nhap vao khong dung.Xin nhap lai!" << endl;
		}
	} while (he_so_chuc_vu_ <= 0.0);

	do
	{
		cout << "thuong:";
		cin >> thuong_;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thuong_ < 100000)
		{
			cout << "Ban nhap lai gia tri <khong nho hon 100.000>" << endl;
		}
	} while (thuong_ < 100000);
}
//luong_co_ban_ = luong_co_ban_ + (luong_co_ban_ * he_so_chuc_vu_) + thuong_;
float Manager::TinhLuong()
{
	return (luong_co_ban_ + (luong_co_ban_ * he_so_chuc_vu_) + thuong_);
}
//xuat thong tin dinh dang tren 1 dong
//do rong 15 ky tu cho chuc vu, can le phai
//do rong 15 ky tu cho luong co ban, can le phai
//do rong 15 ky tu cho he so chuc vu, can le phai
//do rong 15 ky tu cho thuong, can le phai
//do rong 15 ky tu cho Tieng luong, can le phai
void Manager::XuatThongTin() {
	Employee::XuatThongTin();
	cout << setw(15) << chuc_vu_;
	cout << setw(15) << (size_t)luong_co_ban_;
	cout << setw(15) << he_so_chuc_vu_;
	cout << setw(15) << (size_t)thuong_;
	cout << setw(15) << (size_t)TinhLuong();
	cout << endl;
}
// In ra thong so cua manager tren 1 dong
void Manager::Print()
{
	Employee::Print();
	cout << setw(15) << "chuc vu";
	cout << setw(15) << "luong co ban";
	cout << setw(15) << "he so cv";
	cout << setw(15) << "thuong";
	cout << setw(15) << "Tien luong";
	cout << endl;
}

