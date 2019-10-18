import java.util.List;

/**
* Quick sort java algorithm
* @author rafbel
* @since 2019-10-15
*
*/
public class QuickSort {

	public static void sort(List<String> list) {
		if (list == null) {
			return;
		}
		
		sortSublist(list, 0, list.size() - 1);
	}
	
	public static void sortSublist(List<String> list, int startIndex, int endIndex) {
		
		if (startIndex >= endIndex) {
			return;
		}
		
		int middleIndex = partition(list, startIndex, endIndex);
		
		sortSublist(list, startIndex, middleIndex - 1);
		sortSublist(list, middleIndex + 1, endIndex);
	}
	
	private static int partition(List<String> list, int startIndex, int endIndex) {
		int left = startIndex, right = endIndex - 1, pivot = endIndex;
		
		while (left <= right) {
			
			while (left <= endIndex && list.get(left).compareTo(list.get(pivot)) < 0) {
				left++;
			}
			
			while (right >= startIndex && list.get(right).compareTo(list.get(pivot)) >= 0) {
				right--;
			}
			
			if (left < right) {
				swap(list, left, right);
			} else {
				swap(list, left, endIndex);
			}
		}
		
		return left;
	}
	
	private static void swap(List<String> list, int smallerWordIndex, int largerWordIndex) {
		String smallerWord = list.get(largerWordIndex);
		list.set(largerWordIndex, list.get(smallerWordIndex));
		list.set(smallerWordIndex, smallerWord);
	}
}
