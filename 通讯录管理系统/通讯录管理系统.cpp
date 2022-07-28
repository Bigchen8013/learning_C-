#include<iostream>
#include<string>
#include<cstdlib>
#define MAX 1000   // �������1000
using namespace std;

// ��ϵ�˽ṹ��
struct person
{
	string name;   // ����
	int sex;    //�Ա�,1��0Ů
	int age;
	string phone;
	string address;
};

// ͨѶ¼�ṹ��
struct address_book
{
	// ��ϵ������
	struct person personArray[MAX];
	// ���鳤��
	int len;
};

// �����ϵ��
void addPerson(address_book * abs)
{
	// ���ж�ͨѶ¼�Ƿ���������������������ӣ�����������
	if (abs->len >= 999)
	{
		cout << "ͨѶ¼���������ܼ������" << endl;
		return;
	}
	else
	{
		cout << " ��������ϵ�������� " << endl;
		string name;
		cin >> name;
		abs->personArray[abs->len].name = name;
		cout << " ��������ϵ���Ա�(1Ϊ���ԣ�2ΪŮ�ԣ��� " << endl;
		int sex = 0;
		
		// ����������жϣ����벻��ȷ������
		while (true)
		{
			// ����������1����2����ȷ������һֱ���룬֪����ȷΪֹ
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->len].sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		

		cout << " ��������ϵ�����䣺 " << endl;
		int age;
		while (true)
		{
			// �ж����䣬��������Ļ���������
			cin >> age;
			if (0 <= age <= 130)
			{
				abs->personArray[abs->len].age = age;
				break;
			}
			cout << "���������������������룡" << endl;
		}
		
		cout << " ��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->len].phone = phone;
		cout << " ��������ϵ��סַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->len].address = address;

		// ������ɺ󣬸���ͨѶ¼���ȼ�1
		abs->len++;
		cout << "��ӳɹ���" << endl;
	}
	system("pause");  // �밴���������
	system("cls");   // ��������
}

// ��ʾ��ϵ��
void showabs(address_book* abs)
{
	// ͨѶ¼��û����Ա����ʾΪ�գ���������0����ʾͨѶ¼�е���Ϣ
	if (abs->len == 0)
	{
		cout << "ͨѶ¼Ϊ�գ���" << endl;
	}
	else
	{
		for (int i = 0; i < abs->len; i++)
		{
			cout << "������" << abs->personArray[i].name 
				<< "\t �Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů")
				<< "\t ���䣺" << abs->personArray[i].age << "\t ��ϵ�绰��" << abs->personArray[i].phone
				<< "\t סַ��" << abs->personArray[i].address << endl;
		}
	}
	system("pause");  // �밴���������
	system("cls");   // ��������
}

// �����ϵ���Ƿ���ڣ����ڷ���λ�ã������ڷ���-1
int isExist(address_book *abs, string name)
{
	for (int i = 0; i < abs->len; i++)
	{
		// �ҵ��û�������
		if (abs->personArray[i].name == name)
		{
			return i;
		}
	}
	// ��������û���ҵ�������-1
	return -1;
}
// ����˵���ť
void showMenu()
{
	// ��Ϣ��ʾ
	cout << "****************************" << endl
		<< "******1. �����ϵ��*********" << endl
		<< "******2. ��ʾ��ϵ��*********" << endl
		<< "******3. ɾ����ϵ��*********" << endl
		<< "******4. ������ϵ��*********" << endl
		<< "******5. �޸���ϵ��*********" << endl
		<< "******6. �����ϵ��*********" << endl
		<< "******0. �˳�ͨѶ¼*********" << endl
		<< "****************************" << endl;
}

// ɾ����ϵ��
void deletePerson(address_book *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "���޴��ˣ�����ɾ����" << endl;
	}
	else
	{
		// �ҵ�����Ҫɾ������
		// Ҫɾ�����±꿪ʼ�������������ǰ�ƶ�һ����λ��ͨѶ¼�ĳ��ȼ�1
		for (int i = res; i < abs->len; i++)
		{
			// ����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->len -= 1;   // ����ͨѶ¼�ĳ���
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");  // �밴���������
	system("cls");   // ��������
}

// ������ϵ��
void searchPerson(address_book *abs)
{
	cout << "�������Ҫ���ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		cout << " ���ҳɹ�������ϢΪ��" << endl;
		//������ϵ��,��������ص���Ϣ
		cout << "������" << abs->personArray[res].name
			<< "\t �Ա�" << (abs->personArray[res].sex == 1 ? "��" : "Ů")
			<< "\t ���䣺" << abs->personArray[res].age << "\t ��ϵ�绰��" << abs->personArray[res].phone
			<< "\t סַ��" << abs->personArray[res].address << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	system("pause");
	system("cls");
}

// �޸���ϵ��
void modifyPerson(address_book* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		// �޸�ָ��������
		cout << "ѡ��Ҫ�޸ĵ����ԣ�" << endl;
		cout << "1--����" << endl
			<< "2--�Ա�" << endl
			<< "3--����" << endl
			<< "4--�绰" << endl
			<< "5--סַ" << endl;
		int modify_choose;
		cin >> modify_choose;
		switch (modify_choose)
		{
		case 1:  // �޸�����
		{
			string modify_name;
			cout << "�������޸ĺ������:" << endl;
			cin >> modify_name;
			abs->personArray[res].name = modify_name;
			break;
		}
		case 2:   // �޸��Ա�
		{
			int modify_sex = 0;
			cout << "�������޸ĺ���Ա�1Ϊ���ԣ�2ΪŮ�ԣ�:" << endl;
			// ����������жϣ����벻��ȷ������
			while (true)
			{
				// ����������1����2����ȷ������һֱ���룬֪����ȷΪֹ
				cin >> modify_sex;
				if (modify_sex == 1 || modify_sex == 2)
				{
					abs->personArray[res].sex = modify_sex;
					break;
				}
				cout << "����������������" << endl;
			}
			break;
		}
		case 3:   // �޸�����
		{
			int modify_age;
			cout << "�������޸ĺ������:" << endl;
			while (true)
			{
				// �ж����䣬��������Ļ���������
				cin >> modify_age;
				if (0 <= modify_age <= 130)
				{
					abs->personArray[res].age = modify_age;
					break;
				}
				cout << "���������������������룡" << endl;
			}
			break;
		}
		case 4:   // �޸���ϵ�绰
		{
			string modify_phone;
			cout << "�������޸ĺ�ĵ绰:" << endl;
			cin >> modify_phone;
			abs->personArray[res].phone = modify_phone;
			break;
		}
		case 5:   // �޸ĵ�ַ
		{
			string modify_address;
			cout << "�������޸ĺ�ĵ�ַ:" << endl;
			cin >> modify_address;
			abs->personArray[res].address = modify_address;
			break;
		}
		default:
			cout << "��������" << endl;
			break;
		}

		/**  ����Ĵ������������Զ��޸ĵ����
		* ����Ҫ���û�������ѡ���޸ĵ�ʱ��ʹ��switch����ѡ�����ȫ�����޸Ļ����ض������޸�
		// �޸�����
		string modify_name;
		cout << "�������޸ĺ������:" << endl;
		cin >> modify_name;
		abs->personArray[res].name = modify_name;
		// �޸��Ա�
		int modify_sex = 0;
		cout << "�������޸ĺ���Ա�1Ϊ���ԣ�2ΪŮ�ԣ�:" << endl;
		// ����������жϣ����벻��ȷ������
		while (true)
		{
			// ����������1����2����ȷ������һֱ���룬֪����ȷΪֹ
			cin >> modify_sex;
			if (modify_sex == 1 || modify_sex == 2)
			{
				abs->personArray[res].sex = modify_sex;
				break;
			}
			cout << "����������������" << endl;
		}
		// �޸�����
		int modify_age;
		cout << "�������޸ĺ������:" << endl;
		while (true)
		{
			// �ж����䣬��������Ļ���������
			cin >> modify_age;
			if (0 <= modify_age <= 130)
			{
				abs->personArray[res].age = modify_age;
				break;
			}
			cout << "���������������������룡" << endl;
		}
		// �޸���ϵ�绰
		string modify_phone;
		cout << "�������޸ĺ�ĵ绰:" << endl;
		cin >> modify_phone;
		abs->personArray[res].phone = modify_phone;
		// �޸ĵ�ַ
		string modify_address;
		cout << "�������޸ĺ�ĵ�ַ:" << endl;
		cin >> modify_address;
		abs->personArray[res].address = modify_address;
		**/
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// �����ϵ��
// ֻҪ��ͨѶ¼��¼����ϵ��������Ϊ0�����߼���ռ���
void clearAddressBooks(address_book* abs)
{
	cout << " ȷ��Ҫ�����ϵ����1. ȷ���� 2. ��ȷ��" << endl;
	int isClear = 0;
	cin >> isClear;
	if (isClear == 1)
	{
		abs->len = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼�ṹ�����
	struct address_book abs;
	abs.len = 0;   // ��ʼ������
	int select;
	do
	{
		showMenu();
		cout << "�û�����ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			// �˳�ͨѶ¼
			cout << " �˳�ͨѶ¼" << endl;
			break;
		case 1:
			// �����ϵ��
			cout << " �����ϵ��" << endl;
			//  ���õ�ַ�����޸�ʵ��
			addPerson(&abs);
			break;
		case 2:
			// ��ʾ��ϵ��
			cout << " ��ʾ��ϵ��" << endl;
			showabs(&abs);
			break;
		case 3:
			cout << " ɾ����ϵ��" << endl;
			deletePerson(&abs);
			break;
		case 4:
			// ������ϵ��
			cout << " ������ϵ��" << endl;
			searchPerson(&abs);
			break;
		case 5:
			// �޸���ϵ��
			cout << " �޸���ϵ��" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			// �����ϵ��
			cout << " �����ϵ��" << endl;
			clearAddressBooks(&abs);
			break;
		default:
			break;
		}
	} while (select);
	system("pause");
	return 0;
}