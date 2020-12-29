#ifndef OFFICER_H_
#define OFFICER_H_

#include "employee.h"

class Officer : public Employee {

	// Khai bao phan thong tin rieng
private:
	float tro_cap_;
public:
	Officer();
	virtual ~Officer();

	//Bo sung them cac noi dung xu ly phan thong tin rieng
	//Ham nay override tu lop base va viet them noi dung nhap
	//thong tin rieng cua officer
	void NhapThongTin();
	//Ham nay override thu lop base va viet them noi dung xuat
	//thong tin rieng cua lop officer
	void XuatThongTin();
	// luong=luong co ban+ tro cap
	float TinhLuong();
	void Print();
};

#endif /* OFFICER_H_ */



