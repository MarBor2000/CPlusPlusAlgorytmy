#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int tab[1][m];
    int tabTMP[1][m];
    int maxi=0;
    int indeks=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tabTMP[0][j];
            if(i>0){
                if(m==1){
                    tabTMP[0][j]+=tab[0][j];
                }else if(m==2||j==0){
                    if(tab[0][0]>tab[0][1]){
                        tabTMP[0][j]+=tab[0][0];
                    }else{
                        tabTMP[0][j]+=tab[0][1];
                    }
                }else if(j==m-1){
                    if(tab[0][j-1]>tab[0][j]){
                        tabTMP[0][j]+=tab[0][j-1];
                    }else{
                        tabTMP[0][j]+=tab[0][j];
                    }
                }else{
                    if(tab[0][j-1]>=tab[0][j]&&tab[0][j-1]>=tab[0][j+1]){
                        tabTMP[0][j]+=tab[0][j-1];
                    }else if(tab[0][j]>tab[0][j-1]&&tab[0][j]>=tab[0][j+1]){
                        tabTMP[0][j]+=tab[0][j];
                    }else{
                        tabTMP[0][j]+=tab[0][j+1];
                    }
                }
            }
        }

        for(int j =0;j<m;j++){
            tab[0][j]=tabTMP[0][j];
        }
    }

    for(int i = 0;i<m;i++){
        if(maxi<tab[0][i]){
            maxi=tab[0][i];
            indeks = i;
        }
    }
    cout<<indeks<<" "<<maxi;
}