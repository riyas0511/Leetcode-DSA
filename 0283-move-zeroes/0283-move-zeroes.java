// class Solution {
//     public  static int[] moveZeroes(int[] a) 
//     {int j = -1;
//      int n=a.length;
//         //place the pointer j:
//         for (int i = 0; i < n; i++) {
//             if (a[i] == 0) {
//                 j = i;
//                 break;
//             }
//         }
//  if (j == -1) return a;
      

//         //Move the pointers i and j
//         //and swap accordingly:
//         for (int i = j + 1; i < n; i++) {
//             if (a[i] != 0) {
//                 //swap a[i] & a[j]:
//                 int tmp = a[i];
//                 a[i] = a[j];
//                 a[j] = tmp;
//                 j++;
//             }
//         }
//      return a;
    
//     }
// }

class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;  // Pointer to track the position of the first zero

        // Move non-zero elements forward
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // Fill the remaining part of the array with zeros
        for (int i = j; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
