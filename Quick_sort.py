def Quick_Sort(lista):
    if len(lista) <= 1:
        return lista
    key = lista[0]
    equal = [x for x in lista if x == key]
    minor = [x for x in lista if x < key]
    major = [x for x in lista if x > key]
    return Quick_Sort(minor) + equal + Quick_Sort(major)