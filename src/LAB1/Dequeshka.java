package LAB1;

import java.util.*;

public class Dequeshka {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayDeque<Integer> deque = new ArrayDeque<>();

        while (sc.hasNext()) {
            String op = sc.next();

            if (op.equals("!")) {
                break;
            } else if (op.equals("+")) {
                int num = sc.nextInt();
                deque.addFirst(num);
            } else if (op.equals("-")) {
                int num = sc.nextInt();
                deque.addLast(num);
            } else if (op.equals("*")) {
                if (deque.isEmpty()) {
                    System.out.println("error");
                } else if (deque.size() == 1) {
                    int val = deque.removeFirst();
                    System.out.println(val + val);
                } else {
                    int first = deque.removeFirst();
                    int last = deque.removeLast();
                    System.out.println(first + last);
                }
            }
        }
    }
}