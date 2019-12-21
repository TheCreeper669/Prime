// C++ libs
#include <iostream>
#include <string>
#include <vector>
// scp libs
#include "scp/prime.hpp"

using namespace std;

void choice(const vector<string>& args);

int main(int argc, char* argv[]) {
    cout << endl;
    cout << "|=================|" << endl;
    cout << "|Programme started|" << endl;
    cout << "|=================|" << endl;
    cout << endl;
    //
    vector<string> args;
    for (int i = 1; i < argc; i++)
        args.push_back(argv[i]);
    //
    choice(args);
    //
    cout << endl;
    cout << "|===============|" << endl;
    cout << "|Programme ended|" << endl;
    cout << "|===============|" << endl;
    //
    return 0;
}

void choice(const vector<string>& args) {
    string filename;
    unsigned long long number = 0;
    int char_per_line = 0;
    int number_line = 0;
    //
    bool help = false;
    //
    if (args.size() > 0) {
        for (unsigned long long i = 0; i < args.size(); i++) {
            if (args[i] == "-f")
                filename = args[++i];
            else if (args[i] == "-n")
                number = stoull(args[++i]);
            else if (args[i] == "-l") {
                char_per_line = stoi(args[++i]);
                number_line = stoi(args[++i]);
            } else if (args[i] == "-h" || args[i] == "--help")
                help = true;
        }
        //
        if (help) {
            cout << "Usage:" << endl;
            cout << "    prime [-h, --help] [-f filename] [-n number] [l char_per_line number_line]" << endl;
            cout << "        : args interface mode" << endl;
            cout << "    prime" << endl;
            cout << "        : user interface mode" << endl;
            cout << "Options:" << endl;
            cout << "    -h                               prints help message and exit" << endl;
            cout << "    -f filename                      set filename" << endl;
            cout << "    -n number                        set number of primes to compute" << endl;
            cout << "    -l char_per_line number_line     displays a loading bar" << endl;
            cout << endl;
            return;
        }
        //
        if (filename == "")
            filename = "default";
        cout << "filename: '" << filename << "'" << endl;
        if (number == 0)
            number = 1000;
        cout << "number: " << number << endl;
        if (number_line * char_per_line == 0) {
            cout << "Without loading bar." << endl;
            cout << endl;
            scp::prime::calc("./prime_" + filename + ".txt", number);
        } else {
            cout << "char per line: " << char_per_line << endl;
            cout << "line: " << number_line << endl;
            cout << endl;
            scp::prime::calc("./prime_" + filename + ".txt", number, char_per_line, char_per_line * number_line);
        }
    } else {
        string cin_str;
        //
        cout << "|----------------------|" << endl;
        cout << "|No arguments, try '-h'|" << endl;
        cout << "|----------------------|" << endl;
        cout << endl;
        //
        cout << "File name: ";
        getline(cin, filename);
        //
        cout << "How many primes: ";
        getline(cin, cin_str);
        number = stoull(cin_str);
        //
        cout << "How many char per line: ";
        getline(cin, cin_str);
        char_per_line = stoi(cin_str);
        //
        cout << "How many lines: ";
        getline(cin, cin_str);
        number_line = stoi(cin_str);
        //
        if (char_per_line * number_line == 0)
            scp::prime::calc("./prime_" + filename + ".txt", number);
        else
            scp::prime::calc("./prime_" + filename + ".txt", number, char_per_line, char_per_line * number_line);
    }
}
