
def find_free_register(used_registers):
    for i in range(16):
        if i not in used_registers:
           # used_registers.add(i)
            return i
    return None

def hexa(nb):
    if nb>15:
        return hex(nb)[2:]
    else : 
        var=str(hex(nb))
        return var[:1]+var[2:]
    
def transform_instructions(file_path):
    with open(file_path, 'r') as file:
        asm_code = file.readlines()
    valeur_saut=[0]*5
    ind=0
    transformed_code = []
    used_registers = set()
    ip =0
    jumps_positions = [0]*5  # Liste pour stocker les addresses de saut 
    val =0
    for line in asm_code:
        instruction = line.strip().split()

        if instruction[0] == 'JMF':
            jumps_positions[ind]= int(instruction[2])
            #print(jumps_positions[ind])
            ind=ind+1
        elif instruction[0] == 'JMP' :
            jumps_positions[ind]= int(instruction[1])
            #print(jumps_positions[ind])
            ind=ind+1
        ip += 1
    
    print(jumps_positions)
    ip = 0  #
    ind=0
    nb_pointeur=0
    ipn=0
    for line in asm_code:
        instruction = line.strip().split()
        if len(instruction) == 3 and instruction[0] == 'AFC':
            ip=ip+1
            ipn=ipn+2
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1
            value = int(instruction[2])
            register = find_free_register(used_registers)

            if register is None:
                print("Erreur : Pas de registre libre disponible !")
                return

            transformed_code.append(f'x"02{hexa(register)}{hexa(value)}00", --AFC {register} {value}')
            transformed_code.append(f'x"08{hexa(int(instruction[1]))}{hexa(register)}00", --STORE {instruction[1]} {register}')
            
            #used_registers.add(register)
        elif instruction[0] == 'COP':
            ip=ip+1
            ipn=ipn+2
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1

            register = find_free_register(used_registers)
            transformed_code.append(f'x"07{hexa(register)}{hexa(int(instruction[2]))}00", --LOAD {register} {instruction[2]}')
            transformed_code.append(f'x"08{hexa(int(instruction[1]))}{hexa(register)}00", --STORE {instruction[1]} {register}')
            
            
        elif instruction[0] == 'ADD':
            ip=ip+1
            ipn=ipn+4
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1
            register1 = find_free_register(used_registers)
            used_registers.add(register1)
            register2 = find_free_register(used_registers)
            used_registers.add(register2)
            register3 = find_free_register(used_registers)
            used_registers.add(register3)        
            transformed_code.append(f'x"07{hexa(register1)}{hexa(int(instruction[2]))}00", --LOAD {register1} {instruction[2]}')
            transformed_code.append(f'x"07{hexa(register2)}{hexa(int(instruction[3]))}00", --LOAD {register2} {instruction[3]}')
            transformed_code.append(f'x"03{hexa(register3)}{hexa(register1)}{hexa(register2)}", --ADD {register3} {register1} {register2}')
            transformed_code.append(f'x"08{hexa(int(instruction[1]))}{hexa(register3)}00", --STORE {instruction[1]} {register3}')
            used_registers.remove(register1)
            used_registers.remove(register2)
            used_registers.remove(register3)
            
            
        elif instruction[0] == 'SUB':
            ip=ip+1
            ipn=ipn+4
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1

            register1 = find_free_register(used_registers)
            used_registers.add(register1)
            register2 = find_free_register(used_registers)
            used_registers.add(register2)
            register3 = find_free_register(used_registers)
            used_registers.add(register3)        
            transformed_code.append(f'x"07{hexa(register1)}{hexa(int(instruction[2]))}00", --LOAD {register1} {instruction[2]}')
            transformed_code.append(f'x"07{hexa(register2)}{hexa(int(instruction[3]))}00", --LOAD {register2} {instruction[3]}')
            transformed_code.append(f'x"04{hexa(register3)}{hexa(register1)}{hexa(register2)}", --SUB {register3} {register1} {register2}')
            transformed_code.append(f'x"08{hexa(int(instruction[1]))}{hexa(register3)}00", --STORE {instruction[1]} {register3}')
            used_registers.remove(register1)
            used_registers.remove(register2)
            used_registers.remove(register3)
            
        elif instruction[0] =='INF':
            ip=ip+1
            ipn=ipn+3
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1

            register1 = find_free_register(used_registers)
            used_registers.add(register1)
            register2 = find_free_register(used_registers)
            used_registers.add(register2)
            register3 = find_free_register(used_registers)
            used_registers.add(register3)        
            transformed_code.append(f'x"07{hexa(register1)}{hexa(int(instruction[2]))}00", --LOAD {register1} {instruction[2]}')
            transformed_code.append(f'x"07{hexa(register2)}{hexa(int(instruction[3]))}00", --LOAD {register2} {instruction[3]}')
            transformed_code.append(f'x"0C{hexa(register3)}{hexa(register1)}{hexa(register2)}", --INF {register3} {register1} {register2}')
            used_registers.remove(register1)
            used_registers.remove(register2)
            used_registers.remove(register3)
            
        elif instruction[0] == 'JMF':
            ip=ip+1
            ipn=ipn+1
            register = find_free_register(used_registers)
            transformed_code.append(f'x"0B{hexa(int(instruction[2]))}{hexa(int(instruction[1]))}00", --JMF {instruction[2]}')
            
        
        elif instruction[0] == 'JMP':
            ip=ip+1
            ipn=ipn+1
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1
            register = find_free_register(used_registers)
            transformed_code.append(f'x"0A{hexa(int(instruction[1]))}0000", --JMP {instruction[1]}')
            
        else:
            ip=ip+1
            ipn=ipn+1
            while ip ==  jumps_positions[ind]:
                valeur_saut[nb_pointeur] = ipn
                #print(valeur_saut[nb_pointeur])
                nb_pointeur=nb_pointeur+1
                ind=ind+1
            transformed_code.append(line.strip())
            
    nb_pointeur = 0
    print(valeur_saut)
    for i, line in enumerate(transformed_code):
        if "--JMF" in line:
            transformed_code[i] = f'x"0B{hexa(valeur_saut[nb_pointeur])}0000", --JMF {valeur_saut[nb_pointeur]}'
            nb_pointeur=nb_pointeur+1
        elif "--JMP" in line:
            transformed_code[i] = f'x"0A{hexa(valeur_saut[nb_pointeur])}0000", --JMP {valeur_saut[nb_pointeur]} '
            nb_pointeur=nb_pointeur+1    
    return transformed_code

    

# Exemple d'utilisation
file_path = 'ASMCODE.asm'
transformed_code = transform_instructions(file_path)

with open(file_path, "w") as f:
    for line in transformed_code :
        f.writelines(line+ '\n')
for line in transformed_code:
   print(line)
