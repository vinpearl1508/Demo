#ifndef __ROCK_H__
#define __ROCK_H__
#include "Model.h"
class Rock : public Model
{
public:
	Rock(cocos2d::Scene*);
	~Rock();

	virtual bool Init();
	virtual void Update();

	void SetStep(int);
	int GetStep();
private:
	int mStep;
};
#endif

