/*
 * @author Samy Rezzag
 */

/*
 * I believe with my current implementation -- I cannot guarantee an optimal result,
 * as is the nature of greedy algorithms, it can be optimal under the right circumstances.
 * For some parameters such as [1,2,4,8,2^n], this implementation will guarantee the optimal
 * result because the values are spaced out well enough, as are the ones provided for sample input.
 * 
 * For example, one instance where it won't be optimal is the following:
 * 
 * currencies[] = [1, 9, 18, 36, 45] where amount = 73.
 * My implementation would return output[] = [1,1,1,0,1] (1+9+18+45)
 * As compared to the *optimal* output[] = [1,0,0,2,0] (1+36+36)
 */
public class MoneyDispenser {

	private int[] currencies; // Input Array
	private int[] output; // Output Array
	private int counter; // Keep track of how many of a certain bill is used.
	private int total = 0; // Used to verify we are dispensing the right amount.
	private int initialAmount = 0; // Used to verify we are dispensing the right amount.

	/*
	 * @param int[] currencies is an input array that is pre-sorted and contains the
	 * available denominations.
	 *
	 * This is a constructor which initializes the currencies array and creates an
	 * output array of the same length.
	 */
	public MoneyDispenser(int[] currencies) {
		this.currencies = currencies;
		output = new int[currencies.length];
	}

	/*
	 * @param amount is the amount of money a user is looking to receive.
	 * 
	 * This first copies the amount to initalAmount. This is because "amount" will
	 * change throughout the method.
	 * 
	 * Next we check to see if the amount is less than 0. If so, fill the output
	 * array with 0's and return it.
	 * 
	 * Then, we run a loop. For each entry in the input array, from right to left,
	 * subtract that value from "amount" if "amount" is greater. it also adds on to
	 * a running total for verification later on that we are returning the equal
	 * amount. It also has a counter which keeps track of how many of that bill is
	 * being given out.
	 * 
	 * Next, for each iteration of that, we add the counter amount to the output
	 * array in the same index that was used for the currencies array.
	 * 
	 * Finally, we perform a quick check to ensure that we've reached the end of the
	 * array and are capable of giving back exact change. If not, fill output with
	 * 0's and return the array.
	 */
	public int[] dispense(int amount) {
		initialAmount = amount;
		if (amount < 0) {
			for (int i = 0; i < currencies.length; i++) {
				output[i] = 0;
			}
			return output;
		}
		for (int i = currencies.length - 1; i >= 0; i--) {
			counter = 0;
			while (amount >= currencies[i]) {
				amount = amount - currencies[i];
				total += currencies[i];
				counter++;
			}
			output[i] = counter;
		}
		if (total != initialAmount) {
			for (int i = 0; i < currencies.length; i++) {
				output[i] = 0;
			}
		}
		return output;
	}

	public static void main(String[] args) {

		MoneyDispenser m1 = new MoneyDispenser(new int[] { 1, 5, 10, 20, 50, 100 });
		m1.dispense(0);
		MoneyDispenser m2 = new MoneyDispenser(new int[] { 1, 5, 25, 100, 500 });
		m2.dispense(841);
		MoneyDispenser m3 = new MoneyDispenser(new int[] { 1, 9, 18, 36, 45 });
		m3.dispense(73);
		MoneyDispenser m4 = new MoneyDispenser(new int[] { 1, 5, 25, 100, 500 });
		m4.dispense(-1);
	}
}
