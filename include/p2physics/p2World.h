#pragma once
#include "p2Body.h"
#include "vector"
#include "p2Collider.h"
#include "engine/entity.h"
#include "engine/engine.h"

struct bodySetting
{
	// bodyType // Kinetic dynamic static  

	sf::Vector2f setPos;
	sf::Vector2f setSpeed;
	float setMass;

	// shape // Circle or Rectangle

	float setRadius; // used for circle

	// float lenght; // used for rectangles
	// float height;
};
class p2World
{
	float gravity;
	std::vector<p2Body> bodies;

public:
	p2World(sfge::Engine m_Engine, std::vector<bodySetting> bodiesSettings);
	void Step(std::vector<p2Body> bodies, float dt);
	void CreateEntity(sfge::Engine m_Engine,unsigned wantedEntity);
	bool CirclesContact(sf::Vector2f pos1, sf::Vector2f pos2, float radius1, float radius2);

	p2World();
	~p2World();
};

