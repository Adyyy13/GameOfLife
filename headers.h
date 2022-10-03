#pragma once

///////////////////////////////////////////////////////////////////////////////////////////

#define ENGINE
#ifdef ENGINE

class Engine {
protected:
    bool **T, **tmp;
    int nW, nK;
    void Init();
    int* birth, * die, * noChange;
public:
    Engine(int nw, int nk);
    virtual ~Engine();
    void Analyze();
private:
    
    Engine(const Engine& e);
    Engine& operator=(const Engine& e);
};

#endif // ENGINE

////////////////////////////////////////////////////////////////////////////////////////////

#define GAME
#ifdef GAME

class game : public Engine {
public:
    void start();
    virtual void view() = 0;
    game(int nw, int nk);
    virtual ~game();
private:
    game(const game& e);
    game& operator=(const game& e);
};

#endif // GAME

////////////////////////////////////////////////////////////////////////////////////////////

#define GAMETXT
#ifdef GAMETXT

class gameTxt : public game {
public:
    virtual void view();
    gameTxt(int nw,int nk);
    virtual ~gameTxt();
private:
    gameTxt(const gameTxt& e);
    gameTxt& operator=(const gameTxt& e);
};

#endif // GAMETXT

////////////////////////////////////////////////////////////////////////////////////////////

#define GAMEAPI
#ifdef GAMEAPI

class gameApi : public game {
    virtual void view();
    gameApi(int nw, int nk);
    virtual ~gameApi();
private:
    gameApi(const gameApi& e);
    gameApi& operator=(const gameApi& e);
};

#endif // GAMEAPI

////////////////////////////////////////////////////////////////////////////////////////////
