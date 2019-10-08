
#include "codigoEnigma.h"


codigoEnigma::codigoEnigma() {
	key = keyGen();
	srand(time(NULL));
	string duplicateAlphabet = alphabet;
	//Generating the random alphabets
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet1 = randomAlphabet1 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}
	duplicateAlphabet = alphabet;
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet2 = randomAlphabet2 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}
	duplicateAlphabet = alphabet;
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet3 = randomAlphabet3 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}

	int r1 = alphabet.find(key[2]);
	int r2 = alphabet.find(key[1]);
	int r3 = alphabet.find(key[0]);


	for (int i = r1; i < alphabet.length(); i++) {
		R1.push_back(alphabet[i]);
	}
	for (int i = 0; i < r1; i++) {
		R1.push_back(alphabet[i]);
	}

	for (int i = r2; i < alphabet.length(); i++) {
		R2.push_back(alphabet[i]);
	}
	for (int i = 0; i < r2; i++) {
		R2.push_back(alphabet[i]);
	}

	for (int i = r3; i < alphabet.length(); i++) {
		R3.push_back(alphabet[i]);
	}
	for (int i = 0; i < r3; i++) {
		R3.push_back(alphabet[i]);
	}
}
codigoEnigma::codigoEnigma(string randomAlphabet11, string randomAlphabet22, string randomAlphabet33) {
	randomAlphabet1 = randomAlphabet11;
	randomAlphabet2 = randomAlphabet22;
	randomAlphabet3 = randomAlphabet33;
	key = keyGen();
}
codigoEnigma::codigoEnigma(string key1) {
	key = key1;
	srand(time(NULL));
	string duplicateAlphabet = alphabet;
	//Generating the random alphabets
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet1 = randomAlphabet1 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}
	duplicateAlphabet = alphabet;
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet2 = randomAlphabet2 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}
	duplicateAlphabet = alphabet;
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet3 = randomAlphabet3 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}

	int r1 = alphabet.find(key[2]);
	int r2 = alphabet.find(key[1]);
	int r3 = alphabet.find(key[0]);


	for (int i = r1; i < alphabet.length(); i++) {
		R1.push_back(alphabet[i]);
	}
	for (int i = 0; i < r1; i++) {
		R1.push_back(alphabet[i]);
	}

	for (int i = r2; i < alphabet.length(); i++) {
		R2.push_back(alphabet[i]);
	}
	for (int i = 0; i < r2; i++) {
		R2.push_back(alphabet[i]);
	}

	for (int i = r3; i < alphabet.length(); i++) {
		R3.push_back(alphabet[i]);
	}
	for (int i = 0; i < r3; i++) {
		R3.push_back(alphabet[i]);
	}
}

string codigoEnigma::keyGen() {
	srand(time(NULL));
	int key1 = modulo(rand(),alphabet.length());
	int key2 = modulo(rand(), alphabet.length());;
	int key3 = modulo(rand(), alphabet.length());;
	string keyTo = {alphabet[key1],alphabet[key2],alphabet[key3] };
	
	return keyTo;
}
string codigoEnigma::encrypt(string message1) {
	message = message1;
	string encryptedMessage;
	int counter = 0;
	for (int i = 0;i < message.length();i++) {
		if (i <= 4) {
			int index1 = R1.find(message[i]);
			int index2 = R2.find(randomAlphabet1[index1]);
			int index3 = R3.find(randomAlphabet2[index2]);
			encryptedMessage.push_back(randomAlphabet3[index3]);
		}
		if (i > 4 && i <= 8) {
			R3 = shiftR(R3);
			int index1 = R1.find(message[i]);
			int index2 = R2.find(randomAlphabet1[index1]);
			int index3 = R3.find(randomAlphabet2[index2]);
			encryptedMessage.push_back(randomAlphabet3[index3]);
		}
		if (i > 8 && i <= 12) {
			R2 = shiftR(R2);
			R3 = shiftR(R3);
			int index1 = R1.find(message[i]);
			int index2 = R2.find(randomAlphabet1[index1]);
			int index3 = R3.find(randomAlphabet2[index2]);
			encryptedMessage.push_back(randomAlphabet3[index3]);
		}
		if (i > 12) {
			R1 = shiftR(R1);
			R2 = shiftR(R2);
			R3 = shiftR(R3);
			int index1 = R1.find(message[i]);
			int index2 = R2.find(randomAlphabet1[index1]);
			int index3 = R3.find(randomAlphabet2[index2]);
			encryptedMessage.push_back(randomAlphabet3[index3]);
		}
	}
	normalizeR(R1, R2, R3);
	return encryptedMessage;
}
string codigoEnigma::decrypt(string encryptedMessage) {
	string decrypted;

	//randomAlphabet1 = "c 4dgzbef6l2js1t0rnu9xaw837okmq5iyvhp";
	//randomAlphabet2 = "4pqdb3 gzi2k6nou7rs9hwcavmy1lj05f8xet";
	//randomAlphabet3 = "qt0d mpb3fklis19yrnhea4cxj8o2675zvwgu";

	for (int i = 0;i < encryptedMessage.length();i++) {
		if (i <= 4) {
			int index1 = randomAlphabet3.find(encryptedMessage[i]);
			int index2 = randomAlphabet2.find(R3[index1]);
			int index3 = randomAlphabet1.find(R2[index2]);
			decrypted.push_back(R1[index3]);
		}
		if (i > 4 && i <= 8) {
			R3 = shiftR(R3);
			int index1 = randomAlphabet3.find(encryptedMessage[i]);
			int index2 = randomAlphabet2.find(R3[index1]);
			int index3 = randomAlphabet1.find(R2[index2]);
			decrypted.push_back(R1[index3]);
		}
		if (i > 8 && i <= 12) {
			R2 = shiftR(R2);
			R3 = shiftR(R3);
			int index1 = randomAlphabet3.find(encryptedMessage[i]);
			int index2 = randomAlphabet2.find(R3[index1]);
			int index3 = randomAlphabet1.find(R2[index2]);
			decrypted.push_back(R1[index3]);
		}
		if (i > 12) {
			R1 = shiftR(R1);
			R2 = shiftR(R2);
			R3 = shiftR(R3);
			int index1 = randomAlphabet3.find(encryptedMessage[i]);
			int index2 = randomAlphabet2.find(R3[index1]);
			int index3 = randomAlphabet1.find(R2[index2]);
			decrypted.push_back(R1[index3]);
		}
	}
	normalizeR(R1, R2, R3);
	return decrypted;
}
string codigoEnigma::getMessage() {
	return message;
}
string codigoEnigma::shiftR(string alpha) {
	string newR;
	int pos = alphabet.find(alpha[1]);
	for (int i = pos; i < alphabet.length(); i++) {
		newR.push_back(alphabet[i]);
	}
	for (int i = 0; i < pos; i++) {
		newR.push_back(alphabet[i]);
	}
	return newR;
}
void codigoEnigma::normalizeR(string& rot1, string& rot2, string& rot3) {
	rot1 = "";
	rot2 = "";
	rot3 = "";
	int r1 = alphabet.find(key[2]);
	int r2 = alphabet.find(key[1]);
	int r3 = alphabet.find(key[0]);


	for (int i = r1; i < alphabet.length(); i++) {
		rot1.push_back(alphabet[i]);
	}
	for (int i = 0; i < r1; i++) {
		rot1.push_back(alphabet[i]);
	}

	for (int i = r2; i < alphabet.length(); i++) {
		rot2.push_back(alphabet[i]);
	}
	for (int i = 0; i < r2; i++) {
		rot2.push_back(alphabet[i]);
	}

	for (int i = r3; i < alphabet.length(); i++) {
		rot3.push_back(alphabet[i]);
	}
	for (int i = 0; i < r3; i++) {
		rot3.push_back(alphabet[i]);
	}
}
string codigoEnigma::getTest() {
	return randomAlphabet1;
}
