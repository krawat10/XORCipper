#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Save(const char *data, int dataLength, const char *path) {
	ofstream file = ofstream(path, ios::binary);

	if (file.is_open())
	{
		for (size_t i = 0; i < dataLength; i++)
		{
			file.put(data[i]);
		}
	}

	file.close();
}

int GetFileLenght(const char *path)
{
	std::ifstream fs(path, ios::binary);
	fs.seekg(0, fs.end);
	int lenght = fs.tellg();
	fs.close();

	return lenght;
}

const char* Open(const char *path, int dataLength) {
	std::ifstream fs(path, ios::binary);

	fs.seekg(0, fs.end);
	char *data = new char[dataLength];

	fs.seekg(0, fs.beg);

	fs.read(data, dataLength);
	fs.close();


	return data;
}