asm = open("ASMCODE.asm").readlines()
asm = [x.split(" ") for x in asm]
mem = [0] * 1024
ip = 0
index = 0
#tableaux pour memoriser les decalages 
tab = [index]*1024
indret =0
#tableau pour memoriser les addresses de retour
ret = [indret]*1024

decalage = 0
addr_ret = 0
print(asm)

while ip < len(asm):
    opcode = asm[ip][0]

    if opcode == "ADD":
        result_addr = int(asm[ip][1])+decalage
        op1_addr = int(asm[ip][2])+decalage
        op2_addr = int(asm[ip][3])+decalage
        mem[result_addr] = mem[op1_addr] + mem[op2_addr]
        ip = ip +1

    elif opcode == "MUL":
        result_addr = int(asm[ip][1])+decalage
        op1_addr = int(asm[ip][2])+decalage
        op2_addr = int(asm[ip][3])+decalage
        mem[result_addr] = mem[op1_addr] * mem[op2_addr]
        ip = ip +1

    elif opcode == "SUB":
        result_addr = int(asm[ip][1])+decalage
        op1_addr = int(asm[ip][2])+decalage
        op2_addr = int(asm[ip][3])+decalage
        mem[result_addr] = mem[op1_addr] - mem[op2_addr]
        ip += 1
 
    elif opcode == "DIV":
        result_addr = int(asm[ip][1])+decalage
        op1_addr = int(asm[ip][2])+decalage
        op2_addr = int(asm[ip][3])+decalage
        mem[result_addr] = mem[op1_addr] // mem[op2_addr]
        ip = ip +1

    elif opcode == "COP":
        result_addr = int(asm[ip][1])+decalage
        op1_addr = int(asm[ip][2])+decalage
        mem[result_addr] = mem[op1_addr]
        ip = ip +1

    elif opcode == "AFC":
        result_addr = int(asm[ip][1])+decalage
        constant = int(asm[ip][2])
        mem[result_addr] = constant
        ip = ip +1

    elif opcode == "JMP":
        jump_addr = int(asm[ip][1])
        ip = jump_addr

    elif opcode == "JMF":
        x_addr = int(asm[ip][1])+decalage
        jump_addr = int(asm[ip][2])
        if mem[x_addr] == 0:
            ip = jump_addr
        else:
            ip += 1
    elif opcode == "INF":
        x_addr = int(asm[ip][2])+decalage
        y_addr = int(asm[ip][3])+decalage
        result_addr = int(asm[ip][1])+decalage
        if mem[x_addr] < mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "SUP":
        x_addr = int(asm[ip][2])+decalage
        y_addr = int(asm[ip][3])+decalage
        result_addr = int(asm[ip][1])+decalage
        if mem[x_addr] > mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "EQU":
        x_addr = int(asm[ip][2])+decalage
        y_addr = int(asm[ip][3])+decalage
        result_addr = int(asm[ip][1])+decalage
        if mem[x_addr] == mem[y_addr]:
            mem[result_addr] = 1
        else:
            mem[result_addr] = 0
        ip += 1
    elif opcode == "BX":
        
        return_a = int(asm[ip][1])+decalage
        ret_value = int(asm[ip][2])+decalage
        mem[return_a] = mem[ret_value]
        index-=1
        decalage = decalage- tab[index]
        indret-=1
        ip =ret[indret]
    
    elif opcode == "CALL":
        #addr_ret = int(asm[ip][3])+1
        addr_ret = ip+1
        decal_sing = int(asm[ip][2])
        tab[index] = decal_sing+1
        decalage = decalage +tab[index]
        index+=1
        ret[indret] = addr_ret
        indret+= 1
        func_addr = int(asm[ip][1])
        ip = func_addr

    elif opcode == "PRI":
        print("print")
        value = mem[int(asm[ip][1])]
        print(value)
        ip += 1

print("final state \n")
