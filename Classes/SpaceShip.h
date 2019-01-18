#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__
#include "Model.h"
#include "SpaceShip.h"
#include "Bullet.h"
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
private:
	Bullet *bullet;
	vector<Bullet*> bullets;
};
#endif
