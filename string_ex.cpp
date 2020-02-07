#include "string_ex.h"
#include <iostream>
#include <string>
using namespace std;



//	判断字符串是否为整数
bool isInt(string &s)
{
	if (s.length() > 0)
	{
		char c = s[0];
		if ((c >= '0' && c <= '9') || c == '-')
		{
			if (s.length() > 1)
			{
				for (int i = 1; i < s.length(); i++)
				{
					c = s[i];
					if (!(c >= '0' && c <= '9'))
					{
						return false;
					}
				}
			}
			else if (c == '-')
			{
				return false;
			}

		}
		return true;
	}
	else
	{
		return false;
	}
}


//判断字符串的数据是否为浮点数
bool isFloat(string s)
{
	//判断字符串的数据是否为浮点数，如是浮点数，则返回true
	int dotcount = 0;  //小数点计数，初始化为0
	if (s.length() > 0)
	{
		//1、判断第1个字符，如果为0~9、"-"、"."可以继续往下判断
		char c = s[0];
		if ((c >= '0' && c <= '9') || c == '-' || c == '.')
		{
			if (c == '.')
			{
				//2、如果第1个是"."，则dotcount +1
				dotcount++;
			}
			if (s.length() > 1)
			{
				//3、如果s的长度大于1，则继续判断
				//4、遍历后面的字符，当出现"."时dotcount +1,当出现0~9以外的字符，则返回false
				for (int i = 1; i < s.length(); i++)
				{
					c = s[i];
					if (c == '.')
					{
						dotcount++;
					}
					else if (c < '0' || c > '9')
					{
						return false;
					}
				}
			}
			else if (c == '-')  //如果s的长度=1，且只有一个"-"号，返回false
			{
				return false;
			}

		}
		//5、如果dotcout == 1，可判断s为浮点数
		cout << "dotcount:  " << dotcount << endl;
		if (dotcount == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else  //如果为空，返回false
	{
		return false;
	}
}


//将字符串转换为整数类型
int str2int(string s)
{
	//输入字符串，将字符串中的数字转换为int类型
	return strtol(s.c_str(), NULL, 0);
}


//将字符串转换为double类型
double str2double(string s)
{
	return strtod(s.c_str(), NULL);
}