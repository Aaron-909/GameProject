#ifndef __ENEMYSHIP_H__
#define __ENEMYSHIP_H__

#include "GameUtil.h"
#include "GameObject.h"
#include "Shape.h"
#include "Shield.h"
#include "IKeyboardListener.h"
#include "IGameWorldListener.h"

class EnemyShip : public GameObject
{
public:
	EnemyShip();
	EnemyShip(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r);
	EnemyShip(const EnemyShip& s);
	virtual ~EnemyShip(void);

	virtual void Update(int t);
	virtual void Render(void);

	virtual void Thrust(float t);
	virtual void Rotate(float r);
	virtual void Shoot(void);

	void SetSpaceshipShape(shared_ptr<Shape> enemyship_shape) { mEnemyshipShape = enemyship_shape; }
	void SetThrusterShape(shared_ptr<Shape> thruster2_shape) { mThruster2Shape = thruster2_shape; }
	void SetBulletShape(shared_ptr<Shape> bullet2_shape) { mBullet2Shape = bullet2_shape; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

private:
	float mThrust;

	shared_ptr<Shape> mEnemyshipShape;
	shared_ptr<Shape> mThruster2Shape;
	shared_ptr<Shape> mBullet2Shape;
};

#endif
