#ifndef LEGOINPUTMANAGER_H
#define LEGOINPUTMANAGER_H

#include "decomp.h"
#include "legoeventnotificationparam.h"
#include "legoworld.h"
#include "mxlist.h"
#include "mxpresenter.h"
#include "mxqueue.h"

#include <dinput.h>

class LegoControlManager;

// VTABLE: LEGO1 0x100d87b8
// class MxCollection<LegoEventNotificationParam>

// VTABLE: LEGO1 0x100d87d0
// class MxList<LegoEventNotificationParam>

// VTABLE: LEGO1 0x100d87e8
// class MxQueue<LegoEventNotificationParam>

// VTABLE: LEGO1 0x100d8800
// SIZE 0x18
class LegoEventQueue : public MxQueue<LegoEventNotificationParam> {};

// VTABLE: LEGO1 0x100d8760
// SIZE 0x338
class LegoInputManager : public MxPresenter {
public:
	LegoInputManager();
	virtual ~LegoInputManager() override;

	__declspec(dllexport) void QueueEvent(NotificationId p_id, MxU8 p_modifier, MxLong p_x, MxLong p_y, MxU8 p_key);
	__declspec(dllexport) void Register(MxCore*);
	__declspec(dllexport) void UnRegister(MxCore*);

	virtual MxResult Tickle() override; // vtable+0x8

	MxResult Create(HWND p_hwnd);
	void Destroy();
	void CreateAndAcquireKeyboard(HWND hwnd);
	void ReleaseDX();
	MxResult GetJoystickId();
	MxResult GetJoystickState(MxU32* joystick_x, MxU32* joystick_y, DWORD* buttons_state, MxU32* pov_position);
	void SetTimer();
	void KillTimer();
	void SetCamera(LegoCameraController* p_camera);
	void ClearCamera();
	void SetWorld(LegoWorld* p_world);
	void ClearWorld();

	inline void SetUnknown88(MxBool p_unk0x88) { m_unk0x88 = p_unk0x88; }
	inline void SetUnknown336(MxBool p_unk0x336) { m_unk0x336 = p_unk0x336; }

	inline LegoControlManager* GetControlManager() { return m_controlManager; }
	inline LegoWorld* GetWorld() { return m_world; }

	void ProcessEvents();
	MxBool ProcessOneEvent(LegoEventNotificationParam& p_param);

	// private:
	MxCriticalSection m_criticalSection;
	MxList<undefined4>* m_unk0x5c; // list or hash table
	LegoCameraController* m_camera;
	LegoWorld* m_world;
	LegoEventQueue* m_eventQueue; // +0x68
	undefined4 m_unk0x6c;
	undefined4 m_unk0x70;
	undefined4 m_unk0x74;
	UINT m_timer;
	UINT m_timeout;
	undefined m_unk0x80;
	undefined m_unk0x81;
	LegoControlManager* m_controlManager;
	MxBool m_unk0x88;
	IDirectInput* m_directInput;
	IDirectInputDevice* m_directInputDevice;
	undefined m_unk0x94;
	undefined4 m_unk0x98;
	undefined m_unk0x9c[0xF8];
	undefined m_unk0x194;
	MxBool m_unk0x195;
	MxS32 m_joyid;
	MxS32 m_joystickIndex;
	JOYCAPS m_joyCaps;
	MxBool m_useJoystick;
	MxBool m_unk0x335;
	MxBool m_unk0x336;
};

#endif // LEGOINPUTMANAGER_H
