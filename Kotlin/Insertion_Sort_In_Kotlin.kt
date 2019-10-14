//Driver function
fun main (args : Array<String>) {
    print("Enter the size of thev array : ")
    var n = readLine()!!.toInt()
    var arr = Array(n, {0})
    println("Enter the elements of the array")
    for (i in 0 until n) {
        arr[i] = readLine()!!.toInt()
    }
    insertionSort(arr)
}

//function for insertion sort

fun insertionSort(arr : Array<Int>) {
    var n = arr.size
    var key : Int
    var j : Int
    for(i in 1 until  n) {
        key = arr[i]
        j = i-1
        while (j>=0 && arr[j] > key) {
            if (key<arr[j]) {
                arr[j+1] = arr[j]
                j -= 1
            }
        }
        arr[j+1] = key
    }
    for (i in arr) {
        print("$i ")
    }
}

//This code is contributed by jatinsachdevame
