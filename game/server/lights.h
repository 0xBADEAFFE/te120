//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#ifndef LIGHTS_H
#define LIGHTS_H
#ifdef _WIN32
#pragma once
#endif

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
#ifdef TE120
class CLight : public CServerOnlyEntity//TE120
#else
class CLight : public CPointEntity
#endif // TE120
{
public:
#ifdef TE120
	DECLARE_CLASS( CLight, CServerOnlyEntity );//TE120
#else
	DECLARE_CLASS( CLight, CPointEntity );
#endif // TE120

	bool	KeyValue( const char *szKeyName, const char *szValue );
	void	Spawn( void );
#ifdef TE120
	virtual void Activate( void );//TE120
#endif // TE120
	void	FadeThink( void );
#ifdef TE120
	void	ToggleBugThink( void );//TE120
#endif // TE120
	void	Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	
	void	TurnOn( void );
	void	TurnOff( void );
	void	Toggle( void );

	// Input handlers
	void	InputSetPattern( inputdata_t &inputdata );
	void	InputFadeToPattern( inputdata_t &inputdata );
#ifdef TE120
	void	InputSetLightValue( inputdata_t &inputdata );//TE120
#endif // TE120

	void	InputToggle( inputdata_t &inputdata );
	void	InputTurnOn( inputdata_t &inputdata );
	void	InputTurnOff( inputdata_t &inputdata );

	DECLARE_DATADESC();

private:
	int		m_iStyle;
	int		m_iDefaultStyle;
	string_t m_iszPattern;
	char	m_iCurrentFade;
	char	m_iTargetFade;
#ifdef TE120
	bool	m_bRequestedToggleOff;//TE120
	bool	m_bRequestedToggleOn;//TE120
#endif // TE120
};

#endif // LIGHTS_H
