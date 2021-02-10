def growthincm(year):
    growth = year*2
    return growth
def growthinft(year):
    ft = growthincm(year)/24
    return ft
def growthinmiles(year):
    miles = growthinft(year)/5280
    return miles
def main():
    year = int(input("enter a how many years in the future you want to go  "))
    growth = growthincm(year)
    print("The size of island will be",growth, "cm bigger")
    ft = growthinft(year)
    print("Or", ft, "feet bigger")
    miles = growthinmiles(year)
    print("Or", miles, "miles bigger")
main()
