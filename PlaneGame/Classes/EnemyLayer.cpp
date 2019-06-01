#include "EnemyLayer.h"

EnemyLayer::EnemyLayer() {
}

EnemyLayer::~EnemyLayer() {
}
int EnemyLayer::m_score = 0;
bool EnemyLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	cocos2d::Vector<SpriteFrame*> vecTemp;
	vecTemp.clear();

	char buff[16];
	Animation* pAnimation1 = Animation::create();
	pAnimation1->setDelayPerUnit(0.1f);
	for (int id = 1; id <= 8; id++) {
		sprintf(buff, "a_00%d.png", id);
		pAnimation1->addSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	AnimationCache::getInstance()->addAnimation(pAnimation1, "Enemy1Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy1), 1.0f);

	vecTemp.clear();
	for (int id = 1; id <= 8; id++) {
		sprintf(buff, "b_00%d.png", id);
		vecTemp.pushBack(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}

	Animation *pAnimation2 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation2->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation2, "Enemy2Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy2), 3.0f);

	vecTemp.clear();
	for (int id = 1; id <= 9; id++) {
		sprintf(buff, "d_0000%d.png", id);
		vecTemp.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));
	}
	Animation *pAnimation3 = Animation::createWithSpriteFrames(vecTemp);
	pAnimation3->setDelayPerUnit(0.1f);
	AnimationCache::getInstance()->addAnimation(pAnimation3, "Enemy3Blowup");

	this->schedule(schedule_selector(EnemyLayer::addEnemy3), 7.0f);
	return true;
}

void EnemyLayer::addEnemy1(float dt) {
	EnemySprite *pEnemySprite = EnemySprite::create();
	pEnemySprite->setEnemyByType(Enemy1);
	pEnemySprite->setTag(Enemy1);
	this->addChild(pEnemySprite);
	vecEnemy.pushBack(pEnemySprite);
	auto actionMove = MoveTo::create(4.0f,Point(pEnemySprite->getPositionX(),0 - pEnemySprite->getSprite()->getContentSize().height/ 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq1 = Sequence::create(actionMove, actionDone, NULL);
	pEnemySprite->runAction(seq1);
}

void EnemyLayer::addEnemy2(float dt) {
	EnemySprite *pEnemySprite = EnemySprite::create();
	pEnemySprite->setEnemyByType(Enemy2);
	pEnemySprite->setTag(Enemy2);
	this->addChild(pEnemySprite);
	vecEnemy.pushBack(pEnemySprite);

	auto actionMove = MoveTo::create(5.5f,Point(pEnemySprite->getPositionX(),0 - pEnemySprite->getSprite()->getContentSize().height / 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq2 = Sequence::create(actionMove, actionDone, NULL);
	pEnemySprite->runAction(seq2);
}

void EnemyLayer::addEnemy3(float dt) {
	EnemySprite *pEnemySprite = EnemySprite::create();
	pEnemySprite->setEnemyByType(Enemy3);
	pEnemySprite->setTag(Enemy3);
	this->addChild(pEnemySprite);
	vecEnemy.pushBack(pEnemySprite);

	auto actionMove = MoveTo::create(7.0f,
			Point(pEnemySprite->getPositionX(),0 - pEnemySprite->getSprite()->getContentSize().height / 2));
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::removeEnemy, this));
	auto seq3 = Sequence::create(actionMove, actionDone, NULL);
	pEnemySprite->runAction(seq3);
}

void EnemyLayer::removeEnemy(Node *pNode) {
	EnemySprite* enemy = (EnemySprite*) pNode;
	if (enemy != NULL) {
		this->removeChild(enemy, true);
		vecEnemy.eraseObject(enemy);
	}
}

void EnemyLayer::blowupEnemy(EnemySprite* pEnemySprite) {
	Animation *pAnimation = NULL;
	Sprite *pmsprite = NULL;
	char *buff = NULL;
	if (Enemy1 == pEnemySprite->getTag()) {
		buff = "a_001.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy1Blowup");
		setScore(ENEMY1_SCORE);
	} else if (Enemy2 == pEnemySprite->getTag()) {
		buff = "b_001.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy2Blowup");
		setScore(ENEMY2_SCORE);
	} else if (Enemy3 == pEnemySprite->getTag()) {
		buff = "d_00001.png";
		pAnimation = AnimationCache::getInstance()->getAnimation("Enemy3Blowup");
		setScore(ENEMY3_SCORE);
	} else {
		return;
	}
	pmsprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buff));

	Point newPos = pEnemySprite->getcurPoint();
	Animate *pAnimate = Animate::create(pAnimation);
	pmsprite->setPosition(newPos);
	this->addChild(pmsprite);

	CallFuncN* mactiondone = CallFuncN::create(CC_CALLBACK_0(EnemyLayer::f_removemyAnimation, this, pmsprite));
	auto seq = Sequence::create(pAnimate, mactiondone, NULL);
	pmsprite->runAction(seq);
	removeEnemy(pEnemySprite);
	updateScore(m_score);
}

void EnemyLayer::f_removemyAnimation(Node *pNode) {
	Sprite *sp = (Sprite *) pNode;
	this->removeChild(sp);
}
void EnemyLayer::setScore(int nScore) {
	m_score += nScore;
}
int EnemyLayer::getScore() {
	return m_score;
}
void EnemyLayer::updateScore(int score) {
}


