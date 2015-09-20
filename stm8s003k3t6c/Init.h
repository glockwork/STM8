

void CLK_Init(void)
{
  // ����� ��������
  CLK_DeInit();
  // ���������� ��������, 16 ���  
  CLK_HSICmd(ENABLE);
  // ������������ ����� ������������� �� 1 �� 8.
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
};

void UART_Init(void)
{
  //UART1_DeInit();
  // 115200 8N1
  //UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);  
 
  //UART1_Cmd(ENABLE);
};

void TIMR2_Init(void)
{
  // Timer 2, F=100Hz
  // ARR=Fsck/Prescale/Fuser
  // ARR=16 000 000 / 32 / 100 = 5000
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2,ENABLE);
  TIM2_TimeBaseInit(TIM2_PRESCALER_32,5000);
  // Interrupt
  TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);
  // Start TIM2
  TIM2_Cmd(ENABLE);
};

void GP_IO_Init(void)
{
   //����������� ����� ���������
  
  GPIO_Init(GPIOB, GPIO_PIN_6, GPIO_MODE_OUT_PP_HIGH_SLOW);
  //����������� ������� ���������
  GPIO_Init(GPIOB, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_SLOW);
  //����������� ������� ���������
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_SLOW);
  //����������� �����
  GPIO_Init(GPIOF, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_SLOW);
  
 //����������� ������
  GPIO_Init(GPIOC,GPIO_PIN_2,GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOE,GPIO_PIN_5,GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOC,GPIO_PIN_1,GPIO_MODE_IN_PU_IT);
  
  delay_ms(10);
 
  //����������� ����������
  //EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC,EXTI_SENSITIVITY_FALL_ONLY); //��� GPIOC �� ����� ����������.
 
  //ITC_SetSoftwarePriority(ITC_IRQ_PORTC, ITC_PRIORITYLEVEL_1); //����������� ��������� ��� ���������� �� GPIOC.
};


void FLASH_EEPROM_Unlock(void)
{
  // ������� ����������� ������ � EEPROM
  FLASH_DeInit();  
  FLASH_Unlock(FLASH_MEMTYPE_DATA); 
};

void A_D_C_Init(void)
{
  //GPIO_Init(GPIOA,GPIO_Pin_4,GPIO_Mode_In_FL_No_IT);
  //CLK_PeripheralClockConfig(CLK_Peripheral_ADC1,ENABLE);
  //ADC_Init(ADC1, ADC_ConversionMode_Single, ADC_Resolution_12Bit, ADC_Prescaler_1);
  //ADC_Cmd(ADC1, ENABLE);
  //ADC_DMACmd(ADC1, DISABLE);
  //ADC_ChannelCmd(ADC1, ADC_Channel_2, ENABLE);
};