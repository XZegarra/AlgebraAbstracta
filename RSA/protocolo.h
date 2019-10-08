#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
//#include "Funciones.h"
#include <vector>
#include <sstream>
#include <bitset> 
#include "codigoAfin.h"
#include "escitala.h"
#include "vernan.h"
#include "codigoEnigma.h"
#include "vigenere.h"
using namespace std;

class protocolo
{
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
	string message;
	int keyPrivada;
	int keyPublica;
	string shiftRR(string alpha);
	string shiftLL(string alpha);
	string rotor1;
	string rotor2;
	string rotor3;

public:
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	protocolo();
	protocolo(int key1, int key2);
	void keyGen();
	string encrypt(string menssage);
	string decrypt(string encryptedMessage);
	string getMessage();

};