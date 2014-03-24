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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c usb_descriptors.c ../../../CodeBank8/bsp/Microchip/system/system.c ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c ../../../CodeBank8/bsp/Microchip/usb/usb_device.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/_ext/644714797/system.o ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o ${OBJECTDIR}/_ext/1984378694/usb_device.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/usb_descriptors.o.d ${OBJECTDIR}/_ext/644714797/system.o.d ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o.d ${OBJECTDIR}/_ext/1984378694/usb_device.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/_ext/644714797/system.o ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o ${OBJECTDIR}/_ext/1984378694/usb_device.o

# Source Files
SOURCEFILES=main.c usb_descriptors.c ../../../CodeBank8/bsp/Microchip/system/system.c ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c ../../../CodeBank8/bsp/Microchip/usb/usb_device.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F45J50
MP_PROCESSOR_OPTION_LD=18f45j50
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/usb_descriptors.o   usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/644714797/system.o: ../../../CodeBank8/bsp/Microchip/system/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/644714797 
	@${RM} ${OBJECTDIR}/_ext/644714797/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/644714797/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/644714797/system.o   ../../../CodeBank8/bsp/Microchip/system/system.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/644714797/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/644714797/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/96797145/usb_function_cdc.o: ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/96797145 
	@${RM} ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o   ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/96797145/usb_function_cdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1984378694/usb_device.o: ../../../CodeBank8/bsp/Microchip/usb/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1984378694 
	@${RM} ${OBJECTDIR}/_ext/1984378694/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984378694/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1984378694/usb_device.o   ../../../CodeBank8/bsp/Microchip/usb/usb_device.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1984378694/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1984378694/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/usb_descriptors.o   usb_descriptors.c 
	@${DEP_GEN} -d ${OBJECTDIR}/usb_descriptors.o 
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/644714797/system.o: ../../../CodeBank8/bsp/Microchip/system/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/644714797 
	@${RM} ${OBJECTDIR}/_ext/644714797/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/644714797/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/644714797/system.o   ../../../CodeBank8/bsp/Microchip/system/system.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/644714797/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/644714797/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/96797145/usb_function_cdc.o: ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/96797145 
	@${RM} ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o   ../../../CodeBank8/bsp/Microchip/usb/cdc/usb_function_cdc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/96797145/usb_function_cdc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/96797145/usb_function_cdc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1984378694/usb_device.o: ../../../CodeBank8/bsp/Microchip/usb/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1984378694 
	@${RM} ${OBJECTDIR}/_ext/1984378694/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984378694/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"../../../CodeBank8" -I"../../../CodeBank8/bsp/Microchip" -I"../../../CodeBank8/middleware" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1984378694/usb_device.o   ../../../CodeBank8/bsp/Microchip/usb/usb_device.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1984378694/usb_device.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1984378694/usb_device.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    rm18f45j50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "rm18f45j50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   rm18f45j50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "rm18f45j50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/usb_cdc2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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