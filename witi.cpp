#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
int main ()
{
    clock_t start, stop; // do sprawdzenia czasu dzia�ania algorytmu
    float diff,t=0,totaltime; // j.w.
    int n,P[100],W[100],D[100];
    ifstream plik("dane/data.10.txt");
    plik >> n; for(int i=0;i<n;i++) plik >> P[i]>>W[i]>>D[i];
    plik.close();

    /*for(int i=0;i<n;i++)
        cout<<P[i]<<" "<<W[i]<<" "<<D[i]<<endl;*/

    for(int zz=0;zz<100;zz++){ // wielokrotnie wykonujemy ten sam algorytm dla zmierzenia czasu
        start = clock(); // pocz�tek dzia�ania algorytmu

        int N=1<<n, *F=new int[N]; F[0]=0;

        for(int i=1;i<N;i++)
        {
            int c=0;
            for(int k=0,b=1;k<n;k++,b*=2) if(i&b) c+=P[k];
            F[i]=9999999;
            for(int k=0,b=1;k<n;k++,b*=2) if(i&b){
                F[i] = min(F[i], F[i-b] + W[k]*max(c-D[k],0));
            }
        }

        stop = clock(); // koniec dzia�ania algorytmu
        diff = stop - start; // czas dzia�ania algorytmu (r�nica mi�dzy pocz�tkiem i ko�cem)
        t=t+diff;


    //    cout<<F[N-1]<<endl;
    }
    totaltime = ((float)t)/CLOCKS_PER_SEC; // przeliczenie liczby takt�w zegara na sekundy
    cout << "Czas dzialania algorytmu: " << totaltime << " sekund.\n";

 //   cin.get();
    return 0;
}
