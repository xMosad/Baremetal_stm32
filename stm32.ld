ENTRY (Reset_Handler)

MEMORY 
{
	RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 56K
}

SECTIONS 
{
	.text : 
	{
		*(.isr_vector)
		*(.text)
		*(.text.*)
		*(.init)
		*(.fini)
		*(.rodata)
		. = ALIGN(4);
		_etext = . ;
	} >FLASH
	
	.data :
	{
		/* Keep track of vma only */
		_sdata = . ; 
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = . ;
	} > RAM AT> FLASH
	
	.bss :
	{
		_sbss = . ;
		__bss_start__ = _sbss;     	/* standard newlib definition */
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = . ;
		__bss_end__ = _ebss;        /* standard newlib definition */
	} > RAM
}