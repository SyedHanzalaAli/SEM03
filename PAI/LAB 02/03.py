studentRecords = [
    ("Hanzala" ,85 ),
    ("Hussain" ,15 ),
    ("Alu" ,78 ),
    ("shinki" ,47 ),
    ("Usman" ,95 ),
]

for i in range(len(studentRecords)):
    for j in range(i+1, len(studentRecords)):
        if studentRecords[i][1] < studentRecords[j][1]:
            studentRecords[i], studentRecords[j] = studentRecords[j], studentRecords[i]

print("top 3 students: ")
for i in range(3):
    print(studentRecords[i][0],"-",studentRecords[i][1])