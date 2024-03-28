#include <iostream>

using namespace std;


template<typename T>
class Wektor{
    private:
    T* arr;
    size_t capacity;
    size_t cSize;
    
    public:
    Wektor():capacity(10), cSize(0){
        arr=new T[capacity];
    }
    
    ~Wektor(){
        delete[] arr;
    }
    
    size_t size(){
        return cSize;
    }
    
    void push_back(T& x){
        if(cSize==capacity){
            capacity*=2;
            T* newArr = new T[capacity];
            for(size_t i=0;i<cSize;++i){
                newArr[i]=arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[cSize++] = x;
    }
    
    T* begin(){
        return arr;
    }
    
    T* end(){
        return arr+cSize;
    }
};



void showResult(Wektor<unsigned int>& n){
   for(auto i=n.end()-2;i>=n.begin();--i){
        cout<<*i<<" ";
   } 
}


int main()
{
    ios_base::sync_with_stdio(false);
    
    unsigned int n;
    Wektor<unsigned int> wektor;
    while(true){
        cin>>n;
        wektor.push_back(n);
        if(n==0){
            break;
        }
    }
    showResult(wektor);

    return 0;
}