#pragma once
#include <string>
#include "Runtime.h"
#include <stdlib.h>
#include "Types.h"
class Utils {
	public:
		static const char* RandomString(int length);
		static Il2CppString* ToIl2CppString(const char* string);
		static const char* FromIl2CppString(Il2CppString* string);
		static std::string FromConstChar(const char* string);
		static const char* ToConstChar(std::string string);
		template <typename T>
		static inline T ArrayToList(Il2CppArray* array, T Type);
};
