#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cassert>


std::string hotPotato(std::vector<std::string> players, int K){
    std::queue<std::string> q;

    for(std::string player : players){
        q.push(player);
    }

    while(q.size() > 1){
        for(int i = 0; i < K; ++i){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}
int main(){
    std::vector<std::string> players = {
        "Alice", "Bob", "Charlie", "David"
    };

    std::string winner = hotPotato(players, 7);
    std::cout <<winner<<'\n';
    assert(winner == "Charlie");

    std::vector<std::string> players2 = {"Anna"};
    assert(hotPotato(players2, 3) == "Anna");
    std::cout <<"All tests passed!" ;
    return 0;
}
