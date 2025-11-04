#pragma once

#include "../../PluginAPI/IPlugin.h"

class CppPlugin : public IPlugin
{
public:
    virtual const wchar_t* GetPluginName() const override;
    virtual const wchar_t* GetPluginAuthor() const override;
    virtual const wchar_t* GetPluginDescription() const override;
    virtual const wchar_t* GetPluginVersion() const override;
    virtual void Execute(CWordPadView* pView) override;
};
