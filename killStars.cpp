#include "stdafx.h"
#include "stdlib.h"
#include <math.h>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int welcome()
{
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*                                 *" << endl;
    cout << "*                                 *" << endl;
    cout << "*   消  *   灭  *   星  *   星    *" << endl;
    cout << "*                                 *" << endl;
    cout << "*                        V0.10    *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    system("pause");
    system("cls");
    return 0;
}

int information()
{
    cout << "目前已知的问题：" << endl;
    cout << "1.输入数字以外的字符会崩溃，并不打算解决这个问题" << endl;
    cout << "2.长宽大于10时会有显示bug" << endl;
    cout << endl << endl << "10*8是比较令人满意的规模" << endl;
    system("pause");
    system("cls");
    return 0;
}

int roll(int **mat, int h, int w,int r) //将某列移到最右
{
    int i, j, temp;
    for (i = r; i < w - 1; i++)
        for (j=0;j<h;j++)
        {
            temp = mat[j][i];
            mat[j][i] = mat[j][i + 1];
            mat[j][i + 1] = temp;
        }
    return 0;
}

int sort(int **mat,int h,int w) //整理数组
{
    int i, j, k, temp;
    for (i = 0; i < w; i++)
    {
        for (j=i;j<w-1;j++)
        {
            bool allzero = true;
            for (int k = 0; k < h; k++) if (mat[k][i] != 0) allzero = false;
            if (allzero and i < w - 1)  roll(mat, h, w, i);
        }
        int *p = new int[h];
        int temp = 0;
        for (j = 0; j < h /*- 1*/; j++)
            if (mat[j][i] != 0)
            {
                p[temp] = mat[j][i];
                temp++;
            }
        for (j = 0; j < temp; j++) mat[j][i] = p[j];
        for (j = temp; j < h; j++) mat[j][i] = 0;
        delete[]p;
    }
    return 0;
}

int cellkill(int **mat, int h, int w, int x, int y,int *sum,int killtarget) //杀死同类细胞并计算大小
{
    if (x - 1 >= 0) if (mat[y][x - 1] == killtarget) { mat[y][x - 1] = 0; ++*sum; cellkill(mat, h, w, x - 1, y, sum, killtarget); }
    if (x + 1 < w) if (mat[y][x + 1] == killtarget) { mat[y][x + 1] = 0; ++*sum; cellkill(mat, h, w, x + 1, y, sum, killtarget); }
    if (y - 1 >= 0) if (mat[y - 1][x] == killtarget) { mat[y - 1][x] = 0; ++*sum; cellkill(mat, h, w, x, y - 1, sum, killtarget); }
    if (y + 1 < h) if (mat[y + 1][x] == killtarget) { mat[y + 1][x] = 0; ++*sum; cellkill(mat, h, w, x, y + 1, sum, killtarget); }
}

int display(int **mat,int h,int w) //输出结果用
{
    for (int i = 0; i < h; i++)
    {
        cout << h - i - 1 << "  ";
        for (int j = 0; j < w; j++)
        {
            if (mat[h - i - 1][j] == 0)
                cout << " ";
            else
                cout << mat[h - i - 1][j];
        }
        cout << endl;
    }
    cout <<endl<< "   ";
    for (int i = 0; i < w; i++) cout << i;
    cout << endl;
    return 0;
}

bool alive(int **mat, int h, int w) //判断玩家是否存活
{
    for (int i = 0; i < h - 1; i++)
    {
        for (int j = 0; j < w - 1; j++)
        {
            if (mat[i][j] == mat[i + 1][j] and mat[i][j] != 0) return true;
            if (mat[i][j] == mat[i][j + 1] and mat[i][j] != 0) return true;
        }
        if (mat[i][w-1] == mat[i + 1][w-1] and mat[i][w-1] != 0) return true;
    }
    return false;
}

bool illegal(int **mat, int h, int w, int x, int y) //判断是否非法输入
{
    if (x < 0 or x >= w or y < 0 or y >= h) return true;
    if (mat[y][x] == 0) return true;
    if (x - 1 >= 0) if (mat[y][x] == mat[y][x - 1]) return false;
    if (x + 1 < w) if (mat[y][x + 1] == mat[y][x]) return false;
    if (y - 1 >= 0) if (mat[y - 1][x] == mat[y][x]) return false;
    if (y + 1 < h) if (mat[y + 1][x] == mat[y][x]) return false;
    return true;
}

int main()
{	
    welcome();
    information();
    srand((unsigned)time(NULL));
    int h, w, score = 0;
    cout << "请输入长和宽（中间以空格间隔）：";
    cin >> w >> h;
    system("cls");
    int **mat = new int *[h];
    for (int i = 0; i < h; i++) mat[i] = new int[w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            mat[i][j] = rand() % 4 + 1;
    //初始化完毕
    int x, y,killtarget;
    while (alive(mat,h,w))
    {
        system("cls");
        display(mat, h, w);
        int sum = 1;
        cout << "请输入x和y（中间以空格间隔）：";
        cin >> x >> y;
        if (illegal(mat, h, w, x, y)) continue;
        system("cls");
        killtarget = mat[y][x];
        mat[y][x] = 0;
        cellkill(mat, h, w, x, y, &sum, killtarget);
        score += pow(sum, 3);
        display(mat, h, w);
        system("pause");
        sort(mat, h, w);
    }
    //游戏结束
    system("cls");
    display(mat, h, w);
    delete[]mat;
    cout << endl << "Game Over"<<endl;
    cout << "Score:" << score << endl;
    system("pause");
    return 0;
}
