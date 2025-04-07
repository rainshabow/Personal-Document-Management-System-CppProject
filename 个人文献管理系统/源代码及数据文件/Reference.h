#include<iostream>
#include<vector>

using namespace std;

class Reference
{
		friend istream &operator >> (istream &ist, Reference &tmp)
		{
			int n;
			ist >> tmp.DOI >> tmp.title >> tmp.book >> tmp.age >> tmp.type >> n;
			string _author;
			for (int i = 0; i < n; i++)
			{
				ist >> _author;
				tmp.author.push_back(_author);
			}
			return ist;
		}
		friend ostream &operator << (ostream &ost, Reference &tmp)
		{
			ost << tmp.DOI << "\t" << tmp.title << "\t" << tmp.book << "\t" << tmp.age << "\t" << tmp.type << "\t" << tmp.author.size();
			for (int i = 0; i < tmp.author.size(); i++)
				ost << " " << tmp.author[i];

			return ost;
		}
		friend bool operator < (Reference r1, Reference r2)
		{
			if (r1.DOI < r2.DOI)
				return 1;
			return 0;
		}
		friend bool operator == (Reference r1, Reference r2)
		{
			if (r1.DOI == r2.DOI)
				return 1;
			return 0;
		}

	private:
		string DOI;
		vector<string> author;
		string title;
		string book;
		int age;
		string type;
	public:
		Reference(string DOI = "none", string title = "none", string book = "none", int age = 1990, string type = "none") {};
		static void header(ostream &ost)
		{
			ost << "DOI" << "\t" << "标题" << "\t" << "期刊" << "\t" << "年份" << "\t" << "类型" << "\t" << "作者" << endl;
		}
		void show(ostream &ost) const
		{
			ost << DOI << "\t" << title << "\t" << book << "\t" << age << "\t" << type << "\t";
			for (auto i = author.begin(); i != author.end(); i++)
				ost << *i << " ";
			ost << endl;
		}
		void set_DOI(string _DOI = "")
		{
			DOI = _DOI;
		}
		void set_title(string _title = "")
		{
			title = _title;
		}
		void set_book(string _book = "")
		{
			book = _book;
		}
		void set_age(int _age = 0)
		{
			age = _age;
		}
		void set_author()
		{
			int n;
			string tmp;
			author.clear();
			cout << "请输入作者数量：";
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cout << "请输入第" << i << "作者：";
				cin >> tmp;
				author.push_back(tmp);
			}
		}
		void set_type(string _type = "")
		{
			type = _type;
		}
		bool title_search(string _search = "")
		{
			if (title.find(_search) != -1)
				return 1;
			return 0;
		}
		bool DOI_search(string _search = "")
		{
			if (DOI.find(_search) != -1)
				return 1;
			return 0;
		}
		bool book_search(string _search = "")
		{
			if (book.find(_search) != -1)
				return 1;
			return 0;
		}
		bool age_search(int _age = 1990)
		{
			if (age == _age)
				return 1;
			return 0;
		}
		bool type_search(string _search = "")
		{
			if (type.find(_search) != -1)
				return 1;
			return 0;
		}
		bool author_search(string _search = "")
		{
			for (auto i = author.begin(); i != author.end(); i++)
				if (i->find(_search) != -1)
					return 1;
			return 0;
		}
		void operator = (Reference r)
		{
			DOI = r.DOI;
			title = r.title;
			age = r.age;
			book = r.book;
			type = r.type;
			author.clear();
			for (auto i = r.author.begin(); i != r.author.end(); i++)
			{
				author.push_back(*i);
			}
		}
};
