#include <iostream>
#include <vector>

using namespace std;

int main() {
    //массив от 1 до n
    //v[i] * (i + 1)
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++) {
        v[i] = i + 1;
    }
    int counter = 0;
    do{
        int sum = 0;
        for(int i = 0; i < v.size(); i++) {
            sum += v[i] * (i + 1);
        }
        if(sum % k == 0) {
            counter++;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << counter;
    return 0;
}
