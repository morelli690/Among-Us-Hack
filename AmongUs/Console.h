#pragma once
#include <Windows.h>
#include <string.h>
#include <iostream>

struct Console {
	static void Attach(const char* title)
	{
		AllocConsole();
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		SetConsoleTitleA(title);
	}
	static void Log(std::string string)
	{
		std::cout << "[LOG] " << string << std::endl;
	}
	static void SetTitle(const char* title)
	{
		SetConsoleTitleA(title);
	}
};