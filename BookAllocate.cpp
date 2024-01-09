/*Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.*/

bool isPossiblesolution(vector<int> arr,int n,int m,int mid ){

    int studentcount=1;

    int pageSum=0;

    for(int i=0;i<n;i++){

// Check If total no of pages of books allocated to one student is exceeds the mid value or not.

        if(pageSum+arr[i]<=mid){

            pageSum+=arr[i];

        }

        else{

            studentcount++;

// Check whether the studentcount is exceed the no. of student or not and mid is less than present book page numbers.    

            if(studentcount>m || arr[i]>mid){

                return false;

            }

            pageSum=arr[i];

        }

    }

   return true; 

}

int findPages(vector<int>& arr, int n, int m) {

// Special Case      

    if(n<m) return -1;

    int start=0;

    int sum=0;

    for(int i=0;i<n;i++){

        sum+=arr[i];

    }

    int end = sum;

    int ans=-1;

    int mid= start +(end-start)/2;

    // Apply binary search to find mid element

    while(start<=end){

        if(isPossiblesolution(arr,n,m,mid)){

           ans=mid;

           end=mid-1;

        }

        else{

            start=mid+1;

        }

     mid= start +(end-start)/2;

    }

    return ans;

}

