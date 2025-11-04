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
        int requiredSize = g_appFuncs->getSelTxt(NULL, 0);
        if (requiredSize > 0)
        {
            std::string buffer(requiredSize, '\0');
            g_appFuncs->getSelTxt(&buffer[0], requiredSize);
            std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::toupper);
            g_appFuncs->replaceSelTxt(buffer.c_str());
        }
    }
}

extern "C" PLUGIN_API void onAppClose()
{
}
