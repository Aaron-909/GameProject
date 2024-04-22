#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"

class Shield : public GameObject 
{
public:
	Shield(void);
	~Shield(void);

	int hitPoint;

	void activateShield();
};






#endif