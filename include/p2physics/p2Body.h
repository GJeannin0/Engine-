#pragma once
#include <SFML/System/Vector2.hpp>
#include "p2Collider.h"
#include "p2AABB.h"

class p2Body
{
	sf::Vector2f pos;
	sf::Vector2f speed;
	float mass;
	p2Collider m_Collider;
	// p2AABB m_AABB;

public:
	
	float GetRadius();
	float GetMass();

	sf::Vector2f GetPos();
	void SetPos(sf::Vector2f nPos);
	sf::Vector2f GetSpeed();
	void SetSpeed(sf::Vector2f nSpeed);

	p2Body();
	p2Body(sf::Vector2f iPos,sf::Vector2f iSpeed,float iMass, float iRadius);
	void p2Body::SetSpeed();

	p2Body();
	~p2Body();
};

