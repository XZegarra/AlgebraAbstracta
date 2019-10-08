#include "vernan.h"

vernan::vernan() {
}
vernan::vernan(string key1) {
	key = key1;
}
string vernan::keyGen() {
	srand(time(NULL));
	string resultado;
	for (int i = 0;i < message.length();i++) {
		int temp = modulo(rand(), alphabet.length());
		bitset <6> binTemp(temp);
		resultado = resultado + binTemp.to_string();
	}

	return resultado;
}
string vernan::encrypt(string message1) {
	string resultado;
	message = message1;
	key = keyGen();
	string binMessage;
	for (int i = 0; i < message.length();i++) {
		int temp = alphabet.find(message[i]);
		bitset<6> binTemp(temp);
		binMessage = binMessage + binTemp.to_string();
	}
	//cout << "clave:" << key << endl;
	//cout << "Mensaje en binario: " << binMessage << endl;
	for (int i = 0; i < binMessage.length();i++) {
		if (binMessage[i] == key[i]) {
			resultado.push_back('0');
		}
		else {
			resultado.push_back('1');
		}
	}
	//cout << "Binario encriptado: " << resultado << endl;
	return resultado;
}
string vernan::decrypt(string encryptedMessage) {

	string decrypted;
	string resultado;
	for (int i = 0;i < encryptedMessage.length();i++) {
		if (encryptedMessage[i] == key[i]) {
			decrypted.push_back('0');
		}
		else {
			decrypted.push_back('1');
		}
	}
	//cout << "Binario desincriptado: " << decrypted << endl;
	for (int i = 0; i < decrypted.length();i += 6) {
		string temporal;
		int j = i;
		for (int k = 0;k < 6;k++) {
			temporal.push_back(decrypted[j]);
			j++;
		}
		bitset<6> binTemp(temporal);
		int numeroPoner = binTemp.to_ullong();
		resultado = resultado + alphabet[numeroPoner];
	}
	//cout << "Mensaje desincriptado: " << resultado;
	return resultado;
}
string vernan::getMessage() {
	return message;
}
