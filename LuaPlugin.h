#pragma once

#include "PluginAPI/IPlugin.h"
#include "PluginAPI/sol2/sol.hpp"

class LuaPlugin : public IPlugin
{
public:
    LuaPlugin(sol::table plugin_table);
    virtual ~LuaPlugin() = default;

    virtual const wchar_t* GetPluginName() const override;
    virtual const wchar_t* GetPluginAuthor() const override;
    virtual const wchar_t* GetPluginDescription() const override;
    virtual const wchar_t* GetPluginVersion() const override;
    virtual void Execute(CWordPadView* pView) override;
private:
    sol::table m_plugin_table;
    std::wstring m_name;
    std::wstring m_author;
    std::wstring m_description;
    std::wstring m_version;
};
