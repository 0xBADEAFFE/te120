//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// -------------------------------------------------------------------------------- //
// An entity used to access overlays (and change their texture)
// -------------------------------------------------------------------------------- //

#ifdef TE120
class CInfoOverlayAccessor : public CServerOnlyPointEntity//TE120
{
public:

	DECLARE_CLASS( CInfoOverlayAccessor, CServerOnlyPointEntity );//TE120
#else
class CInfoOverlayAccessor : public CPointEntity
{
public:

	DECLARE_CLASS( CInfoOverlayAccessor, CPointEntity );
#endif // TE120

#ifndef TE120
	int  	UpdateTransmitState();

	DECLARE_SERVERCLASS();
#endif // TE120
	DECLARE_DATADESC();

private:

	CNetworkVar( int, m_iOverlayID );
};

#ifndef TE120
// This table encodes the CBaseEntity data.
IMPLEMENT_SERVERCLASS_ST_NOBASE(CInfoOverlayAccessor, DT_InfoOverlayAccessor)
	SendPropInt	(	SENDINFO(m_iTextureFrameIndex),		8,	SPROP_UNSIGNED ),
	SendPropInt	(	SENDINFO(m_iOverlayID),				32,	SPROP_UNSIGNED ),
END_SEND_TABLE()
#endif // TE120

LINK_ENTITY_TO_CLASS( info_overlay_accessor, CInfoOverlayAccessor );

BEGIN_DATADESC( CInfoOverlayAccessor )
	DEFINE_KEYFIELD( m_iOverlayID,	FIELD_INTEGER, "OverlayID" ),
END_DATADESC()

#ifndef TE120
int CInfoOverlayAccessor::UpdateTransmitState()
{
	return SetTransmitState( FL_EDICT_ALWAYS );
}
#endif // TE120