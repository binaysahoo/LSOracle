app(bipartite-mcm bipartite-mcm.cpp EXP_OPT)

add_test_scale(small1 bipartite-mcm -inputType generated -n 100 -numEdges 1000 -numGroups 10 -seed 0)
add_test_scale(small2 bipartite-mcm -inputType generated -n 100 -numEdges 10000 -numGroups 100 -seed 0)
#add_test_scale(web bipartite-mcm -inputType generated -n 1000000 -numEdges 100000000 -numGroups 10000 -seed 0)
