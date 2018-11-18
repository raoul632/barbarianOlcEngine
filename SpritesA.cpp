#include "SpritesA.h"
#include <string.h>




SpritesA::SpritesA()
{
}

SpritesA::SpritesA(int hp, olc::PixelGameEngine *pge):_hp(hp = 12),_pge(pge),_x(30),_y(100),_tickCount(0),_tickCountPerFrame(150),_index(0),_startFrame(0),_endFrame(0),_numberFrame(0), _indexImage(0), _moveLength(2),_sensNormal(true)
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
	//14-16 tombe 17-19 attaquedevant 20 sang 21-22 touche 24-25 coup en haut 26-27 coup de tete
	//28-29 coup de pied 30-32 attaque haute 33-36 moulinet ou toile 37-40 coupe tete 41-42 coup en bas
	//43-46 mort 47-49 vainqueur 50-53 decapitation 54-59 tete 
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
	imagesAVANCE.push_back("images\\spritesA\\blank.png");
	imagesAVANCE.push_back("images\\spritesA\\cou1.png");
	imagesAVANCE.push_back("images\\spritesA\\cou2.png");
	imagesAVANCE.push_back("images\\spritesA\\tete1.png");
	imagesAVANCE.push_back("images\\spritesA\\tete2.png");
	imagesAVANCE.push_back("images\\spritesA\\pied1.png");
	imagesAVANCE.push_back("images\\spritesA\\pied2.png");
	imagesAVANCE.push_back("images\\spritesA\\front1.png");
	imagesAVANCE.push_back("images\\spritesA\\front2.png");
	imagesAVANCE.push_back("images\\spritesA\\front3.png");
	imagesAVANCE.push_back("images\\spritesA\\toile1.png");
	imagesAVANCE.push_back("images\\spritesA\\toile2.png");
	imagesAVANCE.push_back("images\\spritesA\\toile3.png");
	imagesAVANCE.push_back("images\\spritesA\\toile4.png");
	imagesAVANCE.push_back("images\\spritesA\\retourne1.png");
	imagesAVANCE.push_back("images\\spritesA\\retourne2.png");
	imagesAVANCE.push_back("images\\spritesA\\retourne3.png");
	imagesAVANCE.push_back("images\\spritesA\\retourne4.png");
	imagesAVANCE.push_back("images\\spritesA\\genou.png");
	imagesAVANCE.push_back("images\\spritesA\\genou1.png");
	imagesAVANCE.push_back("images\\spritesA\\genou2.png");
	imagesAVANCE.push_back("images\\spritesA\\mort1.png");
	imagesAVANCE.push_back("images\\spritesA\\mort2.png");
	imagesAVANCE.push_back("images\\spritesA\\mort3.png");
	imagesAVANCE.push_back("images\\spritesA\\vainqueur1.png");
	imagesAVANCE.push_back("images\\spritesA\\vainqueur2.png");
	imagesAVANCE.push_back("images\\spritesA\\vainqueur3.png");
	imagesAVANCE.push_back("images\\spritesA\\decap1.png");
	imagesAVANCE.push_back("images\\spritesA\\decap2.png");
	imagesAVANCE.push_back("images\\spritesA\\decap3.png");
	imagesAVANCE.push_back("images\\spritesA\\decap4.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap1.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap2.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap3.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap4.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap5.png");
	imagesAVANCE.push_back("images\\spritesA\\tetedecap6.png");
	


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
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(23)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(24)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(25)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(26)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(27)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(28)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(29)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(30)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(31)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(32)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(33)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(34)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(35)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(36)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(37)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(38)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(39)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(40)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(41)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(42)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(43)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(44)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(45)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(46)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(47)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(48)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(49)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(50)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(51)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(52)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(53)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(54)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(55)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(56)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(57)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(58)));
	spritesAVANCE.push_back(new olc::Sprite(imagesAVANCE.at(59)));

	_currentSprite = new olc::Sprite(imagesAVANCE.at(0));
	_isAlive = true; 
	_isFalling = false;
	_isAttack = false; 
	_oldIsFalling = false;
	_isTouch = false;
	_isDecapit= false;
	_oldIstuching = false; 
	_isWining = false; 
	_standartColor = STANDART_BARBARIAN; 
	_timer = new Timer();
	_timer->StartChrono();
	_offsetX = -1; 
	_animateHeadX = 0;
	_animateHeadY = 0; 
	_compteurIAAttack = 0; 
	if (_isIA) {
		
		_actionByIA = NORMAL; 
		
			initLevelScriptIA();
		
	}

}

void SpritesA::Update(float ElapsedTime)
{
	float test = ElapsedTime; 

	//deplacement //attaque //collision 

	Deplacement();
	
	
	

	
}

void SpritesA::DeplacementWithOutIA() {

	//deplacement touche collision 
	if (!_isAlive) {

		if (_isDecapit) {
			_internalState = SpritesA::DECAPITE; 
			initPosition(50, 0, 0, 50, 53, 3);
		}//envoie vers animations decapitation
		else {
			_internalState = SpritesA::MORT;
			initPosition(44, 0, 0, 44, 46, 3);
		}

	}
	else if (_isWining) {
		_internalState = SpritesA::VAINQUEUR;
		initPosition(47, 0, 0, 47, 49, 3);
	}
	else if( _isFalling && !_oldIsFalling)
	{
		_oldIsFalling = _isFalling;
		_internalState = SpritesA::TOMBE;
		initPosition(14, 0, 0, 14, 16, 3);
		

	}
	else if (_isTouch && !_oldIstuching)
	{
		_oldIstuching = _isTouch;
		_internalState = SpritesA::TOUCHE;
		initPosition(21, 0, 0, 21, 22, 2);
		

	}
	else {

		if (!(_pge->GetKey(olc::CTRL).bHeld))
		{
			if ((_pge->GetKey(olc::N9).bPressed))
			{
				initPosition(9, 0, 0, 9, 9, 1);
				_internalState = SpritesA::PROTEGEH; //protege le corps
			}
			else if ((_pge->GetKey(olc::N7).bPressed))
			{
				initPosition(8, 0, 0, 8, 8, 1);
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
				initPosition(10, 0, 0, 10, 13, 3);
			}
			else if (_pge->GetKey(olc::N1).bPressed)
			{
				_internalState = SpritesA::ROULADER;
				initPosition(10, 0, 0, 10, 13, 3);
			}
			else if (_isFalling)
			{
				_internalState = SpritesA::TOMBE;
				initPosition(14, 0, 0, 14, 16, 3);
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
			else if (_pge->GetKey(olc::N8).bPressed)
			{
				_internalState = SpritesA::ATTAQUECOU;
				initPosition(24, 0, 0, 24, 25, 2);

			}
			else if (_pge->GetKey(olc::N9).bPressed)
			{
				_internalState = SpritesA::ATTAQUETETE;
				initPosition(26, 0, 0, 26, 27, 2);

			}
			else if (_pge->GetKey(olc::N3).bPressed)
			{
				_internalState = SpritesA::ATTAQUEPIED;
				initPosition(28, 0, 0, 28, 29, 2);

			}
			else if (_pge->GetKey(olc::N1).bPressed)
			{
				_internalState = SpritesA::ATTAQUEHAUT;
				initPosition(30, 0, 0, 30, 32, 3);

			}
			else if (_pge->GetKey(olc::N7).bPressed) {
				_internalState = SpritesA::ATTAQUEMOULINET;
				initPosition(33, 0, 0, 33, 36, 4);

			}
			else if (_pge->GetKey(olc::N4).bPressed) {
				_internalState = SpritesA::ATTAQUETRANCHETETE;
				initPosition(37, 0, 0, 37, 40, 4);

			}
			else if (_pge->GetKey(olc::N2).bPressed) {
				_internalState = SpritesA::ATTAQUEBASSE;
				initPosition(41, 0, 0, 41, 43, 3);

			}


		}
	}; 

	_oldInternalState = _internalState; 

}

void SpritesA::DeplacementWithIA()
{
	
	if (!_isAlive)
	{
		if (_isDecapit) {
			_internalState = SpritesA::DECAPITE;
			initPosition(50, 0, 0, 50, 53, 3);
			return; 
		}
		else
		{
			_internalState = SpritesA::MORT;
			initPosition(44, 0, 0, 44, 46, 2);
			return;
		}
	}
	else {
		//float dd = distanceBeetweenSprites(_enemy); 
		if (_isWining) {
			_internalState = SpritesA::VAINQUEUR;
			initPosition(47, 0, 0, 47, 49, 3);
		}
		else if (_isFalling && !_oldIsFalling)
		{
				_oldIsFalling = _isFalling;
				_internalState = SpritesA::TOMBE;
				initPosition(14, 0, 0, 14, 16, 3);
				return;

		}
			else if (_isTouch && !_oldIstuching)
		{
				_oldIstuching = _isTouch;
				_internalState = SpritesA::TOUCHE;
				initPosition(21, 0, 0, 21, 22, 2);
				return;

		}
		else if (_internalState == NORMAL) {
				//_oldIstuching = false; 
				ChangeIAState();
				_currentSprite = spritesAVANCE.at(0);
				
		}
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
		break;
	case SpritesA::RECULER:
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//movingBackward(_moveLength);
			_sensNormal ? movingBackward(1 * _moveLength) : movingBackward(-1 * _moveLength);
			
			//_pge->DrawSprite(_x, _y, _currentSprite);
			

		}
		else {
			initPosition(1, 0, 0, 1, 3, 3);
			//_pge->DrawSprite(_x, _y, _currentSprite);
			_internalState = SpritesA::NORMAL;
			
		}


		if (_pge->GetKey(olc::N4).bReleased)
		{
			_internalState = SpritesA::NORMAL;
		}
		break;
	case SpritesA::AVANCER:
		_pge->DrawString(0, 0, std::to_string(distanceBeetweenSprites(_enemy)));
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			_sensNormal ? movingForward(1 * _moveLength) : movingForward(-1 * _moveLength);
			
			//_pge->DrawSprite(_x, _y, _currentSprite);
			
		}
		else {
			initPosition(1, 0, 0, 1, 3, 3);
			//_pge->DrawSprite(_x, _y, _currentSprite);
			_internalState = SpritesA::NORMAL;
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
			//movingForward(_moveLength);
			_sensNormal ? movingForward(1* _moveLength) : movingForward(-1 *  _moveLength);
			//movingForward(1 * _moveLength);
		CheckAttack(SpritesA::ROULADEA);
		_oldIsFalling = true; 
			break;

		}  //fin du saut 
		else
		{
			_oldIsFalling = false; 
			//_oldIstuching = false; 
			_internalState = SpritesA::NORMAL;
			
		}
		break;
	case SpritesA::ROULADER:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))

		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			
			//movingBackward(_moveLength);
		
			_sensNormal ? movingBackward(1 * _moveLength) : movingBackward(-1 * _moveLength);
			break;

		}  //fin du saut 
		else
		{
			_isFalling = false; 
			
			_internalState = SpritesA::NORMAL;
			if (_isIA) {
				ChangeIAState();
			}
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
			_internalState = SpritesA::NORMAL;
			
		}
		break;
	case SpritesA::ATTAQUEDEVANT:
		
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			
			//_oldIstuching = false;
			_isAttack = true; 
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUEDEVANT);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4; 
			_isAttack = false; 
			_internalState = SpritesA::NORMAL;
		
		}
		break;
	case SpritesA::ATTAQUECOU:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUECOU);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;
		

		}
		break;
	case SpritesA::ATTAQUETETE:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUETETE);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;
		

		}
		break;
	case SpritesA::ATTAQUEPIED:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUEPIED);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;
			

		}
		break;
	case SpritesA::TOUCHE:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
		

			
			break;
		}  //fin du saut 
		else
		{
			_internalState = SpritesA::NORMAL;
		

		}
		break;
	case SpritesA::ATTAQUEHAUT:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUEHAUT);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;
			
	
		

			

		}
		break;
	case SpritesA::ATTAQUEMOULINET:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUEMOULINET);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;

		}
		break;
	case SpritesA::ATTAQUETRANCHETETE:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_sensNormal ? movingForward(2) : movingForward(-2);
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUETRANCHETETE);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;

		}
		break;
	case SpritesA::ATTAQUEBASSE:

		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{

			//_oldIstuching = false;
			_isAttack = true;
			break;
		}  //fin du saut 
		else
		{
			CheckAttack(SpritesA::ATTAQUEBASSE);
			_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
			//_sensNormal ? movingBackward(-1) : movingBackward(1);
			_offsetX = 4;
			_isAttack = false;
			_internalState = SpritesA::NORMAL;

		}
		break;
	case SpritesA::MORT:
		//debut du saut
		if (!animateFrameOne(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false) )
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			break;
		}  //fin du saut 
		else
		{
			_internalState = END; 
			//_currentSprite =  spritesAVANCE.at(46);
		
		}
		break;
	case SpritesA::VAINQUEUR:
		//debut du saut
		if (!animateFrame(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			break;
		}  //fin du saut 
		else
		{
			//_pge->DrawSprite(_x, _y, spritesAVANCE.at(4));
			//_currentSprite = spritesAVANCE.at(4);
			//initPosition(1, 0, 0, 1, 3, 3);
			//_internalState = SpritesA::NORMAL;
		}

		break;
	case SpritesA::DECAPITE:
		if (!animateFrameOneDecapite(_tickCount, _startFrame, _endFrame, spritesAVANCE, _tickCountPerFrame, _index, false))
		{
			//animation du saut 2 frame pour le saut et une de plus avant d(atteindre le status normal	
			
			break;
		}  //fin du saut 
		else
		{
			_internalState = END;
			//_currentSprite =  spritesAVANCE.at(46);

		}
		break; 
	case SpritesA::END:
		if (_isDecapit) {
			_pge->SetPixelMode(olc::Pixel::ALPHA);
			_pge->DrawSprite(_x + _currentSprite->width, 180, spritesAVANCE.at(59));

			_pge->SetPixelMode(olc::Pixel::NORMAL);
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
	delete(_internalIA); 

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
		if (!(res > (_pge->ScreenWidth() - _currentSprite->width ))) {
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
	float res = _x + x; 
	_distanceBetweenEnemy = distanceBeetweenSprites(_enemy);
	if (!(res < _currentSprite->width /2) ) {
		if (!(res >(_pge->ScreenWidth() - _currentSprite->width)))
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
				//_indexImage = lastFrame;
				return true;
			}

			return true;
		}
		
		

	}

	_tickCount++;
	return false;
}
bool SpritesA::animateFrameOneDecapite(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending)
{

	if (_index == 0) {
		_currentSprite = spritesFrame.at(_indexImage);
		_pge->SetPixelMode(olc::Pixel::ALPHA);
		_pge->DrawSprite(_x + _currentSprite->width, _y, spritesAVANCE.at(_indexImage + 4));
		_pge->SetPixelMode(olc::Pixel::NORMAL);
		_animateHeadY = 20; 
	}


	if (_tickCount >= tickCountPerFrame) {
		_index++;
		_indexImage = beginFrame + _index;

		_tickCount = 0;

		if (beginFrame + _index <= lastFrame)
		{
			_currentSprite = spritesFrame.at(_indexImage);
			_animateHeadY += 20;
			_pge->SetPixelMode(olc::Pixel::ALPHA);
			_pge->DrawSprite(_x + _currentSprite->width, _y + _animateHeadY, spritesAVANCE.at(_indexImage + 4));
			
			_pge->SetPixelMode(olc::Pixel::NORMAL);
		}
		else {
			if (_endFrame >= _startFrame)
			{
				//_endFrame--;
				_index = 0;
				//_indexImage = lastFrame;
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

	
		olc::Pixel temp;
		olc::Pixel blank;
	
		if (_isChangeColor)
		{
			changeColorSprite(_color, _spriteTranspose);

		}
	
		matrix3x3 matFinal, matA, matB; 
		//Identity(matFinal); 
		Reflection(matFinal);
		//Rotate(matFinal, 3.14 );
		for (int y = 0; y < _currentSprite->height; y++)
		{
			for (int x = 0; x < _currentSprite->width; x++)
			{
				olc::Pixel p = _currentSprite->GetPixel(x,y);
				float nx, ny;
				Forward(matFinal, (float)x, (float)y, nx, ny); 
				_pge->Draw(nx +_x , ny+_y, p);
			}
		}

	

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

	for (int y = 0; y < currentSprite->height ; y++)
	{
		for (int x = 0; x < currentSprite->width ; x++)
		{
			temp = currentSprite->GetPixel(x, y);
			_spriteTranspose->SetPixel((currentSprite->width - 1) - x, y, currentSprite->GetPixel(x, y));
		}
	}
	return; 


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
	float xTran = 0;
	float xx = 0; 
	if (!sp2->_sensNormal) {
		 xTran = sp2->_x - _currentSprite->width; 
	}
	else {
		xTran = sp2->_x; 
	}
	if (!_sensNormal) {
		xx = _x - _currentSprite->width;
	}
	else {
		xx = _x;
	}

	int w = _currentSprite->width / 2; 
	int h = _currentSprite->height /2; 
	if (xx < xTran + w &&
		xx + w > xTran &&
		_y < sp2->_y + sp2->_currentSprite->height &&
		h + _y > sp2->_y) {
		// collision detected!

		return true;
	}

	return false;


}

float SpritesA::distanceBeetweenSprites(SpritesA *sp2) {
	float xTran = 0;
	float xx = 0;
	float delta = 0; 
	float _pointx;
	
	if (!sp2->_sensNormal) {
		xTran = sp2->_x - _currentSprite->width;
		delta = -40;
	}
	else {
		xTran = sp2->_x;
	//	delta = _isAttack ? 40 : -40;

	}
	if (!_sensNormal) {
		xx = _x - _currentSprite->width ; //- _currentSprite->width
		_pointx = xx;
	}
	else {
		xx = _x;
		 _pointx = xx + _currentSprite->width + delta;
	}

	return abs(xTran - xx); 
	/*
	float _pointy = _y - (_currentSprite->height / 2); 
	float _pointxEnemy = xTran + sp2->_currentSprite->width /2  ; // la taille de l'image augmente quand on attaque 
	float _pointyEnemy = sp2->_y - (sp2->_currentSprite->height / 2);
	return sqrt(pow((_pointxEnemy - _pointx),2) + pow((_pointyEnemy - _pointy),2)); 
	*/


}

void SpritesA::CheckAttack(StateMovement sm) {

	if (sm == ATTAQUEDEVANT)
	{
		float dd = distanceBeetweenSprites(_enemy);
		if ((distanceBeetweenSprites(_enemy) < 12))
		{
			if (_enemy->_internalState == ROULADEA)
			{
				_isFalling = true;
				return; 
			}
			else if (_enemy->_internalState == GENOUX || _enemy->_internalState == ATTAQUEBASSE
				|| _enemy->_internalState == ATTAQUEDEVANT || _enemy->_internalState == ROULADER)
			{
				return; 
			}
			else if ( _enemy->_internalState == PROTEGED)
			{
				_isTouch = true;
				return; 

			}
	

				//&& !_oldIstuching

				_enemy->_isTouch = true;
				_enemy->_oldIstuching = false;
				_enemy->_hp--;
				CheckIfDead();
				return;
			

		}
		return;
	}
	else if (sm == ATTAQUECOU)
	{
		float dd = distanceBeetweenSprites(_enemy);
		if (distanceBeetweenSprites(_enemy) < 14)
		{
			if (_enemy->_internalState == ROULADEA)
			{
				_isFalling = true;
				return;
			}
			else if (_enemy->_internalState == GENOUX || _enemy->_internalState == ATTAQUEBASSE || _enemy->_internalState == ROULADER || _enemy->_internalState == ATTAQUECOU)
			{
				return;
			}
			else if (_enemy->_internalState == PROTEGED) 
			{
				_isTouch = false;
				return;
			}
			
				
				//&& !_oldIstuching
				
					_enemy->_isTouch = true;
					_enemy->_oldIstuching = false;
					_enemy->_hp--;
					CheckIfDead();
					return;
			
		}
		return;
	}
	else if (sm == ATTAQUETETE) {
		float dd = distanceBeetweenSprites(_enemy);

		if ((distanceBeetweenSprites(_enemy) < 20))
		{
			if (_enemy->_internalState == ROULADEA || _enemy->_internalState == ATTAQUEPIED
				|| _enemy->_internalState == ATTAQUEMOULINET || _enemy->_internalState == ATTAQUETETE || _enemy->_internalState == ROULADER)
			{
				return;
			}
			
				_enemy->_isFalling = true;
				_enemy->_oldIsFalling = false;
				_enemy->_hp--;
				CheckIfDead();
			
				return;
		}
		return;
	}
	else if (sm == ATTAQUEPIED) 
	{
		float dd = distanceBeetweenSprites(_enemy);

		if ((distanceBeetweenSprites(_enemy) < 27)) 
		{
			if (_enemy->_internalState == ROULADEA || _enemy->_internalState == ATTAQUEPIED || _enemy->_internalState == ROULADER)
			{
				return;
			}
		
				_enemy->_isFalling = true;
				_enemy->_oldIsFalling = false;
				_enemy->_hp--;
				CheckIfDead();
				return;
		}
		return;
	}
	else if (sm == ATTAQUEHAUT) 
	{
		float dd = distanceBeetweenSprites(_enemy);
		if (distanceBeetweenSprites(_enemy) < 20)
		{
			if (_enemy->_internalState == ROULADEA || _enemy->_internalState == ATTAQUEPIED || _enemy->_internalState == ATTAQUEMOULINET || _enemy->_internalState == ATTAQUEHAUT)
			{
				return;
			}
			else if ( _enemy->_internalState == PROTEGEH) 
			{
				_isTouch = true;
				return;
			}
		
				

				_enemy->_isFalling = true;
				_enemy->_oldIsFalling = false;
				_enemy->_hp--;
				CheckIfDead();
				//_enemy->_internalState = TOMBE; 
				//_sensNormal ? movingBackward(4) : movingBackward(-4);

				return;
		}
		return;
	}
	else if (sm == ATTAQUEMOULINET) 
	{
		

		float dd = distanceBeetweenSprites(_enemy);
		if ((distanceBeetweenSprites(_enemy) < 20))
		{
			if (_enemy->_internalState == ROULADEA
				|| _enemy->_internalState == ATTAQUEPIED || _enemy->_internalState == ROULADER)
			{
				return;
			}
			else if ( _enemy->_internalState == PROTEGED) 
			{
				_isTouch = true;
				return;

			}
			
				_enemy->_isFalling = true;
				_enemy->_oldIsFalling = false;
				_enemy->_hp--;
				CheckIfDead();
				return;
			
		}
		return;
	}
	else if (sm == ATTAQUETRANCHETETE)
	{
		float dd = distanceBeetweenSprites(_enemy);
		if (distanceBeetweenSprites(_enemy) < 20)
		{

			if (_enemy->_internalState == GENOUX || _enemy->_internalState == ROULADEA || _enemy->_internalState == ROULADER
				|| _enemy->_internalState == ATTAQUEBASSE || _enemy->_internalState == PROTEGEH || _enemy->_internalState == ATTAQUETRANCHETETE)
			{
				return;
			}
			else if (_enemy->_internalState == NORMAL ||
				(_enemy->_internalState == AVANCER) ||
				(_enemy->_internalState == ATTAQUEPIED) ||
				(_enemy->_internalState == ATTAQUEDEVANT) ||
				(_enemy->_internalState == RECULER) ||
				(_enemy->_internalState == ATTAQUETETE))
			{
				_enemy->_isTouch = false;
				_enemy->_isAlive = false;
				_enemy->_isDecapit = true;
				_enemy->_oldIstuching = false;
				_enemy->_hp = 0;
				CheckIfDead();
				return;
			}
			return;
		}
		return;
	}
	else if (sm == ATTAQUEBASSE)
	{
		float dd = distanceBeetweenSprites(_enemy);
		//&& !_oldIstuching

		if (distanceBeetweenSprites(_enemy) < 20)
		{
			if (_enemy->_internalState == ATTAQUEBASSE) 
			{
				return;
			}
			else if ( _enemy->_internalState == ATTAQUEPIED ||
				(distanceBeetweenSprites(_enemy) < 20 && _enemy->_internalState == ATTAQUEMOULINET) ||
				(distanceBeetweenSprites(_enemy) < 20 && _enemy->_internalState == ROULADEA)) 
			{
				_isFalling = true;
				return;
			}
			
				_enemy->_isTouch = true;
				_enemy->_oldIstuching = false;
				_enemy->_hp--;
				CheckIfDead();
				return;
			
		}
		return;
	}
	else if (sm == ROULADEA) 
	{

		if(_enemy->_internalState == SAUTER)
		{
			return;
		}
		else
		{
			if (isCollide(_enemy)) 
			{
				_enemy->_isFalling = true;
				_enemy->_oldIsFalling = false;
				//_enemy->_internalState = TOMBE; 
				_sensNormal ? movingBackward(4) : movingBackward(-4);
				return;
			}
		}
		return;
	}


}

void SpritesA::CheckIfDead() {
	if (_enemy->_hp <= 0) {
		_enemy->_isAlive = false; 
		_isWining = true; 
	}
}


void SpritesA::Identity(matrix3x3 &mat)
{
	mat.m[0][0] = 1.0f; mat.m[1][0] = 0.0f; mat.m[2][0] = 0.0f;
	mat.m[0][1] = 0.0f; mat.m[1][1] = 1.0f; mat.m[2][1] = 0.0f;
	mat.m[0][2] = 0.0f; mat.m[1][2] = 0.0f; mat.m[2][2] = 1.0f;
}

void SpritesA::Reflection(matrix3x3 &mat)
{
	mat.m[0][0] = -1.0f; mat.m[1][0] = 0.0f; mat.m[2][0] = 0.0f;
	mat.m[0][1] = 0.0f; mat.m[1][1] = 1.0f; mat.m[2][1] = 0.0f;
	mat.m[0][2] = 0.0f; mat.m[1][2] = 0.0f; mat.m[2][2] = 1.0f;
}

void SpritesA::Translate(matrix3x3 &mat, float ox, float oy)
{
	mat.m[0][0] = 1.0f; mat.m[1][0] = 0.0f; mat.m[2][0] = ox;
	mat.m[0][1] = 0.0f; mat.m[1][1] = 1.0f; mat.m[2][1] = oy;
	mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
}

void SpritesA::Rotate(matrix3x3 &mat, float fTheta)
{
	mat.m[0][0] = cosf(fTheta);  mat.m[1][0] = sinf(fTheta); mat.m[2][0] = 0.0f;
	mat.m[0][1] = -sinf(fTheta); mat.m[1][1] = cosf(fTheta); mat.m[2][1] = 0.0f;
	mat.m[0][2] = 0.0f;			 mat.m[1][2] = 0.0f;		 mat.m[2][2] = 1.0f;
}

void SpritesA::Scale(matrix3x3 &mat, float sx, float sy)
{
	mat.m[0][0] = sx;   mat.m[1][0] = 0.0f; mat.m[2][0] = 0.0f;
	mat.m[0][1] = 0.0f; mat.m[1][1] = sy;   mat.m[2][1] = 0.0f;
	mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
}

void SpritesA::Shear(matrix3x3 &mat, float sx, float sy)
{
	mat.m[0][0] = 1.0f; mat.m[1][0] = sx;   mat.m[2][0] = 0.0f;
	mat.m[0][1] = sy;   mat.m[1][1] = 1.0f; mat.m[2][1] = 0.0f;
	mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
}

void SpritesA::MatrixMultiply(matrix3x3 &matResult, matrix3x3 &matA, matrix3x3 &matB)
{
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 3; r++)
		{
			matResult.m[c][r] = matA.m[0][r] * matB.m[c][0] +
				matA.m[1][r] * matB.m[c][1] +
				matA.m[2][r] * matB.m[c][2];
		}
	}
}

void SpritesA::Forward(matrix3x3 &mat, float in_x, float in_y, float &out_x, float &out_y)
{
	out_x = in_x * mat.m[0][0] + in_y * mat.m[1][0] + mat.m[2][0];
	out_y = in_x * mat.m[0][1] + in_y * mat.m[1][1] + mat.m[2][1];
}

void SpritesA::Invert(matrix3x3 &matIn, matrix3x3 &matOut)
{
	float det = matIn.m[0][0] * (matIn.m[1][1] * matIn.m[2][2] - matIn.m[1][2] * matIn.m[2][1]) -
		matIn.m[1][0] * (matIn.m[0][1] * matIn.m[2][2] - matIn.m[2][1] * matIn.m[0][2]) +
		matIn.m[2][0] * (matIn.m[0][1] * matIn.m[1][2] - matIn.m[1][1] * matIn.m[0][2]);

	float idet = 1.0f / det;
	matOut.m[0][0] = (matIn.m[1][1] * matIn.m[2][2] - matIn.m[1][2] * matIn.m[2][1]) * idet;
	matOut.m[1][0] = (matIn.m[2][0] * matIn.m[1][2] - matIn.m[1][0] * matIn.m[2][2]) * idet;
	matOut.m[2][0] = (matIn.m[1][0] * matIn.m[2][1] - matIn.m[2][0] * matIn.m[1][1]) * idet;
	matOut.m[0][1] = (matIn.m[2][1] * matIn.m[0][2] - matIn.m[0][1] * matIn.m[2][2]) * idet;
	matOut.m[1][1] = (matIn.m[0][0] * matIn.m[2][2] - matIn.m[2][0] * matIn.m[0][2]) * idet;
	matOut.m[2][1] = (matIn.m[0][1] * matIn.m[2][0] - matIn.m[0][0] * matIn.m[2][1]) * idet;
	matOut.m[0][2] = (matIn.m[0][1] * matIn.m[1][2] - matIn.m[0][2] * matIn.m[1][1]) * idet;
	matOut.m[1][2] = (matIn.m[0][2] * matIn.m[1][0] - matIn.m[0][0] * matIn.m[1][2]) * idet;
	matOut.m[2][2] = (matIn.m[0][0] * matIn.m[1][1] - matIn.m[0][1] * matIn.m[1][0]) * idet;
}

void SpritesA::ChangeIAState() {
	float distanceEnemy = distanceBeetweenSprites(_enemy);
	distanceEnemy = floor(distanceEnemy - 19); 
	

			if (distanceEnemy >=25) {
				if (_timer->Steps(1))
				{
					_timer->StartChrono(); 
					//_actionByIA = SpritesA::AVANCER;
					_internalState = SpritesA::AVANCER;
					//setInternalState(2);
					
				}
			}
			else if( distanceEnemy < 25 ){

				if (mapOFAttack[ROAMING] == 2)
				{
					if (_timer->Steps(1.5))
					{

						if (mapOFAttack[ATTAQUEDEVANT] > 0)
						{
							mapOFAttack[ATTAQUEDEVANT] -= 1; 
							_timer->StartChrono();
							_internalState = SpritesA::ATTAQUEDEVANT;
							//setInternalState(16);
							initPosition(17, 0, 0, 17, 19, 3);
							return; 
						}
						else if (mapOFAttack[ROULADEA] > 0)
						{
							mapOFAttack[ROULADEA] -= 1;
							_timer->StartChrono();
							_internalState = SpritesA::ROULADEA;
							//setInternalState(16);
							initPosition(10, 0, 0, 10, 13, 2);
							return;
						}
						else if (mapOFAttack[ATTAQUEPIED] > 0) {
							mapOFAttack[ATTAQUEPIED] -= 1;
							_timer->StartChrono();
							_internalState = SpritesA::ATTAQUEPIED;
							//setInternalState(16);
							initPosition(28, 0, 0, 28, 29, 2);
							return;

						}
						else if (mapOFAttack[RECULER] > 0) {
							mapOFAttack[RECULER] -= 1;
							_timer->StartChrono();
							_internalState = SpritesA::RECULER;
							//setInternalState(16);
							initPosition(0, 0, 0, 1, 3, 3);
							return;

						}
						else if (mapOFAttack[ATTAQUETRANCHETETE] > 0) {
							mapOFAttack[ATTAQUETRANCHETETE] -= 1;
							_timer->StartChrono();
							_internalState = SpritesA::ATTAQUETRANCHETETE;
							//setInternalState(16);
							initPosition(37, 0, 0, 37, 40, 4);
							return;

						}
						else {
							reinitScriptIA(); 
							return; 
						}


					}
				}
				
			}
		
		

}

void SpritesA::setInternalState(int num) {
	int l = sizeof(_internalBoolState) / sizeof(*_internalBoolState);
	for (int i = 0; i < l; i++)
	{
		_internalBoolState[i] = false; 

	}

	_internalBoolState[num] = true; 
	return; 


}

void SpritesA::initLevelScriptIA() {
	mapOFAttack.insert(std::make_pair(ROAMING, 2));
	mapOFAttack.insert(std::make_pair(ATTAQUEDEVANT, 2));
	mapOFAttack.insert(std::make_pair(ROULADER, 1));
	mapOFAttack.insert(std::make_pair(GENOUX, 1));
	mapOFAttack.insert(std::make_pair(ATTAQUEPIED, 1));
	mapOFAttack.insert(std::make_pair(RECULER, 3));
	mapOFAttack.insert(std::make_pair(ATTAQUETRANCHETETE, 1));
	

}

void SpritesA::reinitScriptIA() {
	mapOFAttack[ATTAQUETRANCHETETE] = 1; 
	mapOFAttack[ROAMING] = 2;
		mapOFAttack[ATTAQUEDEVANT] = 2; 
		mapOFAttack[ROULADER] = 1; 
		mapOFAttack[GENOUX] = 1; 
		mapOFAttack[ATTAQUEPIED] = 1; 
		mapOFAttack[RECULER] = 3; 
		mapOFAttack[ATTAQUETRANCHETETE] = 1;

}
/*

else if (_internalState == PROTEGEH)
{
initPosition(9, 0, 0, 9, 9, 3);
//_internalState = SpritesA::PROTEGEH; //protege le corps
return;
}
else if (_internalState == PROTEGED)
{
initPosition(8, 0, 0, 8, 8, 3);
//_internalState = SpritesA::PROTEGED; //protege le corps
return;
}
else if (_internalState == AVANCER)
{
//_internalState = SpritesA::AVANCER;
initPosition(1, 0, 0, 1, 3, 3);
return;
}
else if (_internalState == RECULER)
{
//_internalState = SpritesA::RECULER;
initPosition(0, 0, 0, 1, 3, 3);
return;
}
else if (_internalState == SAUTER)
{
//_internalState = SpritesA::SAUTER;
initPosition(4, 0, 0, 4, 5, 2);
return;

}
else if (_internalState == GENOUX)
{
//_internalState = SpritesA::GENOUX;
initPosition(6, 0, 0, 6, 7, 2);
return;
}
else if (_internalState == ATTAQUETETE) {
//_internalState = SpritesA::ATTAQUETETE;
initPosition(26, 0, 0, 26, 27, 2);
return;
}
else if (_internalState ==ATTAQUEPIED) {
//_internalState = SpritesA::ATTAQUEPIED;
initPosition(28, 0, 0, 28, 29, 2);
return;
}
else if (_internalState == ROULADEA)
{
//_internalState = SpritesA::ROULADEA;
initPosition(10, 0, 0, 10, 13, 1);
return;
}
else if (_internalState == ROULADER)
{
//_internalState = SpritesA::ROULADER;
initPosition(10, 0, 0, 10, 13, 2);
return;
}
else if (_internalState == ATTAQUEDEVANT)
{

//_internalState = SpritesA::ATTAQUEDEVANT;
initPosition(17, 0, 0, 17, 19, 3);
return;

}
else if (_internalState == ATTAQUECOU) {
//_internalState = SpritesA::ATTAQUECOU;
initPosition(24, 0, 0, 24, 25, 2);
return;
}
else if (_internalState == ATTAQUEHAUT ) {
//_internalState = SpritesA::ATTAQUEHAUT;
initPosition(30, 0, 0, 30, 32, 3);
return;


}
else if (_internalState == ATTAQUEMOULINET) {
_internalState = SpritesA::ATTAQUEMOULINET;
initPosition(33, 0, 0, 33, 36, 4);
return;
}
else if (_internalState == ATTAQUETRANCHETETE) {
_internalState = SpritesA::ATTAQUETRANCHETETE;
initPosition(37, 0, 0, 37, 40, 4);
return;

}
else if (_internalState == ATTAQUEBASSE)
{
_internalState = SpritesA::ATTAQUEBASSE;
initPosition(41, 0, 0, 41, 43, 3);
return;
}
else if (_isWining)
{
_internalState = SpritesA::VAINQUEUR;
initPosition(44, 0, 0, 44, 46, 3);
return;
}
else
{

//_internalState = SpritesA::NORMAL;

NORMAL,0
RECULER,1
AVANCER,2
SAUTER,3
GENOUX,4
DESCENTE,5
PROTEGED,6
PROTEGEH,7
ROULADEA,8
ROULADER,9
TOMBE,10
ATTAQUEDEVANT,11
TOUCHE,12
ATTAQUECOU,13
ATTAQUETETE,14
ATTAQUEPIED,15
ATTAQUEHAUT,16
ATTAQUEMOULINET,17
ATTAQUETRANCHETETE,18
ATTAQUEBASSE,19
MORT, 20
VAINQUEUR,21
DECAPITE, 22
END, 23
ROAMING,24
}*/
