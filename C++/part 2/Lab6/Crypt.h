#ifndef CRYPT_H
#define CRYPT_H

class ICrypt
{
public:
	virtual char* Encrypt(char* data, int size) = 0;
	virtual char* Decrypt(char* data, int size) = 0;
protected:
	short int* key;
};


class CaesarCrypt : public ICrypt
{
public:
	CaesarCrypt(short int key);
	char* Encrypt(char* data, int size) override;
	char* Decrypt(char* data, int size) override;
};

class CryptException{};

#endif
