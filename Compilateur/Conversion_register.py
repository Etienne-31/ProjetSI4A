# Lecture des instructions depuis le fichier
asm = open("ASMCODE.asm").readlines()
asm = [x.strip().split() for x in asm]

# Initialisation des registres
registres = [None] * 16

# Initialisation de la liste des nouvelles instructions
new_asm = []

# Parcours de toutes les instructions
for i, instr in enumerate(asm):
    opcode = instr[0]
    
    if opcode == "AFC":
        # Recherche d'un registre libre pour stocker la valeur
        reg = registres.index(None)
        if reg == -1:
            raise Exception("Pas de registre libre pour l'instruction %d" % i)

        # Stockage de la valeur dans le nouveau registre
        val = int(instr[2])
        new_asm.append(["AFC", str(reg), str(val)])

        # Stockage de la valeur à l'adresse spécifiée
        addr = int(instr[1])
        new_asm.append(["STORE", str(addr), str(reg)])

        # Attribution du registre utilisé
        registres[reg] = addr

    else:
        # Copie de l'instruction telle quelle
        new_asm.append(instr)

# Écriture des nouvelles instructions dans le fichier
with open("ASMCODE_NEW.asm", "w") as file:
    for instr in new_asm:
        file.write(" ".join(instr) + "\n")
