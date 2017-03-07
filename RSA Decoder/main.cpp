#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    string msg, plaintxt;
    int relp, prod, p1, p2;
    stringstream coded, trans;

    cout << "Enter encoded message:  ";
    getline(cin, msg);

    cout << "Enter public encryption key (e, m):  ";
    cin >> relp >> prod;

    //finds primes used
    for (int i(1); i < sqrt(prod); i++) {
        if (prod % (i+1) == 0) {
            p1 = i+1;
            p2 = prod/(i+1);
        }
    }

    int phi = prod - (p1 + p2 -1);
    int sum(0), x, y(0);

    for (int i(0); sum != 1; i++){
        sum += max(phi, relp);

        for (int j(0); sum > 0 && sum != 1; ++j) {
            sum -= min(phi, relp);
            y--;
        }

        x++;
    }

    int exp = y % phi;
    //get positive exponent
    if (exp < 0) {
        exp += phi;
    }

    for (int pos(0); pos < msg.size(); pos += 4) {
        int block = atoi(msg.substr(pos, 4).c_str());

        int squ(1);
        //raise to binomial power
        for (int i(1); i < exp; i = pow(2, squ+1), squ++) {
            block = block*block % prod;
        }
        //raise to additional power
        for (int i = pow(2, squ-1); i < exp; i++) {
            block = block*atoi(msg.substr(pos, 4).c_str()) % prod;
        }

        coded << setfill('0') << setw(4) << block;
    }
    coded >> plaintxt;

    for (unsigned pos(0); pos < plaintxt.length(); pos += 2){
        string str = plaintxt.substr(pos, 2);
        switch (atoi(str. c_str())) {
        case 1:
            trans << 'a';
            break;
        case 2:
            trans << 'b';
            break;
        case 3:
            trans << 'c';
            break;
        case 4:
            trans << 'd';
            break;
        case 5:
            trans << 'e';
            break;
        case 6:
            trans << 'f';
            break;
        case 7:
            trans << 'g';
            break;
        case 8:
            trans << 'h';
            break;
        case 9:
            trans << 'i';
            break;
        case 10:
            trans << 'j';
            break;
        case 11:
            trans << 'k';
            break;
        case 12:
            trans << 'l';
            break;
        case 13:
            trans << 'm';
            break;
        case 14:
            trans << 'n';
            break;
        case 15:
            trans << 'o';
            break;
        case 16:
            trans << 'p';
            break;
        case 17:
            trans << 'q';
            break;
        case 18:
            trans << 'r';
            break;
        case 19:
            trans << 's';
            break;
        case 20:
            trans << 't';
            break;
        case 21:
            trans << 'u';
            break;
        case 22:
            trans << 'v';
            break;
        case 23:
            trans << 'w';
            break;
        case 24:
            trans << 'x';
            break;
        case 25:
            trans << 'y';
            break;
        case 26:
            trans << 'z';
            break;
        case 27:
            trans << ' ';
            break;
        }
    }
    getline(trans, msg);

    cout << "Decoded message is " << msg << endl;
    return 0;
}
//1892268423383699420303433637
