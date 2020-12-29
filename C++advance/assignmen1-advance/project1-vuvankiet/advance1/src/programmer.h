#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_

#include "employee.h"

class Programmer : public Employee {

	// Khai bao phan thong tin rieng
private:
	int thoi_gian_lam_viec_;
	int thoi_gian_ngoai_gio_;
	float tro_cap_;
public:
	Programmer();
	virtual ~Programmer();

	//Bo sung them cac noi dung xu ly phan thong tin rieng
	//Ham nay override tu lop base va viet them noi dung nhap
	//thong tin rieng cua programmer
	 void NhapThongTin();
	//Ham nay override tu lop base va viet them noi dung xuat
	//thong tin rieng cua lop programmer
	 void XuatThongTin();
	//luong=luong co ban + (luong co ban/thoi gian lam viec theo quy dinh) x thoi gian lam ngoai gio x 1.5 + tro cap
	 float TinhLuong();
	//ham in ra thong so cua programmer tren 1 dong
	void Print();
};

#endif /* PROGRAMMER_H_ */

