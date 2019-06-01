#include "EnemySprite.h"

EnemySprite::EnemySprite() {
}

EnemySprite::~EnemySprite() {
}

/**
 * 根据敌机类型来创建不同的敌机
 */
void EnemySprite::setEnemyByType(EnemyType enType) {
	switch (enType) {
	case Enemy1:
		pEnemySprite = Sprite::createWithSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"n1.png"));
		nLife = ENEMY1_MAXLIFE;
		break;
	case Enemy2:
		pEnemySprite = Sprite::createWithSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"n2.png"));
		nLife = ENEMY2_MAXLIFE;
		break;
	case Enemy3:
		pEnemySprite = Sprite::createWithSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"n3.png"));
		nLife = ENEMY2_MAXLIFE;
		break;
	case Enemy4:
		pEnemySprite = Sprite::createWithSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(
						"n_boss.png"));
		nLife = ENEMY3_MAXLIFE;
		break;
	default:
		return;
		break;
	}

	this->addChild(pEnemySprite);
	pEnemySprite->setScale(0.6f);
	Size winSize = Director::getInstance()->getWinSize();
	Size enemySize = pEnemySprite->getContentSize();
	//设置敌机随机出现的位置
	int minX = enemySize.width / 2;
	int maxX = winSize.width - enemySize.width / 2;
	int rangeX = maxX - minX;
	int actualX = (rand() % rangeX) + minX;

	this->setPosition(Point(actualX, winSize.height + enemySize.height / 2));
}

bool EnemySprite::init() {
	bool pRet = true;
	if (!Node::init()) {
		pRet = false;
	}
	return pRet;
}
/**
 * 取得创建的敌机精灵
 */
Sprite* EnemySprite::getSprite() {
	return pEnemySprite;
}
/**
 * 取得生命值
 */
int EnemySprite::getLife() {
	return nLife;
}
/**
 * 生命值减少，每次被击中家少0.5
 */
void EnemySprite::loseLife() {
	nLife = nLife - 0.5;
}
/**
 * 取得现在的位置
 */
Point EnemySprite::getcurPoint() {
	return this->getPosition();
}

/**
 * 获取外包装矩形
 */
Rect EnemySprite::getBoundingBox() {
	Rect rect = pEnemySprite->boundingBox();
	Point pos = this->convertToWorldSpace(rect.origin);
	Rect enemyRect(pos.x, pos.y, rect.size.width, rect.size.height);
	return enemyRect;
}

