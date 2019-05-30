#include "Crypt.h"

CaesarCrypt::CaesarCrypt(short int key)
{
	if(key)
	{
		this->key = new short(key);
	}		
	else
	{
		throw CryptException();
	}		
}


char* CaesarCrypt::Encrypt(char* data, int size)
{
	char* result = new char[size];
	for(int i = 0; i < size; i++)
	{
		result[i] = data[i] + *key;
	}
	return result;
}

char* CaesarCrypt::Decrypt(char* data, int size)
{
	char* result = new char[size];
	for(int i = 0; i < size; i++)
	{
		result[i] = data[i] - *key;
	}
	return result;
}
