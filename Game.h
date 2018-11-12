#pragma once
#include<vector>
#include "menu.h"
#include "SpritesA.h"

class SpritesA;


class Game : public olc::PixelGameEngine
{
	
public : 
	enum GameState {BEGIN, INGAME, EXIT} ; 
	GameState _internalState; 
	olc::PixelGameEngine *_pge;
	bool IsExit = false;
	std::vector<std::string> decors; 
	olc::Sprite* imageS;
	SpritesA* _spriteA;
	SpritesA* _spriteB;
	float _totalTimeElapsed; 

public:
	Game(olc::PixelGameEngine *pge);
	void Update(float ElapsedTime);
	void DrawSpriteLife(SpritesA * sp);
	void DrawSpriteLife(SpritesA * sp, short xS, short yS, short rSB, short rSS);
	void Draw();

	~Game();
};

