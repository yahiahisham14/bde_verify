MKINCL?=/bbsrc/mkincludes/
include $(MKINCL)/machdep.newlink
include $(LIBMACROS_MK)

USER_FFLAGS = $(FPIC)

USER_CFLAGS = $(WALL) $(CPIC) -I.

USER_CPPFLAGS  = -I.
USER_CPPFLAGS += $(if $(BAS_NOBBENV), -DBAS_NOBBENV)
USER_CPPFLAGS += $(BREGUISVC_CPPFLAGS)

USER_LDFLAGS = $(BREGUISVC_LDFLAGS)

IS_BDE       = yes
IS_PTHREAD   = yes
IS_EXCEPTION = yes
IS_CPPMAIN   = yes
IS_PEKLUDGE  = $(if $(BAS_NOBBENV),,yes)

# Comment the line below to disable dependency builds
IS_DEPENDS_NATIVE=yes

# Remove "yes" in the macro definition below to disable inlining
INLINING=yes

TASK=testbreguisvc.tsk

###
### DO NOT CHANGE THE DEFINITION OF THE 'MSGOBJS' MACRO
###
MSGOBJS=\
s_breguisvc_messages.o \
s_breguisvc_schema.o \
s_breguisvc_schemautil.o

OBJS=\
$(MSGOBJS) \
testbreguisvc.m.o \

SOBJS=\

OLDOBJS=\

ifndef BAS_NOBBENV
INCLIBS+=\
$(A_BASFS_LIBS) \
$(E_IPC_LIBS) \
$(BBIPC_LIBS)
endif

INCLIBS+=\
$(BAS_LIBS) \
$(BSC_LIBS) \
$(A_XERCESC_LIBS) \
$(XERCESC_LIBS)

LIBS=\
$(INCLIBS) \

-include local.mk

include $(MKINCL)/linktask.newlink

# $Id$ $CSID$ $CCId$
# GENERATED BY BLP_BAS_CODEGEN_3.6.13 Thu Jul 12 15:45:41 2012
