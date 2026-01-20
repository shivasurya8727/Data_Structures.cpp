#include <iostream>
#include <vector>
using namespace std;

 bool isValid(vector<int> &nums,int n,int m,int maxAllVal){
    int stu = 1, pages = 0;
   for(int i = 0; i < n; i++){
    if(nums[i] >  maxAllVal){
      return false;
    } 
    if(pages + nums[i] <= maxAllVal){
      pages += nums[i];
    } else{
      stu++;
      pages = nums[i];
    }
  }
  return stu <= m;
}

int allocateBooks(vector<int> &nums, int n, int m) {
  if(m > n){
    return -1;
  }

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += nums[i];
  }
  int st = 0, end = sum;
  int ans = -1;
  while(st <= end){
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
  vector<int> nums = {2,1,3,4};
  int n = 4 ,  m = 2;

  cout << allocateBooks(nums, n, m);
  return 0;
}
