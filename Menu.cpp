#define OLC_PGE_APPLICATION
#include "Menu.h"

//int32_t x, int32_t y, Sprite *sprite, uint32_t scale = 1
void Menu::DrawScene()
{
	
}

Menu::Menu(olc::PixelGameEngine *pge) {
	_pge = pge;
	image = "images/menu/titre.png"; //"images/menu/titre.png"
	timer = new Timer();
	timer->StartChrono();
	lHEIGHT = _pge->ScreenHeight();
	lWIDTH = _pge->ScreenWidth();
	PlaySound(TEXT("images/sound/AnvilOfCrom.wav"), NULL, SND_ASYNC); //SND_FILENAME or SND_LOOP
	imagesDecorsmini.push_back("images\\stage\\foretmini.png");
	imagesDecorsmini.push_back("images\\stage\\arenemini.png");
	imagesDecorsmini.push_back("images\\stage\\plainemini.png");
	spritesDecorsmini.push_back(new olc::Sprite(imagesDecorsmini.at(0)));
	spritesDecorsmini.push_back(new olc::Sprite(imagesDecorsmini.at(1)));
	spritesDecorsmini.push_back(new olc::Sprite(imagesDecorsmini.at(2)));
	stagesChoice = 0;
}


void Menu::DrawYourself()
{
	if (!timer->OneStep(1))
	{
		
		 imageS = new olc::Sprite(image);
		_pge->DrawSprite(0, 0, imageS);
	}
	else {
		_pge->Clear(olc::BLACK); 
		int x = 50; 
		for (auto value : spritesDecorsmini) {

			_pge->DrawSprite(x, 50, value); 
			x = x + 80; 
		}
		if (stagesChoice == 0)
		{
			_pge->DrawRect(50 , 50, spritesDecorsmini.at(0)->width, spritesDecorsmini.at(0)->height, olc::RED);
		}
		else if (stagesChoice == 1)
		{
			_pge->DrawRect((50 * (stagesChoice+1)) + 30  , 50, spritesDecorsmini.at(0)->width, spritesDecorsmini.at(0)->height, olc::RED);

		}
		else if (stagesChoice == 2)
		{
			_pge->DrawRect((50 * (stagesChoice+2))+10 , 50, spritesDecorsmini.at(0)->width, spritesDecorsmini.at(0)->height, olc::RED);

		}
		_pge->DrawString(lWIDTH/6 -20, lHEIGHT/2 + 40, "PLEASE PRESS SPACE TO CONTINU");
			
	}

      if (_pge->GetKey(olc::SPACE).bPressed) {
		  isExit = true; 

				}
	  if (_pge->GetKey(olc::RIGHT).bPressed) {
		  if (stagesChoice< 2)
		  stagesChoice++; 
	  }
	  if (_pge->GetKey(olc::LEFT).bPressed) {
		  if (stagesChoice > 0)
			  stagesChoice--;
	  }
	
}

void Menu::Update()
{

}






Menu::~Menu()
{
	delete(imageS);
	delete(timer); 
	deleteFromVector(spritesDecorsmini);
}

void Menu::deleteFromVector(std::vector<olc::Sprite*> tabToClean)
{
	for (auto it = tabToClean.cbegin(); it != tabToClean.cend(); it++)
	{
		delete (*it);
	}
	tabToClean.clear();
}




	bool Menu::OnUserCreate(){
		// Called once at the start, so create things here
	
		

		return true;
	}

	bool Menu::OnUserUpdate(float fElapsedTime)
	{
		// called once per frame
		//void DrawSprite(int32_t x, int32_t y, Sprite *sprite, uint32_t scale = 1);
		olc::Sprite *imageS = new olc::Sprite(image);
		DrawSprite(0, 0, imageS); 


		return true;
	}
