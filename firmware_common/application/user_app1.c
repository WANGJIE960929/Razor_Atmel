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
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
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
      LedOff(BLUE);
      LedOff(PURPLE);
      LedOff(WHITE);
      LedOff(RED);
      LedOff(GREEN);
      LedBlink(ORANGE,LED_8HZ);

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

 

/* Wait for a message to be queued */
static void UserApp1SM_Idle(void)
{
/*   if(IsButtonPressed(BUTTON0))
      {
        LedOn(PURPLE);
        LedOn(BLUE);
      }
     if(IsButtonPressed(BUTTON1))
      {
        LedOff(PURPLE);
        LedOff(BLUE);
      }                                    //problem3
 */
  

   
{       
        static u8 u8Correct=1;
        static u8 au8Passwordarray[6]={1,2,3,1,2,3};
        static u8 au8Enterarray[6]={0,0,0,0,0,0};
        static u8 i=0;
        
        if(i<6) 
          
        if(WasButtonPressed(BUTTON1))//Enter 6 passwords
            
          {
            LedBlink(RED,LED_4HZ);//RED Led Blink
            au8Enterarray[i]=1;
            i++;
            ButtonAcknowledge(BUTTON1);
          }
        
        if(WasButtonPressed(BUTTON2))
            
          {
            LedBlink(RED,LED_4HZ);
            au8Enterarray[i]=2;
            i++;
            ButtonAcknowledge(BUTTON2);
          }
        
        if(WasButtonPressed(BUTTON3))
          
          {
            LedBlink(RED,LED_4HZ);
            au8Enterarray[i]=3;
            i++;
            ButtonAcknowledge(BUTTON3);
          }
        
      if(IsButtonPressed(BUTTON0))//confirm
      {    
           LedOff(RED);        
        for(i=0;i<6;i++)//Correct or not
        {
          if(au8Enterarray[i]==au8Passwordarray[i])
          { 
            u8Correct=1;
          }
          else
          {
            u8Correct=0;
            break;
          }
        }
      
     if(u8Correct==1)   
     {
       LedOn(WHITE);
       LedOff(PURPLE);
     }
     else
     {
       LedOff(WHITE);
       LedOn(PURPLE);
     }
    }
}                                        //problem  6


  /*static u16 u16Counter1=0;   //time counter
    static u16 u16Counter2=0;   //0-16
    static LedRateType eLedDutyLevel=LED_PWM_0;
	
	u16Counter1++;
	
	if(u16Counter1==1000)    //1s
	{
		LedToggle(PURPLE);		
		LedPWM(WHITE,eLedDutyLevel);
                u16Counter2++;
		if(u16Counter2<=8)     //up
		{
			LedOn(RED);
			LedOff(GREEN);
			eLedDutyLevel++;
                       }
		else//down
		{
			LedOn(GREEN);
			LedOff(RED);
                                 eLedDutyLevel--;
                        
			if(u16Counter2==16)
			{
                                     u16Counter2=0;
			}
                      }
                     u16Counter1=0; 
	}
     
*/                                  //Duty cycle   0~40,40~0
           
         
}/* end UserAppSM_Idle() */

/*static u32 u32Counter123=0;
  static u8 u8LedNo = 0;
  
  u32Counter123 ++;
  
  if(u32Counter123==1000)   //1s=1000ms
  {
    u32Counter123 = 0;
    u8LedNo++;
 
      switch(u8LedNo)
      {
      case 1:
        LedOn(WHITE);
        LedOn(RED);
        break;
      case 2:
        LedOn(PURPLE);
        LedOn(ORANGE);
        break;
      case 3:
        LedOn(BLUE);
        LedOn(YELLOW);
        break;
      case 4:
        LedOn(CYAN);
        LedOn(GREEN);
        break;
      case 5:
        LedOff(WHITE);
        LedOff(RED);
        break;
      case 6:
        LedOff(PURPLE);
        LedOff(ORANGE);
        break;
      case 7:
        LedOff(BLUE);
        LedOff(YELLOW);
        break;
      case 8:
        LedOff(CYAN);
        LedOff(GREEN);
        break;
      case 10:
        u8LedNo=0;
        break;
      default:
        break;
      }
  }*/                       //Led  basic

 

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)         
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
