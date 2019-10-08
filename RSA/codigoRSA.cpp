#include "codigoRSA.h"



codigoRSA::codigoRSA() {
	keyGen();
}
codigoRSA::codigoRSA(int key1, int key2) {
	p = key1;
	q = key2;
}
void codigoRSA::keyGen() {
	vector <long long int> lista = criba(21417);
	long long int tam = lista.size() - 100;
	srand(time(NULL));
	long long int generator1 = tam - modulo(rand(), tam + 100);
	long long int generator2 = tam - modulo(rand(), tam + 100);
	p = lista[generator1];
	q = lista[generator2];
	long long unsigned int n = p * q;
	long long unsigned int phiN = (p - 1) * (q - 1);
	long long unsigned int e;
	while (true) {
		e = rand() + 211231123123;
		if (euclides(e, phiN) == 1) {
			break;
		}
	}
	long long int eNegativo = euclidesExtendido(e, phiN);
	long long int d = modulo(eNegativo, phiN);
	cout << "Clave publica: " << d << " " << n << endl;
	cout << "Clave privada: " << e << " " << n << endl;
	dd = d;
	ee = e;
	nn = n;
}
vector <long long unsigned int> codigoRSA::encrypt(string message1) {
	message = message1;
	
	vector <long long unsigned int> encrypted;
	for (int i = 0;i<message.length();i++) {
		encrypted.push_back(exp(alphabet.find(message[i]), ee, alphabet.length()));
	}
	return encrypted;
}
string codigoRSA::decrypt(vector <long long unsigned int> encryptedMessage) {
	string decrypted;
	for (int i = 0;i < encryptedMessage.size();i++) {
		decrypted.push_back(alphabet[exp(encryptedMessage[i], dd, alphabet.length())]);
	}
	return decrypted;
}
string codigoRSA::getMessage() {
	return message;
}
