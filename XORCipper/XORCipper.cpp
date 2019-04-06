// XORCipper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		cout << i << ":" << argv[i] << endl;
	}

	if (argc <  4)
	{
		cout << "Enough not provided";
	}

	// C:\Users\mkrawczy\Documents\input.txt C:\Users\mkrawczy\Documents\output.txt someKey123 enc
	const char *inputPath = argv[1];
	const char *outputPath = argv[2];
	const char *key = argv[3];
	const char *type = argv[4];

	int file_size = GetFileLenght(inputPath);
	const char *input = Open(inputPath, file_size);
	
	if (is_equal(type, "dec"))
	{
		char *decrypted = Decrypt(input, key, file_size);
		Save(decrypted, file_size, outputPath);
		delete[] decrypted;
	}
	else if (is_equal(type, "enc"))
	{
		char *encrypted = Encrypt(input, key, file_size);
		Save(encrypted, file_size, outputPath);
		delete[] encrypted;
	}
	else
	{
		std::cout << "Incorrect type";
	}
	
	delete[] input;
	
	return 0;
}