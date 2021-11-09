
num_test_case = 51
num_nodes = 2000
num_special = num_nodes
special = [str(i) for i in range(1, num_nodes + 1)]
selected = 1
st = ""
st += f"{num_nodes} {num_special} {selected}\n"
st += f"{' '.join(special)}\n"

for i in range(1, num_nodes):
    st += f"{i} {i+1}"
    st += "\n" if (i%100 == 0) else " "
st += "\n\n"
with open('/media/psuv/Data/CP/input.in', 'w') as f:
    f.write(f"{num_test_case}\n\n")
    for i in range(num_test_case):
        f.write(st)
