#pragma once
#include "Game.h"
#include <math.h>
#include <map>


using namespace olc; 
struct matrix3x3; 
class IA; 

class SpritesA : public olc::PixelGameEngine
{
public : 
	int _hp; //reserve de vie on commence a 12
    int _chargeTime; //comptage du temps 
	enum StateMovement {NORMAL,RECULER,AVANCER,SAUTER,GENOUX, DESCENTE,PROTEGED, PROTEGEH, ROULADEA, ROULADER, TOMBE, ATTAQUEDEVANT, TOUCHE,ATTAQUECOU, ATTAQUETETE, ATTAQUEPIED, ATTAQUEHAUT, ATTAQUEMOULINET, ATTAQUETRANCHETETE, ATTAQUEBASSE, MORT, VAINQUEUR, DECAPITE, END, ROAMING};
	float _x; 
	float _offsetX; 
	float _animateHeadX; //pour la tete
	float _animateHeadY;
	float _y; 
	int _tickCount; 
	int _tickCountPerFrame; 
	int _index; 
	int _indexImage; 
	int _startFrame; //test pour les animations
	int _endFrame;
	int _numberFrame; 
	int _moveLength; 
	int _compteurIAAttack; 
	StateMovement _internalState; 
	StateMovement _oldInternalState;
	StateMovement _actionByIA; 
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
	bool _isAttack; 
	bool _isWining; 
	bool _internalBoolState[24]; 
	Timer* _timer; 
	IA* _internalIA; 
	int _level; 
	std::map<StateMovement, int> mapOFAttack;


public:
	SpritesA(); 
	SpritesA(int hp, olc::PixelGameEngine *pge);
	SpritesA(int hp, olc::PixelGameEngine *pge, float x, float y, bool isChangeColor ,bool isSensNormal ,  bool isIA , olc::Pixel color );
	void initPosition(int indexImage, int tickCount, int index, int startFrame, int endFrame, int numberFrame);
	void Init();
	void Update(float ElapsedTime);
	void DeplacementWithOutIA();
	void sensSpriteChange(int numFrame);
	void sensSpriteChange();
	void DeplacementWithIA();
	void Draw();
	void sensSpriteChange(olc::Sprite * currentSprite);
	void changeColorSprite(olc::Pixel color, olc::Sprite * currentSprite);
	bool isCollide(SpritesA * sp2);
	float distanceBeetweenSprites(SpritesA * sp2);
	void CheckAttack(StateMovement sm);

	void CheckIfDead();

	void Deplacement();
	void deleteFromVector(std::vector<olc::Sprite*> tabToClean);
	void animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index);
	void movingForward(int x); 
	void movingBackward(int x); 
	bool animateFrame(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending);

	bool animateFrameOne(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending);
	bool animateFrameOneDecapite(int tickCount, int beginFrame, int lastFrame, std::vector<olc::Sprite*> spritesFrame, int tickCountPerFrame, int index, bool isDescending);
	struct matrix3x3
	{
		float m[3][3];
	};
	void SpritesA::Identity(matrix3x3 & mat);

	void Reflection(matrix3x3 & mat);

	void Translate(matrix3x3 & mat, float ox, float oy);

	void Rotate(matrix3x3 & mat, float fTheta);

	void Scale(matrix3x3 & mat, float sx, float sy);

	void Shear(matrix3x3 & mat, float sx, float sy);

	void MatrixMultiply(matrix3x3 & matResult, matrix3x3 & matA, matrix3x3 & matB);

	void Forward(matrix3x3 & mat, float in_x, float in_y, float & out_x, float & out_y);

	void Invert(matrix3x3 & matIn, matrix3x3 & matOut);

	void ChangeIAState();

	void setInternalState(int num);

	void initLevelScriptIA();

	void reinitScriptIA();

	~SpritesA();
};

bool isCollide( SpritesA * sp2);



