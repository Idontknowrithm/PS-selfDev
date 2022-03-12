#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

ll N, ans, arr[500005];

void DnQ(ll left, ll right){
    ll ptr1, ptr2, mid = (left + right) / 2;
    std::vector<ll> tmp;
    
    if(left == right)
        return;
    
    DnQ(left, mid);
    DnQ(mid + 1, right);

    ptr1 = left;
    ptr2 = mid + 1;

    while(ptr1 <= mid || ptr2 <= right){
        if(ptr1 > mid){
            while(ptr2 <= right)
                tmp.push_back(arr[ptr2++]);
        }
        else if(ptr2 > right){
            while(ptr1 <= mid)
                tmp.push_back(arr[ptr1++]);
        }
        else if(arr[ptr1] < arr[ptr2]){
            tmp.push_back(arr[ptr1++]);
        }
        else if(arr[ptr2] < arr[ptr1]){
            ans += ptr2 - left - (ll)tmp.size();
            tmp.push_back(arr[ptr2++]);
        }
        else if(arr[ptr1] == arr[ptr2])
            tmp.push_back(arr[ptr1++]);
    }
    for(ll i = left; i <= right; ++i)
        arr[i] = tmp[i - left];
}

int main() {
    scanf("%lld", &N);
    for(ll i = 0; i < N; ++i){
        scanf("%lld", &arr[i]);
    }
    DnQ(0, N - 1);

    printf("%lld", ans);
    return 0;
}
