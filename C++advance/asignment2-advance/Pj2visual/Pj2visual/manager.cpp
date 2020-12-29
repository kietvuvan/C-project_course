#include "manager.h"

using namespace std;

Manager::Manager() :
	Employee() {
	chuc_vu_ = "";
	he_so_chuc_vu_ = 0.0;
	thuong_ = 0.0;
}

Manager::~Manager() {

}

void Manager::NhapThongTin() {
	Employee::NhapThongTin();
	cin.ignore();
	cout << "Chuc vu:";
	getline(cin, chuc_vu_);
	cout << "He so chu vu:";
	cin >> he_so_chuc_vu_;
	cout << "Thuong:";
	cin >> thuong_;
}

float Manager::TinhLuong() {
	return luong_co_ban_ + luong_co_ban_ * he_so_chuc_vu_ + thuong_;
}

void Manager::XuatThongTin() {
	Employee::XuatThongTin();
	cout << "Chuc vu: " << chuc_vu_ << endl;
	cout << "Luong: " << TinhLuong() << endl;
}

const std::string& Manager::getChucVu() const {
	return chuc_vu_;
}

void Manager::setChucVu(const std::string& chucVu) {
	chuc_vu_ = chucVu;
}

float Manager::getHeSoChucVu() const {
	return he_so_chuc_vu_;
}

void Manager::setHeSoChucVu(float heSoChucVu) {
	he_so_chuc_vu_ = heSoChucVu;
}

float Manager::getThuong() const {
	return thuong_;
}

void Manager::setThuong(float thuong) {
	thuong_ = thuong;
}
