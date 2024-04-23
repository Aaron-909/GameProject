#include "Shield.h"
#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "BoundingShape.h"
#include "Asteroids.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "BoundingSphere.h"

Shield::Shield(void) : GameObject("Shield")
{
	hitPoint = 1;
	isActive = false;
}

Shield::~Shield(void) 
{
}

/*bool Shield::ActivateShield()
{
	isActive = true;
	return isActive;
}

bool Shield::DeactivateShield()
{
	isActive = false;
	return isActive;
}*/

bool Shield::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Spaceship")) 
	{
		isActive = true;
		return false;
	}

	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Shield::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}
