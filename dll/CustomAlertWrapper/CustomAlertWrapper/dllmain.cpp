#include "pch.h"
#include <FlashRuntimeExtensions.h>
#include <Windows.h>
#include <string>
#include <sstream>

// Function to show a native Windows question with customizable button labels and title
int showNativeQuestion(const std::string& message, const std::string& yesLabel, const std::string& noLabel, const std::string& title, bool yesDefault) {
    int type = yesDefault ? (MB_YESNO | MB_DEFBUTTON1) : (MB_YESNO | MB_DEFBUTTON2);
    int result = MessageBoxA(NULL, message.c_str(), title.c_str(), type);

    // Map MessageBox return value to custom action script values
    return (result == IDYES) ? 1 : 0; // Return 1 for Yes, 0 for No
}

// ActionScript function to call the native question with custom parameters
FREObject ASShowNativeQuestion(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
    // Get the message from ActionScript
    uint32_t strLength;
    const uint8_t* asMessage;
    FREGetObjectAsUTF8(argv[0], &strLength, &asMessage);
    std::string message((const char*)asMessage, strLength);

    // Get the Yes button label from ActionScript
    const uint8_t* asYesLabel;
    FREGetObjectAsUTF8(argv[1], &strLength, &asYesLabel);
    std::string yesLabel((const char*)asYesLabel, strLength);

    // Get the No button label from ActionScript
    const uint8_t* asNoLabel;
    FREGetObjectAsUTF8(argv[2], &strLength, &asNoLabel);
    std::string noLabel((const char*)asNoLabel, strLength);

    // Get the title from ActionScript
    const uint8_t* asTitle;
    FREGetObjectAsUTF8(argv[3], &strLength, &asTitle);
    std::string title((const char*)asTitle, strLength);

    // Get the default button choice
    uint32_t yesDefault; // Change to uint32_t
    FREGetObjectAsUint32(argv[4], &yesDefault); // Use FREGetObjectAsUint32

    // Convert to bool
    bool isYesDefault = (yesDefault != 0); // Convert to bool

    // Show the native question with the provided parameters
    int result = showNativeQuestion(message, yesLabel, noLabel, title, isYesDefault);

    // Return the result as an ActionScript object
    FREObject returnValue;
    FRENewObjectFromUint32(result, &returnValue);

    return returnValue;
}

// Context finalizer
void contextFinalizer(FREContext ctx) {
    return;
}

// Context initializer
void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
    static FRENamedFunction extensionFunctions[] = {
        { (const uint8_t*)"show_native_question", NULL, &ASShowNativeQuestion }
    };

    *numFunctionsToSet = sizeof(extensionFunctions) / sizeof(FRENamedFunction);
    *functionsToSet = extensionFunctions;
}

// Extension initializer and finalizer
extern "C" {
    __declspec(dllexport) void ExtensionInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
        *ctxInitializer = &contextInitializer;
        *ctxFinalizer = &contextFinalizer;
    }

    __declspec(dllexport) void ExtensionFinalizer(void* extData) {
        return;
    }
}
