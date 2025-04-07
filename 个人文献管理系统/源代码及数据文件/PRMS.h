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
			cout << "��ȡ�û�Ŀ¼��..." << endl;
			ifs.open("Adminors.txt", ios::in);
			if (!ifs)
				cout << "δ��⵽�û�Ŀ¼������ʹ�÷ÿ�ģʽ" << endl;
			else
			{
				cout << "�ɹ���ȡ�û�Ŀ¼" << endl;
				ifs >> n;
				if (!n)
					cout << "���û���Ϣ������ʹ�÷ÿ�ģʽ" << endl;
				else
					for (int i = 0; i < n; i++)
					{
						Admin tmp;
						ifs >> tmp;
						adm.push_back(tmp);
					}
			}
			ifs.close();

			cout << "��ȡ����Ŀ¼��..." << endl;
			ifs.open("Reference.txt", ios::in);
			if (!ifs)
				cout << "δ��⵽����Ŀ¼" << endl;
			else
			{
				cout << "�ɹ���ȡ����Ŀ¼" << endl;
				ifs >> n;
				if (!n)
					cout << "��������Ϣ" << endl;
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
					cout << "��ӭʹ�ø������׹���ϵͳ" << endl;
					cout << "1.����Ա��¼" << endl;
					cout << "2.�ο͵�¼" << endl;
					cout << "3.�˳�" << endl;
					cout << "��ѡ����еĲ�����";
					cin >> n;
					return n;
				}
				case 11:
				{
					int account;
					string pin;
					cout << "�������˻���";
					cin >> account;
					cout << "���������룺";
					cin >> pin;
					for (auto i = adm.begin(); i != adm.end(); i++)
						if (i->login(account, pin))
						{
							cout << "��¼�ɹ�" << endl;
							cout << "��ӭʹ�ã�����Ա" << search(account).get_name() << "(" << search(account).get_account() << ")" << endl;
							system("pause");
							return account;
						};
					cout << "��¼ʧ��" << endl;
					system("pause");
					return 0;
				}
				case 12:
				{
					cout << "��¼�ɹ�" << endl;
					cout << "��ӭʹ�ã��ο�" << vis.get_name() << "(" << vis.get_account() << ")" << endl;
					system("pause");
					return vis.get_account();
				}
				case 21:
				{
					int n;
					system("cls");
					cout << "������ͨ������Աģʽ����ϵͳ" << endl;
					cout << "1.��ʾ��������" << endl;
					cout << "2.��ѯָ������" << endl;
					cout << "3.������Ϣ����" << endl;
					cout << "4.�˳�" << endl;
					cout << "��ѡ��";
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
					cout << "��ѯָ������" << endl;
					cout << "ѡ���ѯ����" << endl;
					cout << "1.���ױ���" << endl;
					cout << "2.����DOI" << endl;
					cout << "3.�ڿ���" << endl;
					cout << "4.���" << endl;
					cout << "5.����" << endl;
					cout << "6.����" << endl;
					cout << "7.�˳�" << endl;
					cout << "��ѡ��";
					cin >> n;

					return n;
				}
				case 2121:
				{
					system("cls");
					string tmp;
					cout << "���������ױ��⣨���ֻ�������" << endl;
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
					cout << "����������DOI�����ֻ�������" << endl;
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
					cout << "�������ڿ��������ֻ�������" << endl;
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
					cout << "��������� (������" << endl;
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
					cout << "�����������������ֻ�������" << endl;
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
					cout << "������һ�����ߣ�����������������" << endl;
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
					cout << "������Ϣ����ģʽ" << endl;
					cout << "1.��������" << endl;
					cout << "2.��������" << endl;
					cout << "3.�˳�" << endl;
					cout << "��ѡ��";
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
						cout << "������DOI��";
						cin >> tmp;
						_new.set_DOI(tmp);

						for (auto i = ref.begin(); i != ref.end(); i++)
							if (*i == _new)
							{
								a = 1;
								cout << "DOI�Ѵ��ڣ���˶Ի��������������޸�" << endl;
								cout << "����������˳���1/0��:";
								cin >> a;
								if (!a)
									return 0;
							}

					}
					while (a);
					cout << "��������⣺";
					cin >> tmp;
					_new.set_title(tmp);
					cout << "�����������ڿ���";
					cin >> tmp;
					_new.set_book(tmp);
					cout << "�����뷢����ݣ�";
					cin >> _age;
					_new.set_age(_age);
					cout << "��ѡ������(Article/Review/...)��";
					cin >> tmp;
					_new.set_type(tmp);
					_new.set_author();
					ref.push_back(_new);
					datasave();
					cout << "¼����ɣ������ѱ���" << endl;
					system("pause");
					break;
				}
				case 2132:
				{
					system("cls");
					cout << "����ѡ����Ҫ����������" << endl;
					int m;
					cout << "��ѯָ������" << endl;
					cout << "ѡ���ѯ����" << endl;
					cout << "1.���ױ���" << endl;
					cout << "2.����DOI" << endl;
					cout << "3.�ڿ���" << endl;
					cout << "4.���" << endl;
					cout << "5.����" << endl;
					cout << "6.����" << endl;
					cout << "7.�˳�" << endl;
					cout << "��ѡ��";
					cin >> m;
					switch (m)
					{
						case 1:
						{
							system("cls");
							string tmp;
							set<Reference> refs;
							cout << "���������ױ��⣨���ֻ�������" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "����������DOI�����ֻ�������" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "�������ڿ��������ֻ�������" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "��������������ֻ�������" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "���������ͣ����ֻ�������" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "������һ�����ߣ���������ȫ����" << endl;
							cin >> tmp;
							cout << "���\t";
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
							cout << "���������" << endl;
							break;
					}
					break;
				}
				case 22:
				{
					int n;
					system("cls");
					cout << "������ͨ���ÿ�ģʽ����ϵͳ" << endl;
					cout << "1.��ʾ��������" << endl;
					cout << "2.��ѯָ������" << endl;
					cout << "3.�˳�" << endl;
					cout << "��ѡ��";
					cin >> n;

					return n;
				}
				default:
					return 0;
			}
			return 0;
		}

		int part_login(int &_account)//��¼����
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
						cout << "�쳣" << endl;
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
				cout << "δ��ѯ����������������" << endl;
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
				cout << "��������ѡ����Ҫ���������ף�";
				cin >> n;
			}
			while (n > refs.size() && (cout << "���������" << endl));
			system("cls");
			cout << "��ѡ������:" << endl;
			Reference::header(cout);
			auto r = refs.begin();
			for (int i = 0; i < n - 1; i++)
				r++;
			r->show(cout);
			cout << "��ִ�еĲ�����" << endl;
			cout << "1.�޸�" << endl;
			cout << "2.ɾ��" << endl;
			cout << "3.ȡ��" << endl;
			do
			{
				cout << "��ѡ��";
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
							cout << "�Ƿ��޸�DOI��1/0����";
							cin >> m;
							if (m)
							{
								cout << "�����룺";
								cin >> in;
								tmp.set_DOI(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "�Ƿ��޸ı��⣨1/0����";
							cin >> m;
							if (m)
							{
								cout << "�����룺";
								cin >> in;
								tmp.set_title(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "�Ƿ��޸������ڿ���1/0����";
							cin >> m;
							if (m)
							{
								cout << "�����룺";
								cin >> in;
								tmp.set_book(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "�Ƿ��޸���ݣ�1/0����";
							int _age;
							cin >> m;
							if (m)
							{
								cout << "�����룺";
								cin >> _age;
								tmp.set_age(_age);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "�Ƿ��޸����ͣ�1/0����";
							cin >> m;
							if (m)
							{
								cout << "�����룺";
								cin >> in;
								tmp.set_type(in);
							}
						}
						while (m != 0 && m != 1);

						do
						{
							cout << "�Ƿ��޸����ߣ�1/0����";
							cin >> m;
							if (m)
								tmp.set_author();
						}
						while (m != 0 && m != 1);

						cout << "ȷ���޸���1/0����";
						cin >> m;
						if (m)
						{
							*o = tmp;
							datasave();
							cout << "�����ѱ���" << endl;
						}
						else
							cout << "��ȡ��" << endl;

						break;
					}
					case 2:
					{
						int m;
						cout << "ȷ��ɾ����1/0����";
						cin >> m;
						if (!m)
						{
							cout << "��ȡ��" << endl;
							break;
						}
						for (auto i = ref.begin(); i != ref.end(); i++)
							if (*r == *i)
							{
								ref.erase(i);
								datasave();
								cout << "ɾ����ɣ��ѱ���" << endl;
								break;
							}
						break;	
					}
					case 3:
						cout << "��ȡ��" << endl;
						break;
					default:
						cout << "��������룬����ֹ����" << endl;
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
						cout << "�쳣����" << endl;
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
								cout << "�쳣����" << endl;
								break;
						}
						break;
					}
					case 4:
						break;
					default:
						cout << "�쳣����" << endl;
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
			cout << "�����˳����������Զ�����" << endl;
			datasave();
		}

};
