#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "account.h"
using namespace std;

void CreateAccount();
void SearchAndPrintAccount(int);
void SearchAndModifyAccount(int);
void DeleteAccount(int);
void PrintAllAccountInFormat();
void DepositOrWithdraw(int, int);

// Tao moi tai khoan:
// Nhap so tai khoan, ten chu tai khoan, loai tai khoan
// va so du ban dau tu ban phim
void Account::CreateAccount()
{
	//your code here
	do
	{
		cout << "Nhap so tai khoan:";
		cin >> account_number_;
		cout << endl;

	} while (account_number_<=0||account_number_>100);//tai khoan la so nguyen duong nam trong doan1 den 100;
	//cin.getline(name_, 100);
	char dockytuxuongdong_[10];
	cin.getline(dockytuxuongdong_,10);
	cout << "Nhap ten chu tai khoan:";
	cin.getline(name_, 100);
	cout << endl;

	do {
		cout << "Nhap loai tai khoan:";
		cin >> type_;
		cout << endl;
	} while (type_ != 'n'&&type_ != 'v');//Loai tai khoan khac 'n' hoac'v' thi nhap lai

	cout << "Nhap so du ban dau:";
	cin >> balance_;
	while (!cin)
	{
		cout << "gia tri nhap vao khong phai so nguyen. Ban can nhap lai:"<<endl;
		cin.clear();
		cin.ignore();
		cin >> balance_;
	}
}

// Sua doi tai khoan:
// Nhap moi ten chu tai khoan, loai tai khoan va so du
void Account::Modify()
{
	cout << "\nNhap thong tin de thay doi:"<<endl;
	char dockytuxuongdong_[10];
	cin.getline(dockytuxuongdong_, 10);
	cout << "\nTen chu tai khoan: ";
	cin.getline(name_, 100);
	cout << endl;
	do {
		cout << "Nhap loai tai khoan";
		cin >> type_;
		cout << endl;

	} while (type_ != 'n' && type_ != 'v');//Loai tai khoan khac 'n' hoac'v' thi nhap lai
	cout << "So du:";
	cin >> balance_;
	cout << endl;
	while (!cin)
	{
		cout << "gia tri nhap vao khong phai so nguyen. Ban can nhap lai:" << endl;
		cin.clear();
		cin.ignore();
		cin >> balance_;
	}
}

// Nap them tien vao tai khoan
void Account::Deposit(int amount)
{
	//your code here
	balance_ = balance_ +amount;
	
}

// Rut tien tu tai khoan
void Account::Withdraw(int amount)
{
	//your code here
	balance_ = balance_ - amount;
}

// Hien thi thong tin tai khoan (khong in theo dinh dang)
// Thong tin hien thi tren 4 dong:
// Dong 1: So tai khoan
// Dong 2: Ten chu tai khoan
// Dong 3: Loai tai khoan
// Dong 4: So du tai khoan
void Account::PrintAccount() const
{
	cout << "\nSo tai khoan: " << account_number_;
	cout << endl;
	cout << "\nTen chu tai khoan: ";
	//your code here
	cout << name_ << endl;
	cout << "Loai tai khoan:" << type_ << endl;
	cout << "So du tai khoan:" << balance_<<endl;
}

// In ra thong tin tai khoan tren mot dong theo dinh dang
// So tai khoan: do rong 11 ky tu, can le trai
// Ten chu tai khoan: do rong 19 ky tu, can le trai
// Loai tai khoan: do rong 8 ky tu, can le trai
// So du tai khoan: do rong 14 ky tu, can le trai
void Account::PrintAccountInFormat() const
{
	//your code here
	//cout << setw(11) << account_number_;
	cout << account_number_;
	cout << setw(11) << name_;
	cout << setw(19)<<type_;
	cout << setw(11)<<balance_;
	cout << endl;
}

// Lay ra so tai khoan
int Account::GetAccountNumber() const
{
	//your code here
	return account_number_;
}

// Lay ra so du
int Account::GetBalance() const
{
	//your code here
	return balance_;
}

// Lay ra kieu tai khoan
char Account::GetType() const
{
	//your code here
	return type_;
}

int main()
{
	char menu_option;
	int account_number; // Nhap tu ban phim
	//Chon cac chuc nang tuon ung tu 1->8. Nhap lai neu nhap so khac tu 1->8.
	do
	{
		system("cls");
		cout << "\n\n\n\tMenu";
		cout << "\n\n\t1. Tao tai khoan";
		cout << "\n\n\t2. Nop tien";
		cout << "\n\n\t3. Rut tien";
		cout << "\n\n\t4. Tra cuu tai khoan";
		cout << "\n\n\t5. Danh sach tai khoan";
		cout << "\n\n\t6. Xoa tai khoan";
		cout << "\n\n\t7. Sua tai khoan";
		cout << "\n\n\t8. Thoat chuong trinh";
		cout << "\n\n\tChon menu (so tu 1 den 8) ";
		cin >> menu_option;
		system("cls");
		switch (menu_option)
		{
		case '1':
			//your code here
			CreateAccount();
			break;
		case '2':
			cout << "\n\n\tChon so tai khoan: ";
			//your code here
			cin >> account_number;
			DepositOrWithdraw(account_number, 1);
			break;
		case '3':
			cout << "\n\n\tChon tai khoan: ";
			//your code here
			cin >> account_number;
			DepositOrWithdraw(account_number, 2);
			break;
		case '4':
			cout << "\n\n\tNhap so tai khoan: ";
			//your code here
			cin >> account_number;
			SearchAndPrintAccount(account_number);
			break;
		case '5':
			//your code here
			PrintAllAccountInFormat();
			break;
		case '6':
			//your code here
			cout << "\n\n\tNhap so tai khoan: ";
			cin >> account_number;
			DeleteAccount(account_number);
			break;
		case '7':
			cout << "\n\n\tNhap so tai khoan: ";
			//your code here
			cin >> account_number;
			SearchAndModifyAccount(account_number);
			break;
		case '8':
			//your code here
			cout << "Cam on quy khach da su dung dich vu. Hen gap lai !!!!!!!!!!!!!!!" << endl;
			system("pause");
			exit(0);
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (menu_option != '8');
	return 0;
}

// Tao mot tai khoan bang cach nhap tu ban phim
// roi luu tai khoan vua tao vao file "account.dat"
void CreateAccount()
{
	Account account;
	ofstream out_file;
	//your code here
	out_file.open("account.dat", ofstream::out|ofstream::binary|ofstream::app);// output se duoc ghi vao cuoi file "account.dat"
	account.CreateAccount();
	out_file.write(reinterpret_cast<char *> (&account), sizeof(Account));// ep kieu du lieu ve char
	cout << endl;
	cout << "Tai khoan tao thanh cong";
	out_file.close();
}

// Tim va in tai khoan co so tai khoan la account_number (không in theo dinh dang)
// Tim tai khoan trong file "account.dat"
void SearchAndPrintAccount(int account_number)
{
	Account account;
	bool found = false;
	ifstream in_file;

	in_file.open("account.dat", ios::binary);
	if (!in_file)
	{
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}
	cout << "\nKet qua tim kiem:\n";

	while (in_file.read(reinterpret_cast<char *> (&account), sizeof(Account)))//ep kieu ve kieu du lieu char va doc du lieu class Account tu file.
	{
		//your code here
		//so sanh account_number trong file voi gia tri nhap vao.
		//Neu  trung nhau thi in ra tai khoan do.
		if (account.GetAccountNumber() == account_number)
		{
			account.PrintAccount();
			found = true;
		}
	}

	in_file.close();
	
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}

// Tim tai khoan co so tai khoan la account_number (khong in theo dinh dang)
// trong file "account.dat"
// Sau do cho phep nguoi dung sua doi tai khoan nay
// bang cach thay doi ten chu tai khoan, loai tai khoan va so du
// Cuoi cung, luu thay doi vao file "account.dat"
void SearchAndModifyAccount(int account_number)
{
	bool found = false;
	Account account;
	fstream file;

	file.open("account.dat", ios::binary | ios::in | ios::out);//file co the ca doc va ghi gia tri input va output.
	if (!file)
	{
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}

	while (!file.eof() && found == false)
	{
		file.read(reinterpret_cast<char *> (&account), sizeof(Account));// doc gia tri class Account tu file "account.dat"
		//your code here
		if (account.GetAccountNumber() == account_number)
		{
			account.PrintAccount();
			account.Modify();
			int pos = (-1)*static_cast<int>(sizeof(Account));
			file.seekp(pos, ios::cur);//tu vi tri hien tai di chuyen con tro len dau va ghi de
			file.write(reinterpret_cast<char *> (&account), sizeof(Account));//ghi gia tri class Account le file "account.dat"
			cout << "\n\n\t Giao dich thuc hien thanh cong";
			found = true;
		}
		
	}

	file.close();
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}

// Tim tai khoan co so tai khoan la account_number
// trong file "account.dat"
// Sau do xoa tai khoan nay trong file "account.dat"
void DeleteAccount(int account_number)
{
	Account account;
	ifstream in_file;
	ofstream out_file;
	in_file.open("account.dat", ios::binary);

	if (!in_file)//dieu kien khong tim thay file
	{
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}

	// Luu tat ca cac tai khoan trong file "account.dat", tru tai khoan muon xoa vao file "temp.dat"
	out_file.open("temp.dat", ios::binary);
	in_file.seekg(0, ios::beg);//bat dau tu byte dau tien
	while (in_file.read(reinterpret_cast<char *> (&account), sizeof(Account)))
	{
		//your code here
		//ghi account con lai sang file"temp.dat"
		if (account.GetAccountNumber() != account_number)
		{
			//account.PrintAccount();
			out_file.write(reinterpret_cast<char *> (&account), sizeof(Account));//ghi file
		}
	}

	// Dong cac file da mo, xoa file "account.dat", doi ten file "temp.dat" thanh "account.dat"
	//your code here
	in_file.close();
	out_file.close();
	remove("account.dat");//xoa file
	rename("account.dat", "temp.dat");//thay doi tu "account.dat"->"temp.dat".
	cout << "\n\n\tTai khoan da xoa thanh cong";
}

// In ra tat ca cac tai khoan luu trong file "account.dat" theo dinh dang
// Moi tai khoan in tren mot dong
void PrintAllAccountInFormat()
{
	Account account;
	ifstream in_file;
	//in_file.open("account.dat", ios::binary);
	in_file.open("temp.dat", ios::binary);
	if (!in_file)
	{
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}
	cout << "\n\n\t\tDanh sach tai khoan:\n\n";
	cout << "====================================================\n";
	cout << "So TK      Chu TK             Loai    So du\n";
	cout << "====================================================\n";
	while (in_file.read(reinterpret_cast<char *> (&account), sizeof(Account)))
	{
		//your code here
		account.PrintAccountInFormat();
	}
	in_file.close();
}

// Tim tai khoan co so tai khoan la account_number trong file "account.dat"
// Roi nop hoac rut tien vao tai khoan tim duoc
// option = 1: nop tien
// option = 2: rut tien
// So tien nop hoac rut duoc nhap tu ban phim
// Sau cung, luu tai khoan vua sua doi vao file "account.dat"
void DepositOrWithdraw(int account_number, int option)
{
	int amount; // So tien muon rut/nop duoc nhap tu ban phim
	bool found = false;
	Account account;
	fstream file;

	file.open("account.dat", ios::binary | ios::in | ios::out);// file "account.dat co chuc nang ca ghi va doc"
	if (!file)
	{
		//your code here
		cout << "Khong mo duoc. Hay an phim Enter de quay la menu chinh" << endl;
		return;
	}

	while (!file.eof() && found == false)
	{
		file.read(reinterpret_cast<char *> (&account), sizeof(Account));
		if (account.GetAccountNumber() == account_number)
		{
			account.PrintAccount();
			if (option == 1)
			{
				cout << "\n\n\tNop tien ";
				cout << "\n\nNhap so tien nop: ";
				//your code here
				cin >> amount;
				account.Deposit(amount);
				
			}
			else if (option == 2)
			{
				cout << "\n\n\tRut tien ";
				
				do {
					cout << "\n\nNhap so tien rut: ";
					cin >> amount;
				} while (account.GetBalance() < amount);//nhap lai neu so tien rut lon hon gia tri hien tai.
				account.Withdraw(amount);
				
			}

			//your code here
			int pos = (-1)*static_cast<int>(sizeof(Account));// ep khieu ve kieu du dieu integer.
			file.seekp(pos, ios::cur);//di chuyen con tro len dau va ghi de
			file.write(reinterpret_cast<char *> (&account), sizeof(Account));
			cout << "\n\n\t Giao dich thuc hien thanh cong";
			found = true;
		}
	}

	file.close();
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}
