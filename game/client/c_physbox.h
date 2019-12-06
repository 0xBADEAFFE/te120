//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//



// Client-side CBasePlayer

#ifndef C_PHYSBOX_H
#define C_PHYSBOX_H
#pragma once


#include "c_baseentity.h"


class C_PhysBox : public C_BaseEntity
{
public:
	DECLARE_CLASS( C_PhysBox, C_BaseEntity );
	DECLARE_CLIENTCLASS();

					C_PhysBox();
	virtual			~C_PhysBox();
	virtual ShadowType_t ShadowCastType();
#ifdef TE120	
	unsigned char	GetClientSideFade(); // TE120
#endif // TE120
public:
	float			m_mass;	// TEST..
#ifdef TE120
	float			m_fDisappearDist; // TE120
#endif // TE120
};


#endif



