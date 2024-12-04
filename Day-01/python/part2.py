data_in = open("../data.txt",'r')
data_first :list[int] = []
data_second:list[int] = []
for line in data_in:
    x,y = line.split('   ')
    x,y = int(x),int(y)
    data_first.append(x)
    data_second.append(y)

sim_score = 0
for x in data_first:
    sim_score+=x*data_second.count(x)

print(sim_score)