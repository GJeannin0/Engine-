#include "p2Body.h"


p2Body::p2Body(sf::Vector2f iPos, sf::Vector2f iSpeed, float iMass, float iRadius)
{
	pos = iPos;
	speed = iSpeed;
	mass = iMass;

	p2Collider m_Collider(iRadius);
}

p2Body::p2Body()
{
}


p2Body::~p2Body()
{
}

float p2Body::GetMass()
{
	return mass;
}
sf::Vector2f p2Body::GetPos()
{
	return pos;
}
void p2Body::SetPos(sf::Vector2f nPos)
{
	pos = nPos;
}
sf::Vector2f p2Body::GetSpeed()
{
	return speed;
}
void p2Body::SetSpeed(sf::Vector2f nSpeed)
{
	speed = nSpeed;
}
float p2Body::GetRadius()
{
	return m_Collider.GetRadius();
}