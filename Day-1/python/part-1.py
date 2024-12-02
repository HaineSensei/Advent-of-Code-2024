data_in = open("data.txt",'r')
data_pairs : list[tuple[int,int]] = [(int(x),int(y)) for x,y in 
                               [line.split('   ') for line in data_in]]
data : tuple[list[int],list[int]] = ([x for x,_ in data_pairs],[y for _,y in data_pairs])

sorted_data = [None,None]
sorted_data[0] = sorted(data[0])
sorted_data[1] = sorted(data[1])

sorted_data_pairs : list[tuple[int,int]] = [(sorted_data[0][i],sorted_data[1][i]) for i in range(len(sorted_data[0]))]
print(sum(abs(x - y) for x,y in sorted_data_pairs))

