//

#include<iostream>
#include<vector>
#include<algorithm>

typedef struct{
    int element, nested;
} data;

bool compare(data a, data b){
    return a.element < b.element;
}
int find(int ans, int start, int end, std::vector<data> table){
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
    std::vector<data> table;
    int N, M, input, nest, nestId, index = 1;
    data temp;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &input);
        temp.element = input;
        temp.nested = 1;
        table.push_back(temp);
    }
    std::sort(table.begin(), table.end(), compare);
    nest = table[0].element;
    nestId = 0;
    while(index != table.size()){
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
        printf("%d ", find(input, 0, table.size() - 1, table));
    }
    return 0;
}
