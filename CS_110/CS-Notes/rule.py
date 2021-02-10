def applyRules(lhch):
    rhstr = ""
    if lhch == 'A':
        rhstr = 'B'   # Rule 1
    elif lhch == 'B':
        rhstr = 'AB'  # Rule 2
    else:
        rhstr = lhch    # no rules apply
    return rhstr

def processString(oldStr):
    newstr = ""
    for ch in oldStr:
        newstr = newstr + applyRules(ch)
    return newstr

def createLSystem(numIters,axiom):
    startString = axiom
    for i in range(numIters):
        startString = processString(startString)
    return startString

def main():
    print(createLSystem(4, "A"))
main()