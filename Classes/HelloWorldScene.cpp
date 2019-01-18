#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Defines.h"
#include "Rock.h"
#include <vector>
using namespace std;
USING_NS_CC;
Rock *rock;
vector<Rock*> rocks;
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

	for (int i = 0; i < ROCK_MAX; i++) {
		rock = new Rock(this);
		rock->Init();
		rocks.push_back(rock);
	}

	scheduleUpdate();
	
    return true;
}

void HelloWorld::update(float delta)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		rocks.at(i)->Update();
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
}