#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"
#include "Spaceship.h"

class Shield : public GameObject 
{
public:
	Shield(void);
	~Shield(void);

	int hitPoint;
	
	//Controller for the shield status
	bool IsActive()const { return isActive; }
	void SetActive(bool active) { isActive = active; }


	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

private:
	bool isActive;
};

#endif