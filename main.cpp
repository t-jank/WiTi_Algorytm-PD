#include <iostream>
#include <fstream>

using namespace std;
int main ()
{
    int n,P[100],W[100],D[100];
    ifstream plik("data.txt");
    plik >> n; for(int i=0;i<n;i++) plik >> P[i]>>W[i]>>D[i];
    plik.close();

    for(int i=0;i<n;i++)
        cout<<P[i]<<" "<<W[i]<<" "<<D[i]<<endl;

    int N=1<<n, *F=new int(N); F[0]=0;

    for(int i=1;i<N;i++)
    {
        int c=0;
        for(int k=0,b=1;k<n;k++,b*=2) if(i&b) c+=P[k];
        F[i]=9999999;
        for(int k=0,b=1;k<n;k++,b*=2) if(i&b)
        {
            F[i] = min(F[i], F[i-b] + W[k]*max(c-D[k],0));
        }
    }
    cout<<F[N-1]<<endl;

    cin.get();
    return 0;
}
