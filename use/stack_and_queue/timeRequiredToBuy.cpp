#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

int timeRequiredToBuy(std::vector<int> tickets, int k){
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < tickets.size(); ++i){
        q.push({i, tickets[i]});
    }
    int time = 0;

    while(!q.empty()){
        std::pair<int, int> person = q.front();
        q.pop();

        person.second--;
        time++;

        if(person.second > 0){
            q.push(person);
        }
        if(person.first == k && person.second == 0){
            return time;
        }
    }
    return time;
}
int main(){
    std::vector<int> tickets1 = {2, 3, 2};
    assert(timeRequiredToBuy(tickets1, 2) == 6);

    std::vector<int> tickets2 = {5, 1, 1, 1};
    assert(timeRequiredToBuy(tickets2, 0) == 8);

    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';
    std::cout << timeRequiredToBuy(tickets2, 0) << '\n';

    std::cout << "All tests passed!" << '\n';

    return 0;
}