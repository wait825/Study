#include "Staff Management Project.h"
//构造函数
StaffManagementProject::StaffManagementProject()
{
	//文件不存在
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//读文件
	
	if (!ifs.is_open())
	{
		std::cout << "文件不存在" << std::endl;
		//初始化属性
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArray = NULL;//初始化指针
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//代表文件为空
		std::cout << "文件为空" << std::endl;
		//初始化属性
		this->m_EmpNum = 0;//初始化人数
		this->m_EmpArray = NULL;//初始化指针
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录这数据
	int num = this->get_Empnum();
	//std::cout << "目前有" << num << "人" << std::endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//开辟空间
	this->init_Emp();//初始化职工,将文件中的职工信息加载到数组中
	//测试
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	std::cout << "编号"<< this->m_EmpArray[i]->m_Id<<std::endl;
	//	std::cout << "姓名" << this->m_EmpArray[i]->m_Name << std::endl;
	//	std::cout << "岗位" << this->m_EmpArray[i]->getDeptName() << std::endl;
	//}
}
//展示菜单
void StaffManagementProject::Show_Menu()
{
	std::cout << "*********************************" << std::endl;
	std::cout << "******   欢迎来到管理系统   *****" << std::endl;
	std::cout << "******       0.退出         *****" << std::endl;
	std::cout << "******    1.欢迎新人加入    *****" << std::endl;
	std::cout << "******     2.显示所有人     *****" << std::endl;
	std::cout << "******     3.有人离开了     *****" << std::endl;
	std::cout << "******      4.信息不对      *****" << std::endl;
	std::cout << "******      5.查找员工      *****" << std::endl;
	std::cout << "******    6.排序所有员工    *****" << std::endl;
	std::cout << "******     7.公司破产了     *****" << std::endl;
	std::cout << "*********************************" << std::endl;
	system("color 4");
}
//退出系统
void StaffManagementProject::ExitSystem()//退出
{
	std::cout << "感谢你使用,欢迎下在来" << std::endl;
	system("pause");
	exit(0);
}
//添加职工
void StaffManagementProject::Add_Emp()
{
	int addNum = 0;//保存用户输入数量
	std::cout << "请输入想要增加的职工数量" << std::endl;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//增加
		//计算增加新空间的大小
		int newSize = this->m_EmpNum + addNum;//新空间 = 原来记录人数 + 新增人数 
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来的空间下的数据，拷贝到新空间下
		if (this->m_EmpNum != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int dSelect;

			std::cout << "请输入第" << i + 1 << "个员工的编号" << std::endl;
			std::cin >> id;

			std::cout << "请输入第" << i + 1 << "个员工的姓名" << std::endl;
			std::cin >> name;

			std::cout << "请选择职工的岗位" << std::endl;
			std::cout << "1.普通员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.BOSS" << std::endl;
			std::cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1 :
				worker = new Employee(id, name, 1);
				break;
			case 2 :
				worker = new Manager(id, name, 2);
				break;
			case 3 :
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工职责，保存到 数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有的空间
		delete[]this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新空间的人数
		this->m_EmpNum = newSize;
		//更新职工不未空的标志 
		this->m_FileIsEmpty = false;
		//提示增加成功
		std::cout << "成功添加" << addNum << "位职工" << std::endl;
		//保存数据到文件
		this->save();
	}
	else
	{
		std::cout << "输入不合理" << std::endl;
	}
	system("pause");
	system("cls");

}
//统计人数
int StaffManagementProject::get_Empnum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}
//显示职工
void StaffManagementProject::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在或记录为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口显示职工信息
			this->m_EmpArray[i]->showInFo();
		}
	}
	system("pause");
	system("cls");
}
//保存文件
void StaffManagementProject::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);//用输出的方式打开文件
	//将每一个人的数据写进文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << std::endl;
	}
	//关闭文件
	ofs.close();
}
//初始化职工
void StaffManagementProject::init_Emp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//删除职工
void StaffManagementProject::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在" << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		//按照职工编号删除
		std::cout << "请输入想要删除的职工编号" << std::endl;
		int id = 0;
		std::cin >> id;

		int index  = this->IsExist(id);

		if (index != -1)//找到了
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//删除职工，在数组中，删除数据本质是数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中职工人数
			this->m_EmpNum--;
			//同步到文件里面 
			this->save();
			std::cout << "删除成功" << std::endl;
		}
		else
		{
			std::cout << "没有找到该职工" << std::endl;
		}
		system("pause");
		system("cls");
	}
}
//判断职工是否存在
int StaffManagementProject::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//找到了职工，返回职工所在数组中的位置索引
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			
			break;
		}
	}
	return index;
}
//修改职工
void StaffManagementProject::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在" << std::endl;
	}
	else 
	{
		std::cout << "请输入想要修改的职工编号" << std::endl;
		int id = 0;
		std::cin >> id;

		//查找职工编号
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			std::string newName = "";
			int dSelect = 0;

			std::cout << "查找到；" << id << "号职工，请输入新职工编号" << std::endl;
			std::cin >> newId;

			std::cout << "请输入新职工姓名" << std::endl;
			std::cin >> newName;

			std::cout << "请选择新职工的岗位" << std::endl;
			std::cout << "1.普通员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.BOSS" << std::endl;
			std::cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
				case 1:
				worker = new Employee(newId, newName, 1);
				break;
				case 2:
				worker = new Manager(newId, newName, 2);
				break;
				case 3:
				worker = new Boss(newId, newName, 3);
				break;
				default:
				break;
			}
			//更新数组中的职工信息
			this->m_EmpArray[ret] = worker;

			std::cout << "修改成功" << std::endl;
			//保存到文件中
			this->save();
		}
		else
		{
			std::cout << "没有找到该职工,修改失败" << std::endl;
		}
	}

	system("pause");
	system("cls");
}
//查找员工
void StaffManagementProject::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在" << std::endl;
	}
	else
	{ 
		std::cout << "请输入你的查找方式" << std::endl;
		std::cout << "1.按照职工编号查找" << std::endl;
		std::cout << "2.按照姓名查找" << std::endl;

		int select = 0;
		std::cin >> select;
		if (select == 1)
		{
			//按照职工编号查找
			int id = 0;
			std::cout << "请输入想要查找的职工编号" << std::endl;
			std::cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//找到了职工
				std::cout << "找到了编号为" << id << "的职工，信息如下：" << std::endl;
				this->m_EmpArray[ret]->showInFo();
			}
			else
			{
				std::cout << "没有找到编号为" << id << "的职工" << std::endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查找
			std::string name;
			std::cout << "请输入想要查找的职工姓名" << std::endl;
			std::cin >> name;

			//加入一个标志，表示是否找到
			bool flag = false;//默认没有找到

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					std::cout << "找到了姓名为" << name 
							  << "的职工，信息如下：" << std::endl;
					//找到了职工
					flag = true;
					//调用接口显示职工信息
					this->m_EmpArray[i]->showInFo();
				}
			}
			if (!flag)
			{
				std::cout << "没有找到姓名为" << name << "的职工" << std::endl;
			}
		}
		else
		{
			std::cout << "输入选项有误" << std::endl;
		}
		
	}
	system("pause");
	system("cls");
}
//排序职工
void StaffManagementProject::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在" << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "请选择你想要的排序方式" << std::endl;
		std::cout << "1.按照职工编号进行升序" << std::endl;
		std::cout << "2.按照职工编号进行降序" << std::endl;

		int select = 0;
		std::cin >> select;
		
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//假设第一个数是最小的
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;//更新最小数的索引
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;//更新最大数的索引
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		std::cout << "排序成功，排序后的结果为：" << std::endl;
		this->save();//排序完成后保存到文件中
		this->show_Emp();
	}
}
//清空文件
void StaffManagementProject::Clean_File()
{
	std::cout << "你确定要清空文件吗？" << std::endl;
	std::cout << "1.确定" << std::endl;
	std::cout << "2.取消" << std::endl;

	int select = 0;
	std::cin >> select;
	if(select == 1)
	{
		//打开模式 ios::trunc 如果文件存在会将文件清空，如果文件不存在会创建文件
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		std::cout << "文件清空成功" << std::endl;
	}
	else
	{
		std::cout << "停止清空文件" << std::endl;
	}
	system("pause");
	system("cls");
}
//析构函数
StaffManagementProject::~StaffManagementProject()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
