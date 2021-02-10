def multiple_of_3_or_5():
    for i in xrange(1000):
            if not i % 3 or not i % 5:
                return i

    print sum(multiples_of_3_or_5())

multiple_of_3_or_5()
