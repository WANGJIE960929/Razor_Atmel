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
/*{
  static u32 u32Counter1=0;
  static u32 u32Counter2=0;
  static bool blighton=FALSE;
  static u32 au32time[60];
  static u32* pu8Period=&au32time[0];
  static u32 i;
   for(i=0;i<30;i++)
  {
    au32time[i]=i+1;
    au32time[59-i]=i+1;
  }
   u32Counter2++;
   u32Counter1++;
if(u32Counter2==2000)
  {
     pu8Period++;
     u32Counter2=0;  
     u32Counter1=0;
  }
if(pu8Period==&au32time[49]) 
  {
       pu8Period=&au32time[0];
  }
if(u32Counter1==(488/ *pu8Period))
  { u32Counter1=0;
    if(blighton)
     HEARTBEAT_OFF();
    else
     HEARTBEAT_ON();
  blighton=!blighton;
  }


}The first one

  static u32 u32Counter1=0;
  static bool bLightOn=FALSE;
  static u32 u32Counter2=0;
  static u32 u32Time1=1;
  static u32 u32Time2=1;
  u32Counter2++;
  u32Counter1++;
 if(u32Time2==1)
 { 
  if(u32Counter2==2000)
   {
    u32Time1=u32Time1<<1;
    u32Counter2=0;
    u32Counter1=0;
   }
  if(u32Counter1==(488/u32Time1))
   {
    u32Counter1=0;
    if(bLightOn)
      HEARTBEAT_ON();
    else
      HEARTBEAT_OFF();
    bLightOn=!bLightOn;
   }
  if(u32Time1==32)
    u32Time2=2;
 }
 if(u32Time2==2)
 {
   if(u32Counter2==2000)
   {
     u32Time1=u32Time1>>1;
     u32Counter2=0;
     u32Counter1=0;
   }
  if(u32Counter1==(488/u32Time1))
   {
    u32Counter1=0;
    if(bLightOn)
      HEARTBEAT_ON();
    else
      HEARTBEAT_OFF();
    bLightOn=!bLightOn;
   }
   if(u32Time1==1)
     u32Time2=1;
 } 
the second one
Reduce the blinking rate back down to 1.024Hz and repeat forever*/

/*Bouns*/
{ static u32 u32Counter1=0;
  static u32 u32Counter2=0;
  static u32 u32Counter3=0;
  static bool blighton=FALSE;
  static u32 au32time[20]={10,20,30,40,50,60,70,80,90,100,100,90,80,70,60,50,40,30,20,10};
  static u32* pu8Period=&au32time[0];
   u32Counter1++;
   u32Counter2++;
   u32Counter3++;
if(u32Counter2==100)
  {
     pu8Period++;
     u32Counter2=0;  
     u32Counter1=0;
     u32Counter3=0;
  }
if(pu8Period==&au32time[19]) 
  {
     pu8Period=&au32time[0];
  }
if(u32Counter3<=*pu8Period)
  {
  if(u32Counter1==5)
   { u32Counter1=0;
    if(blighton)
     HEARTBEAT_OFF();
    else
     HEARTBEAT_ON();
    blighton=!blighton;
    u32Counter1=0;
   }
    
  }

}
  


 /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
