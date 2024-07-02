#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int hexToDec(string hex, int len) {
    int ans=0;
    string alph = "0123456789abcdef";
    for (int i=0; i<len; i++) {
        for (int j=0; j<16; j++) {
            if (hex[i] == alph[j]) {
                ans += j*pow(16, len-i-1);
                break;
            }
        }
    } return ans;
}

string decToHex(int n) {
    if (!n) {
        return "00";
    } string hex="", alph="0123456789abcdef";
    while (n) {
        hex = alph[n%16] + hex;
        n /= 16;
    }
    if (hex.length() == 1) {
        return ("0" + hex);
    } return hex;
}

void color(string c1, string c2, int n) {
    string r1=c1.substr(0,2), r2=c2.substr(0,2);
    string g1=c1.substr(2,2), g2=c2.substr(2,2);
    string b1=c1.substr(4,2), b2=c2.substr(4,2);
    string R, G, B;
    for (int i=1; i<=n; i++) {
        R = decToHex(hexToDec(r1,2) - i*double(hexToDec(r1,2)-hexToDec(r2,2))/double(n+1));
        G = decToHex(hexToDec(g1,2) - i*double(hexToDec(g1,2)-hexToDec(g2,2))/double(n+1));
        B = decToHex(hexToDec(b1,2) - i*double(hexToDec(b1,2)-hexToDec(b2,2))/double(n+1));
        cout << R+G+B << endl;
    }
}

int main() {
    string c1;
    string c2;
    int n;
    cin >> c1 >> c2 >> n;
    color(c1, c2, n);
}