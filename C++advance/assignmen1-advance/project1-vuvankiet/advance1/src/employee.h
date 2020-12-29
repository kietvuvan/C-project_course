#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include<iomanip>

//Lop Employee la base class ma se duoc cac lop khac ke thua
//Lop EMployee se luu tru nhung thong tin chung cua employee

class Employee {

	//khai bao cac thong tin chung cua employee
	//Cac thuoc tinh nay se de protected de cho phep ke thua
protected:
	std::string ma_so_;
	std::string ten_;
	//std::string ngay_sinh_;
	int ngay, thang, nam;
	std::string email_;
	std::string dien_thoai_;
	std::string dia_chi_;
	float luong_co_ban_;


public:
	Employee();
	virtual ~Employee();

	//Nhap thong tin co ban cua employee
	virtual void NhapThongTin();
	//hien thi thong tin co ban employee
	virtual void XuatThongTin();
	// Ham tinh luong tra ve luong co ban
	virtual float TinhLuong();
	//ham in ra thong so hien thi nhung thong tin cua employee
	virtual void Print();
	virtual int Getngaysinh() const; //khai bao gia tri ngay la const
};

#endif /* EMPLOYEE_H_ */


