#pragma once
#include "MainHeader.h"
#include "Timer.h"


class Menu : public olc::PixelGameEngine
{
public: 
	std::string image; 
	olc::PixelGameEngine *_pge; 
	void DrawScene();
	void DrawYourself();
	void Update();
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool isExit = false; 
	int lWIDTH; 
	int lHEIGHT; 
	std::vector<std::string> imagesDecorsmini;
	std::vector<olc::Sprite*> spritesDecorsmini;
	int stagesChoice; 

	Timer *timer; 
	olc::Sprite *imageS; 
	
public:
	Menu(olc::PixelGameEngine * pge);
	//Menu(olc::PixelGameEngine * pge, int WIDTH, int HEIGHT);
	~Menu();
	void deleteFromVector(std::vector<olc::Sprite*> tabToClean);
};


