#include <iostream>
#include <fstream>

using namespace std;

void beolvas(int t[], int &i)
{
    ifstream in ("be.in"); //-1 0 0 1 1 2 5 2 7 7 6 6 3 3 13 14    a FA

    while(!in.eof())
    {
        in >> t[i];
        i++;
    }
    i--;
}

void levelek(int APA[], int h, int frek[])
{
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(APA[j]==i) frek[i]++;
        }
    }
}

int kozosos(int APA[],int h, int csp1, int csp2)
{
    int seged=csp1;
    int fr[h]={0};

    while(seged!=-1)
    {
        fr[seged]++;
        seged=APA[seged];
    }
    seged=csp2;
    while(fr[seged]==0)
    {
        seged=APA[seged];
    }
    return seged;
}

void azonosszint(int APA[], int frek[], int gy, int h, int &hossz)
{
    for(int i=0; i<h; i++)
    {
        if(APA[i]==gy)
        {
            frek[i]=hossz;
            hossz++;
            azonosszint(APA,frek,i,h,hossz);
        }
    }
}

int magassag(int APA[], int h,int csp)
{
    int seged=csp;
    int hossz=0;

    while(seged!=-1)
    {
        seged=APA[seged];
        hossz++;
    }

    return hossz;
}

int main()
{
    int APA[100];
    int h=0;

    beolvas(APA,h);

    int frek[100]={0};
    levelek(APA,h,frek);

    cout << "levelek: ";
    for(int i=0; i<h; i++)
    {
        if(frek[i]==0) cout << i <<' ';
    }

    cout<<'\n'<<"kozosose ";
    int csp1,csp2;
    cin >> csp1 >>csp2;
    cout <<csp1 << " es " <<csp2<<"nek: ";
    cout <<kozosos(APA,h,csp1,csp2)<<'\n';


    int maxi=0;
    int a;
    for(int i=0; i<h; i++)
    {
        a=magassag(APA,h,i)-1;
        if(maxi<a) maxi=a;
    }
    cout << "magassag = "<<a;

    /*
    int frek2[100]={0};
    int hossz=0;
    azonosszint(APA,frek2,0,h,hossz);

    for(int i=0; i<=hossz; i++)
    {
        cout << i <<".szint: ";
        for(int j=0; j<h; j++)
        {
            if(APA[j]==i)
            cout << j <<' ';
        }
        cout <<'\n';
    }
*/


    return 0;
}
