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
	// Bổ sung thêm các nội xử lý phần thông tin riêng
	// của manager như chức vụ, hệ số chức vụ, thưởng
	// hàm này sẽ override hàm NhapThongTin của lớp base
	// vì thế cần xử lý nhập thông tin chung và phần thông tin riêng
	void NhapThongTin();

	// Hàm này sẽ xử lý xuất thông tin chung và thông tin riêng của manager
	void XuatThongTin();

	// lương = lương cơ bản + (lương cơ bản x hệ số chức vụ) + thưởng
	float TinhLuong();

	const std::string& getChucVu() const;

	void setChucVu(const std::string& chucVu);

	float getHeSoChucVu() const;

	void setHeSoChucVu(float heSoChucVu);

	float getThuong() const;

	void setThuong(float thuong);
};

#endif /* MANAGER_H_ */
