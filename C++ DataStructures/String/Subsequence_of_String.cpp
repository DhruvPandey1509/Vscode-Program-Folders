#include <iostream>
#include <cstring>
using namespace std;

void printSubsq(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    printSubsq(input.substr(1), output);            // excluding one left character (a in abcd)
    printSubsq(input.substr(1), output + input[0]); // including one left character(a in abcd)
}

int main()
{
    string s;
    cin >> s;
    printSubsq(s, " ");
    return 0;
}