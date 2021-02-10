Usage:
    ./workloads <outputFile> <seed> <option> //Options: 1 = NLocality, 2 = 80-20, 3 = Looping
    ./policies <include_clock> <inputFile> //If <include_clock> = 1, then it include clock in data set 

In order to generate workloads:
    ./workloads tests/NLocality 1 1
    ./workloads tests/80_20 1 2
    ./workloads tests/looping 1 3
    
In order to generate data sets:
    ./policies 0 tests/NLocality >data/Graph1/NLoc.csv 
    ./policies 1 tests/80_20 >data/Graph2/80_20.csv
    ./policies 0 tests/looping >data/Graph3/looping.csv

In order to generate graphs:
    gnuplot -e "title='Figure 22.8'" -e "input_filename='data/Graph3/Looping.csv'" plot_hit_rates.plt > Figure_22_8.png
    gnuplot -e "title='Figure 22.6'" -e "input_filename='data/Graph1/NLoc.csv'" plot_hit_rates.plt > Figure_22_6.png
    
    //Need to edit this plot_hit_rates.plt to include clock
    gnuplot -e "title='Figure 22.9'" -e "input_filename='data/Graph2/80_20.csv'" plot_hit_rates.plt > Figure_22_9.png



    
