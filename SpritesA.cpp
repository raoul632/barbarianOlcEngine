#include "SpritesA.h"
#include <string.h>




SpritesA::SpritesA()
{
}

SpritesA::SpritesA(int hp, olc::PixelGameEngine *pge):_hp(hp = 12),_pge(pge),_x(30),_y(100),_tickCount(0),_tickCountPerFrame(3),_index(0),_startFrame(0),_endFrame(0),_numberFrame(0), _indexImage(0), _moveLength(2),_sensNormal(true)
{
	Init(); 
}

SpritesA::SpritesA(int hp, olc::PixelGameEngine * pge, float x, float y, bool isChangeColor, bool isSensNormal, bool isIA, olc::Pixel color) : _hp(hp), _pge(pge), _x(x), _y(y), _tickCount(0), _tickCountPerFrame(3), _index(0), _startFrame(0), _endFrame(0), _numberFrame(0), _indexImage(0), _moveLength(2), _sensNormal(isSensNormal),_isIA(isIA),_color(color),_isChangeColor(isChangeColor)
{

	Init();
}

void SpritesA::initPosition(int indexImage, int tickCount, int index, int startFrame, int endFrame, int numberFrame) {
	_indexImage = indexImage; 
	_tickCount = tickCount;
	_index = index;
	_startFrame = startFrame;
	_endFrame = endFrame;
	_numberFrame = numberFrame;


}

void SpritesA::Init()
{

	_internalState = NORMAL;
	_oldInternalState = NORMAL; 

	//0 normal 1-3 avant recule 4-5 saut 6-7 assis 8 parade corps 9 parade tete 10-13 roulade
	//14-16 tombe 17-19 attaquedevant 20 sang 21-22 touche
	imagesAVANCE.push_back("images\\spritesA\\debout.png");
	imagesAVANCE.push_back("images\\spritesA\\marche1.png");
	imagesAVANCE.push_back("images\\spritesA\\marche2.png");
	imagesAVANCE.push_back("images\\spritesA\\marche3.png");
	imagesAVANCE.push_back("images\\spritesA\\saut1.png");
	imagesAVANCE.push_back("images\\spritesA\\saut2.png");
	imagesAVANCE.push_back("images\\spritesA\\assis1.png");
	imagesAVANCE.push_back("images\\spritesA\\assis2.png");
	imagesAVANCE.push_back("images\\spritesA\\protegeD.png");
	imagesAVANCE.push_back("images\\spritesA\\protegeH.png");

	imagesAVANCE.push_back("images\\spritesA\\roulade1.png");
	imagesAVANCE.push_back("images\\spritesA\\roulade2.png");
	imagesAVANCE.push_back("images\\spritesA\\roulade3.png");
	imagesAVANCE.push_back("images\\spritesA\\roulade4.png");
	imagesAVANCE.push_back("images\\spritesA\\tombe1.png");
	imagesAVANCE.push_back("images\\spritesA\\tombe2.png");
	imagesAVANCE.push_back("images\\spritesA\\tombe3.png");
	imagesAVANCE.push_back("images\\spritesA\\devant1.png");
	imagesAVANCE.push_back("images\\spritesA\\devant2.png");
	imagesAVANCE.push_back("images\\spritesA\\devant3.png");
	imagesAVANCE.push_back("images\\spritesA\\sang.png");
	imagesAVANCE.push_back("images\\spritesA\\touche1.png");
	imagesAVANCE.push_back("images\\spritesA\\touche2.png");


	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(0)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(1)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(2)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(3)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(4)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(5)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(6)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(7)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(8)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(9)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(10)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(11)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(12)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(13)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(14)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(15)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(16)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(17)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(18)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(19)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(20)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(21)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(22)));

	_currentSprite = new olc::Sprite(imagesAVANCE.at(0));
	_spriteTranspose = new olc::Sprite(imagesAVANCE.at(0));
	_isAlive = true; 
	_isFalling = false;
	_oldIsFalling = false;
	_isTouch = false;
	_isDecapit= false;
	_oldIstuching = false; 
	_standartColor = STANDART_BARBARIAN; 
	_timer = new Timer();
	_timer->StartChrono();

}

void SpritesA::Update(float ElapsedTime)
{
	float test = ElapsedTime; 

	//deplacement //attaque //collision 

	Deplacement();
	
	
	

	
}

void SpritesA::DeplacementWithOutIA() {
	if (!(_pge->GetKey(olc::CTRL).bHeld))
	{
		if ((_pge->GetKey(olc::N9).bPressed))
		{
			initPosition(9, 0, 0, 9, 9, 3);
			_internalState = SpritesA::PROTEGEH; //protege le corps
		}
		else if ((_pge->GetKey(olc::N7).bPressed))
		{
			initPosition(8, 0, 0, 8, 8, 3);
			_internalState = SpritesA::PROTEGED; //protege le corps
		}
		else if (_pge->GetKey(olc::N6).bPressed)
		{

			_internalState = SpritesA::AVANCER;
			initPosition(1, 0, 0, 1, 3, 3);

		}
		else if (_pge->GetKey(olc::N4).bPressed)
		{
			_internalState = SpritesA::RECULER;
			initPosition(0, 0, 0, 1, 3, 3);
		}
		else if (_pge->GetKey(olc::N8).bPressed)
		{
			_internalState = SpritesA::SAUTER;
			initPosition(4, 0, 0, 4, 5, 2);

		}
		else if (_pge->GetKey(olc::N2).bPressed)
		{
			_internalState = SpritesA::GENOUX;
			initPosition(6, 0, 0, 6, 7, 2);
		}
		else if (_pge->GetKey(olc::N3).bPressed)
		{
			_internalState = SpritesA::ROULADEA;
			initPosition(10, 0, 0, 10, 13, 1);
		}
		else if (_pge->GetKey(olc::N1).bPressed)
		{
			_internalState = SpritesA::ROULADER;
			initPosition(10, 0, 0, 10, 13, 2);
		}
		else if (_isFalling)
		{
			_internalState = SpritesA::TOMBE;
			initPosition(14, 0, 0, 14, 16, 2);
		}
		else
		{
			_currentSprite = spritesAVANCE.at(0);
			_internalState = SpritesA::NORMAL;
		}
	}
	else {
		 if (_pge->GetKey(olc::N6).bPressed)
		{

			_internalState = SpritesA::ATTAQUEDEVANT;
			initPosition(17, 0, 0, 17, 19, 3);

		}

	}

	_oldInternalState = _internalState; 

}

void SpritesA::DeplacementWithIA()
{

	if (false)
	{
		initPosition(9, 0, 0, 9, 9, 3);
		_internalState = SpritesA::PROTEGEH; //protege le corps
	}
	else if (false)
	{
		initPosition(8, 0, 0, 8, 8, 3);
		_internalState = SpritesA::PROTEGED; //protege le corps
	}
	else if (false)
	{

		_internalState = SpritesA::AVANCER;
		initPosition(1, 0, 0, 1, 3, 3);

	}
	else if (false)
	{
		_internalState = SpritesA::RECULER;
		initPosition(0, 0, 0, 1, 3, 3);
	}
	else if (false)
	{
		_internalState = SpritesA::SAUTER;
		initPosition(4, 0, 0, 4, 5, 2);

	}
	else if (false)
	{
		_internalState = SpritesA::GENOUX;
		initPosition(6, 0, 0, 6, 7, 2);
	}
	else if (false)
	{
		_internalState = SpritesA::ROULADEA;
		initPosition(10, 0, 0, 10, 13, 1);
	}
	else if (false)
	{
		_internalState = SpritesA::ROULADER;
		initPosition(10, 0, 0, 10, 13, 2);
	}
	else if (_isFalling  && !_oldIsFalling)
	{
		_oldIsFalling = _isFalling; 
		_internalState = SpritesA::TOMBE;
		initPosition(14, 0, 0, 14, 16, 3);
		
	}
	else
	{
		
		_currentSprite = spritesAVANCE.at(0);
		_internalState = SpritesA::NORMAL;
	}
	_oldInternalState = _internalState;
}

void SpritesA::Deplacement() {
	switch (_internalState)
	{
	case SpritesA::NORMAL:
		if (!_isIA)
		{
			DeplacementWithOutIA();
		}
		if (_isIA) {
			DeplacementWithIA();
		}
		//_pge->DrawSprite(_x, _y, _currentSprite);
		break;
	case SpritesA::RECULER:
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			movingBackward(_moveLength);
			
			//_pge->DrawSprite(_x, _y, _currentSprite);

		}
		else {
			initPosition(1, 0, 0, 1, 3, 3);
			//_pge->DrawSprite(_x, _y, _currentSprite);
		}


		if (_pge->GetKey(olc::N4).bReleased)
		{
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::AVANCER:

		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			movingForward(_moveLength);
			//_pge->DrawSprite(_x, _y, _currentSprite);


		}
		else {
			initPosition(1, 0, 0, 1, 3, 3);
			//_pge->DrawSprite(_x, _y, _currentSprite);
		}

		if (_pge->GetKey(olc::N6).bReleased)
		{
			_internalState = SpritesA::NORMAL;
		}

		break;
	case SpritesA::SAUTER:
		//debut du saut
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			break;
		}  //fin du saut 
		else
		{
			//_pge->DrawSprite(_x, _y, spritesAVANCE.at(4));
			_currentSprite = spritesAVANCE.at(4);
			initPosition(1, 0, 0, 1, 3, 3);
			_internalState = SpritesA::NORMAL;
		}

		break;
	case SpritesA::GENOUX:
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
		}
		else {
			initPosition(7, 0, 0, 7, 7, 1);
		}

		if (_pge->GetKey(olc::N2).bReleased)
		{
			_currentSprite = spritesAVANCE.at(6);
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::PROTEGED:
		_currentSprite = spritesAVANCE.at(8);
		if ((_pge->GetKey(olc::N7).bReleased))
		{
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::PROTEGEH:
		_currentSprite = spritesAVANCE.at(9);
		if ((_pge->GetKey(olc::N9).bReleased))
		{
			_internalState = SpritesA::NORMAL;
		}

		break;
	case SpritesA::ROULADEA:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			movingForward(_moveLength);
			if (isCollide(_enemy) && !_oldIstuching) {
				_enemy->_isFalling = true; 
				_enemy->_oldIsFalling = false;
				//_enemy->_internalState = TOMBE; 
				_sensNormal ? movingBackward(4) : movingBackward(-4);
			}
			
			break;

		}  //fin du saut 
		else
		{
			
			_oldIstuching = false; 
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::ROULADER:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			
			movingBackward(_moveLength);
			
			break;

		}  //fin du saut 
		else
		{
			_isFalling = false; 
			
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::TOMBE:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false) && _isFalling)
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			_sensNormal ? movingBackward(2) : movingBackward(-2); 
			
			break;
		}  //fin du saut 
		else
		{
			_isFalling = false;
			//_pge->DrawSprite(_x, _y, spritesAVANCE.at(4));
			_currentSprite = spritesAVANCE.at(16);
			initPosition(1, 0, 0, 1, 3, 3);
			//initPosition(1, 0, 0, 1, 3, 3);
			
			_internalState = SpritesA::NORMAL;
			
		}
		break;
	case SpritesA::ATTAQUEDEVANT:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			//_sensNormal ? movingBackward(2) : movingBackward(-2);
			_isFalling = false;
			break;
		}  //fin du saut 
		else
		{
			_internalState = SpritesA::NORMAL;

		}
		break;

	default:
		break;
	}

}


SpritesA::~SpritesA()
{
	delete _currentSprite; 
	delete _spriteTranspose; 
	deleteFromVector(spritesAVANCE); 
	delete(_timer);

}

void SpritesA::deleteFromVector(std::vector<olc::Sprite*> tabToClean)
{
	for (auto it = tabToClean.cbegin(); it != tabToClean.cend(); it++)
	{
		delete (*it);
	}
	tabToClean.clear(); 
}

void SpritesA::animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index)
{
	
	if (_index == 0) {
		_currentSprite = spritesFrame.at(beginFrame);
	}
	

	if (_tickCount >= tickCountPerFrame) {
		_tickCount = 0; 
		
		if (beginFrame + _index < lastFrame)
		{
			_currentSprite = spritesFrame.at(beginFrame + _index);
		}
		else {
			//_endFrame--; 
			_index = 0; 
		}
		_indexImage = beginFrame+_index;
		_index++;
	
	}

	_tickCount++;
}

void SpritesA::movingForward(int x)
{
	//_sensNormal ? _x += x : _x -= x;
	if (_enemy != nullptr && !isCollide(_enemy))
	{
		float res = _x + x;
		if (!(res > (_pge->ScreenWidth() - _currentSprite->width * 2))) {
			if (!(res < _currentSprite->width / 2))
			{
				_x += x;
			}
		}
		_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
	}
}

void SpritesA::movingBackward(int x)
{
	//_sensNormal ? _x -= x : _x += x;  0 + _currentSprite->width*2
	float res = _x - x; 
	
	if (!(res < _currentSprite->width /2) ) {
		if (!(res >(_pge->ScreenWidth() - _currentSprite->width *2)))
		{
			_x -= x;
		}
	}
	else {
		return; 
	}
}




bool SpritesA::animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending)
{

	if (_index == 0) {
		_currentSprite = spritesFrame.at(_indexImage);
	}


	if (_tickCount >= tickCountPerFrame) {
		_tickCount = 0;
		_indexImage = beginFrame + _index;
		_index++;

		if (beginFrame + _index <= lastFrame)
		{
			_currentSprite = spritesFrame.at(_indexImage);
		}
		else {
			if (_endFrame > _startFrame)
			{
				_endFrame--;
				_index = 0;
				return false;
			}
		
			return true;
		}
		

	}

	_tickCount++;
	return false; 
}

bool SpritesA::animateFrameOne(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending)
{

	if (_index == 0) {
		_currentSprite = spritesFrame.at(_indexImage);
	}


	if (_tickCount >= tickCountPerFrame) {
		_index++;
		_indexImage = beginFrame + _index;

		_tickCount = 0;

		if (beginFrame + _index <= lastFrame)
		{
			_currentSprite = spritesFrame.at(_indexImage);
		}
		else {
			if (_endFrame >= _startFrame)
			{
				_endFrame--;
				_index = 0;
				return true;
			}

			return true;
		}
		
		

	}

	_tickCount++;
	return false;
}

void SpritesA::Draw()
{
	//sens normal ou inverse


	_pge->SetPixelMode(olc::Pixel::ALPHA);



	if (!_sensNormal)
	{
		
		if (_isChangeColor)
		{
			changeColorSprite(_color, _currentSprite);
		}
		sensSpriteChange(_currentSprite);
		_pge->DrawSprite(_x, _y, _spriteTranspose);
	}
	else {
		if (_isChangeColor)
		{
			changeColorSprite(_color, _currentSprite);
		}
		_pge->DrawSprite(_x, _y, _currentSprite);
	}

	_pge->SetPixelMode(olc::Pixel::NORMAL);
}


void SpritesA::sensSpriteChange(olc::Sprite* currentSprite) {
	olc::Pixel temp;
	olc::Sprite spriteTempo; 

	for (int y = 0; y < currentSprite->height; y++)
	{

		for (int x = 0; x < currentSprite->width; x++)
		{
			temp = currentSprite->GetPixel(x, y);
			_spriteTranspose->SetPixel((currentSprite->width - 1) - x, y, currentSprite->GetPixel(x, y));


		}

	}


}

void SpritesA::changeColorSprite(olc::Pixel color, olc::Sprite* currentSprite)
{
/*
	olc::Pixel p;
	p.r = 0x60;
	p.g = 0x60;
	p.b = 0x80;

	olc::Pixel target;
	target.r = 0x46;
	target.g = 0x74;
	target.b = 0xb9;
*/

	for (int y = 0; y < _currentSprite->height; y++)
	{

		for (int x = 0; x < _currentSprite->width; x++)
		{
			if ((_currentSprite->GetPixel(x, y).b == _standartColor.b) && (_currentSprite->GetPixel(x, y).g == _standartColor.g) && (_currentSprite->GetPixel(x, y).r == _standartColor.r))
			{
				_currentSprite->SetPixel(x, y, color);

			}
		
		}
	}

}

bool SpritesA::isCollide(SpritesA *sp2)
{
	int w = _currentSprite->width / 2; 
	int h = _currentSprite->height /2; 
	if (_x < sp2->_x + w &&
		_x + w > sp2->_x &&
		_y < sp2->_y + sp2->_currentSprite->height &&
		h + _y > sp2->_y) {
		// collision detected!

		return true;
	}

	return false;


}

float SpritesA::distanceBeetweenSprites(SpritesA *sp2) {
	float _pointx = _x + _currentSprite->width; 
	float _pointy = _y - (_currentSprite->height / 2); 
	float _pointxEnemy = sp2->_x + sp2->_currentSprite->width - 19 ; //19 magique 
	float _pointyEnemy = sp2->_y - (sp2->_currentSprite->height / 2);
	return sqrt(pow((_pointxEnemy - _pointx),2) + pow((_pointyEnemy - _pointy),2)); 



}