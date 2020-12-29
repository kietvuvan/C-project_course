#include <fstream>
#include "employee.h"
#include "list.cpp"
#include "list.h"
#include "manager.h"
#include "officer.h"
#include "programmer.h"
#include "assert.h"
#include<ctype.h>
using namespace std;

// Khai báo list lưu trữ danh sách nhân viên
List<Employee*> list;

// Lưu vào file text với định dạng như sau:
// MSNV,Tên nhân viên,Ngày sinh,Email,Số điện thoại,Địa chỉ,Lương cơ bản,Chức vụ,Hệ số lương,Thưởng
// Ví dụ:
// NV001,Nguyen Viet Hoang,07/03/1990,hoangnv90@gmail.com,0984378232,Hai Duong,4000000,Quan ly,2,3000000
void SaveToFile(string filename) {
	ofstream f(filename);
	Employee *emp;
	for (int i = 0; i < list.size(); i++) {
		emp = list.get(i);
		// TODO: Bạn phải thực hiện code ghi file theo định dạng
		
	}

	f.close();
}

// Hàm explode sử dụng để tách chuỗi theo ký tự cho trước
// và trả về một vector
const vector<string> explode(const string& s, const char& c) {
	string buff{ "" };
	vector<string> v;

	for (auto n : s) {
		if (n != c)
			buff += n;
		else if (n == c && buff != "") {
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

// Hàm is_number để kiểm tra một chuỗi có phải là số hay không
bool is_number(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

void LoadFromFile(string filename) {
	ifstream f(filename);
	// TODO: Bạn phải thực hiện đọc dữ liệu từ file và tạo đối tượng Employee
	// TODO: và add vào list.
	f.close();
}

void MenuInput() {
	// Viết menu cho người dùng lựa chọn nhập thông tin
	// cho đối tượng là manager, programmer hay officer

	int check;
	do {
		cout << "\n 1-Nhap thong tin manager.";
		cout << "\n 2-Nhap thong tin programmer.";
		cout << "\n 3-Nhap thong tin officer.";
		cout << "\n 0-Thoat.";
		cout << "\n Lua chon cua ban la: ";
		cin >> check;
		switch (check) {
		case 1: {
			cout << "\n Ban nhap thong tin manager:\n";
			// TODO: Bạn phải code ở đây
			// TODO: Khởi tạo đối tượng manager
			// TODO: Gọi hàm nhập thông tin
			// TODO: Add vào list

			break;
		}
		case 2: {
			cout << "\n Ban nhap thong tin programmer:\n";
			// TODO: Bạn phải code ở đây
			// TODO: Khởi tạo đối tượng programmer
			// TODO: Gọi hàm nhập thông tin
			// TODO: Add vào list
			break;
		}
		case 3: {
			cout << "\n Ban nhap thong tin officer:\n";
			// TODO: Bạn code ở đây
			// TODO: Khởi tạo đối tượng officer
			// TODO: Gọi hàm nhập thông tin
			// TODO: Add vào list

			break;
		}
		case 0: {
			break;
		}
		default: {
			assert(false);
		}
		}
		if (check != 0) {
			cout << "\nBan an phim bat ky de tiep tuc!";
			string s;
			cin.ignore();
			getline(cin, s);
		}
	} while (check != 0);

}

void Menu() {
	// Viết menu chính cho người dùng lựa chọn chức năng
	// nhập thông tin, xem thông tin hay xem lương
	int ck;
	do {
		//clrscr();
		cout << "\n ========Chuong Trinh Quan Ly Nhan Vien========";
		cout << "\n Moi Ban chon:";
		cout << "\n 1-Nhap thong tin nhan vien.";
		cout << "\n 2-Xem thong tin toan bo nhan vien.";
		cout << "\n 3-Xem thong tin tong luong nhan vien.";
		cout << "\n 4-Luu thong tin nhan vien ra file.";
		cout << "\n 0-Thoat.";
		cout << "\n ============================================\n";
		cout << "\n Lua chon cua ban la: ";
		cin >> ck;
		switch (ck) {
		case 1: {
			MenuInput();
			break;
		}
		case 2: {
			cout << "--------Danh sanh nhan vien--------" << endl;
			// TODO: Bạn phải viết code xử lý duyệt danh sách ở đây
			// TODO: và hiển thị thông tin của mỗi nhân viên
			cout << "-----------------------------------" << endl;
			break;
		}
		case 3: {
			double tongluong = 0.0;
			// TODO: Bạn phải viết code duyệt danh sách lấy lương của
			// TODO: từng nhân viên để tính tổng
			cout << "Tong luong: " << tongluong << endl;

			break;
		}
		case 4: {
			// Lưu thông tin ra file
			SaveToFile("employee.txt");
			break;
		}
		case 0: {
			cout << "\n Cam on ban da su dung chuong trinh!";
			exit(0);
			break;
		}
		default: {
			assert(false);
		}
		}
		if (ck != 0) {
			cout << "\nBan an phim bat ky de tiep tuc!";
			string s;
			cin.ignore();
			getline(cin, s);
		}
	} while (ck != 0);
}

int main() {
	Menu();
	return 0;
}
