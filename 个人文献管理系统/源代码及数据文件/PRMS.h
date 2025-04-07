#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<fstream>
#include"User.h"
#include"Reference.h"

using namespace std;

class PRMS
{
	private:
		vector<Admin> adm;
		Visitor vis;
		list<Reference>	ref;
	public:
		PRMS()
		{
			ifstream ifs;
			int n;
			cout << "读取用户目录中..." << endl;
			ifs.open("Adminors.txt", ios::in);
			if (!ifs)
				cout << "未检测到用户目录，仅可使用访客模式" << endl;
			else
			{
				cout << "成功读取用户目录" << endl;
				ifs >> n;
				if (!n)
					cout << "无用户信息，仅可使用访客模式" << endl;
				else
					for (int i = 0; i < n; i++)
					{
						Admin tmp;
						ifs >> tmp;
						adm.push_back(tmp);
					}
			}
			ifs.close();

			cout << "读取文献目录中..." << endl;
			ifs.open("Reference.txt", ios::in);
			if (!ifs)
				cout << "未检测到文献目录" << endl;
			else
			{
				cout << "成功读取文献目录" << endl;
				ifs >> n;
				if (!n)
					cout << "无文献信息" << endl;
				else
				{
					set<Reference> refs;
					for (int i = 0; i < n; i++)
					{
						Reference tmp;
						ifs >> tmp;
						refs.insert(tmp);
					}
					for (auto i = refs.begin(); i != refs.end(); i++)
						ref.push_back(*i);
				}
			}
			ifs.close();

			system("color F0");
		}
		bool judge_vis(int account = 0)
		{
			if (account == vis.get_account())
				return 1;
			else
				return 0;
		}
		void show_ref()
		{
			Reference::header(cout);
			for (auto i = ref.begin(); i != ref.end(); i++)
				(*i).show(cout);
		}
		void datasave()
		{
			ofstream ofs;
			ofs.open("Adminors.txt", ios::out | ios:: trunc);
			ofs << adm.size() << endl;
			for (auto i = adm.begin(); i != adm.end(); i++)
				ofs << *i << endl;
			ofs.close();
			set<Reference> refs;
			for (auto i = ref.begin(); i != ref.end(); i++)
			{
				refs.insert(*i);
			}
			ref.clear();
			for (auto i = refs.begin(); i != refs.end(); i++)
			{
				ref.push_back(*i);
			}
			ofs.open("Reference.txt", ios::out | ios:: trunc);
			ofs << ref.size() << endl;
			for (auto i = ref.begin(); i != ref.end(); i++)
				ofs << *i << endl;
		}
		Admin search(int _account)
		{
			for (auto i = adm.begin(); i != adm.end(); i++)
				if (i->get_account() == _account)
					return *i;

			Admin none;
			return none;
		}
		int part(int a)
		{
			switch (a)
			{
				case 0:
					return 0;
				case 1:
				{
					system("cls");
					int n;
					cout << "欢迎使用个人文献管理系统" << endl;
					cout << "1.管理员登录" << endl;
					cout << "2.游客登录" << endl;
					cout << "3.退出" << endl;
					cout << "请选择进行的操作：";
					cin >> n;
					return n;
				}
				case 11:
				{
					int account;
					string pin;
					cout << "请输入账户：";
					cin >> account;
					cout << "请输入密码：";
					cin >> pin;
					for (auto i = adm.begin(); i != adm.end(); i++)
						if (i->login(account, pin))
						{
							cout << "登录成功" << endl;
							cout << "欢迎使用，管理员" << search(account).get_name() << "(" << search(account).get_account() << ")" << endl;
							system("pause");
							return account;
						};
					cout << "登录失败" << endl;
					system("pause");
					return 0;
				}
				case 12:
				{
					cout << "登录成功" << endl;
					cout << "欢迎使用，游客" << vis.get_name() << "(" << vis.get_account() << ")" << endl;
					system("pause");
					return vis.get_account();
				}
				case 21:
				{
					int n;
					system("cls");
					cout << "您正在通过管理员模式访问系统" << endl;
					cout << "1.显示所有文献" << endl;
					cout << "2.查询指定文献" << endl;
					cout << "3.文献信息管理" << endl;
					cout << "4.退出" << endl;
					cout << "请选择：";
					cin >> n;

					return n;
				}
				case 211:
				{
					system("cls");
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						(*i).show(cout);
					system("pause");

					return 0;
				}
				case 212:
				{
					int n;
					system("cls");
					cout << "查询指定文献" << endl;
					cout << "选择查询依据" << endl;
					cout << "1.文献标题" << endl;
					cout << "2.文献DOI" << endl;
					cout << "3.期刊名" << endl;
					cout << "4.年代" << endl;
					cout << "5.类型" << endl;
					cout << "6.作者" << endl;
					cout << "7.退出" << endl;
					cout << "请选择：";
					cin >> n;

					return n;
				}
				case 2121:
				{
					system("cls");
					string tmp;
					cout << "请输入文献标题（部分或完整）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->title_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 2122:
				{
					system("cls");
					string tmp;
					cout << "请输入文献DOI（部分或完整）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->DOI_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 2123:
				{
					system("cls");
					string tmp;
					cout << "请输入期刊名（部分或完整）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->book_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 2124:
				{
					system("cls");
					int tmp;
					cout << "请输入年代 (完整）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->age_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 2125:
				{
					system("cls");
					string tmp;
					cout << "请输入类型名（部分或完整）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->type_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 2126:
				{
					system("cls");
					string tmp;
					cout << "请输入一名作者（部分名或完整名）" << endl;
					cin >> tmp;
					Reference::header(cout);
					for (auto i = ref.begin(); i != ref.end(); i++)
						if (i->author_search(tmp))
							i->show(cout);
					system("pause");

					return 0;
				}
				case 213:
				{
					system("cls");
					cout << "文献信息管理模式" << endl;
					cout << "1.新增文献" << endl;
					cout << "2.已有文献" << endl;
					cout << "3.退出" << endl;
					cout << "请选择：";
					int m;
					cin >> m;
					return m;
				}
				case 2131:
				{
					string tmp;
					int _age;
					Reference _new;
					int a = 0;
					do
					{
						a = 0;
						cout << "请输入DOI：";
						cin >> tmp;
						_new.set_DOI(tmp);

						for (auto i = ref.begin(); i != ref.end(); i++)
							if (*i == _new)
							{
								a = 1;
								cout << "DOI已存在，请核对或在已有文献中修改" << endl;
								cout << "重新输入或退出（1/0）:";
								cin >> a;
								if (!a)
									return 0;
							}

					}
					while (a);
					cout << "请输入标题：";
					cin >> tmp;
					_new.set_title(tmp);
					cout << "请输入所属期刊：";
					cin >> tmp;
					_new.set_book(tmp);
					cout << "请输入发表年份：";
					cin >> _age;
					_new.set_age(_age);
					cout << "请选择类型(Article/Review/...)：";
					cin >> tmp;
					_new.set_type(tmp);
					_new.set_author();
					ref.push_back(_new);
					datasave();
					cout << "录入完成，数据已保存" << endl;
					system("pause");
					break;
				}
				case 2132:
				{
					system("cls");
					cout << "请先选中需要操作的文献" << endl;
					int m;
					cout << "查询指定文献" << endl;
					cout << "选择查询依据" << endl;
					cout << "1.文献标题" << endl;
					cout << "2.文献DOI" << endl;
					cout << "3.期刊名" << endl;
					cout << "4.年代" << endl;
					cout << "5.类型" << endl;
					cout << "6.作者" << endl;
					cout << "7.退出" << endl;
					cout << "请选择：";
					cin >> m;
					switch (m)
					{
						case 1:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "请输入文献标题（部分或完整）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->title_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 2:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "请输入文献DOI（部分或完整）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->DOI_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 3:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "请输入期刊名（部分或完整）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->book_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 4:
						{
							system("cls");
							int tmp;
							set<Reference> refs;
							cout << "请输入年代（部分或完整）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->age_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 5:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "请输入类型（部分或完整）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->type_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 6:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "请输入一名作者（部分名或全名）" << endl;
							cin >> tmp;
							cout << "序号\t";
							Reference::header(cout);
							for (auto i = ref.begin(); i != ref.end(); i++)
								if (i->author_search(tmp))
									refs.insert(*i);
							part_change(refs);
							system("pause");
							break;
						}
						case 7:
							break;
						default :
							cout << "错误的输入" << endl;
							break;
					}
					break;
				}
				case 22:
				{
					int n;
					system("cls");
					cout << "您正在通过访客模式访问系统" << endl;
					cout << "1.显示所有文献" << endl;
					cout << "2.查询指定文献" << endl;
					cout << "3.退出" << endl;
					cout << "请选择：";
					cin >> n;

					return n;
				}
				default:
					return 0;
			}
			return 0;
		}

		int part_login(int &_account)//登录界面
		{
			int n;
			do
			{
				n = part(1);
				switch (n)
				{
					case 1:
						_account = part(11);
						break;
					case 2:
						_account = part(12);
						break;
					case 3:
						return 0;
					default:
						cout << "异常" << endl;
						return 0;
				}
			}
			while (n == 1 && _account == 0);

			return 1;
		}

		void part_change(set<Reference> refs)
		{
			if (refs.empty())
			{
				cout << "未查询到符合条件的文献" << endl;
				return;
			}
			int n = 1;
			for (auto i = refs.begin(); i != refs.end(); i++)
			{
				cout << n << "\t";
				n++;
				i->show(cout);
			};
			do
			{
				cout << "请根据序号选择需要操作的文献：";
				cin >> n;
			}
			while (n > refs.size() && (cout << "错误的输入" << endl));
			system("cls");
			cout << "已选中文献:" << endl;
			Reference::header(cout);
			auto r = refs.begin();
			for (int i = 0; i < n - 1; i++)
				r++;
			r->show(cout);
			cout << "可执行的操作：" << endl;
			cout << "1.修改" << endl;
			cout << "2.删除" << endl;
			cout << "3.取消" << endl;
			do
			{
				cout << "请选择：";
				cin >> n;
				switch (n)
				{

					case 1:
					{
						int m;
						string in;
						auto o = ref.begin();
						for (; o != ref.end(); o++)
							if (*r == *o)
								break;
						Reference tmp = *o;
						do
						{
							cout << "是否修改DOI（1/0）：";
							cin >> m;
							if (m)
							{
								cout << "请输入：";
								cin >> in;
								tmp.set_DOI(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "是否修改标题（1/0）：";
							cin >> m;
							if (m)
							{
								cout << "请输入：";
								cin >> in;
								tmp.set_title(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "是否修改所属期刊（1/0）：";
							cin >> m;
							if (m)
							{
								cout << "请输入：";
								cin >> in;
								tmp.set_book(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "是否修改年份（1/0）：";
							int _age;
							cin >> m;
							if (m)
							{
								cout << "请输入：";
								cin >> _age;
								tmp.set_age(_age);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "是否修改类型（1/0）：";
							cin >> m;
							if (m)
							{
								cout << "请输入：";
								cin >> in;
								tmp.set_type(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "是否修改作者（1/0）：";
							cin >> m;
							if (m)
								tmp.set_author();
						}
						while (m != 0 && m != 1);

						cout << "确认修改吗（1/0）：";
						cin >> m;
						if (m)
						{
							*o = tmp;
							datasave();
							cout << "数据已保存" << endl;
						}
						else
							cout << "已取消" << endl;

						break;
					}
					case 2:
					{
						int m;
						cout << "确认删除吗（1/0）：";
						cin >> m;
						if (!m)
						{
							cout << "已取消" << endl;
							break;
						}
						for (auto i = ref.begin(); i != ref.end(); i++)
							if (*r == *i)
							{
								ref.erase(i);
								datasave();
								cout << "删除完成，已保存" << endl;
								break;
							}
						break;	
					}
					case 3:
						cout << "已取消" << endl;
						break;
					default:
						cout << "错误的输入，已终止操作" << endl;
						break;

				}
			}
			while (n != 1 && n != 2 && n != 3);
		}

		void part_vis()
		{
			int n;
			do
			{
				n = part(22);
				switch (n)
				{
					case 1:
						part(211);
						break;
					case 2:
					{
						int m;
						m = part(212);
						switch (m)
						{
							case 1:
								part(2121);
								break;
							case 2:
								part(2122);
								break;
							case 3:
								part(2123);
								break;
							case 4:
								part(2124);
								break;
							case 5:
								part(2125);
								break;
							case 6:
								part(2126);
								break;
							case 7:
								break;
						}
						break;
					}
					case 3:
						break;
					default:
						cout << "异常输入" << endl;
						break;
				}
			}
			while (n != 3);
		}

		void part_Admin()
		{
			int n;
			do
			{
				n = part(21);
				switch (n)
				{
					case 1:
						part(211);
						break;
					case 2:
					{
						int m;
						m = part(212);
						switch (m)
						{
							case 1:
								part(2121);
								break;
							case 2:
								part(2122);
								break;
							case 3:
								part(2123);
								break;
							case 4:
								part(2124);
								break;
							case 5:
								part(2125);
								break;
							case 6:
								part(2126);
								break;
							case 7:
								break;
						}
						break;
					}
					case 3:
					{
						int m = part(213);
						switch (m)
						{
							case 1:
								part(2131);
								break;
							case 2:
								part(2132);
								break;
							case 3:
								break;
							default:
								cout << "异常输入" << endl;
								break;
						}
						break;
					}
					case 4:
						break;
					default:
						cout << "异常输入" << endl;
						break;

				}
			}
			while (n != 4);
		}

		int run()
		{

			int account;
			int n;
			system("pause");

			if (!(part_login(account)))
				return 0;

			if (judge_vis(account))
				part_vis();
			else
				part_Admin();

			return 0;
		}

		~PRMS()
		{
			cout << "程序退出，数据已自动保存" << endl;
			datasave();
		}

};
