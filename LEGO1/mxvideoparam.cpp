#include "mxvideoparam.h"

#include <stdlib.h>
#include <string.h>

// FUNCTION: LEGO1 0x100bec70
MxVideoParam::MxVideoParam()
{
	this->m_rect.SetRight(640);
	this->m_rect.SetBottom(480);
	this->m_rect.SetLeft(0);
	this->m_rect.SetTop(0);
	this->m_palette = NULL;
	this->m_backBuffers = 0;
	this->m_unk1c = 0;
	this->m_deviceId = NULL;
}

// FUNCTION: LEGO1 0x100beca0
MxVideoParam::MxVideoParam(
	COMPAT_CONST MxRect32& p_rect,
	MxPalette* p_pal,
	MxULong p_backBuffers,
	COMPAT_CONST MxVideoParamFlags& p_flags
)
{
	this->m_rect = p_rect;
	this->m_palette = p_pal;
	this->m_backBuffers = p_backBuffers;
	this->m_flags = p_flags;
	this->m_unk1c = 0;
	this->m_deviceId = NULL;
}

// FUNCTION: LEGO1 0x100becf0
MxVideoParam::MxVideoParam(MxVideoParam& p_videoParam)
{
	this->m_rect = p_videoParam.m_rect;
	this->m_palette = p_videoParam.m_palette;
	this->m_backBuffers = p_videoParam.m_backBuffers;
	this->m_flags = p_videoParam.m_flags;
	this->m_unk1c = p_videoParam.m_unk1c;
	this->m_deviceId = NULL;
	SetDeviceName(p_videoParam.m_deviceId);
}

// FUNCTION: LEGO1 0x100bed50
MxVideoParam::~MxVideoParam()
{
	if (this->m_deviceId != NULL)
		delete[] this->m_deviceId;
}

// FUNCTION: LEGO1 0x100bed70
void MxVideoParam::SetDeviceName(char* id)
{
	if (this->m_deviceId != NULL)
		delete[] this->m_deviceId;

	if (id != 0) {
		this->m_deviceId = new char[strlen(id) + 1];

		if (this->m_deviceId != NULL) {
			strcpy(this->m_deviceId, id);
		}
	}
	else {
		this->m_deviceId = NULL;
	}
}

// FUNCTION: LEGO1 0x100bede0
MxVideoParam& MxVideoParam::operator=(const MxVideoParam& p_videoParam)
{
	this->m_rect = p_videoParam.m_rect;
	this->m_palette = p_videoParam.m_palette;
	this->m_backBuffers = p_videoParam.m_backBuffers;
	this->m_flags = p_videoParam.m_flags;
	this->m_unk1c = p_videoParam.m_unk1c;
	SetDeviceName(p_videoParam.m_deviceId);

	return *this;
}
