#ifndef HOSPITALENTITY_H
#define HOSPITALENTITY_H

#include "buildingentity.h"

// VTABLE: LEGO1 0x100d5068
// SIZE 0x68
class HospitalEntity : public BuildingEntity {
public:
	// FUNCTION: LEGO1 0x1000ec40
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f0338
		return "HospitalEntity";
	}

	// FUNCTION: LEGO1 0x1000ec50
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, HospitalEntity::ClassName()) || BuildingEntity::IsA(name);
	}
};

#endif // HOSPITALENTITY_H
