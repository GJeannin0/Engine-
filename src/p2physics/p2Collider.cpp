#include "p2Collider.h"



p2Collider::p2Collider(float iRadius)
{
	colliderType = ColliderType::CIRCLE;
	radius = iRadius;

	sfge::Shape m_shape();

}

p2Collider::p2Collider()
{
}

p2Collider::~p2Collider()
{
}

float p2Collider::GetRadius()
{
	return radius;
}
