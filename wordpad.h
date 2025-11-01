//
// wordpad.h : main header file for the WORDPAD application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "splash.h"
#include "options.h"
#include "afxtempl.h"
#include "PluginManager.h"

#define WPM_BARSTATE WM_USER

/////////////////////////////////////////////////////////////////////////////
// CWordPadCommandLineInfo:
// Handles command-line parsing
//
class CWordPadCommandLineInfo : public CCommandLineInfo
{
public:
    CWordPadCommandLineInfo() { m_bForceTextMode = FALSE; }
    BOOL m_bForceTextMode;
    virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
};

/////////////////////////////////////////////////////////////////////////////
// CWordPadApp:
// Main application class
//
class CWordPadApp : public CWinAppEx
{
public:
    CWordPadApp();
    ~CWordPadApp();

    virtual void PreLoadState();

    // Attributes
    CWordPadCommandLineInfo cmdInfo;
    PluginManager m_pluginManager;
    CDC m_dcScreen;
    LOGFONT m_lf;
    int m_nDefFont;
    static int m_nOpenMsg;
    static int m_nPrinterChangedMsg;
    CRect m_rectPageMargin;
    CRect m_rectInitialFrame;
    BOOL m_bMaximized;
    BOOL m_bPromptForType;
    BOOL m_bWin4;
    BOOL m_bHiColorIcons;

#ifndef _UNICODE
    BOOL m_bWin31;
#endif

    BOOL m_bForceTextMode;
    BOOL m_bWordSel;
    BOOL m_bForceOEM;
    int m_nFilterIndex;
    int m_nNewDocType;

    CDocOptions m_optionsText;
    CDocOptions m_optionsRTF;
    CDocOptions m_optionsWord;
    CDocOptions m_optionsWrite;
    CDocOptions m_optionsIP;
    CDocOptions m_optionsNull;

    CList<HWND, HWND> m_listPrinterNotify;

    BOOL IsDocOpen(LPCTSTR lpszFileName);

    // Getters
    int GetUnits() const { return m_nUnits; }
    int GetTPU() const { return GetTPU(m_nUnits); }
    int GetTPU(int n) const { return m_units[n].m_nTPU; }
    LPCTSTR GetAbbrev() const { return m_units[m_nUnits].m_strAbbrev; }
    LPCTSTR GetAbbrev(int n) const { return m_units[n].m_strAbbrev; }
    const CUnit& GetUnit() const { return m_units[m_nUnits]; }
    CDockState& GetDockState(int nDocType, BOOL bPrimary = TRUE);
    CDocOptions& GetDocOptions(int nDocType);

    // Setters
    void SetUnits(int n)
    {
        ASSERT(n >= 0 && n < m_nPrimaryNumUnits);
        m_nUnits = n;
    }

    // Operations
    void RegisterFormats();
    static BOOL CALLBACK StaticEnumProc(HWND hWnd, LPARAM lParam);
    void UpdateRegistry();
    void NotifyPrinterChanged(BOOL bUpdatePrinterSelection = FALSE);
    BOOL PromptForFileName(CString& fileName, UINT nIDSTitle, DWORD dwFlags,
                           BOOL bOpenFileDialog, int* pType = NULL);
    BOOL ParseMeasurement(TCHAR* buf, int& lVal);
    void PrintTwips(TCHAR* buf, size_t bufSize, int nValue, int nDec);
    void SaveOptions();
    void LoadOptions();
    void LoadAbbrevStrings();

#ifdef CREATE_DEV_NAMES
    HGLOBAL CreateDevNames();
#endif

    // Overrides
    BOOL IsIdleMessage(MSG* pMsg);
    virtual BOOL InitInstance();
    virtual int ExitInstance();
    virtual BOOL OnDDECommand(LPTSTR lpszCommand);
    virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
    virtual BOOL PreTranslateMessage(MSG* pMsg);

    // Implementation
    COleTemplateServer m_server;

    // Message map
    afx_msg void OnAppAbout();
    afx_msg void OnFileNew();
    afx_msg void OnFileOpen();
    afx_msg void OnViewAppLook();

    DECLARE_MESSAGE_MAP()

private:
    int m_nUnits;
    static const int m_nPrimaryNumUnits;
    static const int m_nNumUnits;
    static CUnit m_units[7];
};

extern CWordPadApp theApp;