#include <bits/stdc++.h>
using namespace std;


int operations = 0;
int depth=0,maxd=0;

void complexRec(int n) {
  maxd= max(maxd,depth);
   if (n <= 2) {
        
        return;
        depth++;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
    } else {
        reverse(small.begin(), small.end());
    }

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    depth--;
}

int main() {
    int n;
    cin >> n;

    complexRec(n);
    cout << operations << endl;
    cout << maxd << endl;

    return 0;
}





//t(n)=3t(n/2)+ nlogn --function n/2 is called 3 times with n iterations of f(n)

//f(n)=n g(n)=n^(log b a) = n^(log 2 3) f(n)<g(n) so case 1 of master theorem applies
//so t(n)=O(nlog b a)=O(nlog 2 3)

