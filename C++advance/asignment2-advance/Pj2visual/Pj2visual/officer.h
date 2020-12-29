#ifndef OFFICER_H_
#define OFFICER_H_

#include "employee.h"
class Officer : public Employee {

	// Khai báo phần thông tin riêng
private:
	float tro_cap_;
public:
	Officer();
	virtual ~Officer();

	// Bổ sung thêm các nội dung xử lý phần thông tin riêng
	// Hàm này override từ lớp base và viết thêm nội dung nhập
	// thông tin riêng của officer
	void NhapThongTin();
	// Hàm này override từ lớp base và viết thêm nội dung xuất
	// thông tin riêng của lớp officer
	void XuatThongTin();
	// lương = lương cơ bản + trợ cấp
	float TinhLuong();

	float getTroCap() const;

	void setTroCap(float troCap);
};

#endif /* OFFICER_H_ */
