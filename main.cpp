#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("be.in");

void beolvas(int BAL[],int JOBB[], int &h)
{

    while(!in.eof())
    {
        in >> BAL[h];
        in >> JOBB[h];

        h++;
    }
    h--;

    in.close();
}

void preorder(int BAL[],int JOBB[], int gy)
{
    cout << gy <<' ';
    if(BAL[gy]!=-1) preorder(BAL,JOBB,BAL[gy]);
    if(JOBB[gy]!=-1) preorder(BAL,JOBB,JOBB[gy]);
}

void inorder(int BAL[],int JOBB[], int gy)
{
    if(BAL[gy]!=-1) inorder(BAL,JOBB,BAL[gy]);
    cout << gy <<' ';
    if(JOBB[gy]!=-1) inorder(BAL,JOBB,JOBB[gy]);
}

void postorder(int BAL[],int JOBB[], int gy)
{
    if(BAL[gy]!=-1) postorder(BAL,JOBB,BAL[gy]);
    if(JOBB[gy]!=-1) postorder(BAL,JOBB,JOBB[gy]);
    cout << gy <<' ';
}

void levelek(int BAL[], int JOBB[], int h, int level[100])
{
    for(int i=0; i<h; i++)
    {
        if(BAL[i]==-1 && JOBB[i]==-1)
        {
            level[i]=1;
        }
    }
}

int magassag(int BAL[],int JOBB[],int gy, int m, int maxi)
{
    if(BAL[gy]!=-1)
    {
        m++;

        magassag(BAL,JOBB,BAL[gy],m, maxi);
        if(maxi<m)
        {
            maxi=m;
        }
    }
    if(JOBB[gy]!=-1)
    {
        m++;

        magassag(BAL,JOBB,JOBB[gy],m, maxi);
        if(maxi<m)
        {
            maxi=m;
        }
    }

    return maxi;
}

int main()
{
    int BAL[100];
    int JOBB[100];

    int h=0;

    beolvas(BAL,JOBB,h);

    /*
    int level[100]={0};
    cout << "levelek: ";
    levelek(BAL,JOBB,h,level);
    for(int i=0; i<h; i++)
    {
        if(level[i]!=0) cout << i << ' ';
    }
    cout << '\n';
    */
    int gy=0;

    /*
    preorder(BAL,JOBB,gy);
    cout << '\n';
    inorder(BAL,JOBB,gy);
    cout << '\n';
    postorder(BAL,JOBB,gy);
    */

    //cout << "magassag: " << magassag(BAL,JOBB,0,0,0);

    return 0;
}
