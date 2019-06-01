#pragma once

const int ENEMY1_MAXLIFE=3;
const int ENEMY2_MAXLIFE=5;
const int ENEMY3_MAXLIFE=10;

const int ENEMY1_SCORE=1;
const int ENEMY2_SCORE=6;
const int ENEMY3_SCORE=30;

enum Level
{
	EASY,
	MIDDLE,
	HARD,
	MOREHARD,
};

enum EnemyType
{
	Enemy1 = 1,
	Enemy2,
	Enemy3,
	Enemy4,
};
