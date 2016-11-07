#ifndef ENTITY_NAMES_H
#define ENTITY_NAMES_H

#include <string>

enum
{
	ent_Adorkable_liwei,
	ent_jiajia
};

inline std::string GetNameOfEntity(int n)
{
	switch (n)
	{
	case ent_Adorkable_liwei:
		return "÷Ì";
	case ent_jiajia:
		return "–°÷Ì";
	default:
		return "UNKNOWN";
	}
}

#endif