fun counting_sort(A: Array<Int>, max: Int) {
    // Array in which result will store
	var B = Array<Int>(A.size, { 0 })   
    // count array
	var C = Array<Int>(max, { 0 })      
    for (i in 0..A.size - 1) {
        //count the no. of occurrence of a 
		//particular element store in count array
		C[A[i] - 1] = C[A[i] - 1] + 1    
    }
    for (i in 1..C.size - 1) {
        // calculate commutative sum
		C[i] = C[i] + C[i - 1]          
    }
    for (i in A.size - 1 downTo 0) {
        // place the element at its position
		B[C[A[i] - 1] - 1] = A[i]                  
        // decrease the occurrence of the element by 1
		C[A[i] - 1] = C[A[i] - 1] - 1              
    }
    println("After sorting :")
    for (i in B) {
        print("$i ")
    }

}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    var n = readLine()!!.toInt()

    println("Enter elements : ")
    var A = Array(n, { 0 })
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()
    // calculate maximum element from array
    var max = A[0];
    for (i in A) {
        if (i > max) {
            max = i
        }
    }
    counting_sort(A, max)
}
