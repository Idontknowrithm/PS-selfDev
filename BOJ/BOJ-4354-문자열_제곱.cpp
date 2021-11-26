// 실패 함수를 바꾸니 100퍼에서 틀리던 것을 맞췄다. 따라서 실패함수에
// 대해서 분석해볼 필요가 있다.
// KMP의 실패함수는 접두사와 접미사가 같은 가장 길이가 긴 문자열의 길이를
// 저장한다. 예를 들면 ababcab의 실패함수 배열은 0012012가 되겠다.
// 실수할 수 있는 부분은 aaaa의 실패함수 배열은 0123이다(0234는 아니다).
// 실패함수를 구하는 방법은 두 포인터 front, back을 이용해서 두 포인터가
// 가리키는 문자가 같으면 실패함수 배열을 ++ 시키고 두 포인터를 1씩 앞으로
// 이동시키고, 문자가 다르다면 front 포인터는 0 idx로 가고 back 포인터는
// 1 만큼 앞으로 이동시킨다. 이 알고리즘을 그대로 코드로 옮긴 것이 첫 번째
// 실패함수이다. 하나씩 뜯어보자.

// 첫 실패함수
// void failure(){
// //  front와 back 포인터를 잡는다
//     int front = 0, back = 1;
    
// //  i가 back 포인터가 될 것이다
//     for(int i = 1; i < input.size(); ++i){
// //      front와 back 포인터가 가리키는 문자가 같으면
// //      back 포인터가 가리키는 곳의 pi 배열에 전 배열 + 1을
// //      저장하고, 두 포인터 모두 앞으로 1씩 이동시킨다
//         if(input[front] == input[back]){
//             pi[back] = pi[back - 1] + 1;
//             ++front; ++back;
//         }
// //      다르다면 back이 가리키는 pi 배열에 0을 넣고,
// //      front를 처음으로 이동시킨다
//         else{
//             pi[back++] = 0;
//             front = 0;
//         }
//     }
// }
// 두 번째 실패함수
// void failure(){
// //  여기서는 front, back이 아닌 begin, matched를 이용한다
// //  matched가 front가 되고, matched는 접두사와 접미사가 같은
// //  길이를 나타내므로 back이 begin + matched라고 볼 수 있다
//     int begin = 1, matched = 0;
// //  back이 문자열의 범위를 벗어나지 않을 때까지
//     while(begin + matched < input.size()){
// //      back과 front가 가리키는 문자가 같다면?
//         if(input[begin + matched] == input[matched]){
// //          일치하는 접두 접미의 길이 += 1
//             ++matched;
// //          언뜻 보면 back - 1이지만 matched를 미리
// //          ++ 해줬기 때문에 back에 matched를 넣는 것과
// //          동일하다
//             pi[begin + matched - 1] = matched;
//         }
// //      다를 때
//         else{
// //          일치한 접사가 없을 때는 begin만 ++ 해준다
//             if(!matched)
//                 ++begin;
//             else{
//                 begin += matched - pi[matched - 1];
//                 matched = pi[matched - 1];
//             }
//         }
//     }
// }

// 결론: 실패함수에서 front와 back이 맞지 않을 때 front가 무조건 0이 되는 것이 아니다
// abaabab -> 0011232 틀렸다고 0이 되는 것이 아니고, 그때 접미가와 접두사가 얼마나
// 일치하는 지 재계산을 해야했다

#include<iostream>
#include<cstring>

int pi[1000005];
std::string input;

void failure(){
    int begin = 1, matched = 0;

    while(begin + matched < input.size()){
        if(input[begin + matched] == input[matched]){
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(!matched)
                ++begin;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
int main() {
    while(1){
        memset(pi, 0, sizeof(pi));
        std::cin >> input;
        if(input[0] == '.' && input.size() == 1)
            break;
        failure();
        if(pi[input.size() - 1] % (input.size() - pi[input.size() - 1]))
            std::cout << "1\n";
        else{
            int ans = input.size() / (input.size() - pi[input.size() - 1]);
            std::cout << ans << "\n";
        }   
    }
    return 0;
}
