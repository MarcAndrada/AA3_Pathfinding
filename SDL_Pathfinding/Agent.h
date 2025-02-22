#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>

#include "SDL_SimpleApp.h"
#include "Path.h"
#include "utils.h"
#include "SensorySystem.h"
#include "Blackboard.h"

class FSM;
class PathFindingAlgorithm;

class Agent
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {};
	};
	
private:
	SteeringBehavior *steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;
	bool isEnemy;

	// Pathfinding
	Path path;
	int currentTargetIndex;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

	FSM* brain;
	SensorySystem *sensorySystem;
	Blackboard* blackboard;
	PathFindingAlgorithm* algorithm;

public:
	Agent(bool _isEnemy = false, float _maxForce = 150, float _maxVelocity = 200);
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	Blackboard* getBlackboard();
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void addPathPoint(Vector2D point);
	void setCurrentTargetIndex(int idx);
	int getCurrentTargetIndex();
	int getPathSize();
	Vector2D getPathPoint(int idx);
	void clearPath();
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);
	void setAlgorithm(PathFindingAlgorithm* _algorithm);
	PathFindingAlgorithm* getAlgorithm() { return algorithm; }
	void setMaxSpeed(float _maxVelocity, float _maxForce);
};