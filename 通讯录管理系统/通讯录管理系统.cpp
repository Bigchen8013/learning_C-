#include<iostream>
#include<string>
#include<cstdlib>
#define MAX 1000   // 最大人数1000
using namespace std;

// 联系人结构体
struct person
{
	string name;   // 姓名
	int sex;    //性别,1男0女
	int age;
	string phone;
	string address;
};

// 通讯录结构体
struct address_book
{
	// 联系人数组
	struct person personArray[MAX];
	// 数组长度
	int len;
};

// 添加联系人
void addPerson(address_book * abs)
{
	// 先判断通讯录是否已满，若是满了则不能添加，否则可以添加
	if (abs->len >= 999)
	{
		cout << "通讯录已满，不能继续添加" << endl;
		return;
	}
	else
	{
		cout << " 请输入联系人姓名： " << endl;
		string name;
		cin >> name;
		abs->personArray[abs->len].name = name;
		cout << " 请输入联系人性别(1为男性，2为女性）： " << endl;
		int sex = 0;
		
		// 对输入的做判断，输入不正确不保存
		while (true)
		{
			// 如果输入的是1或者2，正确，否则一直输入，知道正确为止
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->len].sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		

		cout << " 请输入联系人年龄： " << endl;
		int age;
		while (true)
		{
			// 判断年龄，输入有误的话重新输入
			cin >> age;
			if (0 <= age <= 130)
			{
				abs->personArray[abs->len].age = age;
				break;
			}
			cout << "年龄输入有误，请重新输入！" << endl;
		}
		
		cout << " 请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->len].phone = phone;
		cout << " 请输入联系人住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->len].address = address;

		// 输入完成后，更新通讯录长度加1
		abs->len++;
		cout << "添加成功！" << endl;
	}
	system("pause");  // 请按任意键继续
	system("cls");   // 清屏操作
}

// 显示联系人
void showabs(address_book* abs)
{
	// 通讯录中没有人员，提示为空，人数大于0，显示通讯录中的信息
	if (abs->len == 0)
	{
		cout << "通讯录为空！！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->len; i++)
		{
			cout << "姓名：" << abs->personArray[i].name 
				<< "\t 性别：" << (abs->personArray[i].sex == 1 ? "男" : "女")
				<< "\t 年龄：" << abs->personArray[i].age << "\t 联系电话：" << abs->personArray[i].phone
				<< "\t 住址：" << abs->personArray[i].address << endl;
		}
	}
	system("pause");  // 请按任意键继续
	system("cls");   // 清屏操作
}

// 检测联系人是否存在，存在返回位置，不存在返回-1
int isExist(address_book *abs, string name)
{
	for (int i = 0; i < abs->len; i++)
	{
		// 找到用户的名字
		if (abs->personArray[i].name == name)
		{
			return i;
		}
	}
	// 遍历结束没有找到，返回-1
	return -1;
}
// 输出菜单按钮
void showMenu()
{
	// 信息显示
	cout << "****************************" << endl
		<< "******1. 添加联系人*********" << endl
		<< "******2. 显示联系人*********" << endl
		<< "******3. 删除联系人*********" << endl
		<< "******4. 查找联系人*********" << endl
		<< "******5. 修改联系人*********" << endl
		<< "******6. 清空联系人*********" << endl
		<< "******0. 退出通讯录*********" << endl
		<< "****************************" << endl;
}

// 删除联系人
void deletePerson(address_book *abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "查无此人，无需删除！" << endl;
	}
	else
	{
		// 找到的需要删除的人
		// 要删除的下标开始，后面的数据往前移动一个单位，通讯录的长度减1
		for (int i = res; i < abs->len; i++)
		{
			// 数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->len -= 1;   // 更新通讯录的长度
		cout << "删除成功！" << endl;
	}
	system("pause");  // 请按任意键继续
	system("cls");   // 清屏操作
}

// 查找联系人
void searchPerson(address_book *abs)
{
	cout << "请输出你要查找的联系人姓名" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		cout << " 查找成功，其信息为：" << endl;
		//存在联系人,输入其相关的信息
		cout << "姓名：" << abs->personArray[res].name
			<< "\t 性别：" << (abs->personArray[res].sex == 1 ? "男" : "女")
			<< "\t 年龄：" << abs->personArray[res].age << "\t 联系电话：" << abs->personArray[res].phone
			<< "\t 住址：" << abs->personArray[res].address << endl;
	}
	else
	{
		cout << "查找失败" << endl;
	}
	system("pause");
	system("cls");
}

// 修改联系人
void modifyPerson(address_book* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		// 修改指定的属性
		cout << "选择要修改的属性：" << endl;
		cout << "1--姓名" << endl
			<< "2--性别" << endl
			<< "3--年龄" << endl
			<< "4--电话" << endl
			<< "5--住址" << endl;
		int modify_choose;
		cin >> modify_choose;
		switch (modify_choose)
		{
		case 1:  // 修改姓名
		{
			string modify_name;
			cout << "请输入修改后的名字:" << endl;
			cin >> modify_name;
			abs->personArray[res].name = modify_name;
			break;
		}
		case 2:   // 修改性别
		{
			int modify_sex = 0;
			cout << "请输入修改后的性别（1为男性，2为女性）:" << endl;
			// 对输入的做判断，输入不正确不保存
			while (true)
			{
				// 如果输入的是1或者2，正确，否则一直输入，知道正确为止
				cin >> modify_sex;
				if (modify_sex == 1 || modify_sex == 2)
				{
					abs->personArray[res].sex = modify_sex;
					break;
				}
				cout << "输入有误，重新输入" << endl;
			}
			break;
		}
		case 3:   // 修改年龄
		{
			int modify_age;
			cout << "请输入修改后的年龄:" << endl;
			while (true)
			{
				// 判断年龄，输入有误的话重新输入
				cin >> modify_age;
				if (0 <= modify_age <= 130)
				{
					abs->personArray[res].age = modify_age;
					break;
				}
				cout << "年龄输入有误，请重新输入！" << endl;
			}
			break;
		}
		case 4:   // 修改联系电话
		{
			string modify_phone;
			cout << "请输入修改后的电话:" << endl;
			cin >> modify_phone;
			abs->personArray[res].phone = modify_phone;
			break;
		}
		case 5:   // 修改地址
		{
			string modify_address;
			cout << "请输入修改后的地址:" << endl;
			cin >> modify_address;
			abs->personArray[res].address = modify_address;
			break;
		}
		default:
			cout << "输入有误！" << endl;
			break;
		}

		/**  下面的代码是所有属性都修改的情况
		* 若是要更好还可以在选择修改的时候使用switch进行选择进行全属性修改还是特定属性修改
		// 修改姓名
		string modify_name;
		cout << "请输入修改后的名字:" << endl;
		cin >> modify_name;
		abs->personArray[res].name = modify_name;
		// 修改性别
		int modify_sex = 0;
		cout << "请输入修改后的性别（1为男性，2为女性）:" << endl;
		// 对输入的做判断，输入不正确不保存
		while (true)
		{
			// 如果输入的是1或者2，正确，否则一直输入，知道正确为止
			cin >> modify_sex;
			if (modify_sex == 1 || modify_sex == 2)
			{
				abs->personArray[res].sex = modify_sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		// 修改年龄
		int modify_age;
		cout << "请输入修改后的年龄:" << endl;
		while (true)
		{
			// 判断年龄，输入有误的话重新输入
			cin >> modify_age;
			if (0 <= modify_age <= 130)
			{
				abs->personArray[res].age = modify_age;
				break;
			}
			cout << "年龄输入有误，请重新输入！" << endl;
		}
		// 修改联系电话
		string modify_phone;
		cout << "请输入修改后的电话:" << endl;
		cin >> modify_phone;
		abs->personArray[res].phone = modify_phone;
		// 修改地址
		string modify_address;
		cout << "请输入修改后的地址:" << endl;
		cin >> modify_address;
		abs->personArray[res].address = modify_address;
		**/
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 清空联系人
// 只要将通讯录记录的联系人数重置为0，做逻辑清空即可
void clearAddressBooks(address_book* abs)
{
	cout << " 确定要清空联系人吗？1. 确定； 2. 不确定" << endl;
	int isClear = 0;
	cin >> isClear;
	if (isClear == 1)
	{
		abs->len = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录结构体变量
	struct address_book abs;
	abs.len = 0;   // 初始化长度
	int select;
	do
	{
		showMenu();
		cout << "用户输入选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			// 退出通讯录
			cout << " 退出通讯录" << endl;
			break;
		case 1:
			// 添加联系人
			cout << " 添加联系人" << endl;
			//  利用地址传递修改实参
			addPerson(&abs);
			break;
		case 2:
			// 显示联系人
			cout << " 显示联系人" << endl;
			showabs(&abs);
			break;
		case 3:
			cout << " 删除联系人" << endl;
			deletePerson(&abs);
			break;
		case 4:
			// 查找联系人
			cout << " 查找联系人" << endl;
			searchPerson(&abs);
			break;
		case 5:
			// 修改联系人
			cout << " 修改联系人" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			// 清空联系人
			cout << " 清空联系人" << endl;
			clearAddressBooks(&abs);
			break;
		default:
			break;
		}
	} while (select);
	system("pause");
	return 0;
}