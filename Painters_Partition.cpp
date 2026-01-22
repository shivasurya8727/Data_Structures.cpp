#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> nums, int n, int m, int maxAllVal){
    int painter = 1, time = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > maxAllVal){
            return false;
        }
        if(time + nums[i] <= maxAllVal){
            time += nums[i];
        } else{
            painter++;
            time = nums[i];
        }
    }
    return painter <= m;
}

int painterPart(vector<int> nums, int n, int m){
    int sum = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    int st = 0, end = sum;
    while (st <= end){
        int mid = st + (end - st)/2;
        if(isValid(nums, n, m, mid)){
            ans = mid;
            end = mid - 1;
        } else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {40, 30, 10,  20};
    int n = 4, m = 2;

   cout << painterPart(nums, n, m);
}
