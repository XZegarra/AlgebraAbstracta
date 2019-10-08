

#include <iostream>
#include "vigenere.h"
#include "escitala.h"
#include "vernan.h"
#include "codigoEnigma.h"
#include "codigoAfin.h"
#include "codigoRSA.h"
#include "protocolo.h"

using namespace std;

vector <int> criba(int n) {
	vector <int> listaNumerosAnteriores;
	vector <int> listaMarcados;
	vector <bool> marcas;
	vector <int> resultado;
	for (int i = 0; i < n; i++) {
		listaNumerosAnteriores.push_back(i);
		marcas.push_back(true);
	}
	marcas[0] = false;
	marcas[1] = false;
	for (int i = 2;i * i < marcas.size();i++) {
		if (marcas[i]) {
			for (int j = 2;i * j < marcas.size(); j++) {
				marcas[i * j] = false;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		if (marcas[i]) {
			resultado.push_back(listaNumerosAnteriores[i]);
		}
	}

	return resultado;
}

int modulo(int dividendo, int divisor) {
	int cociente = dividendo / divisor;
	int residuo;
	if (divisor > 0) {
		if (dividendo >= 0) {
			residuo = dividendo - (cociente * divisor);
		}
		else {
			cociente--;
			residuo = dividendo - (cociente * divisor);
		}
	}
	else {
		int temp = cociente * divisor;
		temp -= divisor;
		residuo = (temp)-dividendo;
	}

	return residuo;
}
int euclides(int a, int b) {
	int r1 = a;
	int r2 = b;
	while (r2 > 0) {
		int q = r1 / r2;
		int r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}

int euclidesExtendido(int a, int b) {
	int r1 = a;
	int r2 = b;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	int s;
	int r;
	int t;
	while (r2 > 0) {
		int q = r1 / r2;
		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
		s = s1 - (q * s2);
		s1 = s2;
		s2 = s;
		t = t1 - (q * t2);
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	return s;
}

int main()
{
    /*Vigenere:
	vigenere usuario;
	string mensajeEncriptado = usuario.encrypt("hola como estas");
	cout << "Mensaje encriptado = " << mensajeEncriptado << endl;
	cout << "Mensaje desincriptado = " << usuario.decrypt(mensajeEncriptado);
	*/
	/*Escitala:
	escitala usuario(5);
	string mensajeEncriptado = usuario.encrypt("hola como estas");
	cout << "Mensaje encriptado = " << mensajeEncriptado << endl;
	cout << "Mensaje desincriptado = " << usuario.decrypt(mensajeEncriptado);
	*/
	/*Vernan:
	vernan usuario;
	string mensajeEncriptado = usuario.encrypt("hola como estas");
	cout << "Mensaje encriptado = " << mensajeEncriptado << endl;
	cout << "Mensaje desincriptado = " << usuario.decrypt(mensajeEncriptado);
	*/
	/*Enigma:
	codigoEnigma usuario;
	string mensajeEncriptado = usuario.encrypt("hola como estas");
	cout << "Mensaje encriptado = " << mensajeEncriptado << endl;
	cout << "Mensaje desincriptado = " << usuario.decrypt(mensajeEncriptado);
	*/
	/*Afin:
	codigoAfin usuario;
	string mensajeEncriptado = usuario.encrypt("hola como estas");
	cout << "Mensaje encriptado = " << mensajeEncriptado << endl;
	cout << "Mensaje desincriptado = " << usuario.decrypt(mensajeEncriptado);
	*/
	/*RSA:
	codigoRSA usuario;
	vector <long long unsigned int> messageE = usuario.encrypt("hola como estas");
	*/
	/*Protocolo:
	protocolo usuario;
	usuario.encrypt("hola como estas");
	*/
}

