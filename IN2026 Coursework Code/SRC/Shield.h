#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"

class Shield : public GameObject 
{
public:
	Shield(void);
	~Shield(void);

	bool isActive;
	
	//Controller for the shield status
	bool IsActive()const { return isActive; }
	void SetActive(bool active) { isActive = active; }


	bool CollisionTest(shared_ptr<GameObject> o) override;
	void OnCollision(const GameObjectList& objects) override;

private:
	
	
};

#endif