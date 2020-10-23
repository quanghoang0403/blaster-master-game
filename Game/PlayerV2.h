#pragma once
#include "Entity.h"
#include <map>
#include "Timer.h"

#define SOPHIA_WALKING_SPEED			0.1f 


//define HealthBar
#define MAX_HEALTH						8

#define SOPHIA_BIG_STATE_IDLE				0
#define SOPHIA_BIG_STATE_WALKING_RIGHT		100
#define SOPHIA_BIG_STATE_WALKING_LEFT		200
#define SOPHIA_BIG_STATE_DIE				300



#define SOPHIA_ANI_BIG_IDLE_RIGHT				0
#define SOPHIA_ANI_BIG_IDLE_LEFT				1
#define SOPHIA_ANI_BIG_IDLE_TOP					2
#define SOPHIA_ANI_BIG_IDLE_BOT					3

#define SOPHIA_ANI_BIG_WALKING_RIGHT			4
#define SOPHIA_ANI_BIG_WALKING_LEFT				5
#define SOPHIA_ANI_BIG_WALKING_TOP				6
#define SOPHIA_ANI_BIG_WALKING_BOT				7

#define SOPHIA_ANI_BIG_DIE						8

#define SOPHIA_BIG_BBOX_WIDTH		22
#define SOPHIA_BIG_BBOX_HEIGHT		32

//#define MARIO_UNTOUCHABLE_TIME 5000
#define PLAYER_IMMORTAL_DURATION	1000

class PlayerV2 : public Entity
{
	static PlayerV2* instance;

	int level;
	int untouchable;
	bool isImmortaling;
	DWORD untouchable_start;

	Timer* immortalTimer = new Timer(PLAYER_IMMORTAL_DURATION);

	float start_x;	
	float start_y;

public:
	PlayerV2(float x = 0.0f, float y = 0.0f);
	static PlayerV2* GetInstance();

	virtual void Update(DWORD dt, vector<LPGAMEENTITY>* colliable_objects = NULL);
	virtual void Render();

	//Immortal
	bool IsImmortaling() { return isImmortaling; }
	void SetImmortaling(bool immo) { isImmortaling = immo; }
	void StartImmortalingTimer() { immortalTimer->Start(); }

	void SetDirection(int d) { direction = d; }
	void SetState(int state);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void GetPositionCenter(float& x, float& y) { x = this->x + SOPHIA_BIG_BBOX_WIDTH / 2; y = this->y + SOPHIA_BIG_BBOX_HEIGHT / 2; }
	void Setvx(float vx) { vx = vx; }
	void Setvy(float vy) { vy = vy; }
	float GetDy() { return dy; }
	float Getvy() { return vy; }
	void Reset();
	void GetInfoForBullet(int& direct, float& playerx, float& playery) { direct = direction; playerx = x; playery = y; }

	void SetInjured(int dame);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};