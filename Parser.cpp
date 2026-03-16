#include "Parser.hpp"

#include <filesystem>
namespace fs = std::filesystem;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Parser::Parser(int argc, char *argv[])
{
    int arg = 0;

    while (arg < argc - 1)
    {
        arg++;
        string tmp(argv[arg]);
        
        if (tmp == "-h" || tmp == "--help")
        {
            cout << "-h or --help to see list of all cows and clouds" << endl;
            cout << "-l to see list of all cows and clouds" << endl;
            cout << "-f [cowname] to change the cow source" << endl;
            cout << "-c [cloudname] to change the cloud source" << endl;
            cout << "-b [char] to change background character" << endl;
            cout << "-T [1 or 2 chars] to set a tongue" << endl;
	        cout << "-s [string] to change sun" << endl;
            exit(0);
        }

        else if (tmp == "-l") {

            cout << "\tcows:" << endl;
            std::string path = "cows";
            for (const auto & entry : fs::directory_iterator(path))
                cout << entry.path() << endl;

            cout << "\tclouds:" << endl;
            path = "clouds";
            for (const auto & entry : fs::directory_iterator(path))
                cout << entry.path() << endl;
            
            exit(0);
        }

        if (tmp == "-f")
        {
            arg++;
            if ( arg >= argc ) {
                cout << "\tNo cow file (use basename, e.g. ...):" << endl;
                for (const auto & entry : fs::directory_iterator("cows"))
                    cout << entry.path() << endl;
                exit(1);
            }
            cowsource = argv[arg];
            flags.cow = true;
        }

        else if (tmp == "-c")
        {
            arg++;
            if ( arg >= argc ) {
                cout << "\tNo cloud file (use basename, e.g. \"mipt\"):" << endl;
                for (const auto & entry : fs::directory_iterator("clouds"))
                    cout << entry.path() << endl;
                exit(1);
            }
            cloudsource = argv[arg];
            flags.cloud = true;
        }

        else if (tmp == "-b")
        {
            arg++;
            if ( arg >= argc ) {
                cout << "\tNo background symbol" << endl;
                exit(1);
            }
            background = argv[arg];
            flags.background = true;
        }

        else if (tmp == "-T")
        {
            arg++;
            if ( arg >= argc ) {
                cout << "\tNo tongue" << endl;
                exit(1);
            }
            tongue = argv[arg];
            flags.tongue = true;
        }

        else if (tmp == "-s")
        {
            arg++;
            if ( arg >= argc ) {
                cout << "\tNo sun string" << endl;
                exit(1);
            }
            sunsource = argv[arg];
            flags.sun = true;
        }

        else while (arg < argc)
        {
            string tmp(argv[arg]);
            message += tmp;
            message += ' ';
            arg++;
        }
    }

    if (message.size() == 0)
    {
        cin >> message;
    }
}

Parser::~Parser() { }

string Parser::getCow()
{
    if (flags.cow)
        return cowsource;
    else
        return "cow";
}

string Parser::getCloud()
{
    if (flags.cloud)
        return cloudsource;
    else
        return "cloud";
}

string Parser::getTongue()
{
    if (flags.tongue)
        return tongue.append(" ").substr(0, 2);
    else
        return "  ";
}

char Parser::getFill()
{
    if ( flags.background )
        return background[0];
    else
        return ' ';
}

string Parser::getSun()
{
    if (flags.sun)
        return sunsource;
    else
        return ">O<";
}

string Parser::getMessage()
{
    return message;
}