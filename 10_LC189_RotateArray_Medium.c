void rotate(int* nums, int numsSize, int k) {
    int m = numsSize;
    if(k>=m)
    {
      k=k%m;
    }
    int *num2 = malloc(sizeof(int)*m);
    int i = 0,j=m-1;
    int temp;

    for(int i =0 ; i<m;i++)
    {
        num2[(i+k)%m]=nums[i];
    }
    for(int i=0;i<m;i++)
    {
        nums[i]=num2[i];
    }
        

free(num2);
}
