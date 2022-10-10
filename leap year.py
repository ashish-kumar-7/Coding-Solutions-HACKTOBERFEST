year=int(input('Enter the year: '))

if year < 0:
    print("Entered a valid year")
    
else:
    if year%100 == 0:
        if year%400==0:
            print("It is a leap year")  
        else:
            print("It is not a leap year")  

    else:
        if year%4  == 0:
            print("It is a leap year")  
        else:
            print("It is not a leap year")   
