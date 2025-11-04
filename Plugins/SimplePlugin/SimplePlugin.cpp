#include <windows.h>
#include <algorithm>
#include <string>
#include "../../PluginAPI/IPlugin.h"

AppFuncs* g_appFuncs = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" PLUGIN_API void onAppInit(AppFuncs* funcs)
{
    g_appFuncs = funcs;
}

extern "C" PLUGIN_API void onPluginClick()
{
    if (g_appFuncs && g_appFuncs->getSelTxt && g_appFuncs->replaceSelTxt)
    {
        char buffer[1024] = { 0 };
        g_appFuncs->getSelTxt(buffer, sizeof(buffer));

        std::string text(buffer);
        std::transform(text.begin(), text.end(), text.begin(), ::toupper);

        g_appFuncs->replaceSelTxt(text.c_str());
    }
}

extern "C" PLUGIN_API void onAppClose()
{
}
