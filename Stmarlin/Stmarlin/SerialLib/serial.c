/**
  ******************************************************************************
  * @file    serial.c
  * @author  xiaoyuan
  * @version V2.0
  * @date    2018-1-28
  * @brief   �����жϽ��գ��������յ������ݴ��뻷�λ���������ʵ����ӡ����ӣ������⹦��
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "serial.h"
#include "usart.h"

///* ���廷�λ�������ѭ�����У������ﻷ�λ������е�head tail �����ݽṹ��ѭ�����ж����front rear ��ָ��λ��ǡ���෴ */
//RingBufferStruct rx_buffer  =  { { 0 }, 0, 0 };
////ReceiveDataToBuffer
//void ReceiveCharToBuff(unsigned char byte)  //�����յ������ݴ��뻺����
//{
//  int i = (unsigned int)(rx_buffer.head + 1) % RX_BUFFER_SIZE;
//  // if we should be storing the received character into the location  //�������Ӧ�ô洢�Ľ��յ����ַ���λ�øպ�
//  // just before the tail (meaning that the head would advance to the  //��β�˵�ǰ�棨��ζ��ͷ����Ҫ����β�˵�
//  // current location of the tail), we're about to overflow the buffer //��ǰλ�ã�����������������������������
//  // and so we don't write the character or advance the head.          //���ô�������ַ���ʹ���ͷǰ��
//  if (i != rx_buffer.tail)  //������û�д��� 
//	{
//    rx_buffer.buffer[rx_buffer.head] = byte;
//    rx_buffer.head = i;
//  }
//}

//uint8_t ReadCharFromBuff(void)  //������˳�������ȡ�����������ݣ���ɾ��
//{ 
//	uint8_t c;
//  // if the head isn't ahead of the tail, we don't have any characters //���ͷ������β��ǰ�棬���ղ����κ��ַ�
//  if (rx_buffer.head == rx_buffer.tail) 
//	{
//    return 0;
//  } 
//	else 
//	{
//    c = rx_buffer.buffer[rx_buffer.tail];
//    rx_buffer.tail = (unsigned int)(rx_buffer.tail + 1) % RX_BUFFER_SIZE;
//    return c;
//  }
//}

//unsigned int GetRxBuffLen(void)  //���ش��ڻ����������ݵĸ���
//{
//   return (unsigned int)(RX_BUFFER_SIZE + rx_buffer.head - rx_buffer.tail) % RX_BUFFER_SIZE;
//}

//void CheckRxBuff(void)  //�����յ�������
//{ 
//	unsigned char c;
//	unsigned int i;
//	
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
//  { 
//		c = USART_ReceiveData(USART1);
//		i = (unsigned int)(rx_buffer.head + 1) % RX_BUFFER_SIZE;
//		// if we should be storing the received character into the location
//		// just before the tail (meaning that the head would advance to the
//		// current location of the tail), we're about to overflow the buffer
//		// and so we don't write the character or advance the head.
//		if (i != rx_buffer.tail) 
//    {
//			rx_buffer.buffer[rx_buffer.head] = c;
//			rx_buffer.head = i;
//		}
//	}
//}

////uint8_t MSerial_peek(void) //���������������ݣ���ɾ��
////{
////    if (rx_buffer.head == rx_buffer.tail) 
////    {
////        return 0;
////    } 
////    else 
////    {
////        return rx_buffer.buffer[rx_buffer.tail];
////    }
////}


////void MSerial_flush(void)  //�ȴ��������ݴ������
////{
////  // RX
////	// don't reverse this or there may be problems if the RX interrupt  //��Ҫ�ߵ����������ܻ���һЩ���⣬��������ж�
////  // occurs after reading the value of rx_buffer_head but before writing  //�����ڶ�ȡrx_buffer_head֮����д��rx_buffer_tail֮ǰ
////  // the value to rx_buffer_tail; the previous value of rx_buffer_head  //֮ǰ��rx_buffer_headֵ���ܱ�д��rx_buffer_tail
////  // may be written to rx_buffer_tail, making it appear as if the buffer  //ʹ�����ֻ����������Ķ��ǿյ�״̬
////  // were full, not empty.
////  rx_buffer.head = rx_buffer.tail;
////}


////����1�жϷ������
////ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
////u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
////����״̬
////bit15��	������ɱ�־
////bit14��	���յ�0x0d
////bit13~0��	���յ�����Ч�ֽ���Ŀ
//void USART1_IRQHandler(void)                	//����1�жϷ������
//{
//	uint8_t rec;
//	
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d //0x0a��β)
//	{
//		rec = USART_ReceiveData(USART1);//(USART1->DR);	//��ȡ���յ�������
////		printf("%c",rec);  //���Խ���
//		ReceiveCharToBuff(rec);  		//����ȡ�������ݴ��뻺���� 
//		
//  } 
//} 

ring_buffer rx_buffer  =  { { 0 }, 0, 0 };

/*static inline*/ void store_char(unsigned char c)  //�����յ������ݴ��뻺����
{
  int i = (unsigned int)(rx_buffer.head + 1) % RX_BUFFER_SIZE;
  // if we should be storing the received character into the location  //�������Ӧ�ô洢�Ľ��յ����ַ���λ�øպ�
  // just before the tail (meaning that the head would advance to the  //��β�˵�ǰ�棨��ζ��ͷ����Ҫ����β�˵�
  // current location of the tail), we're about to overflow the buffer //��ǰλ�ã�����������������������������
  // and so we don't write the character or advance the head.          //���ô�������ַ���ʹ���ͷǰ��
  if (i != rx_buffer.tail)  //������û�д��� 
	{
    rx_buffer.buffer[rx_buffer.head] = c;
    rx_buffer.head = i;
  }
}

void MYSERIAL_checkRx(void)  //�����յ�������
{ 
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //�����ж�
	{ 
		unsigned char c = USART_ReceiveData(USART1);
		unsigned int i = (unsigned int)(rx_buffer.head + 1) % RX_BUFFER_SIZE;
		// if we should be storing the received character into the location
		// just before the tail (meaning that the head would advance to the
		// current location of the tail), we're about to overflow the buffer
		// and so we don't write the character or advance the head.
		if (i != rx_buffer.tail) 
		{
			rx_buffer.buffer[rx_buffer.head] = c;
			rx_buffer.head = i;
		}
	}
}

unsigned int MYSERIAL_available(void)  //���ش��ڻ����������ݵĸ���
{
   return (unsigned int)(RX_BUFFER_SIZE + rx_buffer.head - rx_buffer.tail) % RX_BUFFER_SIZE;
}

int MYSERIAL_read(void)  //������˳�������ȡ������������
{ 
	uint8_t c;
  // if the head isn't ahead of the tail, we don't have any characters //���ͷ������β��ǰ�棬���ղ����κ��ַ�
  if (rx_buffer.head == rx_buffer.tail) 
	{
    return -1;
  } 
	else 
	{
    c = rx_buffer.buffer[rx_buffer.tail];
    rx_buffer.tail = (unsigned int)(rx_buffer.tail + 1) % RX_BUFFER_SIZE;
    return c;
  }
}
void MYSERIAL_flush(void)  //��մ�������
{
  // RX
	// don't reverse this or there may be problems if the RX interrupt  //��Ҫ�ߵ����������ܻ���һЩ���⣬��������ж�
  // occurs after reading the value of rx_buffer_head but before writing  //�����ڶ�ȡrx_buffer_head֮����д��rx_buffer_tail֮ǰ
  // the value to rx_buffer_tail; the previous value of rx_buffer_head  //֮ǰ��rx_buffer_headֵ���ܱ�д��rx_buffer_tail
  // may be written to rx_buffer_tail, making it appear as if the buffer  //ʹ�����ֻ����������Ķ��ǿյ�״̬
  // were full, not empty.
  rx_buffer.head = rx_buffer.tail;
}		



#if EN_USART1_RX   //���ʹ���˽���
//����1�жϷ������
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
//u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
void USART1_IRQHandler(void)                	//����1�жϷ������
{
	uint8_t rec;
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d //0x0a��β)
	{
		rec = USART_ReceiveData(USART1);//(USART1->DR);	//��ȡ���յ�������
		store_char(rec);  		//����ȡ�������ݴ��뻺���� 
  } 
} 

#endif

