// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <string>

	void Save(const char *data, int dataLength, const char *path);

	const char* Open(const char *path, int dataLength);

	int GetFileLenght(const char *path);

	char* Decrypt(const char *content, const char *key, int file_size);

	char* Encrypt(const char *content, const char *key, int file_size);

	int get_length(const char *array);

	bool is_equal(const char *s1, const char *s2);

#endif //PCH_H
