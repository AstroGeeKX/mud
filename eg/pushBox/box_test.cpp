#include <iostream>
#include <vector>

using namespace std;

// 游戏地图大小
const int WIDTH = 4;
const int HEIGHT = 4;

// 地图元素
enum Tile {
    EMPTY,  // 空地
    WALL,   // 墙壁
    BOX,    // 箱子
    GOAL    // 目标点
};

// 游戏地图
vector<vector<Tile>> map = {
    {WALL, WALL, WALL, WALL},
    {WALL, BOX, GOAL, WALL},
    {WALL, EMPTY, EMPTY, WALL},
    {WALL, WALL, WALL, WALL}
};

// 玩家位置
int playerX = 1;
int playerY = 2;

// 输出地图
void printMap() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x == playerX && y == playerY)
                cout << 'P';  // 玩家
            else {
                switch (map[y][x]) {
                    case EMPTY: cout << ' '; break;
                    case WALL: cout << '#'; break;
                    case BOX: cout << 'B'; break;
                    case GOAL: cout << 'G'; break;
                }
            }
        }
        cout << endl;
    }
}

// 移动玩家
void movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    // 检查新位置是否合法
    if (map[newY][newX] == WALL) return;  // 碰到墙壁，无法移动

    // 检查是否有箱子
    if (map[newY][newX] == BOX) {
        int boxNewX = newX + dx;
        int boxNewY = newY + dy;

        // 检查箱子新位置是否合法
        if (map[boxNewY][boxNewX] == EMPTY || map[boxNewY][boxNewX] == GOAL) {
            // 移动箱子
            map[boxNewY][boxNewX] = BOX;
            map[newY][newX] = EMPTY;
        } else {
            return;  // 箱子无法移动
        }
    }

    // 移动玩家
    playerX = newX;
    playerY = newY;
}

int main() {
    while (true) {
        printMap();

        // 处理用户输入
        char input;
        cin >> input;

        switch (input) {
            case 'w': movePlayer(0, -1); break;  // 上
            case 's': movePlayer(0, 1); break;   // 下
            case 'a': movePlayer(-1, 0); break;  // 左
            case 'd': movePlayer(1, 0); break;   // 右
            case 'q': return 0;  // 退出游戏
        }
    }
    return 0;
}