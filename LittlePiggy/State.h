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

class State
{
public:
	virtual ~State(){}

	virtual void Enter(AdorkablePig*) = 0;
	virtual void Execute(AdorkablePig*) = 0;
	virtual void Exit(AdorkablePig*) = 0;
};

#endif
