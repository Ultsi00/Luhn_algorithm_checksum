#ifndef CHECKSUM_H
#define CHECKSUM_H
#include <iostream>
#include <string>

using namespace std;

class Checker {
    public:
        const char* mStr;
        uint8_t mLen;
        short int *seq;
        uint16_t mSum;
        uint8_t mChecksum;

        Checker() {}
        //len and checksum print null
        // const char* was needed for \0
        // string is object which can use .length()
        // -> rethink if use only string
        // -> maybe create Checker object in program while loop after Selection object,
        //      using mInput as an argument in Checker(arg)
        inline void setString(const char* str) { mStr = str; }

        void processChecksum() {
            cout << "initial mStr: " << mStr << endl;
            countLen();
            cout << "len:" << mLen << endl;
            inputToIntArr();
            cout << "seq 1 2 3:" << seq[0] << seq[1] << seq[2] << endl;
            indexToMultiply();
            cout << "seq 1 2 3 after multiply:" << seq[0] << seq[1] << seq[2] << endl;
            toSum();
            cout << "mSum:" << mSum << endl;
            countAndPrintChecksum();
            //free *seq
        }

        inline void countLen() {
            mLen = 0;
            cout << "mStr0: " << mStr[0] << endl; //
            cout << "len:" << mLen << endl; //
            for (int i = 0; mStr[i] != '\0'; i++)
                mLen++;
        }
        inline void inputToIntArr() {
            seq = (short int *)malloc(sizeof(short int) * (mLen - 1));
            for (int i = 0; *mStr != '\0'; i++) { 
                seq[i] = *mStr - '0';
                mStr++;
            }
        }
        inline void indexToMultiply() {
            int toMultiply = (mLen - 2);
            while(toMultiply >= 0) {
                seq[toMultiply] *= 2;
                toMultiply -= 2;
            }
        }
        inline void toSum() {
            mSum = 0;
            for (int i = 0; i < mLen; i++) {
                if (seq[i] >= 10) {
                    mSum = mSum + (1 + (seq[i] % 10));
                }
                else
                    mSum = mSum + seq[i];
            }
        }
        inline void countAndPrintChecksum() {
            mChecksum = 10 - (mSum % 10);
            cout << "Checksum is: " << mChecksum << endl;
        }
};

class Selection {
    public:
        const char* mInput;
        string mInputTemp;

        Selection() : mInput("0") {}

        inline void instructions() {
            cout << "Choose an option: 1 or 2" << endl;
            cout << "(1.) Enter a number sequence\n\tOR\n" 
                    << "(2.) Premade sequences:" << endl;
            cout << "\t(a) 123456789\n\t(b) 59210\n\t(c) 7649278" << endl;
            cout << "['q' to quit]" << endl;
        }

        inline void menuStart() {
            char mSelection = 0;
            while(mSelection != 'q') {
                instructions();
                cin >> mSelection;
                if (mSelection != '1' && mSelection != '2' && mSelection != 'q')
                    cout << "\n\t*** False input ***\n" << endl;
                switch(mSelection) {
                    case('1'):
                        menuFree();
                        break;
                    case('2'):
                        menuPremade();
                        break;
                    default:
                        ;
                }
                if (mSelection == '1' || mSelection == '2')
                    break;        
            }
        }

        inline void menuPremade()  {
            char sel_premade = 0;
            while (sel_premade != 'a' && sel_premade != 'b' 
                    && sel_premade != 'c' && sel_premade != 'q')
            {
                cout << "Select a premade sequence: [a/b/c]" << endl;
                cout << "\t(a) 123456789\n\t(b) 59210\n\t(c) 7649278" << endl;
                cin >> sel_premade;
                if (sel_premade != 'a' && sel_premade != 'b' && sel_premade != 'c')
                    cout << "\n\t*** False input ***\n" << endl;
                switch(sel_premade) {
                    case('a'):
                        mInput = "123456789";
                        break;
                    case('b'):
                        mInput = "59210";
                        break;
                    case('c'):
                        mInput = "7649278";
                        break;
                    default:
                        ;
                }
            }
        }

        inline void menuFree() {
            while (mInputTemp.length() < 1) {
                cin >> mInputTemp;
                mInput = mInputTemp.c_str();
                cout << mInput << endl;
            }
        }
};

#endif





/* Algo C style
        //sequence
    const char* b = "123456789";
    
        //len
    int len = 0;
    for (int i = 0; b[i] != '\0'; i++) {
        len++;
    }

        //char[] to int[]
    int seq[len - 1];
    for (int i = 0; *b != '\0'; i++) {
        seq[i] = *b - '0';
        b++;
    }

    // multiply
    int toMultiply = (len - 2);
    while(toMultiply >= 0) {
        seq[toMultiply] *= 2;
        toMultiply -= 2;
    }

    //sum
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (seq[i] >= 10) {
            sum = sum + (1 + (seq[i] % 10));
        }
        else
            sum = sum + seq[i];
    }

    //checksum
    int checksum = 0;
    checksum = 10 - (sum % 10);
    cout << checksum << endl;
    
*/
