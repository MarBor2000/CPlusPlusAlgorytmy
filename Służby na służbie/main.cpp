#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void showResults(const vector<pair<int,int>>& kids,int n,int c){
    if(c==0){
        for (int i=0;i<n;++i) {
            cout<<kids[i].first<<" ";
        }
    }else if(c==1) {
        for (int i=0;i<n;++i) {
            cout<<kids[i].second<<" ";
        }
    }

}

//countingSort

void countingSort(vector<pair<int, int>>& kids,int n,int p,int k,int c){
    int range=k-p+1;
    vector<int> counts(range, 0);

    for (int i=0;i<n;++i) {
        ++counts[kids[i].second-p];
    }

    int j = 0;
    for (int i = 0;i<range;++i) {
        while (counts[i]-->0) {
            kids[j++].second=i+p;
        }
    }

    showResults(kids,n,c);
}


//introsort

void swap(pair<int,int>& kids,pair<int,int>& arr){
    pair<int,int> tmp=kids;
    kids=arr;
    arr=tmp;
}

void insertionSort(vector<pair<int,int>>& kids,int p,int r){
    for(int i=p+1;i<=r;++i) {

        pair<int,int> key=kids[i];
        int j=i-1;

        while(j>=p && kids[j].second>key.second){
            kids[j+1]=kids[j];
            --j;
        }
        kids[j+1] = key;
    }
}

int partition(vector<pair<int,int>>& kids,int p,int r){
    pair<int,int> pivot=kids[(p+r)/2];
    int i=p-1;
    int j=r+1;

    while(true){
        do{
            ++i;
        }while(kids[i].second<pivot.second);

        do{
            --j;
        }while(kids[j].second>pivot.second);

        if(i>=j){
            return j;
        }

        swap(kids[i],kids[j]);
    }
}

void heapify(vector<pair<int,int>>& kids,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && kids[left].second>kids[largest].second){
        largest=left;
    }

    if (right<n && kids[right].second>kids[largest].second){
        largest=right;
    }

    if (largest!=i) {
        swap(kids[i],kids[largest]);
        heapify(kids,n,largest);
    }
}

void heapsort(vector<pair<int,int>>& arr,int n) {
    for (int i=n/2-1;i>=0;--i){
        heapify(arr,n,i);
    }

    for(int i=n - 1;i>0;--i){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void introsort(vector<pair<int, int>>& kids, int p, int r, int maxDepth,int n,int c) {
    if (r-p>16){
        if(maxDepth==0){
            heapsort(kids,r-p+1);
            return;
        }

        --maxDepth;

        int q=partition(kids,p,r);
        introsort(kids,p, q,maxDepth,n,c);
        introsort(kids, q+1,r,maxDepth,n,c);
    }else{
        insertionSort(kids,p,r);
    }

    showResults(kids,n,c);

}


//timosort

void merge(vector<pair<int, int>>& kids,int left,int mid,int right,int c){
    int len1=mid-left+1;
    int len2=right-mid;

    vector<pair<int,int>> leftKids(len1);
    vector<pair<int,int>> rightKids(len2);


    for (int i=0;i<len1;++i)
        leftKids[i]=kids[left+i];
    for (int j=0;j<len2;++j)
        rightKids[j]=kids[mid+1+j];

    int i=0;
    int j=0;
    int k=left;

    while (i<len1 && j<len2){
        if ((c == 0 && leftKids[i].second<=rightKids[j].second) || (c==1 && leftKids[i].first<=rightKids[j].first)) {
            kids[k]=leftKids[i];
            ++i;
        } else {
            kids[k]=rightKids[j];
            ++j;
        }
        ++k;
    }

    while (i<len1){
        kids[k]=leftKids[i];
        ++i;
        ++k;
    }

    while (j<len2){
        kids[k]=rightKids[j];
        ++j;
        ++k;
    }
}

void timSort(vector<pair<int,int>>& kids,int n,int c){
    const int RUN = 32;
    for (int i=0;i<n;i+=RUN){
        insertionSort(kids,i,min((i+RUN-1),(n-1)));
    }

    for (int size=RUN;size<n;size=2*size){
        for (int left=0;left+size<n;left+=2*size){
            int mid=left+size-1;
            int right=min((left+2*size-1),(n-1));
            merge(kids,left,mid,right,c);
        }
    }

    showResults(kids,n,c);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,p,k,c;
    cin>>n>>p>>k>>c;

    vector<pair<int, int>> preschoolers;
    preschoolers.reserve(n);

    int nr,points;
    for (int i=0;i<n;++i) {
        cin>>nr>>points;
        preschoolers.emplace_back(nr, points);
    }

    if(c==1){
        countingSort(preschoolers,n,p,k,c);
    }else if(n<10000){
        introsort(preschoolers,0,n-1,2 * log2(n),n,c);
    }else{
        timSort(preschoolers,n,c);
    }

    return 0;
}