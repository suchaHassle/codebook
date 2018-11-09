ll _sieve_size;
bitset<10000010> bs; // #include <bitset>
vi primes;

// call this first!!!!!
void sieve(ll upperbound) { // can go up to 10^7 (need few seconds)
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
} }

bool isPrime(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true; 
} // note: only work for N <= (last prime in vi "primes")^2

vi primeFactors(ll N) {// remember: vi is vector of integers, ll is long long
  vi factors;// vi `primes' is optional
  ll PF_idx = 0, PF = primes[PF_idx];
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

ll numPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll numDiffPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans++;
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll sumPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans += PF; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans += N;
  return ans;
}
// 1, 2, 5, 10, 25, 50, 6 divisors
ll numOfDivisors(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0; // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;
  return ans;
}
// N=50 : 1 + 2 + 5 + 10 + 25 + 50 = 93
ll sumOfDivisors(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
  return ans;
}
//  20 integers < 50 are relatively prime with 50
ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;r
  return ans;
}