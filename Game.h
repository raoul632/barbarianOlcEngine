#pragma once
#include<vector>
#include "menu.h"
#include "SpritesA.h"

class SpritesA;



class Game : public olc::PixelGameEngine
{
	
public : 
	enum GameState {BEGIN, INGAME, EXIT, GAMEOVER} ; 
	GameState _internalState; 
	olc::PixelGameEngine *_pge;
	bool IsExit = false;
	std::vector<std::string> decors; 
	std::vector<olc::Sprite*> imageDecors;
	olc::Sprite* imageS;
	SpritesA* _spriteA;
	SpritesA* _spriteB;
	float _totalTimeElapsed; 
	int _level; 
	int _choiceStage; 

public:
	Game(olc::PixelGameEngine *pge);
	void BeginLevel();
	void Update(float ElapsedTime);
	void DrawSpriteLife(SpritesA * sp);
	void DrawSpriteLife(SpritesA * sp, short xS, short yS, short rSB, short rSS);
	void Draw();

	void deleteFromVector(std::vector<olc::Sprite*> tabToClean);

	~Game();
};

