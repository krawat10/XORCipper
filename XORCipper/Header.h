#include <string>


void Save(std::string *data, std::string *path);

std::string* Open(std::string *path);

std::string* Decrypt(std::string *content, std::string *key);

std::string* Encrypt(std::string *content, std::string *key);

int get_length(char *array);