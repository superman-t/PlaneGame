#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "PlaneLayer.h"
#include "BulletSprite.h"
#include "EnemyLayer.h"

USING_NS_CC;

enum EnBackground {
	e_BackgroundA = 1,
	e_BackgroundB = 2,
};

class GameLayer: public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	CREATE_FUNC(GameLayer);

public:
	void gameUpdate(float dt);
	bool bulletCollisionEnemy(Sprite* pBullet);
	bool enemyCollisionPlane();
	void menuCloseCallback(cocos2d::Ref* pSender);
public:
	PlaneLayer *planeLayer;
	BulletSprite *bulletSprite;
	EnemyLayer *enemyLayer;

	int getRand(int start, int end);
};

#endif // __HELLOWORLD_SCENE_H__
