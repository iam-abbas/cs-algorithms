/**
 * 
 * Sorts a list of generic Comparables using Insertion Sort
 *
 */
public class InsertionSort {
	
	/**
	 * Sorts a list of elements that extend comparable using insertion sort
	 * algorithm
	 * @param list A list of Comparables to be sorted
	 */
	public static <T extends Comparable<T>> void insertionSort (T[] list) 
	{
		int size = list.length;
		int outCounter, inCounter;
		T temp;
		// Sort list[] into increasing order.
		for (outCounter = 1; outCounter < size; outCounter++)
		{
			temp = list[outCounter];
			for (inCounter = outCounter; inCounter > 0 && list[inCounter - 1].compareTo(temp) > 0; inCounter--)
			{
				list[inCounter] = list[inCounter - 1];
			}
			list[inCounter] = temp;
		}
	}
}
