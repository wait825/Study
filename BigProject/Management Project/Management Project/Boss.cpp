#include"Boss.h"
//构造函数
Boss::Boss(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Boss::showInFo()
{
	std::cout
	<< "职工编号； " << this->m_Id
	<< "\t职工姓名； " << this->m_Name
	<< "\t职工岗位； " << this->getDeptName()
	<< "\t岗位职责；给下属下达命令" << std::endl;
}
//获得岗位名称
std::string Boss::getDeptName()
{
	return std::string("BOSS");
}
