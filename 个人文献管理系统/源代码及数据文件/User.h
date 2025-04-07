#include<iostream>

using namespace std;

class User
{
	private:
		string name;//”√ªß√˚
		int account;//’À∫≈
	public:
		User(string _name = "User", int _account = 100000)
		{
			name = _name;
			account = _account;
		};
		void set_User(string _name = "", int _account = 100000)
		{
			name = _name;
			account = _account;
		};
		string get_name()
		{
			return name;
		}
		int get_account()
		{
			return account;
		}

		void out_User(ostream &ost)
		{
			ost << account << "\t" << name;
		}
};

class Admin : public User
{
		friend ostream &operator << (ostream &ost, Admin tmp)
		{
			tmp.out_User(ost);
			ost << "\t" << tmp.pin << "\t" << tmp.access;

			return ost;
		}
		friend istream &operator >> (istream &ist, Admin &tmp)
		{
			string _name;
			int _account;
			ist  >> _account >> _name;
			tmp.set_User(_name, _account);
			ist >> tmp.pin >> tmp.access;
			new_account = max(new_account, _account + 1);
			return ist;
		}
	private:
		static int new_account;
		string pin;
		int access = 0;
	public:
		Admin(string _name = "Adminor", string _pin = "000000")
		{
			pin = _pin;
			set_User(_name, new_account);
			new_account++;
			access = 1;
		};
		bool login(int _account = 0, string _pin = "")
		{
			if (get_account() == _account)
				if (pin== _pin)
					if (access == 1)
						return 1;
			return 0;
		};

};
int Admin::new_account = 10001;

class Visitor : public User
{
	public:
		Visitor(string _name = "visitor", int _account = 10000): User(_name, _account) {};

};
