#include "employee.h"

using namespace std;

Employee::Employee() {
	ma_so_ = "";
	ten_ = "";
	ngay_sinh_ = "";
	email_ = "";
	dien_thoai_ = "";
	dia_chi_ = "";
	luong_co_ban_ = 0.0;

}

Employee::~Employee() {

}

void Employee::NhapThongTin() {
	cin.ignore();
	cout << "Nhap thong tin mot nhan vien moi\n";
	cout << "Ma so:";
	getline(cin, ma_so_);
	cout << "Ho & Ten:";
	getline(cin, ten_);
	cout << "Ngày sinh:";
	getline(cin, ngay_sinh_);
	cout << "Email:";
	getline(cin, email_);
	cout << "Đien thoai:";
	getline(cin, dien_thoai_);
	cout << "Đia chi:";
	getline(cin, dia_chi_);
	cout << "Luong co ban:";
	cin >> luong_co_ban_;
}

void Employee::XuatThongTin() {
	cout << "Ma so: " << ma_so_ << endl;
	cout << "Ho & Ten: " << ten_ << endl;
	cout << "Ngay sinh: " << ngay_sinh_ << endl;
	cout << "Email: " << email_ << endl;
	cout << "Đien thoai: " << dien_thoai_ << endl;
	cout << "Đia chi: " << dia_chi_ << endl;
}

float Employee::TinhLuong() {
	return luong_co_ban_;
}

const std::string& Employee::getDiaChi() const {
	return dia_chi_;
}

void Employee::setDiaChi(const std::string& diaChi) {
	dia_chi_ = diaChi;
}

const std::string& Employee::getDienThoai() const {
	return dien_thoai_;
}

void Employee::setDienThoai(const std::string& dienThoai) {
	dien_thoai_ = dienThoai;
}

const std::string& Employee::getEmail() const {
	return email_;
}

void Employee::setEmail(const std::string& email) {
	email_ = email;
}

float Employee::getLuongCoBan() const {
	return luong_co_ban_;
}

void Employee::setLuongCoBan(float luongCoBan) {
	luong_co_ban_ = luongCoBan;
}

const std::string& Employee::getMaSo() const {
	return ma_so_;
}

void Employee::setMaSo(const std::string& maSo) {
	ma_so_ = maSo;
}

const std::string& Employee::getNgaySinh() const {
	return ngay_sinh_;
}

void Employee::setNgaySinh(const std::string& ngaySinh) {
	ngay_sinh_ = ngaySinh;
}

const std::string& Employee::getTen() const {
	return ten_;
}

void Employee::setTen(const std::string& ten) {
	ten_ = ten;
}
