
#include "vigenere.h"
vigenere::vigenere() {
}
vigenere::vigenere(string key1) {
	key = key1;
}
string vigenere::keyGen() {
	srand(time(NULL));
	vector <string> keyNumbers;
	for (int i = 0;i < message.length();i++) {
		int random =modulo( rand(),  alphabet.length());
		keyNumbers.push_back(to_string(random));
	}
	string key1;
	for (int i = 0;i < message.length();i++) {
		int temp = stoi(keyNumbers[i]);
		key1.push_back(alphabet[temp]);
	}
	return key1;
}
string vigenere::encrypt(string message1) {
	message = message1;
	string encryptedMessage;
	key = keyGen();
	for (int i = 0;i < message.length();i++) {
		int pos = alphabet.find(message[i]) + alphabet.find(key[i]);
		if (pos >= alphabet.length()) {
			encryptedMessage.push_back(alphabet[pos - (alphabet.length())]);
			continue;
		}
		encryptedMessage.push_back(alphabet[pos]);
	}
	return encryptedMessage;
}
string vigenere::decrypt(string encryptedMessage) {
	string trueMessage;
	for (int i = 0;i < encryptedMessage.length();i++) {
		int temp1 = alphabet.find(encryptedMessage[i]);
		int temp2 = alphabet.find(key[i]);
		if (temp1 - temp2 >= 0) {
			trueMessage.push_back(alphabet[temp1 - temp2]);
			continue;
		}
		trueMessage.push_back(alphabet[temp1 - temp2 + alphabet.length()]);
	}
	return trueMessage;
}
string vigenere::getMessage() {
	return message;
}