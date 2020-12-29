#include "officer.h"

using namespace std;

Officer::Officer() {
	// TODO: Bạn phải khởi tạo các dữ liệu mặc định cho các thành viên của Officer ở đây
	tro_cap_ = 0.0;
}

Officer::~Officer() {
}

void Officer::NhapThongTin() {
	// Nhap thong tin cua officer
	Employee::NhapThongTin();
	cout << endl;
	do
	{
		cout << "tro cap:";
		cin >> tro_cap_;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (tro_cap_ < 100000)
		{
			cout << "Ban xin vui long nhap lai<gia tri khong nho hon 100000>:" << endl;
		}
	} while (tro_cap_ < 100000);
}
// luong = luong co ban + tro cap
float Officer::TinhLuong() {

	return (luong_co_ban_ + tro_cap_);
}

void Officer::XuatThongTin() {
	// Xu ly xuat thong tin in ra dinh dang tren 1 dong
	//do rong 15 ky tu luong co ban, can le phai
	//do rong 15 ky tu cho tro cap, can le phai
	//do rong 15 ky tu cho Tinh luong, can le phai
	Employee::XuatThongTin();
	cout << setw(15) << (size_t)luong_co_ban_;
	cout << setw(15) << tro_cap_;
	cout << setw(15) << (size_t)TinhLuong();
	cout << endl;

}
//Xu ly in thong so cua office tren 1 dong
void Officer::Print()
{
	Employee::Print();
	cout << setw(15) << "Luong co ban";
	cout << setw(15) << "Tro cap";
	cout << setw(15) << "Tien Luong";
	cout << endl;
}
