#include "checksum.h"

/*
    reverse order
    multiply every second from right side
    sum digits, e.g. 14 = 1 + 4 = 5 / 4 = 4
    sum all
    checksum: 10  - (sum mod 10)
*/

void program_loop() {
    Checker checker = Checker();
    Selection selection = Selection();
   
    //while()
    selection.menuStart();
    checker.setString(selection.mInput);
    checker.processChecksum();

}

int main() {

    program_loop();

    return 0;
}
