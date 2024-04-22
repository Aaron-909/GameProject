#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"

class Shield : public GameObject 
{
public:
	Shield(void);
	~Shield(void);

	int hitPoint;
	bool isActive;

	bool activateShield();
	bool DeactivateShield();

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};






#endif