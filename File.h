#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ios;

template<typename T>
class File
{
public:
	string path;
	string name;

	File() = default;
	File(string path, string name)
	{
		this->name = name;
		this->path = path;
	}
	bool Save(T object)
	{
		fstream file(path+name, ios::out | ios::binary);
		if (file.is_open())
		{
			file.write((char*)&object, sizeof(object));
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	T Load()
	{
		T object;
		fstream file(path + name, ios::in | ios::binary);
		if (file.is_open())
		{
			file.read((char*)&object, sizeof(object));
			file.close();
			return object;
		}
		else
		{
			return object;
		}
	}
};