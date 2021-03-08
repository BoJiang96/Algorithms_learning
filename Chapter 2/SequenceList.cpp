#include "SequenceList.h"
#include<iostream>

using namespace std;
SequenceList::SequenceList()
{
	elements = new Datatype[maxlen];   //���ٿռ�
	if (!elements) {                    //�����ʱ���쳣
		exit(OVERFLOW);
	}
	list_length = 0;
}
void SequenceList::CreateSL(int n )//��ʼ��һ������Ϊn��˳���
{
	
	if (n > 0)
	{
		list_length = n;
		for (int i = 0; i < list_length; i++)
		{
			cout << "�����" << i + 1 << "���ڵ�����" << endl;
			cin >> elements[i];
		}
	}
	else
	{
		cout << "˳����ȱ���Ϊ�Ǹ�����" << endl;
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
		cout << "�����Ų���ȷ��" << endl;
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
		cout << "���ݲ���˳����У�" << endl;
		return 0;
}

int SequenceList::InsElement(Datatype x,int i)
{
	if (list_length > maxlen)
	{
		cout << "˳������ѳ���󳤶�" << endl;
		return 1;
	}
	else if ((i<1)||(i>list_length+1))
	{
		cout << "����λ�ò��Ϸ���" << endl;
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
		cout << "ɾ��λ�ò��Ϸ���" << endl;
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

