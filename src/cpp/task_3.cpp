#include <iostream>
#include <vector>
using namespace std;
enum State {
    q0, q1, q2, q3, q4, q5, q6, HALT
};

void compareNumbers(vector<char>& tape) {
    State currentState = q0;
    int head = 0;
    while (currentState != HALT) {
        switch (currentState) {
            case q0:
                while (head < tape.size() && tape[head] != 'c') {
                    head++;
                }
                currentState = q1;
                break;
            case q1:
                while (head < tape.size() && tape[head] != '0') {
                    head++;
                }
                currentState = q2;
                break;

            case q2:
                while (head < tape.size() && tape[head] != '1') {
                    head++;
                }
                currentState = q3;
                break;
            case q3:
                while (head < tape.size() && tape[head] != '0') {
                    head++;
                }
                currentState = q4;
                break;

            case q4:
                if (head < tape.size() && tape[head] == '1') {
                    currentState = HALT;
                    cout << "11" << endl;
                } else if (head < tape.size() && tape[head] == '0') {
                    currentState = HALT;
                    cout << "1" << endl;
                } else {
                    currentState = q5;
                }
                break;
            case q5:
                while (head < tape.size() && tape[head] != 'c') {
                    head++;
                }
                currentState = q6;
                break;

            case q6:
                while (head < tape.size()) {
                    head++;
                }
                cout << "11" << endl;
                currentState = HALT;
                break;
        }
    }
}
int task_3 () {
    vector<char> tape = {'0', '1', '1', '1', 'c', '1', '1', '1', '1', '0'};
    compareNumbers(tape);
    return 0;
}
