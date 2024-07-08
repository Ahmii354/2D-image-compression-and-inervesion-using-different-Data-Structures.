#include <iostream>
#include <string>
#include <cstring>
#include<fstream>
#include<ctime>
//#include"image.cpp"
#include"Source1.cpp"
using namespace std;
template <class T>
class nodee {
public:
    T data;
    nodee<T>* next;
};
template <class T>
class stack {
private:
    nodee<T>* top;
public:
    stack(){
        top = NULL;
    }
    
    void push(const T& data) {
        if (top == NULL) {
            top = new nodee<T>;
            top->next = nullptr;
            top->data = data;
        }
        else {
            nodee<T>* temp = new nodee<T>;
            temp->data = data;
            top->next = temp;
            top = temp;
        }
    }
    void pop() {
        if (top == NULL) {
            return ;
        }
        else {
            nodee<T>* temp = top;
            //cout << top->data << " is popped" << endl;
            top = top->next;
            //return temp;
            delete temp;
        }
    }
    bool isEmpty() {
        if (top == NULL)
            return false;
        else
            return true;
    }
    T Top() {
        if (top != NULL) {
            return top->data;
        }
        else
            return -1;

    }
};
template<typename T> class Node {
private:
    T data;
    Node<T>* next;
    template<typename U>
    friend class Queue;
};

template <class T>
class Queue {
    class Node
    { public:
        T data;
        Node* next;
    };
    Node* Head = NULL;
public:
    Node* front;
    Queue(){

        front = NULL;
    }
    void enqueue(T da){
        Node* last = new Node;
        last->next = NULL;
        last->data = da;
        Node* temp = front;
        if (temp != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = last;
        }
        else
            front = last;
    }
    T dequeue(){
        Node* temp = NULL;
        temp = front;
        front = front->next;
        return temp->data;
        delete temp;

    }
    bool empty(){
        if (front == NULL){
            return true;
        }
        return false;
    }
};
class Node3 {
public:
    char data;
    Node3* fst;
    Node3* snd;
    Node3* trd;
    Node3* frt;
};
class QuadTress {
public:
    char data;
    Node3* fst;
    Node3* snd;
    Node3* trd;
    Node3* frt;

    QuadTress() {
        data = NULL;
        fst = NULL;
        snd = NULL;
        trd = NULL;
        frt = NULL;
    }
    QuadTress* Insert(QuadTress* node,char key){
        if (node == NULL){
            node = new QuadTress;
            node->data = key;
            node->fst = NULL;
            node->snd = NULL;
            node->trd = NULL;
            node->frt = NULL;
        }
    }
    char getfisrt(QuadTress* c) {
        return c->fst->data;
    }
    char getsecond(QuadTress* c) {
        return c->snd->data;
    }
    char getthird(QuadTress* c) {
        return c->trd->data;
    }
    char getfourt(QuadTress* c) {
        return c->frt->data;
    }
    void setdata(QuadTress* c, char key) {
        c->data = key;
    }
    void setfisrt(QuadTress* c, char key) {
        c->fst->data = key;
    }
    void setsecond(QuadTress* c, char key) {
        c->snd->data = key;
    }
    void setthird(QuadTress* c, char key) {
        c->trd->data = key;
    }
    void setfourt(QuadTress* c, char key) {
         c->frt->data=key;
    }
    ~QuadTress() {

    }

};
class node4 {
 public:
  int data=0;
  node4 *first;
  node4 *second;
  node4 *third;
  node4 *fourth;

};

// New node creation
node4 *newNode(int da) {
   node4 *node = ( node4 *)malloc(sizeof(node4));

  node->data = da;

  node->first = NULL;
  node->second = NULL;
  node->fourth = NULL;
  node->third = NULL;
  return (node);
}

class Node2 {
public:
    int data;
    Node2* next;
    Node2* prev;
    Node2() {
        data = 0;
        next = nullptr;
        prev=NULL;
    }
    Node2(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = NULL;
    }
    void setData(int d) {
        this->data = d;
    }
    int getData() {
        return data;
    }
    void setNext(Node2* next) {
        this->next = next;
    }

    Node2* getNext()
    {
        return this->next;
    }
};
void Add_ind(Node2** head, int new_data) {
    Node2* newNode = new Node2;
    newNode->data = new_data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}
void ADD_AFTER(Node2* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "Error";
        return;
    }
    Node2* newNode = new Node2;
    newNode->data = new_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}
void ADD_end(Node2** head, int new_data) {
    Node2* newNode = new Node2;
    Node2* last = *head;
    newNode->data = new_data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return;
}

void displayList(Node2* node) {
    Node2* last;
    while (node != NULL) {
        cout << node->data << "<>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "Node is NULL";
}

class list {
    Node2* head;
    Node2* current;
    Node2* lastcurrent;

public:
    list()
    {
        head = nullptr;
        current = nullptr;
        lastcurrent = nullptr;
    }
    void add(int data) {
        Node2* newNode = new Node2(data);

        if (current != nullptr) {
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            lastcurrent = current;
            current = newNode;
        }
        else {
            newNode->setNext(nullptr);
            head = newNode;
            lastcurrent = head;
            current = head;
        }
    }
    void writeintofile() {
        fstream input;
        input.open("RlcData.txt", ios::out);
        input << head->getData();
        head = head->getNext();
        input << " ";
        input << head->getData();
        input << endl;
        head = head->getNext();
        while (head->getNext()!=NULL)
        { 
            if (head->getData() == -1) {
                input << head->getData();
                input << endl;
            }
            else {
                input << head->getData();
                input << " ";

            }
            head = head->getNext();
        }
        input.close();
    }
    void Readintofile() {
        int count = 0;
        fstream f;
        int w;
        int row = 0;
        int coll = 0;
        
        f.open("RlcData.txt", ios::in);
        if (f.is_open()) {
            while (!f.eof())
            {
                f >> w;
                if (count == 1) {
                    row = w;
                }
                else if (count == 2) {
                    coll = w;
                }
                else if (count >= 3) {
                    break;
                }
                count = count + 1;
            }

        }
        else
        {
            cout << "file not found";
        }
        int** array22 = new int* [row];
        for (int i = 0; i < row; i++) {
            array22[i] = new int[coll];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < coll; j++) {
                array22[i][j] = 0;
            }
        }

        f.close();
        int i = 0;
        int j = 0;
        f.open("RlcData.txt", ios::in);
         count = 0;
        if (f.is_open()) {
            while (!f.eof())
            {
                f >> w;
                count++;
                if (count > 2) {
                    if (w == -1) {
                        i += 1;
                        //array22[i][j] = w;
                    }
                    else {
                        array22[i][w] = 255;
                    }

                }
                j++;
                

            }
        }
    }

    void displayList() {
        Node2* temp = head;

        while (temp != nullptr) {

            cout << "|" << temp->getData() << "|";
            temp = temp->getNext();
            if (temp != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }
    void ConvertTonegative() {
        int count = 0;
        fstream f;
        int w;
        int row = 0;
        int coll = 0;

        f.open("RlcData.txt", ios::in);
        if (f.is_open()) {
            while (!f.eof())
            {
                f >> w;
                if (count == 1) {
                    row = w;
                }
                else if (count == 2) {
                    coll = w;
                }
                else if (count >= 3) {
                    break;
                }
                count = count + 1;
            }

        }
        else
        {
            cout << "file not found";
        }
        int** array22 = new int* [row];
        for (int i = 0; i < row; i++) {
            array22[i] = new int[coll];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < coll; j++) {
                array22[i][j] = 0;
            }
        }

        f.close();
        int i = 0;
        int j = 0;
        f.open("RlcData.txt", ios::in);
        count = 0;
        if (f.is_open()) {
            while (!f.eof())
            {
                f >> w;
                count++;
                if (count > 2) {
                    if (w == -1) {
                        i += 1;
                        //array22[i][j] = w;
                    }
                    else {
                        array22[i][w] = 0;
                    }

                }
                j++;


            }
        }
    }

    void addAtFirstLocation(int data) {
        Node2* newNode = new Node2(data);
        newNode->setNext(head);
        head = newNode;
    }

};


//
//  Q2......................................toooooooooo goooooooooooooooooooooo buddddddddddddyyyyyyyyyyy!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//


bool check(int** arr, int row, int coll, int r, int c) {

           if (arr[r][c] == 0) {
                return 0;
            }
            else {
                return 1;
            }
}

void connectedPixel(int arr[], int row, int coll, int rr, int cc) {
    Queue< int> a1;//class C;
    Queue< int> b1;//class C;
    a1.enqueue(rr);
    b1.enqueue(cc);
    //2d
    int** array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[coll];
    }
    int** temparray = new int* [row];
    for (int i = 0; i < row; i++) {
        temparray[i] = new int[coll];
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            temparray[i][j] = 255;
            // c1++;
        }
    }
    int c1 = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            array[i][j] = arr[c1];
            c1++;
        }
    }
    cout << row;
    cout << endl;
    cout << coll;

    int count = 0;
    while (!(a1.empty())){
        int r = a1.dequeue();
        int c = b1.dequeue();
        if (temparray[r][c] == 255) {
            temparray[r][c] = 0;
           if (array[r][c] == array[r][c + 1]) {//front
                a1.enqueue(r);
                b1.enqueue(c + 1);
                
            }
            if (c - 1 >= 0) {
                if (array[r][c] == array[r][c - 1]) {//back
                    a1.enqueue(r);
                    b1.enqueue(c - 1);
                }
            }
            if (r + 1 < row && c < coll) {
                if (array[r][c] == array[r + 1][c]) {//lower
                    a1.enqueue(r + 1);
                    b1.enqueue(c);
                }
            }
            if (r - 1 >= 0) {
                if (array[r][c] == array[r - 1][c]) {//uper
                    a1.enqueue(r - 1);
                    b1.enqueue(c);
                }
            }
            if (r - 1 >= 0) {
                if (array[r][c] == array[r - 1][c + 1]) {//upper front 
                    a1.enqueue(r - 1);
                    b1.enqueue(c + 1);
                }
            }
            if (r - 1 >= 0 && c - 1 >= 0) {
                if (array[r][c] == array[r - 1][c - 1]) {//upper back
                    a1.enqueue(r - 1);
                    b1.enqueue(c - 1);
                }
            }
            if (c - 1>=0 && r+1 <row  ) {
                if (array[r][c] == array[r + 1][c - 1]) {//lower back
                    a1.enqueue(r + 1);
                    b1.enqueue(c - 1);
                }
            }
            if (c+1 < coll && r+1 < row) {
                if (array[r][c] == array[r + 1][c + 1]) {//lowe front
                    a1.enqueue(r + 1);
                    b1.enqueue(c + 1);
                }
            }
        }
        else {
        }
    }
    fstream f;
    f.open("updatesfile.pgm", ios::out);
    f << "P2" << endl;
    f << row << " " << coll;
    cout << endl;
    f << "255" << endl;
    for (int i = 0;i < coll;i++) {
        for (int j = 0;j < row;j++) {
            f << temparray[i][j] << " ";
        }
        f << endl;
    }
    f.close();
    cout << "File is saved as 'updatedfile.pgm' Now please convert it back to GIF " << endl;
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    for (int i = 0; i < row; i++)
    {
        delete[] temparray[i];
    }
    delete[] temparray;
}

void mean(int arr[],int row,int coll) {
    
    int** array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[coll];
    }
    float totalVal = 0;
    int pixelVal = 0;
    //check marny k leya BIG O ma chala jata ha
    int c1 = 0;
    int backpixel = 0;
    float avgblack = 0;
    float avgtotal = 0;
    int whitepixel = 0;
    int rowtotal = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            array[i][j] = arr[c1];
            totalVal++;
            pixelVal += arr[c1];
            if (arr[c1] == 255)
                whitepixel = whitepixel + 1;
            else
                backpixel += 1;

            //if (array[i][j] = 0)
             //   avgblack += 1;
            //cout << array[i][j] << "";
            ///cout << endl;
            c1++;
        }
        //cout << "avgrage black pixel in Row: " << i << " is : " <<float(avgblack / totalVal);
        //cout << avgblack << "  ";
    }

    cout << totalVal << endl;
    cout << pixelVal << endl;
    cout << "Mean value of pixel is :" << pixelVal / totalVal << " " << endl;
    cout << backpixel << endl;
    cout << whitepixel << endl;
    cout<<"Avg. number of Black pixel in each row is: "<< backpixel/row << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < coll; j++) {
            if (array[i][j] == 255) {
                    array[i][j] = 0;
            }
            else {
                 array[i][j] = 255;
            }
        }

    }
    fstream f;
    f.open("updatesfile.pgm", ios::out);
     f << "P2" << endl;
    f << row << " " << coll;
    cout << endl;
    f << "255" << endl;
    for (int i = 0;i < coll;i++) {
        for (int j = 0;j < row;j++) {
            f << array[i][j] << " ";
        }
        f << endl;
    }
    f.close();
    cout << "File is saved as 'updatedfile.pgm' Now please convert it back to GIF " << endl;
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

void checkstack(int arr[], int row, int coll, int rr, int cc) {
    stack< int> a1;//class C;
    stack< int> b1;//class C;
    a1.push(rr);
    b1.push(cc);
    int** array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[coll];
    }
    int** temparray = new int* [row];
    for (int i = 0; i < row; i++) {
        temparray[i] = new int[coll];
    }
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            temparray[i][j] = 255;
            // c1++;
        }
    }
    int c1 = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            array[i][j] = arr[c1];
            c1++;
        }
    }
    while (!(a1.isEmpty())) {
        int c = b1.Top();
        b1.pop();
        int r = a1.Top();
        a1.pop();
        if (temparray[r][c] == 255) {
            temparray[r][c] = 0;
            if (array[r][c] == array[r][c + 1]) {//front
                b1.push(c + 1);
                a1.push(r);
            }
            if (c - 1 >= 0) {
                if (array[r][c] == array[r][c - 1]) {//back
                    b1.push(c - 1);
                    a1.push(r);
                }
            }
            if (r + 1 < row && c < coll) {
                if (array[r][c] == array[r + 1][c]) {//lower
                    a1.push(r + 1);
                    b1.push(c);
                }
            }
            if (r - 1 >= 0) {
                if (array[r][c] == array[r - 1][c]) {//uper
                    a1.push(r - 1);
                    b1.push(c);
                }
            }
            if (r - 1 >= 0) {
                if (array[r][c] == array[r - 1][c + 1]) {//upper front 
                    a1.push(r - 1);
                    b1.push(c + 1);
                }
            }
            if (r - 1 >= 0 && c - 1 >= 0) {
                if (array[r][c] == array[r - 1][c - 1]) {//upper back
                    a1.push(r - 1);
                    b1.push(c - 1);
                }
            }
            if (c - 1 >= 0 && r + 1 < row) {
                if (array[r][c] == array[r + 1][c - 1]) {//lower back
                    a1.push(r + 1);
                    b1.push(c - 1);
                }
            }
            if (c + 1 < coll && r + 1 < row) {
                if (array[r][c] == array[r + 1][c + 1]) {//lowe front
                    a1.push(r + 1);
                    b1.push(c + 1);
                }
            }
        }
        else {
        }
    }
        fstream f;
        f.open("updatesfile.pgm", ios::out);
        f << "P2" << endl;
        f << row << " " << coll;
        cout << endl;
        f << "255" << endl;
        for (int i = 0;i < coll;i++) {
            for (int j = 0;j < row;j++) {
                f << temparray[i][j] << " ";
            }
            f << endl;
        }
        f.close();
        cout << "File is saved as 'updatedfile.pgm' Now please convert it back to GIF " << endl;
    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    for (int i = 0; i < row; i++)
    {
        delete[] temparray[i];
    }
    delete[] temparray;
}

////
////............................................-------Q5------.........................................
////
void quickTree(int** array, int r, int c,node4* node) {
    node = newNode(1);
    cout << "Gray added "<<endl;
    //root->left->left = newNode(4);
    int row, col;
    //node->setfisrt(node) = "G";
    int sum = ((r * c) / 4 );
    row = col = sum;
   // Node head = ;
    int counter1=0;
    //first Quad
    for (int i = 0;i < r/2; i++) {
        for (int j = 0;j < c/2;j++) {
            if (array[i][j] == 255) {
                counter1++;
            }
        }
    }
    int counter2=0;
    //sd Quad
    for (int i = 0;i < r/2; i++) {
        for (int j = c/2;j < c;j++) {
            if (array[i][j] == 255) {
                counter2++;
            }
        }
    }
    int counter3=0;
    //3rd Quad
    for (int i = r/2;i < r; i++) {
        for (int j = 0;j < c/2;j++) {
            if (array[i][j] == 255) {
                counter3++;
            }
        }
    }
    int counter4 = 0;
    //4th Quad
    for (int i = r/2;i < r ; i++) {
        for (int j = c/2;j < c ;j++) {
            if(i<r && j<c){
                if (array[i][j] == 255) {
                    counter4++;
                }
            }
        }
    }
    //1st
    if (counter1 == r / 2 || counter1==0 ) {
        if (counter1 == r / 2){
            node->first = newNode(2);// 1=g,2=b,3=w
            cout << "black added 1nd  ";
        }
        else {
            node->first = newNode(3);
            cout << "White added  1nd ";
        }
    }
    else {
        int** array1 = new int* [r/2];
        for (int i = 0;i < r/2;i++) {
            array1[i] = new int[c/2];
        }
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                if (i < r / 2 && j < c / 2)
                {
                    array1[i][j] = array[i][j];
                }
            }
        }

        quickTree(array1, r/2, c/2, node->first);
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
    else{
        int** array1 = new int* [r / 2];
        for (int i = 0;i < r / 2;i++) {
            array1[i] = new int[c / 2];
        }
        int x = 0;
        int y = 0;
        for (int i = 0;i < r / 2; i++) {
            for (int j = c / 2;j < c;j++) {
                if (x < r / 2 && y<c/2)
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
            cout << "black added 3nd  " ;
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
//....................................---------Q4---------...............................................
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
                if(x2!=x)
                a1.add(x);
            }
        }
        a1.add(-1);
    }
    
    a1.writeintofile();
    cout << "File has been formed...."<<endl;
    int a=0;
    cout << "if you want to read the file......Press 1";
    cin >> a;
    if (a == 1) {
        a1.Readintofile();
    }
    else {
        //exit;
    }
}
///
/////................................------------Q6------------.......................................
///
void HasingTable(string name) {
    int chice = 0;
    cout << "-------------------------------------------------" << endl;
    cout << " 1: press 1 to read files nad inserting " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " 2 : press 2 to search " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " 3: press 3 to Exit " << endl;
    cout << "-------------------------------------------------" << endl;
    cin >> chice;
    HashTable r1;
    fstream input;

    if (chice == 1) {
        int count = 0;
        for (int i = 0;i <= 4;i++) {
            for (int j = 0;j <= 9;j++) {
                for (int k = 0;k <= 9;k++) {
                    count++;
                    string filename = "image" + to_string(i) + to_string(j) + to_string(k);
                    r1.Hashreadfile(filename, count,chice);
                }
            }
        }
    }
    else if (chice == 2) {
        string file;
        cout << "Enter the name of file";
        cin >> file;
        input.open(name, ios::out);
        input << "  User Enter the filename " << file<< " To run sub part of Q6 ";
        input.close();
        r1.Hashreadfile(file, 0, chice);
    }
    else if (chice == 3) {
        //exit ;
    }


}
void readWord(string name, int choice) {
    cout << "2 ";
    fstream  f;
    string w;
    int count = 0;
    int row = 0;
    int coll = 0;

    //char array[8];
    f.open(name, ios::in);
    if (f.is_open()) {
        cout << "3 ";
        while (!f.eof())
        {
            //cout << w << endl;
            //for (int i = 0;i < 8;i++ ) {
            f >> w;
            if (count == 5) {
                row = stoi(w);
            }
            else if (count == 6) {
                coll = stoi(w);
            }
            else if (count == 5) {
                row = stoi(w);
            }
            else if (count == 7) {
                break;
            }
            count = count + 1;
        }

    }
    else
    {
        cout << "file not found";
    }

    f.close();


    int** array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[coll];
    }



    int size = row * coll;
    int* array2 = new int[row * coll];
    char c;
    //if (myfile.is_open())
    //{
        //string myArray[5];
    f.open(name, ios::in);//skip 4liness
    for (int i = 0; i <= 4; i++)
    {
        getline(f, w);

    }
    //} 
    int i = 0;
    while (!f.eof()) {
        f >> c;
        //for(int i = 0; i < row;i++){
            //for (int j = 0;i < coll;i++) {
                //f >>c ;
        if (c == 'ÿ') {
            if (i < size) {
                array2[i] = 255;
            }
        }
        else if (c != 'ÿ') {
            if (i < size) {
                array2[i] = 0;
            }
        }
        i++;
        //else}
    }
    f.close();
    int** array22 = new int* [row];
    for (int i = 0; i < row; i++) {
        array22[i] = new int[coll];
    }
    int c1 = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < coll;j++) {
            if (c1 < (row * coll)) {
                array22[i][j] = array2[c1];
                c1++;
            }
        }
    }

    if (choice == 1) {
        mean(array2, row, coll);
    }
    else if (choice == 2) {
        int r;
        int c2;
        cout << "Connected components being found with 'QUEUE' " << endl;
        cout << "Enter the cordinates.......(row) & (column) respectively " << endl;
        cin >> r;
        cin >> c2;
        if (r < row && r>0 && c2 < coll && c2>0) {

            connectedPixel(array2, row, coll, r, c2);
        }
        else {
            cout << "Out of bound.... Program exit....." << endl;
        }
    }
    else if (choice == 3) {
        int r;
        int c2;
        cout << "Connected components being found with 'STACK' " << endl;
        cout << "Enter the cordinates.......(row) & (column) respectively " << endl;
        cin >> r;
        cin >> c2;
        if (r < row && r>0 && c2 < coll && c2>0) {

            checkstack(array2, row, coll, r, c2);
        }
        else {
            cout << "Out of bound.... Program exit....." << endl;
        }
    }
    else if (choice == 4) {
        RLCimg(array22, row, coll);
    }
    else if (choice == 5) {
        node4* tree = nullptr;
        quickTree(array22, row, coll, tree);
    }
    else if (choice == 6) {
        //HasingTable(array22, row, coll, name);
    }

    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] array2;

}
int main() {
    ifstream myfile("bat-5.pgm");
    int choice;
    string filename;
    struct tm currenttime;
    time_t timee = time(0);
    localtime_s(&currenttime, &timee);
    string timeee = (to_string(currenttime.tm_year + 1900) + to_string(currenttime.tm_mon + 1) + to_string(currenttime.tm_mday));
    string name = "21i1758" + timeee + ".txt";
    int** array = new int* [256];
    for (int i = 0; i < 256;i++)
        array[i] = new int[256];
    for (int i = 0; i < 256;i++) {
        for (int j = 0; j < 256;j++) {
            if (j % 5 == 0 || j % 2 == 0)
                array[i][j] = 0;
            else {
                array[i][j] = 255;
            }

        }
    }
    node4* tree = nullptr;
    cout << "-------------------------------------------------" << endl;
    cout << " Q1: press 1 to run solution of Q1 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Q2 : press 2 to run the solution of Q2 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Q3 : press 3 to run the solution of Q3 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Q4 : press 4 to run the solution of Q4 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Q5 : press 5 to run the solution of Q5 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Q6 : press 6 to run the solution of Q6 " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << " Exit: press 7 to Exit the program " << endl;
    cout << "-------------------------------------------------" << endl;
    cin >> choice;
    if (choice > 7 || choice < 1) {
        cout << " Enter again :) " << endl;
        cin >> choice;
    }
    fstream input;
    input.open(name, ios::out);
    input << "User Enter the Choice " << choice << " to run respective Question";
    input.close();
    switch (choice) {

    case 1:
        cout << "Enter The name of file" << endl;
        cin >> filename;
        input.open(name, ios::out);
        input << "User Enter the filename " << filename << " To run Q1";
        input.close();
        readWord(filename, 1);
        break;
    case 2:
        cout << "Enter The name of file " << endl;
        cin >> filename;
        input.open(name, ios::out);
        input << "  User Enter the filename " << filename << " To run Q2 ";
        input.close();
        readWord(filename, 2);
        break;
    case 3:
        cout << "Enter The name of file" << endl;
        cin >> filename;
        input.open(name, ios::out);
        input << "  User Enter the filename " << filename << " To run Q3 ";
        input.close();

        readWord(filename, 3);
        break;
    case 4:
        cout << "Enter The name of file" << endl;
        cin >> filename;
        input.open(name, ios::out);
        input << "  User Enter the filename " << filename << " To run Q4 ";
        input.close();
        cout << '1  ';
        readWord("bat-5.pgm", 4);
        //quickTree(array, 256, 256, tree);
        break;
    case 5:
        cout << "Enter The name of file" << endl;
        cin >> filename;
        input.open(name, ios::out);
        input << "  User Enter the filename " << filename << " To run Q6 ";
        input.close();
        readWord(filename, 6);
        //HasingTable(array, 10, 10);
        break;
    case 6:
        //cout << "Enter The name of file" << endl;
        //cin >> filename;
        input.open(name, ios::out);
        input << "  User Enter To run Q5 ";
        input.close();
        HasingTable(name);
        //readWord(filename, 5);
        //quickTree(array, 256, 256, tree);
        break;
        
    case 7:
        input.open(name, ios::out);
        input << "  User Exit the Program...... :-( ";
        input.close();
        return 0;
        break;
    }
    return 0;
}
