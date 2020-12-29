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

float Officer::TinhLuong() {
	return luong_co_ban_ + tro_cap_;
}

void Officer::XuatThongTin() {
	Employee::XuatThongTin();
	cout << "Luong: " << TinhLuong() << endl;
}
void Officer::Ghi_file(std::fstream &file_out)
{
	Employee::Ghi_file(file_out);
	file_out << tro_cap_ << ",";
	file_out << endl;
}
void Officer::Doc_file(std::fstream & file_in)
{
	Employee::Doc_file(file_in);
	file_in.seekg(1, 1);
	file_in >> tro_cap_;
}
float Officer::getTroCap() const {
	return tro_cap_;
}

void Officer::setTroCap(float troCap) {
	tro_cap_ = troCap;
}
