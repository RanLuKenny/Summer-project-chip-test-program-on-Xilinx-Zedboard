#python file for vcd imformation extraction
import collections

#python file for vcd imformation extraction
vcd_file_name = 'top_module_tb.vcd'
#vcd_file_name = 'tb.vcd'

input_ports = []
output_ports = []

f = open(vcd_file_name)
file_lines = []
line = f.readline()
while line:
    line = f.readline()
    remove = line.strip('\t').strip('\n')
    if '$var' == remove[0:4]:
        if remove[5:8]=='reg':
            str0 = remove[13 : len(remove)-5]
            if ':' in str0:
                if str0 not in input_ports and str0 not in output_ports:
                    input_ports.append(str0)
            elif '[' not in str0:
                if str0 not in input_ports and str0 not in output_ports:
                    input_ports.append(str0)
                    
        elif remove[5:9] == 'wire':
            str1 = remove[14 : len(remove)-5]
            if ':' in str1:
                if str1 not in output_ports and str1 not in input_ports:
                    output_ports.append(str1)
            elif '[' not in str1:
                if str1 not in output_ports and str1 not in input_ports:
                    output_ports.append(str1)
f.close()

ports = input_ports + output_ports

ports_adjust = []
# port_and_sign = {}
# muil_but_sign = {}
#
# output_sequence = {}
port_and_sign = collections.OrderedDict()
muil_but_sign = collections.OrderedDict()

#input ports_dic && output ports dic
input_ports_dic = collections.OrderedDict()
output_ports_dic = collections.OrderedDict()

output_sequence = collections.OrderedDict()
output_sequence_new = collections.OrderedDict()

wf = open('data.txt', 'w')

def handle_mul_bus(port_name, line):
    if ':' in port_name:
        if port_name in line:
            position = line.index(port_name)
            sign = line[position - 2]
            muil_but_sign[port_name] = sign
            # print(muil_but_sign)
            # muil_but_sign.setdefault(port_name, sign)
    else:
        if port_name in line:
            position = line.index(port_name)
            sign = line[position - 2]
            port_and_sign[port_name] = sign
            # print(port_and_sign)
            # port_and_sign.setdefault(port_name, sign)
pass

def array(strings, mul_ports): #convert the bus or port
    if ':' in strings:
        pos = strings.index(':')
        number = int(strings[pos - 1])
        for i in range(number+1):
            temp = strings[0: pos - 1] + str(i) + ']'
            mul_ports.append(temp)
    else:
        mul_ports.append(strings)
pass

def get_wavetime(strings): #timeslot
    if strings[0] == "#":
        print(strings[1:])
pass

def get_ports(port_name, line): # match the sign and port
    if port_name in line:
        position = line.index(port_name)
        sign = line[position-2]
        port_and_sign[port_name] = sign
        return 0
pass

def ini_sequence():
    for port in ports:
        output_sequence[port] = ''
pass

def store_lines(): #detect #
    f = open(vcd_file_name)
    file_lines = []
    line = f.readline()
    while line:
        line = f.readline()
        remove = line.strip('\t').strip('\n')
        if remove != '':
            file_lines.append(remove)
    f.close()
    return file_lines
pass

def detect_signal_value(f):
    for line in f:
        sub_line = []
        if line[0] == '#':
            for iter in range(f.index(line)+1, len(f) - 1):
                if f[iter][0] == '#':
                    break
                else:
                    sub_line.append(f[iter])
            #for port in ports_adjust:
            for port0 in port_and_sign: ### get the value
                match_signal_value(sub_line, port0)
            for port1 in muil_but_sign:
                mul_match_signal_value(sub_line, port1)
pass

def get_bus_width(string):
    return int(string[string.index(':')-1])
pass

def match_signal_value(s_l, port):
     n = 0
     #temp = ''
     for element in s_l:
        #print(s_l)
        if(element[1] == port_and_sign[port]):
            n = 1
            output_sequence[port] += ' ' + element[0]
        else:
            continue
     if n == 0:
        S = output_sequence[port]
        output_sequence[port] += ' ' + S[len(output_sequence[port])-1]
pass

def mul_match_signal_value(s_l, port):
    n = 0
    for element in s_l:
        if (element[0] == 'b'):
            if(element[len(element)-1] == muil_but_sign[port]):
                # print(element[len(element)-1])
                n = 1
                output_sequence[port] += ' ' + element[1:len(element)-2]
        else:
            continue
    if n == 0:
        S = output_sequence[port]
        temp = S.split(' ')
        # print(temp)
        # temp = temp.remove('')
        # print(S)
        output_sequence[port] += ' ' + str(temp[len(temp) - 1])#########
pass#

def get_size(string):
    if ':' in string:
        size = int(string[string.index(':')-1]) + 1
        return size
    else:
        return 0
pass

def add_zero(binary, size):
    while(len(binary) <= size):
        binary = '0' + binary
    return binary
pass

def bin_to_dec(bin):
    for ele in bin:
        if ele != '0' and ele !='1':
            return 'x'
    temp = int(bin, 2)
    return str(temp)
pass

def convert(dic, dic_store):
    for key in dic:
        if ':' in key:
            number = int(key.index(':') - 1)
            iteration = str(key[number])
            # print(iteration)####iteration + 1
        else:
            dic_store[key] = dic[key]
            continue
        value = dic[key].split(' ')
        for ele in value:####value
            if ele == '':
                value.remove(ele)
        for i in range(0, int(iteration) + 1):
            string_value = ''
            string = key[0: number] + str(i) + ']'
            for ele in value:
                string_value += ' ' + ele[int(iteration) - i]
            # print(string)
            # print(string_value)
            dic_store[string] = string_value
pass

if __name__ == '__main__':

    ini_sequence()

    f = open(vcd_file_name)
    lines = f.readline()
    while lines:
           lines = f.readline()
           # for port in port_and_sign :
           #     get_ports(port, lines) # B[3] B[2] B[1] B[0]
           for port in ports:
               # print(port)
               handle_mul_bus(port, lines)  # A [n:0]

    detect_signal_value(store_lines())
    # print(output_sequence)

    for key in output_sequence:
        store = ''
        value = (output_sequence[key]).split(' ')
        value.remove('')
        #print(value)#

        if ':' in key:
            if key != '':
                size = abs(int(key[key.index(':') - 1]) - int(key[key.index(':') + 1])) + 1
                for element in value:
                    # while len(element) < size:
                    #     element = '0' + element
                    if len(element) < size:
                        element = (size - len(element))*'0' + element
                    store += ' ' + element
                        # string.insert(0, '0')
                output_sequence[key] = store + ' '

    for key in output_sequence:
        value = output_sequence[key].split(' ')
        # print(value)
        # value.remove('')
        # print(value)
        empty_string = ''
        for ele in value:
            if ele != '':
                # empty_string += bin_to_dec(ele) + ' ' ###use decimal
                empty_string += ele + ' ' ###use binary
                # print(empty_string)
        output_sequence[key] = ' ' + empty_string
        # print(empty_string)
    # print(output_sequence)
        # output_sequence[key] = store
    convert(output_sequence, output_sequence_new)

    for key in output_sequence_new:
        temp = key.replace(' ', '') + output_sequence_new[key]
        print(temp)
        wf.write(temp + '\n')
		
size = ((len(output_sequence_new[input_ports[0]]) - 1) / 2)
print('The simulation ends at T=' + str(size - 1))
wf.write('The simulation ends at T=' + str(size))
