#include <iostream>

using namespace std;

short minCost = 10001;
short cost = 0;
short estetyka = 0;

struct opis {
    short s;
    short c;
};

void solution(opis *tab,int n,int start) {
            //cout<<cost<<" "<<estetyka<<endl;
            if(start<n){
            estetyka += tab[start].s;
            cost += tab[start].c;
            if (estetyka == 0 && minCost > cost) {
                    minCost = cost;
            }
            else if (minCost > cost) {
                solution(tab, n, start + 1);
            }
            estetyka -= tab[start].s;
            cost -= tab[start].c;
            
            solution(tab, n, start + 1);
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    short t;
    cin >> t;
    short n;
    for (short i = 0; i < t; ++i) {
        cin >> n;
        opis tab[n];
        for (short j = 0; j < n; j++) {
            cin>>tab[j].s>>tab[j].c;
        }
        solution(tab, n, 0);
        if (minCost != 10001) {
            cout << minCost << "\n";
        }
        else {
            cout << "NIE" << "\n";
        }
        minCost = 10001;
    }

    return 0;
}