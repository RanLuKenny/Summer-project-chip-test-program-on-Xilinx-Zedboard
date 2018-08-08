import os 
import fileinput
import re

def def_signal():
  print('please enter the number of chip inputs,smaller than 24 bits:\n')
  input_num = input()
  while input_num > 24:
    print('Number of inputs cannot be larger than 24 bits!:\n')
    input_num = input()
  print('please enter the number of chip outputs, smaller than 16 bits:\n')
  output_num = input()
  while output_num > 16:
    print('Number of outputs cannot be larger than 16 bits!:\n')
    output_num = input()
  print('please set the clock frequency <DELAY = 10000000 equals clock cycle = 1s>:\n')
  delay = input()
  print('please enter the test cycle value (the length of testing vector):\n')
  test_cycle = input()
  print('input_num :',input_num,'output_num :',output_num,'DELAY:', delay,'TEST_CYCLE:',test_cycle)
  return input_num, output_num, delay, test_cycle

def read_input_signal(input_index):
  f = open('data.txt', 'r')
  data = f.readlines()
  data_list = []
  global numlist  
  for line in data:
    if data.index(line) == input_index:
      numlist = re.sub(r'\D','',line)
  data_list=map(int,str(numlist))
  if input_index > 9:
    data_list.pop(0)
    data_list.pop(1)
  else:
    data_list.pop(0)
#  print(data_list)
  B='{"'
  for item in data_list:
    B +=str(item)
  B = B[:-1]
  B += '"};'
#  print(B)
  f.close  
  return B


def change_parameters(file, delay, test_cycle):
  f1=open(file,'r')
  new_f=open('%s.bak' % file,'w')
  for line in f1:
    if '#define DELAY' in line:
      line = '#define DELAY '+ '%s' % delay + '\n'
    if '#define TEST_CYCLE' in line:
      line = '#define TEST_CYCLE '+ '%s' % test_cycle + '\n'
    new_f.write(line)
  new_f.close()
  f1.close()
  os.remove(file)
  os.rename("%s.bak" % file, file)
  return;
  
def setting_input_signal(line_index, input_val):
  f = open('test.c', 'r')
  data = f.readlines()
  data_list = []  
  for line in data:
    if data.index(line) == line_index-1:
      data_list.append(line.replace("{'0','1','0','1','0','1','0','1'};",'%s' % input_val))
    else:
      data_list.append(line)
  f = open('test.c', 'w')
  f.writelines(data_list)  
  f.flush()
  f.close  
  return;	  
  
def setting_sig(line_index):
  f = open('test.c', 'r')
  data = f.readlines()
  data_list = []  
  for line in data:
    if data.index(line) == line_index-1:
      data_list.append(line.replace('//',' '))
    else:
      data_list.append(line)
  f = open('test.c', 'w')
  f.writelines(data_list)  
  f.flush()
  f.close  
  return;	

       
def excution_func():
  print('Editing c template file.')
  os.system('cp summer_final.c test.c')
  input_num, output_num, delay, test_cycle = def_signal()
# edit parameters
  change_parameters('test.c',delay, test_cycle)
  input_num=int(input_num)
  output_num=int(output_num) 
# edit inputx[]
  base_input_line_index = 116
  for i in range(input_num):
    input_val=read_input_signal(i)
    line_index = base_input_line_index+i
    setting_input_signal(line_index, input_val)    
# edit Write 
  orig_line_index_w = 259 
  for i in range(input_num):
    line_index_w = orig_line_index_w+i
    setting_sig(line_index_w)
# edit Read  
  orig_line_index_r = 288 
  for i in range(output_num):
    line_index_r = orig_line_index_r+i
    setting_sig(line_index_r)  
# edit lseek 
  orig_line_index_o = 306
  for i in range(output_num):
    line_index_o = orig_line_index_o+i
    setting_sig(line_index_o)
# edit WR_FILE
  orig_line_index_i=332      
  for i in range(output_num):
    #print(i,line_index)
    line_index_i = orig_line_index_i+i
    setting_sig(line_index_i)   
  return;

#read_input() 
#change_input_array('test.c','input_4','&s_out_0')
#def_signal()
excution_func()
#change_parameters('test.c',5,8)
#setting_in()
#setting_out()



