#include "SequenceList.h"
#include<iostream>

using namespace std;
SequenceList::SequenceList()
{
	elements = new Datatype[maxlen];   //开辟空间
	if (!elements) {                    //当溢出时报异常
		exit(OVERFLOW);
	}
	list_length = 0;
}
void SequenceList::CreateSL(int n )//初始化一个长度为n的顺序表
{
	
	if (n > 0)
	{
		list_length = n;
		for (int i = 0; i < list_length; i++)
		{
			cout << "输入第" << i + 1 << "个节点数据" << endl;
			cin >> elements[i];
		}
	}
	else
	{
		cout << "顺序表长度必须为非负数！" << endl;
	}

}

SequenceList::~SequenceList()
{
	delete[] elements;
}

int SequenceList::GetLen()
{
	return list_length;
}

Datatype SequenceList::GetElement(int index)
{
	if ((index < 1) || (index > list_length))
	{
		cout << "索引号不正确！" << endl;
		return NULL;
	}
	else
		return elements[index - 1];
}

int SequenceList::LocElement(Datatype x)
{
	int j = 0;
	while ((j < list_length) && (elements[j] != x))
		j++;
	if (j < list_length)
		return j + 1;
	else
		cout << "数据不在顺序表中！" << endl;
		return 0;
}

int SequenceList::InsElement(Datatype x,int i)
{
	if (list_length > maxlen)
	{
		cout << "顺序表长度已超最大长度" << endl;
		return 1;
	}
	else if ((i<1)||(i>list_length+1))
	{
		cout << "插入位置不合法！" << endl;
		return 1;
	}
	else
	{
		for (int j = list_length; j >= i; j--)
		{
			elements[j] = elements[j-1];
		}
		elements[i - 1] = x;
		list_length++;
	}
	return 0;
}

int SequenceList::DelElement(int index)
{
	if ((index < 1) || (index > list_length))
	{
		cout << "删除位置不合法！" << endl;
		return 1;
	}
	else
	{
		for (int j = index; j <= list_length-1; j++)
		{
			elements[j-1] = elements[j];
		}
		list_length--;
	}
	return 0;
}

