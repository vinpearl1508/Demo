#include "SpaceShip.h"
#include "Defines.h"


SpaceShip::SpaceShip(cocos2d::Scene *scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_SPACESHIP);
	scene->addChild(mSprite);
	SetAlive(true);
}


SpaceShip::~SpaceShip()
{
}

bool SpaceShip::Init()
{
	SetPosition(cocos2d::Vec2(SCREEN_W / 2, mSprite->getContentSize().height / 2));
	return true;
}

void SpaceShip::Update()
{
}
