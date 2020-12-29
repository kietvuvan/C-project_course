#include "employee.h"

using namespace std;
bool Employee::is_number(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}
bool Employee::is_letter(const std::string& l) {
	std::regex pattern("^[a-zA-Z]+$");
	return std::regex_match(l, pattern);
}
bool Employee::is_validDate(const std::string & date) {
    std::regex pattern("^(((0[1-9]|[12][0-9]|30)[-/]?(0[13-9]|1[012])|31[-/]?(0[13578]|1[02])|(0[1-9]|1[0-9]|2[0-8])[-/]?02)[-/]?[0-9]{4}|29[-/]?02[-/]?([0-9]{2}(([2468][048]|[02468][48])|[13579][26])|([13579][26]|[02468][048]|0[0-9]|1[0-6])00))$");
	return std::regex_match(date, pattern);
}
bool Employee::is_email(const std::string & email) {
	return std::regex_match(email, std::regex("^[a-zA-Z0-9][a-zA-Z0-9_.]+@[a-zA-Z0-9_]+.[a-zA-Z0-9_.]+$"));
}

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
	char c;
	//ma so nhap vao theo dinh dang tung doi tuong
	//Neu la manager thi chu cai dau tien la M
	//Neu la officer thi chu cai dau tien la O
	//Neu la programmer thi chu cai dau tien la P
	do {
		cout << "Ma so:";
		getline(cin, ma_so_);
		c = ma_so_[0];
		if (c != 'M' && c != 'O' && c != 'P') {
			cout << " Ma so khong hop le." << endl;
		}
	} while (c != 'M' && c != 'O' && c != 'P');
	////////////////////////////////////////////
	do {
        cout << "Ho & Ten:";
		getline(cin, ten_);
		if (is_letter(ten_) == false) {
			cout << "ten nhap vao khong hop le" << endl;
		}
	} while (is_letter(ten_)==false);
	/////////////////////////////////////////
	do {
		cout << "Ngày sinh:";
		getline(cin, ngay_sinh_);
		if (is_validDate(ngay_sinh_) == false) {
			cout << "ngay sinh khong hop le" << endl;
		}
	} while (is_validDate(ngay_sinh_) == false);
	/////////////////////////////////////////////
	do {
		cout << "Email:";
		getline(cin, email_);
		if (is_email(email_) == false) {
			cout << "email khong hop le." << endl;
		}
	} while (is_email(email_) == false);
	///////////////////////////////////////////
	do {
		cout << "Dien thoai:";
		getline(cin, dien_thoai_);
		if (is_number(dien_thoai_) == false || dien_thoai_.size() <= 9) {
			cout << "Nhap lai so dien thoai" << endl;
		}
	}
	while (is_number(dien_thoai_)==false||dien_thoai_.size()<=9);
	/////////////////////////////////////////////////////////////
	cout << "Dia chi:";
	getline(cin, dia_chi_);
	///////////////////////////////////////////////////////////
	do {
		cout << "nhap luong co ban:";
		cin >> luong_co_ban_;
		if (!cin){
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (luong_co_ban_ < 500000){
			cout << "nhap lai gia tri. luong co ban tu 500.000 tro len" << endl;
		}
	} while (luong_co_ban_ < 500000);
}

void Employee::XuatThongTin() {
	cout << "Ma so: " << ma_so_<< endl;
	cout << "Ho & Ten: " << ten_ << endl;
	cout << "Ngay sinh: " << ngay_sinh_ << endl;
	cout << "Email: " << email_ << endl;
	cout << "Dien thoai: " << dien_thoai_ << endl;
	cout << "Dia chi: " << dia_chi_ << endl;
}


void Employee::Ghi_file(fstream & file_out){
	file_out << ma_so_ << ",";
	file_out << ten_ << ",";
	file_out << ngay_sinh_ << ",";
	file_out << email_ << ",";
	file_out << dien_thoai_ << ",";
	file_out << dia_chi_ << ",";
	file_out << luong_co_ban_ << ",";
}
void Employee::Doc_file(std::fstream & file_in) {
	getline(file_in, ma_so_,',');
	getline(file_in, ten_, ',');
	getline(file_in, ngay_sinh_, ',');
	getline(file_in, email_, ',');
	getline(file_in, dien_thoai_, ',');
	getline(file_in, dia_chi_, ',');
	file_in >> luong_co_ban_;
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
