//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

void swap(int a[], int left, int right) {
    int temp;
    temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}


void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        if(a[mid] == 0) {
            swap(a,low,mid);
            low++;
            mid++;
        }
        else if(a[mid] == 1) {
            mid++;
        }
        else if(a[mid] == 2){
            swap(a,mid,high);
            high--;
        }
        
    }
}
