#include <iostream>
#include <vector>
using namspace std;
enum State {
    q0, q1, q2, q3, HALT
};
void unaryAddition(vector<int>& tape) {
    State currentState = q0;
    int head = 0;
    while (currentState != HALT) {
        switch (currentState) {
            case q0:
                while (head < tape.size() && tape[head] != 0) {
                    head++;
                }
                currentState = q1;
                break;

            case q1:
                while (head < tape.size() && tape[head] == 0) {
                    tape[head] = 1;
                    head--;
                    while (head >= 0 && tape[head] != 0) {
                        head--;
                    }
                    head++;
                }
                currentState = (head < tape.size() && tape[head] == 0) ? q1 : q2;
                break;
            case q2:
                tape[head] = 1;
                head++;
                currentState = q3;
                break;
            case q3:
                while (head < tape.size() && tape[head] != 0) {
                    head++;
                }
                currentState = (head < tape.size()) ? q1 : HALT;
                break;
        }
    }
}
int task_2 () {
    vector<int> tape = {1, 1, 1, 0, 1, 1, 1, 1};
    unaryAddition(tape);
    cout << "Result: ";
    for (int bit : tape) {
        cout << bit << " ";
    }
    cout << endl;
    return 0;
}
