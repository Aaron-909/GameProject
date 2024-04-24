#pragma once
#ifndef __ISHIELDLISTENER_H__
#define __ISHIELDLISTENER_H__

class IShieldListener
{
public:
	virtual void ActiveChanged(bool isActive) = false;
};

#endif
