#ifndef MANAGER_H_
#define MANAGER_H_

#include "employee.h"

class Manager : public Employee {

	// Khai báo phần thông tin riêng
private:
	std::string chuc_vu_;
	float he_so_chuc_vu_;
	float thuong_;

public:
	Manager();
	virtual ~Manager();
	//Ham nhap thong tin cua manager va ham nay no override cua lop Employee
	void NhapThongTin();
	//Ham xuat thong tin cua manager va ham nay no override cua lop Employee
	void XuatThongTin();
	//Ham ghi ra file thong tin Manager va ham nay no override cua lop Employee 
	void Ghi_file(std::fstream&);
	//Ham doc file thong tin Manager va ham nay no override cua lop Employee 
	void Doc_file(std::fstream&);
	//luong=luong co ban+(luong co banx he so chuc vu)+ thuong
	float TinhLuong();

	const std::string& getChucVu() const;

	void setChucVu(const std::string& chucVu);

	float getHeSoChucVu() const;

	void setHeSoChucVu(float heSoChucVu);

	float getThuong() const;

	void setThuong(float thuong);
};

#endif /* MANAGER_H_ */
