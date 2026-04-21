int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int soldier = 0;
    for( int i =0; i < numsSize; i++)
    {
        if(count == 0)
        {
            soldier = nums[i];
            count++;
        }
        else
        {
            if(soldier == nums[i])
            {
                count++;
            }
            else count--;
        }
    }
    return soldier;
}
