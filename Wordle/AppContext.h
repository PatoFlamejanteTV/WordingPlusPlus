// AppContext.h

#pragma once

#include "stdafx.h"
#include "docopt.h"

class CAppContext
{
public:
    CAppContext();
    ~CAppContext();

    void Load();
    void Save();

    // Application state and options
    LOGFONT m_lf;
    CRect m_rectPageMargin;
    CRect m_rectInitialFrame;
    BOOL m_bMaximized;
    BOOL m_bWordSel;
    int m_nFilterIndex;
    int m_nNewDocType;
    int m_nUnits;

    // Document options
    CDocOptions m_optionsText;
    CDocOptions m_optionsRTF;
    CDocOptions m_optionsWord;
    CDocOptions m_optionsWrite;
    CDocOptions m_optionsIP;
    CDocOptions m_optionsNull;

private:
    void LoadFromRegistry();
    void SaveToRegistry();
};
