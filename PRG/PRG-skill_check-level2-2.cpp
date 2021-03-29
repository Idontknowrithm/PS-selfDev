#include <string>
#include <vector>
#include<iostream>

typedef struct{
    int lan, where, career, food, points;
}volunteer;
// lan-> 1: cpp, 2: java, 3: python
// where-> 1: back, 2: front
// career-> 1: junior, 2: senior
// food-> 1: chicken, 2: pizza
int lan(char t){
    if(t == 'c')      return 1;
    else if(t == 'j') return 2;
    else if(t == 'p') return 3;
    else              return 0;
}
int where(char t){
    if(t == 'b') return 1;
    else if(t == 'f') return 2;
    else              return 0;
}
int career(char t){
    if(t == 'j') return 1;
    else if(t == 's') return 2;
    else              return 0;
}
int food(char t){
    if(t == 'c') return 1;
    else if(t == 'p') return 2;
    else              return 0;
}
bool possible(volunteer p, volunteer line){
    int can = 0;
    if(line.lan == 0 || line.lan == p.lan) can++;
    if(line.where == 0 || line.where == p.where) can++;
    if(line.career == 0 || line.career == p.career) can++;
    if(line.food == 0 || line.food == p.food) can++;
    if(line.points <= p.points) can++;
    return (can == 5) ? true : false;
}
std::vector<int> solution(std::vector<std::string> info, std::vector<std::string> query) {
    std::vector<volunteer> people;
    std::vector<int> answer;
    std::cout << "k";
    for(int i = 0; i < info.size(); ++i){
        volunteer tmp;
        int space;
        tmp.lan = lan(info[i][0]);
        space = info[i].find(" ", 0) + 1;
        tmp.where = where(info[i][space]);
        space = info[i].find(" ", space) + 1;
        tmp.career = career(info[i][space]);
        space = info[i].find(" ", space) + 1;
        tmp.food = food(info[i][space]);
        space = info[i].find(" ", space) + 1;
        tmp.points = stoi(info[i].substr(space));
        people.push_back(tmp);
    }
    for(int i = 0; i < query.size(); ++i){
        volunteer tmp;
        int space;
        tmp.lan = lan(info[i][0]);
        space = info[i].find(" and ", 0) + 5;
        tmp.where = where(info[i][space]);
        space = info[i].find(" and ", 0) + 5;
        tmp.career = career(info[i][space]);
        space = info[i].find(" and ", 0) + 5;
        tmp.food = food(info[i][space]);
        space = info[i].find(" ", space) + 1;
        tmp.points = stoi(info[i].substr(space));
        int can = 0;
        for(int u = 0; u < people.size(); ++u){
            if(possible(people[u], tmp)) ++can;
        }
        answer.push_back(can);
    }
    
    
    return answer;
}
