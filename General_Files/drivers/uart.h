#ifndef  __UART_H_
#define __UART_H_

void USART2_IRQHandler(void);
void USARTx_CFG(void);
void UART_RxCpltCallback(USART_TypeDef *USARTx);
void print_status();
#endif
