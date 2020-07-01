#include <iostream>

using namespace std;

long long int dividethepow(int n, int r){
    if(r == 1) 
        return n;
    else if(r % 2 == 0){
        long long int t = dividethepow(n, r / 2);
        return t * t;
    }
    else{
        long long int t = dividethepow(n, (r - 1) / 2);
        return t * t * n;
    }
}

int main() {
    int tests_number;
    cin >> tests_number;
    int tests[tests_number];
    for(int t = 0; t < tests_number; ++t){
        cin >> tests[t];
    }
    for(int t = 0; t < tests_number; ++t){
        int test = tests[t], r = 0;
        for(int n = test; n > 0; n /= 10){
            r = r * 10 + n % 10;
        }        
        cout << dividethepow(test, r) << "\n";
    }
	return 0;
}