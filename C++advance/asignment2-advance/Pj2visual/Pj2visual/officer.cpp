#include "officer.h"

using namespace std;

Officer::Officer() {
	tro_cap_ = 0.0;
}

Officer::~Officer() {
}

void Officer::NhapThongTin() {
	Employee::NhapThongTin();
	cin.ignore();
	cout << "Tro cap:";
	cin >> tro_cap_;
}

float Officer::TinhLuong() {
	return luong_co_ban_ + tro_cap_;
}

void Officer::XuatThongTin() {
	Employee::XuatThongTin();
	cout << "Luong: " << TinhLuong() << endl;
}

float Officer::getTroCap() const {
	return tro_cap_;
}

void Officer::setTroCap(float troCap) {
	tro_cap_ = troCap;
}
