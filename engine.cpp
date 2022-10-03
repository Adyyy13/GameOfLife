#include "headers.h"
#include <iostream>
#include <fstream>

using namespace std;


Engine::Engine(int nw, int nk) : nW(nw), nK(nk) {

	T = new bool *[nW];
	for (int i = 0; i < nW; i++) {
		T[i] = new bool[nK];
		for (int j = 0; j < nK; j++) {
			T[i][j] = false;
		}
	}

	tmp = new bool* [nW];
	for (int i = 0; i < nW; i++) {
		tmp[i] = new bool[nK];
		for (int j = 0;j < nK; j++) {
			tmp[i][j] = false;

		}
	}

	birth = new int[8];
	for (int i = 0; i < 8; i++) {
		birth[i] = 10;
	}

	die = new int[8];
	for (int i = 0; i < 8; i++) {
		die[i] = 10;
	}

	noChange = new int[8];
	for (int i = 0; i < 8; i++) {
		noChange[i] = 10;
	}

}

Engine::~Engine() {
	if (T && tmp) {
		for (int i = 0; i < nW; i++) {
			delete[]T[i];
			delete[]tmp[i];
		}
		delete[]T;
		delete[]tmp;
	}
}

void Engine::Init() {


	ifstream file("initialize.txt");

	for (int i = 0;i < 20;i++) {
		for (int j = 0; j < 20;j++) {
			file >> T[i][j];
		}
	}
	int number = 0;

	for (int i=0; i<8;i++) {
	file >> number;
	if (number != 9 ) {birth[i] = number;}
	else { break;}
	}

	for (int i = 0; i < 8;i++) {
		file >> number;
		if (number != 9) { noChange[i] = number; }
	else { break; }

	}

	for (int i=0; i<8;i++) {
	file >> number;
	if (number != 9 ) {die[i] = number;}
	else { break;}
	}

	file.close();

}

void Engine::Analyze() {

	
	if (T && tmp) {
		for (int i = 1; i < nW - 1; i++) {
			for (int j = 1; j < nK - 1; j++) {
				int liveCellsAround = 0;
				if (T[i - 1][j - 1] == true)liveCellsAround++;
				if (T[i][j - 1] == true)liveCellsAround++;
				if (T[i + 1][j - 1] == true)liveCellsAround++;
				if (T[i - 1][j] == true)liveCellsAround++;
				if (T[i + 1][j] == true)liveCellsAround++;
				if (T[i - 1][j + 1] == true)liveCellsAround++;
				if (T[i][j + 1] == true)liveCellsAround++;
				if (T[i + 1][j + 1] == true)liveCellsAround++;

				for (int k = 0; k < 7; k++) {
					int x = birth[k];
					if (x == 10) { break; }
					if (liveCellsAround == x) { tmp[i][j] = true; }
				}
				for (int k = 0; k < 7; k++) {
					int y = noChange[k];
					if (y == 10) { break; }
					if (liveCellsAround == y) { tmp[i][j] = T[i][j]; }
				}
				for (int k = 0; k < 7; k++) {
					int z = die[k];
					if (z == 10) { break; }
					if (liveCellsAround == z) { tmp[i][j] = false; }
				}


			}
		}

		for (int k = 0; k < nW; k++) {
			for (int l = 0; l < nK; l++) {
				T[k][l] = tmp[k][l];
			}
		}
	}
	

}


