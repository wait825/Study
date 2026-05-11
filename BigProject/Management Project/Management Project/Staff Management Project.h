#pragma once//防止头文件重复包含 
#include <iostream>//包含标准的 输出流头文件
#include <fstream>//包含头文件
#include"woker.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"
#define FILENAME "flie.txt"
class  StaffManagementProject
{
public:
	StaffManagementProject();

	//展示界面
	void Show_Menu();
	//退出
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工人员数组指针
	Worker** m_EmpArray;
	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计人数
	int get_Empnum();
	//添加职工
	void Add_Emp();
	//显示职工
	void show_Emp();
	//删除职工
	void  Del_Emp();
	//判断职工是否存在
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空文件
	void Clean_File();
	//初始化职工
	void init_Emp();
	~StaffManagementProject();

};

