with open("ASMCODE.asm", "r") as f:
    lines = f.readlines()

mapping = {
    "ADD": "1",
    "MUL": "2",
    "SUB": "3",
    "DIV": "4",
    "COP": "5",
    "AFC": "6",
    "JMP": "7",
    "JMF": "8",
    "INF": "9",
    "SUP": "A",
    "EQU": "B",
    "PRI": "C",
    "CALL" : "D",
    "BX" : "E"
}

for i in range(len(lines)):
    label = lines[i].split()[0]
    if label in mapping:
        lines[i] = lines[i].replace(label, mapping[label])

with open("ASMCODE.asm", "w") as f:
    f.writelines(lines)
