#include "BulletSprite.h"
#include "PlaneLayer.h"
BulletSprite::BulletSprite() {
}
BulletSprite::~BulletSprite() {
}
bool BulletSprite::init() {
	if (!Sprite::init()) {
		return false;
	}
	this->schedule(schedule_selector(BulletSprite::ShootBullet));
	return true;
}
void BulletSprite::ShootBullet(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos =
			PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	auto spritebullet = Sprite::createWithSpriteFrameName("bullet_1.png");
//	(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet_1.png"));
	this->addChild(spritebullet);
	auto self = f_createAnimate(2, 10);
	spritebullet->runAction(RepeatForever::create(Animate::create(self)));
	Point bulletPos =
			(Point(PlanePos.x,
					PlanePos.y
							+ PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height
									/ 2 + 20));
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.4f);
	vecBullet.pushBack(spritebullet);
	float flyLen = winSize.height - PlanePos.y;
	float flyVelocity = 320 / 1;
	float realFlyDuration = flyLen / flyVelocity;

	auto actionMove = MoveTo::create(realFlyDuration,
			Point(bulletPos.x, winSize.height));
	auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(BulletSprite::removeBullet, this));

	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);

}

void BulletSprite::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*) pNode;
	this->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

Animation* BulletSprite::f_createAnimate(int count, int fps) {
	char buff[16];
	Animation *panimation = Animation::create();
	panimation->setDelayPerUnit(1.0 / fps);
	for (int id = 1; id <= count; id++) {
		sprintf(buff, "bullet_%d.png", id);
		panimation->addSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	return panimation;
}

