#ifndef DOORS_H
#define DOORS_H

#include "legopathactor.h"

// VTABLE: LEGO1 0x100d4788
// SIZE 0x1f8
class Doors : public LegoPathActor {
public:
	// FUNCTION: LEGO1 0x1000e430
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f03e8
		return "Doors";
	}

	// FUNCTION: LEGO1 0x1000e440
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, Doors::ClassName()) || LegoPathActor::IsA(name);
	}
};

#endif // DOORS_H
