#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_

#include "employee.h"

class Programmer : public Employee {

	// Khai báo phần thông tin riêng
private:
	int thoi_gian_lam_viec_;
	int thoi_gian_ngoai_gio_;
	float tro_cap_;
public:
	Programmer();
	virtual ~Programmer();

	// Bổ sung thêm các nội dung xử lý phần thông tin riêng
	// Hàm này override từ lớp base và viết thêm nội dung nhập
	// thông tin riêng của programmer
	void NhapThongTin();
	// Hàm này override từ lớp base và viết thêm nội dung xuất
	// thông tin riêng của lớp programmer
	void XuatThongTin();
	// lương = lương cơ bản +  (lương cơ bản / thời gian làm việc theo quy định) x thời gian làm ngoài giờ x 1.5 + trợ cấp
	float TinhLuong();

	int getThoiGianLamViec() const;

	void setThoiGianLamViec(int thoiGianLamViec);

	int getThoiGianNgoaiGio() const;

	void setThoiGianNgoaiGio(int thoiGianNgoaiGio);

	float getTroCap() const;

	void setTroCap(float troCap);
};

#endif /* PROGRAMMER_H_ */
