#ifndef __PLANE_LAYER_H__
#define __PLANE_LAYER_H__

#include "cocos2d.h"
#include "PigSprite.h"
USING_NS_CC;

enum Enum_Plane {
	AIRPLANE = 1,
};

class PlaneLayer: public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();//创建场景，返回所创建的场景
	virtual bool init();//init初始化函数
	void menuCloseCallback(cocos2d::Ref* pSender);//menu回调函数
	static PlaneLayer* create();//create静态函数，在其中设置单例，并调用init方法
public:
	PigSprite *mp_pig;//跟随的小猪精灵
	static PlaneLayer* sharedPlane;//全局单例标志，以此来返回单例
	void f_createSprite();//创建飞机精灵函数
public:
	bool onTouchBegan(Touch* touch, Event* pEvent);//点击开始事件响应函数
	void onTouchMoved(Touch *touch, Event *pEvent);//点击移动事件响应函数
};

#endif // __HELLOWORLD_SCENE_H__
