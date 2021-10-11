package lab01.p04;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        while (inp.hasNextLine()) {
            String line = inp.nextLine();

            StringBuilder buff = new StringBuilder();
            for (char c : line.toCharArray()) {
                if (Character.isLetter(c)) {
                    buff.append(Character.toLowerCase(c));
                }
            }

            StringBuilder temp = buff;

            temp.reverse();

            System.out.println(buff.toString().equals(temp.toString()) ? "palindrome" : "not a palindrome");
        }

        inp.close();
    }
}
