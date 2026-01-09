#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
    double sum=0,mean,harmean=0,geo=1,geomean,std=0,stdv,max=A[0],min=A[0];
    for(int i=0;i<N;i++){
        
        sum += A[i];
        mean = sum/N;
        harmean += 1/(A[i]);
        geo *= A[i];
        geomean = pow(geo,pow(N,-1));
        if(A[i]>max) max = A[i];
        if(A[i]<min) min = A[i];
        std += pow(A[i],2);
        stdv = sqrt((std/N)-pow(mean,2));
    }
    B[0] = mean;
    B[1] = stdv;
    B[2] = geomean;
    B[3] = N/harmean;
    B[4] = max;
    B[5] = min;
}
