#include <iostream>
#include <string>
#include <vector>
//
#include <cstdlib>
//
#include "class\Prime\Prime.hpp"

using namespace std;

void choice(const vector<string>& str_argv);

int main(int argc, char* argv[]) {
    cout << endl;
    cout << "|=================|" << endl;
    cout << "|Programme started|" << endl;
    cout << "|=================|" << endl;
    //
    vector<string> str_argv;
    for (int i = 1; i < argc; i++) {
        str_argv.push_back(argv[i]);
    }
    //
    choice(str_argv);
    //
    cout << endl;
    cout << "|===============|" << endl;
    cout << "|Programme ended|" << endl;
    cout << "|===============|" << endl;
    //
    return 0;
}

void choice(const vector<string>& str_argv) {
    string name;
    long number;
    int per_line;
    double total;
    //
    if (str_argv.size() == 0) {
        string cin_str;
        //
        cout << endl;
        cout << "|-------------------------|" << endl;
        cout << "|No arguments, try '-help'|" << endl;
        cout << "|-------------------------|" << endl;
        //
        cout << endl;
        cout << "File name :";
        getline(cin, name);
        //
        cout << endl;
        cout << "How many primes :";
        getline(cin, cin_str);
        number = atol(cin_str.c_str());
        //
        cout << endl;
        cout << "How many char per line :";
        getline(cin, cin_str);
        per_line = atoi(cin_str.c_str());
        //
        cout << endl;
        cout << "How many lines :";
        getline(cin, cin_str);
        total = atof(cin_str.c_str());
        total *= per_line;
    } else if (str_argv.size() == 1 && str_argv[1] == "-help") {
        cout << endl;
        cout << "Help :" << endl;
        cout << "-Not implemented yet." << endl;
        return;
    } else {
        if (str_argv.size() >= 2) {
            name = str_argv[0];
            number = atol(str_argv[1].c_str());
        } else {
            name = "default";
            number = 1000;
        }
        //
        if (str_argv.size() >= 4) {
            per_line = atoi(str_argv[2].c_str());
            total = atof(str_argv[3].c_str());
            total *= per_line;
        } else {
            cout << endl;
            cout << "File name :" << name << endl;
            //
            cout << endl;
            cout << "How many primes :" << number << endl;
            //
            cout << endl;
            cout << "Without loading bar." << endl;
            //
            prime::calc("./prime_" + name + ".txt", number);
            return;
        }
        //
        cout << endl;
        cout << "File name :" << name << endl;
        //
        cout << endl;
        cout << "How many primes :" << number << endl;
        //
        cout << endl;
        cout << "How many char per line :" << per_line << endl;
        //
        cout << endl;
        cout << "How many lines :" << total / per_line << endl;
    }
    //
    prime::calc("./prime_" + name + ".txt", number, per_line, total);
}
