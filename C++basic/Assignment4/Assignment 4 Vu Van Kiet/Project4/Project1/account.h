class Account
{
private:
	int account_number_; // So tai khoan
	char name_[100]; // Ho ten chu tai khoan
	int balance_; // So du tai khoan
	char type_; // Kieu tai khoan. N: binh thuong. V: tai khoan Vip
public:
	void CreateAccount();//ham tao tai khoan
	void Modify();//ham sua tai khoan
	void Deposit(int);//ham nap tien
	void Withdraw(int);//ham rut tien
	void PrintAccount() const;//In tai khoan 
	void PrintAccountInFormat() const;// in tai khoan theo dinh dang.
	int GetAccountNumber() const;// ham khai bao gia tri account_number la const
	int GetBalance() const;// khia bao gia tri balance_ la const
	char GetType() const;// khai bao gia tri type_ la const
};

