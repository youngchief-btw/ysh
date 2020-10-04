#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
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
	string pwd = getenv("PWD");
	if (pwd.rfind("/home/"), 0 == 0) {
		// cout << "Detected home directory.\n";
	}

  cout << BOLDGREEN << getenv("USER") << "@" << getenv("HOSTNAME") << BOLDBLUE << ":" << pwd << RESET << "$ ";
  cin >> input;

  if (input == "help") {
    cout << "Commands: \n- help | Run the YoungShell help command.\n- exit | Exit out of YoungShell (and also terminal if this is your default shell)\n- reload | Reload everything!\n- clear | Clear the shell.\n";
  } else if (input == "exit") {
    cout << "Now exiting YoungShell...\n";
    return 0;
  } else if (input == "reload") {
    system("bash src/Setup.sh");
    return 0;
  } else if (input == "clear") {
    system("clear");
    cout << "\033[1m\033[36m" << "Welcome to YoungShell!\nYoungShell is open-source!! ( https://github.com/youngchief-btw/YoungShell )\n© 2020 youngchief btw ツ, All rights reserved.\nType `exit` to exit!\nType `help` for help!\n" << "\033[34m" << "-----------------------------------------------------------------------------\n" << "\033[0m";
  } else {
		cout << "Unknown command! Try it in Bash.\nTo get back to YoungShell, just type `exit`\n";
    system("bash");
  }

  recieveInput();
}

int main() {
  system("clear");
  cout << "\033[1m\033[36m" << "Welcome to YoungShell!\nYoungShell is open-source!! ( https://github.com/youngchief-btw/YoungShell )\n© 2020 youngchief btw ツ, All rights reserved.\nType `exit` to exit!\nType `help` for help!\n" << "\033[34m" << "-----------------------------------------------------------------------------\n" << "\033[0m";
  recieveInput();
  return 0;
}