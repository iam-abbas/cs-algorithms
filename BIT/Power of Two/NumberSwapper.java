/**
 * Demonstrates swapping of two number using bit manipulation.
 */
public class NumberSwapper {

    private Integer x;
    private Integer y;

    public NumberSwapper(Integer x, Integer y) {
        this.x = x;
        this.y = y;
    }

    public Integer getX() {
        return x;
    }

    public Integer getY() {
        return y;
    }

    @Override
    public String toString() {
        return "NumberSwapper{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    /**
     * Swaps the values of fields x and y in class.
     */
    public void swap() {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }

    /**
     * Swaps integers in array. Expects array to be not null and elements in array must be 2.
     * @param arr
     */
    public static void swapArray(int[] arr) {
        checkNotNull(arr);
        checkState(arr);
        arr[0] = arr[0] ^ arr[1];
        arr[1] = arr[0] ^ arr[1];
        arr[0] = arr[0] ^ arr[1];
    }

    private static void checkNotNull(int[] arr) {
        if(arr == null) {
            throw new NullPointerException("Array can not be null.");
        }
    }

    private static void checkState(int[] arr) {
        if(arr.length != 2) {
            throw new IllegalStateException("Array size must be 2.");
        }
    }
}