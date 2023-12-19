

int check_hardDrive_size() {
	GET_LENGTH_INFORMATION size;
	DWORD lpBytesReturned;

	HANDLE drive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (drive == INVALID_HANDLE_VALUE) {
		// Someone is playing tricks. Or not enough privileges.
		CloseHandle(drive);
		return FALSE;
	}
	BOOL result = DeviceIoControl(drive, IOCTL_DISK_GET_LENGTH_INFO, NULL, 0, &size, sizeof(GET_LENGTH_INFORMATION), &lpBytesReturned, NULL);
	CloseHandle(drive);

	if (result != 0) {
		if (size.Length.QuadPart / 1073741824 <= 60) /* <= 60 GB */
			return TRUE;
	}

	return FALSE;
}

BOOL check_ram() {

	DWORDLONG ullMinRam = (1024LL * (1024LL * (1024LL * 1LL))); // 1GB

	MEMORYSTATUSEX statex = { 0 };
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex); // calls NtQuerySystemInformation

	return (statex.ullTotalPhys < ullMinRam) ? TRUE : FALSE;


}
