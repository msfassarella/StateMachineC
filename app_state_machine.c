/*************************************************************************************************/
/*    INFO                                                                                       */
/*************************************************************************************************/


/*************************************************************************************************/
/*    INCLUDES                                                                                   */
/*************************************************************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/*************************************************************************************************/
/*    DEFINES                                                                                    */
/*************************************************************************************************/

/*************************************************************************************************/
/*    TYPEDEFS                                                                                   */
/*************************************************************************************************/


/*************************************************************************************************/
/*    PRIVATE PROTOTYPES                                                                         */
/*************************************************************************************************/

uint8_t fnAPP_STATE_Init ( uint8_t event );
uint8_t fnAPP_STATE_Run ( uint8_t event );

void fnAPP_STATE_ENTER_Init ( void );
void fnAPP_STATE_ENTER_Run ( void );

void fnAPP_STATE_EXIT_Init ( void );
void fnAPP_STATE_EXIT_Run ( void );

/*************************************************************************************************/
/*    VARIABLES                                                                                  */
/*************************************************************************************************/

/* Based on en_app_state_t enumeration */ 
const st_state_machine_functions_t st_app_state_machine_functions[] = {

   {  fnAPP_STATE_Init,                   fnAPP_STATE_ENTER_Init,                 fnAPP_STATE_EXIT_Init                 },
   {  fnAPP_STATE_Run,                    fnAPP_STATE_ENTER_Run,                  fnAPP_STATE_EXIT_Run                  },
};

/* Pointer to the app_state_machine_functions table */
st_state_machine_desc_t st_app_state_machine_desc;


/*************************************************************************************************/
/*    EXTERNAL FUNCTIONS                                                                         */
/*************************************************************************************************/

void fnAPP_STATE_MACHINE_Init ( void ) {

  /* Inicialization of variable */
   st_app_state_machine_desc.pst_functions = (st_state_machine_functions_t*)&st_app_state_machine_functions[0];

   fnSTATE_Machine_Init( &st_app_state_machine_desc );

   return;

}


void fnAPP_STATE_Machine ( en_event_t event ) {

   fnSTATE_Machine( &st_app_state_machine_desc, event );

   return;

}


/*************************************************************************************************/
/*    STATE ENTER FUNCTIONS                                                                      */
/*************************************************************************************************/

void fnAPP_STATE_ENTER_Init ( void ) {

   return;
}

void fnAPP_STATE_ENTER_Run ( void ) {

  return;
}

/*************************************************************************************************/
/*    STATE FUNCTIONS                                                                            */
/*************************************************************************************************/

uint8_t fnAPP_STATE_Init ( uint8_t event ) {

      en_next_app_state = APP_STATE_RUN;
      return APP_STATE_RUN;
}


uint8_t fnAPP_STATE_Run ( uint8_t event ) {
   en_next_app_state = APP_STATE_RUN;
   return APP_STATE_RUN;
   
}


/*************************************************************************************************/
/*    STATE EXIT FUNCTIONS                                                                       */
/*************************************************************************************************/

void fnAPP_STATE_EXIT_Init ( void ) {

   return;
}


void fnAPP_STATE_EXIT_Run ( void ) {

   return;
}


/*************************************************************************************************/
/*    END OF FILE                                                                                */
/*************************************************************************************************/
