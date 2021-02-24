/******************************************************************************

Programming Class Assesment.

The program below is developed to help bank employes and customers manage the four digit PIN code on an ATM. It is assumed that the default PIN code is '1234'. 

The program first presents the user with four option to choose 
(1) verify the PIN (2) change the PIN (3) Display the number of times PIN was entered Successfully and Incorrectly (4) Exit Program.

(1)VerificationL:- The counters are updated after every verification and disapproval.
(2) The PIN first asks to enter the old PIN and if it is correct then only allows the user to change the value. and then updates the PIN value.
(3) The counter updated during 1st option is helped to display the number of times the PIN was entered right or wrong.
(4) Ends the program

IDE :- repl.it 

Author:- Khushboo Subramanium Jayan

Dated:- 22/11/2020

*******************************************************************************/

#include <stdio.h>
#define SIZE 4              //constant SIZE has a valiue 4

int main()
{
  int end;
  int choice, pinValueOne, pinValueTwo;
  int i, j;
  char pinOne[4],  pinTwo[4];
  char pin[4]={'1','2','3','4'};        //consider 1234 as default PIN
  char verify[4];
  int correct=0;
  int wrong=0;
  
  

  end=1;

  printf("Class Assesment\n\n\n");
  printf("ATM Machine Program\n\n\n");
  printf("Select one of the options below\n\n");

   while (end==1)     //execute the while loop while end==1
    {
      int counter=0;
      int character=0;
      int ver=0;
     

        printf("(1) Enter and Verify the PIN\n");
        printf("(2) Change the PIN\n");
        printf("(3) Display the number of times the PIN has been entered \n(i) Successfully and (ii) Incorrectly\n");
        printf("(4) Exit program\n");

        printf("\n\nChoose an option\n");
        scanf(" %d",&choice);         //asks the user to input a choice
        
        switch(choice)                //execute the case with respective to the choice entered
        {
          //Case 1 is true when user enters 1 as a choice when asked for input. 

          case 1:
          {
              printf("Enter and verify the PIN\n");        
                for(i=0; i<SIZE; i++)
                {
                  scanf(" %c", &verify[i]);     //accepts the elements one by one and saves in a character array
                } //end for

                for(i=0; i < SIZE; i++)
                {
                  if (verify[i]>='0' && verify[i]<='9')     //check if the entered value is between 0-9
                  {
                    if(verify[i]==pin[i])                  //if the entered value is equal to the PIN vallue increment ver
                    {             
                      ver++;                                 //use ver as a counter and increment when the elements in both the entered and original PIN values are equal.  
                    }            
                  }     //end if statement
                }    //end for loop

              for(i=0; i < SIZE; i++)
              { 
                if (!(verify[i]>='0' && verify[i]<='9'))      //statement if the input is anything other than numbers between 0-9
                {
                  character++;                          //use character as a counter and increment when the elements in the array is not an integer
                }   //end if statement
              }  //end for loop
              if  (character!=0)           
              {
                printf("\n\nInvalid input please enter a valid integer between 0-9\n\n");   //request to enter a valid integer
                break;
              }   //end if statement
          
              if(ver==4)        //if all the four entered digits are equal to PIN value then print PIN verified 
              {
                 printf("\n\nPIN value verified\n\n");
                correct++;            //use correct as a counter to enter the number of times correct PIN was entered      
                //break;
              }    //end if statement
              else               //if even one element in the array is mismatched print PIN's unmatched
              {
                printf("\n\nPIN's unmatched\n\n");
                wrong++;    //use wrong as a counter to enter the number of times wrong PIN was entered
                break;
              }   //end else statement
            break;    
          }         //end of case 1
          
          //Case2 is true when user enters 2 as a choice when asked for input. 
          
          case 2:
          {

                printf("\n\nEnter a four digit PIN Value\n");
                for(i=0; i<SIZE; i++)
                {
                  scanf(" %c",&pinOne[i]);    //ask the user to enter new PIN and save the elements in a character array 
                }     //end for loop
          
                printf("\n\nRe-enter the four digit PIN value\n");
                for(i=0; i<SIZE; i++)
                {
                  scanf(" %c",&pinTwo[i]);    //ask the user to re-enter the new PIN and save the elements in a character array 
                }   //end for loop
          
                for(i=0; i < SIZE; i++)
                {
                  //check if the elements in both the character arrays are between 0-9 or not if yes then enter the if statement
                  if ((pinOne[i]>='0' && pinOne[i]<='9') && (pinTwo[i]>='0' && pinTwo[i]<='9'))
                  {
                    //check if both the arrays contain same digits or not if yes then enter the if statement              
                      if( pinOne[i] == pinTwo[i])  
                      {             
                         counter= counter+1;    //increment the counter if the elements are equal.
                      }   //end if statement
                      else
                      {
                          printf("\n\nPIN's unmatched\n\n");    //if the values in the array differ print PIN's unmatched 
                          break;    
                      }   //end else statement
                 }    //end if statement
                }     //end for loop
          
                if(counter==4)
                {
                  printf("\n\nPIN value successfully changed\n\n");
                  for(i=0; i<SIZE; i++)
                  {
                    pin[i] = pinTwo[i];       //assign the successfully changed value 
                  }   //end for loop
                
                }     //end if statement  
              
            

            

            for(i=0; i < SIZE; i++)
              { 
                  if ((!(pinOne[i]>='0' && pinOne[i]<='9'))|| (!(pinTwo[i]>='0' && pinTwo[i]<='9')))    
                  //if the user enters any element other than numbers between 0-9 enter the if statement

                  {
                      character++;        //increment character variable 
                  }     //end if statement
               }    //end for loop
                  if  (character!=0)            //is there is even a single character or special input enter the if statement
                  {
                     printf("\n\nInvalid input please enter a valid integer between 0-9\n\n");    //
                     break;
                  }   //end if statement
              break;
           }    //end of case 2

          //Case 3 is true when user enters 3 as a choice when asked for input.

          case 3:
          {
            printf("\nThe number of times you entered correct PIN is : %d\n\n", correct);   //prints the number of times correct PIN value was entered

            printf("The number of times you entered wrong PIN is : %d\n\n", wrong);         //prints the number of times wrong PIN value was entered.
            
            break;

          }   //end case 3

          //Case 4 is true when user enters 4 as a choice when asked for input.
          
          case 4:
          {
            end = 0;            //sets the integer end value to zero resulting the program to end
            break;
          }     //end case 4
          default:
          {
            printf("\nPlease choose a valid option between 0-4\n\n");       
            //prints the respective statement if none of the given case is satisfied
            break;
          }   //end of default statement
      
      
        }
      

      }
  return 0;
}
