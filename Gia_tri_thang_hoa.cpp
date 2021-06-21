// Solve 1 
#include <bits/stdc++.h>
#define EL cout<<endl
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define can(n, q) round(exp(log(n) / q))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "valval"

using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// ordered_set name_of_set;
// int pos = *name_of_set.find_by_order(int(value));
*/
typedef long long ll;
typedef double db;

/*
template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
*/

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

const bool love = true;
namespace bignum
{

	void fix(string &a, string &b)
	{
		while (a.length()<b.length()) a = "0" + a;
		while (b.length()<a.length()) b = "0" + b;
	}

	string operator + (string a, string b)
	{
		long int sum, carry = 0, i;
		string c = "";

		fix(a, b);

		for (i = a.length() - 1; i >= 0; i--)
		{
			sum = a[i] - 48 + b[i] - 48 + carry;
			carry = sum / 10;
			c = char(sum % 10 + 48) + c;

		}

		if (carry>0) c = "1" + c;
		return c;

	}

	string multi(string a, int b){

		if (b == 0) return "0";
		if (b == 1) return a;
		string tmp = multi(a, b / 2);
		if (b % 2 == 0) return tmp + tmp;
		else return a + tmp + tmp;

	}


	string operator * (string a, string b)
	{
		string res = "";
		int n = a.length();
		int m = b.length();
		int len = n + m - 1;
		int carry = 0;
		for (int i = len; i >= 0; i--)
		{
			int tmp = 0;
			for (int j = n - 1; j >= 0; j--)
				if (i - j <= m && i - j >= 1)
				{
					int a1 = a[j] - 48;
					int b1 = b[i - j - 1] - 48;
					tmp += a1*b1;
				}
			tmp += carry;
			carry = tmp / 10;
			res = (char)(tmp % 10 + 48) + res;
		}
		while (res.length()>1 && res[0] == '0') res.erase(0, 1);
		return res;
	}

	string poww(string a, int b){
        if (b == 0) return "1";
        if (b == 1) return a;
        string t = poww(a, b / 2);
        t = t * t;
        if (b % 2 == 0) return t;
        return t * a;
	}

}
using namespace bignum;

pair<ll, ll> factor(ll n) {
    ll s = 0;
    while ((n & 1) == 0) {
        s++;
        n >>= 1;
    }
    return {s, n};
}

ll mul(ll x,ll y,ll mod){
    ll res = 0;
    x = x % mod;
    while (y > 0){
        if (y & 1) res = (res + x) % mod;
        y >>= 1;
        x = (x + x) % mod;
    }
    return res;
}

ll pow(ll x,ll y,ll mod){
    ll res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1) res = mul(res,x,mod);
        y >>= 1;
        x = mul(x,x,mod);
    }
    return res;
}

bool test_a(ll s, ll d, ll n, ll a) {
    if (n == a) return true;
    ll p = pow(a, d, n);
    if (p == 1) return true;
    for (; s > 0; s--) {
        if (p == n-1) return true;
        p = mul(p, p, n);
    }
    return false;
}

bool miller(ll n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    ll s, d;
    tie(s, d) = factor(n-1);
    return test_a(s, d, n, 2) && test_a(s, d, n, 3)
        && test_a(s, d, n, 7 && test_a(s, d, n, 5))
        && test_a(s, d, n, 11) && test_a(s, d, n, 13)
        && test_a(s, d, n, 17) && test_a(s, d, n, 19);
}

ll a, b, c;
const int N = 1e6;
int pr[78500], m = 0; bool p[N + 1];
ll U(ll x){
    ll res = 0;
    while (x){
        res+= x % 10;
        x/= 10;
    }
    return res;
}

bool Square(ll x){
    ll tmp = sqrt(x);
    if (tmp * tmp == x) return true;
    return false;
}

ll F(ll x){
    if (x == 1) return 1;
    ll ans = 1;

    FU(i, 1, m){
        ll t = ll(pr[i]);
        if (t * t * t > x) break;
        ll cnt = 1;
        while (x % pr[i] == 0){
            x = x / pr[i];
            cnt++;
        }
        ans = ans * cnt;
    }
    if (miller(x)) ans*= 2;
    else if (Square(x) && miller(ll(sqrt(x)))) ans*= 3;
    else if (x != 1) ans*= 4;

    return ans;
}

ll cdiv(ll x){
    ll res = 0;
    FU(i, 1, ll(sqrt(x))){
        if (x % i) continue;
        cout << i << ' ';
        res++;
        if (i * i != x){
            cout << x / i << ' ';
            res++;
        }
    }
    return res;
}

string convert(ll x){
    string res = "";
    while (x) res = res + char(x % 10 + '0'), x/= 10;
    reverse(res.begin(), res.end());
    return res;
}

string cal(ll x){
    string f = convert(F(x));
    string u = convert(U(x));
    string t = convert(x);
//    cdiv(23951209663);
//    cout << f << ' ' << cdiv(x),EL;
    return t * f * f * u * u * u;
}

void readinp(){
    cin >> a >> b >> c;
}

void solve(){
//    cout << cal(a);
    cout << cal(a) << ' ' << cal(b) << ' ' << cal(c),EL;
}

int main(){
    setIO();

    FU(i, 2, N){
        if (p[i]) continue;
        pr[++m] = i;
        for (int j = 2 * i; j <= N; j+= i)
            p[j] = true;
    }

    int t = 1;
    cin >> t;
    while (t--){
        readinp();
        solve();
    }
    return 0;
}
/************/
/*Solve 2*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2;
LL mul(LL a, LL b, LL mod)
{
    if (!a)
        return 0;
    return ((a & 1) * b % mod + (mul(a >> 1, b, mod) << 1) % mod) % mod;
}
LL quickPow(LL a, LL d, LL n)
{
    LL ret = 1;
    while (d)
    {
        if (d & 1)
            ret = mul(ret, a, n);
        d >>= 1;
        a = mul(a, a, n);
    }
    return ret;
}
bool check(LL a, LL d, LL n)
{
    if (n == a)
        return true;
    while (~d & 1)
        d >>= 1;
    LL t = quickPow(a, d, n);
    while (d < n - 1 && t != 1 && t != n - 1)
    {
        t = mul(t, t, n);
        d <<= 1;
    }
    return (d & 1) || t == n - 1;
}
bool isP(LL n)
{
    if (n == 2)
        return true;
    if (n < 2 || 0 == (n & 1))
        return false;
    static int p[10] = {2,3};
    for (int i = 0; i < 2; ++i)
        if (!check(p[i], n - 1, n))
            return false;
    return true;
}
LL gcd(LL a, LL b)
{
    if (a < 0)
        return gcd(-a, b);
    return b ? gcd(b, a % b) : a;
}
LL Pollard_rho(LL n, LL c)
{
    LL i = 1, k = 2, x = rand() % n, y = x;
    while (true)
    {
        x = (mul(x, x, n) + c) % n;
        LL d = gcd(y - x, n);
        if (d != 1 && d != n)
            return d;
        if (y == x)
            return n;
        if (++i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}
LL Fac[maxn], tot;
void factorization(LL n)
{
    if (isP(n))
    {
        Fac[tot++] = n;
        return;
    }
    LL p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
        // p = Pollard_rho(p, 2);
    factorization(p);
    factorization(n / p);
}
unordered_map<LL, LL> ump;
LL u(LL source)
{
    string s = to_string(source);
    LL res = 0;
    for (LL i = 0; i < s.size(); i++)
    {
        res = res + (s[i] - '0');
    }
    return res;
}
string nhan(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {

            int n2 = num2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    LL x;
    srand(time(0));
    LL tc;
    cin >> tc;
    while (tc--)
    {
        for (LL i = 0; i < 3; i++)
        {
            cin>>x;
            tot = 0;
            unsigned long long fi, se, th;
            fi = x;
            // if (x == 1)
            // {
            //     se = 1;
            // }
            // if (isP(x))
            // {
            //     se = 4;
            // }
            factorization(x);
            ump.clear();
            for (int i = 0; i < tot; ++i)
                ump[Fac[i]]++;
            long long ret = 1;
            for (auto &it : ump)
                ret *= (it.second + 1);
            se = ret * ret;
            th = u(fi);
            // cout<<th<<"haha"<<'\n';
            th = th * th * th;
            string anss;
            string fi_str = to_string(fi);
            string se_str = to_string(se);
            string th_str = to_string(th);
            anss = nhan(fi_str, nhan(se_str, th_str));
            cout<<anss<<" ";
        }
        cout << '\n';
    }

    return 0;
}
