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

	// Ham nhap thong tin cua programmer va ham nay no override cua lop Employee
	void NhapThongTin();
	// Ham xuat thong tin cua programmer va ham nay no override cua lop Employee
	void XuatThongTin();
	//Ham ghi thong tin cua officer tu file.txt va ham nay no override cua lop Employee
	void Ghi_file(std::fstream&);
	//Ham doc thong tin cua officer tu file.txt va ham nay no override cua lop Employee
	void Doc_file(std::fstream&);
	//luong =luong co ban+(luong co ban/thoi gian lam viec theo quy dinh)x thoi gian lam ngoai gio x 1.5 + tro cap;
	float TinhLuong();

	int getThoiGianLamViec() const;

	void setThoiGianLamViec(int thoiGianLamViec);

	int getThoiGianNgoaiGio() const;

	void setThoiGianNgoaiGio(int thoiGianNgoaiGio);

	float getTroCap() const;

	void setTroCap(float troCap);
};

#endif /* PROGRAMMER_H_ */
