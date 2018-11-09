#define MAX_N 1000 // adjust this value as needed
#define LOG_TWO_N 10// 2^10 > 1000, adjust this value as needed

class RMQ {
private:
  int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
  RMQ(int n, int A[]) { //n: sizeof A 
    for (int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i;
    }
    // O(n log n)
    for (int j = 1; (1<<j) <= n; j++) //O(log n)
      for (int i = 0; i + (1<<j) - 1 < n; i++) // O(n)
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]]) // RMQ
          SpT[i][j] = SpT[i][j-1];
        else SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else                                         return SpT[j-(1<<k)+1][k];
} };