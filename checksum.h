#ifndef CHECKSUM_H
#define CHECKSUM_H
#include <iostream>
#include <string>

using namespace std;

/*
    Calculates checksum from a number sequence (void processChecksum()).
*/
class Checker {
    public:
        const char* mStr;
        short int *seq;
        uint8_t mLen;
        uint16_t mSum;
        uint8_t mChecksum;
        Checker() {}
        ~Checker() { cout << "Checker destructor utilized\n"; }

        inline void setString(const char* str) { mStr = str; }

        void processChecksum() {
            countLen();
            inputToIntArr();
            indexToMultiply();
            toSum();
            countAndPrintChecksum();
            delete seq;
        }
        inline void countLen() {
            mLen = 0;
            for (int i = 0; mStr[i] != '\0'; i++)
                mLen++;  
        }
        inline void inputToIntArr() {
            seq = new short int[mLen];
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
            //Unary '+' operator (in uint8_t mChecksum) promotes the primitive datatype to int,
            // resulting in a printable numerical value, not ASCII
            cout << "Checksum is: " << +mChecksum << endl;
        }
};

/*
    User menu and number sequence input.
*/
class Selection {
    public:
        const char* mInput;
        string mInputTemp;

        Selection() : mInput("0") {}
        ~Selection() { cout << "Selection destructor utilized\n"; }

        inline void printInstructions() {
            cout << "\nChoose an option: 1 or 2 ['q' to quit]" << endl;
            cout << "(1.) Enter a number sequence\n\tOR\n" 
                    << "(2.) Choose a premade sequence" << endl;
        }

        inline short int menuStart() {
            char mSelection = '0';
            while(mSelection != 'q') {
                printInstructions();
                cout << "Selection: ";
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
                    case('q'):
                        return 0;
                    default:
                        ;
                }
                if (mSelection == '1' || mSelection == '2')
                    break;        
            }
            return 1;
        }

        inline void menuPremade()  {
            char sel_premade = '0';
            while (sel_premade != 'a' && sel_premade != 'b' && sel_premade != 'c') {
                cout << "\nChoose a premade sequence: [a/b/c]" << endl;
                cout << "\t(a) 123456789\n\t(b) 59210\n\t(c) 7649278" << endl;
                cout << "Selection: ";
                cin >> sel_premade;
                if (sel_premade != 'a' && sel_premade != 'b' && sel_premade != 'c')
                    cout << "\n***** Error: False input *****\n" << endl;
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
            bool error;
            while (true) {
                error = false;
                cout << "\nInsert number sequence: ";
                cin >> mInputTemp;
                for (int i = 0; i < mInputTemp.size(); i++) {
                    if (isdigit(mInputTemp[i]) != true)
                        error = true;
                }
                if (error == true)
                    cout << "\n***** Error: False input *****\n" << endl; 
                else {
                    mInput = mInputTemp.c_str();
                    break;
                }
            }
        }
};

#endif
