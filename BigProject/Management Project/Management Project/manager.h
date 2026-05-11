#pragma once
#include "woker.h"

class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, std::string name, int dId);
	//显示个人信息
	virtual void showInFo();
	//获得岗位名称
	virtual std::string getDeptName();
};