#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct coordinates
{
    int x = 0;
    int y = 0;
    int z = 0;
};

void new_coordinates(coordinates* coor, int x, int y, int z)
{
    coor->x = x;
    coor->y = y;
    coor->z = z;
}

int dis[101][101][101];
bool f = true;
bool visited[101][101][101];

void bfs(int x1, int x2, int y1, int y2, int z1, int z2)
{

    coordinates start;
    coordinates finish;
    new_coordinates(&start, x1, y1, z1);
    new_coordinates(&finish, x2, y2, z2);
    queue<coordinates> que;

    que.push(start);
    visited[x1][y1][z1] = true;
    dis[x1][y1][z1] = 0;

    while (!que.empty() && f)
    {
        coordinates from = que.front();
        que.pop();
        int cur_x = from.x;
        int cur_y = from.y;
        int cur_z = from.z;
        if (cur_x == x2 && cur_y == y2 && cur_z == z2)
        {
            f = false;
            break;
        }
        if (cur_x - 1 >= 0 && visited[cur_x - 1][cur_y][cur_z] == false)
        {
            visited[cur_x - 1][cur_y][cur_z] = true;
            coordinates to;
            new_coordinates(&to, cur_x - 1, cur_y, cur_z);
            que.push(to);
            dis[cur_x - 1][cur_y][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
        }
        if (cur_x + 1 < 101 && visited[cur_x + 1][cur_y][cur_z] == false)
        {
            visited[cur_x + 1][cur_y][cur_z] = true;
            coordinates to;
            new_coordinates(&to, cur_x + 1, cur_y, cur_z);
            que.push(to);
            dis[cur_x + 1][cur_y][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
        }
        if (cur_y - 1 >= 0 && visited[cur_x][cur_y - 1][cur_z] == false)
        {
            visited[cur_x][cur_y - 1][cur_z] = true;
            coordinates to;
            new_coordinates(&to, cur_x, cur_y - 1, cur_z);
            que.push(to);
            dis[cur_x][cur_y - 1][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
        }
        if (cur_y + 1 < 101 && visited[cur_x][cur_y + 1][cur_z] == false)
        {
            visited[cur_x][cur_y + 1][cur_z] = true;
            coordinates to;
            new_coordinates(&to, cur_x, cur_y + 1, cur_z);
            que.push(to);
            dis[cur_x][cur_y + 1][cur_z] = dis[cur_x][cur_y][cur_z] + 1;
        }
        if (cur_z - 1 >= 0 && visited[cur_x][cur_y][cur_z - 1] == false)
        {
            visited[cur_x][cur_y][cur_z - 1] = true;
            coordinates to;
            new_coordinates(&to, cur_x, cur_y, cur_z - 1);
            que.push(to);
            dis[cur_x][cur_y][cur_z - 1] = dis[cur_x][cur_y][cur_z] + 1;
        }
        if (cur_z + 1 < 101 && visited[cur_x][cur_y][cur_z + 1] == false)
        {
            visited[cur_x][cur_y][cur_z + 1] = true;
            coordinates to;
            new_coordinates(&to, cur_x, cur_y, cur_z + 1);
            que.push(to);
            dis[cur_x][cur_y][cur_z + 1] = dis[cur_x][cur_y][cur_z] + 1;
        }
    }

}

int main()
{
    int num, energy;
    cin >> num >> energy;
    int x1, y1, z1;
    int x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    for (int i = 0; i < num; i++)
    {
        int x, y, z, h;
        cin >> x >> y >> z >> h;
        for (int j = 0; j < h; j++)
        {
            visited[x][y][z + j] = true;
        }
    }
    bfs(x1, x2, y1, y2, z1, z2);

    if (f || energy < dis[x2][y2][z2])
    {
        cout << "-1";
    }
    else
    {
        cout << dis[x2][y2][z2];
    }
}