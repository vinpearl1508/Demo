#include "SpaceShip.h"
#include "Defines.h"


SpaceShip::SpaceShip(cocos2d::Scene *scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_SPACESHIP);
	mSprite->setContentSize(mSprite->getContentSize() / 2);
	scene->addChild(mSprite);
	SetAlive(true);
	SpaceShip::createEvent(scene);
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
	/*if (touch->getLocation().x <= SCREEN_W - mSprite->getContentSize().width / 2
		&& touch->getLocation().x >= mSprite->getContentSize().width / 2
		&& touch->getLocation().y <= SCREEN_H - mSprite->getContentSize().height / 2
		&& touch->getLocation().y >= mSprite->getContentSize().height / 2) {
		mSprite->setPosition(cocos2d::Vec2(touch->getLocation()));
	}*/
	SetPosition(touch->getLocation() - mDistanceToSpaceShip);
}
void SpaceShip::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event) {
}