#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "helicopterstate.h"
#include "islepathactor.h"
#include "realtime/matrix.h"

// VTABLE: LEGO1 0x100d40f8
// SIZE 0x230
class Helicopter : public IslePathActor {
public:
	Helicopter();

	// FUNCTION: LEGO1 0x10003070
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f0130
		return "Helicopter";
	}

	// FUNCTION: LEGO1 0x10003080
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, Helicopter::ClassName()) || IslePathActor::IsA(name);
	}

	virtual MxResult Create(MxDSObject& p_dsObject) override; // vtable+0x18
	virtual void VTable0xe4() override;

	// SYNTHETIC: LEGO1 0x10003210
	// Helicopter::`scalar deleting destructor'
	virtual ~Helicopter() override; // vtable+0x0

protected:
	Matrix4Data m_unk160;
	Matrix4Data m_unk1a8;
	undefined4 m_unk1f0;
	Vector4Data m_unk1f4;
	Vector4Data m_unk20c;
	undefined4 m_unk224;
	HelicopterState* m_state;
	MxAtomId m_unk22c;

private:
	void GetState();
};

#endif // HELICOPTER_H
