#include "PigSprite.h"
#include "PlaneLayer.h"

PigSprite::PigSprite() {
}

PigSprite::~PigSprite() {
}

bool PigSprite::init() {
	if (!Sprite::init()) {
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	spritepig = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_01.png"));
	this->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(spritepig);
	//设置缩放倍数为0.6，也就是变为原来的0.6
	this->setScale(0.6);
	//穿件小猪飞行动画
	f_createAnimate(3, 8);
	//时间调度函数，使每一帧都调用f_followPlane函数来保持小猪在飞机周围
	this->schedule(schedule_selector(PigSprite::f_followPlane));
	return true;
}
/**
 * 获取飞机的位置信息，使小猪的位置始终在飞机周围，函数中判断是否到达边界，以更新小猪
 * 在飞机的左边还是右边
 */
void PigSprite::f_followPlane(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	if (PlanePos.x + 60 + spritepig->getContentSize().width <= winSize.width) {
		this->setPosition(Point(PlanePos.x + 60 + spritepig->getContentSize().width / 2,PlanePos.y));
	} else {
		this->setPosition(Point(PlanePos.x - 60 - spritepig->getContentSize().width / 2,PlanePos.y));
	}

}
/**
 * 创建小猪飞行的动画，count为帧动画的数量，fps为每帧的间隔时间，
 * RepeatForever创建无限重复动画，让spritepig来执行这个动画
 */
void PigSprite::f_createAnimate(int count, int fps) {
	char buff[16];
	Animation *panimation = Animation::create();
	panimation->setDelayPerUnit(1.0 / fps);
	for (int id = 1; id <= count; id++) {
		sprintf(buff, "hero_0%d.png", id);
		panimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	spritepig->runAction(RepeatForever::create(Animate::create(panimation)));

}

