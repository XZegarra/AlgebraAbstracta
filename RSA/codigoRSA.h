#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "Funciones.h"
#include <vector>
#include <sstream>
#include <bitset> 

using namespace std;

class codigoRSA
{
	vector <long long int> criba(int n) {
		vector <long long int> listaNumerosAnteriores;
		vector <long long int> listaMarcados;
		vector <bool> marcas;
		vector <long long int> resultado;
		for (long long int i = 0; i < n; i++) {
			listaNumerosAnteriores.push_back(i);
			marcas.push_back(true);
		}
		marcas[0] = false;
		marcas[1] = false;
		for (long long int i = 2;i * i < marcas.size();i++) {
			if (marcas[i]) {
				for (long long int j = 2;i * j < marcas.size(); j++) {
					marcas[i * j] = false;
				}
			}
		}

		for (long long int i = 0;i < n;i++) {
			if (marcas[i]) {
				resultado.push_back(listaNumerosAnteriores[i]);
			}
		}

		return resultado;
	}

	int modulo(int dividendo, int divisor) {
		while (divisor < dividendo) {
			 dividendo = hallarIgualitario(dividendo, divisor);
		}
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
	int hallarIgualitario(int a, int b) {
		int temp = a / b;
		int resultado = a - (b * temp);
		return resultado;
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
	long long int unsigned exp(long long unsigned int base,long long unsigned int exponente, long long unsigned int m) {
		long long unsigned int exp = 1;
		long long unsigned int x = modulo(base, m);
		while (exponente > 0) {
			if (modulo(exponente, 2)) {
				exp = modulo(exp * x, m);
			}
			x = modulo(x * x, m);
			exponente = exponente / 2;
		}
		return exp;
	}
	string message;
	int p;
	int q;
public:
	long long unsigned int ee;
	long long unsigned int dd;
	long long unsigned int nn;
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	codigoRSA();
	codigoRSA(int key1, int key2);
	void keyGen();
	vector <long long unsigned int> encrypt(string menssage);
	string decrypt(vector<long long unsigned int> encryptedMessage);
	string getMessage();
};
