#ifndef ADORKABLE_PIG_H
#define ADORKABLE_PIG_H


#include "BaseGameEntity.h"
#include "Locations.h"


class State;

const int MaxMoney = 5000;
const int MaxTired = 100;

class AdorkablePig : public BaseGameEntity
{
private:
	State*			m_pCurrentState;
	location_type	m_location;

	int				m_iMoneyInBody;
	int				m_iTired;
	 
public:
	AdorkablePig(int id);

	void Update();

	void ChangeState(State* new_state);

	location_type	Location()const { return m_location; }
	void			ChangeLocation(const location_type loc) { m_location = loc; }

	int				MoneyInBody()const { return m_iMoneyInBody; }
	void			AddMoney(const int val);
	void			GiveMoney(const int val);
	bool			MoneyFull()const {return m_iMoneyInBody >= MaxMoney;}
	bool			MoneyEmpty()const { return MoneyInBody() <= 0; }

	bool			Tired()const {return m_iTired >= MaxTired;}
	bool			NoTired()const { return m_iTired <= 0; }
	void			IncreaseTired() { m_iTired += 10; }
	void			DecreaseTired() { m_iTired -= 20; }
};

#endif


