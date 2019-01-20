#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	int mFrameCount;
	int mScore;
	cocos2d::Label *mScoreLabel;
};

#endif // __HELLOWORLD_SCENE_H__
