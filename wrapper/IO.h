#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

enum IggKey
{
    // Keyboard
    IggKey_None = 0,
    IggKey_Tab = 512,             // == IggKey_NamedKey_BEGIN
    IggKey_LeftArrow,
    IggKey_RightArrow,
    IggKey_UpArrow,
    IggKey_DownArrow,
    IggKey_PageUp,
    IggKey_PageDown,
    IggKey_Home,
    IggKey_End,
    IggKey_Insert,
    IggKey_Delete,
    IggKey_Backspace,
    IggKey_Space,
    IggKey_Enter,
    IggKey_Escape,
    IggKey_LeftCtrl, IggKey_LeftShift, IggKey_LeftAlt, IggKey_LeftSuper,
    IggKey_RightCtrl, IggKey_RightShift, IggKey_RightAlt, IggKey_RightSuper,
    IggKey_Menu,
    IggKey_0, IggKey_1, IggKey_2, IggKey_3, IggKey_4, IggKey_5, IggKey_6, IggKey_7, IggKey_8, IggKey_9,
    IggKey_A, IggKey_B, IggKey_C, IggKey_D, IggKey_E, IggKey_F, IggKey_G, IggKey_H, IggKey_I, IggKey_J,
    IggKey_K, IggKey_L, IggKey_M, IggKey_N, IggKey_O, IggKey_P, IggKey_Q, IggKey_R, IggKey_S, IggKey_T,
    IggKey_U, IggKey_V, IggKey_W, IggKey_X, IggKey_Y, IggKey_Z,
    IggKey_F1, IggKey_F2, IggKey_F3, IggKey_F4, IggKey_F5, IggKey_F6,
    IggKey_F7, IggKey_F8, IggKey_F9, IggKey_F10, IggKey_F11, IggKey_F12,
    IggKey_Apostrophe,        // '
    IggKey_Comma,             // ,
    IggKey_Minus,             // -
    IggKey_Period,            // .
    IggKey_Slash,             // /
    IggKey_Semicolon,         // ;
    IggKey_Equal,             // =
    IggKey_LeftBracket,       // [
    IggKey_Backslash,         // \ (this text inhibit multiline comment caused by backslash)
    IggKey_RightBracket,      // ]
    IggKey_GraveAccent,       // `
    IggKey_CapsLock,
    IggKey_ScrollLock,
    IggKey_NumLock,
    IggKey_PrintScreen,
    IggKey_Pause,
    IggKey_Keypad0, IggKey_Keypad1, IggKey_Keypad2, IggKey_Keypad3, IggKey_Keypad4,
    IggKey_Keypad5, IggKey_Keypad6, IggKey_Keypad7, IggKey_Keypad8, IggKey_Keypad9,
    IggKey_KeypadDecimal,
    IggKey_KeypadDivide,
    IggKey_KeypadMultiply,
    IggKey_KeypadSubtract,
    IggKey_KeypadAdd,
    IggKey_KeypadEnter,
    IggKey_KeypadEqual,

    // Gamepad (some of those are analog values, 0.0f to 1.0f)                              // NAVIGATION action
    IggKey_GamepadStart,          // Menu (Xbox)          + (Switch)   Start/Options (PS) // --
    IggKey_GamepadBack,           // View (Xbox)          - (Switch)   Share (PS)         // --
    IggKey_GamepadFaceUp,         // Y (Xbox)             X (Switch)   Triangle (PS)      // -> ImGuiNavInput_Input
    IggKey_GamepadFaceDown,       // A (Xbox)             B (Switch)   Cross (PS)         // -> ImGuiNavInput_Activate
    IggKey_GamepadFaceLeft,       // X (Xbox)             Y (Switch)   Square (PS)        // -> ImGuiNavInput_Menu
    IggKey_GamepadFaceRight,      // B (Xbox)             A (Switch)   Circle (PS)        // -> ImGuiNavInput_Cancel
    IggKey_GamepadDpadUp,         // D-pad Up                                             // -> ImGuiNavInput_DpadUp
    IggKey_GamepadDpadDown,       // D-pad Down                                           // -> ImGuiNavInput_DpadDown
    IggKey_GamepadDpadLeft,       // D-pad Left                                           // -> ImGuiNavInput_DpadLeft
    IggKey_GamepadDpadRight,      // D-pad Right                                          // -> ImGuiNavInput_DpadRight
    IggKey_GamepadL1,             // L Bumper (Xbox)      L (Switch)   L1 (PS)            // -> ImGuiNavInput_FocusPrev + ImGuiNavInput_TweakSlow
    IggKey_GamepadR1,             // R Bumper (Xbox)      R (Switch)   R1 (PS)            // -> ImGuiNavInput_FocusNext + ImGuiNavInput_TweakFast
    IggKey_GamepadL2,             // L Trigger (Xbox)     ZL (Switch)  L2 (PS) [Analog]
    IggKey_GamepadR2,             // R Trigger (Xbox)     ZR (Switch)  R2 (PS) [Analog]
    IggKey_GamepadL3,             // L Thumbstick (Xbox)  L3 (Switch)  L3 (PS)
    IggKey_GamepadR3,             // R Thumbstick (Xbox)  R3 (Switch)  R3 (PS)
    IggKey_GamepadLStickUp,       // [Analog]                                             // -> ImGuiNavInput_LStickUp
    IggKey_GamepadLStickDown,     // [Analog]                                             // -> ImGuiNavInput_LStickDown
    IggKey_GamepadLStickLeft,     // [Analog]                                             // -> ImGuiNavInput_LStickLeft
    IggKey_GamepadLStickRight,    // [Analog]                                             // -> ImGuiNavInput_LStickRight
    IggKey_GamepadRStickUp,       // [Analog]
    IggKey_GamepadRStickDown,     // [Analog]
    IggKey_GamepadRStickLeft,     // [Analog]
    IggKey_GamepadRStickRight,    // [Analog]

    // Keyboard Modifiers
    // - This is mirroring the data also written to io.KeyCtrl, io.KeyShift, io.KeyAlt, io.KeySuper, in a format allowing
    //   them to be accessed via standard key API, allowing calls such as IsKeyPressed(), IsKeyReleased(), querying duration etc.
    // - Code polling every keys (e.g. an interface to detect a key press for input mapping) might want to ignore those
    //   and prefer using the real keys (e.g. IggKey_LeftCtrl, IggKey_RightCtrl instead of IggKey_ModCtrl).
    // - In theory the value of keyboard modifiers should be roughly equivalent to a logical or of the equivalent left/right keys.
    //   In practice: it's complicated; mods are often provided from different sources. Keyboard layout, IME, sticky keys and
    //   backends tend to interfere and break that equivalence. The safer decision is to relay that ambiguity down to the end-user...
    IggKey_ModCtrl,
    IggKey_ModShift,
    IggKey_ModAlt,
    IggKey_ModSuper,

    IggKey_COUNT,                 // No valid IggKey is ever greater than this value

    // [Internal] Prior to 1.87 we required user to fill io.KeysDown[512] using their own native index + a io.KeyMap[] array.
    // We are ditching this method but keeping a legacy path for user code doing e.g. IsKeyPressed(MY_NATIVE_KEY_CODE)
    IggKey_NamedKey_BEGIN         = 512,
    IggKey_NamedKey_END           = IggKey_COUNT,
    IggKey_NamedKey_COUNT         = IggKey_NamedKey_END - IggKey_NamedKey_BEGIN,
    IggKey_KeysData_SIZE          = IggKey_NamedKey_COUNT,          // Size of KeysData[]: only hold named keys
    IggKey_KeysData_OFFSET        = IggKey_NamedKey_BEGIN           // First key stored in KeysData[0]

    , IggKey_KeyPadEnter = IggKey_KeypadEnter   // Renamed in 1.87
};

extern IggIO iggGetCurrentIO(void);

extern IggBool iggWantCaptureMouse(IggIO handle);
extern IggBool iggWantCaptureMouseUnlessPopupClose(IggIO handle);
extern IggBool iggWantCaptureKeyboard(IggIO handle);
extern IggBool iggWantTextInput(IggIO handle);
extern float iggFramerate(IggIO handle);
extern int iggMetricsRenderVertices(IggIO handle);
extern int iggMetricsRenderIndices(IggIO handle);
extern int iggMetricsRenderWindows(IggIO handle);
extern int iggMetricsActiveWindows(IggIO handle);
extern int iggMetricsActiveAllocations(IggIO handle);
extern void iggMouseDelta(IggIO handle, IggVec2 *value);
extern void iggMouseWheel(IggIO handle, float *mouseWheelH, float *mouseWheel);
extern void iggDisplayFrameBufferScale(IggIO handle, IggVec2 *value);
extern IggFontAtlas iggIoGetFonts(IggIO handle);

extern void iggIoSetDisplaySize(IggIO handle, IggVec2 const *value);
extern void iggIoSetDisplayFrameBufferScale(IggIO handle, IggVec2 const *value);
extern void iggIoGetMousePosition(IggIO handle, IggVec2 *value);
extern void iggIoSetMousePosition(IggIO handle, IggVec2 const *value);
extern void iggIoSetMouseButtonDown(IggIO handle, int index, IggBool value);
extern void iggIoAddMouseWheelDelta(IggIO handle, float x, float y);
extern void iggIoSetDeltaTime(IggIO handle, float value);
extern void iggIoSetFontGlobalScale(IggIO handle, float value);

extern void iggIoAddKeyEvent(IggIO handle, int key, IggBool down);
extern void iggIoKeyCtrl(IggIO handle, IggBool down);
extern IggBool iggIoKeyCtrlPressed(IggIO handle);
extern void iggIoKeyShift(IggIO handle, IggBool down);
extern IggBool iggIoKeyShiftPressed(IggIO handle);
extern void iggIoKeyAlt(IggIO handle, IggBool down);
extern IggBool iggIoKeyAltPressed(IggIO handle);
extern void iggIoKeySuper(IggIO handle, IggBool down);
extern IggBool iggIoKeySuperPressed(IggIO handle);
extern void iggIoAddInputCharactersUTF8(IggIO handle, char const *utf8Chars);
extern void iggIoSetIniFilename(IggIO handle, char const *value);
extern void iggIoSetConfigFlags(IggIO handle, int flags);
extern void iggIoSetBackendFlags(IggIO handle, int flags);
extern int iggIoGetBackendFlags(IggIO handle);
extern void iggIoSetMouseDrawCursor(IggIO handle, IggBool show);

extern void iggIoRegisterClipboardFunctions(IggIO handle);
extern void iggIoClearClipboardFunctions(IggIO handle);

#ifdef __cplusplus
}
#endif
