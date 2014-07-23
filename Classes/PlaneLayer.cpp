#include "PlaneLayer.h"
#include "BulletSprite.h"

USING_NS_CC;
/**
 * 静态单例变量初始化
 */
PlaneLayer *PlaneLayer::sharedPlane = NULL;
/**
 * 创建场景，并添加PlaneLayer层
 */
Scene* PlaneLayer::createScene() {
	auto scene = Scene::create();
	auto layer = PlaneLayer::create();
	scene->addChild(layer);
	return scene;
}

/**
 * 创建层，并将创建的层赋值给单例变量
 */
PlaneLayer* PlaneLayer::create() {
	PlaneLayer *pRet = new PlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedPlane = pRet;//赋值给单例变量
		return pRet;
	} else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PlaneLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	/**
	 * 加载缓存类图片，图片用TexturePacker进行打包处理，
	 * 加载生成的plist文件，也即xml文件
	 * SpriteFrameCache缓存类会根据plist中的键值对应的图片进行加载并缓存到系统中
	 * 方便从缓存中获取相应图片
	 */
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("pig.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("wsparticle_p01.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("nplane.plist");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	//创建closemenu
	auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
			CC_CALLBACK_1(PlaneLayer::menuCloseCallback, this));

	closeItem->setPosition(Point(origin.x + visibleSize.width- closeItem->getContentSize().width / 2,
			origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	//调用创建精灵函数
	f_createSprite();
	return true;
}

/**
 * 创建飞机精灵，并添加小猪精灵，同时注册点击事件
 */
void PlaneLayer::f_createSprite() {
	Size winSize = Director::getInstance()->getWinSize();
	//创建飞机精灵
	auto plane = Sprite::create("mplane.png");
	plane->setTag(AIRPLANE);
	plane->setScale(0.7f);
	plane->setPosition(Point(winSize.width / 2 - plane->getContentSize().width / 2,winSize.height / 7));
	this->addChild(plane);
	//用先前实现的小猪类来创建小猪精灵，并添加到层中
	mp_pig = PigSprite::create();
	this->addChild(mp_pig);
	/**
	 * 注册点击响应事件
	 */
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);//不向下传递触摸事件
	touchListener->onTouchBegan = CC_CALLBACK_2(PlaneLayer::onTouchBegan, this);//触摸开始
	touchListener->onTouchMoved = CC_CALLBACK_2(PlaneLayer::onTouchMoved, this);//触摸移动
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,plane);//飞机精灵注册触摸事件
}

/**
 * 触摸开始事件，
 * 主要设置飞机移动到触摸的位置
 */
void PlaneLayer::onTouchMoved(Touch *touch, Event *pEvent) {
	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
	target->setPosition(touch->getLocation());
}

/**
 * 触摸移动事件，飞机跟随手指的移动进行移动到相应位置
 */
bool PlaneLayer::onTouchBegan(Touch* touch, Event* pEvent) {
	auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	target->setPosition(touch->getLocation());
	return true;
}

/**
 * closemenu回调函数，结束游戏
 */
void PlaneLayer::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
