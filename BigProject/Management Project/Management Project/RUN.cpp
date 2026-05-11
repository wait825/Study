#include <iostream>
#include "Staff Management Project.h"
#include "woker.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
int main()
{
	//实例化
	StaffManagementProject SMP;
	int chioce;
	while (true)
	{
		//调用展示菜单函数
		SMP.Show_Menu();
		std::cout << "请输入你的选择 " << std::endl;
		std::cin >> chioce;
		switch (chioce)
		{
		case 0://退出系统
			SMP.ExitSystem();
			break;
		case 1://增加职工
			SMP.Add_Emp();
			break;
		case 2://显示职工
			SMP.show_Emp();
			break;
		case 3://删除职工
			SMP.Del_Emp();
			break;
		case 4://修改职工
			SMP.Mod_Emp();
			break;
		case 5://查找职工
			SMP.Find_Emp();
			break;
		case 6://对职工进行排序
			SMP.Sort_Emp();
			break;
		case 7://清空文档
			SMP.Clean_File();
			break;
		default:
			
			break;

		}
	}

	std::cin.get();
	return 0;
}