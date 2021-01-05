#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
 
int main(int argc, const char * argv[])
{
    int n,m,s,d;
    int team[500];
    int way[500][500];
    int dis[500];
    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            way[i][j] = 0xfffffff;
        }
    }
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> team[i];
    }
    for(int i = 0; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> way[x][y];
    }
    for(int i = 0; i < n; i++)
    {
        dis[i] = way[0][i];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
        }
    }
    return 0;
}

