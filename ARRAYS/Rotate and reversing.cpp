#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp=*a; *a=*b; *b = temp;
}

//Iterative
void rev(vector < int > &a, int low, int high) {
    while(low < high) {
        swap(&a[low], &a[high]);
        low += 1; high -= 1;
    }
    return;
}

//Recursive
void rev(vector < int > &a, int low, int high) {
    //Base Case
    if(low < high) {
        swap(&a[low], &a[high]);
        rev(low+1, high-1);
    }
    return;
}

//Left Rotate
vector < int > rotateLeft(int d, vector < int > &a) {
    d = d%a.size();
    int n = a.size();

    rev(a, d, n-1);
    rev(a, 0, d-1);
    rev(a, 0, n-1);

    return a;
}

//Right Rotate
vector < int > rotateRight(int d, vector < int > &a) {
    d = d%a.size();
    int n = a.size();

    rev(a, 0, n-d-1);
    rev(a, n-d, n-1);
    rev(a, 0, n-1);

    return a;
}