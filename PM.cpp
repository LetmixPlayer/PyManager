/***********************************************
 *                 Python Manager              *
 *                             by Letmix       *
 ***********************************************
 * A Python code manager command.
 * You can use system command in here.
 * Version: Alpha 1.0.4
 * Website: https://letmixplayer.github.io/
 * Thanks:
 *     GitHub(https://github.com): Repository support, My website
 *     Git(https://git-scm.com/): Repository support, Push to GitHub
 *     MinGW64(https://www.mingw.com/): Compiled Windows program file
 *     VMware Workstation Player(https://www.vmware.com/): Run Ubuntu to Compile Linux program file
 *     BiliBili(https://www.bilibili.com): Upload video
 *     My friend: Coding with me, Amuses me
 * Letmix Studio
 */
#include <iostream>
#include <fstream>
#ifdef _WIN32 // Windows special header file
#include <windows.h>
#endif
#include "const.h"
using namespace std;
#ifdef __linux__ // Linux special function
void Sleep(int sleeptime) 
{
    string a = "python UsePyFunc/sleep.py";
    a += "";
}
#endif
// Install Python
int system_install_python()
{
#ifdef __APPLE__
    system("pybin/python-3.12.1-macos11.pkg");
#elif _WIN32
#ifdef _WIN64
    system("pybin\\python-3.8.10-amd64.exe");
#else
    system("pybin\\python-3.8.10.exe");
#endif
#elif __linux__
    system("sudo add-apt-repository ppa:fkrull/deadsnakes");
    system("sudo apt update");
    system("sudo apt install python3");
    system("sudo apt install python-is-python3");
#else
    cout << "You'll need to find the right Python for your computer on your own";
    return 1;
#endif
    return 0;
}
// Show loading or initizaling
void show(string msg, int s, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << "\r" << msg;
            for (int k = 0; k < i; k++)
                cout << '.';
            cout << '-';
            Sleep(150);
            cout << "\r" << msg;
            for (int k = 0; k < i; k++)
                cout << '.';
            cout << '\\';
            Sleep(150);
            cout << "\r" << msg;
            for (int k = 0; k < i; k++)
                cout << '.';
            cout << '|';
            Sleep(150);
            cout << "\r" << msg;
            for (int k = 0; k < i; k++)
                cout << '.';
            cout << '/';
            Sleep(150);
        }
    }
    cout << "\bdone\n";
}
int cmd(string s)
{
    if (s == "python")
        system("python");
    else if (s == "")
        return 0;
    else if (s == "exit")
        return 1;
        // Shells launch
#ifdef __linux__
    else if (s == "bash")
        system("bash");
    else if (s == "sh")
        system("sh");
    else if (s == "csh")
        system("csh");
    else if (s == "dash")
        system("dash");
    else if (s == "rbash")
        system("rbash");
    else if (s == "tmux")
        system("tmux");
    else if (s == "ksh")
        system("ksh");
    else if (s == "tcsh")
        system("tcsh");
    else if (s == "zsh")
        system("zsh")
#elif _WIN32
    else if (s == "cmd")
        system("cmd");
#elif __APPLE__
    else if (s == "csh")
        system("csh");
    else if (s == "dash")
        system("dash");
    else if (s == "rbash")
        system("rbash");
    else if (s == "tmux")
        system("tmux");
    else if (s == "ksh")
        system("ksh");
    else if (s == "tcsh")
        system("tcsh");
    else if (s == "bash")
        system("bash");
    else if (s == "sh")
        system("sh");
    else if (s == "zsh")
        system("zsh")
#endif
                else cout
            << "Command \"" << s << "\" is not a function\n";
    return 0;
}
int main(int argc, char **argv)
{
    bool pass = true;
    show("Init Python Manage settings ", 3, 3);
    show("Looking for Python ", 5, 3);
scan:
    system("python --version > tmp.txt");
    ifstream fin("tmp.txt");
    string s, w;
    fin >> s;
    if (s != "Python")
        if (system_install_python())
        {
            Sleep(3000);
            return 0;
        }
    fin.close();
    s.clear();
    if (argc >= 2 && pass)
    {
        pass = false;
        for (int i = 0; i < argc; i++)
        {
            s = argv[i];
            if (s == "-c")
            {
                cmd(argv[i + 1]);
            }
        }
    }
    while (1)
    {
        cout << "PyManager" << Version << " $ ";
        cin >> s;
        if (s == "scan")
            goto scan;
        pass = cmd(s);
        if (pass)
            return 0;
    }
}