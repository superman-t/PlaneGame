#include "GameScene.h"

cocos2d::Scene* GameLayer::createScene() {
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	this->setTouchEnabled(true);
	Size winSize = Director::getInstance()->getWinSize();
	char buff[15];
	int id = getRand(1, 5);
	sprintf(buff, "img_bg_%d.jpg", id);
	auto over = Sprite::create(buff);
	over->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(over);
	return true;
}
int GameLayer::getRand(int start, int end) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long int rand_seed = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	srand(rand_seed);
	float i = CCRANDOM_0_1() * (end - start + 1) + start;
	return (int) i;
}

void GameLayer::onEnterTransitionDidFinish() {
	planeLayer = PlaneLayer::create();
	this->addChild(planeLayer);
	bulletSprite = BulletSprite::create();
	this->addChild(bulletSprite);
	enemyLayer = EnemyLayer::create();
	this->addChild(enemyLayer);

	this->schedule(schedule_selector(GameLayer::gameUpdate));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create("CloseNormal.png",
			"CloseSelected.png",
			CC_CALLBACK_1(GameLayer::menuCloseCallback, this));
	closeItem->setPosition(
			Point(
					origin.x + visibleSize.width
							- closeItem->getContentSize().width / 2,
					origin.y + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
}

void GameLayer::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
bool GameLayer::bulletCollisionEnemy(Sprite* pBullet) {
	for (auto& eEnemy : enemyLayer->vecEnemy) {
		EnemySprite* pEnemySprite = (EnemySprite*) eEnemy;
		if (pBullet->boundingBox().intersectsRect(
				pEnemySprite->getBoundingBox())) {
			if (1 == pEnemySprite->getLife()) {
				pEnemySprite->loseLife();
				enemyLayer->blowupEnemy(pEnemySprite);
			} else {
				pEnemySprite->loseLife();
			}
			bulletSprite->removeBullet(pBullet);
			return true;
		}
	}
	return false;
}

void GameLayer::gameUpdate(float dt) {
	bool bMoveButt = false;
	for (auto& eButtle : bulletSprite->vecBullet) {
		Sprite* pBullet = (Sprite*) eButtle;
		bMoveButt = bulletCollisionEnemy(pBullet);
		if (bMoveButt) {
			return;
		}
	}
	enemyCollisionPlane();
}

bool GameLayer::enemyCollisionPlane() {
	Sprite* pPlane = (Sprite*) planeLayer->getChildByTag(AIRPLANE);
	for (auto& eEnemy : enemyLayer->vecEnemy) {
		EnemySprite* pEnemySprite = (EnemySprite*) eEnemy;
		if (pPlane->boundingBox().intersectsRect(pEnemySprite->getBoundingBox())
				&& pEnemySprite->getLife() > 0) {
//			this->unscheduleAllSelectors();
			//	this->bulletLayer->StopBulletShoot();
			//	this->planeLayer->blowUp();
			return true;
		}
	}

	return false;
}
