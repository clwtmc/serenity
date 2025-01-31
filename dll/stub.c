#include <windows.h>

extern VOID dll_ThreadEntry(VOID);

/**
 * @brief Entry point for the DLL.
 *
 * This function is called by the system when the DLL is loaded or unloaded.
 * It handles process attachment and detachment events.
 *
 * @param hInstance Handle to the DLL module.
 * @param fdwReason Reason for calling the function:
 *                  DLL_PROCESS_ATTACH, DLL_THREAD_ATTACH,
 *                  DLL_THREAD_DETACH, or DLL_PROCESS_DETACH.
 * @param lpvReserved Reserved, always NULL.
 *
 * @return TRUE if the initialization succeeds, FALSE otherwise.
 */
BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            // Create a thread calling ThreadEntry from main.pink
            CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)dll_ThreadEntry, hInstance, 0, NULL);
            return TRUE;
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

