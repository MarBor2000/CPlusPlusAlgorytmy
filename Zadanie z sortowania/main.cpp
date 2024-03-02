#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<string>& arr,int n,int m){
    string key;
    int j=0;
    for(int i = 1;i<n;i++){

    key = arr[i];
    j=i-1;

        while(j>=0 && key[m]<arr[j][m]){

            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

/*void bubbleSort(vector<string>& arr,int n,int m){

    bool changed = false;
    string tmp;
    for(int i = 0;i<n;i++){

        for(int j = 0;j<n-1;j++){
            if(arr[j][m]>arr[j+1][m]){
                changed=true;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }

        if(!changed){
            break;
        }
    }

}*/

int main(){

    ios_base::sync_with_stdio(false);

    string napis;
    int n;
    cin>>n;
    vector<string> arr;
    cin.ignore();
    for(int i = 0;i<n;i++)
    {
        getline(cin,napis);
        arr.push_back(napis);
    }

    int m;
    cin>>m;
    vector<int> arrM;
    int number;
    for(int i = 0;i<m;i++){
        cin>>number;
        arrM.push_back(number);
    }
    

    for(int i = 0;i<m;i++){
        insertionSort(arr,n,arrM[i]);
    }


    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}