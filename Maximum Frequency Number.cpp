int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;
    int maxfeq = 0;
    int maxAns =0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        count[arr[i]]++ ;
        maxfeq = max(maxfeq , count[arr[i]]);
    }
    for(int i = 0 ; i<arr.size() ; i++){
        if(maxfeq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}