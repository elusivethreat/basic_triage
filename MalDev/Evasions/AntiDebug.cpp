BOOL CheckPEB(VOID)
/*++

Routine Description:

	BeingDebugged:
	Checks if the BeingDebugged flag is set in the Process Environment Block (PEB).
	This is effectively the same code that IsDebuggerPresent() executes internally.
	The PEB pointer is fetched from DWORD FS:[0x30] on x86_32 and QWORD GS:[0x60] on x86_64.
	
	NTGlobalFlag:
	Checks if NTGlobalFlag is set, if a process was started by a debugger this will have a unique
	value that can be detected.

Arguments:

	None

Return Value:

	TRUE - if debugger was detected
	FALSE - otherwise
--*/
{

	PPEB pPeb = (PPEB)__readgsqword(0x60);

	if (pPeb->BeingDebugged == 1)
		return TRUE;

	DWORD dwNtGlobalFlag = *(PDWORD)((PBYTE)pPeb + 0xBC);
	if (dwNtGlobalFlag & NT_GLOBAL_FLAG_DEBUGGED)
		return TRUE;

	
	return FALSE;
}
