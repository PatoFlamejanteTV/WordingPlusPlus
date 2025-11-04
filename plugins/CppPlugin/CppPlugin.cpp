#include "CppPlugin.h"
#include <Windows.h>
#include "wordpvw.h"

extern "C" __declspec(dllexport) IPlugin* CreatePlugin()
{
    return new CppPlugin();
}

const wchar_t* CppPlugin::GetPluginName() const
{
    return L"C++ Example Plugin";
}

const wchar_t* CppPlugin::GetPluginAuthor() const
{
    return L"Jules";
}

const wchar_t* CppPlugin::GetPluginDescription() const
{
    return L"A C++ plugin that displays the selected text.";
}

const wchar_t* CppPlugin::GetPluginVersion() const
{
    return L"1.0";
}

void CppPlugin::Execute(CWordPadView* pView)
{
    if (pView)
    {
        CString selectedText = pView->GetRichEditCtrl().GetSelText();
        if (!selectedText.IsEmpty())
        {
            MessageBox(NULL, selectedText, L"Selected Text", MB_OK);
        }
        else
        {
            MessageBox(NULL, L"No text selected.", L"C++ Plugin", MB_OK);
        }
    }
}
