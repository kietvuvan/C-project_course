#include "manager.h"
#include "officer.h"
#include "programmer.h"
#include <vector>

using namespace std;

//khoi tao bien idx, idx su dung de lam chi so mang khi duyet
int idx = 0;
int tim_ngay = 0;//khai bao ngay can tim
// Khai báo mảng Employee khởi tạo với 100 phần tử
Employee* employees = new Employee  [100];
//Employee* employees=NULL;// khai bao con tro employees
vector<Employee*> all_employees;//kha bao vector cho tat ca loai nhan vien
vector<Employee*> all_manager;//khai bao vector cho loai nhan vien manager
vector<Employee*> all_officer;//khai bao vector cho loai nhan vien officer
vector<Employee*> all_programmer;//khai bao vector cho loai nhan vien programmer
void MenuInput() {
	//Menu nguoi dung lua chon thong tin
	//cho tung doi tuong la manager, programmer va officer
	int check;
	do {
		system("cls");
		cout << "\n 1-Nhap thong tin manager.";
		cout << "\n 2-Nhap thong tin programmer.";
		cout << "\n 3-Nhap thong tin officer.";
		cout << "\n 0-Thoat.";
		cout << "\n Lua chon cua ban la: ";
		cin >> check;
		switch (check) {
		case 1: {
			cout << "\n Ban nhap thong tin manager:\n";
			// TODO: Xu ly nhap thong tin manager
			employees = new Manager;
			employees->NhapThongTin();
			all_employees.push_back(employees);//them 1 doi tuong con vao mang
			all_manager.push_back(employees);//them 1 doi tuong con vao mang
			break;
		}
		case 2: {
			cout << "\n Ban nhap thong tin programmer:\n";
			// TODO: Ban phai xu ly thong tin o day
			employees = new Programmer;
			employees->NhapThongTin();
			all_employees.push_back(employees);//them 1 doi tuong con vao mang
			all_programmer.push_back(employees);//them 1 doi tuong con vao mang
			break;
		}
		case 3: {
			cout << "\n Ban nhap thong tin officer:\n";
			// TODO: Ban phai xu ly thong tin o day
			employees = new Officer;//  new 1 doi tuong dan xuat-Officer
			employees->NhapThongTin();
			all_employees.push_back(employees);//them 1 doi tuong con vao mang
			all_officer.push_back(employees);//them 1 doi tuong con vao mang
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
//ham sap xep TIEN LUONG cua tung nhan vien tang dan
//bang phuong phap sap xep noi bot
void hamsapxep(vector< Employee*>, int )
{
	Employee *hoandoi;

	for (int i = 0; i < all_employees.size() - 1; i++)
	{
		for (int j = all_employees.size() - 1; j > i; j--)
		{
			if (all_employees[j]->TinhLuong() < all_employees[j - 1]->TinhLuong () )
			{
				hoandoi = all_employees[j-1];
				all_employees[j-1 ] = all_employees[j];
				all_employees[j] = hoandoi;
			}
		}

	}
}


void Menu() {

	//Menu nguoi dung lua chon chuc nang
	//Nhap, xuat va xem thong tin nhan vien
	int ck;
	do {
		system("cls");
		cout << "\n ========Chuong Trinh Quan Ly Nhan Vien========";
		cout << "\n Moi Ban chon:";
		cout << "\n 1-Nhap thong tin nhan vien.";
		cout << "\n 2-Xem thong tin toan bo nhan vien.";
		cout << "\n 3-Xem thong tin tong luong nhan vien.";
		cout << "\n 4-Xuat thong tin nhan vien co cung ngay sinh.";
		cout << "\n 0-Thoat.";
		cout << "\n ============================================\n";
		cout << "\n Lua chon cua ban la: ";
		cin >> ck;
		switch (ck) {
		case 1: {
			// TODO: Bạn code xử lý gọi menu nhập thông tin nhân viên
			MenuInput();
			break;
		}
		case 2: {
			cout << "--------Danh sanh nhan vien--------" << endl;
			// TODO:Hien thi thong tin tat ca nhan vien
			cout << "-----------------------------------" << endl;
			hamsapxep(all_employees, all_employees.size());
			for (idx = 0; idx < all_employees.size(); idx++)
			{

				all_employees[idx]->Print();
				cout << setw(5) << idx + 1;
				all_employees[idx]->XuatThongTin();
			}

			break;
		}
		case 3: {
			double tongluong = 0.0;//tong luong tat ca nhan vien
			double tongluong_manager = 0.0;// tong luong cua loai nhan vien manager
			double tongluong_officer = 0.0;//tong luong loai nhan vien offier
			double tongluong_programmer = 0.0;// tong luong loai nhan vien programmer
			// TODO: ban xu ly code tai day

			for (idx = 0; idx < all_programmer.size(); idx++)
			{
				tongluong_programmer += all_programmer[idx]->TinhLuong();
			}

			for (idx = 0; idx < all_manager.size(); idx++)
			{
				tongluong_manager += all_manager[idx]->TinhLuong();
			}

			for (idx = 0; idx < all_officer.size(); idx++)
			{
				tongluong_officer += all_officer[idx]->TinhLuong();
			}
			cout << "tong luong programmer=" << (size_t)tongluong_programmer << endl;
			cout << "tong luong manager=" << (size_t)tongluong_manager << endl;
			cout << "tong luong officer=" << (size_t)tongluong_officer << endl;
			tongluong = tongluong_manager + tongluong_officer + tongluong_programmer;
			cout << "Tong luong: " << (size_t)tongluong << endl;

			break;
		}
		case 4:
		{
			//so sanh ngay voi gia tri nhap vao neu bang nhau thi in ra danh sach nhan vien do.
			cout << "nhap ngay can tim:";
			cin >> tim_ngay;
			cout << endl;
			bool found=false;
			for (idx = 0; idx < all_employees.size(); idx++)
			{
				if (all_employees[idx]->Getngaysinh() == tim_ngay)// sosanh ngay sinh voi gia tri nhap vao
				{

					all_employees[idx]->Print();
					cout << setw(5) << idx + 1;
					all_employees[idx]->XuatThongTin();
					found = true;
				}

			}
			if (found==false)//truong hop danh sach nhan vien khong co ngay sinh trung ngay tim kiem
			{
				cout << "khong tim thay nhan vien co ngay can tim!" << endl;
			}

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
}

int main() {
	Menu();
	delete [] employees;

	return 0;

}
