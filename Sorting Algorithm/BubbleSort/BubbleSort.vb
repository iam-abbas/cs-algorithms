Module Module1
        Sub Bubblesort(Array() as Integer, Length as Integer)  
        Dim I As Integer  
        Dim J As Integer  
        Dim Temp As Integer  
        Dim Length As Integer  
        Dim Array() As String = {}  
      
        For I = Length - 1 To 1 Step -1 'the last element on the array does not get sorted.    
            For J = 0 To I - 1  
                If Array(J) > Array(J + 1) Then  ' Compare neighboring elements    
                    Temp = Array(J)  
                    Array(J) = Array(J + 1)  
                    Array(J + 1) = Temp  
      
                End If  
            Next  
        Next  
    End Sub  
End Module