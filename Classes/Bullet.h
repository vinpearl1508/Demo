#ifndef __BULLET_H__
#define __BULLET_H__
#include "Model.h"
class Bullet :
	public Model
{
public:
	Bullet(cocos2d::Scene*);
	~Bullet();

	virtual bool Init();
	virtual void Update();

	void SetStep(int);
	int GetStep();
private:
	int mStep;
};
#endif