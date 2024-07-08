#include<iostream>
#include<fstream>
#include<string>
 #include"Source.cpp"
using namespace std;
class image {
    int row;
    int col;
    int** array;
public:
    image() {
        row = 0;
        col = 0;
        array = new int* [row];
        for (int i = 0; i < row; i++) {
            array[row] = new int[col];
        }
    }
    void setPixel(int data, int r, int c) {
        if (r < row && c < col) {
            array[r][c] = data;
        }
    }
    int GetPixel(int r, int c) {
        if (r < row && c < col) {
            return array[r][c];
        }
        else {
            //cout << "out of bound !!!";
            return -1;
        }
    }
    void readFile(string name) {
        fstream f;
        string word;
        int count = 0;
        f.open(name, ios::in);
        while (!f.eof()) {
            f >> word;
            if (count == 6) {
                col = stoi(word);
            }
        }

    }
    int getSize() {
        int size = row * col;
        return size;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    void setRow(int r) {
        row = r;
    }
    void setCol(int c) {
        col = c;
    }
    void convretToNegative() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (array[i][j] == 255) {
                    array[i][j] = 0;
                }
                else {
                    array[i][j] = 255;
                }
            }

        }
        savefile();
    }
    void savefile() {
        fstream f;
        f.open("updatesfile.pgm", ios::out);
        f << "P2" << endl;
        f << row << " " << col;
        cout << endl;
        f << "255" << endl;
        for (int i = 0;i < col;i++) {
            for (int j = 0;j < row;j++) {
                f << array[i][j] << " ";
            }
            f << endl;
        }
        f.close();

    }
    ~image() {

        for (int i = 0; i < row; i++)
        {
            delete array[i];
        }

        delete array;
    }
    void HasingTable(int** array2, int r, int c, string name) {
        int* arrayR = new int[r];
        int* arrayC = new int[c];
        int k = 0;
        int* MergedArray = new int[r + c];
        for (int i = 0;i < r;i++) {
            int counter = 0;
            for (int j = 0;j < c;j++) {
                if (array2[i][j] == 255) {
                    counter++;
                }
                if (i < r)
                    arrayR[i] = counter;
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
                if (array2[j][i] == 255) {
                    counter2++;
                }
                if (i < c)
                    arrayC[i] = counter2;
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
            cout << endl;
            cout << endl;
            cout << sum;
            HashTable d1;
            //d1.Insert(sum, 1);
            //cout << endl;
            //  cout << count;
            //for (int i = 0;i < r;i++)
            //    cout << arrayR[i]<<" ";



        }
    }
    void RLCimg(int** array2, int r, int c) {
        list a1;

        fstream input;
        //string name = "RLCfile.txt";
        //bool flag = true;
        a1.add(r);
        a1.add(c);
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (array2[i][j] == 255) {
                    int x = j;
                    int x2 = j;
                    a1.add(x);
                    if (j < c - 1) {
                        while (array2[i][j + 1] == 255 && j < c - 1) {
                            j = j + 1;
                            x += 1;
                            if (j == c - 1) {
                                break;
                            }
                        }
                    }
                    if (x2 != x)
                        a1.add(x);
                }
            }
            //input.open(name, ios::out);
            //input << " -1 ";
            //input.close();
            a1.add(-1);

        }
    }
    void quickTree(int** array, int r, int c, node4* node) {
        node = newNode(1);
        cout << "Gray added " << endl;
        //root->left->left = newNode(4);
        int row, col;
        //node->setfisrt(node) = "G";
        int sum = ((r * c) / 4);
        row = col = sum;
        // Node head = ;
        int counter1 = 0;
        //first Quad
        for (int i = 0;i < r / 2; i++) {
            for (int j = 0;j < c / 2;j++) {
                if (array[i][j] == 255) {
                    counter1++;
                }
            }
        }
        int counter2 = 0;
        //sd Quad
        for (int i = 0;i < r / 2; i++) {
            for (int j = c / 2;j < c;j++) {
                if (array[i][j] == 255) {
                    counter2++;
                }
            }
        }
        int counter3 = 0;
        //3rd Quad
        for (int i = r / 2;i < r; i++) {
            for (int j = 0;j < c / 2;j++) {
                if (array[i][j] == 255) {
                    counter3++;
                }
            }
        }
        int counter4 = 0;
        //4th Quad
        for (int i = r / 2;i < r; i++) {
            for (int j = c / 2;j < c;j++) {
                if (i < r && j < c) {
                    if (array[i][j] == 255) {
                        counter4++;
                    }
                }
            }
        }
        //1st
        if (counter1 == r / 2 || counter1 == 0) {
            if (counter1 == r / 2) {
                node->first = newNode(2);// 1=g,2=b,3=w
                cout << "black added 1nd  ";
            }
            else {
                node->first = newNode(3);
                cout << "White added  1nd ";
            }
        }
        else {
            int** array1 = new int* [r / 2];
            for (int i = 0;i < r / 2;i++) {
                array1[i] = new int[c / 2];
            }
            for (int i = 0;i < r;i++) {
                for (int j = 0;j < c;j++) {
                    if (i < r / 2 && j < c / 2)
                    {
                        array1[i][j] = array[i][j];
                    }
                }
            }

            quickTree(array1, r / 2, c / 2, node->first);
        }
        //2nd
        if (counter2 == r / 2 || counter2 == 0) {
            if (counter1 == r / 2) {
                node->second = newNode(2);// 1=g,2=b,3=w
                cout << "black added in 2nd  ";
            }
            else {
                node->second = newNode(3);
                cout << "White added 2nd  ";
            }
        }
        else {
            int** array1 = new int* [r / 2];
            for (int i = 0;i < r / 2;i++) {
                array1[i] = new int[c / 2];
            }
            int x = 0;
            int y = 0;
            for (int i = 0;i < r / 2; i++) {
                for (int j = c / 2;j < c;j++) {
                    if (x < r / 2 && y < c / 2)
                    {
                        array1[x][y] = array[i][j];
                        y++;
                    }
                }
                x++;
            }
            quickTree(array1, r / 2, c / 2, node->second);
        }
        //third
        if (counter3 == r / 2 || counter3 == 0) {
            if (counter1 == r / 2) {
                node->third = newNode(2);// 1=g,2=b,3=w
                cout << "black added 3nd  ";
            }
            else {
                node->third = newNode(3);
                cout << "White added 3nd  ";
            }
        }
        else {
            int** array1 = new int* [r / 2];
            for (int i = 0;i < r / 2;i++) {
                array1[i] = new int[c / 2];
            }
            int x = 0;
            int y = 0;
            for (int i = r / 2;i < r; i++) {
                for (int j = 0;j < c / 2;j++) {
                    if (x < r / 2 && y < c / 2)
                    {
                        array1[x][y] = array[i][j];
                        y++;
                    }
                }
                x++;
            }
            quickTree(array, r / 2, c / 2, node->third);
        }
        //4th
        if (counter4 == r / 2 || counter4 == 0) {
            if (counter1 == r / 2) {
                node->fourth = newNode(2);// 1=g,2=b,3=w
                cout << "black added  4nd ";
            }
            else {
                node->fourth = newNode(3);
                cout << "White added  4nd ";
            }
        }
        else {
            int** array1 = new int* [r / 2];
            for (int i = 0;i < r / 2;i++) {
                array1[i] = new int[c / 2];
            }
            int x = 0;
            int y = 0;
            for (int i = r / 2;i < r; i++) {
                for (int j = c / 2;j < c;j++) {
                    if (x < r / 2 && y < c / 2)
                    {
                        array1[x][y] = array[i][j];
                        y++;
                    }
                }
                x++;
            }
            quickTree(array, r / 2, c / 2, node->fourth);
        }
        for (int i = 0; i < r; i++)
        {
            delete[] array[i];
        }
        delete[] array;

    }
};