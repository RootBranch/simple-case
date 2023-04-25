#pragma once
#include <iostream>

template<class T>
class MyArry
{
public:

	MyArry(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];
	}

	MyArry(const MyArry& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	MyArry& operator=(const MyArry& arr)
	{
		if (this->pAddress != NULL)
		{
			for (int i = 0; i < this->m_Size; i++)
			{
				delete this->pAddress[i];
			}
			delete[]pAddress;
		}
		pAddress = NULL;

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		for (int i = 0; i < this->m_Capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}


	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
			return;
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	void Pop_Back()
	{
		if (this->m_Capacity == 0)
			return;
		this->m_Size--;
	}

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	int getSize()
	{
		return this->m_Size;
	}

	int getCapacity()
	{
		return this->m_Capacity;
	}
	~MyArry()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	int m_Capacity;
	int m_Size;
	T* pAddress;

};