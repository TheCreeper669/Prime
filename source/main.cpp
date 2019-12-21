#include <iostream>
#include "class\Prime\Prime.hpp"

using namespace std;

int main(int argc, char *argv[]){
    cout << endl;
    cout << "|=================|" << endl;
    cout << "|Programme started|" << endl;
    cout << "|=================|" << endl;
    //
    string filePathEnd;
    cout << "File name :";
    cin >> filePathEnd;
    //
    Prime prime("./prime_" + filePathEnd + ".txt");
    prime.calc();
    //
    cout << endl;
    cout << "|===============|" << endl;
    cout << "|Programme ended|" << endl;
    cout << "|===============|" << endl;
}
