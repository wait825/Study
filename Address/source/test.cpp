#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
//菜单界面
void showMenu()
{
	cout << "************记Fiend的小本本************************" << endl;
	cout << "*******\t1.新的好盆友                        *******" << endl;
	cout << "*******\t2.看看你认识了多少人                *******" << endl;
	cout << "*******\t3.友谊的小船翻了                    *******" << endl;
	cout << "*******\t4.你要找谁，我来帮你                *******" << endl;
	cout << "*******\t5.好盆友改信息了吗？记得同步一下    *******" << endl;
	cout << "*******\t6.重启一下                          *******" << endl;
	cout << "*******\t0.不需要就拜拜了                    *******" << endl;
	cout << "***************************************************" << endl;
	system("color 04");
}
//添加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "好盆友已经多了" << endl;
		return;
	}
	else
	{
		string name;
		cout << "告诉我叫啥吧" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex = 0;
		cout << "是男的  还是  女的呢" << endl;
		cout << "1是男" << endl;
		cout << "2是女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "男的还是女的啊?不要乱写哦" << endl;
		}

		int age = 0;
		cout << "TA多大了啊" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "TA的扣扣号啊，wx号啊，电话号啊，告诉我一个就行了" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string addr;
		cout << "知道住哪里吗？不知道的话就填不知道就行" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		cout << "OK,已经保存完毕！" << endl;
		abs->m_Size++;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "还没有新朋友呢" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "TA叫：" << abs->personArray[i].m_Name << "\t";
			cout << "TA是：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "TA有：" << abs->personArray[i].m_Age <<" 岁"<<"\t";
			cout << "知道怎么和TA说话吗：" << abs->personArray[i].m_Phone << "\t";
			cout << "TA住：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
// 检测联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "那个小船翻了啊" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "成功告别了哦，不用在想这个事了" << endl;
	}
	else
	{
		cout << "没找到啊，是不是名字打错了啊" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "要找谁啊" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "TA叫：" << abs->personArray[ret].m_Name << '\t';
		cout << "TA是：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << '\t';
		cout << "TA有：" << abs->personArray[ret].m_Age <<"岁"<< '\t';
		cout << "知道怎么和TA说话吗：" << abs->personArray[ret].m_Phone << '\t';
		cout << "TA住：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "没找到啊" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "是谁改了TA的信息呢" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "TA改成什么名字了" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "还会变性啊！" << endl;
		cout << "1是男" << endl;
		cout << "2是女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "男的还是女的啊?不要乱输（气）" << endl;
		}

		int age = 0;
		cout << "多大了" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "TA改了啥，没有就麻烦你输入之前的吧" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string addr;
		cout << "搬家了吗？没有就麻烦你输入之前的吧" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "修改完成！" << endl;
	}
	else
	{
		cout << "没找到啊" << endl;
	}
	system("pause");
	system("cls");
}
//清空所有人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "啥都没有了哦" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_Size = 0;

	//选择功能
	int selet = 0;
	while (true)
	{
		//菜单调用
		showMenu();

		cout << "嘿!朋友，你想使用那个功能了？我都能帮你！(～￣▽￣)～" << endl;
		cout << "输入对应的数字就好了呦" << endl;
		cin >> selet;

		switch (selet)
		{
		case 1://Add 
			addPerson(&abs);//利用地址传递修改实参
			break;
		case 2://Show 
			showPerson(&abs);
			break;
		case 3://Delet
			deletePerson(&abs);
			break;
		case 4://Found
			findPerson(&abs);
			break;
		case 5://Change
			modifyPerson(&abs);
			break;
		case 6://Delet all
			cleanPerson(&abs);
			break;
		case 0://Exit
			cout << " 欢迎下次使用，再见！" << endl;
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