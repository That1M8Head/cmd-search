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

void search(string searchquery, string engine)
{
    string command, engineurl;
    if (engine == "duck")
    {
        engineurl = "https://duckduckgo.com/";
    }
    else if (engine == "less")
    {
        engineurl = "https://that1m8head.github.io/searchless/";
    }
    else if (engine == "google")
    {
        engineurl = "https://www.google.com/search";
    }
    else if (engine == "youtube")
    {
        engineurl = "https://www.youtube.com/results";
    }
    else if (engine == "github")
    {
        engineurl = "https://github.com/search";
    }
    #ifdef OS_X
    command = "open " + engineurl + "?q=" + searchquery;
    #endif
    #ifdef OS_Windows
    command = "start " + engineurl + "?q=" + searchquery;
    #endif
    #ifdef OS_Linux
    command = "xdg-open " + engineurl + "?q=" + searchquery;
    #endif
    system(command.c_str());
}

string compile_search(int xargc, char* xargv[], bool extend_selection)
{
    int x, y; string whole, withspace;
    if (extend_selection) { y = 2; } else { y = 1; }
    for (x = y; x < xargc; x++)
    {
        withspace = xargv[x];
        if (x < xargc - 1)
        {
            withspace.append("+");
        }
        whole.append(withspace);
    }
    return whole;
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        search(argv[1], "duck");
    }
    if (argc > 2)
    {
        if (strcmp(argv[1], "-l") == 0 | strcmp(argv[1], "--less") == 0)
        {
            search(compile_search(argc, argv, true), "less");
        }
        else if (strcmp(argv[1], "-g") == 0 | strcmp(argv[1], "--google") == 0)
        {
            search(compile_search(argc, argv, true), "google");
        }
        else if (strcmp(argv[1], "-yt") == 0 | strcmp(argv[1], "--youtube") == 0)
        {
            search(compile_search(argc, argv, true), "youtube");
        }
        else if (strcmp(argv[1], "-gh") == 0 | strcmp(argv[1], "--github") == 0)
        {
            search(compile_search(argc, argv, true), "github");
        }
        else
        {
            search(compile_search(argc, argv, false), "duck");
        }
    }
}