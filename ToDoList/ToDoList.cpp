// ToDoList.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <direct.h>
#include <direct.h>
#include <windows.h>

void LoadUser();
void CreateUser();

int main()
{

#ifdef _Win64
	std::cout << "Hello Windows";
#elif __unix__
	std::cout << "Hello Unix";
#endif

	bool GameLoop = true;
	while (GameLoop)
	{
		char MenuInput;
		
		std::cout << "1 - Load User" << std::endl;
		std::cout << "2 - Create User" << std::endl;
		std::cout << "3 - Exit" << std::endl;

		std::cin >> MenuInput;

		switch (MenuInput)
		{
			case '1': { LoadUser(); } break;
			case '2': { CreateUser(); } break;
			case '3': GameLoop = false;
		}
		std::system("cls");
	}
    std::cout << "Hello World!\n";
}

void CreateUser()
{
	char* NaN = new char[4];
	bool GoodInfo = false;
	char GoodInput;
	char* Name = new char[20];
	char* HobbyInput = new char[20];
	char* ToDo = new char[100];
	const char* ToDo01;
	char* Password = new char[20];

	do
	{
		std::system("cls");

		std::cout << "Write your Name:\n";
		std::cin >> Name;
		std::system("cls");

		std::cout << "Hello, " << Name << "!\n\n";

		std::cout << "What is your favourite Hobby?\n";
		std::cin >> HobbyInput;
		std::system("cls");

		std::cout << "Write your ToDo\n";
		std::cin >> ToDo;
		std::string Input;
		while (true)
		{
			std::cin.getline(ToDo, 100);

			if (ToDo[0] == '\0')
			{
				break;
			}

			Input += ToDo;
			Input += " ";
		}
		ToDo01 = ToDo;
		ToDo01 = Input.c_str();


		std::system("cls");

		std::cout << "And now your Password\n";
		std::cin >> Password;
		std::system("cls");
		

		std::cout << "So, that are your Informations:\n";
		std::cout << "Name:" << Name << std::endl;
		std::cout << "Favourite Hobby:" << HobbyInput << std::endl;
		std::cout << "Your ToDo:" << ToDo01 << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "And your Password:" << Password << std::endl;
		std::cout << "\nright? (y/n)\n";
		std::cin >> GoodInput;

		if (GoodInput == 'y')
		{
			GoodInfo = true;
		}
		

	} while (!GoodInfo);

	std::string FileType = ".prf";
	std::string FileName = Name + FileType;
	std::ofstream f(FileName);

	f << "Owner: " << Name << std::endl;
	f << std::endl;
	f << "Hobbys: " << HobbyInput << std::endl;
	f << "Your Password: " << Password << std::endl;
	f << std::endl;
	f << std::endl;
	f << "Your DoTo:\n" << *ToDo01;

	delete[] Name;
	delete[] HobbyInput;
	delete[] ToDo;
	delete[] ToDo01;
	delete[] Password;


	std::cin >> NaN;
	delete[] NaN;
}

void LoadUser()
{

	// The Code has Compile-Errors.
	// Search all Files in the directory and sort it with *prf files
	std::wstring directory = L"C:\\Users\\Drominito\\source\\repos\\ToDoList\\ToDoList";
	int i;
	std::wstring* UserArray = new std::wstring[5];
	std::wstring search_path = directory + L"\\*prf";
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(search_path.c_str(), &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		std::cerr << "Error opening directory" << std::endl;
		return;
	}
	std::cout << "Select your Profile:\n";
	do
	{
		if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			UserArray[i] = findFileData.cFileName;
			std::wcout << findFileData.cFileName << std::endl;
		}
		i++;
	} while (FindNextFile(hFind, &findFileData) != 0);

	std::string Input;
	std::cin >> Input;

	if (Input = UserArray[2])


	std::string NaN;
	std::cin >> NaN;

	FindClose(hFind);

}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
