#include "Bullet.h"
#include "Defines.h"


Bullet::Bullet(cocos2d::Scene *scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_BULLET);
	scene->addChild(mSprite);
	SetAlive(false);
	SetStep(BULLET_SHOOTING_STEP);
}


Bullet::~Bullet()
{
}

bool Bullet::Init()
{
	SetPosition(cocos2d::Vec2(SCREEN_W / 2, mSprite->getContentSize().height / 2));
	return true;
}

void Bullet::Update()
{
	if (!IsAlive())
	{
		SetAlive(true);
		SetPosition(GetPosition() + cocos2d::Vec2(0, GetStep()));
	}
	else
	{
		SetPosition(GetPosition() + cocos2d::Vec2(0, GetStep()));
	}
}

void Bullet::SetStep(int step)
{
	mStep = step;
}

int Bullet::GetStep()
{
	return mStep;
}
