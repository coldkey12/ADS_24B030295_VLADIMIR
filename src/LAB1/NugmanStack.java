package LAB1;

import java.util.*;

public class NugmanStack {

    static int[] nearestNotGreater(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int[] res = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && stack.peek() > arr[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                res[i] = stack.peek();
            } else {
                res[i] = -1;
            }
            stack.push(arr[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] ans = nearestNotGreater(arr);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i]);
            if (i < ans.length - 1) System.out.print(" ");
        }
        System.out.println();
    }
}