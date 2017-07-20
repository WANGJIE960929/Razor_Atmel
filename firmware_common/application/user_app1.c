/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */



/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;
/* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
  LCDCommand(LCD_CLEAR_CMD);
        LCDMessage(LINE1_START_ADDR+1,"0");
        LCDMessage(LINE1_START_ADDR+3,"0");
        LCDMessage(LINE1_START_ADDR+6,"0");
        LCDMessage(LINE1_START_ADDR+8,"0");
        LCDMessage(LINE1_START_ADDR+11,"0");
        LCDMessage(LINE1_START_ADDR+13,"0");
        LCDMessage(LINE1_START_ADDR+16,"0");
        LCDMessage(LINE1_START_ADDR+18,"0");
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{ 
    static u8 au8Time[4]={0,0,0,0};
    static u8 aTimeChar[4];
    static u8 au8Message[]="Time :";
    static u16 u16TimeCounter=0;
    static u8 i;
 
    
    LedCommendType aeDemoList[]=
    {
       {RED,1000,TRUE,LED_PWM_100},
       {RED,3000,FALSE,LED_PWM_0},
       {ORANGE,2000,TRUE,LED_PWM_100},
       {ORANGE,4000,FALSE,LED_PWM_0},
       {YELLOW,3000,TRUE,LED_PWM_100},
       {YELLOW,5000,FALSE,LED_PWM_0},
       {GREEN,4000,TRUE,LED_PWM_100},
       {GREEN,6000,FALSE,LED_PWM_0},
       {CYAN,5000,TRUE,LED_PWM_100},
       {CYAN,6000,TRUE,LED_PWM_50},
       {CYAN,7000,FALSE,LED_PWM_0},
       {BLUE,6000,TRUE,LED_PWM_100},
       {BLUE,7000,TRUE,LED_PWM_50},
       {BLUE,8000,FALSE,LED_PWM_0},
       {PURPLE,7000,TRUE,LED_PWM_100},
       {PURPLE,8000,TRUE,LED_PWM_50},
       {PURPLE,9000,FALSE,LED_PWM_0}
              
    };
   u16TimeCounter++;
 
    switch(u16TimeCounter)       // "1" means leds on,"0" means off
    {
    case 1000:
        LCDMessage(LINE1_START_ADDR+18,"1");
        break;
    case 2000:
        LCDMessage(LINE1_START_ADDR+18,"1");
        LCDMessage(LINE1_START_ADDR+16,"1");
        break;
    case 3000:
        LCDMessage(LINE1_START_ADDR+18,"0");
        LCDMessage(LINE1_START_ADDR+16,"1");
        LCDMessage(LINE1_START_ADDR+13,"1");
        break;
    case 4000:
        LCDMessage(LINE1_START_ADDR+16,"0");
        LCDMessage(LINE1_START_ADDR+13,"1");
        LCDMessage(LINE1_START_ADDR+11,"1");
        break;
    case 5000:
        LCDMessage(LINE1_START_ADDR+13,"0");
        LCDMessage(LINE1_START_ADDR+11,"1");
        LCDMessage(LINE1_START_ADDR+8,"1");
        break;
    case 6000:
        LCDMessage(LINE1_START_ADDR+11,"0");
        LCDMessage(LINE1_START_ADDR+8,"1");
        LCDMessage(LINE1_START_ADDR+6,"1");
        break;
    case 7000:
        LCDMessage(LINE1_START_ADDR+8,"0");
        LCDMessage(LINE1_START_ADDR+6,"1");
        LCDMessage(LINE1_START_ADDR+3,"1");
        break;
    case 8000:
        LCDMessage(LINE1_START_ADDR+6,"0");
        LCDMessage(LINE1_START_ADDR+3,"1");
        break;
    case 9000:
        LCDMessage(LINE1_START_ADDR+3,"0");
        break;
    default:
        break;
    }
   
   if(u16TimeCounter%500==0)       // change numbers to chars to show on the lcd
   {
    LCDClearChars(LINE2_START_ADDR,20);
    au8Time[0]=u16TimeCounter/1000;
    au8Time[1]=(u16TimeCounter%1000)/100;
    au8Time[2]=((u16TimeCounter%1000)%100)/10;
    au8Time[3]=((u16TimeCounter%1000)%100)%10;
    aTimeChar[0]=au8Time[0]+'0';
    aTimeChar[1]=au8Time[1]+'0';
    aTimeChar[2]=au8Time[2]+'0';
    aTimeChar[3]=au8Time[3]+'0';
    LCDMessage(LINE2_START_ADDR+7,aTimeChar);
    LCDMessage(LINE2_START_ADDR,au8Message);
   }
   
   if(u16TimeCounter==10000)                //zero clearing
   {
    u16TimeCounter=0;
   }
   for(i=0;i<17;i++)
   {
       if(u16TimeCounter==aeDemoList[i].u32Time)//Times to turn on/off leds
       {
        LedPWM(aeDemoList[i].eLED,aeDemoList[i].eCurrentRate);       
       }
   }
   
} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
