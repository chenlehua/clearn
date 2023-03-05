#include <stdio.h>

int *sortArray(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    for (int gap = numsSize / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < numsSize; i++) {
            int tmp = nums[i], j;
            for (j = i - gap; j >= 0 && nums[j] > tmp; j -= gap) {
                nums[j + gap] = nums[j];
            }
            nums[j + gap] = tmp;
        }
    }
    return nums;
}

int main() {
    int nums[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 04};
    int returnSize;
    int *result = sortArray(nums, 10, &returnSize);
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\nreturnSize: %d", returnSize);
    return 0;
}

