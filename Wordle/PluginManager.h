#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include "../PluginAPI/IPlugin.h"

struct Plugin
{
    HMODULE hModule;
    PLUGIN_INIT_FUNC onAppInit;
    void (*onPluginClick)();
    void (*onAppClose)();
    std::wstring name;
};

class CPluginManager
{
public:
    CPluginManager();
    ~CPluginManager();

    void LoadPlugins(AppFuncs* appFuncs);
    void UnloadPlugins();

    void OnPluginClick(int index);
    const std::vector<Plugin>& GetPlugins() const { return m_plugins; }

private:
    std::vector<Plugin> m_plugins;
};
