// Merge Sort Implementation
#include<iostream>
#include<vector>
using namespace std;

#define print(len, a) for(i=0; i<len; i++) cout<<a[i]<<" "; cout<<endl;

void merge(vector<int> &arr, int p, int q, int r){
  //cout<<p<<" "<<q<<" "<<r<<" "<<endl;
  vector<int> left, right;

  int j,i,k;
  for(j=p;j<=q;j++){
    left.push_back(arr[j]);
  }
  for(;j<r;j++){
    right.push_back(arr[j]);
  }
  left.push_back(99999);
  right.push_back(99999);

  //print(q-p+1,left);print(r-q-1,right);

  i=0;
  j=0;
  for(k=p;k<r;k++){
    if(left[i]<right[j])
      arr[k]=left[i++];
    else
      arr[k]=right[j++];
  }

}

void mergesort(vector<int> &arr, int start, int end) {
    if(start<end) {
      //cout<<start<<" "<<end<<"\n";
      int split = (int)((start+end)/2);
      mergesort(arr, start, split);
      mergesort(arr, split+1, end);
      merge(arr, start, split, end+1);
    }
}

int main() {
    int i, len;
    int list[] = {5, 2, 4, 7, 1, 3, 2, 6,-1};
    vector<int> arr (list, list + sizeof(list)/sizeof(int));
    len = (int)arr.size();
    print(len, arr);
    //cout<<"\n"<<len<<"\n";
    mergesort(arr, 0, len-1);
    print(len, arr);
    return 0;
}
