#include <iostream>
#include <string>
using namespace std;
//constexpr auto MAX = 1000;
#define MAX 1000

struct Person
{
	string name;
	int sex;//1是男 2是女
	int age;
	string phone;
	string address;
};
struct addressBooks
{
	struct Person personArr[MAX];
	int m_Size;
};
//菜单
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl; 
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、情况联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//添加联系人
void addPerson(addressBooks *abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArr[abs->m_Size].name = name;
		cout << "请输入性别(1代表男，2代表女)： " << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->m_Size].sex = sex;
				break;
			}
		}
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->m_Size].age = age;

		cout << "请输入联系号码： " << endl;
		string number;
		cin >> number;
		abs->personArr[abs->m_Size].phone = number;

		cout << "请输入家庭地址： " << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_Size].address = address;

		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

//显示联系人
void showPerson(addressBooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前没有联系人！ " << endl;
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "姓名： " << abs->personArr[i].name << "\t";
			if (abs->personArr[i].sex == 1)
			{
				cout << "性别： 男" << "\t";
			}
			else
			{
				cout << "性别： 女" << "\t";
			}
			cout << "年龄： " << abs->personArr[i].age <<  "\t";
			cout << "电话： " << abs->personArr[i].phone << "\t";
			cout << "住址： " << abs->personArr[i].address << endl;
		}
	}
	system("pause");
	system("cls");

}

//检查联系人是否存在
int isExist(addressBooks *abs, string m_name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArr[i].name == m_name)
		{
			return i;//存在则返回在数组中编号
		}
	}
	return -1;
}

//删除联系人
void deletePerson(addressBooks *abs)
{
	cout << "请输入需要删除联系人姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人 " << endl;
	}
	else
	{
		for (int i = ret;i<abs->m_Size;i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
			abs->m_Size--;
		}
		cout << "删除成功 " << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(addressBooks *abs)
{
	cout << "请输入需要查找的联系人： " << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else 
	{
		cout << "姓名： " << abs->personArr[ret].name << "\t";
		if (abs->personArr[ret].sex == 1)
		{
			cout << "性别： 男" << "\t";
		}
		else
		{
			cout << "性别： 女" << "\t";
		}
		cout << "年龄： " << abs->personArr[ret].age << "\t";
		cout << "电话： " << abs->personArr[ret].phone << "\t";
		cout << "住址： " << abs->personArr[ret].address << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void changePerson(addressBooks *abs)
{
	cout << "请输入需要查找的联系人： " << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArr[ret].name = name;
		cout << "请输入性别(1代表男，2代表女)： " << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[ret].sex = sex;
				break;
			}
			else
				cout << "输入错误！ " << endl;
		}
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].age = age;

		cout << "请输入联系号码： " << endl;
		string number;
		cin >> number;
		abs->personArr[ret].phone = number;

		cout << "请输入家庭地址： " << endl;
		string address;
		cin >> address;
		abs->personArr[ret].address = address;
		cout << "修改成功！ " << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void clearPerson(addressBooks *abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}
int main()
{
	addressBooks num;
	num.m_Size = 0;

	int select = 0;
	//showMenu();
	while(true)
	{
		//显示菜单
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&num);
			break;
		case 2://显示联系人
			showPerson(&num);

			break;
		case 3://删除联系人
			deletePerson(&num);
			break;
		case 4://查找联系人
			findPerson(&num);
			break;
		case 5://修改联系人
			changePerson(&num);
			break;
		case 6://清空联系人
			clearPerson(&num);
			break;
		case 0:
			cout << "欢迎下次使用 " << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}