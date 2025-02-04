#ifndef LEGOCARRACEACTOR_H
#define LEGOCARRACEACTOR_H

#include "legoraceactor.h"

// VTABLE: LEGO1 0x100da0d8
class LegoCarRaceActor : public LegoRaceActor {
public:
	// FUNCTION: LEGO1 0x10081650
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f0568
		return "LegoCarRaceActor";
	}

	// FUNCTION: LEGO1 0x10081670
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, LegoCarRaceActor::ClassName()) || LegoRaceActor::IsA(name);
	}
};

#endif // LEGOCARRACEACTOR_H
