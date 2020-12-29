#include <fstream>
#include "employee.h"
#include "list.cpp"
#include "list.h"
#include "manager.h"
#include "officer.h"
#include "programmer.h"
#include<ctype.h>

using namespace std;
int n;
int tong_luong_manager = 0.0;
int tong_luong_programmer = 0.0;
int tong_luong_officer = 0.0;
Employee *employees = new Employee[100];//khoi tao doi tuong employee
List<Employee*> list;//khai bao list luu tru danh sach nhan vien
//MSNV,Ten,Ngay sinh,Email,So dien thoai, Dia chi, Luong co ban,Chuc vu, He so luong, Thuong.
//luu vao file text voi dinh dang sau:
//Vi du:
// NV001,Nguyen Viet Hoang,07/03/1990,hoangnv90@gmail.com,0984378232,Hai Duong,4000000,Quan ly,2,3000000
void SaveToFile() {
	fstream f;
	Employee *emp;
	f.open("employee.txt", ios::out|ios::in );
	if (!f){
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}
	f >> n;
	n = n + list.dolon();
	f.seekg(-1, 1);
	f << n;
	f << endl;
	f.close();
	f.open("employee.txt", ios::out | ios::app);
	for (int i = 0; i < list.dolon(); i++) {
		emp = list.get(i);
		emp->Ghi_file(f);
	}
	f.close();
}

//ham doc file va xuat thong tin nhan vien
void LoadFromFile() {
	fstream f;
	Employee *emp;
	f.open("employee.txt",ios::in);
	if (!f){
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}
	f >> n;
	for (int i = 0; i < n; i++) {
		char c;
		f >> c;
		f.seekg(-1, 1);
		cout << "Nhan vien thu:" << i + 1 << endl;
		if (c == 'M') {
			emp = new Manager;
			emp->Doc_file(f);
			emp->XuatThongTin();
			tong_luong_manager = (size_t)(emp->TinhLuong());
		}
		else if (c == 'O') {
			emp = new Officer;
			emp->Doc_file(f);
			emp->XuatThongTin();
			tong_luong_officer =(size_t) (emp->TinhLuong());
		}
		else if (c == 'P') {
			emp = new Programmer;
			emp->Doc_file(f);
			emp->XuatThongTin();
			tong_luong_programmer = (size_t)(emp->TinhLuong());
		}

	}
	f.close();
}

//menu lua chon nhap thong tin nhan vien
void MenuInput() {
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
			//khoi tao doi tuong manager va add vao list
			Manager *managers=new Manager;
			managers->NhapThongTin();
			list.add(managers);
			break;
		}
		case 2: {
			cout << "\n Ban nhap thong tin programmer:\n";
	        //khoi tao doi tuong programmer va add vao list
			Programmer *programmers=new Programmer;
			programmers->NhapThongTin();
			list.add(programmers);
			break;
		}
		case 3: {
			cout << "\n Ban nhap thong tin officer:\n";
			//khoi tao doi tuong officer va add vao list
			Officer *officers = new Officer;
			officers->NhapThongTin();
			list.add(officers);
			break;
		}
		case 0: {
			break;
		}
		default: {
			false;
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
	//menu gom cac chuc nang nhap, xuat,ghi,doc thong tin nhan vien
	int ck;
	fstream f;
	f.open("employee.txt", ios::in);
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
			//Lay thong tin toan bo nhan vien trong file employee.txt va xuat ra man hinh
			LoadFromFile();
			cout << "-----------------------------------" << endl;
			
			break;
		}
		case 3: {
			double tongluong = 0.0;
			//tong tuong cua nhan vien bang tong luong cua tung loai nhan vien
			tongluong = (size_t)(tong_luong_manager + tong_luong_officer + tong_luong_programmer);
			cout << "Tong luong: " << (size_t)tongluong << endl;

			break;
		}
		case 4: {
			//Save toan bo thong tin nhan vien
			SaveToFile();
			break;
		}
		case 0: {
			cout << "\n Cam on ban da su dung chuong trinh!";
			exit(0);
			break;
		}
		default: {
			false;
		}
		}
		if (ck != 0) {
			cout << "\nBan an phim bat ky de tiep tuc!";
			string s;
			cin.ignore();
			getline(cin, s);
		}
	} while (ck != 0);
	f.close();
}

int main() {
	delete[] employees;
	Menu();
	return 0;
}
