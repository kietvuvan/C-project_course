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
	cout << "Thoi gian lam viec:";
	cin >> thoi_gian_lam_viec_;
	cout << "Thoi gian ngoai gio:";
	cin >> thoi_gian_ngoai_gio_;
	cout << "Tro cap:";
	cin >> tro_cap_;
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
	cout << "Luong: " << TinhLuong() << endl;
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
