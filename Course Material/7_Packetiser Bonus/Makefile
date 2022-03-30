PROJ_NAME = PACKETISER
SRC = packetiser.c

TEST_SRC = unity.c\
test_packetiser.c


ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

build : $(SRC) $(TEST_SRC)
	gcc $^ -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run : build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(call FixPath,$(PROJ_NAME).$(EXEC))
