#include<stdio.h> /* printf,fgets */
#include<stdlib.h> /* strtod */
#include<ctype.h> /* isspace */
#include<math.h> /* floor */

void readInt(unsigned long long int *integer);
void validateCard();

int main(void)
{
  validateCard();
  return 0;
}


void readInt(unsigned long long int *integer){
  double card_number;
  char buffer[500],*endptr;
  int loop=1;
  do
    {
      printf("Enter card number: ");
      fgets(buffer,sizeof(buffer),stdin);
      card_number = strtod(buffer, &endptr);
      if(buffer == endptr) continue;
      else if( floor(card_number) != card_number ) continue;
      while(isspace((unsigned char) *endptr)) endptr++;
      if( *endptr != '\0' ) continue;
      loop=0;
    } 
  while(loop);
  *integer = (unsigned long long int) card_number;
}
void validateCard(){
  unsigned long long int card_number;
  readInt(&card_number);
  unsigned long long int copy = card_number;
  int sum=0,i=1,count=0,number;

  while(copy>0){
    number = i*(copy%10);
    while(number>0){
      sum += number%10;
      number -= number%10;
      number /= 10;
    }
    copy -= copy%10;
    copy /= 10;
    i = (i%2) + 1;
    count++;
  }
  if(sum%10==0){
    if(count == 13 || count == 16){
      while(card_number>10){
	card_number /= 10;
      }
      if(card_number==4){
	printf("VISA\n");
      }
    }else if(count == 15){
      while(card_number>100){
	card_number /= 10;
      }
      if(card_number==34 || card_number==37){
	printf("AMEX\n");
      }
    }else if(count == 16){
      while(card_number>100){
	card_number /= 10;
      }
      if(card_number==51 || card_number==52 || card_number==53 || card_number==54 || card_number==55){
	printf("MASTERCARD\n");
      }
    }else{
      printf("INVALID\n");
    }
  }else{
    printf("INVALID\n");
  }
}
