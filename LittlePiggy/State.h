#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Leewee 2016
//
//------------------------------------------------------------------------

class AdorkablePig;

template<class entity_type>
class State
{
public:
	virtual ~State(){}

	virtual void Enter(entity_type*) = 0;
	virtual void Execute(entity_type*) = 0;
	virtual void Exit(entity_type*) = 0;
};

#endif
