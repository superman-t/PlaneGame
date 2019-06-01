#include "main.h"
#include "../Classes/AppDelegate.h"

#include <iostream>
USING_NS_CC;
using namespace std;
int WINAPI _tWinMain(HINSTANCE hInstance,
                 HINSTANCE hPrevInstance,
                 LPTSTR    lpCmdLine,
                 int       nCmdShow)
{
	AppDelegate app;
	return Application::getInstance()->run();
}