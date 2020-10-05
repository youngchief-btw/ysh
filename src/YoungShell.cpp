#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

// The following are Linux & MacOS ONLY Terminal color codes.
// To-Do: Work on getting colors done in Windows (see here: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c)
#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define BOLDRED "\033[1m\033[31m" /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m" /* Bold White */

int recieveInput() {
  string input = WHITE;
  input = "";
	ofstream filestream;

  cout << BOLDGREEN << getenv("USER") << "@" << getenv("HOSTNAME") << RESET << ":" << BOLDBLUE << getenv("DIRS") << RESET << "$ ";
  cin >> input;

  if (input == "help") {
    cout << "Commands: \n- help | Run the YoungShell help command.\n- exit | Exit out of YoungShell (and also terminal if this is your default shell)\n- reload | Reload everything!\n- clear | Clear the shell.\n- shn | Set HostName (requires elevated permissions)\n- gab-do | 'Globally Avaliable Binary Do' - Create a link from here to /bin/ys while keeping all functionally including updates. (requires elevated permissions)\n- gab-undo | 'Globally Avaliable Binary Undo' - Remove the globaly avaliable binary (while still keeping YoungShell installed) (requires elevated permissions)\n- update | Update YoungShell and optionally the host computer (could need elevated permissions)\n";
  } else if (input == "exit") {
    cout << BOLDMAGENTA << "Now exiting YoungShell...\n" << RESET;
    return 0;
  } else if (input == "reload") {
    system("bash src/Setup.sh");
    return 0;
  } else if (input == "clear") {
    system("clear");
    cout << "\033[1m\033[36m" << "Welcome to YoungShell!\nYoungShell is open-source!! ( https://github.com/youngchief-btw/YoungShell )\n© 2020 youngchief btw ツ, All rights reserved.\nType `exit` to exit!\nType `help` for help!\n" << "\033[34m" << "-----------------------------------------------------------------------------\n" << "\033[0m";
  } else if (input == "shn") {
    cout << "Enter your new hostname. (must have sudo access)\n$ ";
    cin >> input;
			#ifdef _WIN32
			filestream.open("\Windows\System32\etc\hostname");
			#endif
			#ifdef __unix__
			filestream.open("/etc/hostname");
			#endif
			if (filestream.is_open()) {
				filestream << input;
				filestream.close();
			} else { 
				cout << "Unable to open file! Do you have access?\n";
			}
	} else if (input == "update") {
		cout << BOLDYELLOW << "Now updating YoungShell..." << RESET << WHITE << "\n";
		system("git pull https://github.com/youngchief-btw/YoungShell.git;git fetch https://github.com/youngchief-btw/YoungShell.git");
		cout << RESET << BOLDYELLOW << "Do you want to install system updates as well? (might require sudo permissions) [y/N]:" << RESET << " ";
		cin >> input;
		if (input == "y") {
			#ifdef _WIN32
				system("Install-Module PWWindowsUpdate;Get-WindowsUpdate;Install-WindowsUpdate");
			#endif
			#ifdef linux
				system("sudo apt-get update;sudo apt-get upgrade;sudo apt-get full-upgrade;sudo apt-get dist-upgrade");
			#endif
			#ifdef __MACH__
				system("softwareupdate -I -a");
			#endif
			cout << BOLDYELLOW << "Some updates may require a computer reboot!" << RESET << "\n";
		} else {}
	} else if (input == "gab-do") {
		cout << "Now creating a link from here to /bin/ys\nMake sure to have sudo permissions!\n";
		#ifdef _WIN32
		system("mklink $(echo %cd%)\ys \Windows\System32\ys");
		#endif
		#ifdef __unix__
		system("ln $(pwd)/ys /bin/ys");
		#endif
	} else if (input == "gab-undo") {
		cout << "Now unlinking the globaly avaliable binary from here\nMake sure to have sudo permissions!\n.";
		system("rm -rf /bin/ys");
	} else {
		cout << "Unknown command! Try it in Bash!\nTo get back to YoungShell, just type `exit`\n";
    system("echo [bash];bash");
  }
  recieveInput();
}

int main() {
  system("clear");
  cout << "\033[1m\033[36m" << "Welcome to YoungShell!\nYoungShell is open-source!! ( https://github.com/youngchief-btw/YoungShell )\n© 2020 youngchief btw ツ, All rights reserved.\nType `exit` to exit!\nType `help` for help!\n" << "\033[34m" << "-----------------------------------------------------------------------------\n" << "\033[0m";
  recieveInput();
  return 0;
}
