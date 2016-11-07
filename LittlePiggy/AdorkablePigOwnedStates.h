#ifndef ADORKABLEPIG_OWNED_STATES_H
#define ADORKABLEPIG_OWNED_STATES_H

#include "State.h"

class AdorkablePig;



//在公司上班 赚钱
class WorkInCompany : public State
{
private:
	WorkInCompany() {}

	WorkInCompany(const WorkInCompany&);
	WorkInCompany& operator=(const WorkInCompany&); 
public:
	static WorkInCompany* Instance();

	virtual void Enter(AdorkablePig* pAdorkablePig);
	virtual void Execute(AdorkablePig* pAdorkablePig);
	virtual void Exit(AdorkablePig* pAdorkablePig);
};

//在家睡觉 养足精神
class SleepInHome : public State
{
private:
	SleepInHome() {}

	SleepInHome(const SleepInHome&);
	SleepInHome& operator=(const SleepInHome&);
public:
	static SleepInHome* Instance();

	virtual void Enter(AdorkablePig* pAdorkablePig);
	virtual void Execute(AdorkablePig* pAdorkablePig);
	virtual void Exit(AdorkablePig* pAdorkablePig);
};

//给小猪钱 花钱
class GiveMoneyInBank : public State
{
private:
	GiveMoneyInBank() {}

	GiveMoneyInBank(const GiveMoneyInBank&);
	GiveMoneyInBank& operator=(const GiveMoneyInBank&);
public:
	static GiveMoneyInBank* Instance();

	virtual void Enter(AdorkablePig* pAdorkablePig);
	virtual void Execute(AdorkablePig* pAdorkablePig);
	virtual void Exit(AdorkablePig* pAdorkablePig);
};

#endif



