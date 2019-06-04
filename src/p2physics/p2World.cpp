#include "p2World.h"



p2World::p2World()
{
}

p2World::p2World(sfge::Engine m_Engine,std::vector<bodySetting> bodiesSettings)
{
	for (int i = 0; i < bodiesSettings.size; i++)
	{
		//CreateEntity(m_Engine,(unsigned)i);
		bodies.push_back(
			p2Body()
		);
	}
}

p2World::~p2World()
{
}

void p2World::Step(std::vector<p2Body> bodies, float dt)
{
	std::vector<sf::Vector2f> speedChange;
	std::vector<sf::Vector2f> posChange;
	for (int i = 0; i < bodies.size; i++)
	{
		bodies[i].SetPos(bodies[i].GetPos + bodies[i].GetSpeed * dt);
		speedChange[i] = sf::Vector2f(0, 0);
		posChange[i] = sf::Vector2f(0, 0);
	}

	for (int i = 0; i < bodies.size-1; i++)
	{
		for (int j = i+1; j < bodies.size-1; j++)
		{
			if (CirclesContact(bodies[i].GetPos, bodies[j].GetPos, bodies[i].GetRadius, bodies[j].GetRadius))
			{
				//TODO Recut this with smaller functions on vectors

				sf::Vector2f collisionAxis = bodies[i].GetPos - bodies[j].GetPos;
				speedChange[i] =
									
					(bodies[i].GetSpeed.x*collisionAxis.x+ bodies[i].GetSpeed.y*collisionAxis.y)/
					(sqrtf(bodies[i].GetSpeed.x*bodies[i].GetSpeed.x + bodies[i].GetSpeed.y * bodies[i].GetSpeed.y)*sqrtf(collisionAxis.x*collisionAxis.x + collisionAxis.y * collisionAxis.y))*
									
					(sqrtf(bodies[i].GetSpeed.x*bodies[i].GetSpeed.x + bodies[i].GetSpeed.y * bodies[i].GetSpeed.y))
					
					+(bodies[j].GetMass/bodies[i].GetMass)*(bodies[j].GetSpeed.x*collisionAxis.x + bodies[j].GetSpeed.y*collisionAxis.y) /
					(sqrtf(bodies[j].GetSpeed.x*bodies[j].GetSpeed.x + bodies[j].GetSpeed.y * bodies[j].GetSpeed.y)*sqrtf(collisionAxis.x*collisionAxis.x + collisionAxis.y * collisionAxis.y));


				speedChange[j] =

					-(bodies[j].GetSpeed.x*collisionAxis.x + bodies[j].GetSpeed.y*collisionAxis.y) /
					(sqrtf(bodies[j].GetSpeed.x*bodies[j].GetSpeed.x + bodies[j].GetSpeed.y * bodies[j].GetSpeed.y)*sqrtf(collisionAxis.x*collisionAxis.x + collisionAxis.y * collisionAxis.y))*

					(sqrtf(bodies[j].GetSpeed.x*bodies[j].GetSpeed.x + bodies[j].GetSpeed.y * bodies[j].GetSpeed.y))

					-(bodies[i].GetMass / bodies[j].GetMass)*(bodies[i].GetSpeed.x*collisionAxis.x + bodies[i].GetSpeed.y*collisionAxis.y) /
					(sqrtf(bodies[i].GetSpeed.x*bodies[i].GetSpeed.x + bodies[i].GetSpeed.y * bodies[i].GetSpeed.y)*sqrtf(collisionAxis.x*collisionAxis.x + collisionAxis.y * collisionAxis.y));

				posChange[i] = ((bodies[i].GetRadius + bodies[j].GetRadius) - abs(sqrtf(((bodies[i].GetPos - bodies[j].GetPos).x)*((bodies[i].GetPos - bodies[j].GetPos).x) + ((bodies[i].GetPos - bodies[j].GetPos).y)*((bodies[i].GetPos - bodies[j].GetPos).y)))) * collisionAxis / sqrtf(collisionAxis.x*collisionAxis.x + collisionAxis.y * collisionAxis.y);
				posChange[j] = -posChange[i];
			}
		}
	}

	for (int i = 0; i < bodies.size; i++)
	{
		bodies[i].SetPos(bodies[i].GetPos + posChange[i]);
		bodies[i].SetSpeed(bodies[i].GetSpeed + speedChange[i]);
	}
}

bool p2World::CirclesContact(sf::Vector2f pos1, sf::Vector2f pos2, float radius1, float radius2)
{
	if (abs(radius1) + abs(radius2) >= abs(sqrtf(((pos1-pos2).x)*((pos1 - pos2).x)+((pos1 - pos2).y)*((pos1 - pos2).y))))
	{
		return true;
	}
	return false;
}

void p2World::CreateEntity(sfge::Engine m_Engine, unsigned wantedEntity)
{
	m_Engine.GetEntityManager()->CreateEntity(wantedEntity);
}