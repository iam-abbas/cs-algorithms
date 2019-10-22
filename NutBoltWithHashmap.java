import java.util.Arrays;
import java.util.HashMap;

public class NutBoltWithHashmap{

    public static void domatch(char[] nuts, char[] bolts) {
        
        //Create a HashMap for nuts, nut as key and its position as value
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for (int j = 0; j < nuts.length; j++) {
            map.put(nuts[j], j);
        }

        //for each bolt , check for the nut in map
        for (int j = 0; j < bolts.length; j++) {
            char bolt = bolts[j];
            if (map.containsKey(bolt)) {
                nuts[j] = bolts[j];
            } else {
                System.out.println("for bolt " + bolt + " no nut is present.");
                return;
            }
        }
        System.out.println(" Matched nuts and bolts are: ");
        System.out.println(Arrays.toString(nuts));
        System.out.println(Arrays.toString(bolts));
    }

    public static void main(String[] args) {
        char[] nuts = {'$', '%', '&', 'x', '@'};
        char[] bolts = {'%', '@', 'x', '$', '&'};
        domatch(nuts, bolts);
    }
}