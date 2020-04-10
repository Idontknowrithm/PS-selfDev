#include<iostream>
#include<algorithm>
#include<vector>

int N, arr[1000050], sArr[1000050];
std::vector<int> sorted;

int bsearch(int n){
    int mid, start = 0, end = sorted.size() - 1;
    
    while(start <= end){
        mid = (start + end) / 2;
        if(sorted[mid] == n)
            return mid;
        else if(sorted[mid] < n)
            start = mid + 1;
        else 
            end = mid - 1;
    }
}
int main () {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        sArr[i] = arr[i];
    }
    
    std::sort(sArr, sArr + N);
    sorted.push_back(sArr[0]);
    for(int i = 1; i < N; ++i){
        if(sorted.back() != sArr[i])
            sorted.push_back(sArr[i]);
    }
    for(int i = 0; i < N; ++i)
        std::cout << bsearch(arr[i]) << " ";
    
    return 0;
}
