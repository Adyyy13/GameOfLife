#include "headers.h"
#include <iostream>

using namespace std;

gameTxt::gameTxt(int nw, int nk) : game(nw, nk) {}


gameTxt::~gameTxt() {}

void gameTxt::view() {
    if (T && tmp) {
        system("cls");
        for (int i = 0; i < nW; i++) {
            cout << ' ';
            for (int j = 0; j < nK; j++) {
                if (T[i][j] == true) cout << 'O'<<' ';
                else cout << '-'<<' ';
            }
            cout << ' ' << endl;
        }
    }
}

