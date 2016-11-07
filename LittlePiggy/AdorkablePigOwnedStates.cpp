#include "misc/ConsoleUtils.h"
#include "AdorkablePigOwnedStates.h"
#include "AdorkablePig.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

//-----------------------------WorkInCompany-----------------------------------
//-----------------------------------------------------------------------------
WorkInCompany* WorkInCompany::Instance()
{
	static WorkInCompany instance;
	return &instance;
}

void WorkInCompany::Enter(AdorkablePig* pAdorkablePig)
{
	if (pAdorkablePig->Location() != company)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "猪到公司了，开电脑，HoHo";
		pAdorkablePig->ChangeLocation(company);
	}
}

void WorkInCompany::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->AddMoney(1000);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "写代码呀，写代码，我很快乐的写代码,赚钱呀赚钱";

	if (pAdorkablePig->MoneyFull())
	{
		pAdorkablePig->ChangeState(GiveMoneyInBank::Instance());
	}

	if (pAdorkablePig->Tired())
	{
		pAdorkablePig->ChangeState(SleepInHome::Instance());
	}
}

void WorkInCompany::Exit(AdorkablePig* pAdorkablePig)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "走出公司，不用写代码了^_^";
}

//----------------------------GiveMoneyInBank----------------------------------
//-----------------------------------------------------------------------------
GiveMoneyInBank* GiveMoneyInBank::Instance()
{
	static GiveMoneyInBank instance;
	return &instance;
}

void GiveMoneyInBank::Enter(AdorkablePig* pAdorkablePig)
{
	if (pAdorkablePig->Location() != bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "赚够5000拿起手机打，开支付宝，给小猪转账";
		pAdorkablePig->ChangeLocation(bank);
	}
}

void GiveMoneyInBank::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->GiveMoney(1000);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "支付宝限额，转账呀转账，每次转2000";

	if (pAdorkablePig->MoneyEmpty())
	{
		pAdorkablePig->ChangeState(WorkInCompany::Instance());
	}

	if (pAdorkablePig->Tired())
	{
		pAdorkablePig->ChangeState(SleepInHome::Instance());
	}
}

void GiveMoneyInBank::Exit(AdorkablePig* pAdorkablePig)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "哎，转好了，又没钱了";
}

//----------------------------SleepInHome--------------------------------------
//-----------------------------------------------------------------------------
SleepInHome* SleepInHome::Instance()
{
	static SleepInHome instance;
	return &instance;
}

void SleepInHome::Enter(AdorkablePig* pAdorkablePig)
{
	if (pAdorkablePig->Location() != home)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "累死了回到出租房睡觉";
		pAdorkablePig->ChangeLocation(home);
	}
}

void SleepInHome::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->DecreaseTired();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "睡觉 zzz。。。 恢复体力中。。。";

	if (pAdorkablePig->NoTired())
	{
		pAdorkablePig->ChangeState(WorkInCompany::Instance());
	}
}

void SleepInHome::Exit(AdorkablePig* pAdorkablePig)
{
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "睡饱了，该去干活了。。。";
}
