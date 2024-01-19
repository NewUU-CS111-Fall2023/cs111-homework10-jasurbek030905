#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Clause {
    char variable;
    bool isNegated;
};
struct CNFFormula {
    vector<vector<Clause>> clauses;
};
bool isSatisfied(const CNFFormula& formula, const unordered_map<char, bool>& assignment) {
    for (const auto& clauseGroup : formula.clauses) {
        bool clauseSatisfied = false;
        for (const auto& clause : clauseGroup) {
            char variable = clause.variable;
            bool isNegated = clause.isNegated;
            if (assignment.find(variable) != assignment.end()) {
                bool variableValue = assignment.at(variable);
                if (isNegated) {
                    variableValue = !variableValue;
                }
                clauseSatisfied = clauseSatisfied || variableValue;
            } else {
                clauseSatisfied = clauseSatisfied || (isNegated ? true : false);
            }


        }

    
        if (!clauseSatisfied) {
            return false;
        }
    }
    return true;
}

int task_9 () {
    CNFFormula formula = {{{{'A', false}, {'B', true}}, {{'A', true}, {'B', false}, {'C', true}}}};
    unordered_map<char, bool> assignment = {{'A', true}, {'B', false}, {'C', true}};
    bool satisfied = isSatisfied(formula, assignment);
    if (satisfied) {
        cout << "Satisfied" << endl;
    } else {
        cout << "Not Satisfied" << endl;
    }

    return 0;
}
