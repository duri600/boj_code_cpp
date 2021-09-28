#include <iostream>
#include <vector>
#define MAX 31
using namespace std;

int N, M, H;
int MAP[MAX][11] = { 0, };
int ans = 999;
int minimum_v;

int ladder_result(int i)
{
    for (int r = 1; r <= H; r++)
    {
        if (MAP[r][i] == 1)
        {
            i = i + 1;
            continue;
        }
        else if(MAP[r][i - 1] == 1)
        {
            i = i - 1;
            continue;
        }
    }
    
    return i;
}

bool check()
{
    for (int i = 1; i <= N; i++)
    {
        if (i != ladder_result(i))
        {
            return false;
        }
    }
    return true;
}

void solve(int sr, int sc, int len)
{
    if (len > ans)
    {
        return;
    }
    if (check())
    {
        ans = len;
        return;
    }
    if (len == 3)
    {
        return;
    }

    for (int i = sr; i <= H; i++)
    {
        for (int j = sc; j < N; j++)
        {
            if (MAP[i][j] == 0 && MAP[i][j - 1] == 0 && MAP[i][j + 1] == 0)
            {
                MAP[i][j] = 1;
                solve(i, j, len + 1);
                MAP[i][j] = 0;
            }
        }
        sc = 1;
    }

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
    }

    ans = 4;
    solve(1, 1, 0);
    if (ans == 4)
    {
        ans = -1;
    }

    cout << ans;
    return 0;
}