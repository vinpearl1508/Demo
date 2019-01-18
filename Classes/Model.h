#pragma once
#include "cocos2d.h"
class Model
{
public:
	Model();
	~Model();

	virtual bool Init() = 0;
	virtual void Update() = 0;

	void SetPosition(cocos2d::Vec2);
	cocos2d::Vec2 GetPosition();
	void SetAlive(bool);
	bool IsAlive();
protected:
	cocos2d::Sprite *mSprite;
	bool mIsAlive;
};

