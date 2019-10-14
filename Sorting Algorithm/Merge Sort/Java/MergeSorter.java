/*
 * Merge Sorter
 * @author Samy Rezzag
 * Pseudocode adaptation from Thomas H. Cormens' Introduction to Algoirthms Third Edition.
 */

/*
 * The MergeSorter class demonstrates the divide-and-conquer MergeSort algorithm.
 */

public class MergeSorter<T> {

	/*
	 * Initial point of entry. Public Sort of type T takes an array parameter of
	 * type Comparable<? extends T>[]. This checks for null and base cases. If
	 * neither are found it will pass it to the private overloaded method for
	 * further sorting.
	 * 
	 * @param Comparable<? extends T>[] items
	 * 
	 * @throws NullPointerException if items is a null array, or has null value.
	 */

	public static <T> void sort(Comparable<? extends T>[] items) {
		// Test if items is null.
		if (items == null) {
			throw new NullPointerException("Invalid Array. Array cannot be null.");
			// Test if array is empty, or of size 1 and not [null].
		} else if (items.length == 0 || (items.length == 1 && items[0] != null)) {
			return;
		} else {
			// Scan array for any additional null values.
			for (int i = 0; i < items.length; i++) {
				if (items[i] == null) {
					throw new NullPointerException("Invalid Array. Array values cannot be null.");
				}
			}
			// Pass valid array for sorting.
			sort(items, 0, items.length - 1);
		}
	}

	/*
	 * The private sort method calculates low, middle, and high indices of the
	 * Comparable array. If the start index is lower than the high index, it will
	 * continue to divide the array recursively and merge as needed.
	 * 
	 * @param Comparable<? extends T>[] items, int low, int high
	 * 
	 */
	
	private static <T> void sort(Comparable<? extends T>[] items, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			sort(items, low, mid);
			sort(items, mid + 1, high);
			merge(items, low, mid, high);
		}
	}

	/*
	 * The merge method needed some tweaking in terms the of the parameter. Java
	 * doesn't allow for generic arrays to be created. Type casting is used as a
	 * workaround to this. Items has to be truncated to a raw type of comparable.
	 * Instead of creating left and right subarrays to merge, indices of the index
	 * array are used to traverse the array and compare one side to the other. A
	 * temporary Array is used to collect and store the sorted values, and are then
	 * casted in order to the items array. We use the temporary array to avoid
	 * overwriting the items array which we are referencing.
	 * 
	 * @param Comparable items, int low, int medium, int high
	 */

	private static <T> void merge(Comparable[] items, int low, int mid, int high) {
		Object[] tempArr = new Object[high - low + 1];
		int i = low;
		int j = mid + 1;
		int k = 0;
		while (i <= mid && j <= high) {
			if (items[i].compareTo(items[j]) <= 0)
				tempArr[k] = items[i++];
			else
				tempArr[k] = items[j++];
			k++;
		}
		if (i <= mid && j > high) {
			while (i <= mid)
				tempArr[k++] = items[i++];
		} else {
			while (j <= high)
				tempArr[k++] = items[j++];
		}
		for (k = 0; k < tempArr.length; k++) {
			items[k + low] = (Comparable<?>) (tempArr[k]); // cast
		}
	}

	/*
	 * Main method used for testing various types of arrays to account for any
	 * issues in live/production environment.
	 */

	public static void main(String[] args) {

		// Test Sort of Strings
		String[] sortWords = new String[] { "orange", "green", "blue", "red", "yellow", "purple" };
		MergeSorter.sort(sortWords);

		// Test Sort of Integers
		Integer[] sortNumbers = new Integer[] { 5, 7, 3, 9, 4, 0, 1, 2, 8, 6 };
		MergeSorter.sort(sortNumbers);

		// Test Sort of Empty Array
		Integer[] emptyArray = new Integer[0];
		MergeSorter.sort(emptyArray);

		// Test Sort of Null Array
		Integer[] nullArray = null;
		MergeSorter.sort(nullArray);

		// Test Sort of Null value in Array
		Integer[] nullValueInArray = new Integer[] { 1, 5, 4, null, 3, 2 };
		MergeSorter.sort(nullValueInArray);

		// Test Sort of 1-Value Array
		Integer[] oneNull = new Integer[] { null };
		MergeSorter.sort(oneNull);

		// Test Sort of 1-Value Array
		Integer[] oneArray = new Integer[] { 1 };
		MergeSorter.sort(oneArray);

		// Test Sort of Strings + Integers
		String[] mixedArray = new String[] { "chicken", "5", "cow", "3", "horse", "1", "goat", "4", "sheep", "2" };
		MergeSorter.sort(mixedArray);

		// Test Sort of Negative + Positive Integers.
		Integer[] negativeIntegers = new Integer[] { -5, 5, -4, 4, -3, 3, -2, 2, -1, 1, 0 };
		MergeSorter.sort(negativeIntegers);
	}
}
