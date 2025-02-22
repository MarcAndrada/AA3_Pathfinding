#include "Agent.h"
#include "FSM.h"
#include "PathFindingAlgorithm.h"
#include "PlayerManager.h"
using namespace std;

Agent::Agent(bool _isEnemy, float _maxForce, float _maxVelocity) : sprite_texture(0),
                 position(Vector2D(100, 100)),
	             target(Vector2D(1000, 100)),
	             velocity(Vector2D(0,0)),
	             currentTargetIndex(-1),
				 mass(0.1f),
				 max_force(_maxForce),
				 max_velocity(_maxVelocity),
				 orientation(0),
				 sprite_num_frames(0),
	             sprite_w(0),
	             sprite_h(0),
	             draw_sprite(false),
				 isEnemy(_isEnemy)
{
	sensorySystem = new SensorySystem();
	blackboard = new Blackboard();
	brain = new FSM();
}

Agent::~Agent()
{
	if (sprite_texture)
		SDL_DestroyTexture(sprite_texture);
	if (steering_behaviour)
		delete (steering_behaviour);
}

void Agent::setBehavior(SteeringBehavior *behavior)
{
	steering_behaviour = behavior;
}

Vector2D Agent::getPosition()
{
	return position;
}

Vector2D Agent::getTarget()
{
	return target;
}

Vector2D Agent::getVelocity()
{
	return velocity;
}

float Agent::getMaxVelocity()
{
	return max_velocity;
}

float Agent::getMaxForce()
{
	return max_force;
}

float Agent::getMass()
{
	return mass;
}

Blackboard* Agent::getBlackboard()
{
	return blackboard;
}

void Agent::setPosition(Vector2D _position)
{
	position = _position;
}

void Agent::setTarget(Vector2D _target)
{
	target = _target;
}

void Agent::setVelocity(Vector2D _velocity)
{
	velocity = _velocity;
}

void Agent::update(float dtime, SDL_Event *event)
{
	switch (event->type) {
		/* Keyboard & Mouse events */
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			sensorySystem->SetHasGun(!blackboard->GetData()->hasGun);
		break;
	default:
		break;
	}

	if (isEnemy) 
	{
		sensorySystem->Update(position, getVelocity(), PLAYER.GetPlayer()->getPosition() , dtime);
		blackboard->SetData(sensorySystem->GetData());
		brain->Update(this, dtime);
		std::cout << blackboard->GetData()->hasGun << std::endl;
	}
	steering_behaviour->applySteeringForce(this, dtime);
	
	// Update orientation
	if (velocity.Length())
		orientation = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);

	// Trim position values to window size
	if (position.x < 0) position.x = TheApp::Instance()->getWinSize().x;
	if (position.y < 0) position.y = TheApp::Instance()->getWinSize().y;
	if (position.x > TheApp::Instance()->getWinSize().x) position.x = 0;
	if (position.y > TheApp::Instance()->getWinSize().y) position.y = 0;


	algorithm->update(dtime);
}

void Agent::addPathPoint(Vector2D point)
{
	if (path.points.size() > 0)
		if (path.points[path.points.size() - 1] == point)
			return;

	path.points.push_back(point);
}

int Agent::getCurrentTargetIndex()
{
	return currentTargetIndex;
}

int Agent::getPathSize()
{
	return path.points.size();
}

Vector2D Agent::getPathPoint(int idx)
{
	return path.points[idx];
}

void Agent::clearPath()
{
	setCurrentTargetIndex(-1);
	path.points.clear();
}

void Agent::setCurrentTargetIndex(int idx)
{
	currentTargetIndex = idx;
}

void Agent::draw()
{
	// Path
	if (!isEnemy)
		algorithm->draw();

		for (int i = 0; i < (int)path.points.size(); i++)
		{
			if(!isEnemy)
				draw_circle(TheApp::Instance()->getRenderer(), (int)(path.points[i].x), (int)(path.points[i].y), 15, 255, 255, 0, 255);
			else
				draw_circle(TheApp::Instance()->getRenderer(), (int)(path.points[i].x), (int)(path.points[i].y), 15, 255, 0, 0, 255);
			if (i > 0)
				SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)(path.points[i - 1].x), (int)(path.points[i - 1].y), (int)(path.points[i].x), (int)(path.points[i].y));
		}
		

	if (draw_sprite)
	{
		Uint32 sprite;
		
		if (velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1*velocity.Length() + 250)) % sprite_num_frames;
		
		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation+90, &center, SDL_FLIP_NONE);
	}
	else 
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, 255, 255, 255, 255);
		SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x+15*cos(orientation*DEG2RAD)), (int)(position.y+15*sin(orientation*DEG2RAD)));
	}

	
	
}

bool Agent::loadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	sprite_num_frames = _num_frames;
	sprite_w = image->w / sprite_num_frames;
	sprite_h = image->h;
	draw_sprite = true;

	if (image)
		SDL_FreeSurface(image);

	return true;
}

void Agent::setAlgorithm(PathFindingAlgorithm* _algorithm)
{
	algorithm = _algorithm;
}

void Agent::setMaxSpeed(float _maxVelocity, float _maxForce)
{
	max_velocity = _maxVelocity;
	max_force = _maxForce;
}
