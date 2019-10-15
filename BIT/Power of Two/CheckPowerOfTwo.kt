fun main(args: Array<String>){
	var number = readLine()!!.toInt()
	var check = number and (number - 1)
	if(check == 0){
		print("Yes")
	}
	else{
		print("No")
	}
}