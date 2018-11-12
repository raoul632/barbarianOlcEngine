#define OLC_PGE_APPLICATION
#include "Menu.h"

//int32_t x, int32_t y, Sprite *sprite, uint32_t scale = 1
void Menu::DrawScene()
{
	
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
		_pge->DrawString(lWIDTH/6, lHEIGHT/2, "PLEASE PRESS SPACE TO CONTINU");
			
	}

      if (_pge->GetKey(olc::SPACE).bPressed) {
		  isExit = true; 

				}
	
}

void Menu::Update()
{

}




Menu::Menu(olc::PixelGameEngine *pge){
	_pge = pge; 
	image = "images/menu/titre.png"; //"images/menu/titre.png"
	timer = new Timer(); 
	timer->StartChrono(); 
	lHEIGHT = _pge->ScreenHeight();
	lWIDTH = _pge->ScreenWidth(); 
}


Menu::~Menu()
{
	delete(imageS);
	delete(timer); 
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
