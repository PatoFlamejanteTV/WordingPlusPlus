#include "pch.h"
#include "../../PluginAPI/IPlugin.h"
#include "wordpvw.h"
#include <ctime>

class ExamplePlugin : public IPlugin
{
public:
    virtual const wchar_t* GetPluginName() const override
    {
        return L"Insert Timestamp";
    }

    virtual const wchar_t* GetPluginAuthor() const override
    {
        return L"Jules";
    }

    virtual const wchar_t* GetPluginDescription() const override
    {
        return L"Inserts the current timestamp into the document.";
    }

    virtual const wchar_t* GetPluginVersion() const override
    {
        return L"1.0";
    }

    virtual void Execute(CWordPadView* pView) override
    {
        if (pView)
        {
            time_t now = time(0);
            wchar_t buf[26];
            _wctime_s(buf, sizeof(buf), &now);
            pView->GetRichEditCtrl().ReplaceSel(CString(buf));
        }
    }
};

extern "C" __declspec(dllexport) IPlugin* CreatePlugin()
{
    return new ExamplePlugin();
}
