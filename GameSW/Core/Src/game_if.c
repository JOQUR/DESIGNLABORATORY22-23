#include "game_if.h"

static void reset_state()
{
    /* Disable Buzzer */
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);

	/* Disable Diodes */
	HAL_GPIO_WritePin(BABA_JAGA_PATRZY_GPIO_Port, BABA_JAGA_PATRZY_Pin, 0);
	HAL_GPIO_WritePin(PIR_OUT_1_GPIO_Port, PIR_OUT_1_Pin, 0);
	HAL_GPIO_WritePin(PIR_OUT_2_GPIO_Port, PIR_OUT_2_Pin, 0);

    /* Reset score */
    player_one.score = 0;
    player_two.score = 0;


}

void game_init()
{
	HAL_GPIO_WritePin(GAME_ON_GPIO_Port, GAME_ON_Pin, 1);
	reset_state();
}

void end_game()
{
	/* Disable Interrupts*/
    NVIC_DisableIRQ(EXTI0_IRQn);
	NVIC_DisableIRQ(EXTI1_IRQn);

	reset_state();

	HAL_GPIO_WritePin(GAME_ON_GPIO_Port, GAME_ON_Pin, 0);
}

