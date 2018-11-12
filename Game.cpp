//#define OLC_PGE_APPLICATION
#include "Game.h"



Game::Game(olc::PixelGameEngine *pge) :_totalTimeElapsed(0)
{
	_pge = pge;
	_internalState = INGAME;
	//_spriteA = new SpritesA(12,pge); 
	_spriteA = new SpritesA(12,_pge,25,100,true,true, false,olc::DARK_MAGENTA);
	_spriteB = new SpritesA(12, _pge, 150, 100, true, false, true, olc::RED);

	_spriteA->_enemy = _spriteB; 
	_spriteB->_enemy = _spriteA;
	decors.push_back("images\\stage\\foret.png");
	
}

void Game::Update(float ElapsedTime)
{
	
	if (_internalState == INGAME) {
	/*	if (_totalTimeElapsed < 0.3) {
          _totalTimeElapsed += ElapsedTime; 
		}*/

			_pge->Clear(olc::BLACK);
			imageS = new olc::Sprite(decors[0]);
		
			_pge->DrawSprite(0, 0, imageS);
			_pge->DrawString(0, 0, " ETAT B : " + std::to_string(_spriteB->_internalState));
			_pge->DrawString(0, 8, " index image : " + std::to_string(_spriteB->_indexImage));
			_pge->DrawString(0, 16, " startF : " + std::to_string(_spriteB->_startFrame));
			_pge->DrawString(0, 24, " endF : " + std::to_string(_spriteB->_endFrame));
			_pge->DrawString(0, 32, " distance : " + std::to_string(_spriteB->_distanceBetweenEnemy));
			_pge->DrawString(0, 40, " collide : " + std::to_string(_spriteA->isCollide(_spriteB)));
			_pge->DrawString(0, 48, " ETAT A : " + std::to_string(_spriteA->_internalState));
			_pge->DrawString(82, 0, " _x spA : " + std::to_string((int)_spriteA->_x));
			_pge->DrawString(180, 0, " _x spB : " + std::to_string((int)_spriteB->_x));

			if (_spriteA->_isAlive)
			{
				_spriteA->Update(ElapsedTime);
				_spriteA->Draw();
				DrawSpriteLife(_spriteA, 10, 5, 3, 2);
			}

			if (_spriteB->_isAlive)
			{
				_spriteB->Update(ElapsedTime);
				_spriteB->Draw();
				DrawSpriteLife(_spriteB,282,5,3,2); 
			}
			
		
	}
}

//si c'est  l'ia je dessine a droite sinon je dessine a gauche
void Game::DrawSpriteLife(SpritesA* sp, short xS, short yS,short rSB,short rSS  ) {
	short xSprite = xS;
	short ySprite = yS;
	short rSpriteBig = rSB;
	short rSpriteSmall = rSS;
	bool off = false; 

	if (sp->_hp > 0) {
		for (char i = 0; i <= sp->_hp;  i +=2 )
		{
		
				//check last element
				if (i+2 >= sp->_hp && (sp->_hp % 2) == 0)
				{
					_pge->FillCircle(xSprite, ySprite, rSpriteBig, olc::RED);
					return; 
					
				}
				else if ((i + 2 >= sp->_hp && !((sp->_hp % 2) == 0)))
				{
					_pge->FillCircle(xSprite, ySprite, rSpriteSmall, olc::RED);
					return; 
				}
				else {
					_pge->FillCircle(xSprite, ySprite, rSpriteBig, olc::RED);
				}

					

					
				
				xSprite += 8; 
				if (i +2 >= 6 && !off) {
					ySprite = ySprite + 8;
					xSprite = xS; 
					off = true; 
				}
			

		}

	}

}

void Game::Draw()
{
}


Game::~Game()
{
	delete _spriteA; 
	delete _spriteB; 

}
