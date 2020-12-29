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
	do {
		cout << "he so chuc vu:";
		cin >> he_so_chuc_vu_;
		cout << endl;
		if (!cin){
			cout << "gia tri nhap vao la so." << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (he_so_chuc_vu_ <= 0.0){
			cout << "gia tri nhap vao khong dung.Xin nhap lai!" << endl;
		}
	} while (he_so_chuc_vu_ <= 0.0);

	do{
		cout << "thuong:";
		cin >> thuong_;
		cout << endl;
		if (!cin){
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thuong_ < 100000){
			cout << "Ban nhap lai gia tri <khong nho hon 100.000>" << endl;
		}
	} while (thuong_ < 100000);
}

float Manager::TinhLuong() {
	return luong_co_ban_ + luong_co_ban_ * he_so_chuc_vu_ + thuong_;
}

void Manager::XuatThongTin() {
	Employee::XuatThongTin();
	cout << "Chuc vu: " << chuc_vu_ << endl;
	cout << "he so chuc vu:" << he_so_chuc_vu_ << endl;
	cout << "thuong:" << thuong_ << endl;
}
void Manager::Ghi_file(fstream & file_out) {
	Employee::Ghi_file(file_out);
	file_out << chuc_vu_ << ",";
	file_out << he_so_chuc_vu_ << ",";
	file_out << thuong_ << ",";
	file_out << endl;
}
void Manager::Doc_file(std::fstream & file_in) {
	Employee::Doc_file(file_in);
	file_in.seekg(1, 1);
	getline(file_in, chuc_vu_, ',');
	file_in >> he_so_chuc_vu_;
	file_in.seekg(1, 1);
	file_in >> thuong_;
	file_in.seekg(1, 1);
	
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
