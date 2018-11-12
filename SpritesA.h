#pragma once
#include "Game.h"
#include <math.h>

using namespace olc; 

class SpritesA : public olc::PixelGameEngine
{
public : 
	int _hp; //reserve de vie on commence a 12
    int _chargeTime; //comptage du temps 
	enum StateMovement {NORMAL,RECULER,AVANCER,SAUTER,GENOUX, DESCENTE,PROTEGED, PROTEGEH, ROULADEA, ROULADER, TOMBE, ATTAQUEDEVANT, TOUCHE};
	float _x; 
	float _y; 
	int _tickCount; 
	int _tickCountPerFrame; 
	int _index; 
	int _indexImage; 
	int _startFrame; //test pour les animations
	int _endFrame;
	int _numberFrame; 
	int _moveLength; 
	StateMovement _internalState; 
	StateMovement _oldInternalState;
	olc::PixelGameEngine *_pge;
	std::vector<std::string> imagesAVANCE;
	std::vector<olc::Sprite*> spritesAVANCE;
	olc::Sprite* _currentSprite; 
	bool isStarted; 
	bool _sensNormal; 
	bool _isIA; 
	bool _isChangeColor; 
	olc::Sprite* _spriteTranspose; 
	olc::Pixel _color; 
	olc::Pixel _standartColor; 
	SpritesA* _enemy; 
	float _distanceBetweenEnemy; 
	bool _isFalling; 
	bool _oldIsFalling; 
	bool _oldIstuching; 
	bool _isAlive; 
	bool _isTouch; 
	bool _isDecapit; 
	Timer* _timer; 



	


public:
	SpritesA(); 
	SpritesA(int hp, olc::PixelGameEngine *pge);
	SpritesA(int hp, olc::PixelGameEngine *pge, float x, float y, bool isChangeColor ,bool isSensNormal ,  bool isIA , olc::Pixel color );
	void initPosition(int indexImage, int tickCount, int index, int startFrame, int endFrame, int numberFrame);
	void Init();
	void Update(float ElapsedTime);
	void DeplacementWithOutIA();
	void DeplacementWithIA();
	void Draw();
	void sensSpriteChange(olc::Sprite * currentSprite);
	void changeColorSprite(olc::Pixel color, olc::Sprite * currentSprite);
	bool isCollide(SpritesA * sp2);
	float distanceBeetweenSprites(SpritesA * sp2);
	void Deplacement();
	void deleteFromVector(std::vector<olc::Sprite*> tabToClean);
	void animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index);
	void movingForward(int x); 
	void movingBackward(int x); 
	bool animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending);

	bool animateFrameOne(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending);
	

	~SpritesA();
};

bool isCollide( SpritesA * sp2);
