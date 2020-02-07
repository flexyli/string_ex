#include "string_ex.h"
#include <iostream>
#include <string>
using namespace std;



//	�ж��ַ����Ƿ�Ϊ����
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


//�ж��ַ����������Ƿ�Ϊ������
bool isFloat(string s)
{
	//�ж��ַ����������Ƿ�Ϊ�����������Ǹ��������򷵻�true
	int dotcount = 0;  //С�����������ʼ��Ϊ0
	if (s.length() > 0)
	{
		//1���жϵ�1���ַ������Ϊ0~9��"-"��"."���Լ��������ж�
		char c = s[0];
		if ((c >= '0' && c <= '9') || c == '-' || c == '.')
		{
			if (c == '.')
			{
				//2�������1����"."����dotcount +1
				dotcount++;
			}
			if (s.length() > 1)
			{
				//3�����s�ĳ��ȴ���1��������ж�
				//4������������ַ���������"."ʱdotcount +1,������0~9������ַ����򷵻�false
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
			else if (c == '-')  //���s�ĳ���=1����ֻ��һ��"-"�ţ�����false
			{
				return false;
			}

		}
		//5�����dotcout == 1�����ж�sΪ������
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
	else  //���Ϊ�գ�����false
	{
		return false;
	}
}


//���ַ���ת��Ϊ��������
int str2int(string s)
{
	//�����ַ��������ַ����е�����ת��Ϊint����
	return strtol(s.c_str(), NULL, 0);
}


//���ַ���ת��Ϊdouble����
double str2double(string s)
{
	return strtod(s.c_str(), NULL);
}