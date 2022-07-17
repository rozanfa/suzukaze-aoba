import sys

if len(sys.argv) != 2:
    print("Usage: python3 interpreter.py <file>")
    exit(1)

variables = {}
RED = "\033[1;31m"
NORMAL = "\033[0m"
ORANGE = "\033[93m"

file = open(sys.argv[1], "r")
code = file.read()
code = code.split("\n")
finish = False
length = len(code)


def print_error(line):
    print(RED + "Error: " + ORANGE + "Line " + str(line) + ": " + code[line - 1] + NORMAL)
    exit(1)

pointer = 0
while pointer < length and not finish:
    line = code[pointer].split()
    len_line = len(line)
    i = 0

    if len_line == 0:
        pointer += 1
        continue
    if (line[i] == "ono"):
        i += 1
        while i < len_line:
            variables[line[i]] = None
            i += 1
    elif (line[i] == "tambah"):
        try :
            variables[line[i+1]] += 1
        except:
            print_error(pointer + 1)
    elif (line[i] == "kurang"):
        try :
            variables[line[i+1]] -= 1
        except:
            print_error(pointer + 1)
    elif (line[i] == "tulis"):
        i += 1
        try :
            print(variables[line[i]])
        except :
            print_error(pointer + 1)
    elif (line[i] == "woco"):
        i += 1
        variables[line[i]] = input()
        try :
            variables[line[i]] = int(variables[line[i]])
        except:
            pass
    elif (line[i] == "wocokalimat"):
        variables[line[1:]] = input()
    elif (line[i] == "lungo"):
        pointer = int(line[1]) - 1
        continue
    elif (line[i] == "kalo"):
        var1 = line[1]
        condition = line[2]
        var2 = line[3]
        status = False
        if (condition == "=="):
            if (variables[var1] == int(var2)):
                status = True
        elif (condition == "!="):
            if (variables[var1] != int(var2)):
                status = True
        elif (condition == ">"):
            if (variables[var1] > int(var2)):
                status = True
        elif (condition == "<"):
            if (variables[var1] < int(var2)):
                status = True
        elif (condition == ">="):
            if (variables[var1] >= int(var2)):
                status = True
        elif (condition == "<="):
            if (variables[var1] <= int(var2)):
                status = True
        if (status):
            if (line[4] == "lungo"):
                pointer = int(line[5]) - 1
                continue
            else :
                print_error(pointer + 1)



    else :
        if (line[i] in variables):
            try :
                if (line[i + 1] == "iku"):
                    if (line[i + 2] == "tulisan"):
                        variables[line[i]] = " ".join(line[3:])
                    elif (line[i + 2] == "angka"):
                        variables[line[i]] = int(line[3])
                    else :
                        print_error(pointer + 1)
            except :
                print_error(pointer + 1)


        else :
            print_error(pointer + 1)
                
    pointer += 1