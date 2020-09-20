#pragma once
#include <Windows.h>
#include "Console.h"
#include "Runtime.h"
#include "Mem.h"
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;