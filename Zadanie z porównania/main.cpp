#include <iostream>

using namespace std;

template<typename T>
class Wektor{
private:
size_t currentSize;
size_t capacity;
T* arr;
public:

Wektor(): currentSize(0), capacity(10){
    arr=new T[capacity];
}


void push_back(T& n){
    if(capacity==currentSize){
        capacity*=2;
        T* newArray = new T[capacity];
        for(int i = 0;i < currentSize; i++){
            newArray[i] = arr[i];
        }
        delete[] arr;
        arr=newArray;
    }

    arr[currentSize++] = n;
}

    T* begin(){
        return arr;
    }


    T* end(){
        return arr+currentSize;
    }
};




int main(){

    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;

    int number1,number2;

    Wektor<int> list1;
    Wektor<int> list2;

    for(int i = 0;i < n; i++){
        cin>>number1;
        list1.push_back(number1);
    }

    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>number2;
        list2.push_back(number2);
    }

    
    bool find;

    for(auto i=list2.begin();i<list2.end();i++){
        find = false;
        for(auto j=list1.begin();j<list1.end();j++){
            if(*i==*j){
                find =true;
                break;
            }
        }

        if(find){
            cout<<"T"<<" ";
        }else{
            cout<<"N"<<" ";
        }


    }


    return 0;
}