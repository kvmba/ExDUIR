﻿#pragma once

// 分割条组件回调函数
LRESULT CALLBACK SplitterProc(HWND hWnd, HEXOBJ hObj, INT uMsg, WPARAM wParam,
                              LPARAM lParam);

// 注册分割条组件
EXATOM SplitterRegister();
