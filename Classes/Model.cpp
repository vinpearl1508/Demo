#include "Model.h"

Model::Model()
{
}


Model::~Model()
{
}

void Model::SetPosition(cocos2d::Vec2 pos)
{
	this->mSprite->setPosition(pos);
}

cocos2d::Vec2 Model::GetPosition()
{
	return mSprite->getPosition();
}

void Model::SetAlive(bool alive)
{
	mIsAlive = alive;
	mSprite->setVisible(alive);
}

bool Model::IsAlive()
{
	return mIsAlive;
}
