#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include<fstream>
#include <string>
#include<regex>

//Lop Employee la base class ma se duoc cac lop khac ke thua
//Lop Employee se luu tru cac thong tin chung cua employee
class Employee {


//khai bao cac thong tin chung cua employee
//cac thuoc tinh se de tam vuc protected de cho phep ke thua
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

	
	//Nhap thong tin co ban cua employee
	virtual void NhapThongTin();
	//Hien thu cac thong tin co ban cua employee
	virtual void XuatThongTin();
	//Ham tinh luong se tra ve luong co ban
	virtual float TinhLuong();
	//Ham ghi thong tin employee ra file.txt
	virtual void Ghi_file(std::fstream&);
	//Ham doc thong tin employee tu fie.txt
	virtual void Doc_file(std::fstream&);
	//Ham kiem tra mot chuoi co phai la so hay khong
	bool is_number(const std::string&);
	//ham kiem tra date theo dinh dang dd//mm/yyyy
	bool is_validDate(const std::string &);
	//ham kiem tra email theo dinh dang abc...@abc.acb
	bool is_email(const std::string &);
	//ham kiem tra string nhap vao co phai la chu hay khong
	bool is_letter(const std::string &);
	//const vector<string> explode(const string&, const char&);
	//Ham setter va getter
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

