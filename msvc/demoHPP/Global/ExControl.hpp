﻿#pragma once
#include "ExUIbase.hpp"

using namespace ExDUIR::FrameWorks;


namespace ExDUIR
{
	namespace FrameWorks
	{
		namespace Control
		{
			class ExControl : public virtual ExUIbase
			{
			public:
				ExControl() = default;
				~ExControl() = default;
				ExControl(EXHANDLE hObj)
				{
					m_handle = hObj;
				}
				ExControl(HWND hWnd, POINT point)
				{
					m_handle = Ex_DUIGetObjFromPoint((EXHANDLE)hWnd, point.x, point.y);
				}
				ExControl(ExUIbase pOwner, INT x, INT y, INT width, INT height, std::wstring lptszClassName, std::wstring lptszObjTitle = NULL, INT dwStyle = -1, INT dwStyleEx = -1, INT dwTextFormat = -1, INT nID = NULL, LPARAM lParam = NULL, HEXTHEME hTheme = nullptr, MsgPROC lpfnMsgProc = NULL)
				{
					m_handle = Ex_ObjCreateEx(dwStyleEx, lptszClassName.c_str(), lptszObjTitle.c_str(), dwStyle, x, y, width, height, pOwner.m_handle, nID, dwTextFormat, lParam, hTheme, lpfnMsgProc);
				}

				inline BOOL IsValidate() { return Ex_ObjIsValidate(m_handle); }
				inline BOOL IsVisible() { return Ex_ObjIsVisible(m_handle); }
				inline BOOL Visible(BOOL bVisible) { return Ex_ObjShow(m_handle, bVisible); }
				inline BOOL IsEnable() { return Ex_ObjIsEnable(m_handle); }
				inline BOOL Enable(BOOL bEnable) { return Ex_ObjEnable(m_handle, bEnable); }
				inline BOOL Move(INT left, INT top, INT width, INT height, BOOL bRepaint = FALSE) { return Ex_ObjMove(m_handle, left, top, width, height, bRepaint); }

				inline BOOL GetRect(RECT& rc)
				{
					return Ex_ObjGetRect(m_handle, &rc);
				}

				inline BOOL GetClientRect(RECT& rc)
				{
					return Ex_ObjGetClientRect(m_handle, &rc);
				}

				inline std::wstring GetText()
				{
					size_t len = Ex_ObjGetTextLength(m_handle);
					std::wstring str;
					str.resize(len);
					Ex_ObjGetText(m_handle, str.data(), len * 2);
					return str;
				}

				inline BOOL SetText(std::wstring text, BOOL bRepaint = FALSE)
				{
					return Ex_ObjSetText(m_handle, text.c_str(), bRepaint);
				}
				
				inline size_t GetLong(INT nIndex)
				{
					return Ex_ObjGetLong(m_handle, nIndex);
				}

				inline size_t SetLong(INT nIndex, size_t newLong)
				{
					return Ex_ObjSetLong(m_handle, nIndex, newLong);
				}

				inline BOOL SetPadding(INT nPaddingType, INT left, INT top, INT right, INT bottom, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetPadding(m_handle, nPaddingType, left, top, right, bottom, fRepaint);
				}

				inline BOOL PostMsg(UINT uMsg, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjPostMessage(m_handle, uMsg, wParam, lParam);
				}

				inline size_t SendMsg(UINT uMsg, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjSendMessage(m_handle, uMsg, wParam, lParam);
				}

				inline BOOL SetBackgroundPlayState(BOOL fPlayFrames, BOOL fResetFrame, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetBackgroundPlayState(m_handle, fPlayFrames, fResetFrame, fRepaint);
				}

				inline BOOL SetRadius(FLOAT topLeft, FLOAT topRight, FLOAT bottomRight, FLOAT bottomLeft, BOOL fUpdate = FALSE)
				{
					return Ex_ObjSetRadius(m_handle, topLeft, topRight, bottomRight, bottomLeft, fUpdate);
				}

				inline BOOL SetPosNoAfter(INT x, INT y, INT width, INT height, INT flags)
				{
					return Ex_ObjSetPos(m_handle, 0, x, y, width, height, flags);
				}

				inline BOOL SetPos(ExControl InsertAfter, INT x, INT y, INT width, INT height, INT flags)
				{
					return Ex_ObjSetPos(m_handle, InsertAfter.m_handle, x, y, width, height, flags);
				}

				inline BOOL HandleEvent(INT nEvent, EventHandlerPROC pfnCallback)
				{
					return Ex_ObjHandleEvent(m_handle, nEvent, pfnCallback);
				}

				inline EXARGB GetColor(INT nIndex)
				{
					return Ex_ObjGetColor(m_handle, nIndex);
				}

				inline BOOL BeginPaint(EX_PAINTSTRUCT& ps)
				{
					return Ex_ObjBeginPaint(m_handle, &ps);
				}

				inline BOOL EndPaint(EX_PAINTSTRUCT& ps)
				{
					return Ex_ObjEndPaint(m_handle, &ps);
				}

				inline ExControl GetFocus()
				{
					auto hObj = Ex_ObjGetFocus(m_handle);
					auto ret = ExControl(hObj);
					return ret;
				}

                inline BOOL SetFocus()
                {
                    return Ex_ObjSetFocus(m_handle);
                }

				inline BOOL KillFocus()
				{
					return Ex_ObjKillFocus(m_handle);
				}

				inline BOOL TrackPopupMenu(HMENU hMenu, DWORD uFlags, INT x, INT y, size_t nReserved, RECT* lpRC, MsgPROC pfnCallback, DWORD dwFlags)
				{
					return Ex_TrackPopupMenu(hMenu, uFlags, x, y, nReserved, m_handle, lpRC, pfnCallback, dwFlags);
				}

				inline static size_t CallProc(ClsPROC lpPrevObjProc, HWND hWnd, HEXOBJ hObj, INT uMsg, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjCallProc(lpPrevObjProc, hWnd, hObj, uMsg, wParam, lParam);
				}

				inline static size_t DefProc(HWND hWnd, HEXOBJ hObj, INT uMsg, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjDefProc(hWnd, hObj, uMsg, wParam, lParam);
				}

				inline size_t DispatchMsg(INT uMsg, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjDispatchMessage(m_handle, uMsg, wParam, lParam);
				}

				inline size_t DispatchNotify(INT nCode, WPARAM wParam, LPARAM lParam)
				{
					return Ex_ObjDispatchNotify(m_handle, nCode, wParam, lParam);
				}

				inline BOOL ClientToScreen(INT& x, INT& y)
				{
					return Ex_ObjClientToScreen(m_handle, &x, &y);
				}

				inline BOOL ClientToWindow(INT& x, INT& y)
				{
					return Ex_ObjClientToWindow(m_handle, &x, &y);
				}

				inline BOOL Invalidate()
				{
					return Ex_ObjInvalidateRect(m_handle, NULL);
				}

				inline BOOL Invalidate(RECT rc)
				{
					return Ex_ObjInvalidateRect(m_handle, &rc);
				}

				inline INT SetTimer(INT uElapse)
				{
					return Ex_ObjSetTimer(m_handle, uElapse);
				}

				inline BOOL KillTimer()
				{
					return Ex_ObjKillTimer(m_handle);
				}

				inline BOOL SetFont(std::wstring lpszFontfamily, INT dwFontsize, INT dwFontstyle = 0, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetFontFromFamily(m_handle, lpszFontfamily.c_str(), dwFontsize, dwFontstyle, fRepaint);
				}

				inline BOOL EnablePaintingMsg(BOOL bEnable)
				{
					return Ex_ObjEnablePaintingMsg(m_handle, bEnable);
				}

				inline INT GetDropStringLen(LPVOID pDataObject)
				{
					return Ex_ObjGetDropString(m_handle, pDataObject, 0, 0);
				}

				inline INT GetDropString(LPVOID pDataObject, std::wstring& retStr, INT cchMaxLength)
				{
					return Ex_ObjGetDropString(m_handle, pDataObject, (LPWSTR)retStr.data(), cchMaxLength);
				}

				inline BOOL CheckDropFormat(LPVOID pDataObject, DWORD dwFormat)
				{
					return Ex_ObjCheckDropFormat(m_handle, pDataObject, dwFormat);
				}

				inline ExControl GetFromID(INT nID)
				{
					auto hObj = Ex_ObjGetFromID(m_handle, nID);
					return ExControl(hObj);
				}

				inline ExControl FindObj(std::wstring className)
				{
					return ExControl(Ex_ObjFind(m_handle, 0, className.c_str(), 0));
				}

				inline ExControl FindObjByTitle(std::wstring className, std::wstring title = L"")
				{
					return ExControl(Ex_ObjFind(m_handle, 0, className.c_str(), title.c_str()));
				}

				inline ExControl GetFromNodeID(INT nID)
				{
					auto hObj = Ex_ObjGetFromNodeID(m_handle, nID);
					return ExControl(hObj);
				}

				inline ExControl GetObj(INT nCmd)
				{
					return ExControl(Ex_ObjGetObj(m_handle, nCmd));
				}

			/*	inline std::wstring GetText()
				{
					return std::wstring((LPCWSTR)Ex_ObjGetLong(m_handle, OBJECT_LONG_LPWZTITLE));
				}*/

				inline ExControl GetParent()
				{
					auto hObj = Ex_ObjGetParent(m_handle);
					return ExControl(hObj);
				}

				inline BOOL GetBackgroundImage(EX_BACKGROUNDIMAGEINFO& BkgInfo) { return Ex_ObjGetBackgroundImage(m_handle, &BkgInfo); }

				inline BOOL SetBackgroundImageFromData(std::vector<CHAR> imageData, INT x = 0, INT y = 0, DWORD dwRepeat = BACKGROUND_REPEAT_ZOOM, RECT* lpGrid = NULL, INT dwFlags = BACKGROUND_FLAG_DEFAULT, DWORD dwAlpha = 255, BOOL fUpdate = FALSE)
				{
					return Ex_ObjSetBackgroundImage(m_handle, imageData.data(), imageData.size(), x, y, dwRepeat, lpGrid, dwFlags, dwAlpha, fUpdate);
				}

				inline BOOL SetBackgroundImageFromFile(std::wstring imageFilePath, INT x = 0, INT y = 0, DWORD dwRepeat = BACKGROUND_REPEAT_ZOOM, RECT* lpGrid = NULL, INT dwFlags = BACKGROUND_FLAG_DEFAULT, DWORD dwAlpha = 255, BOOL fUpdate = FALSE)
				{
					std::vector<CHAR> imgdata;
					Ex_ReadFile(imageFilePath.c_str(), &imgdata);
					return SetBackgroundImageFromData(imgdata, x, y, dwRepeat, lpGrid, dwFlags, dwAlpha, fUpdate);
				}

				inline BOOL SetBackgroundImageFromSvg(HEXSVG hSvg, INT x = 0, INT y = 0, DWORD dwRepeat = BACKGROUND_REPEAT_ZOOM, RECT* lpGrid = NULL, INT dwFlags = BACKGROUND_FLAG_DEFAULT, DWORD dwAlpha = 255, BOOL fUpdate = FALSE)
				{
					return Ex_ObjSetBackgroundImageFromSvg(m_handle, hSvg, x, y, dwRepeat, lpGrid, dwFlags, dwAlpha, fUpdate);
				}

				inline EXARGB GetColorBackground()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_BACKGROUND);
				}

				inline BOOL SetColorBackground(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_BACKGROUND, nColor, fRepaint);
				}

				inline EXARGB GetColorBorder()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_BORDER);
				}

				inline BOOL SetColorBorder(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_BORDER, nColor, fRepaint);
				}

				inline EXARGB GetColorTextNormal()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_NORMAL);
				}

				inline BOOL SetColorTextNormal(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_NORMAL, nColor, fRepaint);
				}

				inline EXARGB GetColorTextFocus()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_FOCUS);
				}

				inline BOOL SetColorTextFocus(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_FOCUS, nColor, fRepaint);
				}

				inline EXARGB GetColorTextHover()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_HOVER);
				}

				inline BOOL SetColorTextHover(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_HOVER, nColor, fRepaint);
				}

				inline EXARGB GetColorTextDown()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_DOWN);
				}

				inline BOOL SetColorTextDown(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_DOWN, nColor, fRepaint);
				}

				inline EXARGB GetColorTextChecked()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_CHECKED);
				}

				inline BOOL SetColorTextChecked(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_CHECKED, nColor, fRepaint);
				}

				inline EXARGB GetColorTextSelect()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_SELECT);
				}

				inline BOOL SetColorTextSelect(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_SELECT, nColor, fRepaint);
				}

				inline EXARGB GetColorTextVisted()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_VISTED);
				}

				inline BOOL SetColorTextVisted(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_VISTED, nColor, fRepaint);
				}

				inline EXARGB GetColorTextShadow()
				{
					return Ex_ObjGetColor(m_handle, COLOR_EX_TEXT_SHADOW);
				}

				inline BOOL SetColorTextShadow(EXARGB nColor, BOOL fRepaint = FALSE)
				{
					return Ex_ObjSetColor(m_handle, COLOR_EX_TEXT_SHADOW, nColor, fRepaint);
				}

				inline DWORD GetUIState()
				{
					return Ex_ObjGetUIState(m_handle);
				}

				inline BOOL SetUIState(DWORD dwState, BOOL fRemove, RECT* lprcRedraw, BOOL fRedraw)
				{
					return Ex_ObjSetUIState(m_handle, dwState, fRemove, lprcRedraw, fRedraw);
				}

				inline void SetLongAlpha(DWORD alpha)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_ALPHA, alpha);
				}

				inline DWORD GetLongAlpha()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_ALPHA);
				}

				inline void SetLongBlur(DWORD blur)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_BLUR, blur);
				}

				inline DWORD GetLongBlur()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_BLUR);
				}

				inline void SetLongCursor(HCURSOR cursor)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_CURSOR, (LPARAM)cursor);
				}

				inline HCURSOR GetLongCursor()
				{
					return (HCURSOR)Ex_ObjGetLong(m_handle, OBJECT_LONG_CURSOR);
				}

				inline void SetLongStyleEx(size_t styleEx)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_EXSTYLE, styleEx);
				}

				inline size_t GetLongStyleEx()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_EXSTYLE);
				}

				inline void SetLongStyle(size_t style)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_STYLE, style);
				}

				inline size_t GetLongStyle()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_STYLE);
				}

				inline void SetLongState(INT state)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_STATE, state);
				}

				inline INT GetLongState()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_STATE);
				}

				inline void SetLongID(size_t ID)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_ID, ID);
				}

				inline size_t GetLongID()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_ID);
				}

				inline void SetLongNodeID(size_t nodeID)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_NODEID, nodeID);
				}

				inline size_t GetLongNodeID()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_NODEID);
				}

				inline void SetLongLParam(LONG_PTR LParam)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_LPARAM, LParam);
				}

				inline HEXCANVAS GetLongCanvas()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_HCANVAS);
				}

				inline LONG_PTR GetLongLParam()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_LPARAM);
				}

				inline void SetLongOwner(LONG_PTR owner)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_OWNER, owner);
				}

				inline LONG_PTR GetLongOwner()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_OWNER);
				}

				inline LONG_PTR SetLongUserData(LONG_PTR userdata)
				{
					return (LONG_PTR)Ex_ObjSetLong(m_handle, OBJECT_LONG_USERDATA, userdata);
				}

				inline LONG_PTR GetLongUserData()
				{
					return Ex_ObjGetLong(m_handle, OBJECT_LONG_USERDATA);
				}

				inline void SetLongProc(MsgPROC proc)
				{
					Ex_ObjSetLong(m_handle, OBJECT_LONG_OBJPROC, (size_t)proc);
				}

				inline BOOL EnableEventBubble(BOOL bEnable)
				{
					return Ex_ObjEnableEventBubble(m_handle, bEnable);
				}

				inline INT SetScrollInfo(INT nBar, INT Mask, INT nMin, INT nMax, INT nPage, INT nPos, BOOL bRedraw)
				{
					return Ex_ObjScrollSetInfo(m_handle, nBar, Mask, nMin, nMax, nPage, nPos, bRedraw);
				}

				inline void ScrollShow(INT nBar, BOOL fShow)
				{
					Ex_ObjScrollShow(m_handle, nBar, fShow);
				}

				inline ExControl ScrollGetControl(INT nBar)
				{
					return ExControl(Ex_ObjScrollGetControl(m_handle, nBar));
				}

				inline INT ScrollGetTrackPos(INT nBar)
				{
					return Ex_ObjScrollGetTrackPos(m_handle, nBar);
				}

				inline INT ScrollSetPos(INT nBar, INT nPos, BOOL bRedraw)
				{
					return Ex_ObjScrollSetPos(m_handle, nBar, nPos, bRedraw);
				}

				inline BOOL ScrollGetInfo(INT nBar, INT& lpnMin, INT& lpnMax, INT& lpnPos, INT& lpnTrackPos)
				{
					return Ex_ObjScrollGetInfo(m_handle, nBar, &lpnMin, &lpnMax, &lpnPos, &lpnTrackPos);
				}

				inline BOOL InitPropList(INT nPropCount)
				{
					return Ex_ObjInitPropList(m_handle, nPropCount);
				}

				inline size_t SetObjProp(size_t dwKey, size_t dwValue)
				{
					return Ex_ObjSetProp(m_handle, dwKey, dwValue);
				}

				inline size_t GetObjProp(size_t dwKey)
				{
					return Ex_ObjGetProp(m_handle, dwKey);
				}

				inline BOOL Update()
				{
					return Ex_ObjUpdate(m_handle);
				}
			};
		}
	}
}
