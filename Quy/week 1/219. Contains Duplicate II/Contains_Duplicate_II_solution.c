typedef struct{
    int value;
    int index;
} Element;

int compare( const void* a, const void* b)
{
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;

    if(e1 -> value < e2 -> value) return -1;
    else if (e1 -> value > e2 -> value) return 1;
    else return e1->index - e2->index;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(numsSize < 2) return FALSE;
    // cấp phát bộ nhớ
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for( int i = 0; i < numsSize; i++)
    {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Element), compare);

    for(int j = 0; j < numsSize -1; j++)
    {
        if(arr[j].value == arr[j+1].value)
        {
            if(abs(arr[j+1].index - arr[j].index) <= k)
            {
                free(arr);
                return TRUE;
            }
        }
    }
    free(arr);
    return FALSE;
}
