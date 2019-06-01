#include "BulletSprite.h"
#include "PlaneLayer.h"
BulletSprite::BulletSprite() {
}
BulletSprite::~BulletSprite() {
}
bool BulletSprite::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		Texture2D* texture = TextureCache::sharedTextureCache()->textureForKey("bullet.png");
		//创建BatchNode节点
		bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
		this->addChild(bulletBatchNode);
		//每隔0.2S调用一次发射子弹函数
		this->schedule(schedule_selector(BulletSprite::ShootBullet),0.2f);
		bRet = true;
	} while (0);
	return bRet;
}
void BulletSprite::ShootBullet(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto PlanePos = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithSpriteFrameName("bullet_1.png");
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);
	Point bulletPos = (Point(PlanePos.x,
					PlanePos.y
							+ PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height
									/ 2 + 20));
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.4f);

	float flyLen = winSize.height - PlanePos.y;
	float flyVelocity = 320 / 1;//运行速度，可以自己控制，每秒所走的像素
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间

	//子弹运行的距离和时间，从飞机处开始运行到屏幕顶端
	auto actionMove = MoveTo::create(realFlyDuration,
			Point(bulletPos.x, winSize.height));
	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(BulletSprite::removeBullet, this));

	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);

}
/**
 * 移除子弹，将子弹从容器中移除，同时也从SpriteBatchNode中移除
 */
void BulletSprite::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*) pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

/**
 * 从缓存中获取子弹动画图片后创建子弹动画，最终返回创建好的动画
 */
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

