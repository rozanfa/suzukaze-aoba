#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

void get_ps_name(DWORD pid, TCHAR* pname) {
	HANDLE phandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
	if (phandle != NULL) {
		HMODULE pmod;
		DWORD temp;
		if (EnumProcessModules(phandle, &pmod, sizeof(pmod), &temp))
			GetModuleBaseName(phandle, pmod, pname, 260);
	}
	CloseHandle(phandle);
}

int find_ps_id(TCHAR* pname) {
	DWORD ps_list[1024], ps_memctr, ps_ctr;
	if (!EnumProcesses(ps_list, sizeof(ps_list), &ps_memctr))
		return -1;
	ps_ctr = ps_memctr / sizeof(DWORD);
	TCHAR temp_pname[MAX_PATH] = TEXT("<unknown>");
	for (int i = 0; i < ps_ctr; i++)
		if (ps_list[i] != 0) {
			get_ps_name(ps_list[i], temp_pname);
			if (_tcscmp(pname, temp_pname) == 0) return ps_list[i];
		}
	return -1;
}


int main() {
	TCHAR pname[260] = TEXT("targetprogram.exe");
	int pid = find_ps_id(pname);

	if (pid == -1) {
		printf("Process not found\n");
		exit(-1);
	}
		
	int newValue = 0xABCDEF;	// Nilai baru
	long long valueAddr = 0x000000455ebffdcc;	// Alamat nilai yang diubah

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	

	WriteProcessMemory(handle, (LPVOID)valueAddr, &newValue, sizeof(newValue), 0);
	printf("Value berhasil diubah!\n");
	return 0;
}
