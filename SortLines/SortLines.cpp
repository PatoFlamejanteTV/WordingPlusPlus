#include "../plugin_interface.h"
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

extern "C" __declspec(dllexport) const wchar_t* GetPluginName()
{
    return L"Sort Lines";
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
    std::wstringstream ss(text);
    std::wstring line;
    std::vector<std::wstring> lines;
    while (std::getline(ss, line))
    {
        if (!line.empty() && line.back() == L'\r')
        {
            line.pop_back();
        }
        lines.push_back(line);
    }

    std::sort(lines.begin(), lines.end());

    std::wstringstream sorted_ss;
    for (size_t i = 0; i < lines.size(); ++i)
    {
        sorted_ss << lines[i];
        if (i < lines.size() - 1)
        {
            sorted_ss << L"\r\n";
        }
    }

    return { PluginResult::Type::TextReplacement, sorted_ss.str() };
}
