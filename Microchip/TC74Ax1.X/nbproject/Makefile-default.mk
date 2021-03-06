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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=H:/CodeBank8/bsp/Microchip/delays/delays.c H:/CodeBank8/bsp/Microchip/i2c/i2c.c ../../../CodeBank8/bsp/Microchip/uart/uart.c ../../../CodeBank8/bsp/Microchip/gpios/gpios.c H:/CodeBank8/middleware/printf/printf.c H:/CodeBank8/modules/tc74ax/tc74ax.c H:/Examples/Microchip/TC74Ax1.X/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1977764966/delays.p1 ${OBJECTDIR}/_ext/101565252/i2c.p1 ${OBJECTDIR}/_ext/1386180684/uart.p1 ${OBJECTDIR}/_ext/9437126/gpios.p1 ${OBJECTDIR}/_ext/936580751/printf.p1 ${OBJECTDIR}/_ext/1991572690/tc74ax.p1 ${OBJECTDIR}/_ext/1659582330/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1977764966/delays.p1.d ${OBJECTDIR}/_ext/101565252/i2c.p1.d ${OBJECTDIR}/_ext/1386180684/uart.p1.d ${OBJECTDIR}/_ext/9437126/gpios.p1.d ${OBJECTDIR}/_ext/936580751/printf.p1.d ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d ${OBJECTDIR}/_ext/1659582330/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1977764966/delays.p1 ${OBJECTDIR}/_ext/101565252/i2c.p1 ${OBJECTDIR}/_ext/1386180684/uart.p1 ${OBJECTDIR}/_ext/9437126/gpios.p1 ${OBJECTDIR}/_ext/936580751/printf.p1 ${OBJECTDIR}/_ext/1991572690/tc74ax.p1 ${OBJECTDIR}/_ext/1659582330/main.p1

# Source Files
SOURCEFILES=H:/CodeBank8/bsp/Microchip/delays/delays.c H:/CodeBank8/bsp/Microchip/i2c/i2c.c ../../../CodeBank8/bsp/Microchip/uart/uart.c ../../../CodeBank8/bsp/Microchip/gpios/gpios.c H:/CodeBank8/middleware/printf/printf.c H:/CodeBank8/modules/tc74ax/tc74ax.c H:/Examples/Microchip/TC74Ax1.X/main.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F45J50
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1977764966/delays.p1: H:/CodeBank8/bsp/Microchip/delays/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977764966 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1977764966/delays.p1  H:/CodeBank8/bsp/Microchip/delays/delays.c 
	@-${MV} ${OBJECTDIR}/_ext/1977764966/delays.d ${OBJECTDIR}/_ext/1977764966/delays.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1977764966/delays.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/101565252/i2c.p1: H:/CodeBank8/bsp/Microchip/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/101565252 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/101565252/i2c.p1  H:/CodeBank8/bsp/Microchip/i2c/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/101565252/i2c.d ${OBJECTDIR}/_ext/101565252/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/101565252/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1386180684/uart.p1: ../../../CodeBank8/bsp/Microchip/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1386180684 
	@${RM} ${OBJECTDIR}/_ext/1386180684/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1386180684/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1386180684/uart.p1  ../../../CodeBank8/bsp/Microchip/uart/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1386180684/uart.d ${OBJECTDIR}/_ext/1386180684/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1386180684/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/9437126/gpios.p1: ../../../CodeBank8/bsp/Microchip/gpios/gpios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/9437126 
	@${RM} ${OBJECTDIR}/_ext/9437126/gpios.p1.d 
	@${RM} ${OBJECTDIR}/_ext/9437126/gpios.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/9437126/gpios.p1  ../../../CodeBank8/bsp/Microchip/gpios/gpios.c 
	@-${MV} ${OBJECTDIR}/_ext/9437126/gpios.d ${OBJECTDIR}/_ext/9437126/gpios.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/9437126/gpios.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/936580751/printf.p1: H:/CodeBank8/middleware/printf/printf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/936580751 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.p1.d 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/936580751/printf.p1  H:/CodeBank8/middleware/printf/printf.c 
	@-${MV} ${OBJECTDIR}/_ext/936580751/printf.d ${OBJECTDIR}/_ext/936580751/printf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/936580751/printf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1991572690/tc74ax.p1: H:/CodeBank8/modules/tc74ax/tc74ax.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1991572690 
	@${RM} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1991572690/tc74ax.p1  H:/CodeBank8/modules/tc74ax/tc74ax.c 
	@-${MV} ${OBJECTDIR}/_ext/1991572690/tc74ax.d ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1659582330/main.p1: H:/Examples/Microchip/TC74Ax1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1659582330 
	@${RM} ${OBJECTDIR}/_ext/1659582330/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1659582330/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1659582330/main.p1  H:/Examples/Microchip/TC74Ax1.X/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1659582330/main.d ${OBJECTDIR}/_ext/1659582330/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1659582330/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1977764966/delays.p1: H:/CodeBank8/bsp/Microchip/delays/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977764966 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1977764966/delays.p1  H:/CodeBank8/bsp/Microchip/delays/delays.c 
	@-${MV} ${OBJECTDIR}/_ext/1977764966/delays.d ${OBJECTDIR}/_ext/1977764966/delays.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1977764966/delays.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/101565252/i2c.p1: H:/CodeBank8/bsp/Microchip/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/101565252 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/101565252/i2c.p1  H:/CodeBank8/bsp/Microchip/i2c/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/101565252/i2c.d ${OBJECTDIR}/_ext/101565252/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/101565252/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1386180684/uart.p1: ../../../CodeBank8/bsp/Microchip/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1386180684 
	@${RM} ${OBJECTDIR}/_ext/1386180684/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1386180684/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1386180684/uart.p1  ../../../CodeBank8/bsp/Microchip/uart/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/1386180684/uart.d ${OBJECTDIR}/_ext/1386180684/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1386180684/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/9437126/gpios.p1: ../../../CodeBank8/bsp/Microchip/gpios/gpios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/9437126 
	@${RM} ${OBJECTDIR}/_ext/9437126/gpios.p1.d 
	@${RM} ${OBJECTDIR}/_ext/9437126/gpios.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/9437126/gpios.p1  ../../../CodeBank8/bsp/Microchip/gpios/gpios.c 
	@-${MV} ${OBJECTDIR}/_ext/9437126/gpios.d ${OBJECTDIR}/_ext/9437126/gpios.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/9437126/gpios.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/936580751/printf.p1: H:/CodeBank8/middleware/printf/printf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/936580751 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.p1.d 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/936580751/printf.p1  H:/CodeBank8/middleware/printf/printf.c 
	@-${MV} ${OBJECTDIR}/_ext/936580751/printf.d ${OBJECTDIR}/_ext/936580751/printf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/936580751/printf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1991572690/tc74ax.p1: H:/CodeBank8/modules/tc74ax/tc74ax.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1991572690 
	@${RM} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1991572690/tc74ax.p1  H:/CodeBank8/modules/tc74ax/tc74ax.c 
	@-${MV} ${OBJECTDIR}/_ext/1991572690/tc74ax.d ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1991572690/tc74ax.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1659582330/main.p1: H:/Examples/Microchip/TC74Ax1.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1659582330 
	@${RM} ${OBJECTDIR}/_ext/1659582330/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1659582330/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: (%%n) %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"    -o${OBJECTDIR}/_ext/1659582330/main.p1  H:/Examples/Microchip/TC74Ax1.X/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1659582330/main.d ${OBJECTDIR}/_ext/1659582330/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1659582330/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"        -odist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --rom=default,-0-FFF,-1006-1007,-1016-1017 --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 -I"../../../CodeBank8" -I"../../../CodeBank8/middleware" -I"../../../CodeBank8/modules" -I"../../../CodeBank8/bsp/Microchip" -I"." --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --codeoffset=0x1000 --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: (%%n) %%s" "--msgformat=%%f:%%l: advisory: (%%n) %%s"     -odist/${CND_CONF}/${IMAGE_TYPE}/TC74Ax1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
