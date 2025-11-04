#include "stdafx.h"
#include "PluginManager.h"
#include "LuaPlugin.h"
#include "wordpvw.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

typedef IPlugin* (*CreatePluginFunc)();

PluginManager& PluginManager::GetInstance()
{
    static PluginManager instance;
    return instance;
}

PluginManager::PluginManager()
{
    m_lua.open_libraries(sol::lib::base, sol::lib::package);

    // Expose CWordPadView to Lua
    m_lua.new_usertype<CWordPadView>("CWordPadView",
        "GetSelectedText", [](CWordPadView* pView) {
            CString selectedText = pView->GetRichEditCtrl().GetSelText();
            return std::wstring(selectedText);
        },
        "ReplaceSelectedText", [](CWordPadView* pView, const std::wstring& text) {
            pView->GetRichEditCtrl().ReplaceSel(text.c_str(), TRUE); // TRUE to allow undo
        }
    );
}

void PluginManager::LoadPlugins(const std::wstring& folder)
{
    for (const auto& entry : fs::directory_iterator(folder))
    {
        if (entry.is_regular_file())
        {
            if (entry.path().extension() == ".dll")
            {
                HMODULE hModule = LoadLibrary(entry.path().c_str());
                if (hModule != NULL)
                {
                    CreatePluginFunc createPlugin = (CreatePluginFunc)GetProcAddress(hModule, "CreatePlugin");
                    if (createPlugin != NULL)
                    {
                        IPlugin* plugin = createPlugin();
                        if (plugin)
                        {
                            m_plugins.emplace_back(plugin);
                            m_loadedLibraries.push_back(hModule);
                        }
                    }
                    else
                    {
                        FreeLibrary(hModule);
                    }
                }
            }
            else if (entry.path().extension() == ".lua")
            {
                LoadLuaScript(entry.path());
            }
        }
    }
}

void PluginManager::LoadLuaScript(const std::wstring& scriptPath)
{
    try
    {
        auto result = m_lua.safe_script_file(scriptPath.string(), &sol::script_pass_on_error);
        if (result.valid())
        {
            sol::table plugin_table = result;
            m_plugins.emplace_back(std::make_unique<LuaPlugin>(plugin_table));
        }
    }
    catch (const sol::error& e)
    {
        ::OutputDebugStringA("Error loading Lua script: ");
        ::OutputDebugStringA(e.what());
        ::OutputDebugStringA("\n");
    }
}

const std::vector<std::unique_ptr<IPlugin>>& PluginManager::GetPlugins() const
{
    return m_plugins;
}

PluginManager::~PluginManager()
{
    for (HMODULE hModule : m_loadedLibraries)
    {
        FreeLibrary(hModule);
    }
}
