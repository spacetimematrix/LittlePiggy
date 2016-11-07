#ifndef BASE_GAME_ENTITY_H
#define BASE_GAME_ENTITY_H
//------------------------------------------------------------------------
//
//  Name:   BaseGameEntity.h
//
//  Desc:   Base class for a game object
//
//  Author: Leewee 2016
//
//------------------------------------------------------------------------

class BaseGameEntity
{
private:
	int m_ID;
	static int m_iNextValidID;
	void SetID(int val);

public:
	BaseGameEntity(int id)
	{
		SetID(id);
	}

	virtual ~BaseGameEntity(){}

	virtual void Update()=0;

	int ID()const { return m_ID; }
};

#endif
