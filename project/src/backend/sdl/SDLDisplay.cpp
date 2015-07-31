#include <system/Display.h>


namespace lime {
	
	
	value Display::GetDisplayBounds (int displayIndex) {
		
		SDL_Rect rect = { 0, 0, 0, 0};
		SDL_GetDisplayBounds(displayIndex, &rect);
		
		value mValue = alloc_empty_object ();
		alloc_field (mValue, val_id("x"), alloc_int(rect.x));
		alloc_field (mValue, val_id("y"), alloc_int(rect.y));
		alloc_field (mValue, val_id("width"), alloc_int(rect.w));
		alloc_field (mValue, val_id("height"), alloc_int(rect.h));
		return mValue;
		
	}
	
	value Display::GetCurrentDisplayMode (int displayIndex) {
		
		SDL_DisplayMode mode = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0 };
		SDL_GetCurrentDisplayMode(displayIndex, &mode);
		
		value mValue = alloc_empty_object ();
		alloc_field (mValue, val_id("width"), alloc_int(mode.w));
		alloc_field (mValue, val_id("height"), alloc_int(mode.h));
		alloc_field (mValue, val_id("refresh_rate"), alloc_int(mode.refresh_rate));
		alloc_field (mValue, val_id("format"), alloc_int(mode.format));
		return mValue;
		
	}
	
	value Display::GetDisplayMode (int displayIndex, int modeIndex) {
		
		SDL_DisplayMode mode = { SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0 };
		SDL_GetDisplayMode(displayIndex, modeIndex, &mode);
		
		value mValue = alloc_empty_object ();
		alloc_field (mValue, val_id("width"), alloc_int(mode.w));
		alloc_field (mValue, val_id("height"), alloc_int(mode.h));
		alloc_field (mValue, val_id("refresh_rate"), alloc_int(mode.refresh_rate));
		alloc_field (mValue, val_id("format"), alloc_int(mode.format));
		return mValue;
		
	}
	
	int Display::GetNumDevices() {
		
		return SDL_GetNumVideoDisplays();
		
	}
	
	const char* Display::GetDisplayName (int displayIndex) {
		
		return SDL_GetDisplayName(displayIndex);
		
	}
	
	int Display::GetNumDisplayModes (int displayIndex) {
		
		return SDL_GetNumDisplayModes(displayIndex);
		
	}
	
}