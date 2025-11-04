#ifndef IPLUGIN_H
#define IPLUGIN_H

#ifdef PLUGIN_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif

// Forward declaration of AppFuncs
struct AppFuncs;

// Plugin entry point function signature
typedef void (*PLUGIN_INIT_FUNC)(AppFuncs*);

extern "C" {
    PLUGIN_API void onAppInit(AppFuncs* funcs);
    PLUGIN_API void onPluginClick();
    PLUGIN_API void onAppClose();
}

// Function pointer types for application callbacks
typedef void (*GET_SEL_TEXT_FUNC)(char* buffer, int bufferSize);
typedef void (*REPLACE_SEL_TEXT_FUNC)(const char* newText);

// Struct to hold function pointers from the application
struct AppFuncs {
    GET_SEL_TEXT_FUNC getSelTxt;
    REPLACE_SEL_TEXT_FUNC replaceSelTxt;
};

#endif // IPLUGIN_H
