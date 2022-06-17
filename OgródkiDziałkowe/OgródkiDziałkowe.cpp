#include <iostream>

using namespace std;

struct terytorium{
    int x1;
    int x2;
    int y1;
    int y2;
};

bool result=true;
bool czyBylo=false;

void merge(terytorium *tab,int  left, int mid, int right){
    int sizeLeftSide =  mid-left+1;
    int sizeRightSide = right-mid;
    terytorium leftTable[sizeLeftSide];
    terytorium rightTable[sizeRightSide];
    int i =0;
    int j =0;
    while(i<sizeLeftSide){
        leftTable[i]=tab[left+i];
        i++;
    }
    while(j<sizeRightSide){
        rightTable[j]=tab[mid+1+j];
        j++;
    }
    int a=0;//lewa
    int b=0;//prawa
    int tmp=left;
    if(czyBylo!=0){
    while(a<sizeLeftSide && b<sizeRightSide){
        if(leftTable[a].y1<=rightTable[b].y1){
            tab[tmp] = leftTable[a];
            ++a;
        }
        else{
            tab[tmp] = rightTable[b];
            ++b;
        }
        ++tmp;
    }
    }else{
        while(a<sizeLeftSide && b<sizeRightSide){
        if(leftTable[a].x1<=rightTable[b].x1){
            tab[tmp] = leftTable[a];
            ++a;
        }else{
            tab[tmp] = rightTable[b];
            ++b;
        }
        ++tmp;
        }
    }
    while(a<sizeLeftSide){
        tab[tmp] = leftTable[a];
        ++a;
        ++tmp;
    }
    while(b<sizeRightSide){
        tab[tmp] = rightTable[b];
        ++b;
        ++tmp;
    }
}

void  mergeSort(terytorium *tab,int left, int right){
    if(left>right-1){
        return;
    }
    int mid= (left+right-1)/2;
    mergeSort(tab,left,mid);
    mergeSort(tab,mid+1,right);
    merge(tab,left,mid,right);
}

bool solution(terytorium *tab, int n, int mid, int index){
    if(mid>n-1){
         return result;
    }
    if(czyBylo==false){
        mergeSort(tab,mid,n-1);
        int i = mid + 1;
        while (i < n) {
            if (tab[i].x1 >= tab[index].x2 ){
                result = true;
                break;
            } else if (tab[index].x2 > tab[i].x1 && tab[index].x2 < tab[i].x2) {
                result = false;
                index =i;
            }
            i++;
        }
        czyBylo = true;
        result = solution(tab,i,mid,mid);
        if(result == true){
            czyBylo = false;
            return solution(tab,n,i,i);
        }else{
            return result;
        }
    }
    else{
        czyBylo = true;
        mergeSort(tab, mid, n-1);
        int i  = mid +1;
        while(i < n) {
            if(tab[i].y1 >= tab[index].y2){
                result = true;
                czyBylo = false;
                result = solution(tab,i,mid,mid);
                if(result == true){
                    czyBylo = false;
                    return solution(tab,n,i,i);
                }else{
                    return result;
                }

            }else if (tab[i].y1 < tab[index].y2 && tab[i].y2 > tab[index].y2) {
                result = false;
                index =i;
            }
            i++;
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin>>t;
    int n;
    int i = 0;
    while (i < t) {
        cin>>n;
        terytorium tab[n];
        int j =0;
        while(j < n) {
            cin>>tab[j].x1>>tab[j].y1>>tab[j].x2>>tab[j].y2;
            j++;
        }

        result = solution(tab,n,0,0);
        if(result){
            cout<<"TAK"<<"\n";
        }else{
            cout<<"NIE"<<"\n";
        }
        i++;
        result=true;
        czyBylo=false;
    }

    return 0;
}