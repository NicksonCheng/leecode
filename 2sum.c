#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if ((target - nums[i]) == nums[j]) {
        int *pairs = malloc(sizeof(int) * 2);
        pairs[0] = i;
        pairs[1] = j;
        *returnSize = 2;
        return pairs;
      }
    }
  }
  /* no solution found*/
  *returnSize = 0;
  return malloc(sizeof(int) * 0);
}

int main() {
  int nums[] = {3, 2, 4};
  int numSize = sizeof(nums) / sizeof(nums[0]);
  int target = 6;
  int returnSize;
  int *result = twoSum(nums, numSize, target, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("result[%d] = %d\n", i, result[i]);
  }
  return 0;
}