#include "SpaceShip.h"
#include "Defines.h"
#include "Rock.h"


SpaceShip::SpaceShip(cocos2d::Scene *scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_SPACESHIP);
	mSprite->setContentSize(mSprite->getContentSize() / 2);
	scene->addChild(mSprite);
	SetAlive(true);
	SpaceShip::createEvent(scene);

	for (int i = 0; i < BULLET_MAX; i++) {
		bullet = new Bullet(scene);
		//bullet->Init();
		bullets.push_back(bullet);
	}
}


SpaceShip::~SpaceShip()
{
}

bool SpaceShip::Init()
{
	mFrameCount = 0;
	SetPosition(cocos2d::Vec2(SCREEN_W / 2, mSprite->getContentSize().height / 2));
	return true;
}

void SpaceShip::Update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if(!bullets.at(i)->IsAlive())
			bullets.at(i)->SetPosition(cocos2d::Vec2(mSprite->getPosition().x, mSprite->getPosition().y + mSprite->getContentSize().height / 2));
		bullets.at(i)->Update();
	}
	mFrameCount++;
	if (mFrameCount % 4 == 0) {
		for (int i = 0; i < bullets.size(); i++) {
			if (!bullets.at(i)->IsAlive()) {
				bullets.at(i)->Init();
				bullets.at(i)->SetAlive(true);
				break;
			}
		}
	}
}

void SpaceShip::createEvent(cocos2d::Scene *scene)
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SpaceShip::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SpaceShip::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SpaceShip::onTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);
}

bool SpaceShip::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event) {
	mDistanceToSpaceShip = touch->getLocation() - GetPosition();
	return true;
}

void SpaceShip::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event) {
	SetPosition(touch->getLocation() - mDistanceToSpaceShip);
}

void SpaceShip::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event) {
}

bool SpaceShip::Collision(Rock* rock)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets.at(i)->IsAlive())
		{
			auto rectRock = rock->GetRect();
			auto rectBull = bullets.at(i)->GetRect();
			if (rectBull.intersectsRect(rectRock))
			{
				return true;
			}
		}
	}
	return false;
}

bool SpaceShip::CollisionSpacewithRock(Rock* rock)
{
	auto rectRock = rock->GetRect();
	auto recSpace = GetRect();
	if (recSpace.intersectsRect(rectRock))
	{
		return true;
	}
	return false;
}