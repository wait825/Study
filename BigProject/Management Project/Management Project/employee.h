#pragma once
#include "woker.h"

class Employee :public Worker
{
public:
	//构造函数
	Employee(int id,std::string name, int dId);
	//显示个人信息
	virtual void showInFo();
	//获得岗位名称
	virtual std::string getDeptName();
};