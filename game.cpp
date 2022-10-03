#include "headers.h"
#include <iostream>
#include <windows.h>

using namespace std;

game::game(int nk,int nw):Engine(nw,nk) {}
game::~game() {}

void game::start() {
	Init();
	while (true) {	
		view();
		Analyze();
		Sleep(500); // auomatic
		// system("pause");  // steps by pressing enter
	}
}

void game::view() {}
