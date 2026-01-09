#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool I[][M]){
    for(int i=0;i<32;i++){
        for(int j=0;j<72;j++){
            if(i==0 || i==31){
                cout << "-";
            }else if (j==0 || j==71){
                    cout << "|";
            }else if (I[i-1][j-1]){
                cout << "*";
                
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void updateImage(bool A[][M],int n,int p,int q){
     for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            if((sqrt((pow(i-p,2)+pow(j-q,2))))<=n-1){
                if(i<N&&j<M){
                    A[i][j]=true; 
                }
                   
            }
        }
    }
}