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

static bool bOK=TRUE;                                /*Set the state amount to prevent multiple calls*/

/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/
static void AllLedOff(void)
{
    LedOff(WHITE);
    LedOff(PURPLE);
    LedOff(BLUE);
    LedOff(CYAN);
    LedOff(GREEN);
    LedOff(YELLOW);
    LedOff(ORANGE);
    LedOff(RED);
}

/* Use button 1 and 2 to realize function


static void UserAppSM_State1(void)              //state   1
{
    static u8 au8String[]="STATE  1";
    static bool bOK=TRUE;
    void UserAppSM_State2(void);
    
    if(bOK==TRUE)
    {
        AllLedOff();
        LCDCommand(LCD_CLEAR_CMD);
        PWMAudioOff(BUZZER1);
        DebugPrintf("\n\rEntering state 1\n\r");
        LCDMessage(LINE1_START_ADDR,au8String);
        LedOn(WHITE);
        LedOn(PURPLE);
        LedOn(BLUE);
        LedOn(CYAN);
        LedOn(LCD_RED);                             
        LedOn(LCD_BLUE);
        LedPWM(LCD_RED,LED_PWM_90);                 //lcd backlight��purple
        LedPWM(LCD_GREEN,LED_PWM_10);
        bOK=FALSE;
    }
    if(WasButtonPressed(BUTTON2))               //press button2 to change the state
    {
        ButtonAcknowledge(BUTTON2);
        bOK=TRUE;
        UserApp1_StateMachine = UserAppSM_State2;
    }
}

 static void UserAppSM_State2(void)             //state   2
{
    static u32 u32Count=0;
    static u8 au8String[]="STATE  2";
    static bool bOK=TRUE;
    void UserAppSM_State1(void);
    
    if(bOK==TRUE)
    {
        u32Count=0;
        AllLedOff();
        LCDCommand(LCD_CLEAR_CMD);
        PWMAudioOn(BUZZER1);
        PWMAudioSetFrequency(BUZZER1,200);
        DebugPrintf("\n\rEntering state 2\n\r");
        LCDMessage(LINE1_START_ADDR,au8String);
        LedBlink(GREEN,LED_1HZ);
        LedBlink(YELLOW,LED_2HZ);
        LedBlink(ORANGE,LED_4HZ);
        LedBlink(RED,LED_8HZ);
        LedPWM(LCD_RED,LED_PWM_100);                 //lcd backlight��ORANGE
        LedPWM(LCD_BLUE,LED_PWM_20);
        bOK=FALSE;
    }
    u32Count++;  
    
    if(u32Count==100)                            //buzzer on  100ms
    {
        PWMAudioOff(BUZZER1);
    }
    
    if(u32Count==1000)                           
    {
        u32Count=0;
        PWMAudioOn(BUZZER1);
    }
        
    if(WasButtonPressed(BUTTON1))               //press button1 to change the state
    {
        ButtonAcknowledge(BUTTON1);
        bOK=TRUE;
        UserApp1_StateMachine = UserAppSM_State1;
    }
}
*/

/*Use debug to realize function*/

static void UserAppSM_State1(void)              //state   1
{
    static u8 au8String[]="STATE  1";
    
    if(bOK==TRUE)
    {
        AllLedOff();
        LCDCommand(LCD_CLEAR_CMD);
        PWMAudioOff(BUZZER1);
        DebugPrintf("****************************\n\r");
        DebugPrintf("Entering state 1           *\n\r");
        DebugPrintf("****************************\n\r");
        LCDMessage(LINE1_START_ADDR,au8String);
        LedOn(WHITE);                               //led
        LedOn(PURPLE);
        LedOn(BLUE);
        LedOn(CYAN);
        LedOn(LCD_RED);                             
        LedOn(LCD_BLUE);
        LedPWM(LCD_RED,LED_PWM_90);                 //lcd backlight��purple
        LedPWM(LCD_GREEN,LED_PWM_10);
        bOK=FALSE;
    }
    
}

 static void UserAppSM_State2(void)             //state   2
{
    static u32 u32Count=0;
    static u8 au8String[]="STATE  2";
    
    if(bOK==TRUE)
    {
        u32Count=0;
        AllLedOff();
        LCDCommand(LCD_CLEAR_CMD);
        PWMAudioOn(BUZZER1);
        PWMAudioSetFrequency(BUZZER1,200);
        DebugPrintf("****************************\n\r");
        DebugPrintf("Entering state 2           *\n\r");
        DebugPrintf("****************************\n\r");
        LCDMessage(LINE1_START_ADDR,au8String);
        LedBlink(GREEN,LED_1HZ);
        LedBlink(YELLOW,LED_2HZ);
        LedBlink(ORANGE,LED_4HZ);
        LedBlink(RED,LED_8HZ);
        LedPWM(LCD_RED,LED_PWM_100);                 //lcd backlight��ORANGE
        LedPWM(LCD_BLUE,LED_PWM_20);
        bOK=FALSE;
    }
    u32Count++;  
    
    if(u32Count==100)                             //buzzer on  100ms
    {
        PWMAudioOff(BUZZER1);
    }
    
    if(u32Count==1000)                             
    {
        u32Count=0;
        PWMAudioOn(BUZZER1);
    }
    
}
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
    //UserApp1_StateMachine = UserAppSM_State1;            // use button 
    UserApp1_StateMachine = UserApp1SM_Idle;               // use debug
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
  UserApp1_StateMachine();              //state and Idle Run at the same time
  UserApp1SM_Idle();

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
    static u8 u8temp=0;
    static u8 u8datacount;
    static u8 au8Buffer[]="0";
    static u8 au8Enter[20]={0};
    static u8 i=0;
    
    u8temp=DebugScanf(au8Buffer);
    
    if(u8temp>0)                                //Test whether input
    {
        if(au8Buffer[0]=='\r')                  //Test whether press 'ENTER' to end entering
        {
            if(u8datacount==0)                  //when just input 'enter' 
            {
                DebugScanf(au8Buffer);
            }
            else
            {
                au8Enter[u8datacount]=au8Buffer[0];
                
                if(au8Enter[0]=='1'&&au8Enter[1]=='\r')      //enter 1 to run state1
                {
                    bOK=TRUE;
                    UserApp1_StateMachine = UserAppSM_State1;
                }
                else if(au8Enter[0]=='2'&&au8Enter[1]=='\r')   //enter 2 to run state2
                {
                    bOK=TRUE;
                    UserApp1_StateMachine = UserAppSM_State2;
                }
                else                                     //when input others,Enter again
                {
                    DebugScanf(au8Buffer);
                }
            }
            u8datacount=0;
            for(i=0;i<20;i++)                           //Initialize Array
            {
                au8Enter[i]=0;
            }
        }
        else
        {
            au8Enter[u8datacount]=au8Buffer[0];          //Put the input into an array
            u8datacount++;
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
