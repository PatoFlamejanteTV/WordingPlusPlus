#include "stdafx.h"
#include "PluginManager.h"
#include <windows.h>
#include <memory>

// Concrete implementation of the IPlugin interface that wraps the DLL functions.
class CPlugin : public IPlugin {
public:
    CPlugin(HMODULE hModule, GetPluginNameFunc getName, GetPluginInfoFunc getInfo, InitializePluginFunc init, ExecutePluginFunc execute)
        : m_hModule(hModule), m_getName(getName), m_getInfo(getInfo), m_init(init), m_execute(execute) {}

    ~CPlugin() {
        if (m_hModule) {
            FreeLibrary(m_hModule);
        }
    }

    std::wstring GetName() const override {
        return m_getName();
    }

    PluginInfo GetInfo() const override {
        return m_getInfo();
    }

    void Initialize() override {
        m_init();
    }

    PluginResult Execute(const std::wstring& text, bool format) override {
        return m_execute(text.c_str(), format);
    }

private:
    HMODULE m_hModule;
    GetPluginNameFunc m_getName;
    GetPluginInfoFunc m_getInfo;
    InitializePluginFunc m_init;
    ExecutePluginFunc m_execute;
};

void PluginManager::LoadPlugins(const std::wstring& pluginDir) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((pluginDir + L"\\*.dll").c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::wstring fullPath = pluginDir + L"\\" + findFileData.cFileName;
            HMODULE hModule = LoadLibraryEx(fullPath.c_str(), NULL, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR);
            if (hModule) {
                GetPluginNameFunc getName = (GetPluginNameFunc)GetProcAddress(hModule, "GetPluginName");
                GetPluginInfoFunc getInfo = (GetPluginInfoFunc)GetProcAddress(hModule, "GetPluginInfo");
                InitializePluginFunc init = (InitializePluginFunc)GetProcAddress(hModule, "InitializePlugin");
                ExecutePluginFunc execute = (ExecutePluginFunc)GetProcAddress(hModule, "ExecutePlugin");

                if (getName && getInfo && init && execute) {
                    auto plugin = std::make_shared<CPlugin>(hModule, getName, getInfo, init, execute);
                    __try {
                        plugin->Initialize();
                        m_plugins.push_back(plugin);
                    }
                    __except(EXCEPTION_EXECUTE_HANDLER) {
                        FreeLibrary(hModule);
                    }
                } else {
                    FreeLibrary(hModule);
                }
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

const std::vector<std::shared_ptr<IPlugin>>& PluginManager::GetPlugins() const {
    return m_plugins;
}
