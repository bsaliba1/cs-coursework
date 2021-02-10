def myCount(param_list):
    accum = 0
    for i in param_list:
        accum = accum + 1
    return accum

def main():
    print(myCount([2,4,6]))
main()
