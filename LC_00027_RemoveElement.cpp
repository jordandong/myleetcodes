/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Hide Tags Array Two Pointers
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(A[i] == elem){
                swap(A[i], A[j--]);
            }else{
                i++;
            }
        }
        return i;
    }
};

//Keep original order
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while (i < n) {
            if (A[i] != elem)
                A[j++] = A[i++];
            else
                i++;
        }
        return j;
    }
};
