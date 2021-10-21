#include <iostream>
#include <string>
using namespace std;
//constexpr auto MAX = 1000;
#define MAX 1000

struct Person
{
	string name;
	int sex;//1���� 2��Ů
	int age;
	string phone;
	string address;
};
struct addressBooks
{
	struct Person personArr[MAX];
	int m_Size;
};
//�˵�
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl; 
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
//�����ϵ��
void addPerson(addressBooks *abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼������" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArr[abs->m_Size].name = name;
		cout << "�������Ա�(1�����У�2����Ů)�� " << endl;
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
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->m_Size].age = age;

		cout << "��������ϵ���룺 " << endl;
		string number;
		cin >> number;
		abs->personArr[abs->m_Size].phone = number;

		cout << "�������ͥ��ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_Size].address = address;

		abs->m_Size++;
		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ��
void showPerson(addressBooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰû����ϵ�ˣ� " << endl;
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "������ " << abs->personArr[i].name << "\t";
			if (abs->personArr[i].sex == 1)
			{
				cout << "�Ա� ��" << "\t";
			}
			else
			{
				cout << "�Ա� Ů" << "\t";
			}
			cout << "���䣺 " << abs->personArr[i].age <<  "\t";
			cout << "�绰�� " << abs->personArr[i].phone << "\t";
			cout << "סַ�� " << abs->personArr[i].address << endl;
		}
	}
	system("pause");
	system("cls");

}

//�����ϵ���Ƿ����
int isExist(addressBooks *abs, string m_name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArr[i].name == m_name)
		{
			return i;//�����򷵻��������б��
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(addressBooks *abs)
{
	cout << "��������Ҫɾ����ϵ�������� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴��� " << endl;
	}
	else
	{
		for (int i = ret;i<abs->m_Size;i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
			abs->m_Size--;
		}
		cout << "ɾ���ɹ� " << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(addressBooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else 
	{
		cout << "������ " << abs->personArr[ret].name << "\t";
		if (abs->personArr[ret].sex == 1)
		{
			cout << "�Ա� ��" << "\t";
		}
		else
		{
			cout << "�Ա� Ů" << "\t";
		}
		cout << "���䣺 " << abs->personArr[ret].age << "\t";
		cout << "�绰�� " << abs->personArr[ret].phone << "\t";
		cout << "סַ�� " << abs->personArr[ret].address << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void changePerson(addressBooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArr[ret].name = name;
		cout << "�������Ա�(1�����У�2����Ů)�� " << endl;
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
				cout << "������� " << endl;
		}
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].age = age;

		cout << "��������ϵ���룺 " << endl;
		string number;
		cin >> number;
		abs->personArr[ret].phone = number;

		cout << "�������ͥ��ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArr[ret].address = address;
		cout << "�޸ĳɹ��� " << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void clearPerson(addressBooks *abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
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
		//��ʾ�˵�
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&num);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&num);

			break;
		case 3://ɾ����ϵ��
			deletePerson(&num);
			break;
		case 4://������ϵ��
			findPerson(&num);
			break;
		case 5://�޸���ϵ��
			changePerson(&num);
			break;
		case 6://�����ϵ��
			clearPerson(&num);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�� " << endl;
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