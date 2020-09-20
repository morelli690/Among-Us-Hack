#pragma once
#include <Windows.h>

struct Mem {
	static void PlaceJump(BYTE* address, DWORD jumpTo, DWORD length)
	{
		DWORD oldprotect, newprotect, relativeaddress;
		VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &oldprotect);
		relativeaddress = (DWORD)(jumpTo - (DWORD)address) - 5;
		*address = 0xE9;
		*((DWORD*)(address + 0x1)) = relativeaddress;
		for (DWORD x = 0x5; x < length; x++)
		{
			*(address + x) = 0x90;
		}
		VirtualProtect(address, length, oldprotect, &newprotect);
		//Credit to Adafcaefc for this
	}
};