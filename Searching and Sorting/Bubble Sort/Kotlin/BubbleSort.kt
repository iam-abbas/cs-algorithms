import java.util.*
fun bubbleSort(arr:IntArray){
    for(i in 0 until arr.size-1){
        for(j in 0 until arr.size-i-1){
            if(arr[j]>arr[j+1]){
                var temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
            }
		}
    }
}
fun main(args:Array<String>) {
    var scanner = Scanner(System.`in`)
    print("enter the size to be sorted ")
    var sizeOfList = scanner.nextInt()
    val array = IntArray(sizeOfList)
    print("start entering values to be sorted ")
    for (i in 0 until sizeOfList) {
        array[i] = scanner.nextInt();
    }
    bubbleSort(array)
    for (i in 0 until sizeOfList){
        print(array[i])
        print(" ")
    }
}