#include <iostream>
using namespace std;
int seq[1000000];
int collatzSequenceLen(int n) {
    int len=0;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        seq[1] = 1;
        return 1;
    }

    if(seq[n]!=0){
        return seq[n];
    }

    else{
        if (n % 2 == 0) {
            len=1 + collatzSequenceLen(n/2);
            seq[n]=len;
            return len;
        }

        len= 1 + collatzSequenceLen(3*n+1);
        seq[n]=len;
        return len;
    }

}

int collatzSequenceSum(int T, int A, int B) {
    int n = 0, p=0;
    int result = 0;
    int cur_len;
    while (T--) {
        n = (A*n + B) % 5003;
        cout<<n<<"\n";
        int best_len = 0;
        int best_num = 0;
        for (int k = 0; k <= n; ++k) {
            cur_len = collatzSequenceLen(k);
            cout<<cur_len;
            cout<<" ";
            if (cur_len >= best_len) {
                best_len = cur_len;
                best_num = k;
            }
        }
        cout<<endl;
        result += best_num;
        p=n;
    }
    return result;
}
int main() {
    int T;
    int A;
    int B;
    cin >> T >> A >> B;
    int result = collatzSequenceSum(T, A, B);
    cout << result << endl;
    return 0;
}
