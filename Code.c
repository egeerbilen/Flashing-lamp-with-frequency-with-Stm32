#include "stm32f10x.h"
int main()
{
	RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH |= (1 << 27);
	GPIOC->CRH &= ~((1 << 26) | (1 << 25) | (1 << 24));

	GPIOC->CRH |= ((1 << 21) | (1 << 20));
	GPIOC->CRH &= ~((1 << 23) | (1 << 22));

	while (1)
	{
		if (!(GPIOC->IDR & (1 << 14)))
		{
			GPIOC->ODR |= (1 << 13);
		}
		if (GPIOC->IDR & (1 << 14))
		{
			break;
		}
	}

	for (int j = 0; j < 3000000; j++)
		;
	if ((GPIOC->IDR & (1 << 14)))
	{
		GPIOC->ODR &= ~(1 << 13);
	}
}
