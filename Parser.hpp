#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;

class Parser {

private:
    string cowsource, cloudsource, tongue, sunsource, message, background;
    struct Flags {
        bool cow = false;
        bool cloud = false;
        bool background = false;
        bool tongue = false;
        bool sun = false;
        bool eyes = false;
    } flags;

public:
    Parser(int argc, char *argv[]);
    ~Parser();

    string getCow();
    string getCloud();
    string getTongue();
    char   getFill();
    string getSun();
    string getMessage();
};

#endif
