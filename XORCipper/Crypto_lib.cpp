#include "pch.h"
#include <string>


unsigned char rol(unsigned char n, unsigned int d)
{
	d = d % 8;
	return (n << d) | (n >> (8 - d)); ;
}

unsigned char ror(unsigned char n, unsigned int d)
{
	d = d % 8;
	return (n >> d) | (n << (8 - d));
}

char* Encrypt(const char *content, const char *key, int file_size)
{
	char *encrypted = new char[file_size];
	int key_size = get_length(key);

	int rotation = (file_size % key_size);

	for (int i = 0; i < file_size; i++)
	{
		unsigned char symbol = content[i];
		unsigned char keySymbol = key[i % key_size];

		symbol ^= keySymbol;
		symbol = ror(symbol, rotation);
		encrypted[i] = symbol;
	}

	return encrypted;
}

char* Decrypt(const char *content, const char *key, int file_size)
{
	char *decrypted = new char[file_size];
	int key_size = get_length(key);
	int rotation = (file_size % key_size);

	for (int i = 0; i < file_size; i++)
	{
		unsigned char symbol = content[i];
		unsigned char keySymbol = key[i % key_size];
		symbol = rol(symbol, rotation);

		decrypted[i] = symbol ^ keySymbol;
	}

	return decrypted;
}