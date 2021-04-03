#include <iostream>
#include <string>
#include <cstring>
#ifdef _WIN32
#define OS_Windows
#endif
#ifdef __APPLE__
#define OS_X
#endif
#ifdef linux
#define OS_Linux
#endif
using namespace std;

void search(string searchquery, bool useful)
{
    string command, engine;
    if (useful)
    {
        engine = "https://duckduckgo.com/";
    }
    else
    {
        engine = "https://that1m8head.github.io/searchless/";
    }
    #ifdef OS_X
    command = "open " + engine + "?q=" + searchquery;
    #endif
    #ifdef OS_Windows
    command = "start " + engine + "?q=" + searchquery;
    #endif
    #ifdef OS_Linux
    command = "xdg-open " + engine + "?q=" + searchquery;
    #endif
    system(command.c_str());
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        search(argv[1], true);
    }
    if (argc > 2)
    {
        if (strcmp(argv[1], "less") == 0)
        {
            int x; string whole, withspace;
            for (x = 2; x < argc; x++)
            {
                withspace = argv[x];
                if (x < argc - 1)
                {
                    withspace.append("+");
                }
                whole.append(withspace);
            }
            search(whole, false);
        }
        else
        {
            int x; string whole, withspace;
            for (x = 1; x < argc; x++)
            {
                withspace = argv[x];
                if (x < argc - 1)
                {
                    withspace.append("+");
                }
                whole.append(withspace);
            }
            search(whole, true);
        }
    }
}