#include "employee.h"

using namespace std;

Employee::Employee() {
	// TODO: Bạn phải khởi tạo các dữ liệu mặc định của employee ở đây
	ma_so_ = "";
	ten_ = "";
	//ngay_sinh_ = "";
	email_ = "";
	dien_thoai_ = "";
	dia_chi_ = "";
	luong_co_ban_ = 0.0;
	ngay = 0;
	thang = 0;
	nam = 0;
}

Employee::~Employee() {

}

void Employee::NhapThongTin() {
	// TODO: Bạn phải code phần xử lý nhập thông tin ở đây
	cin.ignore(100, '\n');//xoa bo nho dem
	cout << "ma so nhan vien:";
	getline(cin, ma_so_);
	cout << endl;
	cout << "Ten:";
	getline(cin, ten_);
	cout << endl;
	//cout << "ngay sinh<dd/mm/yyyy>";
	//getline(cin, ngay_sinh_);
	do
	{
		cout << "ngay sinh:" << endl;
		cin >> ngay;

		if (!cin)
		{
			cout << "gia tri nhap vao la so.Ban nhap lai!" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (ngay <= 0 || ngay > 31)
		{
			cout << "ngay sinh khong hop le.Ban nhap lai!" << endl;
		}

	} while ( ngay <= 0 || ngay > 31);//ngay sinh tu 1 den 31
	do
	{
		cout << "thang sinh:" << endl;
		cin >> thang;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (thang <= 0 || thang > 12)
		{
			cout << "thang sinh khong hop le.Ban nhap lai!" << endl;
		}
	} while (thang <= 0 || thang > 12);//dieu kien thang tu thang 1->12.
	do
	{
		cout << "nam sinh:" << endl;
		cin >> nam;
		cout << endl;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (nam < 1960 || nam>2000)
		{
			cout << "nam sinh khong hop le. Ban phai nhap lai!" << endl;
		}
	} while (nam < 1960 || nam>2000);//dieu kien nam sinh trong do tuoi lao dong
	cin.ignore();//xoa bo nho dem
	cout << "email:";
	getline(cin, email_);
	cout << endl;
	cout << "dien thoai:";
	getline(cin, dien_thoai_);
	cout << endl;
	cout << "dia chi:";
	getline(cin, dia_chi_);
	cout << endl;
	do {
		cout << "nhap luong co ban:";
		cin >> luong_co_ban_;
		if (!cin)
		{
			cout << "gia tri nhap vao la so" << endl;
			cin.clear();//reset neu nhap vao charactor
			cin.ignore();//xoa bo nho dem
		}
		else if (luong_co_ban_ < 500000)
		{
			cout << "nhap lai gia tri. luong co ban tu 500.000 tro len" << endl;
		}
	} while (luong_co_ban_ < 500000);


}
//do rong 10 ky tu cho ma so, can le phai
//do rong 10 ky tu cho ten, can le phai
//do rong 10 ky tu cho ngay sinh, can le trai
//do rong 10 ky tu cho email, can le phai
//do rong 10 ky tu cho dien thoai, can le phai
//do rong 10 ky tu cho dia chi, can le phai
void Employee::XuatThongTin() {
	// TODO: Bạn code phần xử lý hiển thị thông tin ở đây
	cout << setw(10) << ma_so_;
	cout << setw(10) << ten_;
	cout << setw(-10) << ngay << "/" << thang << "/" << nam;
	cout << setw(10) << email_;
	cout << setw(15) << dien_thoai_;
	cout << setw(10) << dia_chi_;
}
void Employee::Print()
{
	cout << endl;
	cout << setw(5) << "STT" << setw(10) << "Ma so" << setw(10) << "Ten" << setw(10) << "ngay sinh";
	cout << setw(10) << "Email" << setw(15) << "Dien thoai" << setw(10) << "Dia chi";
}

float Employee::TinhLuong() {
	return luong_co_ban_;
}
int Employee::Getngaysinh() const
{
	return ngay;
}
