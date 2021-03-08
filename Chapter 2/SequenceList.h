#pragma once
typedef int Datatype;
#include<iostream>
#define maxlen 100
class SequenceList
{
private:
	int list_length;
	Datatype * elements;
public:
	SequenceList();

	~SequenceList();
	void CreateSL(int n);
	int GetLen();
	Datatype GetElement(int index);
	int LocElement(Datatype x);
	int InsElement(Datatype x, int i);
	int DelElement(int index);
};

