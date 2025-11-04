#include "stdafx.h"
#include "PluginManager.h"
#include <filesystem>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

CPluginManager::CPluginManager()
{
}

CPluginManager::~CPluginManager()
{
    UnloadPlugins();
}

void CPluginManager::LoadPlugins(AppFuncs* appFuncs)
{
    std::filesystem::path pluginDir = std::filesystem::current_path() / "plugins";
    if (!std::filesystem::exists(pluginDir))
    {
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(pluginDir))
    {
        if (entry.path().extension() == ".dll")
        {
            HMODULE hModule = LoadLibrary(entry.path().c_str());
            if (hModule)
            {
                Plugin plugin;
                plugin.hModule = hModule;
                plugin.onAppInit = (PLUGIN_INIT_FUNC)GetProcAddress(hModule, "onAppInit");
                plugin.onPluginClick = (void (*)())GetProcAddress(hModule, "onPluginClick");
                plugin.onAppClose = (void (*)())GetProcAddress(hModule, "onAppClose");

                if (plugin.onAppInit && plugin.onPluginClick && plugin.onAppClose)
                {
                    plugin.onAppInit(appFuncs);
                    wchar_t buffer[MAX_PATH];
                    GetModuleFileName(hModule, buffer, MAX_PATH);
                    PathStripPath(buffer);
                    plugin.name = buffer;
                    m_plugins.push_back(plugin);
                }
                else
                {
                    FreeLibrary(hModule);
                }
            }
        }
    }
}

void CPluginManager::UnloadPlugins()
{
    for (auto& plugin : m_plugins)
    {
        if (plugin.onAppClose)
        {
            plugin.onAppClose();
        }
        FreeLibrary(plugin.hModule);
    }
    m_plugins.clear();
}

void CPluginManager::OnPluginClick(int index)
{
    if (index >= 0 && index < m_plugins.size())
    {
        if (m_plugins[index].onPluginClick)
        {
            m_plugins[index].onPluginClick();
        }
    }
}
