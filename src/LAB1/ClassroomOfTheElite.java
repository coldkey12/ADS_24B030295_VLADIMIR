package LAB1;

import java.util.*;

public class ClassroomOfTheElite {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();

        Queue<Character> queue = new LinkedList<>();
        for (char c : s.toCharArray()) {
            queue.offer(c);
        }

        int sCount = 0, kCount = 0;
        for (char c : s.toCharArray()) {
            if (c == 'S') sCount++;
            else kCount++;
        }

        int sKills = 0, kKills = 0;

        while (sCount > 0 && kCount > 0) {
            char current = queue.poll();

            if (current == 'S') {
                if (sKills > 0) {
                    sKills--;
                    sCount--;
                } else {
                    kKills++;
                    queue.offer(current);
                }
            } else {
                if (kKills > 0) {
                    kKills--;
                    kCount--;
                } else {
                    sKills++;
                    queue.offer(current);
                }
            }
        }

        if (sCount > 0) {
            System.out.println("SAKAYANAGI");
        } else {
            System.out.println("KATSURAGI");
        }
    }
}