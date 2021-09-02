#include "bits/stdc++.h"
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int board[22][22];
int dist[22][22];
queue<pair<int, int> > bfsQ;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int eatCnt = 0;
    int sharkSize = 2;
    int timeSum = 0;

    cin >> n;
    for (int i = 0 ;i < n ;i ++) {
        for (int j = 0; j< n ;j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                bfsQ.push({i, j});
                board[i][j] = 0;
            }
        }
    }

    pair<int, int> target;
    int seq = 1;
    int next = 0;

    while (true) {
        // 물고기 먹기 준비
        vector<pair<int, int> > menu;
        next = 0;

        // 거리 같은 물고기를 메뉴판 채우기
        while (!bfsQ.empty()) {
            pair<int, int> cur = bfsQ.front();
            bfsQ.pop();

            for (int dir = 0 ; dir < 4 ; dir ++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] != 0 || board[nx][ny] > sharkSize)
                    continue;
                if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
                    menu.push_back({nx, ny});
                }
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                bfsQ.push({nx, ny});
                next ++;
            }
            seq--;
            if (seq <= 0) {
                if (!menu.empty()) {
                    break;
                }
                seq = next;
                next = 0;
            }
        }

        // 물고기 다 먹었으면 탈출
        if (menu.empty())
            break;

        target = menu[0];
        if (menu.size() != 1) {
            // 메뉴판에서 타겟 물고기 선정
            for (int i = 1; i < menu.size(); i++) {
                if (target.X > menu[i].X) {
                    target = menu[i];
                } else if (target.X == menu[i].X) {
                    if (target.Y > menu[i].Y) {
                        target = menu[i];
                    }
                }
            }
        }
        // 상어 상태 갱신
        eatCnt ++;
        if (eatCnt == sharkSize) {
            sharkSize++;
            eatCnt = 0;
        }

        // 물고기 하나 삭제, 시간 갱신, 거리 정보 초기화
        board[target.X][target.Y] = 0;
        timeSum += dist[target.X][target.Y];
        for(int i = 0; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                dist[i][j] = 0;
            }
        }
        // bfs 를 위한 큐 비우기
        while (!bfsQ.empty()) {
            bfsQ.pop();
        }
        // 상어 초기위치를 먹은 물고기 위치로 변경
        bfsQ.push(target);
    }

    cout << timeSum;

    return 0;
}