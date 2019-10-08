#include "codigoAfin.h"



codigoAfin::codigoAfin() {
	keyGen();
}
codigoAfin::codigoAfin(int key1, int key2) {
	keyA = key1;
	keyB = key2;
}
void codigoAfin::keyGen() {
	keyA = modulo(rand(), alphabet.length());
	keyB = modulo(rand(), alphabet.length());
}
string codigoAfin::encrypt(string message1) {
	message = message1;
	string encrypted;
	for (int i = 0;i < message.length(); i++) {
		int temp = alphabet.find(message[i]);
		int posCar = modulo((temp * keyA) + keyB, alphabet.length());
		encrypted.push_back(alphabet[posCar]);
	}
	return encrypted;
}
string codigoAfin::decrypt(string encryptedMessage) {
	string decrypted;
	int aNegativo = euclidesExtendido(keyA, alphabet.length());
	for (int i = 0;i < encryptedMessage.length();i++) {
		int temp = alphabet.find(encryptedMessage[i]);
		int posCar = modulo((temp - keyB) * aNegativo, alphabet.length());
		decrypted.push_back(alphabet[posCar]);
	}
	return decrypted;
}
string codigoAfin::getMessage() {
	return message;
}
int codigoAfin::getKey1() {
	return keyA;
}
int codigoAfin::getKey2() {
	return keyB;
}