#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    int k, m;
    cin >> n >> k >> m;
    char tab[n][k];
    char tabTMP[n][k];
    for (int i = 0; i < n; ++i) {
        for(int j =0;j<k;++j){
            cin>>tab[i][j];
        }
    }

    for (int l = k - 1; l >= 0; --l) {
        int oTMP = 0;
        int xTMP = 0;
        for (int i = 0; i < n; ++i) {
            if (tab[i][l] == 'o') {
                oTMP++;
            }
            else {
                xTMP++;
            }
        }
        int sum = oTMP + xTMP;
        for (int i = n - 1; i >= 0; --i) {
            if (tab[i][l] == 'o') {
                oTMP--;
                for(int j=0;j<k;j++){
                    tabTMP[oTMP][j] = tab[i][j];
                }
            }
            else {
                sum--;
                for(int j=0;j<k;j++){
                    tabTMP[sum][j] = tab[i][j];
                }
            }

        }

        for (int i = 0; i < n; ++i) {
            for(int j =0;j<k;j++){
                tab[i][j]=tabTMP[i][j];
            }
        }
    }
    for (int i = n - 1; i >= n - m; --i) {
            for(int j =0;j<k;j++){
                cout << tab[i][j];
            }
            cout<<"\n";
    }
}