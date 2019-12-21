#include <iostream>
#include <string>
#include <vector>
//
#include <cstdlib>
#include <cstring>
//
#include "./Prime/Prime.hpp"

using namespace std;

void choice(const vector<char*>& args);

int main(int argc, char* argv[]) {
    cout << endl;
    cout << "|=================|" << endl;
    cout << "|Programme started|" << endl;
    cout << "|=================|" << endl;
    //
    vector<char*> args;
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

void choice(const vector<char*>& args) {
    string name;
    uint64_t number;
    int per_line;
    int total;
    //
    if (args.size() == 0) {
        string cin_str;
        //
        cout << endl;
        cout << "|-------------------------|" << endl;
        cout << "|No arguments, try '--help'|" << endl;
        cout << "|-------------------------|" << endl;
        //
        cout << endl;
        cout << "File name: ";
        getline(cin, name);
        //
        cout << endl;
        cout << "How many primes: ";
        getline(cin, cin_str);
        number = strtoull(cin_str.c_str(), nullptr, 10);
        //
        cout << endl;
        cout << "How many char per line: ";
        getline(cin, cin_str);
        per_line = atoi(cin_str.c_str());
        //
        cout << endl;
        cout << "How many lines: ";
        getline(cin, cin_str);
        total = atoi(cin_str.c_str());
        total *= per_line;
        //
        if (total == 0)
            scp::prime::calc("./prime_" + name + ".txt", number);
        else
            scp::prime::calc("./prime_" + name + ".txt", number, per_line, total);
    } else if (args.size() == 1 && strncmp(args[0], "--help", 6) == 0) {
        cout << endl;
        cout << "Help:" << endl;
        cout << "-Not implemented yet." << endl;
        return;
    } else {
        if (args.size() >= 1)
            name = args[0];
        else
            name = "default";
        //
        if (args.size() >= 2)
            number = strtoull(args[1], nullptr, 10);
        else
            number = 1000;
        //
        cout << endl;
        cout << "File name: " << name << endl;
        //
        cout << endl;
        cout << "How many primes: " << number << endl;
        //
        if (args.size() >= 4) {
            per_line = atoi(args[2]);
            total = atoi(args[3]);
            total *= per_line;
            //
            cout << endl;
            cout << "How many char per line: " << per_line << endl;
            //
            cout << endl;
            cout << "How many lines: " << total / per_line << endl;
            //
            scp::prime::calc("./prime_" + name + ".txt", number, per_line, total);
        } else {
            cout << endl;
            cout << "Without loading bar." << endl;
            //
            scp::prime::calc("./prime_" + name + ".txt", number);
        }
    }
}
