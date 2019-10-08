#include "protocolo.h"

ofstream outfile("textoCodigo.txt");



protocolo::protocolo() {
	keyGen();
}
protocolo::protocolo(int key1, int key2) {
	
}
void protocolo::keyGen() {
	//R1:
	string duplicateAlphabet = alphabet;
	string r1;
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		r1 = r1 + duplicateAlphabet[v1];

		duplicateAlphabet[v1] = 'T';
	}
	rotor1 = r1;
	outfile << "Rotor 1: " << r1 << " ";
	//R2:
	duplicateAlphabet = alphabet;
	string r2;
	string mensaje = shiftRR(r1);
	escitala user1(2);
	r2 = user1.encrypt(mensaje);
	rotor2 = r2;
	outfile <<"3 primeras letras del rotor 2: " << r2[0] << r2[1] << r2[3] << endl;
	//R3:
	string mensaje2 = shiftLL(shiftLL(r2));
	string r3 = user1.encrypt(mensaje2);
	rotor3 = r3;
	outfile <<"3 primeras letras del rotor 3: "<< r3[0] << r3[1] << r3[3] << endl;
	outfile << "Filas: " << user1.getFilas() << ", Columnas: " << user1.getColumnas() << endl;

}
string protocolo::encrypt(string message1) {
	message = message1;
	vigenere user2;
	string mensajeEncriptado = user2.encrypt(message);
	codigoAfin user3;
	mensajeEncriptado = user3.encrypt(mensajeEncriptado);
	outfile <<"Longitud del mensaje encriptado de Vigenere: "<< mensajeEncriptado.length() << endl;
	outfile <<"Claves del codigo Afin: "<< user3.getKey1() << " " << user3.getKey2() << endl;
	return mensajeEncriptado;
}
string protocolo::decrypt(string encryptedMessage) {
	string decrypted;
	
	return decrypted;
}
string protocolo::getMessage() {
	return message;
}
string protocolo::shiftRR(string alpha) {
	string newR;
	newR.push_back(alpha[alpha.length() - 1]);
	for (int i = 0; i < alpha.length()-1;i++) {
		newR.push_back(alpha[i]);
	}
	return newR;
}
string protocolo::shiftLL(string alpha) {
	string newR;
	for (int i = 1;i < alpha.length();i++) {
		newR.push_back(alpha[i]);
	}
	newR.push_back(alphabet[0]);
	return newR;
}