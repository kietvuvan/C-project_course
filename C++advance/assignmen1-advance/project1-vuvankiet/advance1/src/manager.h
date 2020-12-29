#ifndef MANAGER_H_
#define MANAGER_H_

#include "employee.h"

class Manager : public Employee {

	// Khai bao phan thong tin rieng
private:
	std::string chuc_vu_;
	float he_so_chuc_vu_;
	float thuong_;

public:
	Manager();
	virtual ~Manager();

	//bo sung them cac noi xu ly phan thong tin rieng
	//cua manager nhu chuc vu,he so chuc vu, thuong
	//ham nay se override ham NhapThongTin cua lop base

	 void NhapThongTin();

	// Hàm ham xuat thong tin cua manager
	 void XuatThongTin();

	//luong=luong co ban+(luong co ban x he so chuc vu)+ thuong
	 float TinhLuong();
	//ham in thong so cua manager tren 1 dong
	 void Print();
};

#endif /* MANAGER_H_ */


