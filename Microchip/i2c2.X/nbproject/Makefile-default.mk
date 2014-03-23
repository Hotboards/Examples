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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=H:/Examples/Microchip/i2c2.X/main.c H:/CodeBank8/middleware/printf/printf.c H:/CodeBank8/bsp/Microchip/i2c/i2c.c H:/CodeBank8/bsp/Microchip/gpios/gpios.c H:/CodeBank8/bsp/Microchip/uart/uart.c H:/CodeBank8/bsp/Microchip/delays/delays.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/831532704/main.o ${OBJECTDIR}/_ext/936580751/printf.o ${OBJECTDIR}/_ext/101565252/i2c.o ${OBJECTDIR}/_ext/1180031314/gpios.o ${OBJECTDIR}/_ext/1146041244/uart.o ${OBJECTDIR}/_ext/1977764966/delays.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/831532704/main.o.d ${OBJECTDIR}/_ext/936580751/printf.o.d ${OBJECTDIR}/_ext/101565252/i2c.o.d ${OBJECTDIR}/_ext/1180031314/gpios.o.d ${OBJECTDIR}/_ext/1146041244/uart.o.d ${OBJECTDIR}/_ext/1977764966/delays.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/831532704/main.o ${OBJECTDIR}/_ext/936580751/printf.o ${OBJECTDIR}/_ext/101565252/i2c.o ${OBJECTDIR}/_ext/1180031314/gpios.o ${OBJECTDIR}/_ext/1146041244/uart.o ${OBJECTDIR}/_ext/1977764966/delays.o

# Source Files
SOURCEFILES=H:/Examples/Microchip/i2c2.X/main.c H:/CodeBank8/middleware/printf/printf.c H:/CodeBank8/bsp/Microchip/i2c/i2c.c H:/CodeBank8/bsp/Microchip/gpios/gpios.c H:/CodeBank8/bsp/Microchip/uart/uart.c H:/CodeBank8/bsp/Microchip/delays/delays.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F45J50
MP_PROCESSOR_OPTION_LD=18f45j50
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/831532704/main.o: H:/Examples/Microchip/i2c2.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/831532704 
	@${RM} ${OBJECTDIR}/_ext/831532704/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/831532704/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/831532704/main.o   H:/Examples/Microchip/i2c2.X/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/831532704/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/831532704/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/936580751/printf.o: H:/CodeBank8/middleware/printf/printf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/936580751 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.o.d 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/936580751/printf.o   H:/CodeBank8/middleware/printf/printf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/936580751/printf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/936580751/printf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/101565252/i2c.o: H:/CodeBank8/bsp/Microchip/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/101565252 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/101565252/i2c.o   H:/CodeBank8/bsp/Microchip/i2c/i2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/101565252/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/101565252/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1180031314/gpios.o: H:/CodeBank8/bsp/Microchip/gpios/gpios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1180031314 
	@${RM} ${OBJECTDIR}/_ext/1180031314/gpios.o.d 
	@${RM} ${OBJECTDIR}/_ext/1180031314/gpios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1180031314/gpios.o   H:/CodeBank8/bsp/Microchip/gpios/gpios.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1180031314/gpios.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1180031314/gpios.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1146041244/uart.o: H:/CodeBank8/bsp/Microchip/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1146041244 
	@${RM} ${OBJECTDIR}/_ext/1146041244/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1146041244/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1146041244/uart.o   H:/CodeBank8/bsp/Microchip/uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1146041244/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1146041244/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1977764966/delays.o: H:/CodeBank8/bsp/Microchip/delays/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977764966 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1977764966/delays.o   H:/CodeBank8/bsp/Microchip/delays/delays.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1977764966/delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977764966/delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/831532704/main.o: H:/Examples/Microchip/i2c2.X/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/831532704 
	@${RM} ${OBJECTDIR}/_ext/831532704/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/831532704/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/831532704/main.o   H:/Examples/Microchip/i2c2.X/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/831532704/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/831532704/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/936580751/printf.o: H:/CodeBank8/middleware/printf/printf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/936580751 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.o.d 
	@${RM} ${OBJECTDIR}/_ext/936580751/printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/936580751/printf.o   H:/CodeBank8/middleware/printf/printf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/936580751/printf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/936580751/printf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/101565252/i2c.o: H:/CodeBank8/bsp/Microchip/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/101565252 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/101565252/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/101565252/i2c.o   H:/CodeBank8/bsp/Microchip/i2c/i2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/101565252/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/101565252/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1180031314/gpios.o: H:/CodeBank8/bsp/Microchip/gpios/gpios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1180031314 
	@${RM} ${OBJECTDIR}/_ext/1180031314/gpios.o.d 
	@${RM} ${OBJECTDIR}/_ext/1180031314/gpios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1180031314/gpios.o   H:/CodeBank8/bsp/Microchip/gpios/gpios.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1180031314/gpios.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1180031314/gpios.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1146041244/uart.o: H:/CodeBank8/bsp/Microchip/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1146041244 
	@${RM} ${OBJECTDIR}/_ext/1146041244/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1146041244/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1146041244/uart.o   H:/CodeBank8/bsp/Microchip/uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1146041244/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1146041244/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1977764966/delays.o: H:/CodeBank8/bsp/Microchip/delays/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1977764966 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977764966/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1977764966/delays.o   H:/CodeBank8/bsp/Microchip/delays/delays.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1977764966/delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1977764966/delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    H:/Examples/Microchip/i2c2.X/rm18f45j50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "H:\Examples\Microchip\i2c2.X\rm18f45j50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   H:/Examples/Microchip/i2c2.X/rm18f45j50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "H:\Examples\Microchip\i2c2.X\rm18f45j50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/i2c2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
