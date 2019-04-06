#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <math.h>
#include "Header.h"

bool is_equal(std::string *s1, std::string *s2) {
	if (s1->length != s2->length) return false;

	for (size_t i = 0; i < s1->length; i++)
	{
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Args not provided";
	}

	std::string *path = new std::string(argv[1], get_length(argv[1]));
	std::string *key = new std::string(argv[2], get_length(argv[2]));
	std::string *type = new std::string(argv[3], get_length(argv[3]));
	
	std::string *input = Open(path);
	
	if (is_equal(type, new std::string("dec")))
	{
		std::string *decrypted = Decrypt(input, key);
		Save(decrypted, path);
	}
	else if (is_equal(type, new std::string("enc")))
	{
		std::string *encrypted = Encrypt(input, key);
		Save(encrypted, path);
	}
	else
	{
		std::cout << "Incorrect type";
	}

	return 0;
}