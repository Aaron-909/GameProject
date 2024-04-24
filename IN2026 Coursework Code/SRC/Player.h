#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameUtil.h"

#include "GameObject.h"
#include "GameObjectType.h"
#include "IPlayerListener.h"
#include "IGameWorldListener.h"
#include "Shield.h"
#include "Spaceship.h"

class Shield;

class Player : public IGameWorldListener
{
public:
	Player() { mLives = 3; mShield = make_shared<Shield>();}
	virtual ~Player() {}


	void OnWorldUpdated(GameWorld* world) {}

	void OnObjectAdded(GameWorld* world, shared_ptr<GameObject> object) {}

	void OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object)
	{

		if (object->GetType() == GameObjectType("Spaceship"))
		{
			
			if (!mShield->IsActive())
			{
				mLives -= 1;
				FirePlayerKilled();
			}
			else 
			{ 
				FirePlayerKilled();
				mShield->SetActive(false);
			}
			
		}

		if (object->GetType() == GameObjectType("Shield")) 
		{
			mShield->SetActive(true);
		}
		
		
	}

	void AddListener(shared_ptr<IPlayerListener> listener)
	{
		mListeners.push_back(listener);
	}

	void FirePlayerKilled()
	{
		// Send message to all listeners
		for (PlayerListenerList::iterator lit = mListeners.begin();
			lit != mListeners.end(); ++lit) {
			(*lit)->OnPlayerKilled(mLives);
		}
	}

private:
	int mLives;

	typedef std::list< shared_ptr<IPlayerListener> > PlayerListenerList;

	PlayerListenerList mListeners;

	shared_ptr<Shield> mShield;

};

#endif
