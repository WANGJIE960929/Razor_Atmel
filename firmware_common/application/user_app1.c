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
static u8 UserApp_CursorPosition1 = LINE1_END_ADDR;
static u8 UserApp_CursorPosition2 = LINE2_END_ADDR;


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
    static u16 u16Counter=0;
    static u16 u16Time=400;
    static u8 u8index=0;
    static u8 au8Message[]="WANG JIE!";
    static u8* pu8Pointer1=&au8Message[0];
    static u8* pu8Pointer2=&au8Message[0];
    static u16 u16TimerCounter=0;
    static u8 u8LedNo=0;//led number
    static bool bOK=FALSE;
    static bool bON=FALSE;
    static u8 u8Comfirm=0;
    
    if(WasButtonPressed(BUTTON3))//choose just line1 or line1 and line2 to scroll up
    {
        if(u8Comfirm==2)
        {
            u8Comfirm=0;
        }
        ButtonAcknowledge(BUTTON3);
        u8Comfirm++;
        u16Counter=0;
        u8index=0;
        UserApp_CursorPosition1=LINE1_END_ADDR;
        UserApp_CursorPosition2=LINE2_END_ADDR;
        pu8Pointer1=&au8Message[0];
        pu8Pointer2=&au8Message[0];
    }
    if(WasButtonPressed(BUTTON0))//make the speed of characters,LED and BUZZER1 up
    {
        ButtonAcknowledge(BUTTON0);
        u16Counter=0;
        if(u16Time==100)
        {
            u16Time=150;
        }
        u16Time=u16Time-50;
    }
    
    if(WasButtonPressed(BUTTON1))//make the speed of characters,LED and BUZZER1 down
    {
        ButtonAcknowledge(BUTTON1);
        u16Counter=0;
        if(u16Time==600)
        {
            u16Time=550;
        }
        u16Time=u16Time+50;
    }
    
    if(WasButtonPressed(BUTTON2))//turn on or turn off the LED and BUZZER
    {
        ButtonAcknowledge(BUTTON2); 
        bON=!bON;
    }
    
    if(bON)
    {
        u16TimerCounter++;

	if(u16TimerCounter==u16Time)
	{
		u8LedNo++;
		u16TimerCounter=0;
		bOK=TRUE;
	}
	
	if(bOK)
	{	
		bOK=FALSE;
                PWMAudioOn(BUZZER1);
		switch(u8LedNo)
		{
			case 8:
				LedOn(WHITE);
                                PWMAudioSetFrequency(BUZZER1,1000);
				break;
			case 7:
				LedOn(PURPLE);
                                PWMAudioSetFrequency(BUZZER1,900);
				break;
			case 6:
				LedOn(BLUE);
                                PWMAudioSetFrequency(BUZZER1,800);
				break;
			case 5:
				LedOn(CYAN);
                                PWMAudioSetFrequency(BUZZER1,700);
				break;
			case 4:
				LedOn(GREEN);
                                PWMAudioSetFrequency(BUZZER1,600);
				break;
			case 3:
				LedOn(YELLOW);
                                PWMAudioSetFrequency(BUZZER1,500);
				break;
			case 2:
				LedOn(ORANGE);
                                PWMAudioSetFrequency(BUZZER1,400);
				break;
			case 1:
				LedOn(RED);
                                PWMAudioSetFrequency(BUZZER1,300);
				break;
			case 9:
				LedOff(WHITE);
				LedOff(PURPLE);
				LedOff(BLUE);
				LedOff(CYAN);
				LedOff(GREEN);
				LedOff(YELLOW);
				LedOff(ORANGE);
				LedOff(RED);
				u8LedNo=0;
                                PWMAudioOff(BUZZER1);
				break;
			default:
				break;		
		}
        }
    }
    else
    {
        LedOff(WHITE);
        LedOff(PURPLE);
        LedOff(BLUE);
        LedOff(CYAN);
        LedOff(GREEN);
        LedOff(YELLOW);
        LedOff(ORANGE);
        LedOff(RED);
        PWMAudioOff(BUZZER1);
        u8LedNo=0;
    }
    if(u8Comfirm==1)//scroll up in line1
    {
        u16Counter++;       
        if(u16Counter==u16Time)
        {      
            u16Counter=0;
            LCDCommand(LCD_CLEAR_CMD);
            
          if(pu8Pointer1==&au8Message[9])
          {
            pu8Pointer1=&au8Message[0];
            UserApp_CursorPosition1=LINE1_END_ADDR;
          }

          if(UserApp_CursorPosition1==LINE1_START_ADDR)
          {        
            LCDMessage(LINE1_START_ADDR,pu8Pointer1);
            pu8Pointer1++;
          }
          else
          {       
            LCDMessage(UserApp_CursorPosition1, au8Message);       
            UserApp_CursorPosition1--;
          }            
        }
    }
    if(u8Comfirm==2)//scroll up in line1 and line2
    {
        u16Counter++;
        if(u16Counter==u16Time)
        {
            u16Counter=0;
            u8index++;
            LCDCommand(LCD_CLEAR_CMD);
            
            if(u8index<=19)
            {
                LCDMessage(UserApp_CursorPosition2, au8Message);       
                UserApp_CursorPosition2--;
            }
            
            if(20<=u8index<=29)
            {
                LCDMessage(LINE2_START_ADDR,pu8Pointer1);
                pu8Pointer1++;
                LCDMessage(UserApp_CursorPosition1,au8Message);
                UserApp_CursorPosition1--;
            }
            if(30<=u8index<=39)
            {
                LCDMessage(UserApp_CursorPosition1,au8Message);
                UserApp_CursorPosition1--;
            }
            if(40<=u8index)
            {
                LCDMessage(LINE2_START_ADDR,pu8Pointer1);
                pu8Pointer2++;               
            }
            if(pu8Pointer1==&au8Message[9])
            {
                pu8Pointer1=&au8Message[0];
            }    
            if(pu8Pointer2==&au8Message[9])
            {
                pu8Pointer2=&au8Message[0];
                u8index=0;
                UserApp_CursorPosition1=LINE1_END_ADDR;
                UserApp_CursorPosition2=LINE2_END_ADDR;
            }                      
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
