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

	//Ham nhap thong tin cua officer va ham nay no override cua lop Employee
	void NhapThongTin();
	//Ham xuat thong tin cua officer va ham nay no override cua lop Employee
	void XuatThongTin();
	//Ham ghi thong tin cua officer tu file.txt va ham nay no override cua lop Employee
	void Ghi_file(std::fstream&);
	//Ham doc thong tin cua officer tu file.txt va ham nay no override cua lop Employee
	void Doc_file(std::fstream&);
	// luong=luong co ban + tro cap
	float TinhLuong();

	float getTroCap() const;

	void setTroCap(float troCap);
};

#endif /* OFFICER_H_ */
