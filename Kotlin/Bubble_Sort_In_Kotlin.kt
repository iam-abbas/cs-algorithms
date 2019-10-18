//Bubble Sort
//Driver function
fun main (args : Array<String>) {
    print("Enter the size of the array : ")
    var n = readLine()!!.toInt()
    var arr = Array(n, {0})
    println("Enter the elements of the array")
    for (i in 0 until n) {
        arr[i] = readLine()!!.toInt()
    }
    bubbleSort(arr)
}

//function for bubble sort

fun bubbleSort(arr : Array<Int>) {
    var n = arr.size
    var temp : Int
    for(i in 0 until  n-1) {
        for(j in 0 until n-1) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
            }
        }
    }
    for (i in arr) {
        print("$i ")
    }
}

//This code is contributed by jatinsachdevame
