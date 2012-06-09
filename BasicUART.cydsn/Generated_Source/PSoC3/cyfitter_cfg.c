/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator 2.0
*
* Description:
* This file is automatically generated by PSoC Creator with device 
* initialization code.
*
* THIS FILE SHOULD NOT BE MODIFIED.
*
********************************************************************************
* Copyright 2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include <cytypes.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <CyLib.h>
#include <CyDmac.h>
#include <cyfitter_cfg.h>

/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0
#define CYCLOCKSTART_XTAL_ERROR  1
#define CYCLOCKSTART_32KHZ_ERROR 2
#define CYCLOCKSTART_PLL_ERROR   3

/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc) the system will end up here.  Unless reimplemented by 
*  the customer, an infinite loop will be encountered.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc)    */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
}


#undef CYCODE
#undef CYDATA
#undef CYXDATA
#undef CYFAR
#if defined(__C51__) || defined(__CX51__)
	#define CYCODE code
	#define CYDATA data
	#define CYXDATA xdata
	#define CYFAR far

	#define CYPACKED
	#define CYALIGNED
    #define DMAINITSEC
	#define CY_CFG_MEMORY_BARRIER()

	#ifndef CYCONFIGCPY_DECLARED
		extern void cymemzero(void CYFAR *addr, uint16 size);
		extern void cyconfigcpy(uint16 size, const void CYFAR *src, void CYFAR *dest) small;
		extern void cyconfigcpycode(uint16 size, const void CYCODE *src, void CYFAR *dest);
	#endif


	#define CYMEMZERO(a,c) cymemzero((a),(c))
	#define CYCONFIGCPY(d,s,c) cyconfigcpy((c),(s),(d))
	#define CYCONFIGCPYCODE(d,s,c) cyconfigcpycode((c),(s),(d))
#else
	#error Unsupported toolchain
#endif

/* Defines the layout and meaning of each entry in the cfg_memset_list used for clearing registers */
typedef struct {
	void CYFAR *address;
	uint16 size;
} CYPACKED cfg_memset_t;

/* Defines the layout and meaning of each entry in the cfg_memcpy_list used for initializing registers */
typedef struct {
	void CYFAR *dest;
	const void CYFAR *src;
	uint16 size;
} CYPACKED cfg_memcpy_t;

/* TD structure for big-endian systems. Requires 2-byte endian swap */
struct td_t {
	uint16 size;
	uint8 flags;
	uint8 next_td_ptr;
	uint16 src;
	uint16 dest;
} CYPACKED;

/* IOPORT_0 Address: CYDEV_PRTDSI_PRT0_BASE Size (bytes): 7 */
#define BS_IOPORT_0_VAL ((const uint8 CYFAR *)0x00080000)

/* IDMUX_IRQ Address: CYREG_IDMUX_IRQ_CTL0 Size (bytes): 8 */
#define BS_IDMUX_IRQ_VAL ((const uint8 CYFAR *)0x00080008)

/* UDB_1_4_1_CONFIG Address: CYDEV_UCFG_B0_P1_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_4_1_CONFIG_VAL ((const uint8 CYFAR *)0x00080010)

/* UDB_1_4_0_CONFIG Address: CYDEV_UCFG_B0_P1_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_4_0_CONFIG_VAL ((const uint8 CYFAR *)0x00080090)

/* UDB_1_3_0_CONFIG Address: CYDEV_UCFG_B0_P2_U0_BASE Size (bytes): 128 */
#define BS_UDB_1_3_0_CONFIG_VAL ((const uint8 CYFAR *)0x00080110)

/* UDB_1_3_1_CONFIG Address: CYDEV_UCFG_B0_P2_U1_BASE Size (bytes): 128 */
#define BS_UDB_1_3_1_CONFIG_VAL ((const uint8 CYFAR *)0x00080190)

/* UWRK_B0_WRK_STATCTL_BITS Address: CYDEV_UWRK_UWRK8_B0_BASE + 0x00000070 Size (bytes): 32 */
#define BS_UWRK_B0_WRK_STATCTL_BITS_VAL ((const uint8 CYFAR *)0x00080210)

/* UDB_2_2_HV_ROUTING Address: CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_2_HV_ROUTING_VAL ((const uint8 CYFAR *)0x00080230)

/* UDBSWITCH_1_3 Address: CYDEV_UCFG_B0_P2_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_3_VAL ((const uint8 CYFAR *)0x000802B0)

/* UDB_2_3_HV_ROUTING Address: CYDEV_UCFG_B0_P2_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_3_HV_ROUTING_VAL ((const uint8 CYFAR *)0x00080330)

/* UDBSWITCH_1_4 Address: CYDEV_UCFG_B0_P1_ROUTE_BASE Size (bytes): 128 */
#define BS_UDBSWITCH_1_4_VAL ((const uint8 CYFAR *)0x000803B0)

/* UDB_2_4_HV_ROUTING Address: CYDEV_UCFG_B0_P1_ROUTE_BASE + 0x00000080 Size (bytes): 128 */
#define BS_UDB_2_4_HV_ROUTING_VAL ((const uint8 CYFAR *)0x00080430)

/* DSI3_3_HV_ROUTING Address: CYDEV_UCFG_DSI2_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI3_3_HV_ROUTING_VAL ((const uint8 CYFAR *)0x000804B0)

/* DSISWITCH_1_4 Address: CYDEV_UCFG_DSI1_BASE Size (bytes): 128 */
#define BS_DSISWITCH_1_4_VAL ((const uint8 CYFAR *)0x00080530)

/* DSI3_4_HV_ROUTING Address: CYDEV_UCFG_DSI1_BASE + 0x00000080 Size (bytes): 128 */
#define BS_DSI3_4_HV_ROUTING_VAL ((const uint8 CYFAR *)0x000805B0)

/* UCFG_BCTL0 Address: CYREG_BCTL0_MDCLK_EN Size (bytes): 16 */
#define BS_UCFG_BCTL0_VAL ((const uint8 CYFAR *)0x00080630)

/* IOPINS0_0 Address: CYREG_PRT0_DM0 Size (bytes): 8 */
#define BS_IOPINS0_0_VAL ((const uint8 CYFAR *)0x00080640)

/* IOPINS0_2 Address: CYREG_PRT2_DM0 Size (bytes): 8 */
#define BS_IOPINS0_2_VAL ((const uint8 CYFAR *)0x00080648)


/* PHUB_CH1_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH1_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* PHUB_CH2_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH2_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00 };

/* PHUB_CH5_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH5_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00 };

/* PHUB_CH6_CFGMEM_CFG0/1 initialization data */
static const uint8 CYCODE CH6_ADDR_DATA0[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00 };

/* Initialization data for each DMA channel's TD registers */
static const uint8 CYCODE DMA_TD_START_CMD[] DMAINITSEC = { 0x01, 0x00, 0x00, 0x00, 0x01 };

static uint32 CYXDATA DMA_ZERO_VAL CYALIGNED;

/* This table holds all of the initialization data necessary for the DMA
   process to transfer data from the source location to the destination. */
static const struct td_t CYCODE CFG_TD_LIST0[] DMAINITSEC = {
/* Size, Flags, Next, Source, Destination */
	{ 8, 0x23, 0x02, (uint16)(&CH1_ADDR_DATA0), (uint16)(CYREG_PHUB_CFGMEM1_CFG0) },	/* TD 1 */
	{ 8, 0x23, 0x03, (uint16)(&CH2_ADDR_DATA0), (uint16)(CYREG_PHUB_CFGMEM2_CFG0) },	/* TD 2 */
	{ 8, 0x23, 0x04, (uint16)(&CH5_ADDR_DATA0), (uint16)(CYREG_PHUB_CFGMEM5_CFG0) },	/* TD 3 */
	{ 8, 0x23, 0x05, (uint16)(&CH6_ADDR_DATA0), (uint16)(CYREG_PHUB_CFGMEM6_CFG0) },	/* TD 4 */
	{ 5, 0x23, 0x06, (uint16)(&DMA_TD_START_CMD), (uint16)(CYREG_PHUB_CH1_BASIC_CFG) },	/* TD 5 */
	{ 5, 0x23, 0x07, (uint16)(&DMA_TD_START_CMD), (uint16)(CYREG_PHUB_CH2_BASIC_CFG) },	/* TD 6 */
	{ 5, 0x23, 0x08, (uint16)(&DMA_TD_START_CMD), (uint16)(CYREG_PHUB_CH5_BASIC_CFG) },	/* TD 7 */
	{ 5, 0x23, 0xFE, (uint16)(&DMA_TD_START_CMD), (uint16)(CYREG_PHUB_CH6_BASIC_CFG) },	/* TD 8 */
	{ 16, 0x22, 0x0A, (uint16)(&DMA_ZERO_VAL), (uint16)(CYREG_PRT1_DR) },	/* TD 9 */
	{ 64, 0x22, 0x0B, (uint16)(&DMA_ZERO_VAL), (uint16)(CYREG_PRT3_DR) },	/* TD 10 */
	{ 16, 0x22, 0x0C, (uint16)(&DMA_ZERO_VAL), (uint16)(CYREG_PRT12_DR) },	/* TD 11 */
	{ 16, 0x22, 0xFE, (uint16)(&DMA_ZERO_VAL), (uint16)(CYREG_PRT15_DR) },	/* TD 12 */
	{ 512, 0x22, 0x0E, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_B0_P0_U0_BASE) },	/* TD 13 */
	{ 384, 0x22, 0x0F, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_B0_P3_U0_BASE) },	/* TD 14 */
	{ 2048, 0x22, 0x10, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_B0_P4_U0_BASE) },	/* TD 15 */
	{ 2048, 0x22, 0x11, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_B1_P2_U0_BASE) },	/* TD 16 */
	{ 256, 0x22, 0x12, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_DSI0_BASE) },	/* TD 17 */
	{ 128, 0x22, 0x13, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_DSI2_BASE) },	/* TD 18 */
	{ 1792, 0x22, 0x14, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_DSI3_BASE) },	/* TD 19 */
	{ 512, 0x22, 0x15, (uint16)(&DMA_ZERO_VAL), (uint16)(CYDEV_UCFG_DSI12_BASE) },	/* TD 20 */
	{ 16, 0x22, 0xFE, (uint16)(&DMA_ZERO_VAL), (uint16)(CYREG_BCTL1_MDCLK_EN) },	/* TD 21 */
	{ 7, 0x23, 0x17, (uint16)(BS_IOPORT_0_VAL), (uint16)(CYDEV_PRTDSI_PRT0_BASE) },	/* TD 22 */
	{ 32, 0x23, 0xFE, (uint16)(BS_UWRK_B0_WRK_STATCTL_BITS_VAL), (uint16)(CYDEV_UWRK_UWRK8_B0_BASE + 0x00000070) },	/* TD 23 */
	{ 8, 0x23, 0x19, (uint16)(BS_IDMUX_IRQ_VAL), (uint16)(CYREG_IDMUX_IRQ_CTL0) },	/* TD 24 */
	{ 128, 0x23, 0x1A, (uint16)(BS_UDB_1_4_1_CONFIG_VAL), (uint16)(CYDEV_UCFG_B0_P1_U0_BASE) },	/* TD 25 */
	{ 128, 0x23, 0x1B, (uint16)(BS_UDB_1_4_0_CONFIG_VAL), (uint16)(CYDEV_UCFG_B0_P1_U1_BASE) },	/* TD 26 */
	{ 128, 0x23, 0x1C, (uint16)(BS_UDB_1_3_0_CONFIG_VAL), (uint16)(CYDEV_UCFG_B0_P2_U0_BASE) },	/* TD 27 */
	{ 128, 0x23, 0x1D, (uint16)(BS_UDB_1_3_1_CONFIG_VAL), (uint16)(CYDEV_UCFG_B0_P2_U1_BASE) },	/* TD 28 */
	{ 128, 0x23, 0x1E, (uint16)(BS_UDB_2_2_HV_ROUTING_VAL), (uint16)(CYDEV_UCFG_B0_P3_ROUTE_BASE + 0x00000080) },	/* TD 29 */
	{ 128, 0x23, 0x1F, (uint16)(BS_UDBSWITCH_1_3_VAL), (uint16)(CYDEV_UCFG_B0_P2_ROUTE_BASE) },	/* TD 30 */
	{ 128, 0x23, 0x20, (uint16)(BS_UDB_2_3_HV_ROUTING_VAL), (uint16)(CYDEV_UCFG_B0_P2_ROUTE_BASE + 0x00000080) },	/* TD 31 */
	{ 128, 0x23, 0x21, (uint16)(BS_UDBSWITCH_1_4_VAL), (uint16)(CYDEV_UCFG_B0_P1_ROUTE_BASE) },	/* TD 32 */
	{ 128, 0x23, 0x22, (uint16)(BS_UDB_2_4_HV_ROUTING_VAL), (uint16)(CYDEV_UCFG_B0_P1_ROUTE_BASE + 0x00000080) },	/* TD 33 */
	{ 128, 0x23, 0x23, (uint16)(BS_DSI3_3_HV_ROUTING_VAL), (uint16)(CYDEV_UCFG_DSI2_BASE + 0x00000080) },	/* TD 34 */
	{ 128, 0x23, 0x24, (uint16)(BS_DSISWITCH_1_4_VAL), (uint16)(CYDEV_UCFG_DSI1_BASE) },	/* TD 35 */
	{ 128, 0x23, 0x25, (uint16)(BS_DSI3_4_HV_ROUTING_VAL), (uint16)(CYDEV_UCFG_DSI1_BASE + 0x00000080) },	/* TD 36 */
	{ 16, 0x23, 0xFE, (uint16)(BS_UCFG_BCTL0_VAL), (uint16)(CYREG_BCTL0_MDCLK_EN) },	/* TD 37 */
};
/*******************************************************************************
* Function Name: cfg_dma_init
********************************************************************************
* Summary:
*  This function is used to copy device configuration data from constant values
*  stored in memory into the proper chip configuration registers using DMA.  It
*  pulls data out of the CFG_TD_LISTs to know exactly how/what to configure.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_dma_init(void)
{
	DMA_ZERO_VAL = 0u;
	DMAC_CFGMEM[0].CFG0[0] = 0x10;		/* set burstcount */
	DMAC_CH[0].basic_cfg[0] = 0x01u;	/* enable channel0 */
	DMAC_CH[0].basic_status[1] = 0;		/* set channel0's first td to 0 */
	
	DMAC_TDMEM[0].TD0[2] = 0x01;		/* set td0's next td to 1 */
	DMAC_TDMEM[0].TD0[3] = 0xA3;		/* set td0's flags */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD0[0], 37*8);					/* set td0's size */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[0], (uint16)(uint32)CFG_TD_LIST0);	/* set td0's src addr */
	CY_SET_REG16((reg16 *) &DMAC_TDMEM[0].TD1[2], CYDEV_PHUB_TDMEM1_BASE);	/* set td0's dst addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[0], (uint16)(CYDEV_FLS_BASE >> 16));				/* set ch0's src high addr */
	CY_SET_REG16((reg16 *) &DMAC_CFGMEM[0].CFG1[2], (uint16)(CYDEV_PHUB_TDMEM1_BASE >> 16));				/* set ch0's dst high addr */
	DMAC_CH[1].basic_status[1] = 0x09; /* First TD = 9 */
	DMAC_CH[2].basic_status[1] = 0x0D; /* First TD = 13 */
	DMAC_CH[5].basic_status[1] = 0x16; /* First TD = 22 */
	DMAC_CH[6].basic_status[1] = 0x18; /* First TD = 24 */

	CY_CFG_MEMORY_BARRIER();
	DMAC_CH[0].action[0] = CPU_REQ;    /* initiate the DMA transfer */
	CY_CFG_MEMORY_BARRIER();

	/* Wait for all DMA transfers to complete */
	while((CY_GET_REG8(CYREG_PHUB_CH0_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH1_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH2_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH5_BASIC_STATUS) & 0x01u)){}
	while((CY_GET_REG8(CYREG_PHUB_CH6_BASIC_STATUS) & 0x01u)){}


}
/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void)
{
	reg32  timeout;
	reg32* timeout_p = &timeout;
	reg8   pllLock;


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG24((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x180138);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_REG8((void CYXDATA *)(CYREG_SLOWCLK_ILO_CR0), 0x02);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_CR), 0x08);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_REG8((void CYXDATA *)(CYREG_FASTCLK_IMO_CR), 0x03);
	CY_SET_REG8((void CYXDATA *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8(CYREG_FLSHID_CUST_TABLES_IMO_3MHZ)));

	/* Configure PLL based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0008);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1051);
	/* Wait up to 250us for the PLL to lock */
	pllLock = 0;
	for (timeout = 250 / 10; *timeout_p && (pllLock != 0x03u); timeout--) { 
		pllLock = 0x03u & ((pllLock << 1) | ((CY_GET_REG8(CYREG_FASTCLK_PLL_SR) & 0x01u) >> 0));
		CyDelayCycles(10 * 48); /* Delay 10us based on 48MHz clock */
	}

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x0103);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_MSTR0), 0x07);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_BCFG0), 0x00);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_BCFG2), 0x48);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_MSTR0), 0x00);
	CY_SET_REG8((void CYXDATA *)(CYREG_CLKDIST_LD), 0x02);

	CY_SET_REG8((void CYXDATA *)(CYREG_PM_ACT_CFG2), ((CY_GET_REG8(CYREG_PM_ACT_CFG2) | 0x01)));
}


/* Analog API Functions */

/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogSetDefault(void)
{
	uint8 bg_xover_inl_trim = CY_GET_XTND_REG8(CYREG_FLSHID_MFG_CFG_BG_XOVER_INL_TRIM + 1u);
	CY_SET_REG8(CYREG_BG_DFT0, bg_xover_inl_trim & 0x07u);
	CY_SET_REG8(CYREG_BG_DFT1, (bg_xover_inl_trim >> 4) & 0x0Fu);
	CY_SET_REG8(CYREG_PUMP_CR0, 0x44);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
void cyfitter_cfg(void)
{
	/* Setup Flash Cycles based on 48MHz clock startup frequency. */
	CY_SET_REG8((void CYXDATA *)(CYREG_CACHE_CR), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0xF1 : 0xC0));
	/* Enable/Disable Debug functionality based on settings from System DWR */
	CY_SET_XTND_REG8(CYREG_MLOGIC_DEBUG, (CY_GET_XTND_REG8(CYREG_MLOGIC_DEBUG) | 0x05));

	{
		cfg_dma_init();

		/* Enable digital routing */
		CY_SET_XTND_REG8(CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8(CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8(CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_REG8(CYREG_PM_ACT_CFG0, CY_GET_REG8(CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_REG8(CYREG_PM_AVAIL_CR2, CY_GET_REG8(CYREG_PM_AVAIL_CR2) | 0x10u);
	}

	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT0_DM0), (void CYFAR *)(BS_IOPINS0_0_VAL), 8);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT2_DM0), (void CYFAR *)(BS_IOPINS0_2_VAL), 8);
	CY_SET_REG8((void CYXDATA *)(CYREG_INTC_CSR_EN), 0x01);
	CY_SET_REG8((void CYXDATA *)(CYREG_PWRSYS_WAKE_TR2), 0x3A);


	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_REG8((void CYXDATA *)(CYREG_CACHE_CR), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0x31 : 0x00));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 24.00MHz Bus Clock. */
	CY_SET_REG8((void CYXDATA *)(CYREG_CACHE_CR), ((CYDEV_INSTRUCT_CACHE_ENABLED) ? 0xB1 : 0x80));

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (void CYFAR *)CYDEV_PM_ACT_BASE, 14);
	CY_SET_REG8(CYREG_PM_STBY_CFG0, CY_GET_REG8(CYREG_PM_STBY_CFG0) & ~0x02u);	/* Disable CPU */
}