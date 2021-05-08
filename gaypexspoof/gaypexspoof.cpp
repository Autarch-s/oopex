// thanks to who ever made hwid shifter, this is a just a loader for kdmapper and the driver simple download stuff
// u can find hwid shifter on github for the source



#include <iostream>
#include<windows.h>
#include <tchar.h>
#include <stdio.h>
#include <urlmon.h>
#include <filesystem>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")

void download()
{

	//downloads compiled driver to spoof serial numbers
	

	// downloads are not packed UC u can decompile all 

	/// <summary>
	///  driver - spoof.sys https://github.com/rezadfx/HWID-shifter
	///	 kdmapper - mapper.exe https://github.com/TheCruZ/kdmapper 
	///  traces - trace.bat https://www.unknowncheats.me/forum/apex-legends/450793-apex-eac-origin-trace-files-cleaner.html
	/// </summary>
	HRESULT hr;
	LPCTSTR Url = _T("https://cdn.discordapp.com/attachments/834660296567423006/840265703071416320/spoofer_1.sys"), File = _T("C:\\spoof.sys");
	hr = URLDownloadToFile(0, Url, File, 0, 0);


	// kdmapper 20hz supported by thecruz 

	LPCTSTR mapper = _T("https://cdn.discordapp.com/attachments/836243815890419718/840365876921892864/kdmapper.exe"), map = _T("C:\\mapper.exe");
	hr = URLDownloadToFile(0, mapper, map, 0, 0);


	
	// tarce cleaner from UC, modifyed to not destory your pc and delete apex LOL 
	LPCTSTR traces = _T("https://cdn.discordapp.com/attachments/836243815890419718/840373348348592178/Apex_Cleaner.bat"), trace = _T("C:\\traces.bat");
	hr = URLDownloadToFile(0, traces, trace, 0, 0);

}


void traces()
{
	// kill running tasks

	system("taskkill /f /im OriginWebHelperService.exe");
	system("taskkill /f /im Origin.exe");
	system("taskkill /f /im OriginClientService.exe");
	system("taskkill /f /im OriginER.exe");
	system("taskkill /f /im OriginThinSetupInternal.exe");
	system("taskkill /f /im OriginLegacyCLI.exe");
	system("taskkill /f /im Apex.exe");


	// traces that don't delete apex LOL 

	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\Cleanup.dat");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\installerdata.xml");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\\Origin Games\\Apex\\__Installer\\InstallLog.txt");
	system("del /f /s /q %systemdrive%\\Program Files(x86)\Origin Games\Apex\\__Installer\\Touchup.dat");


	// registry info spoof
	
	system("REG ADD HKLM\HARDWARE\DESCRIPTION\System\\BIOS /v BaseBoardManufacturer /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BaseBoardProduct /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BaseBoardVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v BIOSVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemFamily /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemManufacturer /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemProductName /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemSKU /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemVersion /t REG_SZ /d gaypex-%random% /f");
	system("REG ADD HKLM\\HARDWARE\\DESCRIPTION\\System\\BIOS /v SystemProductName /t REG_SZ /d gaypex-%random% /f");
	



	// clear screen
	system("cls");
	
	
	std::cout << "spoofed disk serial \n";
	system("wmic diskdrive get serialnumber");
	// runs a "trace cleaner" im lazy no more system calls 
	std::cout << "cleaning traces\n";
	ShellExecute(NULL, _T("open"), _T("C:\\traces.exe"), NULL, NULL, SW_HIDE);
	

}
int main()
{
	std::cin.clear();
	SetConsoleTitle(TEXT("gaypex.cc spoofer "));
    
	download();
	std::cout << "\nDownloaded mapper drivers, tarce cleaner!\n"; 
	// Exc Downloaded files mapper and driver 
	ShellExecute(NULL, _T("open"), _T("C:\\mapper.exe"), _T("C:\\spoof.sys"), NULL, SW_HIDE);

	traces();
	std::cout << "done go play some apex (:";
	std::cout << "loader made by gaypex.cc team (:";
	std::cin.get();
}


