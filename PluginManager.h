#pragma once

#include "plugin_interface.h"
#include <vector>
#include <memory>

// Forward declaration
class CPlugin;

class PluginManager {
public:
    void LoadPlugins(const std::wstring& pluginDir);
    const std::vector<std::shared_ptr<IPlugin>>& GetPlugins() const;

private:
    std::vector<std::shared_ptr<IPlugin>> m_plugins;
};
