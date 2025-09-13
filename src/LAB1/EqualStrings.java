package LAB1;

import java.io.*;

public class EqualStrings {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        String s1 = input[0];
        String s2 = input[1];

        String result1 = processString(s1);
        String result2 = processString(s2);

        if (result1.equals(result2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    static String processString(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '#') {
                if (sb.length() > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                }
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}