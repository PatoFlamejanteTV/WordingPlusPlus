#include "stdafx.h"
#include "LuaPlugin.h"
#include "wordpvw.h"

LuaPlugin::LuaPlugin(sol::table plugin_table)
    : m_plugin_table(plugin_table)
{
    m_name = m_plugin_table.get_or<std::wstring>(L"name", L"Unnamed Lua Plugin");
    m_author = m_plugin_table.get_or<std::wstring>(L"author", L"Unknown");
    m_description = m_plugin_table.get_or<std::wstring>(L"description", L"");
    m_version = m_plugin_table.get_or<std::wstring>(L"version", L"1.0");
}

const wchar_t* LuaPlugin::GetPluginName() const
{
    return m_name.c_str();
}

const wchar_t* LuaPlugin::GetPluginAuthor() const
{
    return m_author.c_str();
}

const wchar_t* LuaPlugin::GetPluginDescription() const
{
    return m_description.c_str();
}

const wchar_t* LuaPlugin::GetPluginVersion() const
{
    return m_version.c_str();
}

void LuaPlugin::Execute(CWordPadView* pView)
{
    sol::protected_function execute_func = m_plugin_table["Execute"];
    if (execute_func.valid())
    {
        auto result = execute_func(pView);
        if (!result.valid())
        {
            sol::error err = result;
            ::OutputDebugStringA("Error executing Lua plugin: ");
            ::OutputDebugStringA(err.what());
            ::OutputDebugStringA("\n");
        }
    }
}
