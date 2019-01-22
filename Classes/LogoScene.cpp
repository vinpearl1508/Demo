#include "LogoScene.h"
#include "TitleScene.h"
#include "Defines.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}
bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create(IMG_LOGO);
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	auto loadingBarGB = Sprite::create(LOADINGBAR_GB);
	loadingBarGB->setColor(Color3B(0, 0, 0));
	loadingBarGB->setPosition(Vec2(SCREEN_W / 2, 50));
	addChild(loadingBarGB);
	static auto loadingbar = ui::LoadingBar::create(LOADINGBAR);
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());
	addChild(loadingbar);
	//update Loading Bar
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});
	auto sequenceRunUpdateLoadingBar =
		Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);

	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TitleScene::createScene());
	});
	auto sequence = Sequence::create(DelayTime::create(10), gotoNext,
		nullptr);
	runAction(sequence);

	return true;
}