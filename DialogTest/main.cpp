#include "Resource.h"
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>

BOOL DlgInitProc(HWND hwnd, HWND, LPARAM lParam)
{
	return TRUE;
}

VOID DlgCommandProc(HWND hwnd,int id,HWND hwndCtrl,UINT codeNotify)
{
	switch (id)
	{
	case IDCANCEL:
		EndDialog(hwnd, id);
	}
}

INT_PTR WINAPI DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return SetDlgMsgResult(hwnd, uMsg,
							   HANDLE_WM_INITDIALOG(hwnd, wParam, lParam, DlgInitProc));
	case WM_COMMAND:
		return SetDlgMsgResult(hwnd, uMsg,
							   HANDLE_WM_COMMAND(hwnd, wParam, lParam, DlgCommandProc));
	}
	return FALSE;
}
int WINAPI _tWinMain(_In_ HINSTANCE hInstance,
			  _In_opt_ HINSTANCE hPrevInstance,
			  _In_ PTSTR lpCmdLine, _In_ int nShowCmd)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOGMAIN), NULL, DlgProc, _ttoi(lpCmdLine));
	return 0;
}