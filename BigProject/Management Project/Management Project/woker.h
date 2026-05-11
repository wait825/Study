#pragma once
#include <iostream>
#include <string>

//职工抽象类
class Worker
{
public:
	//显示个人信息
	virtual void showInFo() = 0;
	//获得岗位名称
	virtual std::string getDeptName() = 0;
	//职工编号
	int m_Id;

	//职工姓名
	std:: string m_Name;

	//部门编号
	int m_DeptId;
};