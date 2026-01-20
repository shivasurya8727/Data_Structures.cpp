#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPoss(vector<int> &arr, int n, int c, int minVal){
    int cows = 1, stall = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - stall >= minVal){
            cows ++;
            stall = arr[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}

int getDist(vector<int> &arr, int n, int c){
    sort(arr.begin() , arr.end());
    int st = 1, end = arr[n-1] - arr[0], ans = -1;
    while(st <= end){
        int mid = st + (end - st)/2;

    if(isPoss(arr, n, c, mid)){
        ans = mid;
        st = mid + 1;
    } else{
        end = mid - 1;
    }
    
    }
    return ans;

}

int main(){
    vector<int> arr = {1,2,8,4,9};
    int n = 5, c = 3;
    cout << getDist(arr, n, c);

    return 0;
}
