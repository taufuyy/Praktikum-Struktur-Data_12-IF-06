    //Taufik Hafit Zakaria
    //103112430093_12 - IF 06
    // File: main.cpp

    #include <iostream>
    #include "stack.h"
    #include "stack.cpp"
    using namespace std;

    int main() {
        // ========== LATIHAN 1 ==========
        cout << "===== LATIHAN 1 =====" << endl;
        cout << "Hello world!" << endl;

        Stack S1;
        createStack(S1);

        push(S1, 3);
        push(S1, 4);
        push(S1, 8);
        pop(S1);
        push(S1, 2);
        push(S1, 3);
        pop(S1);
        push(S1, 9);

        printInfo(S1);
        cout << "balik stack" << endl;
        balikStack(S1);
        printInfo(S1);

        // ========== LATIHAN 2 ==========
        cout << "\n===== LATIHAN 2 =====" << endl;
        cout << "Hello world!" << endl;

        Stack S2;
        createStack(S2);

        pushAscending(S2, 3);
        pushAscending(S2, 4);
        pushAscending(S2, 8);
        pushAscending(S2, 2);
        pushAscending(S2, 3);
        pushAscending(S2, 9);

        printInfo(S2);
        cout << "balik stack" << endl;
        balikStack(S2);
        printInfo(S2);

        // ========== LATIHAN 3 ==========
        cout << "\n===== LATIHAN 3 =====" << endl;
        cout << "Hello world!" << endl;

        Stack S3;
        createStack(S3);

        getInputStream(S3);
        printInfo(S3);
        cout << "balik stack" << endl;
        balikStack(S3);
        printInfo(S3);

        return 0;
    }
