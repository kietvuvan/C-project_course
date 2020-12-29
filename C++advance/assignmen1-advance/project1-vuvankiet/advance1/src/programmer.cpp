#include "programmer.h"

using namespace std;

Programmer::Programmer() {
	//khoi tao gia tri mac dinh cua programmer
	thoi_gian_lam_viec_ = 0;
	thoi_gian_ngoai_gio_ = 0;
	tro_cap_ = 0.0;
}

Programmer::~Programmer() {

}

void Programmer::NhapThongTin() {
	//nhap thong tin cua 1 programmer bao gom thong tin rieng
	Employee::NhapThongTin();
	do {
		cout << "thoi gian lam viec:<ngay>";
		cin >> thoi_gian_lam_viec_;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thoi_gian_lam_viec_<=0||thoi_gian_lam_viec_ > 30)
		{
			cout << "Thoi gian lam viec khong dung.Ban nhap lai gia tri" << endl;
		}
	} while (thoi_gian_lam_viec_ <=0 || thoi_gian_lam_viec_ > 30);//thoi gian lam viec khong duoc qua 30 ngay
	do
	{
		cout << "thoi gian ngoai gio:<gio>";
		cin >> thoi_gian_ngoai_gio_;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thoi_gian_ngoai_gio_ <=0||thoi_gian_ngoai_gio_ > 50)
		{
			cout << "Ban nhap lai gia tri" << endl;
		}
	} while (thoi_gian_ngoai_gio_ <=0 || thoi_gian_ngoai_gio_ > 50);//thoi gian lam overtime khong qua 50h.
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

//luong=luong co ban+(luong co ban/thoi gian lam viec)*thoi gian ngoai gio*1.5+ tro cap
float Programmer::TinhLuong() {

	double luong = 0.0;
	luong = double(luong_co_ban_ + (luong_co_ban_ / thoi_gian_lam_viec_) * thoi_gian_ngoai_gio_ * 1.5 + tro_cap_);
	return luong;
}
//thong tin programmer in tren 1 dong va can le phai
//do rong 15 ky tu cho luong co ban, can le phai
//do rong 15 ky tu cho thoi gian lam viec, can le phai
//do rong 20 ky tu cho thoi gian ngoai gio, can le phai
//do rong 15 ky tu chotro cap, can le phai
//do rong 15 ky tu cho Tinh luong, can le phai
void Programmer::XuatThongTin() {
	Employee::XuatThongTin();
	cout << setw(15) << (size_t)luong_co_ban_;
	cout << setw(15) << thoi_gian_lam_viec_;
	cout << setw(20) << thoi_gian_ngoai_gio_;
	cout << setw(15) << tro_cap_;
	cout << setw(15) << (size_t)TinhLuong() << endl;
}
void Programmer::Print()
{
	Employee::Print();
	cout << setw(15) << "luong CB";
	cout << setw(15) << "TGian lviec";
	cout << setw(20) << " overtime(gio)";
	cout << setw(15) << "tro cap";
	cout << setw(15) << "Tong luong ";
	cout << endl;
}
