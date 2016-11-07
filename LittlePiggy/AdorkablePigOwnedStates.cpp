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
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "����˾�ˣ������ԣ�HoHo";
		pAdorkablePig->ChangeLocation(company);
	}
}

void WorkInCompany::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->AddMoney(1000);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "д����ѽ��д���룬�Һܿ��ֵ�д����,׬Ǯѽ׬Ǯ";

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
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "�߳���˾������д������^_^";
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
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "׬��5000�����ֻ��򣬿�֧��������С��ת��";
		pAdorkablePig->ChangeLocation(bank);
	}
}

void GiveMoneyInBank::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->GiveMoney(1000);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "֧�����޶ת��ѽת�ˣ�ÿ��ת2000";

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
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "����ת���ˣ���ûǮ��";
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
		cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "�����˻ص����ⷿ˯��";
		pAdorkablePig->ChangeLocation(home);
	}
}

void SleepInHome::Execute(AdorkablePig* pAdorkablePig)
{
	pAdorkablePig->DecreaseTired();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "˯�� zzz������ �ָ������С�����";

	if (pAdorkablePig->NoTired())
	{
		pAdorkablePig->ChangeState(WorkInCompany::Instance());
	}
}

void SleepInHome::Exit(AdorkablePig* pAdorkablePig)
{
	cout << "\n" << GetNameOfEntity(pAdorkablePig->ID()) << ": " << "˯���ˣ���ȥ�ɻ��ˡ�����";
}
