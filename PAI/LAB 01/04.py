tuple = (1, -3, 2, 4, -1, 5, -2)

closestSum = float('inf')
pair = (0,0)

for i in range(len(tuple)):
    for j in range(i+1 , len(tuple)):
        currentSum = tuple[i] + tuple[j]
        if abs(currentSum) < abs(closestSum):
            closestSum = currentSum
            pair = (tuple[i], tuple[j])


print("pair with sum closest to zero : " , pair)
print("sum" , closestSum) 



