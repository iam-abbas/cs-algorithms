import java.util.*
fun insertionSort(arr:IntArray){
    var i,key,j
    for(i in 0 until arr.size-1){
        key = arr[i]
        j = i-i
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j]
            j = j-1
        }
        arr[j+1] = key
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
    insertionSort(array)
    for (i in 0 until sizeOfList){
        print(array[i])
        print(" ")
    }
}
