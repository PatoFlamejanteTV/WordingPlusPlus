#pragma once

#include <vector>
#include <memory>
#include "PluginAPI/IPlugin.h"
#include <Windows.h>

#include "PluginAPI/sol2/sol.hpp"

class PluginManager
{
public:
    static PluginManager& GetInstance();
    void LoadPlugins(const std::wstring& folder);
    const std::vector<std::unique_ptr<IPlugin>>& GetPlugins() const;
    void LoadLuaScript(const std::wstring& scriptPath);

private:
    PluginManager();
    ~PluginManager();

    sol::state m_lua;
    std::vector<std::unique_ptr<IPlugin>> m_plugins;
    std::vector<HMODULE> m_loadedLibraries;

    // Prevent copying
    PluginManager(const PluginManager&) = delete;
    void operator=(const PluginManager&) = delete;
};
