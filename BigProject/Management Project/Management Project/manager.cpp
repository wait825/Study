#include "manager.h"
//构造函数
Manager::Manager(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Manager::showInFo()
{
	std::cout
	<< "职工编号； " << this->m_Id
	<< "\t职工姓名； " << this->m_Name
	<< "\t职工岗位； " << this->getDeptName()
	<< "\t岗位职责；完成Boss交给的任务,并且下发任务" << std::endl;
 }
//获得岗位名称
std::string Manager::getDeptName()
{
	return std::string("经理");
 }
