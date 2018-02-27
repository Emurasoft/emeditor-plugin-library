/*
	etlframe.h version 17.5
	Copyright © 2018 by Emurasoft, Inc.
*/

#if _MSC_VER > 1000
#pragma once
#endif

#include "plugin.h"
#include <crtdbg.h>
#pragma warning( push )
#pragma warning( disable : 4995 ) // 'function': name was marked as #pragma deprecated
#if _MSC_VER < 0x0700
	#pragma warning( disable : 4786 ) // identifier was truncated to '255' characters in the browser information
	#pragma warning( disable : 4512 ) // assignment operator could not be generated
	#pragma warning( disable : 4100 ) // unreferenced formal parameter

#endif
#include <shlwapi.h>
#include <strsafe.h>
#include <map>
#pragma warning( pop )

#if _MSC_VER < 0x0700
	#pragma warning( push )
	#pragma warning( disable : 4127 ) // conditional expression is constant
	#pragma warning( disable : 4786 ) // identifier was truncated to '255' characters in the browser information
#endif

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

#define LOC_USE_EMEDLOC_DLL		2   // use emedloc.dll
#define LOC_USE_LOC_DLL			1   // use _loc.dll in MUI sub folder
#define LOC_USE_PLUGIN_DLL		0   // use the resource within plugin dll

// these asserts fail on previous versions of EmEditor (v4.13 or earlier).
#ifdef TEST_V5
#define ASSERT_STRICT(x) _ASSERTE(x)
#else
#define ASSERT_STRICT(x) (void(0))
#endif

#ifdef EE_IMPLEMENT
#define EE_EXTERN
#else
#define EE_EXTERN extern
#endif

#ifdef _DEBUG
#ifdef _DEBUG_NEW
#define new _DEBUG_NEW
#endif
#endif

LPCTSTR const szDefaultLang = _T("DefaultLang");

// forward declaration
#define DEFINE_CREATE(c) 
class ETL_FRAME_CLASS_NAME;
template <typename T> class CETLFrame;
typedef CETLFrame<ETL_FRAME_CLASS_NAME> CETLFrameX;
typedef std::map<HWND, CETLFrameX*> CETLFrameMap;
CETLFrameX* _ETLCreateFrame();
void _ETLDeleteFrame( CETLFrameX* pFrame );
BOOL IsFileExist( LPCTSTR pszPathName );
void GetModuleFilePath( LPCTSTR szFile, LPTSTR szPath );
HINSTANCE GetInstancePath( LPCTSTR szPath, bool bResourceOnly );

#define _ETL_IMPLEMENT CETLFrameX* _ETLCreateFrame() { CETLFrameX* pFrame = new ETL_FRAME_CLASS_NAME; return pFrame; } void _ETLDeleteFrame( CETLFrameX* pFrame ) { delete static_cast<ETL_FRAME_CLASS_NAME*>(pFrame); }

#pragma warning( push )
#pragma warning( disable : 4127 ) // C4127: conditional expression is constant

// global data definition
class CETLData
{
public:
	HINSTANCE			m_hInstance;
	HINSTANCE			m_hinstLoc;
	CRITICAL_SECTION	m_cs;
	CETLFrameMap*		m_pETLFrameMap;
	WORD				m_wCmdID;

	CETLData() 
	{
		ZeroMemory( this, sizeof( CETLData ) );
		InitializeCriticalSection( &m_cs );
	}

	~CETLData() 
	{
		DeleteCriticalSection( &m_cs );
	}

	void Lock() 
	{
		EnterCriticalSection( &m_cs );
	}

	void Unlock()
	{
		::LeaveCriticalSection( &m_cs );
	}
};

#ifndef EE_EXTERN_ONLY
class CETLData _ETLData;
#endif


class CETLLock
{
public:
#ifdef EE_EXTERN_ONLY
	CETLLock();
	~CETLLock();
#else
	CETLLock()
	{
		_ETLData.Lock();
	}

	~CETLLock()
	{
		_ETLData.Unlock();
	}
#endif
};

template <typename T> class __declspec(novtable) CETLFrame
{
public:
	HWND	m_hWnd;
	CETLFrame<T>() : m_hWnd(0)
	{
	}

	~CETLFrame<T>()
	{
	}

	virtual void OnCommand( HWND hwndView )
	{
		T* pT = static_cast<T*>(this);
		pT->OnCommand( hwndView );
	}

	void OnEvents( HWND hwndView, UINT nEvent, LPARAM lParam )
	{
		T* pT = static_cast<T*>(this);
		pT->OnEvents( hwndView, nEvent, lParam );
	}

	BOOL QueryStatus( HWND hwndView, LPBOOL pbChecked )
	{
		T* pT = static_cast<T*>(this);
		return pT->QueryStatus( hwndView, pbChecked );
	}

	static UINT GetMenuTextID()
	{
		if( T::_USE_LOC_DLL ){
			return 0;
		}
		else {
			return T::_IDS_MENU;
		}
	}

	static UINT GetStatusMessageID()
	{
		if(  T::_USE_LOC_DLL ){
			return 0;
		}
		else {
			return T::_IDS_STATUS;
		}
	}

	static UINT GetBitmapID()
	{
		return T::_IDB_BITMAP;
	}

	static LRESULT GetStringA( LPSTR pBuf, size_t cchBuf, UINT nID )
	{
		char sz[80];
		HINSTANCE hinst = EEGetLocaleInstanceHandle();
		LRESULT lResult = 0;
		if( hinst ){
			lResult = LoadStringA( hinst, nID, sz, _countof( sz ) ) + 1;
			//_ASSERTE( lResult > 1 );
			if( pBuf ){
				StringCchCopyA( pBuf, cchBuf, sz );
			}
		}
		return lResult;
	}

	static LRESULT GetStringW( LPWSTR pBuf, size_t cchBuf, UINT nID )
	{
		WCHAR sz[80];
		HINSTANCE hinst = EEGetLocaleInstanceHandle();
		LRESULT lResult = 0;
		if( hinst ){
			lResult = LoadStringW( hinst, nID, sz, _countof( sz ) ) + 1;   // LoadStringW does not work on Windows 9x, but that is OK.
			//_ASSERTE( lResult > 1 );  
			if( pBuf ){
				StringCchCopyW( pBuf, cchBuf, sz );
			}
		}
		return lResult;
	}

	static LRESULT GetNameA( LPSTR pBuf, size_t cchBuf )
	{
		return GetStringA( pBuf, cchBuf, T::_IDS_NAME );
	}

	static LRESULT GetNameW( LPWSTR pBuf, size_t cchBuf )
	{
		return GetStringW( pBuf, cchBuf, T::_IDS_NAME );
	}

	static LRESULT GetVersionA( LPSTR pBuf, size_t cchBuf )
	{
		return GetStringA( pBuf, cchBuf, T::_IDS_VER );
	}

	static LRESULT GetVersionW( LPWSTR pBuf, size_t cchBuf )
	{
		return GetStringW( pBuf, cchBuf, T::_IDS_VER );
	}

	static LRESULT GetMenuW( LPWSTR pBuf, size_t cchBuf )
	{
		return GetStringW( pBuf, cchBuf, T::_IDS_MENU );
	}

	static LRESULT GetStatusW( LPWSTR pBuf, size_t cchBuf )
	{
		return GetStringW( pBuf, cchBuf, T::_IDS_STATUS );
	}

	static LRESULT GetInfo( WPARAM flag )
	{
		LRESULT lResult = 0;
		switch( flag ){
		case EPGI_ALLOW_OPEN_SAME_GROUP:
			lResult = T::_ALLOW_OPEN_SAME_GROUP;
			break;
		case EPGI_ALLOW_MULTIPLE_INSTANCES:
			lResult = T::_ALLOW_MULTIPLE_INSTANCES;
			break;
		case EPGI_MAX_EE_VERSION:
			lResult = T::_MAX_EE_VERSION;
			break;
		case EPGI_MIN_EE_VERSION:
			lResult = T::_MIN_EE_VERSION;
			break;
		case EPGI_SUPPORT_EE_PRO:
			lResult = T::_SUPPORT_EE_PRO;
			break;
		case EPGI_SUPPORT_EE_STD:
			lResult = T::_SUPPORT_EE_STD;
			break;
		}
		return lResult;
	}

	LRESULT PlugInProc( HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam )
	{
		LRESULT lResult = 0;
		T* pT = static_cast<T*>(this);
		switch( nMsg ){
		case EP_QUERY_UNINSTALL:
			lResult = pT->QueryUninstall( hwnd );
			break;
		case EP_SET_UNINSTALL:
			lResult = pT->SetUninstall( hwnd, (LPTSTR)wParam, (LPTSTR)lParam );
			break;
		case EP_QUERY_PROPERTIES:
			lResult = pT->QueryProperties( hwnd );
			break;
		case EP_SET_PROPERTIES:
			lResult = pT->SetProperties( hwnd );
			break;
		case EP_PRE_TRANSLATE_MSG:
			lResult = pT->PreTranslateMessage( hwnd, (MSG*)lParam );
			break;
		case EP_USE_DROPPED_FILES:
			lResult = pT->UseDroppedFiles( hwnd );
			break;
		case EP_DISABLE_AUTO_COMPLETE:
			lResult = pT->DisableAutoComplete( hwnd );
			break;
		case EP_USER_MSG:
			lResult = pT->UserMessage( hwnd, wParam, lParam );
			break;
		}
		return lResult;
	}

	static LRESULT GetMask( WPARAM wParam )
	{
		LRESULT lResult = 0;
		if( wParam & BITMAP_24BIT_COLOR ){
			lResult = T::_MASK_TRUE_COLOR;
		}
		return lResult;
	}

	static LRESULT GetBitmap( WPARAM wParam )
	{
		LRESULT lResult = 0;
		if( wParam & BITMAP_LARGE ){
			if( wParam & BITMAP_24BIT_COLOR ){
				if( wParam & BITMAP_DISABLED ){
					lResult = T::_IDB_TRUE_24_BW;
				}
				else if( wParam & BITMAP_HOT ){
					lResult = T::_IDB_TRUE_24_HOT;
				}
				else {
					lResult = T::_IDB_TRUE_24_DEFAULT;
				}
			}
			else {
				lResult = T::_IDB_16C_24;
			}
		}
		else {
			if( wParam & BITMAP_24BIT_COLOR ){
				if( wParam & BITMAP_DISABLED ){
					lResult = T::_IDB_TRUE_16_BW;
				}
				else if( wParam & BITMAP_HOT ){
					lResult = T::_IDB_TRUE_16_HOT;
				}
				else {
					lResult = T::_IDB_TRUE_16_DEFAULT;
				}
			}
			else {
				lResult = T::_IDB_BITMAP;
			}
		}
		return lResult;
	}

// Registry/INI
	void GetProfileString( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, LPWSTR lpszBuf, DWORD cchBufSize, LPCWSTR lpszDefault )
	{
		DWORD dwSize = cchBufSize * sizeof( WCHAR );
		if( ERROR_SUCCESS == Editor_RegQueryValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_SZ, (LPBYTE)lpszBuf, &dwSize, 0 ) ){
			return;
		}
		lstrcpynW( lpszBuf, lpszDefault, cchBufSize );
	}

	void GetProfileString( LPCWSTR lpszEntry, LPWSTR lpszBuf, DWORD cchBufSize, LPCWSTR lpszDefault )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			GetProfileString( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, lpszBuf, cchBufSize, lpszDefault );
			return;
		}
		lstrcpynW( lpszBuf, lpszDefault, cchBufSize );
	}

	int GetProfileInt( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, int nDefault )
	{
		_ASSERT( lpszEntry );
		DWORD dwSize = sizeof( DWORD );
		DWORD dwData = 0;
		if( ERROR_SUCCESS == Editor_RegQueryValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_DWORD, (LPBYTE)&dwData, &dwSize, 0 ) ){
			return (int)dwData;
		}
		return nDefault;
	}

	int GetProfileInt( LPCWSTR lpszEntry, int nDefault )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			return GetProfileInt( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, nDefault );
		}
		return nDefault;
	}

	DWORD GetProfileBinary( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, LPBYTE lpBuf, DWORD cbBufSize )
	{
		_ASSERT( lpszEntry );
		if( ERROR_SUCCESS == Editor_RegQueryValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_BINARY, (LPBYTE)lpBuf, &cbBufSize, 0 ) ){
			return cbBufSize;
		}
		return 0;
	}

	DWORD GetProfileBinary( LPCWSTR lpszEntry, LPBYTE lpBuf, DWORD cbBufSize )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			return GetProfileBinary( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, lpBuf, cbBufSize );
		}
		return 0;
	}

	void WriteProfileString( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, LPCWSTR lpszValue )
	{
		_ASSERT( lpszEntry );
		_ASSERT( lpszValue );
		VERIFY( ERROR_SUCCESS == Editor_RegSetValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_SZ, (const LPBYTE)lpszValue, (lstrlen( lpszValue ) + 1) * sizeof( TCHAR ), 0 ) );
	}

	void WriteProfileString( LPCWSTR lpszEntry, LPCWSTR lpszValue )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			WriteProfileString( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, lpszValue );
		}
	}

	void WriteProfileInt( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, int nValue )
	{
		_ASSERT( lpszEntry );
		DWORD dwData = nValue;
		VERIFY( ERROR_SUCCESS == Editor_RegSetValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_DWORD, (const LPBYTE)&dwData, sizeof( DWORD ), 0 ) );
	}

	void WriteProfileInt( LPCWSTR lpszEntry, int nValue )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			WriteProfileInt( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, nValue );
		}
	}

	void WriteProfileBinary( DWORD dwKey, LPCWSTR pszConfig, LPCWSTR lpszEntry, const LPBYTE lpBuf, DWORD cbBufSize, bool bVariableSize )
	{
		_ASSERT( lpszEntry );
		_ASSERT( lpBuf );
		VERIFY( ERROR_SUCCESS == Editor_RegSetValue( m_hWnd, dwKey, pszConfig, lpszEntry, REG_BINARY, (const LPBYTE)lpBuf, cbBufSize, bVariableSize ? EE_REG_VARIABLE_SIZE : 0 ) );
	}

	void WriteProfileBinary( LPCWSTR lpszEntry, const LPBYTE lpBuf, DWORD cbBufSize, bool bVariableSize )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			WriteProfileBinary( EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, lpBuf, cbBufSize, bVariableSize );
		}
	}

	void EraseProfile()
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			Editor_RegSetValue( m_hWnd, EEREG_EMEDITORPLUGIN, szFileName, NULL, REG_SZ, (const LPBYTE)NULL, 0, 0 );
		}
	}

	void EraseEntry( LPCWSTR lpszEntry )
	{
		TCHAR szFileName[MAX_PATH];
		if( GetModuleFile( szFileName ) ) {
			Editor_RegSetValue( m_hWnd, EEREG_EMEDITORPLUGIN, szFileName, lpszEntry, REG_SZ, (const LPBYTE)NULL, 0, 0 );
		}
	}

	BOOL IsLangExist( LPCTSTR szLang )
	{
		if( szLang[0] != '.' ){
			TCHAR szPath[MAX_PATH];
			GetModuleFilePath( _T("mui"), szPath );
			PathAppend( szPath, szLang );
			return PathIsDirectory( szPath );
		}
		return FALSE;
	}

	BOOL GetResourceFolder( LPTSTR szFolder, bool bSystemLang, LPCTSTR szLang )
	{
		TCHAR szPath[MAX_PATH];
		GetModuleFilePath( _T("mui"), szPath );
		if( bSystemLang ){
			TCHAR szFile[MAX_PATH];
			UINT nLang = GetUserDefaultUILanguage();
			StringCchPrintf( szFile, _countof( szFile ), _T("%u"), nLang );
			if( IsLangExist( szFile ) ){
				PathCombine( szFolder, szPath, szFile );
				return TRUE;
			}
		}
		if( szLang[0] ){
			if( IsLangExist( szLang ) ){
				PathCombine( szFolder, szPath, szLang );
				return TRUE;
			}
		}
		szFolder[0] = 0;
		return FALSE;

	}

	BOOL GetAnyResourceFolder( LPTSTR szFolder )
	{
		// find anything available.
		TCHAR szLang[MAX_PATH];
		szLang[0] = 0;
		TCHAR szPath[MAX_PATH];
		GetModuleFilePath( _T("mui\\*"), szPath );
		WIN32_FIND_DATA find;
		HANDLE hFind = INVALID_HANDLE_VALUE;
		hFind = FindFirstFile( szPath, &find );
		if( hFind != INVALID_HANDLE_VALUE ) {
			do {
				if( find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ){
					if( IsLangExist( find.cFileName ) ){
						StringCchCopy( szLang, _countof( szLang ), find.cFileName );
						break;
					}
				}
			} while( FindNextFile(hFind, &find) );
			FindClose(hFind);
		}
		if( szLang[0] ){
			return GetResourceFolder( szFolder, false, szLang );
		}
		return FALSE;
	}

	BOOL GetDefaultResourceFolder( LPTSTR szFolder )
	{
		TCHAR szLang[MAX_PATH];
		int nLang = GetProfileInt( EEREG_LM_COMMON, NULL, szDefaultLang, 1033 );
		StringCchPrintf( szLang, _countof( szLang ), _T("%d"), nLang );
		BOOL bResult = GetResourceFolder( szFolder, false, szLang );
		if( !bResult ){
			bResult = GetAnyResourceFolder( szFolder );
		}
		return bResult;
	}

	BOOL GetResourceFolder( LPTSTR szFolder )
	{
		TCHAR szDir[MAX_PATH];
		szDir[0] = 0;
		Editor_Info( m_hWnd, EI_GET_LANGUAGE, (LPARAM)szDir );
		if( szDir[0] ){
			PathStripPath( szDir );
			GetModuleFilePath( _T("mui"), szFolder );
			PathAppend( szFolder, szDir );
			return TRUE;
		}
		return FALSE;
	}

	BOOL GetResourceFile( LPTSTR szPath, LPCTSTR szFile )
	{
		if( GetResourceFolder( szPath ) ){
			PathAppend( szPath, szFile );
			if( IsFileExist( szPath ) ){
				return TRUE;
			}
			if( GetDefaultResourceFolder( szPath ) ){
				PathAppend( szPath, szFile );
				if( IsFileExist( szPath ) ){
					return TRUE;
				}
			}
		}
		szPath[0] = 0;
		return FALSE;
	}

	HINSTANCE GetEmedLocInstance()
	{
		if( T::_USE_LOC_DLL == LOC_USE_EMEDLOC_DLL ){
			HINSTANCE hinstLoc = (HINSTANCE)Editor_Info( m_hWnd, EI_GET_LOC_DLL_INSTANCE, 0 );
			_ASSERT( hinstLoc );
			return hinstLoc;
			//TCHAR szPath[MAX_PATH];
			//szPath[0] = 0;
			//Editor_Info( m_hWnd, EI_GET_LANGUAGE, (LPARAM)szPath );
			//PathAppend( szPath, L"emedloc.dll" );
			//return GetInstancePath( szPath );
		}
		else if( T::_USE_LOC_DLL == LOC_USE_LOC_DLL ){
			TCHAR szFileName[MAX_PATH];
			TCHAR szPath[MAX_PATH];
			szPath[0] = 0;
			if( GetModuleFile( szFileName ) ) {
				StringCchCat( szFileName, _countof( szFileName ), _T("_loc.dll") );
				if( !GetResourceFile( szPath, szFileName ) ){
					TCHAR sz[260];
					StringCchCopy( sz, _countof( sz ), _T("No localized file found - ") );
					StringCchCat( sz, _countof( sz ), szFileName );
					::MessageBox( NULL, sz, _T("EmEditor"), MB_ICONSTOP | MB_OK );
					return NULL;
				}
			}
			else {
				return NULL;
			}
			return GetInstancePath( szPath, true );
		}
		else {
			return NULL;
		}
	}

	void FreeLocInstance( HINSTANCE hinstLoc )
	{
		if( T::_USE_LOC_DLL != LOC_USE_EMEDLOC_DLL ){
			if( hinstLoc != NULL ){
				FreeLibrary( hinstLoc );
			}
		}
	}
};


extern HINSTANCE EEGetLocaleInstanceHandle();
extern HINSTANCE EEGetInstanceHandle();
extern BOOL IsFileExist( LPCTSTR pszPathName );
extern BOOL GetModuleFile( LPTSTR szFileName );
extern void GetModuleFilePath( LPCTSTR szFile, LPTSTR szPath );
extern HINSTANCE GetInstancePath( LPCTSTR szPath );
extern WORD EEGetCmdID();
extern CETLFrameX* GetFrameFromFrame( HWND hwndFrame );
extern CETLFrameX* GetFrame( HWND hwnd );
extern CETLFrameX* GetFrameFromDlg( HWND hwnd );
extern CETLFrameX* GetFrameFromView( HWND hwndView );

#ifndef EE_EXTERN_ONLY
HINSTANCE EEGetLocaleInstanceHandle()
{
	CETLLock lock;
	{
		if( _ETLData.m_hinstLoc != NULL ){
			return _ETLData.m_hinstLoc;
		}
	}
	return _ETLData.m_hInstance;
}

HINSTANCE EEGetInstanceHandle()
{
	_ASSERTE( _ETLData.m_hInstance != NULL );
	return _ETLData.m_hInstance;
}

BOOL IsFileExist( LPCTSTR pszPathName )
{
	return( !(GetFileAttributes( pszPathName ) & FILE_ATTRIBUTE_DIRECTORY) );
}

// buffer must be MAX_PATH character long.
BOOL GetModuleFile( LPTSTR szFileName )
{
	TCHAR szPath[MAX_PATH];
	if( !GetModuleFileName( EEGetInstanceHandle(), szPath, _countof( szPath ) ) ){
		return FALSE;
	}
	TCHAR szBuf[MAX_PATH];
	LPTSTR pszFile = szBuf;
	if( !GetFullPathName( szPath, MAX_PATH, szBuf, &pszFile ) ){
		return FALSE;
	}
	LPTSTR p = _tcschr( pszFile, _T('.') );
	if( p != NULL )  *p = _T('\0');
	StringCchCopy( szFileName, MAX_PATH, pszFile );
	return TRUE;
}

void GetModuleFilePath( LPCTSTR szFile, LPTSTR szPath )
{
	szPath[0] = '\0';
	TCHAR szModulePath[MAX_PATH];
	LPTSTR p = szPath;
	if( ::GetModuleFileName( EEGetInstanceHandle(), szModulePath, MAX_PATH) ){
		GetFullPathName( szModulePath, MAX_PATH, szPath, &p );
	}
	StringCchCopy( p, (size_t)(MAX_PATH - (p - szPath)), szFile );
}

HINSTANCE GetInstancePath( LPCTSTR szPath, bool bResourceOnly )
{
	_ASSERT( szPath[0] );
	_ASSERT( !PathIsRelative( szPath ) );  //  szPath must be full path to avoid dll hijacking issues
	HINSTANCE hinstRes = ::LoadLibraryEx( szPath, NULL, bResourceOnly ? (LOAD_LIBRARY_AS_DATAFILE | LOAD_LIBRARY_AS_IMAGE_RESOURCE) : 0 );
	if( hinstRes == NULL ){
		TCHAR sz[MAX_PATH + 64];
		StringCchPrintf( sz, _countof( sz ), _T("Cannot load %s."), szPath );
		MessageBox( NULL, sz, _T("EmEditor"), MB_OK | MB_ICONSTOP );
		return NULL;
	}
	return hinstRes;
}

WORD EEGetCmdID()
{
	_ASSERTE( _ETLData.m_wCmdID >= EEID_PLUG_IN1 );
	_ASSERTE( _ETLData.m_wCmdID <= EEID_PLUG_IN1 + 255 );
	return _ETLData.m_wCmdID;
}

CETLFrameX* GetFrameFromFrame( HWND hwndFrame )
{
	_ASSERTE( hwndFrame );
	_ASSERTE( IsWindow( hwndFrame ) );
	ASSERT_STRICT( _ETLData.m_pETLFrameMap != NULL );
	if( _ETLData.m_pETLFrameMap == NULL )  return NULL;
	CETLFrameX* pFrame = NULL;
	{
		CETLLock lock;
		CETLFrameMap::iterator it = _ETLData.m_pETLFrameMap->find( hwndFrame );
		ASSERT_STRICT( it != _ETLData.m_pETLFrameMap->end() );
		if( it != _ETLData.m_pETLFrameMap->end() ){
			pFrame = it->second;
			_ASSERTE( pFrame != NULL );
		}
	}
	return pFrame;
}

CETLFrameX* GetFrame( HWND hwnd )
{
	_ASSERTE( IsWindow( hwnd ) );
	HWND hwndFrame = GetAncestor( hwnd, GA_ROOTOWNER );
	_ASSERTE( IsWindow( hwndFrame ) );
	CETLFrameX* pFrame = GetFrameFromFrame( hwndFrame );
//	_ASSERTE( pFrame );
	return pFrame;
}

CETLFrameX* GetFrameFromDlg( HWND hwnd )
{
	return GetFrame( hwnd );
}

CETLFrameX* GetFrameFromView( HWND hwndView )
{
	return GetFrame( hwndView );
}

void DeleteAllFrames()
{
	for( CETLFrameMap::iterator it = _ETLData.m_pETLFrameMap->begin(); it != _ETLData.m_pETLFrameMap->end(); it++ ){
		CETLFrameX* pFrame = it->second;
		pFrame->OnEvents( NULL, EVENT_CLOSE_FRAME, 0 );
		delete pFrame;
	}
	_ETLData.m_pETLFrameMap->clear();
}

BOOL APIENTRY DllMain( HINSTANCE hModule, DWORD  ul_reason_for_call, LPVOID /*lpReserved*/ )
{
    if( ul_reason_for_call == DLL_PROCESS_ATTACH ){
#ifdef _DEBUG
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_EVERY_1024_DF /* _CRTDBG_CHECK_ALWAYS_DF */ );
#endif
		_ASSERTE( _ETLData.m_hInstance == NULL );
		_ETLData.m_hInstance = hModule;
	}
	else if( ul_reason_for_call == DLL_PROCESS_DETACH ){
//		_ASSERTE( _ETLData.m_pETLFrameMap == NULL );
		if( _ETLData.m_pETLFrameMap ) {
			for( CETLFrameMap::iterator it = _ETLData.m_pETLFrameMap->begin(); it != _ETLData.m_pETLFrameMap->end(); it++ ){
				CETLFrameX* pFrame = it->second;
				delete pFrame;
			}
			delete _ETLData.m_pETLFrameMap;
			_ETLData.m_pETLFrameMap = NULL;
			_ETLData.m_wCmdID = 0;
		}
	}
    return TRUE;
}

extern "C" void __stdcall OnCommand( HWND hwndView )
{
	CETLFrameX* pFrame = GetFrameFromView( hwndView );
	pFrame->OnCommand( hwndView );
}


extern "C" BOOL __stdcall QueryStatus( HWND hwndView, LPBOOL pbChecked )
{
	CETLFrameX* pFrame = GetFrameFromView( hwndView );
	if( pFrame == NULL )  return FALSE;
	return pFrame->QueryStatus( hwndView, pbChecked );
}

extern "C" UINT __stdcall GetMenuTextID()
{
	return CETLFrameX::GetMenuTextID();
}

extern "C" UINT __stdcall GetStatusMessageID()
{
	return CETLFrameX::GetStatusMessageID();
}

extern "C" UINT __stdcall GetBitmapID()
{
	return CETLFrameX::GetBitmapID();
}


extern "C" void __stdcall OnEvents( HWND hwndView, UINT nEvent, LPARAM lParam )
{
	HWND hwndFrame = NULL;
	if( nEvent != EVENT_CLOSE ){
		_ASSERTE( hwndView );
		if( !IsWindow( hwndView ) ) {  // hwndView can be already destroyed if PostMessage( WM_ENDSESSION, ...) is used ("Do not share process between documents (disables tabs)" is checked in the Advanced page of Customize dialog box)
			return;
		}
		hwndFrame = GetParent( hwndView );
		_ASSERTE( hwndFrame );
		if( !hwndFrame ) {
			return;
		}
	}
	if( nEvent & EVENT_CREATE ){
		_ASSERTE( (UINT)lParam >= EEID_PLUG_IN1 && (UINT)lParam <= EEID_PLUG_IN1 + 255 );
		_ASSERTE( _ETLData.m_wCmdID == 0 );
		_ASSERTE( _ETLData.m_pETLFrameMap == NULL );
		_ETLData.m_wCmdID = LOWORD( lParam );
		_ETLData.m_pETLFrameMap = new CETLFrameMap;
		if( Editor_GetVersion( hwndView ) < 5000 ){   // previous versions of EmEditor do not fire EVENT_CREATE_FRAME.
			OnEvents( hwndView, EVENT_CREATE_FRAME, lParam );
		}
	}
	else {
		ASSERT_STRICT( _ETLData.m_pETLFrameMap != NULL );
		if( _ETLData.m_pETLFrameMap != NULL ){
			if( nEvent & EVENT_CREATE_FRAME ){
				_ASSERTE( _ETLData.m_wCmdID == LOWORD( lParam ) );
				CETLFrameX* pFrame = static_cast<CETLFrameX*>(_ETLCreateFrame());
				pFrame->m_hWnd = hwndFrame;
				{
					CETLLock lock;
					_ASSERTE( _ETLData.m_pETLFrameMap->find( hwndFrame ) == _ETLData.m_pETLFrameMap->end() );
					_ETLData.m_pETLFrameMap->insert( std::pair<HWND, CETLFrameX*>( hwndFrame, pFrame ) );
					if( _ETLData.m_pETLFrameMap->size() == 1 ){
						_ASSERT( _ETLData.m_hinstLoc == NULL );
						_ETLData.m_hinstLoc = pFrame->GetEmedLocInstance();
					}
					pFrame->OnEvents( hwndView, nEvent, lParam );
				}
			}
			else if( nEvent & EVENT_CLOSE_FRAME ){
				CETLFrameX* pFrame;
				{
					CETLLock lock;
					CETLFrameMap::iterator it = _ETLData.m_pETLFrameMap->find( hwndFrame );
					_ASSERTE( it != _ETLData.m_pETLFrameMap->end() );
					if( it == _ETLData.m_pETLFrameMap->end() ) {
						return;
					}
					pFrame = it->second;
					pFrame->OnEvents( hwndView, nEvent, lParam );
					_ETLData.m_pETLFrameMap->erase( it );
					if( _ETLData.m_pETLFrameMap->size() == 0 ){
						if( _ETLData.m_hinstLoc != NULL ){
							pFrame->FreeLocInstance( _ETLData.m_hinstLoc );
							_ETLData.m_hinstLoc = NULL;
						}
					}
				}
				_ETLDeleteFrame( pFrame );
			}
			else if( nEvent & EVENT_CLOSE ){
				ASSERT_STRICT( _ETLData.m_pETLFrameMap->empty() );
				DeleteAllFrames();  // previous versions of EmEditor do not fire EVENT_CLOSE_FRAME.
				delete _ETLData.m_pETLFrameMap;
				_ETLData.m_pETLFrameMap = NULL;
				_ETLData.m_wCmdID = 0;
			}
			else {
				CETLFrameX* pFrame;
				{
					CETLLock lock;
					CETLFrameMap::iterator it = _ETLData.m_pETLFrameMap->find( hwndFrame );
					if( it == _ETLData.m_pETLFrameMap->end() ) {
						return;
					}
					pFrame = it->second;
				}
				if( nEvent & EVENT_UI_CHANGED ){
					if( lParam & UI_CHANGED_LANGUAGE ){
						CETLLock lock;
						if( _ETLData.m_hinstLoc != NULL ){
							_ETLData.m_hinstLoc = pFrame->GetEmedLocInstance();
						}
					}
				}
				pFrame->OnEvents( hwndView, nEvent, lParam );
			}
		}
	}
}


extern "C" LRESULT __stdcall PlugInProc( HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam )
{
	// hwnd can be either view handle, frame handle, or plug-ins settings dialog handle.
	LRESULT lResult = 0;
	switch( nMsg ){
	case EP_GET_BITMAP:
		lResult = CETLFrameX::GetBitmap( wParam );
		break;
	case EP_GET_MASK:
		lResult = CETLFrameX::GetMask( wParam );
		break;
	case EP_GET_NAMEA:
		lResult = CETLFrameX::GetNameA( (LPSTR)lParam, (size_t)wParam );
		break;
	case EP_GET_NAMEW:
		lResult = CETLFrameX::GetNameW( (LPWSTR)lParam, (size_t)wParam );
		break;
	case EP_GET_VERSIONA:
		lResult = CETLFrameX::GetVersionA( (LPSTR)lParam, (size_t)wParam );
		break;
	case EP_GET_VERSIONW:
		lResult = CETLFrameX::GetVersionW( (LPWSTR)lParam, (size_t)wParam );
		break;
	case EP_GET_INFO:
		lResult = CETLFrameX::GetInfo( wParam );
		break;
	case EP_GET_MENU_TEXT:
		lResult = CETLFrameX::GetMenuW( (LPWSTR)lParam, (size_t)wParam );
		break;
	case EP_GET_STATUS_MESSAGE:
		lResult = CETLFrameX::GetStatusW( (LPWSTR)lParam, (size_t)wParam );
		break;
	default:
		{
			// hwnd is plug-ins settings dialog handle or view window handle.
			CETLFrameX* pFrame = GetFrame( hwnd );
			if( pFrame ){
				lResult = pFrame->PlugInProc( hwnd, nMsg, wParam, lParam );
			}
		}
		break;
	}
	return lResult;
}
#pragma warning( pop )
#endif // EE_EXTERN_ONLY
