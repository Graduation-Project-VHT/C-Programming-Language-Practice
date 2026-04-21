int compare(const void* a,const void* b)
{
    int obj1 = *(const int*)a;
    int obj2 = *(const int*)b;

    if( obj1 < obj2) return -1;
    else if( obj1 > obj2) return 1;
    else return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize < 2) return FALSE;

    qsort(nums, numsSize, sizeof(int), compare);    
    for(int i = 0; i< numsSize - 1; i++)
    {
        if (nums[i] == nums[i+1])
        {
            return TRUE;
        }
    }
    return FALSE;
}
