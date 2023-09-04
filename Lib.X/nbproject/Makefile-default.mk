#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=hal/hal_uart.c hal/interrupts.s lib/io.c lib/wimbus.c lib/wimuart.c lib/async_uart.c lib/driver_init.c lib/ringbuffer.c main.c system.c board.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/hal/hal_uart.o ${OBJECTDIR}/hal/interrupts.o ${OBJECTDIR}/lib/io.o ${OBJECTDIR}/lib/wimbus.o ${OBJECTDIR}/lib/wimuart.o ${OBJECTDIR}/lib/async_uart.o ${OBJECTDIR}/lib/driver_init.o ${OBJECTDIR}/lib/ringbuffer.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/board.o
POSSIBLE_DEPFILES=${OBJECTDIR}/hal/hal_uart.o.d ${OBJECTDIR}/hal/interrupts.o.d ${OBJECTDIR}/lib/io.o.d ${OBJECTDIR}/lib/wimbus.o.d ${OBJECTDIR}/lib/wimuart.o.d ${OBJECTDIR}/lib/async_uart.o.d ${OBJECTDIR}/lib/driver_init.o.d ${OBJECTDIR}/lib/ringbuffer.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/board.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/hal/hal_uart.o ${OBJECTDIR}/hal/interrupts.o ${OBJECTDIR}/lib/io.o ${OBJECTDIR}/lib/wimbus.o ${OBJECTDIR}/lib/wimuart.o ${OBJECTDIR}/lib/async_uart.o ${OBJECTDIR}/lib/driver_init.o ${OBJECTDIR}/lib/ringbuffer.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/board.o

# Source Files
SOURCEFILES=hal/hal_uart.c hal/interrupts.s lib/io.c lib/wimbus.c lib/wimuart.c lib/async_uart.c lib/driver_init.c lib/ringbuffer.c main.c system.c board.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GL406
MP_LINKER_FILE_OPTION=,--script=p24FJ256GL406.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/hal/hal_uart.o: hal/hal_uart.c  .generated_files/flags/default/fbd4b6f45d890c95616dcf27e20183b9472abb65 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/hal" 
	@${RM} ${OBJECTDIR}/hal/hal_uart.o.d 
	@${RM} ${OBJECTDIR}/hal/hal_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal/hal_uart.c  -o ${OBJECTDIR}/hal/hal_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/hal/hal_uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/io.o: lib/io.c  .generated_files/flags/default/1a0630f89d4e72cf7f23bbb61e05635abef34118 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/io.o.d 
	@${RM} ${OBJECTDIR}/lib/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/io.c  -o ${OBJECTDIR}/lib/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/io.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/wimbus.o: lib/wimbus.c  .generated_files/flags/default/a26e9e5c9cc02b121655366a0b4907a0d7137872 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/wimbus.o.d 
	@${RM} ${OBJECTDIR}/lib/wimbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/wimbus.c  -o ${OBJECTDIR}/lib/wimbus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/wimbus.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/wimuart.o: lib/wimuart.c  .generated_files/flags/default/aeaa5ff346b3e326129b0e5b7c530050048ee175 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/wimuart.o.d 
	@${RM} ${OBJECTDIR}/lib/wimuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/wimuart.c  -o ${OBJECTDIR}/lib/wimuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/wimuart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/async_uart.o: lib/async_uart.c  .generated_files/flags/default/169201e99e94e39d38cb751935c1b00822193721 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/async_uart.o.d 
	@${RM} ${OBJECTDIR}/lib/async_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/async_uart.c  -o ${OBJECTDIR}/lib/async_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/async_uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/driver_init.o: lib/driver_init.c  .generated_files/flags/default/7f38bb74d38c6d3c2d400a2030fb92abd4e96fb .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/driver_init.o.d 
	@${RM} ${OBJECTDIR}/lib/driver_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/driver_init.c  -o ${OBJECTDIR}/lib/driver_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/driver_init.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/ringbuffer.o: lib/ringbuffer.c  .generated_files/flags/default/9ec040f76b9f5e63015fe8d4ac06ccffcfda870 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/ringbuffer.o.d 
	@${RM} ${OBJECTDIR}/lib/ringbuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/ringbuffer.c  -o ${OBJECTDIR}/lib/ringbuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/ringbuffer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/dc2b3021eebd63f5c33af883bd950a6d3bc7d1f4 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/31ffaacfcb07fefe6e51aafdc720bd966ae36c6e .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/board.o: board.c  .generated_files/flags/default/15e62de6096ddbf15cb5f7003a71a8608c0006cd .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/board.o.d 
	@${RM} ${OBJECTDIR}/board.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  board.c  -o ${OBJECTDIR}/board.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/board.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/hal/hal_uart.o: hal/hal_uart.c  .generated_files/flags/default/22d08f542b83da4f9613a67e811cbdf612eca33 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/hal" 
	@${RM} ${OBJECTDIR}/hal/hal_uart.o.d 
	@${RM} ${OBJECTDIR}/hal/hal_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  hal/hal_uart.c  -o ${OBJECTDIR}/hal/hal_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/hal/hal_uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/io.o: lib/io.c  .generated_files/flags/default/90887d41cb11753e888253e7307e660d3b0ea913 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/io.o.d 
	@${RM} ${OBJECTDIR}/lib/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/io.c  -o ${OBJECTDIR}/lib/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/io.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/wimbus.o: lib/wimbus.c  .generated_files/flags/default/28577458e838b29e49d60acf1ff4ee1efa64a8c2 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/wimbus.o.d 
	@${RM} ${OBJECTDIR}/lib/wimbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/wimbus.c  -o ${OBJECTDIR}/lib/wimbus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/wimbus.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/wimuart.o: lib/wimuart.c  .generated_files/flags/default/f752e4488aa8364ba6b26754f5a459afdeecad94 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/wimuart.o.d 
	@${RM} ${OBJECTDIR}/lib/wimuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/wimuart.c  -o ${OBJECTDIR}/lib/wimuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/wimuart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/async_uart.o: lib/async_uart.c  .generated_files/flags/default/fdc93b65ed155ba3e82c5915508602107ca19456 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/async_uart.o.d 
	@${RM} ${OBJECTDIR}/lib/async_uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/async_uart.c  -o ${OBJECTDIR}/lib/async_uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/async_uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/driver_init.o: lib/driver_init.c  .generated_files/flags/default/1cce4687365a28c9fceaafad56c75ade0724ae43 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/driver_init.o.d 
	@${RM} ${OBJECTDIR}/lib/driver_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/driver_init.c  -o ${OBJECTDIR}/lib/driver_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/driver_init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib/ringbuffer.o: lib/ringbuffer.c  .generated_files/flags/default/f8ca52f813c0505cc7114fbeb6519a418fbe0861 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/lib" 
	@${RM} ${OBJECTDIR}/lib/ringbuffer.o.d 
	@${RM} ${OBJECTDIR}/lib/ringbuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib/ringbuffer.c  -o ${OBJECTDIR}/lib/ringbuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib/ringbuffer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/2afa7553a5531ef7b63d80bca6e375949747e61c .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/17048330634533b8b6ec1d2add602a81e3de4c45 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/board.o: board.c  .generated_files/flags/default/212cc664b618f129bb20f0b8b7f1801d04b6a3f0 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/board.o.d 
	@${RM} ${OBJECTDIR}/board.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  board.c  -o ${OBJECTDIR}/board.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/board.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/hal/interrupts.o: hal/interrupts.s  .generated_files/flags/default/721a656b1fae6c15ab803c797cdd1e9c5b7b09f1 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/hal" 
	@${RM} ${OBJECTDIR}/hal/interrupts.o.d 
	@${RM} ${OBJECTDIR}/hal/interrupts.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  hal/interrupts.s  -o ${OBJECTDIR}/hal/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/hal/interrupts.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/hal/interrupts.o: hal/interrupts.s  .generated_files/flags/default/39781f78f50b7eb27df4b0b79dd0414aed785d47 .generated_files/flags/default/940bf91e7636c845858d50fc63297f50cd1b4766
	@${MKDIR} "${OBJECTDIR}/hal" 
	@${RM} ${OBJECTDIR}/hal/interrupts.o.d 
	@${RM} ${OBJECTDIR}/hal/interrupts.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  hal/interrupts.s  -o ${OBJECTDIR}/hal/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/hal/interrupts.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
