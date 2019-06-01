#include "AppDelegate.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs( glContextAttrs );
}


bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::createWithRect( "PlaneGame", Rect(0, 0, 320, 480));
		director->setOpenGLView( glview );
    }

	glview->setDesignResolutionSize( 320.0f, 480.0f, ResolutionPolicy::FIXED_WIDTH );

	std::vector<std::string> searchPath;
	searchPath.push_back( "Resources" );

	// set searching path
	FileUtils::getInstance()->setSearchPaths( searchPath );

    director->setDisplayStats(false);
    director->setAnimationInterval(1.0 / 60);
    auto scene = GameLayer::createScene();
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
