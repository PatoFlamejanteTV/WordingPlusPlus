// AppContext.cpp

#include "stdafx.h"
#include "AppContext.h"
#include "strings.h" // For szSection, etc.

CAppContext::CAppContext() :
    m_optionsText(0), m_optionsRTF(1),
    m_optionsWord(2), m_optionsWrite(2), m_optionsIP(2), m_optionsNull(0)
{
}

CAppContext::~CAppContext()
{
}

void CAppContext::Load()
{
    LoadFromRegistry();
}

void CAppContext::Save()
{
    SaveToRegistry();
}

void CAppContext::LoadFromRegistry()
{
    CWinApp* pApp = AfxGetApp();
    BYTE* pb = NULL;
    UINT nLen = 0;

    HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    if (hFont == NULL)
        hFont = (HFONT)GetStockObject(ANSI_VAR_FONT);
    VERIFY(::GetObject(hFont, sizeof(LOGFONT), &m_lf));

    m_bWordSel = pApp->GetProfileInt(szSection, szWordSel, TRUE);
    TCHAR buf[2];
    buf[0] = NULL;
    GetLocaleInfo(GetUserDefaultLCID(), LOCALE_IMEASURE, buf, 2);
    int nDefUnits = buf[0] == '1' ? 0 : 1;
    m_nUnits = pApp->GetProfileInt(szSection, szUnits, nDefUnits);
    m_bMaximized = pApp->GetProfileInt(szSection, szMaximized, (int)FALSE);

    if (pApp->GetProfileBinary(szSection, szFrameRect, &pb, &nLen))
    {
        ASSERT(nLen == sizeof(CRect));
        memcpy(&m_rectInitialFrame, pb, sizeof(CRect));
        delete pb;
    }
    else
        m_rectInitialFrame.SetRect(0,0,0,0);

    CRect rectScreen(0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    CRect rectInt;
    rectInt.IntersectRect(&rectScreen, &m_rectInitialFrame);
    if (rectInt.Width() < 10 || rectInt.Height() < 10)
        m_rectInitialFrame.SetRect(0, 0, 0, 0);

    if (pApp->GetProfileBinary(szSection, szPageMargin, &pb, &nLen))
    {
        ASSERT(nLen == sizeof(CRect));
        memcpy(&m_rectPageMargin, pb, sizeof(CRect));
        delete pb;
    }
    else
        m_rectPageMargin.SetRect(1800, 1440, 1800, 1440);

    m_optionsText.LoadOptions(szTextSection);
    m_optionsRTF.LoadOptions(szRTFSection);
    m_optionsWord.LoadOptions(szWordSection);
    m_optionsWrite.LoadOptions(szWriteSection);
    m_optionsIP.LoadOptions(szIPSection);
}

void CAppContext::SaveToRegistry()
{
    CWinApp* pApp = AfxGetApp();
    pApp->WriteProfileInt(szSection, szWordSel, m_bWordSel);
    pApp->WriteProfileInt(szSection, szUnits, m_nUnits);
    pApp->WriteProfileInt(szSection, szMaximized, m_bMaximized);
    pApp->WriteProfileBinary(szSection, szFrameRect, (BYTE*)&m_rectInitialFrame, sizeof(CRect));
    pApp->WriteProfileBinary(szSection, szPageMargin, (BYTE*)&m_rectPageMargin, sizeof(CRect));

    m_optionsText.SaveOptions(szTextSection);
    m_optionsRTF.SaveOptions(szRTFSection);
    m_optionsWord.SaveOptions(szWordSection);
    m_optionsWrite.SaveOptions(szWriteSection);
    m_optionsIP.SaveOptions(szIPSection);
}
