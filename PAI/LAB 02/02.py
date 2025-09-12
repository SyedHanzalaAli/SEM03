def add(m1 , m2):
    rows = len(m1)
    cols = len(m1[0])
    m3 = []

    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(m1[i][j]+m2[i][j])
        m3.append(row)

    return m3

def multiply(m1 , m2):
    r1 = len(m1)
    c1 = len(m1[0])
    r2 = len(m2)
    c2 = len(m2[0])

    if c1 != r2:
        return "Multiplication not possible"
    
    m3 = []
    for i in range(r1):
        row = []
        for j in range(c2):
            sum =0
            for k in range (c1):
                sum += m1[i][k] * m2[k][j]
            row.append(sum)
        m3.append(row)
    
    return m3



