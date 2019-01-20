#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"
#include "Rock.h"
#include "Bullet.h"
#include "SpaceShip.h"
#include <vector>
using namespace std;
USING_NS_CC;
Rock *rock;
vector<Rock*> rocks;
SpaceShip *spaceShip;
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create(IMG_BG);
	background->setContentSize(visibleSize);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	for (int i = 0; i < ROCK_MAX; i++) {
		rock = new Rock(this);
		rock->Init();
		rocks.push_back(rock);
	}

	spaceShip = new SpaceShip(this);
	spaceShip->Init();
	
	scheduleUpdate();
	
    return true;
}

void HelloWorld::update(float delta)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		rocks.at(i)->Update();
	}

	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks.at(i)->IsAlive())
		{
			if (spaceShip->Collision(rocks.at(i)))
			{
				rocks.at(i)->SetAlive(false);
			}
			if (spaceShip->CollisionSpacewithRock(rocks.at(i)))
			{
				rocks.at(i)->SetAlive(false);
				CCLOG("Die");
			}
		}
	}
	
	mFrameCount++;
	if (mFrameCount % 4 == 0) {
		for (int i = 0; i < rocks.size(); i++) {
			if (!rocks.at(i)->IsAlive()) {
				rocks.at(i)->Init();
				rocks.at(i)->SetAlive(true);
				break;
			}
		}
	}
	spaceShip->Update();
}