#include <iostream>
#include <string>
#include <cstring>
#include<fstream>
#include<ctime>
//#include"image.cpp"
using namespace std;

class HashData {
public:
    int val;
    int v;
    HashData(int k, int v) {
        this->val = k;
        this->v = v;
    }
};
class HashTable {
private:
    HashData** HashArr;
public:
    HashTable() {
        HashArr = new HashData * [23];
        for (int i = 0; i < 23; i++) {
            HashArr[i] = NULL;
        }
    }
    int HashFunc(int val) {
        return val % 354;  //my trade mark........
    }
    void Hashreadfile(string name, int num, int chice) {
        fstream  f;
        string w;
        int count = 0;
        int r = 0;
        int c = 0;
        f.open(name, ios::in);
        if (f.is_open()) {
            while (!f.eof())
            {
                //cout << w << endl;
                //for (int i = 0;i < 8;i++ ) {
                f >> w;
                if (count == 5) {
                    r = stoi(w);
                }
                else if (count == 6) {
                    c = stoi(w);
                }
                else if (count == 5) {
                    r = stoi(w);
                }
                else if (count == 7) {
                    break;
                }
                count = count + 1;
            }

        }
        f.close();
        //
        int** array22 = new int* [r];
        for (int i = 0; i < r; i++) {
            array22[i] = new int[c];
        }



        int size = r * c;
        int* array2 = new int[r * c];
        char c2;
        f.open(name, ios::in);//skip 4liness
        for (int i = 0; i <= 4; i++) {
            getline(f, w);
        }
        int i = 0;
        while (!f.eof()) {
            f >> c2;
            //for(int i = 0; i < row;i++){
                //for (int j = 0;i < coll;i++) {
                    //f >>c ;
            if (c2 == 'ÿ') {
                if (i < size) {
                    array2[i] = 255;
                }
            }
            else if (c2 != 'ÿ') {
                if (i < size) {
                    array2[i] = 0;
                }
            }
            i++;
            //else}
        }
        f.close();
        /////////////////////////////

        int c1 = 0;
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (c1 < (r * c)) {
                    array22[i][j] = array2[c1];
                    c1++;
                }
            }
        }
        int k = 0;
        int* MergedArray = new int[r + c];
        for (int i = 0;i < r;i++) {
            int counter = 0;
            for (int j = 0;j < c;j++) {
                if (array22[i][j] == 255) {
                    counter++;
                }
                if (i < r)
                    //arrayR[i] = counter;
                    MergedArray[i] = counter;

            }
            k++;
        }
        //for (int i = 0;i < r + c;i++) {
        //    cout << MergedArray[i] << " ";
        //   count++;
        //}
        //cout << k << endl;
        for (int j = 0;j < c;j++) {
            int counter2 = 0;
            for (int i = 0;i < r;i++) {
                if (array22[j][i] == 255) {
                    counter2++;
                }
                if (i < c)
                    MergedArray[k] = counter2;
                k++;
            }
        }
        k = r + c;
        for (int i = 0;i < r + c;i++) {
            cout << MergedArray[i] << " ";

            int j = 0;
            int sum = 0;
            while (j < k) {
                if (sizeof(MergedArray) % 4 != 0) {
                    if ((sizeof(MergedArray) + 1) % 4 == 0) {
                        sum += (MergedArray[j] * 1000) + (MergedArray[j + 1] * 100) + (MergedArray[j + 1 + 1] * 10) + 0;
                    }
                    if (sizeof(MergedArray) + 2 % 4 == 0) {
                        sum += (MergedArray[j] * 1000) + (MergedArray[j + 1] * 100) + 0;
                    }
                    if ((sizeof(MergedArray) + 3) % 4 == 0) {
                        sum += (MergedArray[j] * 1000) + 0;
                    }
                }
                else {
                    if (j + 3 < k) {
                        sum += (MergedArray[j] * 1000) + (MergedArray[j + 1] * 100) + (MergedArray[j + 1 + 1] * 10) + (MergedArray[j + 1 + 1] * 1);
                    }
                }
                //cout << sum << "   ";
                j += 4;
            }
            //   cout << endl;
            //   cout << endl;
            //   cout << sum;
            fstream input;
            input.open("Hashing", ios::out);
            input << sum << " " << name << endl;
            input.close();
            //HashTable d1;
            if (chice == 1) {
                Insert(sum, num);
            }
            else
            {
                SearchKey(sum);
            }
        }
        for (int i = 0; i < r; i++)
        {
            delete[] array22[i];
        }
        delete[] array22;
        delete[] array2;
    }
    void Insert(int k, int v) {
        int h = HashFunc(k);
        while (HashArr[h] != NULL && HashArr[h]->val != k) {
            h = HashFunc(h + 1);
        }
        if (HashArr[h] != NULL)
            delete HashArr[h];
        HashArr[h] = new HashData(k, v);
    }


    int SearchKey(int val) {
        int h = HashFunc(val);
        while (HashArr[h] != NULL && HashArr[h]->val != val) {
            h = HashFunc(h + 1);
        }
        if (HashArr[h] == NULL)
            return -1;
        else
            return HashArr[h]->v;
    }


    ~HashTable() {
        for (int i = 0; i < 500; i++) {
            if (HashArr[i] != NULL)
                delete HashArr[i];
            delete[] HashArr;
        }
    }
};