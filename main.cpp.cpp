
#include <iostream>
#include "string_ex.h"


void test01()
{
	//测试程程序 isFloat() 和 str2Double()
	string a = "15";

	if (isFloat(a))
	{
		cout << "字符a是一个浮点数：" << a << endl;
	}
	else
	{
		cout << "字符a不是一个浮点数：" << a << endl;
	}
	double ret = str2double(a);
	cout << ret << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
