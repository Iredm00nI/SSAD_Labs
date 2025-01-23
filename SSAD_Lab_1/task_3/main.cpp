#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

//..........Using array..........
//    int array[n];
//    for (int i=0; i<n; i++) {
//        int x;
//        cin >> x;
//        array[i] = x;
//    }
//
//    for (int i=0; i<n; i++) {
//        bool flag = true;
//        for (int j=0; j<i; j++) {
//            if (array[i] == array[j]) {
//                flag = false;
//            }
//        }
//        if (flag) {
//            cout << array[i] << " ";
//        }
//    }

//..........Using vector..........
    vector<int> vec;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    for (int i=0; i<vec.size(); i++) {
        for(int j=0; j<i; j++) {
            if (vec[i] == vec[j]) {
                vec.erase(vec.begin() + i);
                i--;
                break;
            }
        }
    }

    for (auto v : vec) {
        cout << v << " ";
    }

    return 0;
}
