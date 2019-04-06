#include "pch.h"

int get_length(const char* array)
{
	int length = 0;

	while (true)
	{
		if (array[++length] == '\0') return length;
	}

	return -1;
}

bool is_equal(const char *s1, const char *s2) {
	int s1_length = get_length(s1);
	int s2_lenght = get_length(s2);

	if (s1_length != s2_lenght) return false;

	for (int i = 0; i < s1_length; i++)
	{
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

