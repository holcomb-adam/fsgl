#pragma once

// Standard Library includes
#include <type_traits>



// TODO: These key codes should be placed in a seperate file
// From glfw3 key codes
#define RLE_IMPL_KEY_UNKNOWN            -1
#define RLE_IMPL_KEY_SPACE              32
#define RLE_IMPL_KEY_APOSTROPHE         39  /* ' */
#define RLE_IMPL_KEY_COMMA              44  /* , */
#define RLE_IMPL_KEY_MINUS              45  /* - */
#define RLE_IMPL_KEY_PERIOD             46  /* . */
#define RLE_IMPL_KEY_SLASH              47  /* / */
#define RLE_IMPL_KEY_0                  48
#define RLE_IMPL_KEY_1                  49
#define RLE_IMPL_KEY_2                  50
#define RLE_IMPL_KEY_3                  51
#define RLE_IMPL_KEY_4                  52
#define RLE_IMPL_KEY_5                  53
#define RLE_IMPL_KEY_6                  54
#define RLE_IMPL_KEY_7                  55
#define RLE_IMPL_KEY_8                  56
#define RLE_IMPL_KEY_9                  57
#define RLE_IMPL_KEY_SEMICOLON          59  /* ; */
#define RLE_IMPL_KEY_EQUAL              61  /* = */
#define RLE_IMPL_KEY_A                  65
#define RLE_IMPL_KEY_B                  66
#define RLE_IMPL_KEY_C                  67
#define RLE_IMPL_KEY_D                  68
#define RLE_IMPL_KEY_E                  69
#define RLE_IMPL_KEY_F                  70
#define RLE_IMPL_KEY_G                  71
#define RLE_IMPL_KEY_H                  72
#define RLE_IMPL_KEY_I                  73
#define RLE_IMPL_KEY_J                  74
#define RLE_IMPL_KEY_K                  75
#define RLE_IMPL_KEY_L                  76
#define RLE_IMPL_KEY_M                  77
#define RLE_IMPL_KEY_N                  78
#define RLE_IMPL_KEY_O                  79
#define RLE_IMPL_KEY_P                  80
#define RLE_IMPL_KEY_Q                  81
#define RLE_IMPL_KEY_R                  82
#define RLE_IMPL_KEY_S                  83
#define RLE_IMPL_KEY_T                  84
#define RLE_IMPL_KEY_U                  85
#define RLE_IMPL_KEY_V                  86
#define RLE_IMPL_KEY_W                  87
#define RLE_IMPL_KEY_X                  88
#define RLE_IMPL_KEY_Y                  89
#define RLE_IMPL_KEY_Z                  90
#define RLE_IMPL_KEY_LEFT_BRACKET       91  /* [ */
#define RLE_IMPL_KEY_BACKSLASH          92  /* \ */
#define RLE_IMPL_KEY_RIGHT_BRACKET      93  /* ] */
#define RLE_IMPL_KEY_GRAVE_ACCENT       96  /* ` */
#define RLE_IMPL_KEY_WORLD_1            161 /* non-US #1 */
#define RLE_IMPL_KEY_WORLD_2            162 /* non-US #2 */
#define RLE_IMPL_KEY_ESCAPE             256
#define RLE_IMPL_KEY_ENTER              257
#define RLE_IMPL_KEY_TAB                258
#define RLE_IMPL_KEY_BACKSPACE          259
#define RLE_IMPL_KEY_INSERT             260
#define RLE_IMPL_KEY_DELETE             261
#define RLE_IMPL_KEY_RIGHT              262
#define RLE_IMPL_KEY_LEFT               263
#define RLE_IMPL_KEY_DOWN               264
#define RLE_IMPL_KEY_UP                 265
#define RLE_IMPL_KEY_PAGE_UP            266
#define RLE_IMPL_KEY_PAGE_DOWN          267
#define RLE_IMPL_KEY_HOME               268
#define RLE_IMPL_KEY_END                269
#define RLE_IMPL_KEY_CAPS_LOCK          280
#define RLE_IMPL_KEY_SCROLL_LOCK        281
#define RLE_IMPL_KEY_NUM_LOCK           282
#define RLE_IMPL_KEY_PRINT_SCREEN       283
#define RLE_IMPL_KEY_PAUSE              284
#define RLE_IMPL_KEY_F1                 290
#define RLE_IMPL_KEY_F2                 291
#define RLE_IMPL_KEY_F3                 292
#define RLE_IMPL_KEY_F4                 293
#define RLE_IMPL_KEY_F5                 294
#define RLE_IMPL_KEY_F6                 295
#define RLE_IMPL_KEY_F7                 296
#define RLE_IMPL_KEY_F8                 297
#define RLE_IMPL_KEY_F9                 298
#define RLE_IMPL_KEY_F10                299
#define RLE_IMPL_KEY_F11                300
#define RLE_IMPL_KEY_F12                301
#define RLE_IMPL_KEY_F13                302
#define RLE_IMPL_KEY_F14                303
#define RLE_IMPL_KEY_F15                304
#define RLE_IMPL_KEY_F16                305
#define RLE_IMPL_KEY_F17                306
#define RLE_IMPL_KEY_F18                307
#define RLE_IMPL_KEY_F19                308
#define RLE_IMPL_KEY_F20                309
#define RLE_IMPL_KEY_F21                310
#define RLE_IMPL_KEY_F22                311
#define RLE_IMPL_KEY_F23                312
#define RLE_IMPL_KEY_F24                313
#define RLE_IMPL_KEY_F25                314
#define RLE_IMPL_KEY_KP_0               320
#define RLE_IMPL_KEY_KP_1               321
#define RLE_IMPL_KEY_KP_2               322
#define RLE_IMPL_KEY_KP_3               323
#define RLE_IMPL_KEY_KP_4               324
#define RLE_IMPL_KEY_KP_5               325
#define RLE_IMPL_KEY_KP_6               326
#define RLE_IMPL_KEY_KP_7               327
#define RLE_IMPL_KEY_KP_8               328
#define RLE_IMPL_KEY_KP_9               329
#define RLE_IMPL_KEY_KP_DECIMAL         330
#define RLE_IMPL_KEY_KP_DIVIDE          331
#define RLE_IMPL_KEY_KP_MULTIPLY        332
#define RLE_IMPL_KEY_KP_SUBTRACT        333
#define RLE_IMPL_KEY_KP_ADD             334
#define RLE_IMPL_KEY_KP_ENTER           335
#define RLE_IMPL_KEY_KP_EQUAL           336
#define RLE_IMPL_KEY_LEFT_SHIFT         340
#define RLE_IMPL_KEY_LEFT_CONTROL       341
#define RLE_IMPL_KEY_LEFT_ALT           342
#define RLE_IMPL_KEY_LEFT_SUPER         343
#define RLE_IMPL_KEY_RIGHT_SHIFT        344
#define RLE_IMPL_KEY_RIGHT_CONTROL      345
#define RLE_IMPL_KEY_RIGHT_ALT          346
#define RLE_IMPL_KEY_RIGHT_SUPER        347
#define RLE_IMPL_KEY_MENU				348

#define RLE_IMPL_KEY_LAST               RLE_KEY_MENU





namespace rle
{
	enum class KeyCode : std::int32_t
	{
		////////////////////////////////////////////////////////////////////////////////
		// - UNKNOWN KEY ---------------------------------------------------------------

		Unknown							= RLE_IMPL_KEY_UNKNOWN,



		////////////////////////////////////////////////////////////////////////////////
		// - PRINTABLE KEYS ------------------------------------------------------------
		
		Space							= RLE_IMPL_KEY_SPACE,
		A								= RLE_IMPL_KEY_A,
		B								= RLE_IMPL_KEY_B,
		C								= RLE_IMPL_KEY_C,
		D								= RLE_IMPL_KEY_D,
		E								= RLE_IMPL_KEY_E,
		F								= RLE_IMPL_KEY_F,
		G								= RLE_IMPL_KEY_G,
		H								= RLE_IMPL_KEY_H,
		I								= RLE_IMPL_KEY_I,
		J								= RLE_IMPL_KEY_J,
		K								= RLE_IMPL_KEY_K,
		L								= RLE_IMPL_KEY_L,
		M								= RLE_IMPL_KEY_M,
		N								= RLE_IMPL_KEY_N,
		O								= RLE_IMPL_KEY_O,
		P								= RLE_IMPL_KEY_P,
		Q								= RLE_IMPL_KEY_Q,
		R								= RLE_IMPL_KEY_R,
		S								= RLE_IMPL_KEY_S,
		T								= RLE_IMPL_KEY_T,
		U								= RLE_IMPL_KEY_U,
		V								= RLE_IMPL_KEY_V,
		W								= RLE_IMPL_KEY_W,
		X								= RLE_IMPL_KEY_X,
		Y								= RLE_IMPL_KEY_Y,
		Z								= RLE_IMPL_KEY_Z,
		LeftBracket						= RLE_IMPL_KEY_LEFT_BRACKET,   // '['
		BackSlash						= RLE_IMPL_KEY_BACKSLASH,      // '\'
		RightBracket					= RLE_IMPL_KEY_RIGHT_BRACKET,  // ']'
		Grave							= RLE_IMPL_KEY_GRAVE_ACCENT,   // '`'
		World_1							= RLE_IMPL_KEY_WORLD_1,        // non-US #1
		World_2                         = RLE_IMPL_KEY_WORLD_2,        // non-US #2



		////////////////////////////////////////////////////////////////////////////////
		// - FUNCTION KEYS -------------------------------------------------------------

		Escape							= RLE_IMPL_KEY_ESCAPE,
		Enter							= RLE_IMPL_KEY_ENTER,
		Tab								= RLE_IMPL_KEY_TAB,
		Backspace						= RLE_IMPL_KEY_BACKSPACE,
		Insert							= RLE_IMPL_KEY_INSERT,
		Delete							= RLE_IMPL_KEY_DELETE,
		Right							= RLE_IMPL_KEY_RIGHT,
		Left							= RLE_IMPL_KEY_LEFT,
		Down							= RLE_IMPL_KEY_DOWN,
		Up								= RLE_IMPL_KEY_UP,
		PageUp							= RLE_IMPL_KEY_PAGE_UP,
		PageDown						= RLE_IMPL_KEY_PAGE_DOWN,
		Home							= RLE_IMPL_KEY_HOME,
		End								= RLE_IMPL_KEY_END,
		CapsLock						= RLE_IMPL_KEY_CAPS_LOCK,
		ScrollLock						= RLE_IMPL_KEY_SCROLL_LOCK,
		NumLock							= RLE_IMPL_KEY_NUM_LOCK,
		PrintScreen						= RLE_IMPL_KEY_PRINT_SCREEN,
		Pause							= RLE_IMPL_KEY_PAUSE,
		F1								= RLE_IMPL_KEY_F1,
		F2								= RLE_IMPL_KEY_F2,
		F3								= RLE_IMPL_KEY_F3,
		F4								= RLE_IMPL_KEY_F4,
		F5								= RLE_IMPL_KEY_F5,
		F6								= RLE_IMPL_KEY_F6,
		F7								= RLE_IMPL_KEY_F7,
		F8								= RLE_IMPL_KEY_F8,
		F9								= RLE_IMPL_KEY_F9,
		F10								= RLE_IMPL_KEY_F10,
		F11								= RLE_IMPL_KEY_F11,
		F12								= RLE_IMPL_KEY_F12,
		F13								= RLE_IMPL_KEY_F13,
		F14								= RLE_IMPL_KEY_F14,
		F15								= RLE_IMPL_KEY_F15,
		F16								= RLE_IMPL_KEY_F16,
		F17								= RLE_IMPL_KEY_F17,
		F18								= RLE_IMPL_KEY_F18,
		F19								= RLE_IMPL_KEY_F19,
		F20								= RLE_IMPL_KEY_F20,
		F21								= RLE_IMPL_KEY_F21,
		F22								= RLE_IMPL_KEY_F22,
		F23								= RLE_IMPL_KEY_F23,
		F24								= RLE_IMPL_KEY_F24,
		F25								= RLE_IMPL_KEY_F25,



		////////////////////////////////////////////////////////////////////////////////
		// - KEYPAD KEYS ---------------------------------------------------------------

		KP_0							= RLE_IMPL_KEY_KP_0,
		KP_1							= RLE_IMPL_KEY_KP_1,
		KP_2							= RLE_IMPL_KEY_KP_2,
		KP_3							= RLE_IMPL_KEY_KP_3,
		KP_4							= RLE_IMPL_KEY_KP_4,
		KP_5							= RLE_IMPL_KEY_KP_5,
		KP_6							= RLE_IMPL_KEY_KP_6,
		KP_7							= RLE_IMPL_KEY_KP_7,
		KP_8							= RLE_IMPL_KEY_KP_8,
		KP_9							= RLE_IMPL_KEY_KP_9,
		KP_Decimal						= RLE_IMPL_KEY_KP_DECIMAL,
		KP_Divide						= RLE_IMPL_KEY_KP_DIVIDE,
		KP_Multiply						= RLE_IMPL_KEY_KP_MULTIPLY,
		KP_Subtract						= RLE_IMPL_KEY_KP_SUBTRACT,
		KP_Add							= RLE_IMPL_KEY_KP_ADD,
		KP_Enter						= RLE_IMPL_KEY_KP_ENTER,
		KP_Equal						= RLE_IMPL_KEY_KP_EQUAL,



		////////////////////////////////////////////////////////////////////////////////
		// - KEY MODIFIERS -------------------------------------------------------------

		LeftShift						= RLE_IMPL_KEY_LEFT_SHIFT,
		LeftControl						= RLE_IMPL_KEY_LEFT_CONTROL,
		LeftAlt							= RLE_IMPL_KEY_LEFT_ALT,
		LeftSuper						= RLE_IMPL_KEY_LEFT_SUPER,
		RightShift						= RLE_IMPL_KEY_RIGHT_SHIFT,
		RightControl					= RLE_IMPL_KEY_RIGHT_CONTROL,
		RightAlt						= RLE_IMPL_KEY_RIGHT_ALT,
		RightSuper						= RLE_IMPL_KEY_RIGHT_SUPER,
		Menu							= RLE_IMPL_KEY_MENU
	};





	////////////////////////////////////////////////////////////////////////////////
	// - UTILITY FUNCTIONS ---------------------------------------------------------

	// For converting from 'rle::KeyCode' to 'std::int32_t'
	inline constexpr std::underlying_type_t<KeyCode> to_code(const KeyCode code) noexcept
	{
		return static_cast<std::underlying_type_t<KeyCode>>(code);
	}

	// For converting from 'std::int32_t' to 'rle::KeyCode'
	inline constexpr KeyCode to_key(const std::underlying_type_t<KeyCode> code) noexcept
	{
		return static_cast<KeyCode>(code);
	}
}
