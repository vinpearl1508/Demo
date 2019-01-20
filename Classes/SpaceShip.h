#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__
#include "Model.h"
#include "SpaceShip.h"
#include "Bullet.h"
#include "Rock.h"
#include <vector>
using namespace std;
class SpaceShip :
	public Model
{
public:
	SpaceShip(cocos2d::Scene*);
	~SpaceShip();

	virtual bool Init();
	virtual void Update();

	void createEvent(cocos2d::Scene*);
	bool SpaceShip::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	void SpaceShip::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	void SpaceShip::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	bool Collision(Rock*);	bool CollisionSpacewithRock(Rock*);
private:
	cocos2d::Vec2 mDistanceToSpaceShip;
	Bullet *bullet;
	vector<Bullet*> bullets;
	int mFrameCount;
};
#endif
