//Selection Sort
//Driver function
fun main (args : Array<String>) {
    print("Enter the size of the array : ")
    var n = readLine()!!.toInt()
    var arr = Array(n, {0})
    println("Enter the elements of the array")
    for (i in 0 until n) {
        arr[i] = readLine()!!.toInt()
    }
    selectionSort(arr)
}

//function for selection sort

fun selectionSort(arr : Array<Int>) {
    var n = arr.size
    var index : Int
    var min : Int
    for(i in 0 until  n-1) {
        min = arr[i]
        index = i
        for(j in i+1 until n) {
            if (min > arr[j]) {
                min = arr[j]
                index = j
            }
        }
        var temp = arr[i]
        arr[i] = arr[index]
        arr[index] = temp

    }
    for (i in arr) {
        print("$i ")
    }
}

//This code is contributed by jatinsachdevame
