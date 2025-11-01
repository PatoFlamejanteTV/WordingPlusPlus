#include "../plugin_interface.h"
#include <windows.h>
#include <string>
#include <sstream>

extern "C" __declspec(dllexport) const wchar_t* GetPluginName()
{
    return L"Word Count";
}

extern "C" __declspec(dllexport) PluginInfo GetPluginInfo()
{
    PluginInfo info;
    info.textRequirement = TEXT_SELECTED;
    info.wantsFormatted = false;
    return info;
}

extern "C" __declspec(dllexport) void InitializePlugin()
{
    // No initialization required
}

extern "C" __declspec(dllexport) PluginResult ExecutePlugin(const wchar_t* text, bool /*format*/)
{
    std::wstring inputText(text);
    std::wstringstream wss(inputText);
    std::wstring word;
    int count = 0;
    while (wss >> word)
    {
        count++;
    }

    std::wstring result = L"Word count: " + std::to_wstring(count);
    return { PluginResult::Type::Information, result };
}
