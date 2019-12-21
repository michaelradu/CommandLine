#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <filesystem>
#define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std::experimental::filesystem;
using namespace std;
ifstream read("data.in");
ofstream write("data.in", ios_base::app);
std::string GetCurrentWorkingDir(void) {
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}


void about()
{
	cout << "TerminalS v0.1 BETA\n";
}


void check(char msg[1000])
{
	if (strcmp(msg,"about")==0)
		about();
	else
		if (strcmp(msg,"exit")==0)
			system("pause");
		else
			system(msg);
}


void create_user()
{
	string usr1, pwd1;
	cout << "Your username will be: ";
	cin >> usr1;
	cout << "\nYour password will be: ";
	cin >> pwd1;

	write << usr1 << " " << pwd1 << endl;
}
int n, i;
char msg[1000];
string ver,usr,pwd,ac;
int main()
{
	//system("Color 0A");
	cout << "Do you have an account? y/n\n";
	cin >> ac;
	if (ac == "n") {
		create_user();
		while (strcmp(msg,"exit")!=0)
		{
			
			cout << GetCurrentWorkingDir() << ">> ";
			cin >> msg;
			check(msg);
		}
	}
	if(ac == "y")
	{
		cout << "Username: ";
		cin >> usr;
		cout << "\nPassword: ";
		cin >> pwd;
		while (getline(read, ver))
			if (usr + " " + pwd != ver)
				cout << "";
			else
				while (msg != "exit()")
				{
					cout << GetCurrentWorkingDir() << ">> ";
					cin >> msg;
					check(msg);
				}
	}
	read.close();
	write.close();
	return 0;
}
