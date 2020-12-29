#include "programmer.h"

using namespace std;

Programmer::Programmer() {
	thoi_gian_lam_viec_ = 0;
	thoi_gian_ngoai_gio_ = 0;
	tro_cap_ = 0.0;
}

Programmer::~Programmer() {

}

void Programmer::NhapThongTin() {
	Employee::NhapThongTin();
	cin.ignore();
	do {
		cout << "thoi gian lam viec:<ngay>";
		cin >> thoi_gian_lam_viec_;
		cout << endl;
		if (!cin){
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thoi_gian_lam_viec_ <= 0 || thoi_gian_lam_viec_ > 30){
			cout << "Thoi gian lam viec khong dung.Ban nhap lai gia tri" << endl;
		}
	} while (thoi_gian_lam_viec_ <= 0 || thoi_gian_lam_viec_ > 30);//thoi gian lam viec khong duoc qua 30 ngay
	do{
		cout << "thoi gian ngoai gio:<gio>";
		cin >> thoi_gian_ngoai_gio_;
		cout << endl;
		if (!cin){
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thoi_gian_ngoai_gio_ <= 0 || thoi_gian_ngoai_gio_ > 50){
			cout << "Ban nhap lai gia tri" << endl;
		}
	} while (thoi_gian_ngoai_gio_ <= 0 || thoi_gian_ngoai_gio_ > 50);//thoi gian lam overtime khong qua 50h.
	do{
		cout << "tro cap:";
		cin >> tro_cap_;
		cout << endl;
		if (!cin){
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (tro_cap_ < 100000){
			cout << "Ban xin vui long nhap lai<gia tri khong nho hon 100000>:" << endl;
		}
	} while (tro_cap_ < 100000);
}

float Programmer::TinhLuong() {
	return luong_co_ban_
		+ (luong_co_ban_ / thoi_gian_lam_viec_) * thoi_gian_ngoai_gio_ * 1.5
		+ tro_cap_;
}

void Programmer::XuatThongTin() {
	Employee::XuatThongTin();
	cout << "Thoi gian lam viec: " << thoi_gian_lam_viec_ << endl;
	cout << "Thoi gian ngoai gio: " << thoi_gian_ngoai_gio_ << endl;
	cout << "tro cap:" << tro_cap_ << endl;
}
void Programmer::Ghi_file(std::fstream & file_out) {
	Employee::Ghi_file(file_out);
	file_out << thoi_gian_lam_viec_ << ",";
	file_out << thoi_gian_ngoai_gio_ << ",";
	file_out << tro_cap_ << ",";
	file_out << endl;
}
void Programmer::Doc_file(std::fstream & file_in)
{
	Employee::Doc_file(file_in);
	file_in.seekg(1, 1);
	file_in >> thoi_gian_lam_viec_;
	file_in.seekg(1, 1);
	file_in >> thoi_gian_ngoai_gio_; 
	file_in.seekg(1, 1);
	file_in >> tro_cap_;
}
int Programmer::getThoiGianLamViec() const {
	return thoi_gian_lam_viec_;
}

void Programmer::setThoiGianLamViec(int thoiGianLamViec) {
	thoi_gian_lam_viec_ = thoiGianLamViec;
}

int Programmer::getThoiGianNgoaiGio() const {
	return thoi_gian_ngoai_gio_;
}

void Programmer::setThoiGianNgoaiGio(int thoiGianNgoaiGio) {
	thoi_gian_ngoai_gio_ = thoiGianNgoaiGio;
}

float Programmer::getTroCap() const {
	return tro_cap_;
}

void Programmer::setTroCap(float troCap) {
	tro_cap_ = troCap;
}
