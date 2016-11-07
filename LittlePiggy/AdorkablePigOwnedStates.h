#ifndef ADORKABLEPIG_OWNED_STATES_H
#define ADORKABLEPIG_OWNED_STATES_H

#include "State.h"

class AdorkablePig;



//�ڹ�˾�ϰ� ׬Ǯ
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

//�ڼ�˯�� ���㾫��
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

//��С��Ǯ ��Ǯ
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



