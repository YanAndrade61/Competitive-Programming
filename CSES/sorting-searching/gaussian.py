import numpy as np

# n: number of equations
# k: number of variables
n, k = list((map(int,input().split())))
loop = n+1

# Step 1: create the augment matrix
system = []
while loop := loop-1:
        equation = np.array(list(map(float,input().split())))
        system.append(equation)
system = np.array(system)

# Step 2: transform the matrix in echelon form
eq = 0
for ki in range(k):
        while(eq < n and system[eq][ki] == 0): eq+=1
        if(eq >= n): break
        system[eq] = system[eq]/system[eq][ki]
        for ni in range(eq+1,n):
                system[ni] = system[ni] - system[ni][ki]*system[eq]
        eq+=1

# Step 3: Back Substitution
eq = n-1
for ki in range(k-1,-1,-1):
        while(eq < n and system[eq][ki] == 0): eq-=1
        if(eq <= 0): break
        for ni in range(eq-1, -1, -1):
                system[ni] = system[ni] - system[ni][ki]*system[eq]
        eq -= 1

print(system)