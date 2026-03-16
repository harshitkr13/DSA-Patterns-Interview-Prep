int paintersPartition(vector<int>& boards,int painters){
    int low=*max_element(boards.begin(),boards.end());
    int high=accumulate(boards.begin(),boards.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        int required=1,sum=0;

        for(int x:boards){
            if(sum+x>mid){
                required++;
                sum=x;
            }
            else sum+=x;
        }

        if(required<=painters) high=mid-1;
        else  low=mid+1;
    }

    return low;
}
