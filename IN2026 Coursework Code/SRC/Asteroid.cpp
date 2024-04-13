#include <stdlib.h>
#include "GameUtil.h"
#include "Asteroid.h"
#include "BoundingShape.h"
#include "Asteroids.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "BoundingSphere.h"


Asteroid::Asteroid(void) : GameObject("Asteroid")
{
	mAngle = rand() % 360;
	mRotation = 0; // rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD*mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD*mAngle);
	mVelocity.z = 0.0;
}

Asteroid::~Asteroid(void)
{
}

bool Asteroid::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Asteroid::SplitAsteroid() {

	for (uint i = 0; i < 2; i++)
	{
		Animation* anim_ptr = AnimationManager::GetInstance().GetAnimationByName("asteroid1");
		shared_ptr<Sprite> asteroid_sprite
			= make_shared<Sprite>(anim_ptr->GetWidth(), anim_ptr->GetHeight(), anim_ptr);
		asteroid_sprite->SetLoopAnimation(true);
		shared_ptr<GameObject> small_asteroid = make_shared<Asteroid>();
		small_asteroid->SetBoundingShape(make_shared<BoundingSphere>(small_asteroid->GetThisPtr(), 10.0f));
		small_asteroid->SetSprite(asteroid_sprite);
		small_asteroid->SetScale(0.1f);
		mWorld->AddObject(small_asteroid);
	}
}

void Asteroid::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());

	// Check if the collided object is a bullet
	for (const auto& obj : objects) {
		if (obj->GetType() == GameObjectType("Bullet")) {
			// Split the asteroid only if the collided object is a bullet
			SplitAsteroid();
			return; // Exit the method to prevent creating new asteroids
		}
	}
}
