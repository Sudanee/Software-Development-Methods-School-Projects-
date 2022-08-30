def createCollections():
    c1 = ("apple", "banana" , "orange")
    c2 ={"avocado","tomato", "beet"}
    c3 = ["rice" ,"potatoes","bread"]
    c4 = {"Sun": c1, "Mon " : c2, "Tue " : c3}
    return(c1, c2, c3, c4)

def main():
    col1, col2, col3, col4 = createCollections()
    print (f"{col1}, {type(col1)}, {type(col1) == list}")
    print (f"{col2}, {type (col2)}, {type ( col2) == set}")
    print (f"{col3}, {type (col3)}, {type(col3) == tuple} ")
    print (f"{col4.get('Sun')}, {type(col4)}, {type(col4) == dict}")
main()

