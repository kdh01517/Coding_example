#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n, m;
int note[520][520]; // 노트 정보를 위한 배열
int tet[5][5];      // 테트블럭을 위한 배열
int k = 5;          // 테트블럭의 수

//회전 함수
void rotate()
{
    int tmp[5][5];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = tet[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tet[i][j] = tmp[4 - 1 - j][i];
}
// y축 대칭 함수
void y_mirror()
{
    int tmp[5][5];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = tet[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tet[i][j] = tmp[i][4 - j - 1];
}
// x축 대칭 함수
void x_mirror()
{
    int tmp[5][5];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = tet[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tet[i][j] = tmp[4 - i - 1][j];
}
// 점 대칭 함수
void sp_mirror()
{
    int tmp[5][5];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = tet[i][j];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tet[i][j] = tmp[4 - i - 1][4 - j - 1];
}
// note에서 최대값 반환 함수
int max_tet(int x, int y)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
			if (x + i < 0 || y + j < 0)
				continue;
            if (note[x + i][y + j] && tet[i][j] == 1)
            {
                sum += note[x + i][y + j];
                cnt++;
            }
        }
    }
    if (cnt == 4)
        return sum;
    else
        return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int val = 0;
    // 맵 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> note[i][j];
    while (k > 0) // 테트블럭 수 만큼 반복 -> 5번
    {
        // 테트블럭 초기화
        for (int p = 0; p < 5; p++)
            for (int q = 0; q < 5; q++)
                tet[p][q] = 0;
        if (k == 5)
        {
            // ---- 모양
            tet[0][0] = 1;
            tet[0][1] = 1;
            tet[0][2] = 1;
            tet[0][3] = 1;
        }
        else if (k == 4)
        {
            // ㅁ 모양
            tet[0][0] = 1;
            tet[0][1] = 1;
            tet[1][0] = 1;
            tet[1][1] = 1;
        }
        else if (k == 3)
        {
            // ㅜ 모양
            tet[0][0] = 1;
            tet[0][1] = 1;
            tet[0][2] = 1;
            tet[1][1] = 1;
        }
        else if (k == 2)
        {
            // 번개 모양
            tet[0][0] = 1;
            tet[1][0] = 1;
            tet[1][1] = 1;
            tet[2][1] = 1;
        }
        else if (k == 1)
        {
            // ㄴ 모양
            tet[0][0] = 1;
            tet[1][0] = 1;
            tet[2][0] = 1;
            tet[2][1] = 1;
        }
        // 90도 4번 돌리기
        for (int rot = 0; rot < 4; rot++)
        {
            // 기본형 확인
            for (int x = -3; x < n; x++)
                for (int y = -3; y < m; y++)
                    val = max(val, max_tet(x, y));
            y_mirror();
            // y축 대칭 확인
            for (int x = -3; x < n; x++)
                for (int y = -3; y < m; y++)
                    val = max(val, max_tet(x, y));
            y_mirror();
            x_mirror();
            // x축 대칭 확인
            for (int x = -3; x < n; x++)
                for (int y = -3; y < m; y++)
                    val = max(val, max_tet(x, y));
            x_mirror();
            sp_mirror();
            // 점 대칭 확인
            for (int x = -3; x < n; x++)
                for (int y = -3; y < m; y++)
                    val = max(val, max_tet(x, y));
            sp_mirror();
            rotate(); // 회전
        }
        k--;
    }

    cout << val << '\n';
}


/*
반례
https://www.acmicpc.net/board/view/38779
*/
/*

1 1 1 1 1
1 1 5 1 1
1 5 5 1 1
1 1 5 1 1
1 1 1 1 1    

0001
0011
0001
0000

*/