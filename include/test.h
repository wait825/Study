//main是每个代码有切仅由一个的
//#define是常量，在头文件的位置，且常量无法改变·无法改变
//const 数据类型 变量名  = 变量值  const修饰变量变为常量
// 
// 标识符命名规则
// 不能是关键字
//只能是字母 数字 下划线
//第一个字符不能是数字
//区分大小写

//短整型   short                       超上线变下线
//整型     int
//长整型   long
//长长整型 longlong

//sizeof表示数据类型所占内存大小
// cout << "(相关数据类型）" << sizeof(相关数据类型） << endl;

//单精度 float   4字节  7有效数字
//双精度 double  8字节  15~16有效数字
//float f1 = 3,14f;
//double f1 = 3,14;

//字符型变量创建     所占字符唯1
//char (ch) = 'a';
//不能用双引号，字符只能有一个
//字符型变量对应的ASCII编码
//cout << (int) (ch) << endl;
//a = 97  A = 65

//C风格字符串   char 变量名[] = "字符串"
//C++ 风格字符串  在开头要头文件
//#include <string> 否则无法使用
//
// bool flag = ture ;
// cout << flag << endl;
// 会输出1
// flag = false;
// cout  << flag << endl;
// 会输出0 
//
// ++a  前置递增 先加一 在运算
// a++ 后置递增 先运算 后加一
// int a = 10;                               
// int b = ++a * 10 ;
// cout << " a = " << endl;
// cout << " b = " << endl;  
// 运行得 a = 11 b = 101
// 
// int a = 10
// int b = a++ * 10 ;
// cout << " a = " << endl;
// cout << " b = " << endl; 
// 运行得 a = 11 b = 100
//
// 三目运算符
//int a = 10; 
//int b = 20;
//int c = 0;
//c = (a > b ? a : b);
// 
// cout << "c = " << endl;
//会输出 c = 20
// 在c++中三目运算符返回的还是变量可以继续赋值
// 
//在if语句条件中括号后面不能加分号(;)否则会把if后面的结果全部输出
//if (xxxxxxx);(错误示范)

//if else                         switch case default
//                              优点 结构清晰 执行效率高
//                              缺点 只能是整型或字符型 不能是一个区间（比如1~10）


//rand()%范围  生成随机数
//val = 数字   玩家输入的数

//
//数据类型 数组名[数组长度]
//int arr[5];
//arr[0] = 10;
//arr[1] = 20;
//arr[2] = 30;
//arr[3] = 40;
//arr[4] = 50;
//
//cout << arr[0] << endl;

//数据类型 数组名[数组长度] = {值1. 值2， ，，，}
//int arr2[5] = { 10.20.30.40.50 };
//cout << arr[0] << endl;

//数据类型 数组名[] = {值1. 值2， ，，，}
//int arr2[] = { 10.20.30.40.50 };
//cout << arr[0] << endl;  
//                         元素逆秩
// 
// 
//int arr[5] = { 1,3,2,5,4 };
//
//for (int i = 0; i < 5; i++)
//{
//	std::cout << arr[i] << endl;
//}
//
//int start = 0;
//int end = sizeof(arr) / sizeof(arr[0]) - 1;
//
//while (start < end)
//{
//	int temp = arr[start];
//	arr[start] = arr[end];
//	arr[end] = temp;
//
//	start++;
//	end--;
//}
//for (int i = 0; i < 5; i++)
//{
//	std::cout << arr[i] << endl;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//
////无参无返
//void AAIT()
//{
//	cout << "Hallo Aait!" << endl;
//}
////有参无返
//void BAIT(int B)
//{
//	cout << "Hallo Bait!B = " << B << endl;
//}
////无参有返
//int CAIT()
//{
//	cout << "Hallo Cait!" << endl;
//	return 825;
//}
////有参有返
//int DAIT(int D)
//{
//	cout << "Hallo Dait!" << endl;
//	return D;
//}
//
//int main() {
//
//	//无参无返函数调用
//	AAIT();
//	//有参无返函数调用
//	BAIT(825);
//	//有参无返函数调用
//	int WAIT = CAIT();
//	cout << "WAIT= " << WAIT << endl;
//	//有参有返函数调用
//	int Wait = DAIT(825);
//	cout << "DAIT= " << Wait << endl;
//
//	system("pause");
//
//	return 0;
//}
// 
//            指针配合数组和函数案例
// 
// 
// 
//#include <iostream>
//#include <string>
//using namespace std;
//void BubbleSort(int* arr, int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void printArray(int* arr, int len)
//{
//	for (int a = 0; a < len; a++)
//	{
//		cout << arr[a] << endl;
//	}
//}
//
//int main() {
//	//数组
//	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
//	//数组长度
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//创建函数，实现冒泡循环排列
//	BubbleSort(arr, len);
//	//打印数组
//	printArray(arr, len);
//
//	system("pause");
//
//	return 0;
//}
//
//
//    结构体的定义和使用
//            记得用 . 来访问数据(英文键盘下)
//            记得用 . 来访问数据(英文键盘下)
//            记得用 . 来访问数据(英文键盘下)
//#include <iostream>
//#include <string>
//using namespace std;
//1 创建数据类型有一些集合组成
//struct Student
//{
//	string name;
//
//	int age;
//
//	int score;
//
//	int weight;
//
//	int hight;
//}ZYF26256;
//2 创建数据具体数据
//
//int main() {
//
//	//1 sturct Student s1
//	//    sturct 可以省略在main函数里可以省略
//	Student FJ;
//	FJ.name = "FJ";
//	FJ.age = 17;
//	FJ.score = 777;
//	FJ.weight = 77;
//	FJ.hight = 177;
//
//	cout << "姓名：" << FJ.name << endl;
//	cout << "年龄：" << FJ.age << endl;
//	cout << "分数：" << FJ.score << endl;
//	cout << "体重：" << FJ.weight << endl;
//	cout << "身高：" << FJ.hight << endl;
//	cout << endl;
//	//2 struct Student s2 = {,,,}
//	struct Student FJ1 = { "ZYF", 17,777,77,177 };
//	cout << "姓名：" << FJ1.name << endl;
//	cout << "年龄：" << FJ1.age << endl;
//	cout << "分数：" << FJ1.score << endl;
//	cout << "体重：" << FJ1.weight << endl;
//	cout << "身高：" << FJ1.hight << endl;
//	cout << endl;
//	//3 在定义结构体时顺便定义结构体变量
//	ZYF26256.name = "26256";
//	ZYF26256.age = 17;
//	ZYF26256.score = 777;
//	ZYF26256.weight = 77;
//	ZYF26256.hight = 177;
//
//	cout << "姓名：" << ZYF26256.name << endl;
//	cout << "年龄：" << ZYF26256.age << endl;
//	cout << "分数：" << ZYF26256.score << endl;
//	cout << "体重：" << ZYF26256.weight << endl;
//	cout << "身高：" << ZYF26256.hight << endl;
//
//	system("pause");
//
//	return 0;
//}
//
//
//					结构体数组
// 
//#include <iostream>
//#include <string>
//using namespace std;
////定义结构体
//struct students
//{
//	string name;
//	int age;
//	int score;
//};
//int main() {
//	//
//	struct students stuArry[3]
//	{
//		{ "FJ" , 17 , 177},
//		{ "ZYF" , 18 , 277 },
//		{ "26256" , 19, 377 }
//	};
//	//给结构体赋值
//	stuArry[2].name = "祝于菲";
//	stuArry[2].age = 17;
//	stuArry[2].score = 777;
//	//遍历结构体数组
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "姓名：" << stuArry[i].name << endl;
//		cout << "年龄：" << stuArry[i].age << endl;
//		cout << "分数：" << stuArry[i].score << endl;
//		cout << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}
//结构体指针    指针访问结构体变量用   p->
//#include <iostream>
//#include <string>
//using namespace std;
////定义学生结构体
//struct students
//{
//	string name;
//	int age;
//	int score;
//};
//int main() {
//	//创建学生结构体变量
//	struct students FJ = { "FJ" , 17 ,177 };
//
//	//通过指针指向结构体变量
//	struct students* p = &FJ;
//
//	//通过指针指向结构体变量的数据
//
//	//FJ.name;
//	//cout << FJ.name << endl;
//	//可直接用数据名加 .  提取数据
//	cout << "姓名：" << p->name << endl;
//	cout << "年龄：" << p->age << endl;
//	cout << "分数：" << p->score << endl;
//
//	system("pause");
//
//	return 0;
//}
//      结构体嵌套
//#include <iostream>
//#include <string>
//using namespace std;
////定义学生结构体
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
////定义老师结构体
//struct teacher
//{
//	int id;
//	string name;
//	int age;
//	struct student stu;
//};
//int main() {
//	//创建结构体嵌套
//	teacher T;
//	T.id = 10000;
//	T.name = "等待";
//	T.age = 20;
//	T.stu.name = "zyf";
//	T.stu.age = 17;
//	T.stu.score = 777;
//
//	cout << "老师的姓名:" << T.name << endl;
//	cout << "职工编号:" << T.id << endl;
//	cout << "老师的年龄:" << T.age << endl;
//	cout << "老师的所带的学生:" << T.stu.name << endl;
//	cout << "学生年龄:" << T.stu.age << endl;
//	cout << "学生分数:" << T.stu.score << endl;
//	cout << endl;
//
//	system("pause");
//
//	return 0;
//}
//
//    结构体做函数的参数
//
//#include <iostream>
//#include <string>
//using namespace std;
////定义学生结构体
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
////定义老师结构体
//struct teacher
//{
//	int id;
//	string name;
//	int age;
//	struct student stu;
//};
////值传递
//void printstudent(struct student FJ)
//{
//	FJ.age = 100;
//	cout << "子函数中打印结果" << endl;
//	cout << "学生姓名：" << FJ.name << " 学生年龄：" << FJ.age << " 学生分数：" << FJ.score << endl;
//}
////地址传递
//void printstudent1(struct student* p)
//{
//	p->age = 100;
//	cout << "子函数2中打印的结果" << endl;
//	cout << "学生姓名：" << p->name << " 学生年龄：" << p->age << " 学生分数：" << p->score << endl;
//}
//int main() {
//
//	student FJ;
//	FJ.name = "ZYF";
//	FJ.age = 17;
//	FJ.score = 777;
//
//	cout << "main函数打印的结果" << endl;
//	cout << "学生姓名：" << FJ.name << " 学生年龄：" << FJ.age << " 学生分数：" << FJ.score << endl;
//
//	//printstudent(FJ);
//	printstudent1(&FJ);
//	cout << "main函数打印的结果" << endl;
//	cout << "学生姓名：" << FJ.name << " 学生年龄：" << FJ.age << " 学生分数：" << FJ.score << endl;
//
//	system("pause");
//
//	return 0;
//}
//
//// const 函数使用
//#include <iostream>
//#include <string>
//using namespace std;
////cost使用场景
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
////将函数中的形参改为指针，可以减少内存占用，并且不会像值传递一样复制新的副本
//void printstudents(const student* FJ)
//{
//	//FJ->name = "祝雨菲";（写） 
//	cout << "名字：" << FJ->name << endl;
//	cout << "年龄：" << FJ->age << endl;
//	cout << "分数：" << FJ->score << endl;
//}
////constant 只能读，不能写
//int main() {
//	//创建结构体变量
//	student FJ = { "FJ", 17,77 };
//	//通过函数打印结构体变量信息
//	printstudents(&FJ);
//	cout << "main 函数中" << FJ.name << endl;
//	system("pause");
//
//	return 0;
//}
////     结构体案例
//#include <iostream>
//#include <string>
//#include <ctime>
//using namespace std;
////学生结构体定义
//struct student
//{
//	string name;
//
//	int score;
//};
////老师结构体定义
//struct teacher
//{
//	string tname;
//
//	struct student sArray[5];
//};
////给老师和学生赋值的函数
//void allocateSpace(struct teacher tArray[], int len)
//{
//	string nameSeed = "ABCDE";
//	//开始给老师赋值
//	for (int i = 0; i < len; i++)
//	{
//		tArray[i].tname = "Wait_";
//		tArray[i].tname += nameSeed[i];
//		//通过循环给每名老师所带的学生赋值
//		for (int j = 0; j < 5; j++)
//		{
//			tArray[i].sArray[j].name = "FJ_";
//			tArray[i].sArray[j].name += nameSeed[j];
//			int random = rand() % 61 + 40;
//			tArray[i].sArray[j].score = random;
//		}
//	}
//
//}
////打印所有信息的函数
//void printInfo(struct teacher tArray[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << " Teacher name :" << tArray[i].tname << endl;
//
//		for (int j = 0; j < 5; j++)
//		{
//			cout << "\tStudent name :" << tArray[i].sArray[j].name << " Score :" << tArray[i].sArray[j].score << endl;
//		}
//	}
//}
//
//int main() {
//
//	//随机数种子
//	srand((unsigned int)time(NULL));
//	//1，创建3名老师的数组
//	struct teacher tArray[3];
//	int len = sizeof(tArray) / sizeof(tArray[0]);
//
//	//2，通过函数给3名老师的信息赋值，并且给老师所带的学生赋值
//	allocateSpace(tArray, len);
//
//	//3，打印所有老师和所带学生的信息
//	printInfo(tArray, len);
//
//	system("pause");
//
//	return 0;
//}            
//           结构体训练二
//#include <iostream>
//#include <string>
//#include <ctime>
//using namespace std;
////创建结构体
//struct Hero
//{
//	string name;
//	int age;
//	string sex;
//};
////实现冒泡循环
//void bubbleSort(struct Hero hArray[], int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			if (hArray[j].age > hArray[j + 1].age)
//			{
//				struct Hero temp = hArray[j];
//				hArray[j] = hArray[j + 1];
//				hArray[j + 1] = temp;
//			}
//		}
//	}
//}
////打印数组
//void printHero(struct Hero hArray[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << "Hero Name:" << hArray[i].name << "Hero Age:" << hArray[i].age << "Hero Sex:" << hArray[i].sex << endl;
//	}
//}
//int main() {
//	//1 创建数组
//	struct Hero hArray[5] =
//	{
//		{"刘备",23,"男" },
//		{"关羽",22,"男" },
//		{"张飞",20,"男" },
//		{"赵云",21,"男" },
//		{"貂蝉",19,"女" },
//	};
//	int len = sizeof(hArray) / sizeof(hArray[0]);
//	//2 实现冒泡循环
//	bubbleSort(hArray, len);
//
//	//3 打印
//	printHero(hArray, len);
//
//	cout << "\tHallo FJ" << endl;
//
//	system("pause");
//
//	return 0;
//}
