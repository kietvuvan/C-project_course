#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

// Lớp Employee là base class mà sẽ được các lớp khác kế thừa
// Lớp Employee sẽ lưu trữ những thông tin chung của employee
class Employee {

	// Khai báo các thông tin chung của employee
	// Các thuộc tính này sẽ để protected để cho phép kế thừa
protected:
	std::string ma_so_;
	std::string ten_;
	std::string ngay_sinh_;
	std::string email_;
	std::string dien_thoai_;
	std::string dia_chi_;
	float luong_co_ban_;

public:
	Employee();
	virtual ~Employee();

	// Nhập các thông tin cơ bản của employee
	virtual void NhapThongTin();
	// Hiển thị các thông tin cơ bản của employee
	virtual void XuatThongTin();
	// Hàm tính lương sẽ trả về lương cơ bản
	virtual float TinhLuong();

	const std::string& getDiaChi() const;

	void setDiaChi(const std::string& diaChi);

	const std::string& getDienThoai() const;

	void setDienThoai(const std::string& dienThoai);

	const std::string& getEmail() const;

	void setEmail(const std::string& email);

	float getLuongCoBan() const;

	void setLuongCoBan(float luongCoBan);

	const std::string& getMaSo() const;

	void setMaSo(const std::string& maSo);

	const std::string& getNgaySinh() const;

	void setNgaySinh(const std::string& ngaySinh);

	const std::string& getTen() const;

	void setTen(const std::string& ten);
};

#endif /* EMPLOYEE_H_ */
