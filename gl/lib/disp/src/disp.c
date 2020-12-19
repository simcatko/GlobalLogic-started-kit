#include "disp.h"

GPIO_InitTypeDef DISP_GPIO;

void DISP_RW_pulse(void);

void DISP_Init_GPIO(void)
{
  HAL_Delay(400);
  DISP_GPIO.Mode = GPIO_MODE_OUTPUT_PP;
  DISP_GPIO.Speed = GPIO_SPEED_FREQ_MEDIUM;
  DISP_GPIO.Pull = GPIO_NOPULL;
  DISP_GPIO.Pin = DISP_RS_Pin | DISP_RW_Pin | DISP_ENA_Pin | DISP_DB7_Pin | DISP_DB6_Pin | DISP_DB5_Pin | DISP_DB4_Pin;
  HAL_GPIO_Init(DISP_PORT, &DISP_GPIO);
  HAL_GPIO_WritePin(DISP_PORT, DISP_RS_Pin | DISP_RW_Pin | DISP_ENA_Pin | DISP_DB4_Pin | DISP_DB5_Pin | DISP_DB6_Pin | DISP_DB7_Pin, GPIO_PIN_RESET);
}

void DISP_Init(void)
{
  HAL_Delay(40);

  DISP_Write_Ins(0x02);
  HAL_Delay(DISP_DELAY);

  DISP_Write_Ins(DISP_TWO_LINE_MODE);
  HAL_Delay(DISP_DELAY);

  DISP_Write_Ins(DISP_ON | DISP_CURSOR_OFF | DISP_CURSOR_BLINK_OFF);
  HAL_Delay(DISP_DELAY);

  DISP_Write_Ins(DISP_CLEAR);
  HAL_Delay(DISP_DELAY);

  DISP_Write_Ins(DISP_INCREMENT_MODE | DISP_ENTIRE_SHIFT_OFF);
  HAL_Delay(DISP_DELAY);
}

void DISP_Write_Ins(char instruction)
{
  HAL_GPIO_WritePin(DISP_RS_GPIO_Port, DISP_RS_Pin, 0);
  HAL_GPIO_WritePin(DISP_RW_GPIO_Port, DISP_RW_Pin, 0);

  instruction &DISP_BIT_7_MASK ? HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_6_MASK ? HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_5_MASK ? HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_4_MASK ? HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_RESET);

  DISP_RW_pulse();
  HAL_Delay(DISP_DELAY);

  instruction &DISP_BIT_3_MASK ? HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_2_MASK ? HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_1_MASK ? HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_RESET);
  instruction &DISP_BIT_0_MASK ? HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_RESET);

  DISP_RW_pulse();
  HAL_Delay(DISP_DELAY);
}

void DISP_Write_Data(char data)
{
  HAL_GPIO_WritePin(DISP_RS_GPIO_Port, DISP_RS_Pin, 1);
  HAL_GPIO_WritePin(DISP_RW_GPIO_Port, DISP_RW_Pin, 0);

  data &DISP_BIT_7_MASK ? HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_6_MASK ? HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_5_MASK ? HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_4_MASK ? HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_RESET);

  DISP_RW_pulse();
  HAL_Delay(DISP_DELAY);

  data &DISP_BIT_3_MASK ? HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB7_GPIO_Port, DISP_DB7_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_2_MASK ? HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB6_GPIO_Port, DISP_DB6_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_1_MASK ? HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB5_GPIO_Port, DISP_DB5_Pin, GPIO_PIN_RESET);
  data &DISP_BIT_0_MASK ? HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(DISP_DB4_GPIO_Port, DISP_DB4_Pin, GPIO_PIN_RESET);

  DISP_RW_pulse();
  HAL_Delay(DISP_DELAY);
}

void DISP_Write_Data_Array(char *data, const uint8_t length)
{
  for (int i = 0; i < length; i++)
  {
    DISP_Write_Data(data[i]);
  }
}

void DISP_Write_Data_Repeat(char data, const uint8_t length)
{
  for (int i = 0; i < length; i++)
  {
    DISP_Write_Data(data);
  }
}

void DISP_RW_pulse(void)
{
  HAL_GPIO_WritePin(DISP_ENA_GPIO_Port, DISP_ENA_Pin, GPIO_PIN_SET);
  HAL_Delay(DISP_DELAY);
  HAL_GPIO_WritePin(DISP_ENA_GPIO_Port, DISP_ENA_Pin, GPIO_PIN_RESET);
}