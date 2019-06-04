#pragma once
#include <Graphics/shape2d.h>

enum class ColliderType
{
	CIRCLE,
	NONE,
	// RECTANGLE,
};

class p2Collider
{
	ColliderType colliderType;
	float radius;
	
	// float bottomRight;
	// float topLeft;

	sfge::Shape m_shape;

public:

	float GetRadius();
	p2Collider();
	p2Collider(float iRadius);

	p2Collider();
	~p2Collider();
};

