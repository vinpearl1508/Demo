#include "Rock.h"
#include "Defines.h"


Rock::Rock(cocos2d::Scene *scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_ROCK);
	scene->addChild(mSprite);
	SetAlive(false);
	SetStep(cocos2d::random(ROCK_MIN_STEP, ROCK_MAX_STEP));
}


Rock::~Rock()
{
}

bool Rock::Init()
{
	float x = cocos2d::random(mSprite->getContentSize().width, SCREEN_W - mSprite->getContentSize().width / 2);
	float y = SCREEN_H + mSprite->getContentSize().height / 2;
	SetPosition(cocos2d::Vec2(x, y));

	return true;
}

void Rock::Update()
{
	if (!IsAlive())
	{
		SetAlive(true);
		SetPosition(GetPosition() - cocos2d::Vec2(0, GetStep()));
	}
	else
	{
		SetPosition(GetPosition() - cocos2d::Vec2(0, GetStep()));
	}
}

void Rock::SetStep(int step)
{
	mStep = step;
}

int Rock::GetStep()
{
	return mStep;
}
