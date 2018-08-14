#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//Hard coding for all available Pmod GPIOs
//Potential 24 Chip Input Pins: Gpio 78-101
//Pmod JA
#define JA1 78
#define JA2 79 
#define JA3 80 
#define JA4 81 
#define JA5 82 
#define JA6 83 
#define JA7 84 
#define JA8 85  
//Pmod JB
#define JB1 86
#define JB2 87
#define JB3 88
#define JB4 89
#define JB5 90
#define JB6 91
#define JB7 92
#define JB8 93
//Pmod JC
#define JC1 94
#define JC2 95
#define JC3 96
#define JC4 97
#define JC5 98
#define JC6 99
#define JC7 100
#define JC8 101

//Potential Chip Output Pins
//Pmod JD
#define JD1 102
#define JD2 103
#define JD3 104
#define JD4 105
#define JD5 106
#define JD6 107
#define JD7 108
#define JD8 109

//Pmod JE
#define JE1 13
#define JE2 10
#define JE3 11
#define JE4 12
#define JE5 0
#define JE6 9
#define JE7 14
#define JE8 15

#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO(x) TEMP(x)
#define TEMP(x) #x            //Stringfication
//middle macro for expansion of parameters because of usage of "#"

#define GPIO_DIR(x) TEMP1(x)
#define TEMP1(x) "/sys/class/gpio/gpio" #x"/direction"
#define DIR_OUT "out"
#define DIR_IN "in"

#define GPIO_VAL(x) TEMP2(x)
#define TEMP2(x) "/sys/class/gpio/gpio" #x"/value"

#define EXPORT(x) TEMP3(x)
#define TEMP3(x) write(fd, #x, sizeof(#x))

#define SET_DIR(x,y) do{          \
fd = open(GPIO_DIR(x), O_WRONLY); \
write(fd, y, sizeof(y));          \
close(fd);                        \
}while(0)
	
#define DELAY 10000
#define TEST_CYCLE 10

void WR_FILE(FILE *file, char *chip, int i){
	
   fprintf(file, "%s[%d]", "read", i);
   for(i = 0; i < TEST_CYCLE; i++)
	   fprintf(file, " %c", chip[i]);
   fprintf(file, "\n");

}

int main()
{
  int fd, fd_en[40], i;
  int count = 0;

  //Buffers for saving data read from pins
  char read0[TEST_CYCLE];
  char read1[TEST_CYCLE];
  char read2[TEST_CYCLE];
  char read3[TEST_CYCLE];
	char read4[TEST_CYCLE];
	char read5[TEST_CYCLE];
	char read6[TEST_CYCLE];
	char read7[TEST_CYCLE];
	char read8[TEST_CYCLE];
	char read9[TEST_CYCLE];
	char read_10[TEST_CYCLE];
	char read_11[TEST_CYCLE];
	char read_12[TEST_CYCLE];
	char read_13[TEST_CYCLE];
	char read_14[TEST_CYCLE];
	char read_15[TEST_CYCLE];

	//Buffers for vectors ready to send to the chip
  char input0[]={'0','1','0','1','0','1','0','1'};
  char input1[]={'0','1','0','1','0','1','0','1'};
  char input2[]={'0','1','0','1','0','1','0','1'};
  char input3[]={'0','1','0','1','0','1','0','1'};
  char input4[]={'0','1','0','1','0','1','0','1'};
  char input5[]={'0','1','0','1','0','1','0','1'};
  char input6[]={'0','1','0','1','0','1','0','1'};
  char input7[]={'0','1','0','1','0','1','0','1'};
  char input8[]={'0','1','0','1','0','1','0','1'};
  char input9[]={'0','1','0','1','0','1','0','1'};
  char input_10[]={'0','1','0','1','0','1','0','1'};
  char input_11[]={'0','1','0','1','0','1','0','1'};
  char input_12[]={'0','1','0','1','0','1','0','1'};
  char input_13[]={'0','1','0','1','0','1','0','1'};
  char input_14[]={'0','1','0','1','0','1','0','1'};
  char input_15[]={'0','1','0','1','0','1','0','1'};
  char input_16[]={'0','1','0','1','0','1','0','1'};
  char input_17[]={'0','1','0','1','0','1','0','1'};
  char input_18[]={'0','1','0','1','0','1','0','1'};
  char input_19[]={'0','1','0','1','0','1','0','1'};
  char input_20[]={'0','1','0','1','0','1','0','1'};
  char input_21[]={'0','1','0','1','0','1','0','1'};
  char input_22[]={'0','1','0','1','0','1','0','1'};
  char input_23[]={'0','1','0','1','0','1','0','1'};
		
  //Export All Pins
  fd = open(GPIO_EXPORT, O_WRONLY);
  EXPORT(JA1);
  EXPORT(JA2);
  EXPORT(JA3);
  EXPORT(JA4);
  EXPORT(JA5);
  EXPORT(JA6);
  EXPORT(JA7);
  EXPORT(JA8);
  EXPORT(JB1);
  EXPORT(JB2);
  EXPORT(JB3);
  EXPORT(JB4);
  EXPORT(JB5);
  EXPORT(JB6);
  EXPORT(JB7);
  EXPORT(JB8);
  EXPORT(JC1);
  EXPORT(JC2);
  EXPORT(JC3);
  EXPORT(JC4);
  EXPORT(JC5);
  EXPORT(JC6);
  EXPORT(JC7);
  EXPORT(JC8);
  EXPORT(JD1);
  EXPORT(JD2);
  EXPORT(JD3);
  EXPORT(JD4);
  EXPORT(JD5);
  EXPORT(JD6);
  EXPORT(JD7);
  EXPORT(JD8);
  EXPORT(JE1);
  EXPORT(JE2);
  EXPORT(JE3);
  EXPORT(JE4);
  EXPORT(JE5);
  EXPORT(JE6);
  EXPORT(JE7);
  EXPORT(JE8);
  close(fd);

//Set Output pins direction, default direction set as input
  SET_DIR(JA1, DIR_OUT);
  SET_DIR(JA2, DIR_OUT);
  SET_DIR(JA3, DIR_OUT);
  SET_DIR(JA4, DIR_OUT);
  SET_DIR(JA5, DIR_OUT);
  SET_DIR(JA6, DIR_OUT);
  SET_DIR(JA7, DIR_OUT);
  SET_DIR(JA8, DIR_OUT);
  SET_DIR(JB1, DIR_OUT);
  SET_DIR(JB2, DIR_OUT);
  SET_DIR(JB3, DIR_OUT);
  SET_DIR(JB4, DIR_OUT);
  SET_DIR(JB5, DIR_OUT);
  SET_DIR(JB6, DIR_OUT);
  SET_DIR(JB7, DIR_OUT);
  SET_DIR(JB8, DIR_OUT);
  SET_DIR(JC1, DIR_OUT);
  SET_DIR(JC2, DIR_OUT);
  SET_DIR(JC3, DIR_OUT);
  SET_DIR(JC4, DIR_OUT);
  SET_DIR(JA5, DIR_OUT);
  SET_DIR(JA6, DIR_OUT);
  SET_DIR(JA7, DIR_OUT);
  SET_DIR(JA8, DIR_OUT);

//Open all pins' value file, prepared for write into and read from it
  fd_en[0] = open(GPIO_VAL(JA1), O_WRONLY);
  fd_en[1] = open(GPIO_VAL(JA2), O_WRONLY);
  fd_en[2] = open(GPIO_VAL(JA3), O_WRONLY);
  fd_en[3] = open(GPIO_VAL(JA4), O_WRONLY);
  fd_en[4] = open(GPIO_VAL(JA5), O_WRONLY);
  fd_en[5] = open(GPIO_VAL(JA6), O_WRONLY);
  fd_en[6] = open(GPIO_VAL(JA7), O_WRONLY);
  fd_en[7] = open(GPIO_VAL(JA8), O_WRONLY);
  fd_en[8] = open(GPIO_VAL(JB1), O_WRONLY);
  fd_en[9] = open(GPIO_VAL(JB2), O_WRONLY);
  fd_en[10] = open(GPIO_VAL(JB3), O_WRONLY);
  fd_en[11] = open(GPIO_VAL(JB4), O_WRONLY);
  fd_en[12] = open(GPIO_VAL(JB5), O_WRONLY);
  fd_en[13] = open(GPIO_VAL(JB6), O_WRONLY);
  fd_en[14] = open(GPIO_VAL(JB7), O_WRONLY);
  fd_en[15] = open(GPIO_VAL(JB8), O_WRONLY);
  fd_en[16] = open(GPIO_VAL(JC1), O_WRONLY);
  fd_en[17] = open(GPIO_VAL(JC2), O_WRONLY);
  fd_en[18] = open(GPIO_VAL(JC3), O_WRONLY);
  fd_en[19] = open(GPIO_VAL(JC4), O_WRONLY);
  fd_en[20] = open(GPIO_VAL(JC5), O_WRONLY);
  fd_en[21] = open(GPIO_VAL(JC6), O_WRONLY);
  fd_en[22] = open(GPIO_VAL(JC7), O_WRONLY);
  fd_en[23] = open(GPIO_VAL(JC8), O_WRONLY);

  fd_en[24] = open(GPIO_VAL(JD1), O_RDONLY);
  fd_en[25] = open(GPIO_VAL(JD2), O_RDONLY);
  fd_en[26] = open(GPIO_VAL(JD3), O_RDONLY);
  fd_en[27] = open(GPIO_VAL(JD4), O_RDONLY);
  fd_en[28] = open(GPIO_VAL(JD5), O_RDONLY);
  fd_en[29] = open(GPIO_VAL(JD6), O_RDONLY);
  fd_en[30] = open(GPIO_VAL(JD7), O_RDONLY);
  fd_en[31] = open(GPIO_VAL(JD8), O_RDONLY);
  fd_en[32] = open(GPIO_VAL(JE1), O_RDONLY);
  fd_en[33] = open(GPIO_VAL(JE2), O_RDONLY);
  fd_en[34] = open(GPIO_VAL(JE3), O_RDONLY);
  fd_en[35] = open(GPIO_VAL(JE4), O_RDONLY);
  fd_en[36] = open(GPIO_VAL(JE5), O_RDONLY);
  fd_en[37] = open(GPIO_VAL(JE6), O_RDONLY);
  fd_en[38] = open(GPIO_VAL(JE7), O_RDONLY);
  fd_en[39] = open(GPIO_VAL(JE8), O_RDONLY);


  printf("Start testing: \n");
	/************************************READ/WRIET_TO_GPIO************************************/
  while(count < TEST_CYCLE){
  //output signals to EMIO
//       write (fd_en[0], input0 + count, 1);
//       write (fd_en[1], input1 + count, 1);
//       write (fd_en[2], input2 + count, 1);
//       write (fd_en[3], input3 + count, 1);
//       write (fd_en[4], input4 + count, 1);
//       write (fd_en[5], input5 + count, 1);
//       write (fd_en[6], input6 + count, 1);
//       write (fd_en[7], input7 + count, 1);
//       write (fd_en[8], input8 + count, 1);
//       write (fd_en[9], input9 + count, 1);
//       write (fd_en[10], input_10 + count, 1);
//       write (fd_en[11], input_11 + count, 1);
//       write (fd_en[12], input_12 + count, 1);
//       write (fd_en[13], input_13 + count, 1);
//       write (fd_en[14], input_14 + count, 1);
//       write (fd_en[15], input_15 + count, 1);
//       write (fd_en[16], input_16 + count, 1);
//       write (fd_en[17], input_17 + count, 1);
//       write (fd_en[18], input_18 + count, 1);
//       write (fd_en[19], input_19 + count, 1);
//       write (fd_en[20], input_20 + count, 1);
//       write (fd_en[21], input_21 + count, 1);
//       write (fd_en[22], input_22 + count, 1);
//       write (fd_en[23], input_23 + count, 1);


    for(i=0;i<DELAY;i++);          //setting the system clock

 // read signals from EMIO
//       read(fd_en[24], read0 + count, 1);
//       read(fd_en[25], read1 + count, 1);
//       read(fd_en[26], read2 + count, 1);
//       read(fd_en[27], read3 + count, 1);
//       read(fd_en[28], read4 + count, 1);
//       read(fd_en[29], read5 + count, 1);
//       read(fd_en[30], read6 + count, 1);
//       read(fd_en[31], read7 + count, 1);
//       read(fd_en[32], read8 + count, 1);
//       read(fd_en[33], read9 + count, 1);
//       read(fd_en[34], read_10 + count, 1);
//       read(fd_en[35], read_11 + count, 1);
//       read(fd_en[36], read_12 + count, 1);
//       read(fd_en[37], read_13 + count, 1);
//       read(fd_en[38], read_14 + count, 1);
//       read(fd_en[39], read_15 + count, 1);

//Reset the file cursor for those input pins
//       lseek(fd_en[24], 0, SEEK_SET);
//       lseek(fd_en[25], 0, SEEK_SET);
//       lseek(fd_en[26], 0, SEEK_SET);
//       lseek(fd_en[27], 0, SEEK_SET);
//       lseek(fd_en[28], 0, SEEK_SET);
//       lseek(fd_en[29], 0, SEEK_SET);
//       lseek(fd_en[30], 0, SEEK_SET);
//       lseek(fd_en[31], 0, SEEK_SET);
//       lseek(fd_en[32], 0, SEEK_SET);
//       lseek(fd_en[33], 0, SEEK_SET);
//       lseek(fd_en[34], 0, SEEK_SET);
//       lseek(fd_en[35], 0, SEEK_SET);
//       lseek(fd_en[36], 0, SEEK_SET);
//       lseek(fd_en[37], 0, SEEK_SET);
//       lseek(fd_en[38], 0, SEEK_SET);
//       lseek(fd_en[39], 0, SEEK_SET);

	 count++;
  }
  printf("Test finish! Check result.txt file\n");

  for(i=0; i< 40; i++)
    close(fd_en[i]);
	   
//Write the result vectors into a text file.
  FILE *fpWrite = fopen("result.txt","w");   
//    WR_FILE(fpWrite, read0, 0);
//    WR_FILE(fpWrite, read1, 1);
//    WR_FILE(fpWrite, read2, 2);
//    WR_FILE(fpWrite, read3, 3);
//    WR_FILE(fpWrite, read4, 4);
//    WR_FILE(fpWrite, read5, 5);
//    WR_FILE(fpWrite, read6, 6);
//    WR_FILE(fpWrite, read7, 7);
//    WR_FILE(fpWrite, read8, 8);
//    WR_FILE(fpWrite, read9, 9);
//    WR_FILE(fpWrite, read_10, 10);
//    WR_FILE(fpWrite, read_11, 11);
//    WR_FILE(fpWrite, read_12, 12);
//    WR_FILE(fpWrite, read_13, 13);
//    WR_FILE(fpWrite, read_14, 14);
//    WR_FILE(fpWrite, read_10, 15);
  fclose(fpWrite);
  return 0;
}
