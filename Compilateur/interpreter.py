asm = open("ASMCODE.asm").readlines()
asm = [x.split(" ") for x in asm]
mem = [0] * 10
ip = 0
print(asm)

while ip < len(asm):
    opcode = asm[ip][0]
    if opcode == "ADD":
        print("add")
        result_addr = int(asm[ip][1])
        op1_addr = int(asm[ip][2])
        op2_addr = int(asm[ip][3])
        mem[result_addr] = mem[op1_addr] + mem[op2_addr]
        ip = ip +1
        print(mem)

    elif opcode == "MUL":
        result_addr = int(asm[ip][1])
        op1_addr = int(asm[ip][2])
        op2_addr = int(asm[ip][3])
        mem[result_addr] = mem[op1_addr] * mem[op2_addr]
        ip = ip +1

    elif opcode == "SUB":
        result_addr = int(asm[ip][1])
        op1_addr = int(asm[ip][2])
        op2_addr = int(asm[ip][3])
        mem[result_addr] = mem[op1_addr] - mem[op2_addr]
        ip += 1
 
    elif opcode == "DIV":
        result_addr = int(asm[ip][1])
        op1_addr = int(asm[ip][2])
        op2_addr = int(asm[ip][3])
        mem[result_addr] = mem[op1_addr] // mem[op2_addr]
        ip = ip +1

    elif opcode == "COP":
        print("cop")
        result_addr = int(asm[ip][1])
        op1_addr = int(asm[ip][2])
        mem[result_addr] = mem[op1_addr]
        ip = ip +1
        print(mem)

    elif opcode == "AFC":
        print("afc")
        result_addr = int(asm[ip][1])
        constant = int(asm[ip][2])
        mem[result_addr] = constant
        ip = ip +1
        print(mem)

    elif opcode == "JMP":
        jump_addr = int(asm[ip][1])
        ip = jump_addr

    elif opcode == "JMF":
        print("jmf")
        x_addr = int(asm[ip][1])
        jump_addr = int(asm[ip][2])
        if mem[x_addr] == 0:
            ip = jump_addr
        else:
            ip += 1
    elif opcode == "INF":
        x_addr = int(asm[ip][2])
        y_addr = int(asm[ip][3])
        result_addr = int(asm[ip][1])
        if mem[x_addr] < mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "SUP":
        x_addr = int(asm[ip][2])
        y_addr = int(asm[ip][3])
        result_addr = int(asm[ip][1])
        if mem[x_addr] > mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "EQU":
        x_addr = int(asm[ip][2])
        y_addr = int(asm[ip][3])
        result_addr = int(asm[ip][1])
        if mem[x_addr] == mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "BX":
        print("bx")
        return_a = int(asm[ip][1])
        ret_value = int(asm[ip][2])
        ip = mem[return_a]
        mem[return_a] = mem[ret_value]
        print(mem)
    elif opcode == "CALL":
        print("call")
        return_addr = int(asm[ip][2])
        func_addr = int(asm[ip][1])
        ip = func_addr
        print(mem)
    elif opcode == "PRI":
        value = mem[int(asm[ip][1])]
        print(value)
        ip += 1

    
    
print("final state \n")
print(mem)