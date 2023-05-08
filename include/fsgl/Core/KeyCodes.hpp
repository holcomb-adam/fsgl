#pragma once

// --- Standard ---
#include <type_traits>



// TODO: These key codes should be placed in a seperate file
// From glfw3 key codes
#define FSGL_IMPL_KEY_UNKNOWN            -1
#define FSGL_IMPL_KEY_SPACE              32
#define FSGL_IMPL_KEY_APOSTROPHE         39  /* ' */
#define FSGL_IMPL_KEY_COMMA              44  /* , */
#define FSGL_IMPL_KEY_MINUS              45  /* - */
#define FSGL_IMPL_KEY_PERIOD             46  /* . */
#define FSGL_IMPL_KEY_SLASH              47  /* / */
#define FSGL_IMPL_KEY_0                  48
#define FSGL_IMPL_KEY_1                  49
#define FSGL_IMPL_KEY_2                  50
#define FSGL_IMPL_KEY_3                  51
#define FSGL_IMPL_KEY_4                  52
#define FSGL_IMPL_KEY_5                  53
#define FSGL_IMPL_KEY_6                  54
#define FSGL_IMPL_KEY_7                  55
#define FSGL_IMPL_KEY_8                  56
#define FSGL_IMPL_KEY_9                  57
#define FSGL_IMPL_KEY_SEMICOLON          59  /* ; */
#define FSGL_IMPL_KEY_EQUAL              61  /* = */
#define FSGL_IMPL_KEY_A                  65
#define FSGL_IMPL_KEY_B                  66
#define FSGL_IMPL_KEY_C                  67
#define FSGL_IMPL_KEY_D                  68
#define FSGL_IMPL_KEY_E                  69
#define FSGL_IMPL_KEY_F                  70
#define FSGL_IMPL_KEY_G                  71
#define FSGL_IMPL_KEY_H                  72
#define FSGL_IMPL_KEY_I                  73
#define FSGL_IMPL_KEY_J                  74
#define FSGL_IMPL_KEY_K                  75
#define FSGL_IMPL_KEY_L                  76
#define FSGL_IMPL_KEY_M                  77
#define FSGL_IMPL_KEY_N                  78
#define FSGL_IMPL_KEY_O                  79
#define FSGL_IMPL_KEY_P                  80
#define FSGL_IMPL_KEY_Q                  81
#define FSGL_IMPL_KEY_R                  82
#define FSGL_IMPL_KEY_S                  83
#define FSGL_IMPL_KEY_T                  84
#define FSGL_IMPL_KEY_U                  85
#define FSGL_IMPL_KEY_V                  86
#define FSGL_IMPL_KEY_W                  87
#define FSGL_IMPL_KEY_X                  88
#define FSGL_IMPL_KEY_Y                  89
#define FSGL_IMPL_KEY_Z                  90
#define FSGL_IMPL_KEY_LEFT_BRACKET       91  /* [ */
#define FSGL_IMPL_KEY_BACKSLASH          92  /* \ */
#define FSGL_IMPL_KEY_RIGHT_BRACKET      93  /* ] */
#define FSGL_IMPL_KEY_GRAVE_ACCENT       96  /* ` */
#define FSGL_IMPL_KEY_WORLD_1            161 /* non-US #1 */
#define FSGL_IMPL_KEY_WORLD_2            162 /* non-US #2 */
#define FSGL_IMPL_KEY_ESCAPE             256
#define FSGL_IMPL_KEY_ENTER              257
#define FSGL_IMPL_KEY_TAB                258
#define FSGL_IMPL_KEY_BACKSPACE          259
#define FSGL_IMPL_KEY_INSERT             260
#define FSGL_IMPL_KEY_DELETE             261
#define FSGL_IMPL_KEY_RIGHT              262
#define FSGL_IMPL_KEY_LEFT               263
#define FSGL_IMPL_KEY_DOWN               264
#define FSGL_IMPL_KEY_UP                 265
#define FSGL_IMPL_KEY_PAGE_UP            266
#define FSGL_IMPL_KEY_PAGE_DOWN          267
#define FSGL_IMPL_KEY_HOME               268
#define FSGL_IMPL_KEY_END                269
#define FSGL_IMPL_KEY_CAPS_LOCK          280
#define FSGL_IMPL_KEY_SCROLL_LOCK        281
#define FSGL_IMPL_KEY_NUM_LOCK           282
#define FSGL_IMPL_KEY_PRINT_SCREEN       283
#define FSGL_IMPL_KEY_PAUSE              284
#define FSGL_IMPL_KEY_F1                 290
#define FSGL_IMPL_KEY_F2                 291
#define FSGL_IMPL_KEY_F3                 292
#define FSGL_IMPL_KEY_F4                 293
#define FSGL_IMPL_KEY_F5                 294
#define FSGL_IMPL_KEY_F6                 295
#define FSGL_IMPL_KEY_F7                 296
#define FSGL_IMPL_KEY_F8                 297
#define FSGL_IMPL_KEY_F9                 298
#define FSGL_IMPL_KEY_F10                299
#define FSGL_IMPL_KEY_F11                300
#define FSGL_IMPL_KEY_F12                301
#define FSGL_IMPL_KEY_F13                302
#define FSGL_IMPL_KEY_F14                303
#define FSGL_IMPL_KEY_F15                304
#define FSGL_IMPL_KEY_F16                305
#define FSGL_IMPL_KEY_F17                306
#define FSGL_IMPL_KEY_F18                307
#define FSGL_IMPL_KEY_F19                308
#define FSGL_IMPL_KEY_F20                309
#define FSGL_IMPL_KEY_F21                310
#define FSGL_IMPL_KEY_F22                311
#define FSGL_IMPL_KEY_F23                312
#define FSGL_IMPL_KEY_F24                313
#define FSGL_IMPL_KEY_F25                314
#define FSGL_IMPL_KEY_KP_0               320
#define FSGL_IMPL_KEY_KP_1               321
#define FSGL_IMPL_KEY_KP_2               322
#define FSGL_IMPL_KEY_KP_3               323
#define FSGL_IMPL_KEY_KP_4               324
#define FSGL_IMPL_KEY_KP_5               325
#define FSGL_IMPL_KEY_KP_6               326
#define FSGL_IMPL_KEY_KP_7               327
#define FSGL_IMPL_KEY_KP_8               328
#define FSGL_IMPL_KEY_KP_9               329
#define FSGL_IMPL_KEY_KP_DECIMAL         330
#define FSGL_IMPL_KEY_KP_DIVIDE          331
#define FSGL_IMPL_KEY_KP_MULTIPLY        332
#define FSGL_IMPL_KEY_KP_SUBTRACT        333
#define FSGL_IMPL_KEY_KP_ADD             334
#define FSGL_IMPL_KEY_KP_ENTER           335
#define FSGL_IMPL_KEY_KP_EQUAL           336
#define FSGL_IMPL_KEY_LEFT_SHIFT         340
#define FSGL_IMPL_KEY_LEFT_CONTROL       341
#define FSGL_IMPL_KEY_LEFT_ALT           342
#define FSGL_IMPL_KEY_LEFT_SUPER         343
#define FSGL_IMPL_KEY_RIGHT_SHIFT        344
#define FSGL_IMPL_KEY_RIGHT_CONTROL      345
#define FSGL_IMPL_KEY_RIGHT_ALT          346
#define FSGL_IMPL_KEY_RIGHT_SUPER        347
#define FSGL_IMPL_KEY_MENU				348

#define FSGL_IMPL_KEY_LAST               FSGL_KEY_MENU





namespace fsgl
{
	enum class KeyCode : std::int32_t
	{
		////////////////////////////////////////////////////////////////////////////////
		// - UNKNOWN KEY ---------------------------------------------------------------

		Unknown							= FSGL_IMPL_KEY_UNKNOWN,



		////////////////////////////////////////////////////////////////////////////////
		// - PRINTABLE KEYS ------------------------------------------------------------
		
		Space							= FSGL_IMPL_KEY_SPACE,
		A								= FSGL_IMPL_KEY_A,
		B								= FSGL_IMPL_KEY_B,
		C								= FSGL_IMPL_KEY_C,
		D								= FSGL_IMPL_KEY_D,
		E								= FSGL_IMPL_KEY_E,
		F								= FSGL_IMPL_KEY_F,
		G								= FSGL_IMPL_KEY_G,
		H								= FSGL_IMPL_KEY_H,
		I								= FSGL_IMPL_KEY_I,
		J								= FSGL_IMPL_KEY_J,
		K								= FSGL_IMPL_KEY_K,
		L								= FSGL_IMPL_KEY_L,
		M								= FSGL_IMPL_KEY_M,
		N								= FSGL_IMPL_KEY_N,
		O								= FSGL_IMPL_KEY_O,
		P								= FSGL_IMPL_KEY_P,
		Q								= FSGL_IMPL_KEY_Q,
		R								= FSGL_IMPL_KEY_R,
		S								= FSGL_IMPL_KEY_S,
		T								= FSGL_IMPL_KEY_T,
		U								= FSGL_IMPL_KEY_U,
		V								= FSGL_IMPL_KEY_V,
		W								= FSGL_IMPL_KEY_W,
		X								= FSGL_IMPL_KEY_X,
		Y								= FSGL_IMPL_KEY_Y,
		Z								= FSGL_IMPL_KEY_Z,
		LeftBracket						= FSGL_IMPL_KEY_LEFT_BRACKET,   // '['
		BackSlash						= FSGL_IMPL_KEY_BACKSLASH,      // '\'
		RightBracket					= FSGL_IMPL_KEY_RIGHT_BRACKET,  // ']'
		Grave							= FSGL_IMPL_KEY_GRAVE_ACCENT,   // '`'
		World_1							= FSGL_IMPL_KEY_WORLD_1,        // non-US #1
		World_2                         = FSGL_IMPL_KEY_WORLD_2,        // non-US #2



		////////////////////////////////////////////////////////////////////////////////
		// - FUNCTION KEYS -------------------------------------------------------------

		Escape							= FSGL_IMPL_KEY_ESCAPE,
		Enter							= FSGL_IMPL_KEY_ENTER,
		Tab								= FSGL_IMPL_KEY_TAB,
		Backspace						= FSGL_IMPL_KEY_BACKSPACE,
		Insert							= FSGL_IMPL_KEY_INSERT,
		Delete							= FSGL_IMPL_KEY_DELETE,
		Right							= FSGL_IMPL_KEY_RIGHT,
		Left							= FSGL_IMPL_KEY_LEFT,
		Down							= FSGL_IMPL_KEY_DOWN,
		Up								= FSGL_IMPL_KEY_UP,
		PageUp							= FSGL_IMPL_KEY_PAGE_UP,
		PageDown						= FSGL_IMPL_KEY_PAGE_DOWN,
		Home							= FSGL_IMPL_KEY_HOME,
		End								= FSGL_IMPL_KEY_END,
		CapsLock						= FSGL_IMPL_KEY_CAPS_LOCK,
		ScrollLock						= FSGL_IMPL_KEY_SCROLL_LOCK,
		NumLock							= FSGL_IMPL_KEY_NUM_LOCK,
		PrintScreen						= FSGL_IMPL_KEY_PRINT_SCREEN,
		Pause							= FSGL_IMPL_KEY_PAUSE,
		F1								= FSGL_IMPL_KEY_F1,
		F2								= FSGL_IMPL_KEY_F2,
		F3								= FSGL_IMPL_KEY_F3,
		F4								= FSGL_IMPL_KEY_F4,
		F5								= FSGL_IMPL_KEY_F5,
		F6								= FSGL_IMPL_KEY_F6,
		F7								= FSGL_IMPL_KEY_F7,
		F8								= FSGL_IMPL_KEY_F8,
		F9								= FSGL_IMPL_KEY_F9,
		F10								= FSGL_IMPL_KEY_F10,
		F11								= FSGL_IMPL_KEY_F11,
		F12								= FSGL_IMPL_KEY_F12,
		F13								= FSGL_IMPL_KEY_F13,
		F14								= FSGL_IMPL_KEY_F14,
		F15								= FSGL_IMPL_KEY_F15,
		F16								= FSGL_IMPL_KEY_F16,
		F17								= FSGL_IMPL_KEY_F17,
		F18								= FSGL_IMPL_KEY_F18,
		F19								= FSGL_IMPL_KEY_F19,
		F20								= FSGL_IMPL_KEY_F20,
		F21								= FSGL_IMPL_KEY_F21,
		F22								= FSGL_IMPL_KEY_F22,
		F23								= FSGL_IMPL_KEY_F23,
		F24								= FSGL_IMPL_KEY_F24,
		F25								= FSGL_IMPL_KEY_F25,



		////////////////////////////////////////////////////////////////////////////////
		// - KEYPAD KEYS ---------------------------------------------------------------

		KP_0							= FSGL_IMPL_KEY_KP_0,
		KP_1							= FSGL_IMPL_KEY_KP_1,
		KP_2							= FSGL_IMPL_KEY_KP_2,
		KP_3							= FSGL_IMPL_KEY_KP_3,
		KP_4							= FSGL_IMPL_KEY_KP_4,
		KP_5							= FSGL_IMPL_KEY_KP_5,
		KP_6							= FSGL_IMPL_KEY_KP_6,
		KP_7							= FSGL_IMPL_KEY_KP_7,
		KP_8							= FSGL_IMPL_KEY_KP_8,
		KP_9							= FSGL_IMPL_KEY_KP_9,
		KP_Decimal						= FSGL_IMPL_KEY_KP_DECIMAL,
		KP_Divide						= FSGL_IMPL_KEY_KP_DIVIDE,
		KP_Multiply						= FSGL_IMPL_KEY_KP_MULTIPLY,
		KP_Subtract						= FSGL_IMPL_KEY_KP_SUBTRACT,
		KP_Add							= FSGL_IMPL_KEY_KP_ADD,
		KP_Enter						= FSGL_IMPL_KEY_KP_ENTER,
		KP_Equal						= FSGL_IMPL_KEY_KP_EQUAL,



		////////////////////////////////////////////////////////////////////////////////
		// - KEY MODIFIERS -------------------------------------------------------------

		LeftShift						= FSGL_IMPL_KEY_LEFT_SHIFT,
		LeftControl						= FSGL_IMPL_KEY_LEFT_CONTROL,
		LeftAlt							= FSGL_IMPL_KEY_LEFT_ALT,
		LeftSuper						= FSGL_IMPL_KEY_LEFT_SUPER,
		RightShift						= FSGL_IMPL_KEY_RIGHT_SHIFT,
		RightControl					= FSGL_IMPL_KEY_RIGHT_CONTROL,
		RightAlt						= FSGL_IMPL_KEY_RIGHT_ALT,
		RightSuper						= FSGL_IMPL_KEY_RIGHT_SUPER,
		Menu							= FSGL_IMPL_KEY_MENU
	};





	////////////////////////////////////////////////////////////////////////////////
	// - UTILITY FUNCTIONS ---------------------------------------------------------

	// For converting from 'fsgl::KeyCode' to 'std::int32_t'
	inline constexpr std::underlying_type_t<KeyCode> to_code(const KeyCode code) noexcept
	{
		return static_cast<std::underlying_type_t<KeyCode>>(code);
	}

	// For converting from 'std::int32_t' to 'fsgl::KeyCode'
	inline constexpr KeyCode to_key(const std::underlying_type_t<KeyCode> code) noexcept
	{
		return static_cast<KeyCode>(code);
	}
}
