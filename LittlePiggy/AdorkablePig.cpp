#include "AdorkablePig.h"
#include "AdorkablePigOwnedStates.h"

#include <cassert>



AdorkablePig::AdorkablePig(int id):BaseGameEntity(id),
m_iMoneyInBody(0),
m_iTired(0),
m_location(home),
m_pCurrentState(SleepInHome::Instance()){}


//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void AdorkablePig::ChangeState(State<AdorkablePig>* pNewState)
{
	assert(m_pCurrentState && pNewState);

	m_pCurrentState->Exit(this);

	m_pCurrentState = pNewState;

	m_pCurrentState->Enter(this);
}

//-----------------------------------------------------------------------------
void AdorkablePig::AddMoney(const int val)
{
	m_iMoneyInBody += val;

	if (m_iMoneyInBody <= 0)
	{
		m_iMoneyInBody = 0;
	}
}

//-----------------------------------------------------------------------------
void AdorkablePig::GiveMoney(const int val)
{
	m_iMoneyInBody -= val;

	if (m_iMoneyInBody <= 0)
	{
		m_iMoneyInBody = 0;
	}
}

//-----------------------------------------------------------------------------
void AdorkablePig::Update()
{
	IncreaseTired();

	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}