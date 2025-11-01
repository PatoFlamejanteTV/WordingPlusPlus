#pragma once

#include <string>

// Enum to specify the type of text a plugin requires.
enum TextRequirement {
    TEXT_NONE,
    TEXT_SELECTED,
    TEXT_ALL
};

// Struct to hold information about a plugin's requirements.
struct PluginInfo {
    TextRequirement textRequirement;
    bool wantsFormatted;
};

// Defines the result of a plugin's execution.
struct PluginResult {
    enum class Type { TextReplacement, Information };
    Type type;
    std::wstring content;
};

// Defines the function pointer types that plugins must implement.
typedef const wchar_t* (*GetPluginNameFunc)();
typedef PluginInfo (*GetPluginInfoFunc)();
typedef void (*InitializePluginFunc)();
typedef PluginResult (*ExecutePluginFunc)(const wchar_t* text, bool format);

// Defines the interface for a plugin.
struct IPlugin {
    virtual ~IPlugin() {}
    virtual std::wstring GetName() const = 0;
    virtual PluginInfo GetInfo() const = 0;
    virtual void Initialize() = 0;
    virtual PluginResult Execute(const std::wstring& text, bool format) = 0;
};
