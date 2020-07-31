#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORZ(i, n) for (int i = 0; i < n; ++i)
int const DEFAULT_SIZE = 31;

int n, k, MOD;
struct MATRIX
{
    int SIZE;
    int matrix[DEFAULT_SIZE][DEFAULT_SIZE];
    MATRIX(int SIZE)
    {
        this->SIZE = SIZE;
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        matrix[i][j] = 0;
    }
    MATRIX()
    {
        this->SIZE = 30;
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        matrix[i][j] = 0;
    }
    MATRIX operator+(const MATRIX &p)
    {
        int SIZE = this->SIZE;
        MATRIX ret = MATRIX(SIZE);
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        ret.matrix[i][j] = (this->matrix[i][j] + p.matrix[i][j]) % MOD;
        return ret;
    }
    MATRIX operator*(const MATRIX &p)
    {
        int SIZE = this->SIZE;
        MATRIX ret = MATRIX(SIZE);
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        FORZ(k, SIZE)
        {
            ret.matrix[i][j] += (this->matrix[i][k] * p.matrix[k][j]) % MOD;
            ret.matrix[i][j] %= MOD;
        }
        return ret;
    }
    void identityMatrix()
    {
        FORZ(i, SIZE)
        matrix[i][i] = 1;
    }
};

struct MATRIX2
{
    int SIZE;
    MATRIX O = MATRIX(30);
    MATRIX matrix[2][2];
    MATRIX2(int SIZE)
    {
        this->SIZE = SIZE;
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        matrix[i][j] = O;
    }

    MATRIX2(int SIZE, MATRIX A)
    {
        MATRIX I(n);
        I.identityMatrix();
        this->SIZE = SIZE;
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        matrix[i][j] = O;
        this->matrix[0][0] = I;
        this->matrix[0][1] = I;
        this->matrix[1][0] = O;
        this->matrix[1][1] = A;
    }
    MATRIX2 operator*(const MATRIX2 &p)
    {
        int SIZE = this->SIZE;
        MATRIX2 ret = MATRIX2(SIZE);
        FORZ(i, SIZE)
        FORZ(j, SIZE)
        FORZ(k, SIZE)
        {
            ret.matrix[i][j] = ret.matrix[i][j] + (this->matrix[i][k] * p.matrix[k][j]);
        }
        return ret;
    }
    MATRIX2 powerMatrix(int k)
    {
        if (k == 1)
            return *(this);
        MATRIX2 m = powerMatrix(k / 2);
        m = m * m;
        //le
        if (k & 1)
            return m * *(this);
        return m;
    }
};

int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);

    cin >> n >> k >> MOD;

    MATRIX A = MATRIX(n);
    FORZ(i, n)
    FORZ(j, n)
    {
        cin >> A.matrix[i][j];
        A.matrix[i][j] %= MOD;
    }

    MATRIX2 m2 = MATRIX2(2, A);
    m2 = m2.powerMatrix(k);

    MATRIX rs = (A * m2.matrix[0][1]);
    FORZ(i, n)
    {
        FORZ(j, n)
        cout << rs.matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
