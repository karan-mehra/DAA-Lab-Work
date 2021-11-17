//Author Karan Mehra
// Week-02 Problem 02
/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

pii two_pointers(vector<int> a, int n) {
    int i = 1, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == a[n]) {
            return {i, j};
        }else if(a[i] + a[j] < a[n]) {
            i++;
        }else {
            j--;
        }
    }
    return {-1, -1};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n++;
        vector<int> a(n);
        for(int i = 1; i < n; i++) {
            cin >> a[i];
        }
        int f = -1;
        int s = -1;
        int k = -1;

        for(int i = 3; i < n; i++) {
            pii p = two_pointers(a, i);
            if(p.first != -1 && p.second != -1) {
                f = p.first;
                s = p.second;
                k = i;
                break;
            }
        }

        if (k != -1) {
            cout << f << ", " << s << ", " << k << endl;
        }
        else
            cout << "No sequence found." << endl;
    }
    return 0;
}