// 벡터를 인자로 넘기는 과정에서 타임아웃
// 일반 배열로 바꾸고 포인터 인자로 넘기는 방법으로 해결

#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int element, nested;
} data;

bool compare(data a, data b){
    return a.element < b.element;
}
int find(int ans, int start, int end, data* table){
    while(start <= end){
        int mid = (start + end) / 2;
        if(ans == table[mid].element && table[mid].nested != -1)
            return table[mid].nested;
        else if(ans > table[mid].element)
            start = mid + 1;
        else if(ans < table[mid].element)
            end = mid - 1;
        else if(ans == table[mid].element){
            end = mid - 1;
        }
    }
    return 0;
}

int main () {
    data* table, temp;
    int N, M, input, nest, nestId, size = 0, index = 1;
    scanf("%d", &N);
    table = new data[N];
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        temp.element = input;
        temp.nested = 1;
        table[size++] = temp;
    }
    std::sort(table, table + N, compare);
    nest = table[0].element;
    nestId = 0;
    while(index != size){
        if(table[index].element == nest){
            table[index].nested = -1;
            ++table[nestId].nested;
            ++index;
        }
        else{
            nest = table[index].element;
            nestId = index;
            ++index;
        }
    }

    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        scanf("%d", &input);
        printf("%d ", find(input, 0, N - 1, table));
    }
    return 0;
}
