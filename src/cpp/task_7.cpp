#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int minRabbits(vector<int>& answers) {
   unordered_map<int, int> countMap;
    for (int answer : answers) {
        countMap[answer]++;
    }
    int minRabbits = 0;
    for (const auto& entry : countMap) {
        int answer = entry.first;
        int count = entry.second;
        minRabbits += (count + answer - 1) / (answer + 1) * (answer + 1);
    }
    return minRabbits;
}
int task_7() {
    vector<int> answers = {1, 1, 2};
    int result = minRabbits(answers);
    cout << "Minimum number of rabbits: " << result <<endl;
    return 0;
}

